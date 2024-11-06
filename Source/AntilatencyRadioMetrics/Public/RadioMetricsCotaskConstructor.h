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

#include "RadioMetricsCotask.h"
#include "CotaskConstructor.h"
#include "DeviceNetwork.h"
#include "DeviceNetworkTypes.h"

#include <Antilatency.RadioMetrics.h>

#include "RadioMetricsCotaskConstructor.generated.h"

/**
 * The UE wrapper for the Antilatency::RadioMetrics::ICotaskConstructor object.
 * Do not instantiate this class directly by calling the NewObject<URadioMetricsCotaskConstructor> method,
 * use the URadioMetricsLibrary::GetCotaskConstructor instead.
 */
UCLASS(BlueprintType)
class ANTILATENCYRADIOMETRICS_API URadioMetricsCotaskConstructor : public UCotaskConstructor {
    GENERATED_BODY()

public:
    typedef Antilatency::RadioMetrics::ICotaskConstructor TInterface;
    
    Antilatency::InterfaceContract::ExceptionCode StartTask(UDeviceNetwork* network, const FAdnNode& node, URadioMetricsCotask*& result);
};
