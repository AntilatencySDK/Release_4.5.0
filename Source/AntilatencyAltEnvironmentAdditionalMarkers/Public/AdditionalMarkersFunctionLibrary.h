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

#include "AdditionalMarkersLibrary.h"

#include "AdditionalMarkersFunctionLibrary.generated.h"

/** An additional enum that is used by the blueprint methods to allow user to check if called method has been executed successfully or not. */
UENUM(BlueprintType)
enum class EAdditionalMarkersExceptionResult : uint8 {
    /** The method executed successfully. */
    Success = 1 UMETA(DisplayName = "Success"),
    /** The method execution failed with some exception. */
    Fail = 0 UMETA(DisplayName = "Fail"),
};

/**
 * Provides Additional Markers module's methods wrappers for the UE blueprint system.
 */
UCLASS()
class ANTILATENCYALTENVIRONMENTADDITIONALMARKERS_API UAdditionalMarkersFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()

public:
    /**
    * Get the UAdditionalMarkersLibrary instance.
    * @param result The pointer to UAdditionalMarkersLibrary object instance.
    * @param exception Method execution result.
    */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|Alt|Environment|Additional Markers|Library", Meta = (ExpandEnumAsExecs = "exception"))
    static void GetAdditionalMarkersLibrary(UAdditionalMarkersLibrary*& result, EAdditionalMarkersExceptionResult& exception);
};
