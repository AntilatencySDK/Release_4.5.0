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

#include "DeviceNetwork.h"

#include <Antilatency.DeviceNetwork.h>
#include <ObjectConstructor.h>

#include "DeviceNetworkLibrary.generated.h"

/**
 * Provides methods to work with Device Network library.
 * Do not instantiate this class directly by calling NewObject<UDeviceNetworkLibrary> method,
 * use UDeviceNetworkLibrary::GetLibrary instead.
 */
UCLASS(BlueprintType)
class ANTILATENCYDEVICENETWORK_API UDeviceNetworkLibrary : public UObject {
    GENERATED_BODY()

public:
    typedef Antilatency::DeviceNetwork::ILibrary TInterface;
    
    template<class TInterfacedObject>
    friend class ObjectConstructor;
    
    /**
     * Get UDeviceNetworkLibrary instance.
     * @return The UDeviceNetworkLibrary wrapper object. If native Antilatency::DeviceNetwork::ILibrary creation fails, returns nullptr.
     */
    static UDeviceNetworkLibrary* GetLibrary();

    Antilatency::InterfaceContract::ExceptionCode CreateFilter(UDeviceFilter*& result);

    /**
     * Create the device network to work with Antilatency devices.
     * @param deviceFilter The filter for devices that will be used by network.
     * @param result The pointer to the created UDeviceNetwork instance.
     * @return ExceptionCode::Ok if the method execution is successful, otherwise returns the appropriate error code.
     */
    Antilatency::InterfaceContract::ExceptionCode CreateNetwork(UDeviceFilter* deviceFilter, UDeviceNetwork*& result);

    /**
     * Get the Antilatency Device Network library version.
     * @param result The Antilatency Device Network library version.
     * @return ExceptionCode::Ok if the method execution is successful, otherwise returns the appropriate error code.
     */
    Antilatency::InterfaceContract::ExceptionCode GetVersion(FString& result);

    /**
     * Set the log verbosity level for Antilatency Device Network library.
     * @param level The verbosity level to set.
     * @return ExceptionCode::Ok if the method execution is successful, otherwise returns the appropriate error code.
     */
    Antilatency::InterfaceContract::ExceptionCode SetLogLevel(const EDeviceNetworkLogLevel& level);

    /**
     * Check if UDeviceNetworkLibrary has been initialized properly (the native Antilatency::DeviceNetwork::ILibrary is not nullptr).
     * @return True if object is initialized properly, otherwise false.
     */
    bool IsValid() const;

protected:
    template<class TSpecificInterface>
    TSpecificInterface& AsInterface() {
        return *static_cast<TSpecificInterface*>(&_native);
    }

    /** Pointer to native object */
    TInterface _native;
    
};
