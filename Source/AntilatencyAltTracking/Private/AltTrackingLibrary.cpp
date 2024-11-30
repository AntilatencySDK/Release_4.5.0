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

#include "AltTrackingLibrary.h"
#include "IAntilatencyAltTrackingModule.h"
#include "AltTrackingLog.h"

#include "Math/UnrealMathUtility.h"

#include <ExceptionCheck.h>

UAltTrackingLibrary* UAltTrackingLibrary::GetLibrary() {
    auto module = IAntilatencyAltTrackingModule::Get();
    auto library = module.GetNativeLibrary();

    if (library == nullptr) {
        return nullptr;
    }

    return ObjectConstructor<UAltTrackingLibrary>::create(library);
}

UAltTrackingLibrary::TInterface UAltTrackingLibrary::GetNative() {
    return _native;
}

Antilatency::InterfaceContract::ExceptionCode UAltTrackingLibrary::CreatePlacement(const FString& code, FAltPose& result) {
    if (!IsValid()) {
        ALTTRACKING_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    Antilatency::Math::floatP3Q nativePlacement;
    auto exception = _native.createPlacement(std::string(TCHAR_TO_UTF8(*code)), nativePlacement);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    result = FAltPose(nativePlacement);
    return exception;
}

Antilatency::InterfaceContract::ExceptionCode UAltTrackingLibrary::EncodePlacement(const FAltPose& placement, FString& result) {
    if (!IsValid()) {
        ALTTRACKING_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    std::string nativeValue;

    const FRotator placementRotation = FRotator(placement.Rotation);
    
    auto exception = _native.encodePlacement(
        placement.ToNative().position,
        {
	        static_cast<float>(FMath::DegreesToRadians(placementRotation.Pitch)),
	        static_cast<float>(FMath::DegreesToRadians(placementRotation.Yaw)),
	        static_cast<float>(FMath::DegreesToRadians(placementRotation.Roll))
	    },
	    nativeValue
	);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    result = { nativeValue.c_str() };
    return exception;
}

Antilatency::InterfaceContract::ExceptionCode UAltTrackingLibrary::CreateTrackingCotaskConstructor(UTrackingCotaskConstructor*& result) {
    if (!IsValid()) {
        ALTTRACKING_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    Antilatency::Alt::Tracking::ITrackingCotaskConstructor nativeResult;
    auto exception = _native.createTrackingCotaskConstructor(nativeResult);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    result = ObjectConstructor<UTrackingCotaskConstructor>::create(nativeResult);
    return exception;
}

bool UAltTrackingLibrary::IsValid() const {
    if (_native == nullptr) {
        return false;
    }
    return true;
}
