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

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "CotaskBatteryPowered.h"
#include "CotaskConstructor.h"
#include "DeviceNetworkLibrary.h"
#include "DeviceNetwork.h"
#include "DeviceNetworkTypes.h"

#include "DeviceNetworkFunctionLibrary.generated.h"

 /** An additional enum that is used by the blueprint methods to allow user to check if called method has been executed successfully or not. */
UENUM(BlueprintType)
enum class EDeviceNetworkExceptionResult : uint8 {
    /** The method executed successfully. */
    Success = 1 UMETA(DisplayName = "Success"),
    /** The method execution failed with some exception. */
    Fail = 0 UMETA(DisplayName = "Fail")
};


/**
 * Provides Device Network module's methods wrappers for the UE blueprint system.
 */
UCLASS()
class ANTILATENCYDEVICENETWORK_API UDeviceNetworkFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()

public:

#pragma region UDeviceNetworkLibrary
    /**
     * Get the native device network library object.
     * @param result The native device network library object.
     * @param exception Method execution result.
     */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|DeviceNetwork|Library", Meta = (ExpandEnumAsExecs = "exception"))
    static void GetLibrary(UDeviceNetworkLibrary*& result, EDeviceNetworkExceptionResult& exception);

    /**
    * Create empty filter.
    * @param deviceNetworkLibrary The pointer to the UDeviceNetworkLibrary object.
    * @param result The pointer to the created UDeviceFilter instance.
    * @param exception Method execution result.
    */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|DeviceNetwork|Library", Meta = (ExpandEnumAsExecs = "exception"))
    static void CreateFilter(UPARAM(ref) UDeviceNetworkLibrary* deviceNetworkLibrary, UDeviceFilter*& result, EDeviceNetworkExceptionResult& exception);

    /**
     * Create the device network to work with Antilatency devices.
     * @param deviceNetworkLibrary The pointer to the UDeviceNetworkLibrary object.
     * @param deviceFilter The device filter that will be used by network.
     * @param result The pointer to the created UDeviceNetwork instance.
     * @param exception Method execution result.
     */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|DeviceNetwork|Library", Meta = (ExpandEnumAsExecs = "exception"))
    static void CreateNetwork(UPARAM(ref) UDeviceNetworkLibrary* deviceNetworkLibrary, UPARAM(ref) UDeviceFilter* deviceFilter, UDeviceNetwork*& result, EDeviceNetworkExceptionResult& exception);

    /**
     * Get the Antilatency Device Network library version.
     * @param deviceNetworkLibrary The pointer to the UDeviceNetworkLibrary object.
     * @param result The Antilatency Device Network library version.
     * @param exception Method execution result.
     */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|DeviceNetwork|Library", Meta = (ExpandEnumAsExecs = "exception"))
    static void GetVersion(UPARAM(ref) UDeviceNetworkLibrary* deviceNetworkLibrary, FString& result, EDeviceNetworkExceptionResult& exception);

    /** 
     * Set the log verbosity level for Antilatency Device Network library. 
     * @param deviceNetworkLibrary The pointer to the UDeviceNetworkLibrary object.
     * @param level The verbosity level to set.
     * @param exception Method execution result.
     */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|DeviceNetwork|Library", Meta = (ExpandEnumAsExecs = "exception"))
    static void SetLogLevel(UPARAM(ref) UDeviceNetworkLibrary* deviceNetworkLibrary, const EDeviceNetworkLogLevel& level, EDeviceNetworkExceptionResult& exception);

    /**
     * Check if UDeviceNetworkLibrary has been initialized properly (the UDeviceNetworkLibrary is not nullptr and the native Antilatency::DeviceNetwork::ILibrary is not nullptr).
     * @param deviceNetworkLibrary A pointer to the UDeviceNetworkLibrary object.
     * @return True if object is initialized properly, otherwise false.
     */
    UFUNCTION(BlueprintPure, Category = "Antilatency|DeviceNetwork|Library")
    static bool IsLibraryValid(const UDeviceNetworkLibrary* deviceNetworkLibrary);
#pragma endregion

