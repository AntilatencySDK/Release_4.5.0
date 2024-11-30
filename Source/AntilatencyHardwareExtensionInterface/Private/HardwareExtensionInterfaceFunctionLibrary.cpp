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

#include "HardwareExtensionInterfaceFunctionLibrary.h"
#include "HardwareExtensionInterfaceConstants.h"

void UHardwareExtensionInterfaceFunctionLibrary::GetLibrary(UHardwareExtensionInterfaceLibrary *&result, EHardwareExtensionInterfaceExceptionResult &exception) {
    result = UHardwareExtensionInterfaceLibrary::GetLibrary();
    exception = static_cast<EHardwareExtensionInterfaceExceptionResult>(result != nullptr);
}

bool UHardwareExtensionInterfaceFunctionLibrary::IsLibraryValid(const UHardwareExtensionInterfaceLibrary *library) {
    if (library == nullptr) {
        return false;
    }

    return library->IsValid();
}

void UHardwareExtensionInterfaceFunctionLibrary::GetVersion(UHardwareExtensionInterfaceLibrary* library, FString& result, EHardwareExtensionInterfaceExceptionResult& exception) {
    if (library == nullptr) {
        exception = EHardwareExtensionInterfaceExceptionResult::Fail;
        return;
    }

    const auto callResult = library->GetVersion(result);
    exception = static_cast<EHardwareExtensionInterfaceExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UHardwareExtensionInterfaceFunctionLibrary::GetCotaskConstructor(UHardwareExtensionInterfaceLibrary* library, UHardwareExtensionInterfaceCotaskConstructor*& result,
    EHardwareExtensionInterfaceExceptionResult& exception) {
    if (library == nullptr) {
        exception = EHardwareExtensionInterfaceExceptionResult::Fail;
        return;
    }

    const auto callResult = library->GetCotaskConstructor(result);
    exception = static_cast<EHardwareExtensionInterfaceExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UHardwareExtensionInterfaceFunctionLibrary::StartTask(UHardwareExtensionInterfaceCotaskConstructor* constructor, UDeviceNetwork* network, const FAdnNode& node,
    UHardwareExtensionInterfaceCotask*& result, EHardwareExtensionInterfaceExceptionResult& exception) {
    if (constructor == nullptr) {
        exception = EHardwareExtensionInterfaceExceptionResult::Fail;
        return;
    }

    const auto callResult = constructor->StartTask(network, node, result);
    exception = static_cast<EHardwareExtensionInterfaceExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UHardwareExtensionInterfaceFunctionLibrary::CreateInputPin(UHardwareExtensionInterfaceCotask* cotask, const EPins& pin, UInputPin*& result, EHardwareExtensionInterfaceExceptionResult& exception) {
	if (cotask == nullptr) {
		exception = EHardwareExtensionInterfaceExceptionResult::Fail;
		return;
	}

    const auto callResult = cotask->CreateInputPin(pin, result);
	exception = static_cast<EHardwareExtensionInterfaceExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UHardwareExtensionInterfaceFunctionLibrary::CreateOutputPin(UHardwareExtensionInterfaceCotask* cotask, const EPins& pin, const EPinState& initialState, UOutputPin*& result, EHardwareExtensionInterfaceExceptionResult& exception) {
	if (cotask == nullptr) {
		exception = EHardwareExtensionInterfaceExceptionResult::Fail;
		return;
	}

    const auto callResult = cotask->CreateOutputPin(pin, initialState, result);
	exception = static_cast<EHardwareExtensionInterfaceExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UHardwareExtensionInterfaceFunctionLibrary::CreateAnalogPin(UHardwareExtensionInterfaceCotask* cotask, const EPins& pin, const uint8 refreshIntervalMs, UAnalogPin*& result, EHardwareExtensionInterfaceExceptionResult& exception) {
	if (cotask == nullptr) {
		exception = EHardwareExtensionInterfaceExceptionResult::Fail;
		return;
	}

    const auto callResult = cotask->CreateAnalogPin(pin, static_cast<uint32_t>(refreshIntervalMs), result);
	exception = static_cast<EHardwareExtensionInterfaceExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UHardwareExtensionInterfaceFunctionLibrary::CreatePulseCounterPin(UHardwareExtensionInterfaceCotask* cotask, const EPins& pin, const uint8 refreshIntervalMs, UPulseCounterPin*& result, EHardwareExtensionInterfaceExceptionResult& exception) {
	if (cotask == nullptr) {
		exception = EHardwareExtensionInterfaceExceptionResult::Fail;
		return;
	}

    const auto callResult = cotask->CreatePulseCounterPin(pin, static_cast<uint32_t>(refreshIntervalMs), result);
	exception = static_cast<EHardwareExtensionInterfaceExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UHardwareExtensionInterfaceFunctionLibrary::CreatePwmPin(UHardwareExtensionInterfaceCotask* cotask, const EPins& pin, int32 frequency, float initialDuty, UPwmPin*& result,
    EHardwareExtensionInterfaceExceptionResult& exception) {
    if (cotask == nullptr) {
        exception = EHardwareExtensionInterfaceExceptionResult::Fail;
        return;
    }

    const auto callResult = cotask->CreatePwmPin(pin, static_cast<uint32>(frequency), initialDuty, result);
    exception = static_cast<EHardwareExtensionInterfaceExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UHardwareExtensionInterfaceFunctionLibrary::Run(UHardwareExtensionInterfaceCotask* cotask, EHardwareExtensionInterfaceExceptionResult& exception) {
	if (cotask == nullptr) {
		exception = EHardwareExtensionInterfaceExceptionResult::Fail;
		return;
	}

    const auto callResult = cotask->Run();
	exception = static_cast<EHardwareExtensionInterfaceExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}



void UHardwareExtensionInterfaceFunctionLibrary::GetInputPinState(UInputPin* pin, EPinState& result, EHardwareExtensionInterfaceExceptionResult& exception) {
	if (pin == nullptr) {
		exception = EHardwareExtensionInterfaceExceptionResult::Fail;
		return;
	}

    const auto callResult = pin->GetState(result);
	exception = static_cast<EHardwareExtensionInterfaceExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

bool UHardwareExtensionInterfaceFunctionLibrary::IsInputPinValid(const UInputPin* pin) {
	if (pin == nullptr) {
		return false;
	}

	return pin->IsValid();
}

void UHardwareExtensionInterfaceFunctionLibrary::GetOutputPinState(UOutputPin* pin, EPinState& result, EHardwareExtensionInterfaceExceptionResult& exception) {
	if (pin == nullptr) {
		exception = EHardwareExtensionInterfaceExceptionResult::Fail;
		return;
	}

    const auto callResult = pin->GetState(result);
	exception = static_cast<EHardwareExtensionInterfaceExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UHardwareExtensionInterfaceFunctionLibrary::SetOutputPinState(UOutputPin* pin, const EPinState& state, EHardwareExtensionInterfaceExceptionResult& exception) {
	if (pin == nullptr) {
		exception = EHardwareExtensionInterfaceExceptionResult::Fail;
		return;
	}

    const auto callResult = pin->SetState(state);
	exception = static_cast<EHardwareExtensionInterfaceExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

bool UHardwareExtensionInterfaceFunctionLibrary::IsOutputPinValid(const UOutputPin* pin) {
	if (pin == nullptr) {
		return false;
	}

	return pin->IsValid();
}

void UHardwareExtensionInterfaceFunctionLibrary::GetAnalogPinValue(UAnalogPin* pin, float& result, EHardwareExtensionInterfaceExceptionResult& exception) {
	if (pin == nullptr) {
		exception = EHardwareExtensionInterfaceExceptionResult::Fail;
		return;
	}

    const auto callResult = pin->GetValue(result);
	exception = static_cast<EHardwareExtensionInterfaceExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

bool UHardwareExtensionInterfaceFunctionLibrary::IsAnalogPinValid(const UAnalogPin* pin) {
	if (pin == nullptr) {
		return false;
	}

	return pin->IsValid();
}

void UHardwareExtensionInterfaceFunctionLibrary::GetPulseCounterPinValue(UPulseCounterPin* pin, uint8& result, EHardwareExtensionInterfaceExceptionResult& exception) {
	if (pin == nullptr) {
		exception = EHardwareExtensionInterfaceExceptionResult::Fail;
		return;
	}

	uint16 nativeResult;
    const auto callResult = pin->GetValue(nativeResult);
	result = static_cast<uint8>(nativeResult);
	exception = static_cast<EHardwareExtensionInterfaceExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

bool UHardwareExtensionInterfaceFunctionLibrary::IsPulseCounterPinValid(const UPulseCounterPin* pin) {
	if (pin == nullptr) {
		return false;
	}

	return pin->IsValid();
}

void UHardwareExtensionInterfaceFunctionLibrary::SetDuty(UPwmPin* pin, float value, EHardwareExtensionInterfaceExceptionResult& exception) {
    if (pin == nullptr) {
        exception = EHardwareExtensionInterfaceExceptionResult::Fail;
        return;
    }

    const auto callResult = pin->SetDuty(value);
    exception = static_cast<EHardwareExtensionInterfaceExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UHardwareExtensionInterfaceFunctionLibrary::GetDuty(UPwmPin* pin, float& result, EHardwareExtensionInterfaceExceptionResult& exception) {
    if (pin == nullptr) {
        exception = EHardwareExtensionInterfaceExceptionResult::Fail;
        return;
    }

    const auto callResult = pin->GetDuty(result);
    exception = static_cast<EHardwareExtensionInterfaceExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UHardwareExtensionInterfaceFunctionLibrary::GetFrequency(UPwmPin* pin, int32& result, EHardwareExtensionInterfaceExceptionResult& exception) {
    if (pin == nullptr) {
        exception = EHardwareExtensionInterfaceExceptionResult::Fail;
        return;
    }
    uint32 nativeResult;
    const auto callResult = pin->GetFrequency(nativeResult);
    if (callResult == Antilatency::InterfaceContract::ExceptionCode::Ok) {
        result = static_cast<int32>(nativeResult);
    }
    exception = static_cast<EHardwareExtensionInterfaceExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

bool UHardwareExtensionInterfaceFunctionLibrary::IsPwmPinValid(const UPwmPin* pin, EHardwareExtensionInterfaceExceptionResult& exception) {
    if (pin == nullptr) {
        return false;
    }

    return pin->IsValid();
}

int32 UHardwareExtensionInterfaceFunctionLibrary::AnalogMinRefreshIntervalMs() {
    return static_cast<int32>(HardwareExtensionInterfaceConstants::AnalogMinRefreshIntervalMs);
}

int32 UHardwareExtensionInterfaceFunctionLibrary::AnalogMaxRefreshIntervalMs() {
    return static_cast<int32>(HardwareExtensionInterfaceConstants::AnalogMaxRefreshIntervalMs);
}

int32 UHardwareExtensionInterfaceFunctionLibrary::PulseCounterMinRefreshIntervalMs() {
    return static_cast<int32>(HardwareExtensionInterfaceConstants::PulseCounterMinRefreshIntervalMs);
}

int32 UHardwareExtensionInterfaceFunctionLibrary::PulseCounterMaxRefreshIntervalMs() {
    return static_cast<int32>(HardwareExtensionInterfaceConstants::PulseCounterMaxRefreshIntervalMs);
}

int32 UHardwareExtensionInterfaceFunctionLibrary::PwmMinFrequency() {
    return static_cast<int32>(HardwareExtensionInterfaceConstants::PwmMinFrequency);
}

int32 UHardwareExtensionInterfaceFunctionLibrary::PwmMaxFrequency() {
    return static_cast<int32>(HardwareExtensionInterfaceConstants::PwmMaxFrequency);
}

int32 UHardwareExtensionInterfaceFunctionLibrary::MaxInputPinsCount() {
    return static_cast<int32>(HardwareExtensionInterfaceConstants::MaxInputPinsCount);
}

int32 UHardwareExtensionInterfaceFunctionLibrary::MaxOutputPinsCount() {
    return static_cast<int32>(HardwareExtensionInterfaceConstants::MaxOutputPinsCount);
}

int32 UHardwareExtensionInterfaceFunctionLibrary::MaxAnalogPinsCount() {
    return static_cast<int32>(HardwareExtensionInterfaceConstants::MaxAnalogPinsCount);
}

int32 UHardwareExtensionInterfaceFunctionLibrary::MaxPulseCounterPinsCount() {
    return static_cast<int32>(HardwareExtensionInterfaceConstants::MaxPulseCounterPinsCount);
}

int32 UHardwareExtensionInterfaceFunctionLibrary::MaxPwmPinsCount() {
    return static_cast<int32>(HardwareExtensionInterfaceConstants::MaxPwmPinsCount);
}
