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

#include "RadioMetricsFunctionLibrary.h"

void URadioMetricsFunctionLibrary::GetLibrary(URadioMetricsLibrary*& result, ERadioMetricsExceptionResult& exception) {
    result = URadioMetricsLibrary::GetLibrary();
    exception = static_cast<ERadioMetricsExceptionResult>(result != nullptr);
}

bool URadioMetricsFunctionLibrary::IsLibraryValid(const URadioMetricsLibrary* radioMetricsLibrary) {
    if (radioMetricsLibrary == nullptr) {
        return false;
    }

    return radioMetricsLibrary->IsValid();
}

void URadioMetricsFunctionLibrary::GetVersion(URadioMetricsLibrary* library, FString& result, ERadioMetricsExceptionResult& exception) {
    if (library == nullptr) {
        exception = ERadioMetricsExceptionResult::Fail;
        return;
    }

    const auto callResult = library->GetVersion(result);
    exception = static_cast<ERadioMetricsExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void URadioMetricsFunctionLibrary::GetCotaskConstructor(URadioMetricsLibrary* library, URadioMetricsCotaskConstructor*& result, ERadioMetricsExceptionResult& exception) {
    if (library == nullptr) {
        exception = ERadioMetricsExceptionResult::Fail;
        return;
    }

    const auto callResult = library->GetCotaskConstructor(result);
    exception = static_cast<ERadioMetricsExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void URadioMetricsFunctionLibrary::StartTask(URadioMetricsCotaskConstructor* constructor, UDeviceNetwork* network, const FAdnNode& node, URadioMetricsCotask*& result,
    ERadioMetricsExceptionResult& exception) {
    if (constructor == nullptr) {
        exception = ERadioMetricsExceptionResult::Fail;
        return;
    }

    const auto callResult = constructor->StartTask(network, node, result);
    exception = static_cast<ERadioMetricsExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
    
}

void URadioMetricsFunctionLibrary::GetMetrics(URadioMetricsCotask* radioMetricsCotask, const FAdnNode& targetNode, FRadioMetrics& result, ERadioMetricsExceptionResult& exception) {
	if (radioMetricsCotask == nullptr) {
		exception = ERadioMetricsExceptionResult::Fail;
		return;
	}

    const auto callResult = radioMetricsCotask->GetMetrics(targetNode, result);
	exception = static_cast<ERadioMetricsExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void URadioMetricsFunctionLibrary::GetExtendedMetrics(URadioMetricsCotask* radioMetricsCotask, const FAdnNode& targetNode, FExtendedMetrics& result, ERadioMetricsExceptionResult& exception) {
	if (radioMetricsCotask == nullptr) {
		exception = ERadioMetricsExceptionResult::Fail;
		return;
	}

    const auto callResult = radioMetricsCotask->GetExtendedMetrics(targetNode, result);
	exception = static_cast<ERadioMetricsExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}