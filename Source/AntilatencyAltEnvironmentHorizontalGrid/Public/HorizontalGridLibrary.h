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

#include "EnvironmentConstructor.h"

#include <Antilatency.Alt.Environment.HorizontalGrid.h>

#include "HorizontalGridLibrary.generated.h"

/**
 * Antilatency::Alt::Environment::HorizontalGrid::ILibrary wrapper for UE.
 * Do not instantiate this class directly by calling NewObject<UHorizontalGridLibrary> method,
 * use UHorizontalGridLibrary::GetLibrary instead.
 */
UCLASS(BlueprintType)
class ANTILATENCYALTENVIRONMENTHORIZONTALGRID_API UHorizontalGridLibrary : public UEnvironmentConstructor {
    GENERATED_BODY()

public:
    typedef Antilatency::Alt::Environment::HorizontalGrid::ILibrary TInterface;

    /**
     * Get the UHorizontalGridLibrary instance.
     */
    static UHorizontalGridLibrary* GetLibrary();
};
