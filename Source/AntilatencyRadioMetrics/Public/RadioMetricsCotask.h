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

#include "DeviceNetworkTypes.h"
#include "RadioMetricsTypes.h"
#include "Cotask.h"

#include <Antilatency.RadioMetrics.h>
#include <Antilatency.RadioMetrics.Interop.h>

#include "RadioMetricsCotask.generated.h"

/**
 * An UE wrapper for the host part of the radio metrics task (cotask). That task can be executed on the USB Radio Socket nodes to get radio metrics data.
 * Do not instantiate this class directly by calling NewObject<URadioMetricsCotask> method,
 * use URadioMetricsCotaskConstructor::StartTask instead.
 */
UCLASS(BlueprintType)
class ANTILATENCYRADIOMETRICS_API URadioMetricsCotask : public UCotask {
    GENERATED_BODY()

public:
    typedef Antilatency::RadioMetrics::ICotask TInterface;

	/**
	 * Get simplified metrics.
	 * @param targetNode A slave radio node to get metrics.
	 * @param result Resulting simplified metrics.
	 * ExceptionCode::Ok if the method execution is successful, otherwise returns the appropriate error code.
	 */
	Antilatency::InterfaceContract::ExceptionCode GetMetrics(const FAdnNode& targetNode, FRadioMetrics& result);

	/**
	 * Get extended metrics.
	 * @param targetNode A slave radio node to get metrics.
	 * @param result Resulting extended metrics.
	 * ExceptionCode::Ok if the method execution is successful, otherwise returns the appropriate error code.
	 */
	Antilatency::InterfaceContract::ExceptionCode GetExtendedMetrics(const FAdnNode& targetNode, FExtendedMetrics& result);
};
