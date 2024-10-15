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

#include "DeviceNetwork.h"
#include "BracerCotaskConstructor.h"

#include <Antilatency.Bracer.h>
#include <ObjectConstructor.h>

#include "BracerLibrary.generated.h"

/** 
 * Provides methods to work with Antilatency Bracer library.
 * Do not instantiate this class directly by calling NewObject<UBracerLibrary> method,
 * use UBracerLibrary::GetLibrary instead.
 */
UCLASS(BlueprintType)
class ANTILATENCYBRACER_API UBracerLibrary : public UObject {
    GENERATED_BODY()

public:
    typedef Antilatency::Bracer::ILibrary TInterface;
    
    template<class TInterfacedObject>
    friend class ObjectConstructor;
    
    /** @return bracer library object */
    static UBracerLibrary* GetLibrary();

    /** @return true if library initialized properly */
    bool IsValid() const;

    Antilatency::InterfaceContract::ExceptionCode GetVersion(FString& result);

    Antilatency::InterfaceContract::ExceptionCode GetCotaskConstructor(UBracerCotaskConstructor*& result);

protected:
    template<class TSpecificInterface>
    TSpecificInterface& AsInterface() {
        return *static_cast<TSpecificInterface*>(&_native);
    }
    
    Antilatency::Bracer::ILibrary _native;
};