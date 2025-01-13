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

#include "HardwareExtensionInterfaceCotask.h"
#include "CotaskConstructor.h"
#include "DeviceNetwork.h"

#include <Antilatency.HardwareExtensionInterface.h>

#include "HardwareExtensionInterfaceCotaskConstructor.generated.h"

/**
 * The UE wrapper for the Antilatency::HardwareExtensionInterface::ICotaskConstructor object.
 * Do not instantiate this class directly by calling the NewObject<UHardwareExtensionInterfaceCotaskConstructor> method,
 * use the UHardwareExtensionInterfaceLibrary::GetCotaskConstructor instead.
 */
UCLASS(BlueprintType)
class ANTILATENCYHARDWAREEXTENSIONINTERFACE_API UHardwareExtensionInterfaceCotaskConstructor : public UCotaskConstructor {
    GENERATED_BODY()

public:
    typedef Antilatency::HardwareExtensionInterface::ICotaskConstructor TInterface;

    Antilatency::InterfaceContract::ExceptionCode StartTask(UDeviceNetwork* network, const FAdnNode& node, UHardwareExtensionInterfaceCotask*& result);
};
