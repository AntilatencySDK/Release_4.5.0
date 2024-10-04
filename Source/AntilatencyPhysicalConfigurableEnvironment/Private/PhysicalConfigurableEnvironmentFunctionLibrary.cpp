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

#include "PhysicalConfigurableEnvironmentFunctionLibrary.h"

#include "PhysicalConfigurableEnvironmentLog.h"

void UPhysicalConfigurableEnvironmentFunctionLibrary::GetPhysicalConfigurableEnvironmentLibrary(
    UPhysicalConfigurableEnvironmentLibrary*& result,
    EPhysicalConfigurableEnvironmentExceptionResult& exception
) {
    result = UPhysicalConfigurableEnvironmentLibrary::GetLibrary();
    exception = static_cast<EPhysicalConfigurableEnvironmentExceptionResult>(result != nullptr);
}


void UPhysicalConfigurableEnvironmentFunctionLibrary::CreateCotaskConstructor(
    UPhysicalConfigurableEnvironmentLibrary* library,
    UPhysicalConfigurableEnvironmentCotaskConstructor*& result,
    EPhysicalConfigurableEnvironmentExceptionResult& exception
) {
    if (library == nullptr) {
        exception = EPhysicalConfigurableEnvironmentExceptionResult::Fail;
        return;
    }

    const auto callResult = library->CreateCotaskConstructor(result);
    exception = static_cast<EPhysicalConfigurableEnvironmentExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}


void UPhysicalConfigurableEnvironmentFunctionLibrary::StartTask(
    UPhysicalConfigurableEnvironmentCotaskConstructor* constructor,
    UDeviceNetwork* network,
    const FAdnNode& node,
    UPhysicalConfigurableEnvironmentCotask*& result,
    EPhysicalConfigurableEnvironmentExceptionResult& exception
) {
    if (constructor == nullptr) {
        exception = EPhysicalConfigurableEnvironmentExceptionResult::Fail;
        return;
    }

    const auto callResult = constructor->StartTask(network, node, result);
    exception = static_cast<EPhysicalConfigurableEnvironmentExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

int32 UPhysicalConfigurableEnvironmentFunctionLibrary::GetConfigId(
    UPhysicalConfigurableEnvironmentCotask* cotask,
    EPhysicalConfigurableEnvironmentExceptionResult& exception
) {
    if (cotask == nullptr) {
        exception = EPhysicalConfigurableEnvironmentExceptionResult::Fail;
        return 0;
    }

    uint32_t result;
    const auto callResult = cotask->GetConfigId(result);
    exception = static_cast<EPhysicalConfigurableEnvironmentExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);

    if (exception == EPhysicalConfigurableEnvironmentExceptionResult::Fail) {
        return 0;
    }
    
    if (static_cast<uint32_t>(TNumericLimits<int32>::Max()) < result) {
        PHYSICALCONFIGURABLEENVRIONMENT_LOG(Error, TEXT("UPhysicalConfigurableEnvironmentFunctionLibrary::GetConfigId: value is out of range of int32"));
        exception = EPhysicalConfigurableEnvironmentExceptionResult::Fail;
        return 0;
    }
    
    return static_cast<int32>(result);
}


void UPhysicalConfigurableEnvironmentFunctionLibrary::SetConfigId(
    UPhysicalConfigurableEnvironmentCotask* cotask,
    int32 configId,
    EPhysicalConfigurableEnvironmentExceptionResult& exception
) {
    if (cotask == nullptr) {
        exception = EPhysicalConfigurableEnvironmentExceptionResult::Fail;
        return;
    }

    if (configId < 0) {
        PHYSICALCONFIGURABLEENVRIONMENT_LOG(Error, TEXT("UPhysicalConfigurableEnvironmentFunctionLibrary::SetConfigId: config id cannot be less than 0"));
        exception = EPhysicalConfigurableEnvironmentExceptionResult::Fail;
        return;
    }
    
    const auto callResult = cotask->SetConfigId(configId);
    exception = static_cast<EPhysicalConfigurableEnvironmentExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}


