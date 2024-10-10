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

#include "EnvironmentConstructor.h"

#include "AltTrackingLog.h"
#include <ExceptionCheck.h>

UEnvironmentConstructor::TInterface UEnvironmentConstructor::GetNative() {
    return _native;
}

bool UEnvironmentConstructor::IsValid() const {
    return _native != nullptr;
}

Antilatency::InterfaceContract::ExceptionCode UEnvironmentConstructor::CreateEnvironment(const FString& data, UAltEnvironment*& result) {
    if (!IsValid()) {
        ALTTRACKING_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    Antilatency::Alt::Environment::IEnvironment nativeResult;
    auto exception = _native.createEnvironment(std::string(TCHAR_TO_UTF8(*data)), nativeResult);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    result = ObjectConstructor<UAltEnvironment>::create(nativeResult);
    return exception;
}


