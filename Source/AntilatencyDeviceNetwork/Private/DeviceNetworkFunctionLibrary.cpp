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

#include "DeviceNetworkFunctionLibrary.h"

#include "DeviceNetworkConstants.h"

void UDeviceNetworkFunctionLibrary::GetLibrary(UDeviceNetworkLibrary*& result, EDeviceNetworkExceptionResult& exception) {
    result = UDeviceNetworkLibrary::GetLibrary();
    exception = static_cast<EDeviceNetworkExceptionResult>(result != nullptr);
}

void UDeviceNetworkFunctionLibrary::CreateFilter(UDeviceNetworkLibrary* deviceNetworkLibrary, UDeviceFilter*& result, EDeviceNetworkExceptionResult& exception) {
    if (deviceNetworkLibrary == nullptr) {
        exception = EDeviceNetworkExceptionResult::Fail;
        return;
    }

    const auto callResult = deviceNetworkLibrary->CreateFilter(result);
    exception = static_cast<EDeviceNetworkExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UDeviceNetworkFunctionLibrary::CreateNetwork(UDeviceNetworkLibrary* deviceNetworkLibrary, UDeviceFilter* deviceFilter, UDeviceNetwork*& result, EDeviceNetworkExceptionResult& exception) {
    if (deviceNetworkLibrary == nullptr) {
        exception = EDeviceNetworkExceptionResult::Fail;
        return;
    }

    const auto callResult = deviceNetworkLibrary->CreateNetwork(deviceFilter, result);
    exception = static_cast<EDeviceNetworkExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UDeviceNetworkFunctionLibrary::GetVersion(UDeviceNetworkLibrary* deviceNetworkLibrary, FString& result, EDeviceNetworkExceptionResult& exception) {
    if (deviceNetworkLibrary == nullptr) {
        exception = EDeviceNetworkExceptionResult::Fail;
        return;
    }

    const auto callResult = deviceNetworkLibrary->GetVersion(result);
    exception = static_cast<EDeviceNetworkExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UDeviceNetworkFunctionLibrary::SetLogLevel(UDeviceNetworkLibrary* deviceNetworkLibrary, const EDeviceNetworkLogLevel& level, EDeviceNetworkExceptionResult& exception) {
    if (deviceNetworkLibrary == nullptr) {
        exception = EDeviceNetworkExceptionResult::Fail;
        return;
    }

    const auto callResult = deviceNetworkLibrary->SetLogLevel(level);
    exception = static_cast<EDeviceNetworkExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

bool UDeviceNetworkFunctionLibrary::IsLibraryValid(const UDeviceNetworkLibrary* deviceNetworkLibrary) {
    if (deviceNetworkLibrary == nullptr) {
        return false;
    }

    return deviceNetworkLibrary->IsValid();
}

void UDeviceNetworkFunctionLibrary::AddUsbDevice(UDeviceFilter* filter, const FUsbDeviceFilter& usbDeviceFilter, EDeviceNetworkExceptionResult& exception) {
    if (filter == nullptr) {
        exception = EDeviceNetworkExceptionResult::Fail;
        return;
    }

    const auto callResult = filter->AddUsbDevice(usbDeviceFilter);
    exception = static_cast<EDeviceNetworkExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UDeviceNetworkFunctionLibrary::AddIpDevice(UDeviceFilter* filter, const FString& ip, const FString& mask, EDeviceNetworkExceptionResult& exception) {
    if (filter == nullptr) {
        exception = EDeviceNetworkExceptionResult::Fail;
        return;
    }

    const auto callResult = filter->AddIpDevice(ip, mask);
    exception = static_cast<EDeviceNetworkExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UDeviceNetworkFunctionLibrary::GetUsbDevice(UDeviceFilter* filter, const int32 index, FUsbDeviceFilter& result, EDeviceNetworkExceptionResult& exception) {
    if (filter == nullptr) {
        exception = EDeviceNetworkExceptionResult::Fail;
        return;
    }

    const auto callResult = filter->GetUsbDevice(static_cast<uint32>(index), result);
    exception = static_cast<EDeviceNetworkExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UDeviceNetworkFunctionLibrary::GetIpDevice(UDeviceFilter* filter, const int32 index, FString& result, EDeviceNetworkExceptionResult& exception) {
    if (filter == nullptr) {
        exception = EDeviceNetworkExceptionResult::Fail;
        return;
    }

    const auto callResult = filter->GetIpDevice(static_cast<uint32>(index), result);
    exception = static_cast<EDeviceNetworkExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UDeviceNetworkFunctionLibrary::GetIpDeviceMask(UDeviceFilter* filter, const int32 index, FString& result, EDeviceNetworkExceptionResult& exception) {
    if (filter == nullptr) {
        exception = EDeviceNetworkExceptionResult::Fail;
        return;
    }

    const auto callResult = filter->GetIpDeviceMask(static_cast<uint32>(index), result);
    exception = static_cast<EDeviceNetworkExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

bool UDeviceNetworkFunctionLibrary::IsDeviceFilterValid(const UDeviceFilter* filter) {
    if (filter == nullptr) {
        return false;
    }

    return filter->IsValid();
}


void UDeviceNetworkFunctionLibrary::GetUpdateId(UDeviceNetwork* network, int32& result, EDeviceNetworkExceptionResult& exception) {
    if (network == nullptr) {
        exception = EDeviceNetworkExceptionResult::Fail;
        return;
    }

    uint32 nativeResult;
    const auto callResult = network->GetUpdateId(nativeResult);
    result = static_cast<int32>(nativeResult);
    exception = static_cast<EDeviceNetworkExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UDeviceNetworkFunctionLibrary::GetDeviceFilter(UDeviceNetwork* network, UDeviceFilter*& result, EDeviceNetworkExceptionResult& exception) {
    if (network == nullptr) {
        exception = EDeviceNetworkExceptionResult::Fail;
        return;
    }

    const auto callResult = network->GetDeviceFilter(result);
    exception = static_cast<EDeviceNetworkExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UDeviceNetworkFunctionLibrary::GetNodes(UDeviceNetwork* network, TArray<FAdnNode>& result, EDeviceNetworkExceptionResult& exception) {
    if (network == nullptr) {
        exception = EDeviceNetworkExceptionResult::Fail;
        return;
    }

    const auto callResult = network->GetNodes(result);
    exception = static_cast<EDeviceNetworkExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UDeviceNetworkFunctionLibrary::NodeGetStatus(UDeviceNetwork* network, const FAdnNode& node, ENodeStatus& result, EDeviceNetworkExceptionResult& exception) {
    if (network == nullptr) {
        exception = EDeviceNetworkExceptionResult::Fail;
        return;
    }

    const auto callResult = network->NodeGetStatus(node, result);
    exception = static_cast<EDeviceNetworkExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UDeviceNetworkFunctionLibrary::NodeIsTaskSupported(UDeviceNetwork* network, const FAdnNode& node, const FGuid& interfaceId, bool& result, EDeviceNetworkExceptionResult& exception) {
    if (network == nullptr) {
        exception = EDeviceNetworkExceptionResult::Fail;
        return;
    }

    const auto callResult = network->NodeIsTaskSupported(node, interfaceId, result);
    exception = static_cast<EDeviceNetworkExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UDeviceNetworkFunctionLibrary::NodeGetParent(UDeviceNetwork* network, const FAdnNode& node, FAdnNode& result, EDeviceNetworkExceptionResult& exception) {
    if (network == nullptr) {
        exception = EDeviceNetworkExceptionResult::Fail;
        return;
    }

    const auto callResult = network->NodeGetParent(node, result);
    exception = static_cast<EDeviceNetworkExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UDeviceNetworkFunctionLibrary::NodeGetPhysicalPath(UDeviceNetwork* network, const FAdnNode& node, FString& result, EDeviceNetworkExceptionResult& exception) {
    if (network == nullptr) {
        exception = EDeviceNetworkExceptionResult::Fail;
        return;
    }

    const auto callResult = network->NodeGetPhysicalPath(node, result);
    exception = static_cast<EDeviceNetworkExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UDeviceNetworkFunctionLibrary::NodeGetStringProperty(UDeviceNetwork* network, const FAdnNode& node, const FString& key, FString& result, EDeviceNetworkExceptionResult& exception) {
    if (network == nullptr) {
        exception = EDeviceNetworkExceptionResult::Fail;
        return;
    }

    const auto callResult = network->NodeGetStringProperty(node, key, result);
    exception = static_cast<EDeviceNetworkExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UDeviceNetworkFunctionLibrary::NodeGetBinaryProperty(UDeviceNetwork* network, const FAdnNode& node, const FString& key, TArray<uint8>& result, EDeviceNetworkExceptionResult& exception) {
    if (network == nullptr) {
        exception = EDeviceNetworkExceptionResult::Fail;
        return;
    }

    const auto callResult = network->NodeGetBinaryProperty(node, key, result);
    exception = static_cast<EDeviceNetworkExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UDeviceNetworkFunctionLibrary::NodeStartPropertyTask(UDeviceNetwork* network, const FAdnNode& node, UPropertyCotask*& result, EDeviceNetworkExceptionResult& exception) {
    if (network == nullptr) {
        exception = EDeviceNetworkExceptionResult::Fail;
        return;
    }

    const auto callResult = network->NodeStartPropertyTask(node, result);
    exception = static_cast<EDeviceNetworkExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

bool UDeviceNetworkFunctionLibrary::IsNetworkValid(UDeviceNetwork* network) {
    if (network == nullptr) {
        return false;
    }

    return network->IsValid();
}

void UDeviceNetworkFunctionLibrary::IsTaskFinished(UCotask* cotask, bool& result, EDeviceNetworkExceptionResult& exception) {
    if (cotask == nullptr) {
        exception = EDeviceNetworkExceptionResult::Fail;
        return;
    }

    const auto callResult = cotask->IsTaskFinished(result);
    exception = static_cast<EDeviceNetworkExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UDeviceNetworkFunctionLibrary::Stop(UCotask* cotask) {
    if (cotask == nullptr) {
        return;
    }

    cotask->Stop();
}

bool UDeviceNetworkFunctionLibrary::IsCotaskValid(UCotask* cotask) {
    if (cotask == nullptr) {
        return false;
    }

    return cotask->IsValid();
}

void UDeviceNetworkFunctionLibrary::GetBatteryLevel(UCotaskBatteryPowered* cotaskBatteryPowered, float& result, EDeviceNetworkExceptionResult& exception) {
    if (cotaskBatteryPowered == nullptr) {
        exception = EDeviceNetworkExceptionResult::Fail;
        return;
    }

    const auto callResult = cotaskBatteryPowered->GetBatteryLevel(result);
    exception = static_cast<EDeviceNetworkExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UDeviceNetworkFunctionLibrary::GetPropertyKey(UPropertyCotask* propertyCotask, const int32 index, FString& result, EDeviceNetworkExceptionResult& exception) {
    if (propertyCotask == nullptr) {
        exception = EDeviceNetworkExceptionResult::Fail;
        return;
    }

    const auto callResult = propertyCotask->GetPropertyKey(static_cast<uint32>(index), result);
    exception = static_cast<EDeviceNetworkExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UDeviceNetworkFunctionLibrary::GetStringProperty(UPropertyCotask* propertyCotask, const FString& key, FString& result, EDeviceNetworkExceptionResult& exception) {
    if (propertyCotask == nullptr) {
        exception = EDeviceNetworkExceptionResult::Fail;
        return;
    }

    const auto callResult = propertyCotask->GetStringProperty(key, result);
    exception = static_cast<EDeviceNetworkExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UDeviceNetworkFunctionLibrary::SetStringProperty(UPropertyCotask* propertyCotask, const FString& key, const FString& value, EDeviceNetworkExceptionResult& exception) {
    if (propertyCotask == nullptr) {
        exception = EDeviceNetworkExceptionResult::Fail;
        return;
    }

    const auto callResult = propertyCotask->SetStringProperty(key, value);
    exception = static_cast<EDeviceNetworkExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UDeviceNetworkFunctionLibrary::GetBinaryProperty(UPropertyCotask* propertyCotask, const FString& key, TArray<uint8>& result, EDeviceNetworkExceptionResult& exception) {
    if (propertyCotask == nullptr) {
        exception = EDeviceNetworkExceptionResult::Fail;
        return;
    }

    const auto callResult = propertyCotask->GetBinaryProperty(key, result);
    exception = static_cast<EDeviceNetworkExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UDeviceNetworkFunctionLibrary::SetBinaryProperty(UPropertyCotask* propertyCotask, const FString& key, const TArray<uint8>& value, EDeviceNetworkExceptionResult& exception) {
    if (propertyCotask == nullptr) {
        exception = EDeviceNetworkExceptionResult::Fail;
        return;
    }

    const auto callResult = propertyCotask->SetBinaryProperty(key, value);
    exception = static_cast<EDeviceNetworkExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UDeviceNetworkFunctionLibrary::DeleteProperty(UPropertyCotask* propertyCotask, const FString& key, EDeviceNetworkExceptionResult& exception) {
    if (propertyCotask == nullptr) {
        exception = EDeviceNetworkExceptionResult::Fail;
        return;
    }

    const auto callResult = propertyCotask->DeleteProperty(key);
    exception = static_cast<EDeviceNetworkExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UDeviceNetworkFunctionLibrary::IsSupported(UCotaskConstructor* cotaskConstructor, UDeviceNetwork* network, const FAdnNode& node, bool& result, EDeviceNetworkExceptionResult& exception) {
    if (cotaskConstructor == nullptr) {
        exception = EDeviceNetworkExceptionResult::Fail;
        return;
    }

    const auto callResult = cotaskConstructor->IsSupported(network, node, result);
    exception = static_cast<EDeviceNetworkExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UDeviceNetworkFunctionLibrary::FindSupportedNodes(UCotaskConstructor* cotaskConstructor, UDeviceNetwork* network, TArray<FAdnNode>& result, EDeviceNetworkExceptionResult& exception) {
    if (cotaskConstructor == nullptr) {
        exception = EDeviceNetworkExceptionResult::Fail;
        return;
    }

    const auto callResult = cotaskConstructor->FindSupportedNodes(network, result);
    exception = static_cast<EDeviceNetworkExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

bool UDeviceNetworkFunctionLibrary::IsCotaskConstructorValid(const UCotaskConstructor* constructor) {
    if (constructor == nullptr) {
        return false;
    }

    return constructor->IsValid();
}

bool UDeviceNetworkFunctionLibrary::EqualEqual_FAdnNodeFAdnNode(const FAdnNode& arg1, const FAdnNode& arg2) {
	return arg1 == arg2;
}

bool UDeviceNetworkFunctionLibrary::NotEqual_FAdnNodeFAdnNode(const FAdnNode& arg1, const FAdnNode& arg2) {
	return arg1 != arg2;
}

FUsbDeviceFilter UDeviceNetworkFunctionLibrary::AllUsbDevices() {
    return UDeviceNetworkConstants::AllUsbDevices;
}

int32 UDeviceNetworkFunctionLibrary::UsbAllDeviceMask() {
    return UDeviceNetworkConstants::UsbAllDeviceMask;
}

int32 UDeviceNetworkFunctionLibrary::UsbOneDeviceMask() {
    return UDeviceNetworkConstants::UsbOneDeviceMask;
}

FString UDeviceNetworkFunctionLibrary::AllIpDevicesIp() {
    return UDeviceNetworkConstants::AllIpDevicesIp;
}

FString UDeviceNetworkFunctionLibrary::AllIpDevicesMask() {
    return UDeviceNetworkConstants::AllIpDevicesMask;
}

FAdnNode UDeviceNetworkFunctionLibrary::NullNode() {
    return UDeviceNetworkConstants::NullNode;
}

FString UDeviceNetworkFunctionLibrary::HardwareVersionKey() {
    return UDeviceNetworkConstants::HardwareVersionKey;
}

FString UDeviceNetworkFunctionLibrary::HardwareNameKey() {
    return UDeviceNetworkConstants::HardwareNameKey;
}

FString UDeviceNetworkFunctionLibrary::FirmwareVersionKey() {
    return UDeviceNetworkConstants::FirmwareVersionKey;
}

FString UDeviceNetworkFunctionLibrary::FirmwareNameKey() {
    return UDeviceNetworkConstants::FirmwareNameKey;
}

FString UDeviceNetworkFunctionLibrary::HardwareSerialNumberKey() {
    return UDeviceNetworkConstants::HardwareSerialNumberKey;
}

FString UDeviceNetworkFunctionLibrary::ImageVersionKey() {
    return UDeviceNetworkConstants::ImageVersionKey;
}

int32 UDeviceNetworkFunctionLibrary::IpBroadcastSenderPort() {
    return static_cast<int32>(UDeviceNetworkConstants::IpBroadcastSenderPort);
}

int32 UDeviceNetworkFunctionLibrary::IpBroadcastReceiverPort() {
    return static_cast<int32>(UDeviceNetworkConstants::IpBroadcastReceiverPort);
}

int32 UDeviceNetworkFunctionLibrary::IpDefaultStreamPort() {
    return static_cast<int32>(UDeviceNetworkConstants::IpDefaultStreamPort);
}