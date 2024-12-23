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

#include "InputPin.h"
#include "OutputPin.h"
#include "AnalogPin.h"
#include "PulseCounterPin.h"
#include "PwmPin.h"
#include "HardwareExtensionInterfaceTypes.h"
#include "Cotask.h"

#include <Antilatency.HardwareExtensionInterface.h>
#include <Antilatency.HardwareExtensionInterface.Interop.h>
#include <ObjectConstructor.h>

#include "HardwareExtensionInterfaceCotask.generated.h"

/**
 * An UE wrapper for the host part of the hardware extension interface task (cotask).
 * Do not instantiate this class directly by calling NewObject<UHardwareExtensionInterfaceCotask> method,
 * use UHardwareExtensionInterfaceCotaskConstructor::StartTask instead.
 */
UCLASS(BlueprintType)
class ANTILATENCYHARDWAREEXTENSIONINTERFACE_API UHardwareExtensionInterfaceCotask : public UCotask {
    GENERATED_BODY()

public:
    typedef Antilatency::HardwareExtensionInterface::ICotask TInterface;
    
	/**
	 * @return ExceptionCode::Ok if the method execution is successful, otherwise returns the appropriate error code.
	 */
	Antilatency::InterfaceContract::ExceptionCode CreateInputPin(const EPins& pin, UInputPin*& result);

	/**
	 * @return ExceptionCode::Ok if the method execution is successful, otherwise returns the appropriate error code.
	 */
	Antilatency::InterfaceContract::ExceptionCode CreateOutputPin(const EPins& pin, const EPinState& initialState, UOutputPin*& result);

	/**
	 * @return ExceptionCode::Ok if the method execution is successful, otherwise returns the appropriate error code.
	 */
	Antilatency::InterfaceContract::ExceptionCode CreateAnalogPin(const EPins& pin, const uint32 refreshIntervalMs, UAnalogPin*& result);

	/**
	 * @return ExceptionCode::Ok if the method execution is successful, otherwise returns the appropriate error code.
	 */
	Antilatency::InterfaceContract::ExceptionCode CreatePulseCounterPin(const EPins& pin, const uint32 refreshIntervalMs, UPulseCounterPin*& result);

    /**
     * @return ExceptionCode::Ok if the method execution is successful, otherwise returns the appropriate error code.
     */
    Antilatency::InterfaceContract::ExceptionCode CreatePwmPin(const EPins& pin, uint32 frequency, float initialDuty, UPwmPin*& result);

	/**
	 * @return ExceptionCode::Ok if the method execution is successful, otherwise returns the appropriate error code.
	 */
	Antilatency::InterfaceContract::ExceptionCode Run();
};