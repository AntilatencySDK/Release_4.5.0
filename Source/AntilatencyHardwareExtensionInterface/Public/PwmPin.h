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

#include "HardwareExtensionInterfaceTypes.h"

#include <Antilatency.HardwareExtensionInterface.h>
#include <ObjectConstructor.h>

#include "PwmPin.generated.h"

/**
* An UE wrapper for the Antilatency::HardwareExtensionInterface::IPwmPin.
* Do not instantiate this class directly by calling NewObject<UIPwmPin> method,
* use UHardwareExtensionInterfaceCotask::CreatePulseCounterPin instead.
*/
UCLASS(BlueprintType)
class ANTILATENCYHARDWAREEXTENSIONINTERFACE_API UPwmPin : public UObject {
    GENERATED_BODY()

public:
    typedef Antilatency::HardwareExtensionInterface::IPwmPin TInterface;
    
    template<class TInterfacedObject>
    friend class ObjectConstructor;

    Antilatency::InterfaceContract::ExceptionCode SetDuty(float value);
    Antilatency::InterfaceContract::ExceptionCode GetDuty(float& result);
    Antilatency::InterfaceContract::ExceptionCode GetFrequency(uint32& result);

    bool IsValid() const;

protected:
    template<class TSpecificInterface>
    TSpecificInterface& AsInterface() {
        return *static_cast<TSpecificInterface*>(&_native);
    }

    /** Pointer to native object */
    TInterface _native;
};
