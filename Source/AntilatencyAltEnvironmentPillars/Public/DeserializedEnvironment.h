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

#include "PillarsTypes.h"
#include "PillarsScheme.h"

#include <Antilatency.Alt.Environment.Pillars.h>
#include <ObjectConstructor.h>

#include "DeserializedEnvironment.generated.h"

/**
* Antilatency::Alt::Environment::Pillars::IDeserializedEnvironment wrapper for UE.
* Do not instantiate this class directly by calling NewObject<UDeserializedEnvironment> method,
* use UPillarsLibrary::DeserializeEnvironment instead.
 */
UCLASS(BlueprintType)
class ANTILATENCYALTENVIRONMENTPILLARS_API UDeserializedEnvironment : public UObject {
	GENERATED_BODY()

public:
    typedef Antilatency::Alt::Environment::Pillars::IDeserializedEnvironment TInterface;
    
    template<class TInterfacedObject>
    friend class ObjectConstructor;

	TInterface GetNative();
    bool IsValid() const;

    
	Antilatency::InterfaceContract::ExceptionCode GetPillars(TArray<FPillarsData>& result);
	Antilatency::InterfaceContract::ExceptionCode GetScheme(UPillarsScheme*& result);

protected:
    template<class TSpecificInterface>
    TSpecificInterface& AsInterface() {
        return *static_cast<TSpecificInterface*>(&_native);
    }
    
private:
	TInterface _native;
};
