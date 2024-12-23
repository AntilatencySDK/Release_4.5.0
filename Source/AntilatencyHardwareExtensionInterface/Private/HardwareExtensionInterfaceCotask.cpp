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

#include "HardwareExtensionInterfaceCotask.h"

#include "HardwareExtensionInterfaceLog.h"

#include <ExceptionCheck.h>

Antilatency::InterfaceContract::ExceptionCode UHardwareExtensionInterfaceCotask::CreateInputPin(const EPins& pin, UInputPin*& result) {
	if (!IsValid()) {
	    HARDWAREEXTENSIONINTERFACE_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
		return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
	}

	Antilatency::HardwareExtensionInterface::IInputPin nativeResult;
	auto exception = AsInterface<TInterface>().createInputPin(static_cast<Antilatency::HardwareExtensionInterface::Interop::Pins>(pin), nativeResult);
	ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    if (nativeResult == nullptr) {
        HARDWAREEXTENSIONINTERFACE_LOG(Warning, TEXT("Failed to create input pin"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

	result = ObjectConstructor<UInputPin>::create(nativeResult);
	return exception;
}

Antilatency::InterfaceContract::ExceptionCode UHardwareExtensionInterfaceCotask::CreateOutputPin(const EPins& pin, const EPinState& initialState, UOutputPin*& result) {
	if (!IsValid()) {
	    HARDWAREEXTENSIONINTERFACE_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
		return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
	}

	Antilatency::HardwareExtensionInterface::IOutputPin nativeResult;
	auto exception = AsInterface<TInterface>().createOutputPin(static_cast<Antilatency::HardwareExtensionInterface::Interop::Pins>(pin), static_cast<Antilatency::HardwareExtensionInterface::Interop::PinState>(initialState), nativeResult);
	ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    if (nativeResult == nullptr) {
        HARDWAREEXTENSIONINTERFACE_LOG(Warning, TEXT("Failed to create output pin"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }
    
	result = ObjectConstructor<UOutputPin>::create(nativeResult);
	return exception;
}

Antilatency::InterfaceContract::ExceptionCode UHardwareExtensionInterfaceCotask::CreateAnalogPin(const EPins& pin, const uint32 refreshIntervalMs, UAnalogPin*& result) {
	if (!IsValid()) {
	    HARDWAREEXTENSIONINTERFACE_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
		return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
	}

	Antilatency::HardwareExtensionInterface::IAnalogPin nativeResult;
	auto exception = AsInterface<TInterface>().createAnalogPin(static_cast<Antilatency::HardwareExtensionInterface::Interop::Pins>(pin), static_cast<uint32_t>(refreshIntervalMs), nativeResult);
	ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    if (nativeResult == nullptr) {
        HARDWAREEXTENSIONINTERFACE_LOG(Warning, TEXT("Failed to create analog pin"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }
    
	result = ObjectConstructor<UAnalogPin>::create(nativeResult);
	return exception;
}

Antilatency::InterfaceContract::ExceptionCode UHardwareExtensionInterfaceCotask::CreatePulseCounterPin(const EPins& pin, const uint32 refreshIntervalMs, UPulseCounterPin*& result) {
	if (!IsValid()) {
	    HARDWAREEXTENSIONINTERFACE_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
		return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
	}

	Antilatency::HardwareExtensionInterface::IPulseCounterPin nativeResult;
	auto exception = AsInterface<TInterface>().createPulseCounterPin(static_cast<Antilatency::HardwareExtensionInterface::Interop::Pins>(pin), static_cast<uint32_t>(refreshIntervalMs), nativeResult);
	ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    if (nativeResult == nullptr) {
        HARDWAREEXTENSIONINTERFACE_LOG(Warning, TEXT("Failed to create pulse counter pin"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }
    
	result = ObjectConstructor<UPulseCounterPin>::create(nativeResult);
	return exception;
}

Antilatency::InterfaceContract::ExceptionCode UHardwareExtensionInterfaceCotask::CreatePwmPin(const EPins& pin, uint32 frequency, float initialDuty, UPwmPin*& result) {
    if (!IsValid()) {
        HARDWAREEXTENSIONINTERFACE_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    Antilatency::HardwareExtensionInterface::IPwmPin nativeResult;
    auto exception = AsInterface<TInterface>().createPwmPin(static_cast<Antilatency::HardwareExtensionInterface::Interop::Pins>(pin), static_cast<uint32_t>(frequency), initialDuty, nativeResult);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    if (nativeResult == nullptr) {
        HARDWAREEXTENSIONINTERFACE_LOG(Warning, TEXT("Failed to create pwm pin"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    result = ObjectConstructor<UPwmPin>::create(nativeResult);
    return exception;
}

Antilatency::InterfaceContract::ExceptionCode UHardwareExtensionInterfaceCotask::Run() {
    if (!IsValid()) {
        HARDWAREEXTENSIONINTERFACE_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    auto exception = AsInterface<TInterface>().run();
    ANTILATENCY_EXCEPTION_CHECK();

    return exception;
}
