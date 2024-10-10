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

#include <Antilatency.TrackingAlignment.h>
#include <Antilatency.Math.h>

#include "TrackingAlignmentTypes.generated.h"

USTRUCT(BlueprintType, Category = "Antilatency|Tracking Alignment")
struct FTrackingAlignmentState {
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Antilatency|Tracking Alignment|Tracking Alignment State")
    FQuat RotationARelativeToB;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Antilatency|Tracking Alignment|Tracking Alignment State")
    FQuat RotationBSpace;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Antilatency|Tracking Alignment|Tracking Alignment State")
	float TimeBAheadOfA;

	FTrackingAlignmentState() :
		RotationARelativeToB(EForceInit::ForceInit),
		RotationBSpace(EForceInit::ForceInit),
		TimeBAheadOfA(EForceInit::ForceInit) {}

    FTrackingAlignmentState(const Antilatency::TrackingAlignment::State native) {
        RotationARelativeToB = FQuat(native.rotationARelativeToB.x, native.rotationARelativeToB.y, native.rotationARelativeToB.z, native.rotationARelativeToB.w);
        RotationBSpace = FQuat(native.rotationBSpace.x, native.rotationBSpace.y, native.rotationBSpace.z, native.rotationBSpace.w);
        TimeBAheadOfA = native.timeBAheadOfA;
    }

    FTrackingAlignmentState(const FQuat& rotationARelativeToB, const FQuat& rotationBSpace, const float timeBAheadOfA) :
        RotationARelativeToB(rotationARelativeToB),
        RotationBSpace(rotationBSpace),
        TimeBAheadOfA(timeBAheadOfA) {}

    Antilatency::TrackingAlignment::State ToNative() const {
        Antilatency::TrackingAlignment::State result;
        result.rotationARelativeToB = {
            static_cast<float>(RotationARelativeToB.X),
            static_cast<float>(RotationARelativeToB.Y),
            static_cast<float>(RotationARelativeToB.Z),
            static_cast<float>(RotationARelativeToB.W)
        };
        result.rotationBSpace = {
            static_cast<float>(RotationBSpace.X),
            static_cast<float>(RotationBSpace.Y),
            static_cast<float>(RotationBSpace.Z),
            static_cast<float>(RotationBSpace.W)
        };
        result.timeBAheadOfA = TimeBAheadOfA;
        
        return result;
    }
};
