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

#include "Cotask.h"
#include "AltTrackingTypes.h"

#include <Antilatency.Alt.Tracking.h>

#include "AltTrackingCotask.generated.h"

/**
 * An UE wrapper for the host part of the alt tracking task (cotask). That task can be executed on the Alt tracker nodes to get tracking data.
 * Do not instantiate this class directly by calling the NewObject<UAltTrackingCotask> method,
 * use the UTrackingCotaskConstructor::StartTask instead.
 */
UCLASS(BlueprintType)
class ANTILATENCYALTTRACKING_API UAltTrackingCotask : public UCotask {
    GENERATED_BODY()

public:
    typedef Antilatency::Alt::Tracking::ITrackingCotask TInterface;

    /**
    * Get raw tracking state without extrapolation and placement applied.
    * @param result Result raw tracking state.
    * @return ExceptionCode::Ok if the method execution is successful, otherwise returns the appropriate error code.
    */
    Antilatency::InterfaceContract::ExceptionCode GetState(FTrackingState& result);

    /**
    * Get tracking state with placement and extrapolation corrections applied.
    * @param placement A placement pose that will be used for the tracking pose correction.
    * @param deltaTime An tracking extrapolation time.
    * @param result Result tracking state.
    * @return ExceptionCode::Ok if the method execution is successful, otherwise returns the appropriate error code.
    */
    Antilatency::InterfaceContract::ExceptionCode GetExtrapolatedState(const FAltPose& placement, const float deltaTime, FTrackingState& result);
};