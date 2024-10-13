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

#include <type_traits>

#include <Antilatency.InterfaceContract.h>

 #define ANTILATENCY_EXCEPTION_CHECK() \
{ \
    static_assert(std::is_base_of<Antilatency::InterfaceContract::IUnsafe, decltype(_native)>::value, "Type mismatch for interace object"); \
    static_assert(std::is_same<decltype(exception), Antilatency::InterfaceContract::ExceptionCode>::value, "Type mismatch for exception"); \
    if(exception != Antilatency::InterfaceContract::ExceptionCode::Ok) { \
        auto exceptionInterface = _native.queryInterface<Antilatency::InterfaceContract::IExceptionData>(); \
        if(exceptionInterface == nullptr) { \
            UE_LOG(LogTemp, Error, TEXT("Failed to read exception message")); \
        }else{ \
            auto msg = exceptionInterface.getMessage(); \
            UE_LOG(LogTemp, Warning, TEXT("%s"), UTF8_TO_TCHAR(msg.c_str())); \
        } \
    } \
}

/** Check for exception and RETURN exception if something going wrong */
#define ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL() \
{ \
    static_assert(std::is_base_of<Antilatency::InterfaceContract::IUnsafe, decltype(_native)>::value, "Type mismatch for interace object"); \
    static_assert(std::is_same<decltype(exception), Antilatency::InterfaceContract::ExceptionCode>::value, "Type mismatch for exception"); \
    if(exception != Antilatency::InterfaceContract::ExceptionCode::Ok) { \
        auto exceptionInterface = _native.queryInterface<Antilatency::InterfaceContract::IExceptionData>(); \
        if(exceptionInterface == nullptr) { \
            UE_LOG(LogTemp, Error, TEXT("Failed to read exception message")); \
        }else{ \
            auto msg = exceptionInterface.getMessage(); \
            UE_LOG(LogTemp, Warning, TEXT("%s"), UTF8_TO_TCHAR(msg.c_str())); \
        } \
        return exception; \
    } \
}
