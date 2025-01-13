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

#include <Antilatency.DeviceNetwork.h>

/**
 * Convert InterfaceID to FGuid.
 */
inline FGuid InterfaceIDToFGuid(const Antilatency::InterfaceContract::InterfaceID& native) {
    static_assert(sizeof(FGuid) == sizeof(Antilatency::InterfaceContract::InterfaceID), "FGuid and InterfaceID size mismatch");
    FGuid guid;
    memcpy(&guid, &native, 16);
    return guid;
}

/**
 * Convert FGuid to InterfaceID.
 */
inline Antilatency::InterfaceContract::InterfaceID FGuidToInterfaceID(const FGuid& guid) {
    static_assert(sizeof(FGuid) == sizeof(Antilatency::InterfaceContract::InterfaceID), "FGuid and InterfaceID size mismatch");
    Antilatency::InterfaceContract::InterfaceID nativeId;
    memcpy(&nativeId, &guid, 16);
    return nativeId;
}