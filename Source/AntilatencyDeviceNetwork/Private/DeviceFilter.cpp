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

#include "DeviceFilter.h"
#include "AdnLog.h"

#include <ExceptionCheck.h>

UDeviceFilter::TInterface UDeviceFilter::GetNative() {
    return _native;
}

Antilatency::InterfaceContract::ExceptionCode UDeviceFilter::AddUsbDevice(const FUsbDeviceFilter& usbDeviceFilter) {
    if (!IsValid()) {
        ADN_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    auto exception = _native.addUsbDevice(usbDeviceFilter.ToNative());
    ANTILATENCY_EXCEPTION_CHECK();

    return exception;
}

Antilatency::InterfaceContract::ExceptionCode UDeviceFilter::AddIpDevice(const FString& ip, const FString& mask) {
    if (!IsValid()) {
        ADN_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    auto exception = _native.addIpDevice(std::string(TCHAR_TO_UTF8(*ip)), std::string(TCHAR_TO_UTF8(*mask)));
    ANTILATENCY_EXCEPTION_CHECK();

    return exception;
}

Antilatency::InterfaceContract::ExceptionCode UDeviceFilter::GetUsbDevice(const uint32 index, FUsbDeviceFilter& result) {
    if (!IsValid()) {
        ADN_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    Antilatency::DeviceNetwork::UsbDeviceFilter nativeResult;
    auto exception = _native.getUsbDevice(static_cast<uint32_t>(index), nativeResult);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    result = {nativeResult};

    return exception;
}

Antilatency::InterfaceContract::ExceptionCode UDeviceFilter::GetIpDevice(const uint32 index, FString& result) {
    if (!IsValid()) {
        ADN_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    std::string nativeResult;
    auto exception = _native.getIpDevice(static_cast<uint32_t>(index), nativeResult);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    result = {nativeResult.c_str()};

    return exception;
}

Antilatency::InterfaceContract::ExceptionCode UDeviceFilter::GetIpDeviceMask(const uint32 index, FString& result) {
    if (!IsValid()) {
        ADN_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    std::string nativeResult;
    auto exception = _native.getIpDevice(static_cast<uint32_t>(index), nativeResult);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    result = {nativeResult.c_str()};

    return exception;
}

bool UDeviceFilter::IsValid() const {
    return _native != nullptr;
}



