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

#include "Cotask.h"

#include "CotaskBatteryPowered.generated.h"

/**
* An UE wrapper for the Antilatency::DeviceNetwork::ICotaskBatteryPowered.
* Do not instantiate this class directly by calling NewObject<UCotaskBatteryPowered> method.
*/
UCLASS(BlueprintType)
class ANTILATENCYDEVICENETWORK_API UCotaskBatteryPowered : public UCotask {
    GENERATED_BODY()
    
public:
    typedef Antilatency::DeviceNetwork::ICotaskBatteryPowered TInterface;

    Antilatency::InterfaceContract::ExceptionCode GetBatteryLevel(float& result);
};