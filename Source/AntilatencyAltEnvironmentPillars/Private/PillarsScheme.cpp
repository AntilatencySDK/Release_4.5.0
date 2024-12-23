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

#include "PillarsScheme.h"

#include "PillarsLog.h"

#include <ExceptionCheck.h>


UPillarsScheme::TInterface UPillarsScheme::GetNative() {
	return _native;
}

bool UPillarsScheme::IsValid() const {
	return _native != nullptr;
}

Antilatency::InterfaceContract::ExceptionCode UPillarsScheme::GetNumMarkersPerPillar(uint32_t& result) {
	if (!IsValid()) {
		PILLARS_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
		return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
	}
	
	auto exception = _native.getNumMarkersPerPillar(result);
	ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

	return exception;
}

Antilatency::InterfaceContract::ExceptionCode UPillarsScheme::SetNumMarkersPerPillar(const uint32_t numMarkersPerPillar) {
	if (!IsValid()) {
		PILLARS_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
		return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
	}

	auto exception = _native.setNumMarkersPerPillar(numMarkersPerPillar);
	ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

	return exception;
}

Antilatency::InterfaceContract::ExceptionCode UPillarsScheme::GetPillarLength(float& result) {
	if (!IsValid()) {
		PILLARS_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
		return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
	}

	auto exception = _native.getPillarLength(result);
	ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

	return exception;
}

Antilatency::InterfaceContract::ExceptionCode UPillarsScheme::SetPillarLength(const float pillarLength) {
	if (!IsValid()) {
		PILLARS_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
		return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
	}

	auto exception = _native.setPillarLength(pillarLength);
	ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

	return exception;
}

Antilatency::InterfaceContract::ExceptionCode UPillarsScheme::GetDefaultFovDeg(float& result) {
	if (!IsValid()) {
		PILLARS_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
		return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
	}

	auto exception = _native.getDefaultFovDeg(result);
	ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

	return exception;
}

Antilatency::InterfaceContract::ExceptionCode UPillarsScheme::SetDefaultFovDeg(const float defaultFovDeg) {
	if (!IsValid()) {
		PILLARS_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
		return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
	}

	auto exception = _native.setDefaultFovDeg(defaultFovDeg);
	ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

	return exception;
}

Antilatency::InterfaceContract::ExceptionCode UPillarsScheme::GetPillarsVerticalOffset(float& result) {
	if (!IsValid()) {
		PILLARS_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
		return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
	}

	auto exception = _native.getPillarsVerticalOffset(result);
	ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

	return exception;
}

Antilatency::InterfaceContract::ExceptionCode UPillarsScheme::SetPillarsVerticalOffset(const float pillarsVerticalOffset) {
	if (!IsValid()) {
		PILLARS_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
		return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
	}

	auto exception = _native.setPillarsVerticalOffset(pillarsVerticalOffset);
	ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

	return exception;
}

Antilatency::InterfaceContract::ExceptionCode UPillarsScheme::GetStrictMatch(bool& result) {
	if (!IsValid()) {
		PILLARS_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
		return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
	}

	Antilatency::InterfaceContract::LongBool nativeResult;
	auto exception = _native.getStrictMatch(nativeResult);
	ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

	result = static_cast<bool>(nativeResult);

	return exception;
}

Antilatency::InterfaceContract::ExceptionCode UPillarsScheme::SetStrictMatch(const bool strictMatch) {
	if (!IsValid()) {
		PILLARS_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
		return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
	}

	auto exception = _native.setStrictMatch(static_cast<Antilatency::InterfaceContract::LongBool>(strictMatch));
	ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

	return exception;
}

Antilatency::InterfaceContract::ExceptionCode UPillarsScheme::GetNumPillarsKinds(uint32_t& result) {
	if (!IsValid()) {
		PILLARS_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
		return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
	}

	auto exception = _native.getNumPillarsKinds(result);
	ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

	return exception;
}

Antilatency::InterfaceContract::ExceptionCode UPillarsScheme::SetNumPillarsKinds(const uint32_t numPillarsKinds) {
	if (!IsValid()) {
		PILLARS_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
		return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
	}

	auto exception = _native.setNumPillarsKinds(numPillarsKinds);
	ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

	return exception;
}

Antilatency::InterfaceContract::ExceptionCode UPillarsScheme::GetProportions(const uint32_t pillarKind, TArray<float>& result) {
	if (!IsValid()) {
		PILLARS_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
		return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
	}

	std::vector<float> nativeResult = {};
	auto exception = _native.getProportions(pillarKind, nativeResult);
	ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

	const auto propsCount = nativeResult.size();

	result.Empty(propsCount);
	
	for (size_t i = 0; i < propsCount; ++i) {
		result.Add(nativeResult[i]);
	}

	return exception;
}

Antilatency::InterfaceContract::ExceptionCode UPillarsScheme::SetProportions(const TArray<float>& proportions, const uint32_t pillarKind) {
	if (!IsValid()) {
		PILLARS_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
		return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
	}

	const auto propsCount = proportions.Num();
	std::vector<float> nativeValue = {};
	nativeValue.reserve(propsCount);

	for (int32 i = 0; i < propsCount; ++i) {
		nativeValue.push_back(proportions[i]);
	}
	
	auto exception = _native.setProportions(nativeValue, pillarKind);
	ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

	return exception;
}











