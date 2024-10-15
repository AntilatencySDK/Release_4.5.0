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

#include "Arbitrary2DLibrary.h"
#include "Arbitrary2DLog.h"

#include <ExceptionCheck.h>

#include "IAntilatencyAltEnvironmentArbitrary2DModule.h"

UArbitrary2DLibrary* UArbitrary2DLibrary::GetArbitrary2DLibrary() {
	auto module = IAntilatencyAltEnvironmentArbitrary2DModule::Get();
	auto native = module.GetNativeLibrary();

	if (native == nullptr) {
		return nullptr;
	}

	return ObjectConstructor<UArbitrary2DLibrary>::create(native);
}

Antilatency::InterfaceContract::ExceptionCode UArbitrary2DLibrary::SerializeEnvironment(const TArray<FVector2D>& markers, const float height, const bool floor, FString& result) {
	if (!IsValid()) {
	    ARBITRARY2D_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
		return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
	}

	std::vector<Antilatency::Math::float2> markersNative;
	const auto markersCount = markers.Num();
	markersNative.reserve(markersCount);
	
	for (int32 i = 0; i < markersCount; ++i) {
		markersNative.push_back({ static_cast<float>(markers[i].X), static_cast<float>(markers[i].Y) });
	}

	std::string nativeResult;
	auto exception = AsInterface<TInterface>().serialize(markersNative, height, static_cast<Antilatency::InterfaceContract::LongBool>(floor), nativeResult);
	ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

	result = {nativeResult.c_str()};
	return exception;
}

Antilatency::InterfaceContract::ExceptionCode UArbitrary2DLibrary::DeserializeEnvironment(const FString& environmentData, UArbitrary2DDeserializedEnvironment*& result) {
	if (!IsValid()) {
	    ARBITRARY2D_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
		return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
	}

	Antilatency::Alt::Environment::Arbitrary2D::IDeserializedEnvironment nativeResult;
	auto exception = AsInterface<TInterface>().deserialize(std::string(TCHAR_TO_UTF8(*environmentData)), nativeResult);
	ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

	result = ObjectConstructor<UArbitrary2DDeserializedEnvironment>::create(nativeResult);
	return exception;
}