#pragma region UDeviceFilter
    UFUNCTION(BlueprintCallable, Category = "Antilatency|DeviceNetwork|Device Filter", Meta = (ExpandEnumAsExecs = "exception"))
    static void AddUsbDevice(UPARAM(ref) UDeviceFilter* filter, const FUsbDeviceFilter& usbDeviceFilter, EDeviceNetworkExceptionResult& exception);
    
    UFUNCTION(BlueprintCallable, Category = "Antilatency|DeviceNetwork|Device Filter", Meta = (ExpandEnumAsExecs = "exception"))
    static void AddIpDevice(UPARAM(ref) UDeviceFilter* filter, const FString& ip, const FString& mask, EDeviceNetworkExceptionResult& exception);

    UFUNCTION(BlueprintCallable, Category = "Antilatency|DeviceNetwork|Device Filter", Meta = (ExpandEnumAsExecs = "exception"))
    static void GetUsbDevice(UPARAM(ref) UDeviceFilter* filter, const int32 index, FUsbDeviceFilter& result, EDeviceNetworkExceptionResult& exception);

    UFUNCTION(BlueprintCallable, Category = "Antilatency|DeviceNetwork|Device Filter", Meta = (ExpandEnumAsExecs = "exception"))
    static void GetIpDevice(UPARAM(ref) UDeviceFilter* filter, const int32 index, FString& result, EDeviceNetworkExceptionResult& exception);

    UFUNCTION(BlueprintCallable, Category = "Antilatency|DeviceNetwork|Device Filter", Meta = (ExpandEnumAsExecs = "exception"))
    static void GetIpDeviceMask(UPARAM(ref) UDeviceFilter* filter, const int32 index, FString& result, EDeviceNetworkExceptionResult& exception);

    /**
     * Check if UDeviceFilter has been initialized properly.
     * @param filter A pointer to the UDeviceFilter object.
     * @return True if object is initialized properly, otherwise false.
     */
    UFUNCTION(BlueprintPure, Category = "Antilatency|DeviceNetwork|Library")
    static bool IsDeviceFilterValid(const UDeviceFilter* filter);
#pragma endregion 
    
