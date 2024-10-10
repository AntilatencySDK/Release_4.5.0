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
#include "Kismet/BlueprintFunctionLibrary.h"

#include "RadioMetricsLibrary.h"
#include "RadioMetricsCotaskConstructor.h"
#include "RadioMetricsCotask.h"

#include "RadioMetricsFunctionLibrary.generated.h"

/** An additional enum that is used by the blueprint methods to allow user to check if called method has been executed successfully or not. */
UENUM(BlueprintType)
enum class ERadioMetricsExceptionResult : uint8 {
    /** The method executed successfully. */
    Success = 1 UMETA(DisplayName = "Success"),
    /** The method execution failed with some exception. */
    Fail = 0 UMETA(DisplayName = "Fail"),
};

/**
 * Provides Radio Metrics module's methods wrappers for the UE blueprint system.
 */
UCLASS()
class ANTILATENCYRADIOMETRICS_API URadioMetricsFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:

#pragma region URadioMetricsLibrary
    /**
     * Get the native radio metrics library object.
     * @param result The native radio metrics library object.
     * @param exception Method execution result.
     */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|Radio Metrics|Library", Meta = (ExpandEnumAsExecs = "exception"))
    static void GetLibrary(URadioMetricsLibrary*& result, ERadioMetricsExceptionResult& exception);

    /**
    * Check if URadioMetricsLibrary has been initialized properly (the URadioMetricsLibrary is not nullptr and the native Antilatency::RadioMetrics::ILibrary is not nullptr).
    * @param radioMetricsLibrary A pointer to the URadioMetricsLibrary object.
    * @return True if object is initialized properly, otherwise false.
    */
    UFUNCTION(BlueprintPure, Category = "Antilatency|Radio Metrics|Library")
    static bool IsLibraryValid(const URadioMetricsLibrary* radioMetricsLibrary);

    UFUNCTION(BlueprintCallable, Category = "Antilatency|Radio Metrics|Library", Meta = (ExpandEnumAsExecs = "exception"))
    static void GetVersion(UPARAM(ref) URadioMetricsLibrary* library, FString& result, ERadioMetricsExceptionResult& exception);

    UFUNCTION(BlueprintCallable, Category = "Antilatency|Radio Metrics|Library", Meta = (ExpandEnumAsExecs = "exception"))
    static void GetCotaskConstructor(UPARAM(ref) URadioMetricsLibrary* library, URadioMetricsCotaskConstructor*& result, ERadioMetricsExceptionResult& exception);
#pragma endregion 

#pragma region URadioMetricsCotaskConstructor
    /**
    * Create the radio metrics task on the node.
    * @param constructor A pointer to the URadioMetricsCotaskConstructor object.
    * @param network A pointer to the UDeviceNetwork object.
    * @param node A node to start the radio metrics task on.
    * @param result A result pointer to the radio metrics cotask.
    * @param exception Method execution result.
    */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|Radio Metrics|Cotask Constructor", Meta = (ExpandEnumAsExecs = "exception"))
    static void StartTask(UPARAM(ref) URadioMetricsCotaskConstructor* constructor, UPARAM(ref) UDeviceNetwork* network, const FAdnNode& node, URadioMetricsCotask*& result, ERadioMetricsExceptionResult& exception);
#pragma endregion 

#pragma region URadioMetricsCotask
	/**
	 * Get simplified metrics.
	 * @param radioMetricsCotask A pointer to the URadioMetricsCotask object.
	 * @param targetNode A slave radio node to get metrics.
	 * @param result Resulting simplified metrics.
	 * @param exception Method execution result.
	 */
	UFUNCTION(BlueprintCallable, Category = "Antilatency|Radio Metrics|Cotask", Meta = (ExpandEnumAsExecs = "exception"))
	static void GetMetrics(UPARAM(ref) URadioMetricsCotask* radioMetricsCotask, const FAdnNode& targetNode, FRadioMetrics& result, ERadioMetricsExceptionResult& exception);

	/**
	 * Get extended metrics.
	 * @param radioMetricsCotask A pointer to the URadioMetricsCotask object.
	 * @param targetNode A slave radio node to get metrics.
	 * @param result Resulting simplified metrics.
	 * @param exception Method execution result.
	 */
	UFUNCTION(BlueprintCallable, Category = "Antilatency|Radio Metrics|Cotask", Meta = (ExpandEnumAsExecs = "exception"))
	static void GetExtendedMetrics(UPARAM(ref) URadioMetricsCotask* radioMetricsCotask, const FAdnNode& targetNode, FExtendedMetrics& result, ERadioMetricsExceptionResult& exception);
};
