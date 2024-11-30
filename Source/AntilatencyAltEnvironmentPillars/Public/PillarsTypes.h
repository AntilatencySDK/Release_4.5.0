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

#include <Antilatency.Alt.Environment.Pillars.h>

#include "UObject/NoExportTypes.h"

#include "PillarsTypes.generated.h"

USTRUCT(BlueprintType, Category = "Antilatency|Alt|Environment|Pillars")
struct FPillarsData {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Antilatency|Alt|Environment|Pillars")
	FVector Position;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Antilatency|Alt|Environment|Pillars")
	int32 Kind;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Antilatency|Alt|Environment|Pillars")
	float Angle01;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Antilatency|Alt|Environment|Pillars")
	float Fov01;

    FPillarsData() :
        Position(EForceInit::ForceInit),
        Kind(EForceInit::ForceInit),
		Angle01(EForceInit::ForceInit),
		Fov01(EForceInit::ForceInit){}

	FPillarsData(const FVector& position, const int32 kind, const float angle01, const float fov01) : Position(position), Kind(kind), Angle01(angle01), Fov01(fov01){}

	FPillarsData(const Antilatency::Alt::Environment::Pillars::PillarData& native) {
		Position = FVector(native.position.z * 100.0f, native.position.x * 100.0f, native.position.y * 100.0f);
		Kind = static_cast<int32>(native.kind);
    	Angle01 = native.angle01;
    	Fov01 = native.fov01;
	}

	Antilatency::Alt::Environment::Pillars::PillarData ToNative() const {
		Antilatency::Alt::Environment::Pillars::PillarData result;
        
		result.position = { static_cast<float>(Position.Y) / 100.0f, static_cast<float>(Position.Z) / 100.0f, static_cast<float>(Position.X) / 100.0f };
		result.kind = static_cast<uint32_t>(Kind);
		result.angle01 = Angle01;
    	result.fov01 = Fov01;
    	
		return result;
	}
};

