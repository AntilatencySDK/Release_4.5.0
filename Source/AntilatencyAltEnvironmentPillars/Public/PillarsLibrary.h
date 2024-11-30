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

#include "DeserializedEnvironment.h"
#include "PillarsScheme.h"
#include "PillarsTypes.h"
#include "EnvironmentConstructor.h"

#include <Antilatency.Alt.Environment.Pillars.h>

#include "PillarsLibrary.generated.h"

/**
 * Antilatency::Alt::Environment::Pillars::ILibrary wrapper for UE.
 * Do not instantiate this class directly by calling NewObject<UPillarsLibrary> method,
 * use UPillarsLibrary::GetPillarsLibrary instead.
 */
UCLASS(BlueprintType)
class ANTILATENCYALTENVIRONMENTPILLARS_API UPillarsLibrary : public UEnvironmentConstructor {
	GENERATED_BODY()

public:
    typedef Antilatency::Alt::Environment::Pillars::ILibrary TInterface;
    
	static UPillarsLibrary* GetPillarsLibrary();

	Antilatency::InterfaceContract::ExceptionCode SerializeEnvironment(const TArray<FPillarsData>& pillars, UPillarsScheme* scheme, FString& result);
	Antilatency::InterfaceContract::ExceptionCode DeserializeEnvironment(const FString& environmentData, UDeserializedEnvironment*& result);
};
