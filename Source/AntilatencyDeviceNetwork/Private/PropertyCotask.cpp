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

#include "PropertyCotask.h"

#include "AdnLog.h"

#include <ExceptionCheck.h>

Antilatency::InterfaceContract::ExceptionCode UPropertyCotask::GetPropertyKey(const uint32 index, FString& result) {
    if (!IsValid()) {
        ADN_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    std::string nativeResult;
    auto exception = AsInterface<TInterface>().getPropertyKey(static_cast<uint32_t>(index), nativeResult);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    result = {nativeResult.c_str()};
    return exception;
}

Antilatency::InterfaceContract::ExceptionCode UPropertyCotask::GetStringProperty(const FString& key, FString& result) {
    if (!IsValid()) {
        ADN_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    std::string nativeResult;
    auto exception = AsInterface<TInterface>().getStringProperty(std::string(TCHAR_TO_UTF8(*key)), nativeResult);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    result = {nativeResult.c_str()};
    return exception;
}

Antilatency::InterfaceContract::ExceptionCode UPropertyCotask::SetStringProperty(const FString& key, const FString& value) {
    if (!IsValid()) {
        ADN_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    auto exception = AsInterface<TInterface>().setStringProperty(std::string(TCHAR_TO_UTF8(*key)), std::string(TCHAR_TO_UTF8(*value)));
    ANTILATENCY_EXCEPTION_CHECK();

    return exception;
}

Antilatency::InterfaceContract::ExceptionCode UPropertyCotask::GetBinaryProperty(const FString& key, TArray<uint8>& result) {
    if (!IsValid()) {
        ADN_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    std::vector<uint8_t> nativeResult;
    auto exception = AsInterface<TInterface>().getBinaryProperty(std::string(TCHAR_TO_UTF8(*key)), nativeResult);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    result.Reserve(nativeResult.size());

    for (auto prop : nativeResult) {
        result.Add(static_cast<uint8>(prop));        
    }
    
    return exception;
}

Antilatency::InterfaceContract::ExceptionCode UPropertyCotask::SetBinaryProperty(const FString& key, const TArray<uint8>& value) {
    if (!IsValid()) {
        ADN_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    std::vector<uint8_t> nativeValue;
    nativeValue.reserve(value.Num());
    for (auto i = 0; i < value.Num(); ++i) {
        nativeValue.push_back(static_cast<uint8_t>(value[i]));
    }

    auto exception = AsInterface<TInterface>().setBinaryProperty(std::string(TCHAR_TO_UTF8(*key)), nativeValue);
    ANTILATENCY_EXCEPTION_CHECK();
    
    return exception;
}

Antilatency::InterfaceContract::ExceptionCode UPropertyCotask::DeleteProperty(const FString& key) {
    if (!IsValid()) {
        ADN_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }
    
    auto exception = AsInterface<TInterface>().deleteProperty(std::string(TCHAR_TO_UTF8(*key)));
    ANTILATENCY_EXCEPTION_CHECK();
        
    return exception;
}
