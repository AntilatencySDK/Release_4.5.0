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

#include "DeserializedEnvironment.h"
#include "PillarsScheme.h"
#include "PillarsLibrary.h"
#include "PillarsTypes.h"

#include "PillarsFunctionLibrary.generated.h"

/** An additional enum that is used by the blueprint methods to allow user to check if called method has been executed successfully or not. */
UENUM(BlueprintType)
enum class EPillarsExceptionResult : uint8 {
    /** The method executed successfully. */
    Success = 1 UMETA(DisplayName = "Success"),
    /** The method execution failed with some exception. */
    Fail = 0 UMETA(DisplayName = "Fail"),
};

/**
 * 
 */
UCLASS(BlueprintType)
class ANTILATENCYALTENVIRONMENTPILLARS_API UPillarsFunctionLibrary : public UObject {
    GENERATED_BODY()

public:

#pragma region UPillarsLibrary
    UFUNCTION(BlueprintCallable, Category = "Antilatency|Alt|Environment|Pillars|Library", Meta = (ExpandEnumAsExecs = "exception"))
    static void GetPillarsLibrary(UPillarsLibrary*& result, EPillarsExceptionResult& exception);

    UFUNCTION(BlueprintCallable, Category = "Antilatency|Alt|Environment|Pillars|Library", Meta = (ExpandEnumAsExecs = "exception"))
    static void SerializeEnvironment(
        UPARAM(ref) UPillarsLibrary* pillarsLibrary,
        const TArray<FPillarsData>& pillars,
        UPillarsScheme* scheme,
        FString& result,
        EPillarsExceptionResult& exception
    );

    UFUNCTION(BlueprintCallable, Category = "Antilatency|Alt|Environment|Pillars|Library", Meta = (ExpandEnumAsExecs = "exception"))
    static void DeserializeEnvironment(UPARAM(ref) UPillarsLibrary* pillarsLibrary, const FString& environmentData, UDeserializedEnvironment*& result, EPillarsExceptionResult& exception);
#pragma endregion

#pragma region UDeserializedEnvironment
    UFUNCTION(BlueprintCallable, Category = "Antilatency|Alt|Environment|Pillars|Deserialized Environment", Meta = (ExpandEnumAsExecs = "exception"))
    static void GetPillars(UPARAM(ref) UDeserializedEnvironment* deserializedEnvironment, TArray<FPillarsData>& result, EPillarsExceptionResult& exception);

    UFUNCTION(BlueprintCallable, Category = "Antilatency|Alt|Environment|Pillars|Deserialized Environment", Meta = (ExpandEnumAsExecs = "exception"))
    static void GetScheme(UPARAM(ref) UDeserializedEnvironment* deserializedEnvironment, UPillarsScheme*& result, EPillarsExceptionResult& exception);

    UFUNCTION(BlueprintPure, Category = "Antilatency|Alt|Environment|Pillars|Deserialized Environment")
    static bool IsValid(const UDeserializedEnvironment* deserializedEnvironment);
#pragma endregion

#pragma region UPillarsScheme
    UFUNCTION(BlueprintCallable, Category = "Antilatency|Alt|Environment|Pillars|Scheme", Meta = (ExpandEnumAsExecs = "exception"))
    static int32 GetNumMarkersPerPillar(UPARAM(ref) UPillarsScheme* scheme, EPillarsExceptionResult& exception);

    UFUNCTION(BlueprintCallable, Category = "Antilatency|Alt|Environment|Pillars|Scheme", Meta = (ExpandEnumAsExecs = "exception"))
    static void SetNumMarkersPerPillar(UPARAM(ref) UPillarsScheme* scheme, int32 numMarkersPerPillar, EPillarsExceptionResult& exception);

    
    UFUNCTION(BlueprintCallable, Category = "Antilatency|Alt|Environment|Pillars|Scheme", Meta = (ExpandEnumAsExecs = "exception"))
    static float GetPillarLength(UPARAM(ref) UPillarsScheme* scheme, EPillarsExceptionResult& exception);

    UFUNCTION(BlueprintCallable, Category = "Antilatency|Alt|Environment|Pillars|Scheme", Meta = (ExpandEnumAsExecs = "exception"))
    static void SetPillarLength(UPARAM(ref) UPillarsScheme* scheme, float pillarLength, EPillarsExceptionResult& exception);
    
    
    UFUNCTION(BlueprintCallable, Category = "Antilatency|Alt|Environment|Pillars|Scheme", Meta = (ExpandEnumAsExecs = "exception"))
    static float GetDefaultFovDeg(UPARAM(ref) UPillarsScheme* scheme, EPillarsExceptionResult& exception);

    UFUNCTION(BlueprintCallable, Category = "Antilatency|Alt|Environment|Pillars|Scheme", Meta = (ExpandEnumAsExecs = "exception"))
    static void SetDefaultFovDeg(UPARAM(ref) UPillarsScheme* scheme, float defaultFovDeg, EPillarsExceptionResult& exception);
    
    
    UFUNCTION(BlueprintCallable, Category = "Antilatency|Alt|Environment|Pillars|Scheme", Meta = (ExpandEnumAsExecs = "exception"))
    static float GetPillarsVerticalOffset(UPARAM(ref) UPillarsScheme* scheme, EPillarsExceptionResult& exception);

    UFUNCTION(BlueprintCallable, Category = "Antilatency|Alt|Environment|Pillars|Scheme", Meta = (ExpandEnumAsExecs = "exception"))
    static void SetPillarsVerticalOffset(UPARAM(ref) UPillarsScheme* scheme, float pillarsVerticalOffset, EPillarsExceptionResult& exception);
    
    
    UFUNCTION(BlueprintCallable, Category = "Antilatency|Alt|Environment|Pillars|Scheme", Meta = (ExpandEnumAsExecs = "exception"))
    static bool GetStrictMatch(UPARAM(ref) UPillarsScheme* scheme, EPillarsExceptionResult& exception);

    UFUNCTION(BlueprintCallable, Category = "Antilatency|Alt|Environment|Pillars|Scheme", Meta = (ExpandEnumAsExecs = "exception"))
    static void SetStrictMatch(UPARAM(ref) UPillarsScheme* scheme, bool strictMatch, EPillarsExceptionResult& exception);
    
    
    UFUNCTION(BlueprintCallable, Category = "Antilatency|Alt|Environment|Pillars|Scheme", Meta = (ExpandEnumAsExecs = "exception"))
    static int32 GetNumPillarsKinds(UPARAM(ref) UPillarsScheme* scheme, EPillarsExceptionResult& exception);

    UFUNCTION(BlueprintCallable, Category = "Antilatency|Alt|Environment|Pillars|Scheme", Meta = (ExpandEnumAsExecs = "exception"))
    static void SetNumPillarsKinds(UPARAM(ref) UPillarsScheme* scheme, int32 numPillarsKinds, EPillarsExceptionResult& exception);
    
    
    UFUNCTION(BlueprintCallable, Category = "Antilatency|Alt|Environment|Pillars|Scheme", Meta = (ExpandEnumAsExecs = "exception"))
    static TArray<float> GetProportions(UPARAM(ref) UPillarsScheme* scheme, int32 pillarKind, EPillarsExceptionResult& exception);

    UFUNCTION(BlueprintCallable, Category = "Antilatency|Alt|Environment|Pillars|Scheme", Meta = (ExpandEnumAsExecs = "exception"))
    static void SetProportions(UPARAM(ref) UPillarsScheme* scheme, UPARAM(ref) TArray<float> proportions, int32 pillarKind, EPillarsExceptionResult& exception);
#pragma endregion
};
