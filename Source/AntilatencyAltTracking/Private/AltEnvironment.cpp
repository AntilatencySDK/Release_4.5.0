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

#include "AltEnvironment.h"

#include "AltTrackingLibrary.h"
#include "AltTrackingLog.h"

#include <ExceptionCheck.h>

Antilatency::Alt::Environment::IEnvironment UAltEnvironment::GetNative() {
    return _native;
}

Antilatency::InterfaceContract::ExceptionCode UAltEnvironment::GetMarkers(TArray<FVector>& result) {
    if (!IsValid()) {
        ALTTRACKING_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    std::vector<Antilatency::Math::float3> markers;
    auto exception = _native.getMarkers(markers);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    for (auto marker : markers) {
        result.Add({ marker.x, marker.y, marker.z});
    }

    return exception;
}

Antilatency::InterfaceContract::ExceptionCode UAltEnvironment::IsMutable(bool& result) {
    if (!IsValid()) {
        ALTTRACKING_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    Antilatency::InterfaceContract::LongBool nativeResult;
    auto exception = _native.isMutable(nativeResult);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    result = static_cast<bool>(nativeResult);
    return exception;
}

Antilatency::InterfaceContract::ExceptionCode UAltEnvironment::FilterRay(FVector up, FVector ray, bool& result) {
    if (!IsValid()) {
        ALTTRACKING_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    Antilatency::InterfaceContract::LongBool nativeResult;
    const Antilatency::Math::float3 nativeUp = { static_cast<float>(up.X), static_cast<float>(up.Y), static_cast<float>(up.Z) };
    const Antilatency::Math::float3 nativeRay = { static_cast<float>(ray.X), static_cast<float>(ray.Y), static_cast<float>(ray.Z) };
    
    auto exception = _native.filterRay(nativeUp, nativeRay, nativeResult);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    result = static_cast<bool>(nativeResult);
    return exception;
}

Antilatency::InterfaceContract::ExceptionCode UAltEnvironment::Match(const TArray<FVector>& raysUpSpace, const TArray<uint32>& markersIndices, const FAltPose& poseOfUpSpace, bool& result) {
    if (!IsValid()) {
        ALTTRACKING_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    Antilatency::InterfaceContract::LongBool nativeResult;

    std::vector<Antilatency::Math::float3> nativeRaysUpSpace;
    nativeRaysUpSpace.reserve(raysUpSpace.Num());
    for (int32 i = 0; i < raysUpSpace.Num(); ++i) {
        nativeRaysUpSpace.push_back({ static_cast<float>(raysUpSpace[i].X), static_cast<float>(raysUpSpace[i].Y), static_cast<float>(raysUpSpace[i].Z) });
    }

    std::vector<Antilatency::Alt::Environment::MarkerIndex> nativeMarkersIndices;
    nativeMarkersIndices.reserve(markersIndices.Num());
    for (int32 i = 0; i < markersIndices.Num(); ++i) {
        nativeMarkersIndices.push_back(static_cast<Antilatency::Alt::Environment::MarkerIndex>(markersIndices[i]));
    }

    Antilatency::Math::floatP3Q nativePoseOfUpSpace = poseOfUpSpace.ToNative();

    auto exception = _native.match(nativeRaysUpSpace, nativeMarkersIndices, nativePoseOfUpSpace, nativeResult);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    result = static_cast<bool>(nativeResult);
    return exception;
}

Antilatency::InterfaceContract::ExceptionCode UAltEnvironment::MatchByPosition(const TArray<FVector>& rays, FVector origin, TArray<uint32>& result) {
    if (!IsValid()) {
        ALTTRACKING_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    std::vector<Antilatency::Math::float3> nativeRays;
    nativeRays.reserve(rays.Num());
    for (int32 i = 0; i < rays.Num(); ++i) {
        nativeRays.push_back({ static_cast<float>(rays[i].X), static_cast<float>(rays[i].Y), static_cast<float>(rays[i].Z) });
    }

    const Antilatency::Math::float3 nativeOrigin = { static_cast<float>(origin.X), static_cast<float>(origin.Y), static_cast<float>(origin.Z) };
    std::vector<Antilatency::Alt::Environment::MarkerIndex> nativeResult;
    auto exception = _native.matchByPosition(nativeRays, nativeOrigin, nativeResult);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    result.Empty();
    result.Reserve(nativeResult.size());
    for (auto markerIndex : nativeResult) {
        result.Add(static_cast<uint32>(markerIndex));
    }
    
    return exception;
}

bool UAltEnvironment::IsValid() const {
    if (_native == nullptr) {
        return false;
    }

    return true;
}
