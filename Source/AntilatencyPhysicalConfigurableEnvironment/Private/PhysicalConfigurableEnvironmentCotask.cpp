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

#include "PhysicalConfigurableEnvironmentCotask.h"

#include "PhysicalConfigurableEnvironmentLog.h"

#include <InterfaceIdUtils.h>
#include <ExceptionCheck.h>


Antilatency::InterfaceContract::ExceptionCode UPhysicalConfigurableEnvironmentCotask::GetConfigId(uint32_t& result) {
	if (!IsValid()) {
		PHYSICALCONFIGURABLEENVRIONMENT_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
		return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
	}

	auto exception = AsInterface<TInterface>().getConfigId(result);
	ANTILATENCY_EXCEPTION_CHECK();

	return exception;
}

Antilatency::InterfaceContract::ExceptionCode UPhysicalConfigurableEnvironmentCotask::SetConfigId(uint32_t configId) {
	if (!IsValid()) {
		PHYSICALCONFIGURABLEENVRIONMENT_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
		return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
	}

	auto exception = AsInterface<TInterface>().setConfigId(configId);
	ANTILATENCY_EXCEPTION_CHECK();

	return exception;
}

Antilatency::InterfaceContract::ExceptionCode UPhysicalConfigurableEnvironmentCotask::GetConfigCount(uint32_t& result) {
	if (!IsValid()) {
		PHYSICALCONFIGURABLEENVRIONMENT_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
		return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
	}

	auto exception = AsInterface<TInterface>().getConfigCount(result);
	ANTILATENCY_EXCEPTION_CHECK();

	return exception;
}

Antilatency::InterfaceContract::ExceptionCode UPhysicalConfigurableEnvironmentCotask::GetEnvironment(uint32_t configId, FString& result) {
	if (!IsValid()) {
		PHYSICALCONFIGURABLEENVRIONMENT_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
		return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
	}

	std::string nativeResult;
	auto exception = AsInterface<TInterface>().getEnvironment(configId, nativeResult);
	ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

	result = { nativeResult.c_str() };
	
	return exception;
}

Antilatency::InterfaceContract::ExceptionCode UPhysicalConfigurableEnvironmentCotask::GetMarkersConfig(uint32_t configId, TArray<bool>& result) {
	if (!IsValid()) {
		PHYSICALCONFIGURABLEENVRIONMENT_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
		return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
	}

	std::vector<Antilatency::InterfaceContract::LongBool> nativeResult;
	auto exception = AsInterface<TInterface>().getMarkersConfig(configId, nativeResult);
	ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

	const int32 markersCount = static_cast<int32>(nativeResult.size());
	result.Init(false, markersCount);

	for (int32 i = 0; i < markersCount; i++) {
		result[i] = nativeResult[i];
	}

	return exception;
}

Antilatency::InterfaceContract::ExceptionCode UPhysicalConfigurableEnvironmentCotask::GetScreenPosition(FVector& result) {
	if (!IsValid()) {
		PHYSICALCONFIGURABLEENVRIONMENT_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
		return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
	}

	Antilatency::Math::float3 nativeResult;
	auto exception = AsInterface<TInterface>().getScreenPosition(nativeResult);
	ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

	result.X = { nativeResult.x };
	result.Y = { nativeResult.y };
	result.Z = { nativeResult.z };

	return exception;
}

Antilatency::InterfaceContract::ExceptionCode UPhysicalConfigurableEnvironmentCotask::GetScreenX(FVector& result) {
	if (!IsValid()) {
		PHYSICALCONFIGURABLEENVRIONMENT_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
		return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
	}

	Antilatency::Math::float3 nativeResult;
	auto exception = AsInterface<TInterface>().getScreenX(nativeResult);
	ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

	result.X = { nativeResult.x };
	result.Y = { nativeResult.y };
	result.Z = { nativeResult.z };

	return exception;
}

Antilatency::InterfaceContract::ExceptionCode UPhysicalConfigurableEnvironmentCotask::GetScreenY(FVector& result) {
	if (!IsValid()) {
		PHYSICALCONFIGURABLEENVRIONMENT_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
		return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
	}

	Antilatency::Math::float3 nativeResult;
	auto exception = AsInterface<TInterface>().getScreenY(nativeResult);
	ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

	result.X = { nativeResult.x };
	result.Y = { nativeResult.y };
	result.Z = { nativeResult.z };

	return exception;
}
