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

#include "EnvironmentSelectorLibrary.h"

#include "EnvironmentSelectorFunctionLibrary.generated.h"

UENUM(BlueprintType)
enum class EEnvironmentSelectorExceptionResult : uint8 {
    Success = 1 UMETA(DisplayName = "Success"),
    Fail = 0 UMETA(DisplayName = "Fail"),
};

/**
 * 
 */
UCLASS(BlueprintType)
class ANTILATENCYALTENVIRONMENTSELECTOR_API UEnvironmentSelectorFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "Antilatency|Alt|Environment|Selector|Library", Meta = (ExpandEnumAsExecs = "exception"))
    static void GetEnvironmentSelectorLibrary(UEnvironmentSelectorLibrary*& result, EEnvironmentSelectorExceptionResult& exception);

    UFUNCTION(BlueprintCallable, Category = "Antilatency|Alt|Environment|Selector|Library", Meta = (ExpandEnumAsExecs = "exception"))
    static void CreateEnvironment(UPARAM(ref) UEnvironmentSelectorLibrary* library, const FString& data, UAltEnvironment*& result, EEnvironmentSelectorExceptionResult& exception);

    /** 
     * Check if environment selector library initialized properly.
     * @return true if environment selector library initialized properly, otherwise false.
     */
    UFUNCTION(BlueprintPure, Category = "Antilatency|Alt|Environment|Selector|Library")
    static bool IsLibraryValid(const UEnvironmentSelectorLibrary* library);
};