#pragma region UDeviceNetwork
    /**
     * Every time any supported device is connected or disconnected, update ID will be incremented. You can use this method to check if there are any changes in ADN.
     * @param network The pointer to the UDeviceNetwork object.
     * @param result Current Device Network update ID.
     * @param exception Method execution result.
     */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|DeviceNetwork|Network", Meta = (ExpandEnumAsExecs = "exception"))
    static void GetUpdateId(UPARAM(ref) UDeviceNetwork* network, int32& result, EDeviceNetworkExceptionResult& exception);

    /**
     * Get USB device types selected to work with this network instance.
     * @param network The pointer to the UDeviceNetwork object.
     * @param result The array of FUsbDeviceType, that describes the list of USB devices which is used by this Device Network instance to work with.
     * @param exception Method execution result.
     */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|DeviceNetwork|Network", Meta = (ExpandEnumAsExecs = "exception"))
    static void GetDeviceFilter(UPARAM(ref) UDeviceNetwork* network, UDeviceFilter*& result, EDeviceNetworkExceptionResult& exception);

    /**
     * Get all currently connected nodes.
     * @param network The pointer to the UDeviceNetwork object.
     * @param result The array of currently connected devices.
     * @param exception Method execution result.
     */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|DeviceNetwork|Network", Meta = (ExpandEnumAsExecs = "exception"))
    static void GetNodes(UPARAM(ref) UDeviceNetwork* network, TArray<FAdnNode>& result, EDeviceNetworkExceptionResult& exception);

    /**
     * Get current node status.
     * @param network The pointer to the UDeviceNetwork object.
     * @param node The node to get status.
     * @param result Current node status.
     * @param exception Method execution result.
     */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|DeviceNetwork|Network", Meta = (ExpandEnumAsExecs = "exception"))
    static void NodeGetStatus(UPARAM(ref) UDeviceNetwork* network, const FAdnNode& node, ENodeStatus& result, EDeviceNetworkExceptionResult& exception);

    /**
     * Checks if task is supported by node.
     * @param network The pointer to the UDeviceNetwork object.
     * @param node The node top check the task support.
     * @param interfaceId The guid of task.
     * @param result True if the node supports the task, otherwise false.
     * @param exception Method execution result.
     */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|DeviceNetwork|Network", Meta = (ExpandEnumAsExecs = "exception"))
    static void NodeIsTaskSupported(UPARAM(ref) UDeviceNetwork* network, const FAdnNode& node, const FGuid& interfaceId, bool& result, EDeviceNetworkExceptionResult& exception);

    /**
     * Get the parent node.
     * @param network The pointer to the UDeviceNetwork object.
     * @param node The node to get it's parent.
     * @param result The node's parent. If node is USB node, parent will be Null node.
     * @param exception Method execution result.
     */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|DeviceNetwork|Network", Meta = (ExpandEnumAsExecs = "exception"))
    static void NodeGetParent(UPARAM(ref) UDeviceNetwork* network, const FAdnNode& node, FAdnNode& result, EDeviceNetworkExceptionResult& exception);

    /**
     * The physical address path to the first level device that contains this node in the network tree.
     * @param network The pointer to the UDeviceNetwork object.
     * @param node The node to get physical path.
     * @param result The USB node physical path.
     * @param exception Method execution result.
     */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|DeviceNetwork|Network", Meta = (ExpandEnumAsExecs = "exception"))
    static void NodeGetPhysicalPath(UPARAM(ref) UDeviceNetwork* network, const FAdnNode& node, FString& result, EDeviceNetworkExceptionResult& exception);

    /**
     * Get the node string property value.
     * @param network The pointer to the UDeviceNetwork object.
     * @param node The node to get property from.
     * @param key The property name to get value for.
     * @param result The property value.
     * @param exception Method execution result.
     */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|DeviceNetwork|Network", Meta = (ExpandEnumAsExecs = "exception"))
    static void NodeGetStringProperty(UPARAM(ref) UDeviceNetwork* network, const FAdnNode& node, const FString& key, FString& result, EDeviceNetworkExceptionResult& exception);

    /**
    * Get the node string property value.
    * @param network The pointer to the UDeviceNetwork object.
    * @param node The node to get property from.
    * @param key The property name to get value for.
    * @param result The property value.
    * @param exception Method execution result.
    */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|DeviceNetwork|Network", Meta = (ExpandEnumAsExecs = "exception"))
    static void NodeGetBinaryProperty(UPARAM(ref) UDeviceNetwork* network, const FAdnNode& node, const FString& key, TArray<uint8>& result, EDeviceNetworkExceptionResult& exception);

    /**
     * Start property task on node.
     * @param network The pointer to the UDeviceNetwork object.
     * @param node The node to start property task on.
     * @param result The property task object.
     * @param exception Method execution result.
     */ 
	UFUNCTION(BlueprintCallable, Category = "Antilatency|DeviceNetwork|Network", Meta = (ExpandEnumAsExecs = "exception"))
    static void NodeStartPropertyTask(UPARAM(ref) UDeviceNetwork* network, const FAdnNode& node, UPropertyCotask*& result, EDeviceNetworkExceptionResult& exception);

    /**
     * Check if the Device Network wrapper initialized properly.
     * @param network The pointer to the UDeviceNetwork object.
     * @return True if the Device Network wrapper initialized properly, otherwise false.
     */
    UFUNCTION(BlueprintPure, Category = "Antilatency|DeviceNetwork|Network")
    static bool IsNetworkValid(UPARAM(ref) UDeviceNetwork* network);
#pragma endregion

#pragma region UCotask
    /**
     * @brief Check if the task is finished on node.
     * @param cotask The pointer to the UCotask object.
     * @param result True if task finished, otherwise false.
     * @param exception Method execution result.
     */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|DeviceNetwork|Cotask", Meta = (ExpandEnumAsExecs = "exception"))
    static void IsTaskFinished(UPARAM(ref) UCotask* cotask, bool& result, EDeviceNetworkExceptionResult& exception);

    /**
     * @brief Stop tracking task. Remember to free the target cotask instance after calling this method because it will be not useful at all after that moment.
     * The node which is used by that task will become free (FNodeStatus::Idle) after calling this method, so you can run another task on it.
     * IMPORTANT: there is no guarantee that this node changes status immediately after calling this method, this may take some time.
     * @param cotask The pointer to the UCotask object.
     */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|DeviceNetwork|Cotask")
    static void Stop(UPARAM(ref) UCotask* cotask);

    /**
     * Check if the Device Network wrapper initialized properly.
     * @param cotask The pointer to the UCotask object.
     * @return True if the Device Network wrapper initialized properly, otherwise false.
     */
    UFUNCTION(BlueprintPure, Category = "Antilatency|DeviceNetwork|Cotask")
    static bool IsCotaskValid(UPARAM(ref) UCotask* cotask);
