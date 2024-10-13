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

#include <Antilatency.PhysicalConfigurableEnvironment.h>

#include "PhysicalConfigurableEnvironmentCotask.generated.h"

/**
 * An UE wrapper for the host part of the PhysicalConfigurableEnvironment task (cotask).
 * Do not instantiate this class directly by calling the NewObject<UPhysicalConfigurableEnvironmentCotask> method,
 * use the UPhysicalConfigurableEnvironmentCotaskConstructor::StartTask instead.
 */
UCLASS(BlueprintType)
class ANTILATENCYPHYSICALCONFIGURABLEENVIRONMENT_API UPhysicalConfigurableEnvironmentCotask : public UCotask {
    GENERATED_BODY()

public:
    typedef Antilatency::PhysicalConfigurableEnvironment::ICotask TInterface;

	Antilatency::InterfaceContract::ExceptionCode GetConfigId(uint32_t& result);
	Antilatency::InterfaceContract::ExceptionCode SetConfigId(uint32_t configId);
	Antilatency::InterfaceContract::ExceptionCode GetConfigCount(uint32_t& result);
	Antilatency::InterfaceContract::ExceptionCode GetEnvironment(uint32_t configId, FString& result);
	Antilatency::InterfaceContract::ExceptionCode GetMarkersConfig(uint32_t configId, TArray<bool>& result);
	Antilatency::InterfaceContract::ExceptionCode GetScreenPosition(FVector& result);
	Antilatency::InterfaceContract::ExceptionCode GetScreenX(FVector& result);
	Antilatency::InterfaceContract::ExceptionCode GetScreenY(FVector& result);
};