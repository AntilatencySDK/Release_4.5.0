// Copyright 2022, ALT LLC. All Rights Reserved.
// This file is part of Antilatency SDK.
// It is subject to the license terms in the LICENSE file found in the top-level directory
// of this distribution and at http://www.antilatency.com/eula
// You may not use this file except in compliance with the License.
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

using System;
using System.IO;

namespace UnrealBuildTool.Rules {
	public class AntilatencyRadioMetrics : ModuleRules {
		public AntilatencyRadioMetrics(ReadOnlyTargetRules Target) : base(Target) {
			PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

#if UE_4_27_OR_LATER
            bUsePrecompiled = false;
#endif
            
            var baseDirectory = Path.GetFullPath(Path.Combine(ModuleDirectory, "..", ".."));
            var binaryDirectory = Path.Combine(baseDirectory, "ThirdParty", "Antilatency", "Bin", Target.Platform.ToString());
            var headersDirectory = Path.Combine(baseDirectory, "ThirdParty", "Antilatency", "Api");
            var toolsDirectory = Path.Combine(baseDirectory, "ThirdParty", "Antilatency", "Tools");

            PublicIncludePathModuleNames.AddRange(
                new string[] { "Launch", "Core" }
            );

            PublicIncludePaths.AddRange(
				new string[] {
                    headersDirectory,
                    toolsDirectory
                }
			);

            PublicDependencyModuleNames.AddRange(
				new string[] {
                    "Core",
                    "CoreUObject",
                    "Engine",
                    "Projects",
                    "AntilatencyDeviceNetwork"
                }
			);

#if UE_5_0_OR_LATER
            if (Target.Platform == UnrealTargetPlatform.Win64) {
#else                
            if (Target.Platform == UnrealTargetPlatform.Win32 || Target.Platform == UnrealTargetPlatform.Win64) {
#endif
                var radioMetricsLibraryPath = Path.Combine(binaryDirectory, "AntilatencyRadioMetrics.dll");

#if UE_4_19_OR_LATER
                RuntimeDependencies.Add(radioMetricsLibraryPath);
#else
                RuntimeDependencies.Add(new RuntimeDependency(radioMetricsLibraryPath));
#endif
            } else if (Target.Platform == UnrealTargetPlatform.Android){
	            var pluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
                var aplPath = Path.Combine(pluginPath, "AntilatencyRadioMetrics_APL.xml");
#if UE_4_19_OR_LATER
				AdditionalPropertiesForReceipt.Add("AndroidPlugin", aplPath);
#else
                AdditionalPropertiesForReceipt.Add(new ReceiptProperty("AndroidPlugin", aplPath));
#endif
            } else {
                throw new NotImplementedException("NOT IMPLEMENTED YET FOR PLATFORM " + Target.Platform.ToString());
            }
        }
    }
}
