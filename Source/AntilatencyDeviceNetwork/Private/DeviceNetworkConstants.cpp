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

#include "DeviceNetworkConstants.h"

#include <Antilatency.DeviceNetwork.h>
#include <Antilatency.DeviceNetwork.Interop.h>

const FUsbDeviceFilter UDeviceNetworkConstants::AllUsbDevices = {Antilatency::DeviceNetwork::Constants::AllUsbDevices};
const uint16 UDeviceNetworkConstants::UsbAllDeviceMask = static_cast<uint16>(Antilatency::DeviceNetwork::Constants::UsbAllDeviceMask);
const uint16 UDeviceNetworkConstants::UsbOneDeviceMask = static_cast<uint16>(Antilatency::DeviceNetwork::Constants::UsbOneDeviceMask);
const FString UDeviceNetworkConstants::AllIpDevicesIp = {Antilatency::DeviceNetwork::Constants::AllIpDevicesIp};
const FString UDeviceNetworkConstants::AllIpDevicesMask = {Antilatency::DeviceNetwork::Constants::AllIpDevicesMask};

const FAdnNode UDeviceNetworkConstants::NullNode = {};

const FString UDeviceNetworkConstants::HardwareVersionKey = { Antilatency::DeviceNetwork::Interop::Constants::HardwareVersionKey };
const FString UDeviceNetworkConstants::HardwareNameKey = { Antilatency::DeviceNetwork::Interop::Constants::HardwareNameKey };
const FString UDeviceNetworkConstants::FirmwareVersionKey = { Antilatency::DeviceNetwork::Interop::Constants::FirmwareNameKey };
const FString UDeviceNetworkConstants::FirmwareNameKey = { Antilatency::DeviceNetwork::Interop::Constants::FirmwareVersionKey };
const FString UDeviceNetworkConstants::HardwareSerialNumberKey = { Antilatency::DeviceNetwork::Interop::Constants::HardwareSerialNumberKey };
const FString UDeviceNetworkConstants::ImageVersionKey = { Antilatency::DeviceNetwork::Interop::Constants::ImageVersionKey };
const uint16 UDeviceNetworkConstants::IpBroadcastSenderPort = static_cast<uint16>(Antilatency::DeviceNetwork::Interop::Constants::IpBroadcastSenderPort);
const uint16 UDeviceNetworkConstants::IpBroadcastReceiverPort = static_cast<uint16>(Antilatency::DeviceNetwork::Interop::Constants::IpBroadcastReceiverPort);
const uint16 UDeviceNetworkConstants::IpDefaultStreamPort = static_cast<uint16>(Antilatency::DeviceNetwork::Interop::Constants::IpDefaultStreamPort);



