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

#include "RadioMetricsLibrary.h"
#include "IAntilatencyRadioMetricsModule.h"
#include "RadioMetricsLog.h"

#include <ExceptionCheck.h>

URadioMetricsLibrary* URadioMetricsLibrary::GetLibrary() {
    auto module = IAntilatencyRadioMetricsModule::Get();
    auto native = module.GetNativeLibrary();

    if (native == nullptr) {
        return nullptr;
    }

    return ObjectConstructor<URadioMetricsLibrary>::create(native);
}


bool URadioMetricsLibrary::IsValid() const {
    if (_native == nullptr) {
        return false;
    }
    return true;
}

Antilatency::InterfaceContract::ExceptionCode URadioMetricsLibrary::GetVersion(FString& result) {
    if (!IsValid()) {
        RADIOMETRICS_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    std::string nativeResult;
    auto exception = _native.getVersion(nativeResult);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    result = {nativeResult.c_str()};
    return exception;
}

Antilatency::InterfaceContract::ExceptionCode URadioMetricsLibrary::GetCotaskConstructor(URadioMetricsCotaskConstructor*& result) {
    if (!IsValid()) {
        RADIOMETRICS_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    Antilatency::RadioMetrics::ICotaskConstructor nativeResult;
    auto exception = _native.getCotaskConstructor(nativeResult);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    result = ObjectConstructor<URadioMetricsCotaskConstructor>::create(nativeResult);
    return exception;   
}
