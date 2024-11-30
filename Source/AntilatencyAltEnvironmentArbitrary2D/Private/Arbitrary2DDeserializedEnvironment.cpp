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

#include "Arbitrary2DDeserializedEnvironment.h"

#include "Arbitrary2DLog.h"

#include <ExceptionCheck.h>

UArbitrary2DDeserializedEnvironment::TInterface UArbitrary2DDeserializedEnvironment::GetNative() {
	return _native;
}

Antilatency::InterfaceContract::ExceptionCode UArbitrary2DDeserializedEnvironment::GetMarkers(TArray<FVector2D>& result) {
	if (!IsValid()) {
	    ARBITRARY2D_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
		return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
	}

	std::vector<Antilatency::Math::float2> nativeResult;
	auto exception = _native.getMarkers(nativeResult);
	ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

	for(auto marker : nativeResult) {
		result.Add({marker.x, marker.y});
	}

	return exception;
}

Antilatency::InterfaceContract::ExceptionCode UArbitrary2DDeserializedEnvironment::GetHeight(float& result) {
	if (!IsValid()) {
	    ARBITRARY2D_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
		return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
	}
    
	auto exception = _native.getHeight(result);
	ANTILATENCY_EXCEPTION_CHECK();

	return exception;
}

Antilatency::InterfaceContract::ExceptionCode UArbitrary2DDeserializedEnvironment::GetFloor(bool& result) {
	if (!IsValid()) {
	    ARBITRARY2D_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
		return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
	}

	Antilatency::InterfaceContract::LongBool nativeResult;
	auto exception = _native.getFloor(nativeResult);
	ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

	result = static_cast<bool>(nativeResult);
	return exception;
}

bool UArbitrary2DDeserializedEnvironment::IsValid() const {
	return _native != nullptr;
}


