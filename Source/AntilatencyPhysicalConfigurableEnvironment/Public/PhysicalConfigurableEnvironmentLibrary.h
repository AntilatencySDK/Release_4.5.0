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

#include "PhysicalConfigurableEnvironmentCotaskConstructor.h"

#include <Antilatency.PhysicalConfigurableEnvironment.h>

#include "PhysicalConfigurableEnvironmentLibrary.generated.h"

/**
 * Antilatency::PhysicalConfigurableEnvironment::ILibrary wrapper for UE.
 * Do not instantiate this class directly by calling NewObject<UPhysicalConfigurableEnvironmentLibrary> method,
 * use UPhysicalConfigurableEnvironmentLibrary::GetLibrary instead.
 */
UCLASS(BlueprintType)
class ANTILATENCYPHYSICALCONFIGURABLEENVIRONMENT_API UPhysicalConfigurableEnvironmentLibrary : public UObject {
    GENERATED_BODY()

public:
    typedef Antilatency::PhysicalConfigurableEnvironment::ILibrary TInterface;

	template<class TInterfacedObject>
	friend class ObjectConstructor;

    /**
     * Get the UPhysicalConfigurableEnvironmentLibrary instance.
     */
    static UPhysicalConfigurableEnvironmentLibrary* GetLibrary();

	TInterface GetNative();

	Antilatency::InterfaceContract::ExceptionCode CreateCotaskConstructor(UPhysicalConfigurableEnvironmentCotaskConstructor*& result);

	bool IsValid() const;

protected:
	template<class TSpecificInterface>
	TSpecificInterface& AsInterface() {
		return *static_cast<TSpecificInterface*>(&_native);
	}

	/** A pointer to the native tracking library object. */
	TInterface _native;
};
