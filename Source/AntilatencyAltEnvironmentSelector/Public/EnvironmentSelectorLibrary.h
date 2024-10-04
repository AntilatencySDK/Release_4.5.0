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

#include "AltEnvironment.h"

#include <Antilatency.Alt.Environment.Selector.h>
#include <ObjectConstructor.h>

#include "EnvironmentSelectorLibrary.generated.h"

/**
 * Antilatency::Alt::Environment::Selector::ILibrary wrapper for UE.
 * Do not instantiate this class directly by calling NewObject<UEnvironmentSelectorLibrary> method,
 * use UEnvironmentSelectorLibrary::GetLibrary instead.
 */
UCLASS(BlueprintType)
class ANTILATENCYALTENVIRONMENTSELECTOR_API UEnvironmentSelectorLibrary : public UObject {
	GENERATED_BODY()

public:
    typedef Antilatency::Alt::Environment::Selector::ILibrary TInterface;
    
    template<class TInterfacedObject>
    friend class ObjectConstructor;
    
	static UEnvironmentSelectorLibrary* GetLibrary();
    bool IsValid() const;
	
	Antilatency::InterfaceContract::ExceptionCode CreateEnvironment(const FString& data, UAltEnvironment*& result);

protected:
    template<class TSpecificInterface>
    TSpecificInterface& AsInterface() {
        return *static_cast<TSpecificInterface*>(&_native);
    }
    
	TInterface _native;
};