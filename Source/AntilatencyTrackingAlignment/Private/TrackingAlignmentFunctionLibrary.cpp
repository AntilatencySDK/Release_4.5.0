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

#include "TrackingAlignmentFunctionLibrary.h"

void UTrackingAlignmentFunctionLibrary::GetLibrary(UTrackingAlignmentLibrary*& result, ETrackingAlignmentExceptionResult& exception) {
    result = UTrackingAlignmentLibrary::GetLibrary();
    exception = static_cast<ETrackingAlignmentExceptionResult>(result != nullptr);
}

void UTrackingAlignmentFunctionLibrary::CreateTrackingAlignment(UTrackingAlignmentLibrary* trackingAlignmentLibrary, const FQuat& initialARelativeToB, const float initialTimeBAheadOfA, UTrackingAlignment*& result, ETrackingAlignmentExceptionResult& exception) {
    if (trackingAlignmentLibrary == nullptr) {
        exception = ETrackingAlignmentExceptionResult::Fail;
        return;
    }

    const auto callResult = trackingAlignmentLibrary->CreateTrackingAlignment(initialARelativeToB, initialTimeBAheadOfA, result);
    exception = static_cast<ETrackingAlignmentExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

bool UTrackingAlignmentFunctionLibrary::IsLibraryValid(const UTrackingAlignmentLibrary* trackingAlignmentLibrary) {
    if (trackingAlignmentLibrary == nullptr) {
        return false;
    }

    return trackingAlignmentLibrary->IsValid();
}

void UTrackingAlignmentFunctionLibrary::Update(UTrackingAlignment* trackingAlignment, const FQuat& a, const FQuat& b, const float time, FTrackingAlignmentState& result, ETrackingAlignmentExceptionResult& exception) {
	result = {};

	if (trackingAlignment == nullptr) {
        exception = ETrackingAlignmentExceptionResult::Fail;
        return;
    }

    const auto callResult = trackingAlignment->Update(a, b, time, result);
    exception = static_cast<ETrackingAlignmentExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

bool UTrackingAlignmentFunctionLibrary::IsTrackingAlignmentValid(const UTrackingAlignment* trackingAlignment) {
    if (trackingAlignment == nullptr) {
        return false;
    }
    
    return trackingAlignment->IsValid();
}


