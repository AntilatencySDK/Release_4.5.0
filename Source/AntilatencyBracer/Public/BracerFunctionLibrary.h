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

#include "BracerLibrary.h"
#include "BracerCotaskConstructor.h"
#include "BracerCotask.h"
#include "BracerTypes.h"

#include "BracerFunctionLibrary.generated.h"

/** An additional enum that is used by the blueprint methods to allow user to check if called method has been executed successfully or not. */
UENUM(BlueprintType)
enum class EBracerExceptionResult : uint8 {
    /** The method executed successfully. */
    Success = 1 UMETA(DisplayName = "Success"),
    /** The method execution failed with some exception. */
    Fail = 0 UMETA(DisplayName = "Fail"),
};

/**
 * Provides Bracer module's methods wrappers for the UE blueprint system.
 */
UCLASS()
class ANTILATENCYBRACER_API UBracerFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:

#pragma region UBracerLibrary
    /**
     * Get the native bracer library object.
     * @param result The native bracer library object.
     * @param exception Method execution result.
     */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|Bracer|Library", Meta = (ExpandEnumAsExecs = "exception"))
    static void GetLibrary(UBracerLibrary*& result, EBracerExceptionResult &exception);

    /**
    * Check if UBracerLibrary has been initialized properly (the UBracerLibrary is not nullptr and the native Antilatency::Bracer::ILibrary is not nullptr).
    * @param bracerLibrary A pointer to the UBracerLibrary object.
    * @return True if object is initialized properly, otherwise false.
    */
    UFUNCTION(BlueprintPure, Category = "Antilatency|Bracer|Library")
    static bool IsLibraryValid(const UBracerLibrary* bracerLibrary);

    UFUNCTION(BlueprintPure, Category = "Antilatency|Bracer|Library", Meta = (ExpandEnumAsExecs = "exception"))
    static void GetVersion(UPARAM(ref) UBracerLibrary* bracerLibrary, FString& result, EBracerExceptionResult &exception);

    UFUNCTION(BlueprintCallable, Category = "Antilatency|Bracer|Library", Meta = (ExpandEnumAsExecs = "exception"))
    static void GetCotaskConstructor(UPARAM(ref) UBracerLibrary* bracerLibrary, UBracerCotaskConstructor*& result, EBracerExceptionResult &exception);
#pragma endregion 

#pragma region UBracerCotaskConstructor
    /**
     * Create the bracer task on the node.
     * @param constructor A pointer to the UBracerCotaskConstructor object.
     * @param network A pointer to the UDeviceNetwork object.
     * @param node A node to start the bracer task on.
     * @param result A result pointer to the bracer cotask.
     * @param exception Method execution result.
     */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|Bracer|Cotask Constructor", Meta = (ExpandEnumAsExecs = "exception"))
    static void StartTask(UPARAM(ref) UBracerCotaskConstructor* constructor, UPARAM(ref) UDeviceNetwork* network, const FAdnNode &node, UBracerCotask*& result, EBracerExceptionResult& exception);
#pragma endregion 

#pragma region UBracerCotask
	/**
	 * Get touch channels count.
	 * @param bracerCotask A pointer to the UBracerCotask object.
	 * @param result Bracer's touch channels count.
	 * @param exception Method execution result.
	 */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|Bracer|Cotask", Meta = (ExpandEnumAsExecs = "exception"))
	static void GetTouchChannelsCount(UPARAM(ref) UBracerCotask* bracerCotask, int32& result, EBracerExceptionResult& exception);

	/**
	 * Get the raw touchpad trigger value.
	 * @param bracerCotask A pointer to the UBracerCotask object.
	 * @param channel Bracer channel.
	 * @param result The current touchpad value.
	 * @param exception Method execution result.
	 */
	UFUNCTION(BlueprintCallable, Category = "Antilatency|Bracer|Cotask", Meta = (ExpandEnumAsExecs = "exception"))
	static void GetTouchNativeValue(UPARAM(ref) UBracerCotask* bracerCotask, const int32 channel, int32& result, EBracerExceptionResult& exception);

    /**
     * Get the current touchpad value.
     * @param bracerCotask A pointer to the UBracerCotask object.
	 * @param channel Bracer channel.
     * @param result The current touchpad value.
     * @param exception Method execution result.
     */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|Bracer|Cotask", Meta = (ExpandEnumAsExecs = "exception"))
    static void GetTouch(UPARAM(ref) UBracerCotask* bracerCotask, const int32 channel, float& result, EBracerExceptionResult& exception);

    /**
     * Execute vibration on the device.
     * @param bracerCotask A pointer to the UBracerCotask object.
     * @param exception Method execution result.
     */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|Bracer|Cotask", Meta = (ExpandEnumAsExecs = "exception"))
    static void ExecuteVibrationSequence(UPARAM(ref) UBracerCotask* bracerCotask, const TArray<FVibration>& vibrationSequence, EBracerExceptionResult& exception);
#pragma endregion

#pragma region Constants
    UFUNCTION(BlueprintPure, Category = "Antilatency|Bracer|Constants")
    static void GetTouchWindowBaseName(FString& result);

    UFUNCTION(BlueprintPure, Category = "Antilatency|Bracer|Constants")
    static void GetTouchChannelsCountPropertyName(FString& result);
#pragma endregion 
};