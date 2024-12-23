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

#include "AltTrackingFunctionLibrary.h"

void UAltTrackingFunctionLibrary::GetTrackingLibrary(UAltTrackingLibrary*& result, EAltTrackingExceptionResult& exception) {
    result = UAltTrackingLibrary::GetLibrary();
    exception = static_cast<EAltTrackingExceptionResult>(result != nullptr);
}

void UAltTrackingFunctionLibrary::CreatePlacement(UAltTrackingLibrary* altTrackingLibrary, const FString& code, FAltPose& result, EAltTrackingExceptionResult& exception) {
    if (altTrackingLibrary == nullptr) {
        exception = EAltTrackingExceptionResult::Fail;
        return;
    }

    const auto callResult = altTrackingLibrary->CreatePlacement(code, result);
    exception = static_cast<EAltTrackingExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UAltTrackingFunctionLibrary::EncodePlacement(UAltTrackingLibrary* altTrackingLibrary, const FAltPose& placement, FString& result, EAltTrackingExceptionResult& exception) {
    if (altTrackingLibrary == nullptr) {
        exception = EAltTrackingExceptionResult::Fail;
        return;
    }

    const auto callResult = altTrackingLibrary->EncodePlacement(placement, result);
    exception = static_cast<EAltTrackingExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UAltTrackingFunctionLibrary::CreateTrackingCotaskConstructor(UAltTrackingLibrary* altTrackingLibrary, UTrackingCotaskConstructor*& result, EAltTrackingExceptionResult& exception) {
    if (altTrackingLibrary == nullptr) {
        exception = EAltTrackingExceptionResult::Fail;
        return;
    }

    const auto callResult = altTrackingLibrary->CreateTrackingCotaskConstructor(result);
    exception = static_cast<EAltTrackingExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

bool UAltTrackingFunctionLibrary::IsLibraryValid(const UAltTrackingLibrary* altTrackingLibrary) {
    if (altTrackingLibrary == nullptr) {
        return false;
    }

    return altTrackingLibrary->IsValid();
}

void UAltTrackingFunctionLibrary::StartTrackingTask(UTrackingCotaskConstructor* constructor, UDeviceNetwork* network, const FAdnNode& node, UAltEnvironment* environment, UAltTrackingCotask*& result,
    EAltTrackingExceptionResult& exception) {
    if (constructor == nullptr) {
        exception = EAltTrackingExceptionResult::Fail;
        return;
    }

    const auto callResult = constructor->StartTask(network, node, environment, result);
    exception = static_cast<EAltTrackingExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UAltTrackingFunctionLibrary::GetState(UAltTrackingCotask* trackingCotask, FTrackingState& result, EAltTrackingExceptionResult& exception) {
    if (trackingCotask == nullptr) {
        exception = EAltTrackingExceptionResult::Fail;
        return;
    }

    const auto callResult = trackingCotask->GetState(result);
    exception = static_cast<EAltTrackingExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UAltTrackingFunctionLibrary::GetExtrapolatedState(UAltTrackingCotask* trackingCotask, const FAltPose& placement, const float deltaTime, FTrackingState& result, EAltTrackingExceptionResult& exception) {
    if (trackingCotask == nullptr) {
        exception = EAltTrackingExceptionResult::Fail;
        return;
    }

    const auto callResult = trackingCotask->GetExtrapolatedState(placement, deltaTime, result);
    exception = static_cast<EAltTrackingExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UAltTrackingFunctionLibrary::IsMutable(UAltEnvironment* environment, bool& result, EAltTrackingExceptionResult& exception) {
    if (environment == nullptr) {
        exception = EAltTrackingExceptionResult::Fail;
        return;
    }

    const auto callResult = environment->IsMutable(result);
    exception = static_cast<EAltTrackingExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UAltTrackingFunctionLibrary::GetMarkers(UAltEnvironment* environment, TArray<FVector>& result, EAltTrackingExceptionResult& exception) {
    if (environment == nullptr) {
        exception = EAltTrackingExceptionResult::Fail;
        return;
    }

    const auto callResult = environment->GetMarkers(result);
    exception = static_cast<EAltTrackingExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UAltTrackingFunctionLibrary::FilterRay(UAltEnvironment* environment, FVector up, FVector ray, bool& result, EAltTrackingExceptionResult& exception) {
    if (environment == nullptr) {
        exception = EAltTrackingExceptionResult::Fail;
        return;
    }

    const auto callResult = environment->FilterRay(up, ray, result);
    exception = static_cast<EAltTrackingExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UAltTrackingFunctionLibrary::Match(UAltEnvironment* environment, const TArray<FVector>& raysUpSpace, const TArray<int32>& markersIndices, const FAltPose& poseOfUpSpace, bool& result,
    EAltTrackingExceptionResult& exception) {
    if (environment == nullptr) {
        exception = EAltTrackingExceptionResult::Fail;
        return;
    }

    TArray<uint32> nativeMarkersIndices;
    nativeMarkersIndices.Reserve(markersIndices.Num());
    for (auto i = 0; i < markersIndices.Num(); ++i) {
        nativeMarkersIndices.Add(static_cast<uint32>(markersIndices[i]));
    }

    const auto callResult = environment->Match(raysUpSpace, nativeMarkersIndices, poseOfUpSpace,result);
    exception = static_cast<EAltTrackingExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UAltTrackingFunctionLibrary::MatchByPosition(UAltEnvironment* environment, const TArray<FVector>& rays, FVector origin, TArray<int32>& result, EAltTrackingExceptionResult& exception) {
    if (environment == nullptr) {
        exception = EAltTrackingExceptionResult::Fail;
        return;
    }

    TArray<uint32> nativeResult;
    
    const auto callResult = environment->MatchByPosition(rays, origin, nativeResult);

    result.Reserve(nativeResult.Num());
    for (auto i = 0; i < nativeResult.Num(); ++i) {
        result.Add(static_cast<int32>(nativeResult[i]));
    }
    
    exception = static_cast<EAltTrackingExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

bool UAltTrackingFunctionLibrary::IsAltEnvironmentValid(const UAltEnvironment* environment) {
    if (environment == nullptr) {
        return false;
    }

    return environment->IsValid();
}

void UAltTrackingFunctionLibrary::CreateEnvironment(UEnvironmentConstructor* constructor, const FString& data, UAltEnvironment*& result, EAltTrackingExceptionResult& exception) {
    if (constructor == nullptr) {
        exception = EAltTrackingExceptionResult::Fail;
        return;
    }

    const auto callResult = constructor->CreateEnvironment(data, result);
    exception = static_cast<EAltTrackingExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

bool UAltTrackingFunctionLibrary::IsValid(const UEnvironmentConstructor* constructor) {
    if (constructor == nullptr) {
        return false;
    }

    return constructor->IsValid();
}
