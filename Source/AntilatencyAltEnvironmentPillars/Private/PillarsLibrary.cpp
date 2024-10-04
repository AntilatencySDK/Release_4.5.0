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

#include "PillarsLibrary.h"
#include "PillarsLog.h"

#include <ExceptionCheck.h>

#include "IAntilatencyAltEnvironmentPillarsModule.h"

UPillarsLibrary* UPillarsLibrary::GetPillarsLibrary() {
	auto module = IAntilatencyAltEnvironmentPillarsModule::Get();
	auto native = module.GetNativeLibrary();

	if (native == nullptr) {
		return nullptr;
	}

	return ObjectConstructor<UPillarsLibrary>::create(native);
}

Antilatency::InterfaceContract::ExceptionCode UPillarsLibrary::SerializeEnvironment(const TArray<FPillarsData>& pillars, UPillarsScheme* scheme, FString& result) {
	if (!IsValid()) {
	    PILLARS_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
		return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
	}

	if (scheme == nullptr || !scheme->IsValid()) {
		PILLARS_LOG(Warning, TEXT("UPillarsLibrary::SerializeEnvironment: scheme is null or invalid"));
		return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
	}

	std::vector<Antilatency::Alt::Environment::Pillars::PillarData> pillarsNative;
	const auto pillarsCount = pillars.Num();
	pillarsNative.reserve(pillarsCount);
	
	for (int32 i = 0; i < pillarsCount; ++i) {
		pillarsNative.push_back(pillars[i].ToNative());
	}

	

	std::string nativeResult;
	auto exception = AsInterface<TInterface>().serialize(pillarsNative, scheme->GetNative(), nativeResult);
	ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

	result = {nativeResult.c_str()};
	return exception;
}

Antilatency::InterfaceContract::ExceptionCode UPillarsLibrary::DeserializeEnvironment(const FString& environmentData, UDeserializedEnvironment*& result) {
	if (!IsValid()) {
	    PILLARS_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
		return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
	}

	Antilatency::Alt::Environment::Pillars::IDeserializedEnvironment nativeResult;
	auto exception = AsInterface<TInterface>().deserialize(std::string(TCHAR_TO_UTF8(*environmentData)), nativeResult);
	ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

	result = ObjectConstructor<UDeserializedEnvironment>::create(nativeResult);
	return exception;
}

