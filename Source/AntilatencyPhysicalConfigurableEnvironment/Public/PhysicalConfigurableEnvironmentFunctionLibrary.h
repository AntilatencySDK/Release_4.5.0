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

#include "PhysicalConfigurableEnvironmentLibrary.h"
#include "PhysicalConfigurableEnvironmentCotaskConstructor.h"
#include "PhysicalConfigurableEnvironmentCotask.h"

#include "PhysicalConfigurableEnvironmentFunctionLibrary.generated.h"

/** An additional enum that is used by the blueprint methods to allow user to check if called method has been executed successfully or not. */
UENUM(BlueprintType)
enum class EPhysicalConfigurableEnvironmentExceptionResult : uint8 {
    /** The method executed successfully. */
    Success = 1 UMETA(DisplayName = "Success"),
    /** The method execution failed with some exception. */
    Fail = 0 UMETA(DisplayName = "Fail"),
};

/**
 * Provides Physical Configurable Environment module's methods wrappers for the UE blueprint system.
 */
UCLASS()
class ANTILATENCYPHYSICALCONFIGURABLEENVIRONMENT_API UPhysicalConfigurableEnvironmentFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()

public:
#pragma region UPhysicalConfigurableEnvironmentLibrary
    /**
    * Get the UPhysicalConfigurableEnvironmentLibrary instance.
    * @param result The pointer to UPhysicalConfigurableEnvironmentLibrary object instance.
    * @param exception Method execution result.
    */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|PhysicalConfigurableEnvironment|Library", Meta = (ExpandEnumAsExecs = "exception"))
    static void GetPhysicalConfigurableEnvironmentLibrary(UPhysicalConfigurableEnvironmentLibrary*& result, EPhysicalConfigurableEnvironmentExceptionResult& exception);

    UFUNCTION(BlueprintCallable, Category = "Antilatency|PhysicalConfigurableEnvironment|Library", Meta = (ExpandEnumAsExecs = "exception"))
    static void CreateCotaskConstructor(UPARAM(ref)UPhysicalConfigurableEnvironmentLibrary* library, UPhysicalConfigurableEnvironmentCotaskConstructor*& result, EPhysicalConfigurableEnvironmentExceptionResult& exception);
#pragma endregion

#pragma region UPhysicalConfigurableEnvironmentCotaskConstructor
    UFUNCTION(BlueprintCallable, Category = "Antilatency|PhysicalConfigurableEnvironment|Cotask Constructor", Meta = (ExpandEnumAsExecs = "exception"))
    static void StartTask(UPARAM(ref) UPhysicalConfigurableEnvironmentCotaskConstructor* constructor, UPARAM(ref) UDeviceNetwork* network, const FAdnNode& node, UPhysicalConfigurableEnvironmentCotask*& result, EPhysicalConfigurableEnvironmentExceptionResult& exception);
#pragma endregion

#pragma region UPhysicalConfigurableEnvironmentCotask
    UFUNCTION(BlueprintCallable, Category = "Antilatency|PhysicalConfigurableEnvironment|Cotask", Meta = (ExpandEnumAsExecs = "exception"))
    static int32 GetConfigId(UPARAM(ref) UPhysicalConfigurableEnvironmentCotask* cotask, EPhysicalConfigurableEnvironmentExceptionResult& exception);

    UFUNCTION(BlueprintCallable, Category = "Antilatency|PhysicalConfigurableEnvironment|Cotask", Meta = (ExpandEnumAsExecs = "exception"))
    static void SetConfigId(UPARAM(ref) UPhysicalConfigurableEnvironmentCotask* cotask, int32 configId, EPhysicalConfigurableEnvironmentExceptionResult& exception);

    UFUNCTION(BlueprintCallable, Category = "Antilatency|PhysicalConfigurableEnvironment|Cotask", Meta = (ExpandEnumAsExecs = "exception"))
    static int32 GetConfigCount(UPARAM(ref) UPhysicalConfigurableEnvironmentCotask* cotask, EPhysicalConfigurableEnvironmentExceptionResult& exception);

    UFUNCTION(BlueprintCallable, Category = "Antilatency|PhysicalConfigurableEnvironment|Cotask", Meta = (ExpandEnumAsExecs = "exception"))
    static FString GetEnvironment(UPARAM(ref) UPhysicalConfigurableEnvironmentCotask* cotask, int32 configId, EPhysicalConfigurableEnvironmentExceptionResult& exception);

    UFUNCTION(BlueprintCallable, Category = "Antilatency|PhysicalConfigurableEnvironment|Cotask", Meta = (ExpandEnumAsExecs = "exception"))
    static TArray<bool> GetMarkersConfig(UPARAM(ref) UPhysicalConfigurableEnvironmentCotask* cotask, int32 configId, EPhysicalConfigurableEnvironmentExceptionResult& exception);

    UFUNCTION(BlueprintCallable, Category = "Antilatency|PhysicalConfigurableEnvironment|Cotask", Meta = (ExpandEnumAsExecs = "exception"))
    static FVector GetScreenPosition(UPARAM(ref) UPhysicalConfigurableEnvironmentCotask* cotask, EPhysicalConfigurableEnvironmentExceptionResult& exception);

    UFUNCTION(BlueprintCallable, Category = "Antilatency|PhysicalConfigurableEnvironment|Cotask", Meta = (ExpandEnumAsExecs = "exception"))
    static FVector GetScreenX(UPARAM(ref) UPhysicalConfigurableEnvironmentCotask* cotask, EPhysicalConfigurableEnvironmentExceptionResult& exception);

    UFUNCTION(BlueprintCallable, Category = "Antilatency|PhysicalConfigurableEnvironment|Cotask", Meta = (ExpandEnumAsExecs = "exception"))
    static FVector GetScreenY(UPARAM(ref) UPhysicalConfigurableEnvironmentCotask* cotask, EPhysicalConfigurableEnvironmentExceptionResult& exception);
#pragma endregion
    
};
