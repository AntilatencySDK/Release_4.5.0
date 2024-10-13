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
#include "DeviceNetworkTypes.h"



/**
 *
 */
class ANTILATENCYDEVICENETWORK_API UDeviceNetworkConstants {
public:

    const static FUsbDeviceFilter AllUsbDevices;
    const static uint16 UsbAllDeviceMask;
    const static uint16 UsbOneDeviceMask;
    const static FString AllIpDevicesIp;
    const static FString AllIpDevicesMask;
    
    const static FAdnNode NullNode;
    const static FString HardwareVersionKey;
    const static FString HardwareNameKey;
    const static FString FirmwareVersionKey;
    const static FString FirmwareNameKey;
    const static FString HardwareSerialNumberKey;
    const static FString ImageVersionKey;
    const static uint16 IpBroadcastSenderPort;
    const static uint16 IpBroadcastReceiverPort;
    const static uint16 IpDefaultStreamPort;
};
