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

#include "StorageClientLibrary.h"
#include "IAntilatencyStorageClientModule.h"

#include "StorageClientLog.h"

#include <ExceptionCheck.h>

UStorageClientLibrary* UStorageClientLibrary::GetLibrary() {
    auto module = IAntilatencyStorageClientModule::Get();
    const auto native = module.GetNativeLibrary();

    if (native == nullptr) {
        return nullptr;
    }

    return ObjectConstructor<UStorageClientLibrary>::create(native);
}

Antilatency::InterfaceContract::ExceptionCode UStorageClientLibrary::GetRemoteStorage(const FString& ipAddress, const uint32 port, UStorage*& result) {
    if (!IsValid()) {
        STORAGECLIENT_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    Antilatency::StorageClient::IStorage nativeResult;
    auto exception = _native.getRemoteStorage(TCHAR_TO_UTF8(*ipAddress), static_cast<uint32_t>(port), nativeResult);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();
    
    if (nativeResult == nullptr) {
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    result = ObjectConstructor<UStorage>::create(nativeResult);
    return Antilatency::InterfaceContract::ExceptionCode::Ok;
}

Antilatency::InterfaceContract::ExceptionCode UStorageClientLibrary::GetLocalStorage(UStorage*& result) {
    if (!IsValid()) {
        STORAGECLIENT_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    Antilatency::StorageClient::IStorage nativeResult;
    auto exception = _native.getLocalStorage(nativeResult);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();
    
    if (nativeResult == nullptr) {
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    result = ObjectConstructor<UStorage>::create(nativeResult);
    return Antilatency::InterfaceContract::ExceptionCode::Ok;
}

bool UStorageClientLibrary::IsValid() const {
    if (_native == nullptr) {
        return false;
    }

    return true;
}
