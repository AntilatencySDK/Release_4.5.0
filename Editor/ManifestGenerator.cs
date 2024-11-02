using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Xml;
using UnityEngine;
using UnityEditor;

public class ManifestGenerator : MonoBehaviour {
    [MenuItem("Antilatency/Generate Android Manifest")]
    static void GenerateAndroidManifest() {
        var androidPluginsPath = Path.Combine(Application.dataPath, "Plugins", "Android");
        var androidManifestFilePath = Path.Combine(androidPluginsPath, "AndroidManifest.xml");

        if (!Directory.Exists(androidPluginsPath)) {
            Directory.CreateDirectory(androidPluginsPath);
        }

        if (File.Exists(androidManifestFilePath)) {
            if (EditorUtility.DisplayDialog(
                "AndroidManifest.xml already exists!", 
                "Would you like to replace the existing manifest with a new one? All modifications will be lost.", 
                "Replace", 
                "Cancel")
            ) {
               File.Delete(androidManifestFilePath);
            } else {
                return;
            }
        }

        var defaultManifestName = "AndroidManifest.xml";
        
#if UNITY_2019_3_OR_NEWER
        defaultManifestName = "UnityManifest.xml";
#endif

        var defaultAndroidManifestFilePath = Path.Combine(EditorApplication.applicationContentsPath, "PlaybackEngines", "AndroidPlayer", "Apk", defaultManifestName);
        if (!File.Exists(defaultAndroidManifestFilePath)) {
            EditorUtility.DisplayDialog("Generate Android Manifest", "Failed to find default android manifest. Aborting.", "Ok");
            return;
        }

        File.Copy(defaultAndroidManifestFilePath, androidManifestFilePath);
        PatchAndroidManifest(androidManifestFilePath, true);

        AssetDatabase.Refresh();
    }

    [MenuItem("Antilatency/Update Android Manifest")]
    static void UpdateAndroidManifest() {
        var androidManifestFilePath = Path.Combine(Application.dataPath, "Plugins", "Android", "AndroidManifest.xml");

        if (!File.Exists(androidManifestFilePath)) {
            if (EditorUtility.DisplayDialog(
                "AndroidManifest.xml doest not exists!", 
                "Would you like to create a new manifest?", 
                "Ok", 
                "Cancel")
            ) {
                GenerateAndroidManifest();
                AssetDatabase.Refresh();
            }
        } else {
            PatchAndroidManifest(androidManifestFilePath, false);
            AssetDatabase.Refresh();
        }
    }

    private static void PatchAndroidManifest(string manifestPath, bool ignoreComments) {
        // Remove <!-- *** --> comments
        if (ignoreComments) {
            var lines = File.ReadAllLines(manifestPath).ToList();
            var linesToRemove = new List<int>();
            for (int i = 0; i < lines.Count; ++i) {
                if (lines[i].StartsWith("<!--") && lines[i].EndsWith("-->")) {
                    linesToRemove.Add(i);
                }
            }

            if (linesToRemove.Count > 0) {
                for (var i = linesToRemove.Count - 1; i == 0; i--) {
                    lines.RemoveAt(linesToRemove[i]);
                }
            }
            
            File.WriteAllLines(manifestPath, lines);
        }
        
        var xDoc = new XmlDocument();
        xDoc.Load(manifestPath);

        var manifestElement = (XmlElement) xDoc.SelectSingleNode("/manifest");
        if (manifestElement == null) {
            Debug.LogError("PatchAndroidManifest: couldn't find manifest tag");
            return;
        }

        var namespaceUri = manifestElement.GetAttribute("xmlns:android");
        if (string.IsNullOrEmpty(namespaceUri)) {
            Debug.Log("PatchAndroidManifest: couldn't find android namespace");
            return;
        }

        AddNode(xDoc,
            namespaceUri,
            "manifest/application/activity/intent-filter",
            "action",
            new Dictionary<string, string> {
                ["name"] = "android.hardware.usb.action.USB_DEVICE_ATTACHED"
            }
        );
        AddNode(
            xDoc, 
            namespaceUri, 
            "manifest/application/activity",
            "meta-data", 
            new Dictionary<string, string> {
                ["name"] = "android.hardware.usb.action.USB_DEVICE_ATTACHED",
                ["resource"] = "@xml/antilatency_usb_filter"
            }
        );

        if (PlayerSettings.Android.targetSdkVersion >= AndroidSdkVersions.AndroidApiLevel30) {
            AddNode(
                xDoc, 
                null, 
                "manifest",
                "queries", 
                null
            );
            AddNode(
                xDoc, 
                namespaceUri, 
                "manifest/queries",
                "package", 
                new Dictionary<string, string> {
                    ["name"] = "com.antilatency.antilatencyservice"
                }
            );
        } else {
            // RemoveNode(xDoc, "manifest/queries");
        }

        xDoc.Save(manifestPath);
    }

    private static void AddNode(XmlDocument xDoc, string namespaceUri, string path, string nodeName, Dictionary<string, string> attributes) {
        var nodes = xDoc.SelectNodes(path + "/" + nodeName);

        XmlElement targetNode = null;
        if (nodes != null) {
            foreach (XmlElement node in nodes) {
                if (attributes == null || attributes.Count == 0) {
                    if (node.Attributes.Count == 0) {
                        targetNode = node;
                        break;
                    }
                }
                var firstAttribute = attributes.First();
                var nodeAttribute = string.IsNullOrEmpty(namespaceUri) ? node.GetAttribute(firstAttribute.Key) : node.GetAttribute(firstAttribute.Key, namespaceUri);
                
                if (firstAttribute.Value == nodeAttribute) {
                    targetNode = node;
                }
            }
        }
        
        if (targetNode != null) {
            targetNode.RemoveAllAttributes();
        } else {
            targetNode = xDoc.CreateElement(nodeName);

            if (string.IsNullOrEmpty(path)) {
                xDoc.AppendChild(targetNode);
            } else {
                var parentNode = xDoc.SelectSingleNode(path);
                if (parentNode != null) {
                    parentNode.AppendChild(targetNode);
                } else {
                    XmlNode currentNode = null;
                
                    var pathElements = path.Split('/');
                    for (var i = 0; i < pathElements.Length; ++i) {
                        var currentPath = string.Join("/", pathElements, 0, i + 1);
                        var node = xDoc.SelectSingleNode(currentPath);
                        if (node == null) {
                            node = xDoc.CreateElement(pathElements[i], namespaceUri);
                        }

                        if (currentNode == null) {
                            xDoc.AppendChild(node);
                        } else {
                            currentNode.AppendChild(node);
                        }
                    
                        currentNode = node;
                    }

                    if (currentNode != null) {
                        currentNode.AppendChild(targetNode);
                    }
                }
            }
        }

        if (attributes != null && attributes.Count > 0) {
            foreach (var attribute in attributes) {
                targetNode.SetAttribute(attribute.Key, namespaceUri, attribute.Value);
            }
        }
    }

    private static void RemoveNode(XmlDocument xDoc, string path) {
        var nodes = xDoc.SelectNodes(path);

        foreach (XmlElement node in nodes) {
            var parent = node.ParentNode;
            if (parent != null) {
                parent.RemoveChild(node);
            }
        }
    }
}
