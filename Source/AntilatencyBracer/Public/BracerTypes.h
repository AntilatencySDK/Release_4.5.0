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

#include <Antilatency.Bracer.h>

#include "BracerTypes.generated.h"

/**
 * The UE wrapper for the Antilatency::Bracer::Vibration.
 */
USTRUCT(BlueprintType, Category = "Antilatency|Bracer|Vibration")
struct FVibration {
	GENERATED_BODY()

	FVibration() : Intensity(0.0f), Duration(0.0f) {}
	FVibration(Antilatency::Bracer::Vibration native) : Intensity(native.intensity), Duration(native.duration) {}
	FVibration(float intensity, float duration) : Intensity(intensity), Duration(duration) {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Antilatency|Bracer|Vibration")
	float Intensity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Antilatency|Bracer|Vibration")
	float Duration;

	Antilatency::Bracer::Vibration ToNative() const {
		Antilatency::Bracer::Vibration result;

		result.intensity = Intensity;
		result.duration = Duration;

		return result;
	}
};
