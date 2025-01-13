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

#include "DeviceNetworkLibrary.h"
#include "IAntilatencyDeviceNetworkModule.h"

#include "AdnLog.h"

#include <ExceptionCheck.h>

UDeviceNetworkLibrary* UDeviceNetworkLibrary::GetLibrary() {
    auto module = IAntilatencyDeviceNetworkModule::Get();
    auto library = module.GetNativeLibrary();

    if (library == nullptr) {
        return nullptr;
    }

    return ObjectConstructor<UDeviceNetworkLibrary>::create(library);
}

Antilatency::InterfaceContract::ExceptionCode UDeviceNetworkLibrary::CreateFilter(UDeviceFilter*& result) {
    if (!IsValid()) {
        ADN_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }
    
    Antilatency::DeviceNetwork::IDeviceFilter nativeResult;
    auto exception = _native.createFilter(nativeResult);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    if (nativeResult == nullptr) {
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    result = ObjectConstructor<UDeviceFilter>::create(nativeResult);
    return exception;
}

Antilatency::InterfaceContract::ExceptionCode UDeviceNetworkLibrary::CreateNetwork(UDeviceFilter* deviceFilter, UDeviceNetwork*& result) {
    if (!IsValid()) {
        ADN_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }
    
    Antilatency::DeviceNetwork::INetwork nativeResult;
    auto exception = _native.createNetwork(deviceFilter->GetNative(), nativeResult);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    if (nativeResult == nullptr) {
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    result = ObjectConstructor<UDeviceNetwork>::create(nativeResult);
    return exception;
}

Antilatency::InterfaceContract::ExceptionCode UDeviceNetworkLibrary::GetVersion(FString& result) {
    if (!IsValid()) {
        ADN_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }
    
    std::string str;
    auto exception = _native.getVersion(str);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    result = { str.c_str() };
    return exception;
}

Antilatency::InterfaceContract::ExceptionCode UDeviceNetworkLibrary::SetLogLevel(const EDeviceNetworkLogLevel& level) {
    if (!IsValid()) {
        ADN_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }
    
    auto exception = _native.setLogLevel(static_cast<Antilatency::DeviceNetwork::LogLevel>(level));
    ANTILATENCY_EXCEPTION_CHECK();
    return exception;
}

bool UDeviceNetworkLibrary::IsValid() const {
    if (_native == nullptr) {
        ADN_LOG(Warning, TEXT("Antilatency Device Network library is nullptr."));
        return false;
    }

    return true;
}

