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

#include "Arbitrary2DFunctionLibrary.h"

void UArbitrary2DFunctionLibrary::GetArbitrary2DLibrary(UArbitrary2DLibrary*& result, EArbitrary2DExceptionResult& exception) {
    result = UArbitrary2DLibrary::GetArbitrary2DLibrary();
    exception = static_cast<EArbitrary2DExceptionResult>(result != nullptr);
}

void UArbitrary2DFunctionLibrary::SerializeEnvironment(UArbitrary2DLibrary* arbitrary2DLibrary, const TArray<FVector2D>& markers, const float height, const bool floor, FString& result, EArbitrary2DExceptionResult& exception) {
    if (arbitrary2DLibrary == nullptr) {
        exception = EArbitrary2DExceptionResult::Fail;
        return;
    }

    const auto callResult = arbitrary2DLibrary->SerializeEnvironment(markers, height, floor, result);
    exception = static_cast<EArbitrary2DExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UArbitrary2DFunctionLibrary::DeserializeEnvironment(UArbitrary2DLibrary* arbitrary2DLibrary, const FString& environmentData, UArbitrary2DDeserializedEnvironment*& result, EArbitrary2DExceptionResult& exception) {
    if (arbitrary2DLibrary == nullptr) {
        exception = EArbitrary2DExceptionResult::Fail;
        return;
    }

    const auto callResult = arbitrary2DLibrary->DeserializeEnvironment(environmentData, result);
    exception = static_cast<EArbitrary2DExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UArbitrary2DFunctionLibrary::GetMarkers(UArbitrary2DDeserializedEnvironment* deserializedEnvironment, TArray<FVector2D>& result, EArbitrary2DExceptionResult& exception) {
    if (deserializedEnvironment == nullptr) {
        exception = EArbitrary2DExceptionResult::Fail;
        return;
    }

    const auto callResult = deserializedEnvironment->GetMarkers(result);
    exception = static_cast<EArbitrary2DExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UArbitrary2DFunctionLibrary::GetHeight(UArbitrary2DDeserializedEnvironment* deserializedEnvironment, float& result, EArbitrary2DExceptionResult& exception) {
    if (deserializedEnvironment == nullptr) {
        exception = EArbitrary2DExceptionResult::Fail;
        return;
    }

    const auto callResult = deserializedEnvironment->GetHeight(result);
    exception = static_cast<EArbitrary2DExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UArbitrary2DFunctionLibrary::GetFloor(UArbitrary2DDeserializedEnvironment* deserializedEnvironment, bool& result, EArbitrary2DExceptionResult& exception) {
    if (deserializedEnvironment == nullptr) {
        exception = EArbitrary2DExceptionResult::Fail;
        return;
    }
    
    const auto callResult = deserializedEnvironment->GetFloor(result);
    exception = static_cast<EArbitrary2DExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

bool UArbitrary2DFunctionLibrary::IsValid(const UArbitrary2DDeserializedEnvironment* deserializedEnvironment) {
    if (deserializedEnvironment == nullptr) {
        return false;
    }

    return deserializedEnvironment->IsValid();
}