int32 UPhysicalConfigurableEnvironmentFunctionLibrary::GetConfigCount(
    UPhysicalConfigurableEnvironmentCotask* cotask,
    EPhysicalConfigurableEnvironmentExceptionResult& exception
) {
    if (cotask == nullptr) {
        exception = EPhysicalConfigurableEnvironmentExceptionResult::Fail;
        return 0;
    }

    uint32_t result;
    const auto callResult = cotask->GetConfigCount(result);
    exception = static_cast<EPhysicalConfigurableEnvironmentExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);

    if (exception == EPhysicalConfigurableEnvironmentExceptionResult::Fail) {
        return 0;
    }
    
    if (static_cast<uint32_t>(TNumericLimits<int32>::Max()) < result) {
        PHYSICALCONFIGURABLEENVRIONMENT_LOG(Error, TEXT("UPhysicalConfigurableEnvironmentFunctionLibrary::GetConfigCount: value is out of range of int32"));
        exception = EPhysicalConfigurableEnvironmentExceptionResult::Fail;
        return 0;
    }
    
    return static_cast<int32>(result);
}


FString UPhysicalConfigurableEnvironmentFunctionLibrary::GetEnvironment(
    UPhysicalConfigurableEnvironmentCotask* cotask,
    int32 configId,
    EPhysicalConfigurableEnvironmentExceptionResult& exception
) {
    FString result = "";
    
    if (cotask == nullptr) {
        exception = EPhysicalConfigurableEnvironmentExceptionResult::Fail;
        return result;
    }

    if (configId < 0) {
        PHYSICALCONFIGURABLEENVRIONMENT_LOG(Error, TEXT("UPhysicalConfigurableEnvironmentFunctionLibrary::GetEnvironment: config id cannot be less than 0"));
        exception = EPhysicalConfigurableEnvironmentExceptionResult::Fail;
        return result;
    }
    
    const auto callResult = cotask->GetEnvironment(static_cast<uint32_t>(configId), result);
    exception = static_cast<EPhysicalConfigurableEnvironmentExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);

    return result;
}


TArray<bool> UPhysicalConfigurableEnvironmentFunctionLibrary::GetMarkersConfig(
    UPhysicalConfigurableEnvironmentCotask* cotask,
    int32 configId,
    EPhysicalConfigurableEnvironmentExceptionResult& exception
) {
    TArray<bool> result = {};
    
    if (cotask == nullptr) {
        exception = EPhysicalConfigurableEnvironmentExceptionResult::Fail;
        return result;
    }

    if (configId < 0) {
        PHYSICALCONFIGURABLEENVRIONMENT_LOG(Error, TEXT("UPhysicalConfigurableEnvironmentFunctionLibrary::GetMarkersConfig: config id cannot be less than 0"));
        exception = EPhysicalConfigurableEnvironmentExceptionResult::Fail;
        return result;
    }

    const auto callResult = cotask->GetMarkersConfig(static_cast<uint32_t>(configId), result);
    exception = static_cast<EPhysicalConfigurableEnvironmentExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);

    return result;
}

FVector UPhysicalConfigurableEnvironmentFunctionLibrary::GetScreenPosition(
    UPhysicalConfigurableEnvironmentCotask* cotask,
    EPhysicalConfigurableEnvironmentExceptionResult& exception
) {
    FVector result = FVector::ZeroVector;
    
    if (cotask == nullptr) {
        exception = EPhysicalConfigurableEnvironmentExceptionResult::Fail;
        return result;
    }

    const auto callResult = cotask->GetScreenPosition(result);
    exception = static_cast<EPhysicalConfigurableEnvironmentExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);

    return result;
}

FVector UPhysicalConfigurableEnvironmentFunctionLibrary::GetScreenX(
    UPhysicalConfigurableEnvironmentCotask* cotask,
    EPhysicalConfigurableEnvironmentExceptionResult& exception
) {
    FVector result = FVector::ZeroVector;
    
    if (cotask == nullptr) {
        exception = EPhysicalConfigurableEnvironmentExceptionResult::Fail;
        return result;
    }

    const auto callResult = cotask->GetScreenX(result);
    exception = static_cast<EPhysicalConfigurableEnvironmentExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);

    return result;
}

FVector UPhysicalConfigurableEnvironmentFunctionLibrary::GetScreenY(
    UPhysicalConfigurableEnvironmentCotask* cotask,
    EPhysicalConfigurableEnvironmentExceptionResult& exception
) {
    FVector result = FVector::ZeroVector;
    
    if (cotask == nullptr) {
        exception = EPhysicalConfigurableEnvironmentExceptionResult::Fail;
        return result;
    }

    const auto callResult = cotask->GetScreenY(result);
    exception = static_cast<EPhysicalConfigurableEnvironmentExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);

    return result;
}


