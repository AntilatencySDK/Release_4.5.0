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

#include "TrackingAlignmentLibrary.h"
#include "IAntilatencyTrackingAlignmentModule.h"

#include "TrackingAlignmentLog.h"

#include <ExceptionCheck.h>

UTrackingAlignmentLibrary* UTrackingAlignmentLibrary::GetLibrary() {
    auto module = IAntilatencyTrackingAlignmentModule::Get();
    auto native = module.GetNativeLibrary();

    if (native == nullptr) {
        return nullptr;
    }

    return ObjectConstructor<UTrackingAlignmentLibrary>::create(native);
}

Antilatency::InterfaceContract::ExceptionCode UTrackingAlignmentLibrary::CreateTrackingAlignment(const FQuat& initialARelativeToB, const float initialTimeBAheadOfA, UTrackingAlignment*& result) {
    if (!IsValid()) {
        TRACKINGALIGNMENT_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    const Antilatency::Math::floatQ nativeInitialARelativeToB = { 
		static_cast<float>(initialARelativeToB.X),
		static_cast<float>(initialARelativeToB.Y),
		static_cast<float>(initialARelativeToB.Z),
		static_cast<float>(initialARelativeToB.W)
	};

	Antilatency::TrackingAlignment::ITrackingAlignment native;
	auto exception = _native.createTrackingAlignment(nativeInitialARelativeToB, initialTimeBAheadOfA, native);
	ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

	result = ObjectConstructor<UTrackingAlignment>::create(native);
	
	return exception;
}

bool UTrackingAlignmentLibrary::IsValid() const {
    if (_native == nullptr) {
        return false;
    }
    
    return true;
}