#pragma endregion 
    
#pragma region UCotaskBatteryPowered
    /**
    * @brief Get actual battery level.
    * @param cotaskBatteryPowered The pointer to the UCotaskBatteryPowered object.
    * @param result Actual battery level.
    * @param exception Method execution result.
    */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|DeviceNetwork|Cotask Battery Powered", Meta = (ExpandEnumAsExecs = "exception"))
    static void GetBatteryLevel(UPARAM(ref) UCotaskBatteryPowered* cotaskBatteryPowered, float& result, EDeviceNetworkExceptionResult& exception);
#pragma endregion

#pragma region UPropertyCotask
    /**
     * @brief Get property key using it's index.
     * @param propertyCotask 
     * @param index 
     * @param result 
     * @param exception 
     */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|DeviceNetwork|Property Cotask", Meta = (ExpandEnumAsExecs = "exception"))
    static void GetPropertyKey(UPARAM(ref) UPropertyCotask* propertyCotask, const int32 index, FString& result, EDeviceNetworkExceptionResult& exception);

    UFUNCTION(BlueprintCallable, Category = "Antilatency|DeviceNetwork|Property Cotask", Meta = (ExpandEnumAsExecs = "exception"))
    static void GetStringProperty(UPARAM(ref) UPropertyCotask* propertyCotask, const FString& key, FString& result, EDeviceNetworkExceptionResult& exception);

    UFUNCTION(BlueprintCallable, Category = "Antilatency|DeviceNetwork|Property Cotask", Meta = (ExpandEnumAsExecs = "exception"))
    static void SetStringProperty(UPARAM(ref) UPropertyCotask* propertyCotask, const FString& key, const FString& value, EDeviceNetworkExceptionResult& exception);

    UFUNCTION(BlueprintCallable, Category = "Antilatency|DeviceNetwork|Property Cotask", Meta = (ExpandEnumAsExecs = "exception"))
    static void GetBinaryProperty(UPARAM(ref) UPropertyCotask* propertyCotask, const FString& key, TArray<uint8>& result, EDeviceNetworkExceptionResult& exception);

    UFUNCTION(BlueprintCallable, Category = "Antilatency|DeviceNetwork|Property Cotask", Meta = (ExpandEnumAsExecs = "exception"))
    static void SetBinaryProperty(UPARAM(ref) UPropertyCotask* propertyCotask, const FString& key, const TArray<uint8>& value, EDeviceNetworkExceptionResult& exception);

    UFUNCTION(BlueprintCallable, Category = "Antilatency|DeviceNetwork|Property Cotask", Meta = (ExpandEnumAsExecs = "exception"))
    static void DeleteProperty(UPARAM(ref) UPropertyCotask* propertyCotask, const FString& key, EDeviceNetworkExceptionResult& exception);
#pragma endregion 

#pragma region UCotaskConstructor
    /**
     * @brief Is node supports this type of task.
     * @param cotaskConstructor The pointer to the UCotaskConstructor object.
     * @param network The pointer to the UDeviceNetwork object.
     * @param node The node to check support of the task.
     * @param result 
     * @param exception Method execution result.
     */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|DeviceNetwork|CotaskConstructor", Meta = (ExpandEnumAsExecs = "exception"))
    static void IsSupported(UPARAM(ref) UCotaskConstructor* cotaskConstructor, UPARAM(ref) UDeviceNetwork* network, const FAdnNode& node, bool& result, EDeviceNetworkExceptionResult& exception);

    /**
     * @brief Get the array of nodes that supports this type of task.
     * @param cotaskConstructor The pointer to the UCotaskConstructor object.
     * @param network The pointer to the UDeviceNetwork object.
     * @param result The array of nodes that supports this type of task.
     * @param exception Method execution result.
     */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|DeviceNetwork|CotaskConstructor", Meta = (ExpandEnumAsExecs = "exception"))
    static void FindSupportedNodes(UPARAM(ref) UCotaskConstructor* cotaskConstructor, UPARAM(ref) UDeviceNetwork* network, TArray<FAdnNode>& result, EDeviceNetworkExceptionResult& exception);

    /**
     * Check if UCotaskConstructor has been initialized properly.
     * @param constructor A pointer to the UCotaskConstructor object.
     * @return True if object is initialized properly, otherwise false.
     */
    UFUNCTION(BlueprintPure, Category = "Antilatency|DeviceNetwork|Library")
    static bool IsCotaskConstructorValid(const UCotaskConstructor* constructor);
