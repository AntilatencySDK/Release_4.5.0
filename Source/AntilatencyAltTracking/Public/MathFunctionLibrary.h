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
#include "Kismet/BlueprintFunctionLibrary.h"

#include "MathFunctionLibrary.generated.h"

/**
 * Provides several useful math methods in blueprints.
 */
UCLASS()
class ANTILATENCYALTTRACKING_API UMathFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()

public:
    /**
     * Create FQuat.
     * @param x Result quaternion's X value.
     * @param y Result quaternion's Y value.
     * @param z Result quaternion's Z value.
     * @param w Result quaternion's W value.
     * @return FQuat constructed from provided values.
     */
    UFUNCTION(BlueprintPure, meta = (DisplayName = "Make Quaternion", CompactNodeTitle = "Make Quat"), Category = "Math")
    static FQuat MakeFQuat(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 1.0f);

    /**
     * Create identity FQuat.
     * @return Identity FQuat (x = 0.0, y = 0.0, z = 0.0, w = 1.0).
     */
    UFUNCTION(BlueprintPure, meta = (DisplayName = "Identity Quaternion", CompactNodeTitle = "Identity Quat"), Category = "Math")
    static FQuat FQuatIdentity();

    /**
     * Convert FRotator to FQuat.
     * @param r A rotator to convert to FQuat.
     * @return A quaternion created from provided rotator.
     */
    UFUNCTION(BlueprintPure, meta = (DisplayName = "Rotator to Quaternion", CompactNodeTitle = "To Quat"), Category = "Math")
    static FQuat FRotatorToFQuat(const FRotator& r = FRotator::ZeroRotator);

    /**
     * Convert FQuat to FRotator.
     * @param q A quaternion to convert to rotator.
     * @return A rotator created from provided quaternion.
     */
    UFUNCTION(BlueprintPure, meta = (DisplayName = "Quaternion to Rotator", CompactNodeTitle = "To Rotator"), Category = "Math")
    static FRotator FQuatToFRotator(const FQuat& q);

    
    /**
     * Combines two quaternions.
     * Order matters when composing quaternions: C = A * B will yield a quaternion C that logically first applies B then A to any subsequent transformation (right first, then left).
     * @return The result quaternion.
     */
    UFUNCTION(BlueprintPure, meta = (DisplayName = "Multiply Quaternions", CompactNodeTitle = "*", Keywords = "* multiply"), Category = "Math")
    static FQuat MultFQuatFQuat(const FQuat& q1, const FQuat& q2);

    /**
     * Inverse quaternion.
     * @param q A quaternion to inverse.
     * @return Inverse of the provided quaternion.
     */
    UFUNCTION(BlueprintPure, meta = (DisplayName = "Inverse Quaternion", CompactNodeTitle = "Inverse", Keywords = "inverse"), Category = "Math")
    static FQuat InverseFQuat(const FQuat& q);

    /**
     * Fast Linear Quaternion Interpolation. Result is NOT normalized.
     * @param q1 First quaternion.
     * @param q2 Second quaternion.
     * @param alpha Interpolation value.
     * @return Result quaternion, not normalized.
     */
    UFUNCTION(BlueprintPure, meta = (DisplayName = "Fast Lerp Quaternion", CompactNodeTitle = "Fast Lerp", Keywords = "fast lerp"), Category = "Math")
    static FQuat FastLerpFQuat(const FQuat& q1, const FQuat& q2, float alpha);

    /**
     * Spherical interpolation. Will correct alignment. Result is normalized.
     * @param q1 First quaternion.
     * @param q2 Second quaternion.
     * @param alpha Interpolation value.
     * @return Result quaternion, normalized.
     */
    UFUNCTION(BlueprintPure, meta = (DisplayName = "Spherical Lerp Quaternion", CompactNodeTitle = "SLerp", Keywords = "spherical lerp"), Category = "Math")
    static FQuat SLerpFQuat(const FQuat& q1, const FQuat& q2, float alpha);

    /**
     * Normalize this quaternion if it is large enough. If it is too small, returns an identity quaternion.
     * @param q A quaternion to normalize.
     * @param tolerance Minimum squared length of quaternion for normalization.
     * @return Normalized quaternion.
     */
    UFUNCTION(BlueprintPure, meta = (DisplayName = "Normalize Quaternion", CompactNodeTitle = "Normalize", Keywords = "normalize"), Category = "Math")
    static FQuat NormalizeFQuat(const FQuat& q, float tolerance);

    /**
     * Find the angular distance between two rotation quaternions (in radians).
     * @param q1 First quaternion.
     * @param q2 Second quaternion.
     * @return The angular distance between two rotation quaternions (in radians).
     */
    UFUNCTION(BlueprintPure, meta = (DisplayName = "Angular Distance", CompactNodeTitle = "Angle", Keywords = "angle angular distance"), Category = "Math")
    static float FQuatAngularDistance(const FQuat& q1, const FQuat& q2);

    /**
     * Convert vector from Antilatency space to UE.
     * @param source The vector in Antilatency space.
     * @return The vector in UE space.
     */
    UFUNCTION(BlueprintPure, Category = "Antilatency|Math")
    static FVector AntilatencyVectorToUe(const FVector& source);

    /**
    * Convert vector from UE space to Antilatency.
    * @param source The vector in UE space.
    * @return The vector in Antilatency space.
    */
    UFUNCTION(BlueprintPure, Category = "Antilatency|Math")
    static FVector UeVectorToAntilatency(const FVector& source);

    /**
    * Convert quaternion from Antilatency space to UE.
    * @param source The quaternion in Antilatency space.
    * @return The quaternion in UE space.
    */
    UFUNCTION(BlueprintPure, Category = "Antilatency|Math")
    static FQuat AntilatencyQuatToUe(const FQuat& source);

    /**
    * Convert quaternion from UE space to Antilatency.
    * @param source The quaternion in UE space.
    * @return The quaternion in Antilatency space.
    */
    UFUNCTION(BlueprintPure, Category = "Antilatency|Math")
    static FQuat UeQuatToAntilatency(const FQuat& source);
};