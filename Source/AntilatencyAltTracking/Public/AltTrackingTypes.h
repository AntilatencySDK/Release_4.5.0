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

#include <Antilatency.Alt.Tracking.h>
#include <Antilatency.Math.h>

#include "MathLibrary.h"

#include "AltTrackingTypes.generated.h"

/** Describes the tracker position and rotation, also used as a placement representation. */
USTRUCT(BlueprintType, Category = "Antilatency|Alt Tracking|Alt Pose")
struct FAltPose {
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Antilatency|Alt Tracking|Alt Pose")
    FVector Position;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Antilatency|Alt Tracking|Alt Pose")
    FQuat Rotation;

    FAltPose() :
        Position(EForceInit::ForceInit),
        Rotation(EForceInit::ForceInit) {}

    FAltPose(const Antilatency::Math::floatP3Q native) {
        Position = FVector(native.position.x, native.position.y, native.position.z);
        Rotation = FQuat(native.rotation.x, native.rotation.y, native.rotation.z, native.rotation.w);
    }

    FAltPose(const FVector& pos, const FQuat& rot) : Position(pos), Rotation(rot) {}

    Antilatency::Math::floatP3Q ToNative() const {
        Antilatency::Math::floatP3Q result;
        result.position = { static_cast<float>(Position.X), static_cast<float>(Position.Y), static_cast<float>(Position.Z) };
        result.rotation = {
            static_cast<float>(Rotation.X),
            static_cast<float>(Rotation.Y),
            static_cast<float>(Rotation.Z),
            static_cast<float>(Rotation.W)
        };
        
        return result;
    }
};

/** Describes the current tracking stage. */
UENUM(BlueprintType, Category = "Antilatency|Alt Tracking|Tracking Stage")
enum class ETrackingStage : uint8 {
    /** Tracker collects the accelerometer data to find the upright orientation. No tracking data is valid in this stage. */
    InertialDataInitialization,
    /** Only the rotation part is valid in this stage. The rotation around the vertical axis may drifts. */
    Tracking3Dof,
    /** A full 6 DoF tracking, corrected by the optics. */
    Tracking6Dof,
    /** Inertial only 6 DoF tracking, without optical corrections. */
    TrackingBlind6Dof
};

/** Describes the current tracking stability. */
USTRUCT(BlueprintType, Category = "Antilatency|Alt Tracking|Tracking Stability")
struct FTrackingStability {
    GENERATED_BODY()

public:
    /** Current tracking stage. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Antilatency|Alt Tracking|Tracking Stability")
    ETrackingStage Stage;

    /**
    * Describes the current stability value.
    * If the tracking stage is InertialDataInitialization or Tracking3Dof, stability value will be always 0.
    * If the tracking stage is Tracking6Dof, this value represents how stable the solution is. Since this value depends on many factors, there is no units for it. This value may be used for debug purposes.
    * If the tracking stage is TrackingBlind6Dof, this value is a fraction of time left before switch to Tracking3Dof - it is useful to notify the user about the oncoming loss of tracking.
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Antilatency|Alt Tracking|Tracking Stability")
    float Value;
    
    FTrackingStability() {
        Stage = ETrackingStage::InertialDataInitialization;
        Value = 0.0f;
    }

    FTrackingStability(const Antilatency::Alt::Tracking::Stability& native) {
        Stage = static_cast<ETrackingStage>(native.stage);
        Value = native.value;
    }

    Antilatency::Alt::Tracking::Stability ToNative() const {
        Antilatency::Alt::Tracking::Stability result;

        result.stage = static_cast<Antilatency::Alt::Tracking::Stage>(Stage);
        result.value = Value;

        return result;
    }
};

/** Describes the current tracking state. */
USTRUCT(BlueprintType, Category = "Antilatency|Alt Tracking|Tracking State")
struct FTrackingState {
    GENERATED_BODY()

public:
    /** Tracker position and rotation. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Antilatency|Alt Tracking|Tracking State")
    FAltPose Pose;

    /** Tracker velocity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Antilatency|Alt Tracking|Tracking State")
    FVector Velocity;

    /** Tracker local angular velocity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Antilatency|Alt Tracking|Tracking State")
    FVector LocalAngularVelocity;

    /** Current tracking stability. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Antilatency|Alt Tracking|Tracking State")
    FTrackingStability Stability;
    
    FTrackingState() {
        Pose = {};
        Velocity = {};
        LocalAngularVelocity = {};
        Stability = {};
    }

    FTrackingState(const Antilatency::Alt::Tracking::State native) {
        Pose = FAltPose(native.pose);
        Velocity = {native.velocity.x, native.velocity.y, native.velocity.z};
        LocalAngularVelocity = { native.localAngularVelocity.x, native.localAngularVelocity.y, native.localAngularVelocity.z};
        Stability = FTrackingStability(native.stability);
    }

    Antilatency::Alt::Tracking::State ToNative() const {
        Antilatency::Alt::Tracking::State result;

        result.pose = Pose.ToNative();
        result.velocity = { static_cast<float>(Velocity.X), static_cast<float>(Velocity.Y), static_cast<float>(Velocity.Z) };
        result.localAngularVelocity = { static_cast<float>(LocalAngularVelocity.X), static_cast<float>(LocalAngularVelocity.Y), static_cast<float>(LocalAngularVelocity.Z) };
        result.stability = Stability.ToNative();

        return result;
    }
};
