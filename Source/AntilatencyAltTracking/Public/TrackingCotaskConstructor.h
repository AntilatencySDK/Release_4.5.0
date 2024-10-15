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

#include "CotaskConstructor.h"
#include "AltEnvironment.h"
#include "AltTrackingCotask.h"

#include <Antilatency.Alt.Tracking.h>

#include "TrackingCotaskConstructor.generated.h"

/**
 * Antilatency::Alt::Tracking::ITrackingCotaskConstructor wrapper for UE.
 * Do not instantiate this class directly by calling NewObject<UTrackingCotaskConstructor> method,
 * use UAltTrackingLibrary::CreateTrackingCotaskConstructor instead.
 */
UCLASS(BlueprintType)
class ANTILATENCYALTTRACKING_API UTrackingCotaskConstructor : public UCotaskConstructor {
    GENERATED_BODY()

public:
    typedef Antilatency::Alt::Tracking::ITrackingCotaskConstructor TInterface;
    
    /**
     * @brief Start tracking task on node.
     * @param network The pointer to the UDeviceNetwork object.
     * @param node The node to start tracking task on.
     * @param environment The pointer to the UAltEnvironment object.
     * @param result The host part of tracking task (cotask).
     * @return ExceptionCode::Ok if the method execution is successful, otherwise returns the appropriate error code.
     */
    Antilatency::InterfaceContract::ExceptionCode StartTask(UDeviceNetwork* network, const FAdnNode& node, UAltEnvironment* environment, UAltTrackingCotask*& result);
};
