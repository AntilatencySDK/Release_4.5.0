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

#include <Antilatency.HardwareExtensionInterface.h>
#include <Antilatency.HardwareExtensionInterface.Interop.h>

#include "HardwareExtensionInterfaceTypes.generated.h"


UENUM(BlueprintType, Category = "Antilatency|Hardware Extension Interface|Types")
enum class EPins : uint8 {
	IO1 = 0x0,
	IO2 = 0x1,
	IOA3 = 0x2,
	IOA4 = 0x3,
	IO5 = 0x4,
	IO6 = 0x5,
	IO7 = 0x6,
	IO8 = 0x7
};

UENUM(BlueprintType, Category = "Antilatency|Hardware Extension Interface|Types")
enum class EPinState : uint8 {
	Low = 0x0,
	High = 0x1
};
