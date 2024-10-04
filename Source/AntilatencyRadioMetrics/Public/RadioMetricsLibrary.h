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

#include "RadioMetricsCotaskConstructor.h"

#include <Antilatency.RadioMetrics.h>
#include <ObjectConstructor.h>

#include "RadioMetricsLibrary.generated.h"

/** 
 * Provides methods to work with Antilatency Radio Metrics library.
 * Do not instantiate this class directly by calling NewObject<URadioMetricsLibrary> method,
 * use URadioMetricsLibrary::GetLibrary instead.
 */
UCLASS(BlueprintType)
class ANTILATENCYRADIOMETRICS_API URadioMetricsLibrary : public UObject {
    GENERATED_BODY()

public:
    typedef Antilatency::RadioMetrics::ILibrary TInterface;
    
    template<class TInterfacedObject>
    friend class ObjectConstructor;
    
    /** @return RadioMetrics library object */
    static URadioMetricsLibrary* GetLibrary();

    /** @return true if library initialized properly */
    bool IsValid() const;

    Antilatency::InterfaceContract::ExceptionCode GetVersion(FString& result);

    Antilatency::InterfaceContract::ExceptionCode GetCotaskConstructor(URadioMetricsCotaskConstructor*& result);

protected:
    template<class TSpecificInterface>
    TSpecificInterface& AsInterface() {
        return *static_cast<TSpecificInterface*>(&_native);
    }

    /** Pointer to native object */
    TInterface _native;

};
