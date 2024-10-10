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

#include "AltTrackingCotask.h"

#include "AltTrackingLog.h"

#include <InterfaceIdUtils.h>
#include <ExceptionCheck.h>

Antilatency::InterfaceContract::ExceptionCode UAltTrackingCotask::GetState(FTrackingState& result) {
    if (!IsValid()) {
        ALTTRACKING_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    Antilatency::Alt::Tracking::State nativeState;
    auto exception = AsInterface<TInterface>().getState(Antilatency::Alt::Tracking::Constants::DefaultAngularVelocityAvgTime, nativeState);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    result = { nativeState };

    if (result.Pose.Position.ContainsNaN()) {
        result.Pose.Position = FVector::ZeroVector;
    }
    
    if (result.Pose.Rotation.ContainsNaN()) {
        result.Pose.Rotation = FQuat::Identity;
    }
    
    return exception;
}

Antilatency::InterfaceContract::ExceptionCode UAltTrackingCotask::GetExtrapolatedState(const FAltPose& placement, const float deltaTime, FTrackingState& result) {
    if (!IsValid()) {
        ALTTRACKING_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    Antilatency::Alt::Tracking::State nativeState;
    auto exception = AsInterface<TInterface>().getExtrapolatedState(placement.ToNative(), deltaTime, nativeState);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    result = { nativeState };

    if (result.Pose.Position.ContainsNaN()) {
        result.Pose.Position = FVector::ZeroVector;
    }
        
    if (result.Pose.Rotation.ContainsNaN()) {
        result.Pose.Rotation = FQuat::Identity;
    }
        
    return exception;
}
