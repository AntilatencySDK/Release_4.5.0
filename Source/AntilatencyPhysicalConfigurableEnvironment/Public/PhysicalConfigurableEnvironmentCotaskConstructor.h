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

#include "CotaskConstructor.h"
#include "PhysicalConfigurableEnvironmentCotask.h"

#include <Antilatency.PhysicalConfigurableEnvironment.h>

#include "PhysicalConfigurableEnvironmentCotaskConstructor.generated.h"

/**
 * Antilatency::PhysicalConfigurableEnvironment::ICotaskConstructor wrapper for UE.
 * Do not instantiate this class directly by calling NewObject<UPhysicalConfigurableEnvironmentCotaskConstructor> method,
 * use UPhysicalConfigurableEnvironmentLibrary::CreatePhysicalConfigurableEnvironmentCotaskConstructor instead.
 */
UCLASS(BlueprintType)
class ANTILATENCYPHYSICALCONFIGURABLEENVIRONMENT_API UPhysicalConfigurableEnvironmentCotaskConstructor : public UCotaskConstructor {
    GENERATED_BODY()

public:
    typedef Antilatency::PhysicalConfigurableEnvironment::ICotaskConstructor TInterface;
    
    /**
     * @brief Start PhysicalConfigurableEnvironment task on node.
     * @param network The pointer to the UDeviceNetwork object.
     * @param node The node to start task on.
     * @param result The host part of task (cotask).
     * @return ExceptionCode::Ok if the method execution is successful, otherwise returns the appropriate error code.
     */
    Antilatency::InterfaceContract::ExceptionCode StartTask(UDeviceNetwork* network, const FAdnNode& node, UPhysicalConfigurableEnvironmentCotask*& result);
};
