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

#include "StorageClientFunctionLibrary.h"

void UStorageClientFunctionLibrary::GetLibrary(UStorageClientLibrary*& result, EStorageClientExceptionResult& exception) {
    result = UStorageClientLibrary::GetLibrary();
    exception = static_cast<EStorageClientExceptionResult>(result != nullptr);
}

void UStorageClientFunctionLibrary::GetRemoteStorage(UStorageClientLibrary* storageClientLibrary, const FString& ipAddress, int32 port, UStorage*& result, EStorageClientExceptionResult& exception) {
    if (storageClientLibrary == nullptr) {
        exception = EStorageClientExceptionResult::Fail;
        return;
    }

    const auto callResult = storageClientLibrary->GetRemoteStorage(ipAddress, static_cast<uint32>(port), result);
    exception = static_cast<EStorageClientExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UStorageClientFunctionLibrary::GetLocalStorage(UStorageClientLibrary* storageClientLibrary, UStorage*& result, EStorageClientExceptionResult& exception) {
    if (storageClientLibrary == nullptr) {
        exception = EStorageClientExceptionResult::Fail;
        return;
    }

    const auto callResult = storageClientLibrary->GetLocalStorage(result);
    exception = static_cast<EStorageClientExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

bool UStorageClientFunctionLibrary::IsLibraryValid(const UStorageClientLibrary* storageClientLibrary) {
    if (storageClientLibrary == nullptr) {
        return false;
    }

    return storageClientLibrary->IsValid();
}



void UStorageClientFunctionLibrary::Read(UStorage* storage, const FString& group, const FString& key, FString& result, EStorageClientExceptionResult& exception) {
    if (storage == nullptr) {
        exception = EStorageClientExceptionResult::Fail;
        return;
    }

    const auto callResult = storage->Read(group, key, result);
    exception = static_cast<EStorageClientExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UStorageClientFunctionLibrary::Write(UStorage* storage, const FString& group, const FString& key, const FString& data, EStorageClientExceptionResult& exception) {
    if (storage == nullptr) {
        exception = EStorageClientExceptionResult::Fail;
        return;
    }

    const auto callResult = storage->Write(group, key, data);
    exception = static_cast<EStorageClientExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UStorageClientFunctionLibrary::Remove(UStorage* storage, const FString& group, const FString& key, EStorageClientExceptionResult& exception) {
    if (storage == nullptr) {
        exception = EStorageClientExceptionResult::Fail;
        return;
    }

    const auto callResult = storage->Remove(group, key);
    exception = static_cast<EStorageClientExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UStorageClientFunctionLibrary::Next(UStorage* storage, const FString& group, const FString& key, FString& result, EStorageClientExceptionResult& exception) {
    if (storage == nullptr) {
        exception = EStorageClientExceptionResult::Fail;
        return;
    }

    const auto callResult = storage->Next(group, key, result);
    exception = static_cast<EStorageClientExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UStorageClientFunctionLibrary::Exists(UStorage* storage, bool& result, EStorageClientExceptionResult& exception) {
    if (storage == nullptr) {
        exception = EStorageClientExceptionResult::Fail;
        return;
    }

    const auto callResult = storage->Exists(result);
    exception = static_cast<EStorageClientExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

bool UStorageClientFunctionLibrary::IsStorageValid(const UStorage* storage) {
    if (storage == nullptr) {
        return false;
    }

    return storage->IsValid();
}
