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

#include "BracerTypes.h"
#include "CotaskBatteryPowered.h"

#include <Antilatency.Bracer.h>

#include "BracerCotask.generated.h"

/**
 * An UE wrapper for the host part of the bracer task (cotask). That task can be executed on the bracer nodes to get touchpad data and execute vibration on the device.
 * Do not instantiate this class directly by calling NewObject<UBracerCotask> method,
 * use UBracerCotaskConstructor::StartTask instead.
 */
UCLASS(BlueprintType)
class ANTILATENCYBRACER_API UBracerCotask : public UCotaskBatteryPowered {
    GENERATED_BODY()

public:
    typedef Antilatency::Bracer::ICotask TInterface;

	/**
	 *
	 */
	Antilatency::InterfaceContract::ExceptionCode GetTouchChannelsCount(uint32& result);

	/**
	 * 
	 */
	Antilatency::InterfaceContract::ExceptionCode GetTouchNativeValue(const uint32 channel, uint32& result);

    /**
     * Get the current touchpad value.
     * @param result The current touchpad value.
     * @return ExceptionCode::Ok if the method execution is successful, otherwise returns the appropriate error code.
     */
    Antilatency::InterfaceContract::ExceptionCode GetTouch(const uint32 channel, float& result);

    /**
     * Execute vibration on the device.
     * @return ExceptionCode::Ok if the method execution is successful, otherwise returns the appropriate error code.
     */
    Antilatency::InterfaceContract::ExceptionCode ExecuteVibrationSequence(const TArray<FVibration> vibrationSequence);
};