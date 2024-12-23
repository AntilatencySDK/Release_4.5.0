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

#include "BracerCotask.h"

#include "BracerLog.h"

#include <ExceptionCheck.h>

Antilatency::InterfaceContract::ExceptionCode UBracerCotask::GetTouchChannelsCount(uint32& result) {
	if (!IsValid()) {
	    BRACER_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
		return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
	}

	uint32_t nativeValue;
	auto exception = AsInterface<TInterface>().getTouchChannelsCount(nativeValue);
	ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

	result = static_cast<uint32>(nativeValue);
	return exception;
}

Antilatency::InterfaceContract::ExceptionCode UBracerCotask::GetTouchNativeValue(const uint32 channel, uint32& result) {
	if (!IsValid()) {
	    BRACER_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
		return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
	}

	uint32_t nativeValue;
	auto exception = AsInterface<TInterface>().getTouchNativeValue(static_cast<uint32_t>(channel), nativeValue);
	ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

	result = static_cast<uint32>(nativeValue);
	return exception;
}

Antilatency::InterfaceContract::ExceptionCode UBracerCotask::GetTouch(const uint32 channel, float& result) {
    if (!IsValid()) {
        BRACER_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    auto exception = AsInterface<TInterface>().getTouch(static_cast<uint32_t>(channel), result);
    ANTILATENCY_EXCEPTION_CHECK();
    
    return exception;
}

Antilatency::InterfaceContract::ExceptionCode UBracerCotask::ExecuteVibrationSequence(const TArray<FVibration> vibrationSequence) {
    if (!IsValid()) {
        BRACER_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

	std::vector<Antilatency::Bracer::Vibration> native;
	native.reserve(static_cast<size_t>(vibrationSequence.Num()));

	for (const auto v : vibrationSequence) {
		native.push_back(v.ToNative());
	}

    auto exception = AsInterface<TInterface>().executeVibrationSequence(native);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    return exception;
}