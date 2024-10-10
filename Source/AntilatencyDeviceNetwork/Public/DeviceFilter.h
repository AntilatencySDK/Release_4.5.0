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

#include "DeviceNetworkTypes.h"

#include <Antilatency.DeviceNetwork.h>
#include <ObjectConstructor.h>

#include "DeviceFilter.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class ANTILATENCYDEVICENETWORK_API UDeviceFilter : public UObject {
    GENERATED_BODY()

public:
    typedef Antilatency::DeviceNetwork::IDeviceFilter TInterface;
    
    template<class TInterfacedObject>
    friend class ObjectConstructor;

    TInterface GetNative();

    Antilatency::InterfaceContract::ExceptionCode AddUsbDevice(const FUsbDeviceFilter& usbDeviceFilter);
    Antilatency::InterfaceContract::ExceptionCode AddIpDevice(const FString& ip, const FString& mask);
    Antilatency::InterfaceContract::ExceptionCode GetUsbDevice(const uint32 index, FUsbDeviceFilter& result);
    Antilatency::InterfaceContract::ExceptionCode GetIpDevice(const uint32 index, FString& result);
    Antilatency::InterfaceContract::ExceptionCode GetIpDeviceMask(const uint32 index, FString& result);

    bool IsValid() const;
    
protected:
    template<class TSpecificInterface>
    TSpecificInterface& AsInterface() {
        return *static_cast<TSpecificInterface*>(&_native);
    }

    TInterface _native;

};
