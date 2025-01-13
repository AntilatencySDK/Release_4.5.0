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

#include "BracerFunctionLibrary.h"
#include "BracerConstants.h"

void UBracerFunctionLibrary::GetLibrary(UBracerLibrary *&result, EBracerExceptionResult &exception) {
    result = UBracerLibrary::GetLibrary();
    exception = static_cast<EBracerExceptionResult>(result != nullptr);
}

bool UBracerFunctionLibrary::IsLibraryValid(const UBracerLibrary *bracerLibrary) {
    if (bracerLibrary == nullptr) {
        return false;
    }

    return bracerLibrary->IsValid();
}

void UBracerFunctionLibrary::GetVersion(UBracerLibrary* bracerLibrary, FString& result, EBracerExceptionResult& exception) {
    if (bracerLibrary == nullptr) {
        exception = EBracerExceptionResult::Fail;
        return;
    }

    const auto callResult = bracerLibrary->GetVersion(result);
    exception = static_cast<EBracerExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UBracerFunctionLibrary::GetCotaskConstructor(UBracerLibrary* bracerLibrary, UBracerCotaskConstructor*& result, EBracerExceptionResult& exception) {
    if (bracerLibrary == nullptr) {
        exception = EBracerExceptionResult::Fail;
        return;
    }

    const auto callResult = bracerLibrary->GetCotaskConstructor(result);
    exception = static_cast<EBracerExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UBracerFunctionLibrary::StartTask(UBracerCotaskConstructor* constructor, UDeviceNetwork* network, const FAdnNode& node, UBracerCotask*& result, EBracerExceptionResult& exception) {
    if (constructor == nullptr) {
        exception = EBracerExceptionResult::Fail;
        return;
    }

    const auto callResult = constructor->StartTask(network, node, result);
    exception = static_cast<EBracerExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UBracerFunctionLibrary::GetTouchChannelsCount(UBracerCotask* bracerCotask, int32& result, EBracerExceptionResult& exception) {
	if (bracerCotask == nullptr) {
		exception = EBracerExceptionResult::Fail;
		return;
	}

    uint32 nativeResult;
    const auto callResult = bracerCotask->GetTouchChannelsCount(nativeResult);
    if (callResult == Antilatency::InterfaceContract::ExceptionCode::Ok) {
        result = static_cast<int32>(nativeResult);
    }
	exception = static_cast<EBracerExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UBracerFunctionLibrary::GetTouchNativeValue(UBracerCotask* bracerCotask, const int32 channel, int32& result, EBracerExceptionResult& exception) {
	if (bracerCotask == nullptr) {
		exception = EBracerExceptionResult::Fail;
		return;
	}

    uint32 nativeResult;
    const auto callResult = bracerCotask->GetTouchNativeValue(static_cast<uint32>(channel), nativeResult);
    if (callResult == Antilatency::InterfaceContract::ExceptionCode::Ok) {
        result = static_cast<int32>(nativeResult);
    }
	exception = static_cast<EBracerExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}


void UBracerFunctionLibrary::GetTouch(UBracerCotask* bracerCotask, const int32 channel, float& result, EBracerExceptionResult& exception) {
    if (bracerCotask == nullptr) {
        exception = EBracerExceptionResult::Fail;
        return;
    }

    const auto callResult = bracerCotask->GetTouch(static_cast<uint32>(channel), result);
    exception = static_cast<EBracerExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UBracerFunctionLibrary::ExecuteVibrationSequence(UBracerCotask* bracerCotask, const TArray<FVibration>& vibrationSequence, EBracerExceptionResult& exception) {
    if (bracerCotask == nullptr) {
        exception = EBracerExceptionResult::Fail;
        return;
    }

    const auto callResult = bracerCotask->ExecuteVibrationSequence(vibrationSequence);
    exception = static_cast<EBracerExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UBracerFunctionLibrary::GetTouchWindowBaseName(FString& result) {
    result = TouchWindowBaseName;
}

void UBracerFunctionLibrary::GetTouchChannelsCountPropertyName(FString& result) {
    result = TouchChannelsCountPropertyName;
}

