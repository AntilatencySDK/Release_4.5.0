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
#include "UObject/NoExportTypes.h"

#include "DeviceNetworkConstants.h"
#include "DeviceNetworkTypes.h"
#include "DeviceFilter.h"
#include "PropertyCotask.h"

#include <Antilatency.DeviceNetwork.h>
#include <ObjectConstructor.h>

#include "DeviceNetwork.generated.h"

/**
 * The UE wrapper for the Antilatency::DeviceNetwork::INetwork object.
 * Do not instantiate this class directly by calling the NewObject<UDeviceNetwork> method,
 * use the UDeviceNetworkLibrary::CreateNetwork instead.
 */
UCLASS(BlueprintType)
class ANTILATENCYDEVICENETWORK_API UDeviceNetwork : public UObject {
    GENERATED_BODY()

public:
    typedef Antilatency::DeviceNetwork::INetwork TInterface;
    
    template<class TInterfacedObject>
    friend class ObjectConstructor;

    /**
     * Get the native Antilatency::DeviceNetwork::INetwork object.
     * @return Native Antilatency::DeviceNetwork::INetwork object.
     */
    TInterface GetNative();

    /**
     * Every time any supported device is connected or disconnected, update ID will be incremented. You can use this method to check if there are any changes in ADN.
     * @param result Current Device Network update ID.
     * @return ExceptionCode::Ok if the method execution is successful, otherwise returns the appropriate error code.
     */
    Antilatency::InterfaceContract::ExceptionCode GetUpdateId(uint32& result);

    /**
     * Get USB device types selected to work with this network instance.
     * @param result The array of FUsbDeviceType, that describes the list of USB devices which is used by this Device Network instance to work with.
     * @return ExceptionCode::Ok if the method execution is successful, otherwise returns the appropriate error code.
     */
    Antilatency::InterfaceContract::ExceptionCode GetDeviceFilter(UDeviceFilter*& result);

    /**
     * Get all currently connected nodes.
     * @param result The array of currently connected devices.
     * @return ExceptionCode::Ok if the method execution is successful, otherwise returns the appropriate error code.
     */
    Antilatency::InterfaceContract::ExceptionCode GetNodes(TArray<FAdnNode>& result);

    /** 
     * Get current node status.
     * @param node The node to get status.
     * @param result Current node status.
     * @return ExceptionCode::Ok if the method execution is successful, otherwise returns the appropriate error code.
     */
    Antilatency::InterfaceContract::ExceptionCode NodeGetStatus(const FAdnNode& node, ENodeStatus& result);

    // TODO: FGuid == Antilatency::InterfaceContract::InterfaceID??????
    /** 
     * Checks if task is supported by node.
     * @param node The node top check the task support.
     * @param interfaceId The guid of task.
     * @param result True if the node supports the task, otherwise false.
     * @return ExceptionCode::Ok if the method execution is successful, otherwise returns the appropriate error code.
     */
    Antilatency::InterfaceContract::ExceptionCode NodeIsTaskSupported(const FAdnNode& node, const FGuid& interfaceId, bool& result);

    /**
     * Get the parent node.
     * @param node The node to get it's parent.
     * @param result The node's parent. If node is USB node, parent will be Null node.
     * @return ExceptionCode::Ok if the method execution is successful, otherwise returns the appropriate error code.
     */
    Antilatency::InterfaceContract::ExceptionCode NodeGetParent(const FAdnNode& node, FAdnNode& result);

    /**
     * The physical address path to the first level device that contains this node in the network tree.
     * @param node The node to get physical path.
     * @param result The USB node physical path.
     * @return ExceptionCode::Ok if the method execution is successful, otherwise returns the appropriate error code.
     */
    Antilatency::InterfaceContract::ExceptionCode NodeGetPhysicalPath(const FAdnNode& node, FString& result);

    /**
     * Get the node string property value.
     * @param node The node to get property from.
     * @param key The property name to get value for.
     * @param result The property value.
     * @return ExceptionCode::Ok if the method execution is successful, otherwise returns the appropriate error code.
     */
    Antilatency::InterfaceContract::ExceptionCode NodeGetStringProperty(const FAdnNode& node, const FString& key, FString& result);

    Antilatency::InterfaceContract::ExceptionCode NodeGetBinaryProperty(const FAdnNode& node, const FString& key, TArray<uint8>& result);

    Antilatency::InterfaceContract::ExceptionCode NodeStartPropertyTask(const FAdnNode& node, UPropertyCotask*& result);

    /**
     * Check if the Device Network wrapper initialized properly.
     * @return True if the Device Network wrapper initialized properly, otherwise false.
     */
    bool IsValid() const;

protected:
    template<class TSpecificInterface>
    TSpecificInterface& AsInterface() {
        return *static_cast<TSpecificInterface*>(&_native);
    }

    TInterface _native;
 
};