#pragma endregion 

#pragma region Nodehandle
	/**
	* Check if two FAdnNodes are equal.
	* @param arg1 The first FAdnNode to compare.
	* @param arg2 The second FAdnNode to compare.
	* @return True if nodes are equal, otherwise false.
	*/
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal FAdnNode", CompactNodeTitle = "==", Keywords = "== equal"), Category = "Math")
	static bool EqualEqual_FAdnNodeFAdnNode(const FAdnNode& arg1, const FAdnNode& arg2);

	/**
	* Check if two FAdnNodes are not equal.
	* @param arg1 The first FAdnNode to compare.
	* @param arg2 The second FAdnNode to compare.
	* @return True if nodes are not equal, otherwise false.
	*/
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Not Equal FAdnNode", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = "Math")
	static bool NotEqual_FAdnNodeFAdnNode(const FAdnNode& arg1, const FAdnNode& arg2);
#pragma endregion 

#pragma region Constants
     /**
     * @return The predefined FUsbDeviceType structure that matches all Antilatency devices.
     */
    UFUNCTION(BlueprintPure, Category = "Antilatency|DeviceNetwork|Constants|USB Device Filter")
    static FUsbDeviceFilter AllUsbDevices();

    UFUNCTION(BlueprintPure, Category = "Antilatency|DeviceNetwork|Constants|USB Device Filter")
    static int32 UsbAllDeviceMask();

    UFUNCTION(BlueprintPure, Category = "Antilatency|DeviceNetwork|Constants|USB Device Filter")
    static int32 UsbOneDeviceMask();

    UFUNCTION(BlueprintPure, Category = "Antilatency|DeviceNetwork|Constants|IP Device Filter")
    static FString AllIpDevicesIp();

    UFUNCTION(BlueprintPure, Category = "Antilatency|DeviceNetwork|Constants|IP Device Filter")
    static FString AllIpDevicesMask();

    /**
     * Get the null node, that can be used as invalid node. Also, calling nodeGetParent on USB node will return null node.
     * @return The null node.
     */
    UFUNCTION(BlueprintPure, Category = "Antilatency|DeviceNetwork|Constants|Node")
    static FAdnNode NullNode();

    /**
     * The predefined key to get the hardware version property value from the node.
     * @return The hardware version property key.
     */
    UFUNCTION(BlueprintPure, Category = "Antilatency|DeviceNetwork|Constants|Property Key")
    static FString HardwareVersionKey();

    /**
     * The predefined key to get the hardware name property value from the node.
     * @return The hardware name property key.
     */
    UFUNCTION(BlueprintPure, Category = "Antilatency|DeviceNetwork|Constants|Property Key")
    static FString HardwareNameKey();

    /**
     * The predefined key to get the software version property value from the node.
     * @return The software version property key.
     */
    UFUNCTION(BlueprintPure, Category = "Antilatency|DeviceNetwork|Constants|Property Key")
    static FString FirmwareVersionKey();

    /**
     * The predefined key to get the hardware version property value from the node.
     * @return The hardware version property key.
     */
    UFUNCTION(BlueprintPure, Category = "Antilatency|DeviceNetwork|Constants|Property Key")
    static FString FirmwareNameKey();

    /**
     * The predefined key to get the hardware serial number property value from the node.
     * @return The hardware serial number property key.
     */
    UFUNCTION(BlueprintPure, Category = "Antilatency|DeviceNetwork|Constants|Property Key")
    static FString HardwareSerialNumberKey();

    /**
    * The predefined key to get the image version property value from the node.
    * @return The image version property key.
    */
    UFUNCTION(BlueprintPure, Category = "Antilatency|DeviceNetwork|Constants|Property Key")
    static FString ImageVersionKey();

    UFUNCTION(BlueprintPure, Category = "Antilatency|DeviceNetwork|Constants|Property Key")
    static int32 IpBroadcastSenderPort();

    UFUNCTION(BlueprintPure, Category = "Antilatency|DeviceNetwork|Constants|Property Key")
    static int32 IpBroadcastReceiverPort();

    UFUNCTION(BlueprintPure, Category = "Antilatency|DeviceNetwork|Constants|Property Key")
    static int32 IpDefaultStreamPort();
#pragma endregion
    
};
