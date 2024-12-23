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

#include "PwmPin.h"

#include "HardwareExtensionInterfaceLog.h"

#include <ExceptionCheck.h>

Antilatency::InterfaceContract::ExceptionCode UPwmPin::SetDuty(float value) {
    if (!IsValid()) {
        HARDWAREEXTENSIONINTERFACE_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    auto exception = _native.setDuty(value);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    return exception;
}

Antilatency::InterfaceContract::ExceptionCode UPwmPin::GetDuty(float& result) {
    if (!IsValid()) {
        HARDWAREEXTENSIONINTERFACE_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    auto exception = _native.getDuty(result);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    return exception;
}

Antilatency::InterfaceContract::ExceptionCode UPwmPin::GetFrequency(uint32& result) {
    if (!IsValid()) {
        HARDWAREEXTENSIONINTERFACE_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    uint32_t nativeResult;
    auto exception = _native.getFrequency(nativeResult);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    result = static_cast<uint32>(nativeResult);
    
    return exception;
}

bool UPwmPin::IsValid() const {
    if (_native == nullptr) {
        return false;
    }

    return true;
}
