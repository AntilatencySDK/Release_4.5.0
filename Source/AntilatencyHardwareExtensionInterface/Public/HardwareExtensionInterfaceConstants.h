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

class HardwareExtensionInterfaceConstants {
public:
    const static uint32 AnalogMinRefreshIntervalMs;
    const static uint32 AnalogMaxRefreshIntervalMs;
    const static uint32 PulseCounterMinRefreshIntervalMs;
    const static uint32 PulseCounterMaxRefreshIntervalMs;
    const static uint32 PwmMinFrequency;
    const static uint32 PwmMaxFrequency;
    
    const static uint32 MaxInputPinsCount;
    const static uint32 MaxOutputPinsCount;
    const static uint32 MaxAnalogPinsCount;
    const static uint32 MaxPulseCounterPinsCount;
    const static uint32 MaxPwmPinsCount;
};


