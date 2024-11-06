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

#include "Arbitrary2DDeserializedEnvironment.h"
#include "Arbitrary2DLibrary.h"

#include "Arbitrary2DFunctionLibrary.generated.h"

/** An additional enum that is used by the blueprint methods to allow user to check if called method has been executed successfully or not. */
UENUM(BlueprintType)
enum class EArbitrary2DExceptionResult : uint8 {
    /** The method executed successfully. */
    Success = 1 UMETA(DisplayName = "Success"),
    /** The method execution failed with some exception. */
    Fail = 0 UMETA(DisplayName = "Fail"),
};

/**
 * 
 */
UCLASS(BlueprintType)
class ANTILATENCYALTENVIRONMENTARBITRARY2D_API UArbitrary2DFunctionLibrary : public UObject {
    GENERATED_BODY()

public:

#pragma region UArbitrary2DLibrary
    UFUNCTION(BlueprintCallable, Category = "Antilatency|Alt|Environment|Arbitrary 2D|Library", Meta = (ExpandEnumAsExecs = "exception"))
    static void GetArbitrary2DLibrary(UArbitrary2DLibrary*& result, EArbitrary2DExceptionResult& exception);

    UFUNCTION(BlueprintCallable, Category = "Antilatency|Alt|Environment|Arbitrary 2D|Library", Meta = (ExpandEnumAsExecs = "exception"))
    static void SerializeEnvironment(
        UPARAM(ref) UArbitrary2DLibrary* arbitrary2DLibrary,
        const TArray<FVector2D>& markers,
        const float height,
        const bool floor,
        FString& result,
        EArbitrary2DExceptionResult& exception
    );

    UFUNCTION(BlueprintCallable, Category = "Antilatency|Alt|Environment|Arbitrary 2D|Library", Meta = (ExpandEnumAsExecs = "exception"))
    static void DeserializeEnvironment(UPARAM(ref) UArbitrary2DLibrary* arbitrary2DLibrary, const FString& environmentData, UArbitrary2DDeserializedEnvironment*& result, EArbitrary2DExceptionResult& exception);
#pragma endregion

#pragma region UDeserializedEnvironment
    UFUNCTION(BlueprintCallable, Category = "Antilatency|Alt|Environment|Arbitrary 2D|Deserialized Environment", Meta = (ExpandEnumAsExecs = "exception"))
    static void GetMarkers(UPARAM(ref) UArbitrary2DDeserializedEnvironment* deserializedEnvironment, TArray<FVector2D>& result, EArbitrary2DExceptionResult& exception);

    UFUNCTION(BlueprintCallable, Category = "Antilatency|Alt|Environment|Arbitrary 2D|Deserialized Environment", Meta = (ExpandEnumAsExecs = "exception"))
    static void GetHeight(UPARAM(ref) UArbitrary2DDeserializedEnvironment* deserializedEnvironment, float& result, EArbitrary2DExceptionResult& exception);

    UFUNCTION(BlueprintCallable, Category = "Antilatency|Alt|Environment|Arbitrary 2D|Deserialized Environment", Meta = (ExpandEnumAsExecs = "exception"))
    static void GetFloor(UPARAM(ref) UArbitrary2DDeserializedEnvironment* deserializedEnvironment, bool& result, EArbitrary2DExceptionResult& exception);

    UFUNCTION(BlueprintPure, Category = "Antilatency|Alt|Environment|Arbitrary 2D|Deserialized Environment")
    static bool IsValid(const UArbitrary2DDeserializedEnvironment* deserializedEnvironment);
#pragma endregion 
};
