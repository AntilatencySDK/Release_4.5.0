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

#include "Arbitrary2DDeserializedEnvironment.h"
#include "EnvironmentConstructor.h"

#include <Antilatency.Alt.Environment.Arbitrary2D.h>

#include "Arbitrary2DLibrary.generated.h"

/**
 * Antilatency::Alt::Environment::Arbitrary2D::ILibrary wrapper for UE.
 * Do not instantiate this class directly by calling NewObject<UArbitrary2DLibrary> method,
 * use UArbitrary2DLibrary::GetArbitrary2DLibrary instead.
 */
UCLASS(BlueprintType)
class ANTILATENCYALTENVIRONMENTARBITRARY2D_API UArbitrary2DLibrary : public UEnvironmentConstructor {
	GENERATED_BODY()

public:
    typedef Antilatency::Alt::Environment::Arbitrary2D::ILibrary TInterface;
    
	static UArbitrary2DLibrary* GetArbitrary2DLibrary();

	Antilatency::InterfaceContract::ExceptionCode SerializeEnvironment(
		const TArray<FVector2D>& markers,
		const float height,
		const bool floor,
		FString& result);

	Antilatency::InterfaceContract::ExceptionCode DeserializeEnvironment(const FString& environmentData, UArbitrary2DDeserializedEnvironment*& result);
};
