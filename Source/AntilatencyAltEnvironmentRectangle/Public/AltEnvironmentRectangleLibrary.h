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

#include "AltEnvironment.h"
#include "EnvironmentConstructor.h"

#include <Antilatency.Alt.Environment.Rectangle.h>

#include "AltEnvironmentRectangleLibrary.generated.h"

/**
 * Antilatency::Alt::Environment::Rectangle::ILibrary wrapper for UE.
 * Do not instantiate this class directly by calling NewObject<URectangleLibrary> method,
 * use URectangleLibrary::GetLibrary instead.
 */
UCLASS(BlueprintType)
class ANTILATENCYALTENVIRONMENTRECTANGLE_API UAltEnvironmentRectangleLibrary : public UEnvironmentConstructor {
    GENERATED_BODY()

public:
    typedef Antilatency::Alt::Environment::Rectangle::ILibrary TInterface;

    /**
     * Get the UHorizontalGridLibrary instance.
     */
    static UAltEnvironmentRectangleLibrary* GetLibrary();

	Antilatency::InterfaceContract::ExceptionCode GetRotation(UAltEnvironment* environment, FQuat& result);
};
