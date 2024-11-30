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

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "HardwareExtensionInterfaceLibrary.h"
#include "HardwareExtensionInterfaceCotaskConstructor.h"
#include "HardwareExtensionInterfaceCotask.h"

#include "HardwareExtensionInterfaceFunctionLibrary.generated.h"

/** An additional enum that is used by the blueprint methods to allow user to check if called method has been executed successfully or not. */
UENUM(BlueprintType)
enum class EHardwareExtensionInterfaceExceptionResult : uint8 {
    /** The method executed successfully. */
    Success = 1 UMETA(DisplayName = "Success"),
    /** The method execution failed with some exception. */
    Fail = 0 UMETA(DisplayName = "Fail"),
};

/**
 * Provides Hardware Extension Interface module's methods wrappers for the UE blueprint system.
 */
UCLASS()
class ANTILATENCYHARDWAREEXTENSIONINTERFACE_API UHardwareExtensionInterfaceFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:

#pragma region UHardwareExtensionInterfaceLibrary
    /**
     * Get the Hardware Extension Interface library object.
     * @param result The Hardware Extension Interface library object.
     * @param exception Method execution result.
     */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|Hardware Extension Interface|Library", Meta = (ExpandEnumAsExecs = "exception"))
    static void GetLibrary(UHardwareExtensionInterfaceLibrary*& result, EHardwareExtensionInterfaceExceptionResult &exception);

    /**
     * Check if UHardwareExtensionInterfaceLibrary has been initialized properly (the UHardwareExtensionInterfaceLibrary is not nullptr and the native Antilatency::HardwareExtensionInterface::ILibrary is not nullptr).
     * @param library A pointer to the UHardwareExtensionInterfaceLibrary object.
     * @return True if object is initialized properly, otherwise false.
     */
    UFUNCTION(BlueprintPure, Category = "Antilatency|Hardware Extension Interface|Library")
    static bool IsLibraryValid(const UHardwareExtensionInterfaceLibrary* library);

    UFUNCTION(BlueprintCallable, Category = "Antilatency|Hardware Extension Interface|Library", Meta = (ExpandEnumAsExecs = "exception"))
    static void GetVersion(UPARAM(ref) UHardwareExtensionInterfaceLibrary* library, FString& result, EHardwareExtensionInterfaceExceptionResult &exception);

    UFUNCTION(BlueprintCallable, Category = "Antilatency|Hardware Extension Interface|Library", Meta = (ExpandEnumAsExecs = "exception"))
    static void GetCotaskConstructor(UPARAM(ref) UHardwareExtensionInterfaceLibrary* library, UHardwareExtensionInterfaceCotaskConstructor*& result, EHardwareExtensionInterfaceExceptionResult &exception);
#pragma endregion 

#pragma region UHardwareExtensionInterfaceCotaskConstructor
    UFUNCTION(BlueprintCallable, Category = "Antilatency|Hardware Extension Interface|Cotask Constructor", Meta = (ExpandEnumAsExecs = "exception"))
    static void StartTask(UPARAM(ref) UHardwareExtensionInterfaceCotaskConstructor* constructor, UDeviceNetwork* network, const FAdnNode& node, UHardwareExtensionInterfaceCotask*& result, EHardwareExtensionInterfaceExceptionResult &exception);
#pragma endregion

#pragma region UHardwareExtensionInterfaceCotask
	UFUNCTION(BlueprintCallable, Category = "Antilatency|Hardware Extension Interface|Cotask", Meta = (ExpandEnumAsExecs = "exception"))
	static void CreateInputPin(UPARAM(ref) UHardwareExtensionInterfaceCotask* cotask, const EPins& pin, UInputPin*& result, EHardwareExtensionInterfaceExceptionResult& exception);

	UFUNCTION(BlueprintCallable, Category = "Antilatency|Hardware Extension Interface|Cotask", Meta = (ExpandEnumAsExecs = "exception"))
	static void CreateOutputPin(UPARAM(ref) UHardwareExtensionInterfaceCotask* cotask, const EPins& pin, const EPinState& initialState, UOutputPin*& result, EHardwareExtensionInterfaceExceptionResult& exception);

	UFUNCTION(BlueprintCallable, Category = "Antilatency|Hardware Extension Interface|Cotask", Meta = (ExpandEnumAsExecs = "exception"))
	static void CreateAnalogPin(UPARAM(ref) UHardwareExtensionInterfaceCotask* cotask, const EPins& pin, const uint8 refreshIntervalMs, UAnalogPin*& result, EHardwareExtensionInterfaceExceptionResult& exception);

	UFUNCTION(BlueprintCallable, Category = "Antilatency|Hardware Extension Interface|Cotask", Meta = (ExpandEnumAsExecs = "exception"))
	static void CreatePulseCounterPin(UPARAM(ref) UHardwareExtensionInterfaceCotask* cotask, const EPins& pin, const uint8 refreshIntervalMs, UPulseCounterPin*& result, EHardwareExtensionInterfaceExceptionResult& exception);

    UFUNCTION(BlueprintCallable, Category = "Antilatency|Hardware Extension Interface|Cotask", Meta = (ExpandEnumAsExecs = "exception"))
    static void CreatePwmPin(UPARAM(ref) UHardwareExtensionInterfaceCotask* cotask, const EPins& pin, int32 frequency, float initialDuty, UPwmPin*& result, EHardwareExtensionInterfaceExceptionResult& exception);
    
	UFUNCTION(BlueprintCallable, Category = "Antilatency|Hardware Extension Interface|Cotask", Meta = (ExpandEnumAsExecs = "exception"))
	static void Run(UHardwareExtensionInterfaceCotask* cotask, EHardwareExtensionInterfaceExceptionResult& exception);
#pragma endregion 

#pragma region UInputPin
	UFUNCTION(BlueprintCallable, Category = "Antilatency|Hardware Extension Interface|Input Pin", Meta = (ExpandEnumAsExecs = "exception"))
	static void GetInputPinState(UPARAM(ref) UInputPin* pin, EPinState& result, EHardwareExtensionInterfaceExceptionResult& exception);

	UFUNCTION(BlueprintPure, Category = "Antilatency|Hardware Extension Interface|Input Pin")
	static bool IsInputPinValid(const UInputPin* pin);
#pragma endregion 

#pragma region UOutputPin
	UFUNCTION(BlueprintCallable, Category = "Antilatency|Hardware Extension Interface|Output Pin", Meta = (ExpandEnumAsExecs = "exception"))
	static void GetOutputPinState(UPARAM(ref) UOutputPin* pin, EPinState& result, EHardwareExtensionInterfaceExceptionResult& exception);

	UFUNCTION(BlueprintCallable, Category = "Antilatency|Hardware Extension Interface|Output Pin", Meta = (ExpandEnumAsExecs = "exception"))
	static void SetOutputPinState(UPARAM(ref) UOutputPin* pin, const EPinState& state, EHardwareExtensionInterfaceExceptionResult& exception);

	UFUNCTION(BlueprintPure, Category = "Antilatency|Hardware Extension Interface|Output Pin")
	static bool IsOutputPinValid(const UOutputPin* pin);
#pragma endregion 

#pragma region UAnalogPin
	UFUNCTION(BlueprintCallable, Category = "Antilatency|Hardware Extension Interface|Analog Pin", Meta = (ExpandEnumAsExecs = "exception"))
	static void GetAnalogPinValue(UPARAM(ref) UAnalogPin* pin, float& result, EHardwareExtensionInterfaceExceptionResult& exception);

	UFUNCTION(BlueprintPure, Category = "Antilatency|Hardware Extension Interface|Analog Pin")
	static bool IsAnalogPinValid(const UAnalogPin* pin);
#pragma endregion 

#pragma region UPulseCounterPin
	UFUNCTION(BlueprintCallable, Category = "Antilatency|Hardware Extension Interface|Pulse Counter Pin", Meta = (ExpandEnumAsExecs = "exception"))
	static void GetPulseCounterPinValue(UPARAM(ref) UPulseCounterPin* pin, uint8& result, EHardwareExtensionInterfaceExceptionResult& exception);

	UFUNCTION(BlueprintPure, Category = "Antilatency|Hardware Extension Interface|Pulse Counter Pin")
	static bool IsPulseCounterPinValid(const UPulseCounterPin* pin);
#pragma endregion

#pragma region UPwmPin
    UFUNCTION(BlueprintCallable, Category = "Antilatency|Hardware Extension Interface|PWM Pin", Meta = (ExpandEnumAsExecs = "exception"))
    static void SetDuty(UPARAM(ref) UPwmPin* pin, float value, EHardwareExtensionInterfaceExceptionResult& exception);

    UFUNCTION(BlueprintCallable, Category = "Antilatency|Hardware Extension Interface|PWM Pin", Meta = (ExpandEnumAsExecs = "exception"))
    static void GetDuty(UPARAM(ref) UPwmPin* pin, float& result, EHardwareExtensionInterfaceExceptionResult& exception);

    UFUNCTION(BlueprintCallable, Category = "Antilatency|Hardware Extension Interface|PWM Pin", Meta = (ExpandEnumAsExecs = "exception"))
    static void GetFrequency(UPARAM(ref) UPwmPin* pin, int32& result, EHardwareExtensionInterfaceExceptionResult& exception);

    UFUNCTION(BlueprintPure, Category = "Antilatency|Hardware Extension Interface|PWM Pin")
    static bool IsPwmPinValid(const UPwmPin* pin, EHardwareExtensionInterfaceExceptionResult& exception);
#pragma endregion

#pragma region Constants
    UFUNCTION(BlueprintPure, Category = "Antilatency|Hardware Extension Interface|Constants")
    static int32 AnalogMinRefreshIntervalMs();

    UFUNCTION(BlueprintPure, Category = "Antilatency|Hardware Extension Interface|Constants")
    static int32 AnalogMaxRefreshIntervalMs();

    UFUNCTION(BlueprintPure, Category = "Antilatency|Hardware Extension Interface|Constants")
    static int32 PulseCounterMinRefreshIntervalMs();

    UFUNCTION(BlueprintPure, Category = "Antilatency|Hardware Extension Interface|Constants")
    static int32 PulseCounterMaxRefreshIntervalMs();
    
    UFUNCTION(BlueprintPure, Category = "Antilatency|Hardware Extension Interface|Constants")
    static int32 PwmMinFrequency();
    
    UFUNCTION(BlueprintPure, Category = "Antilatency|Hardware Extension Interface|Constants")
    static int32 PwmMaxFrequency();

    UFUNCTION(BlueprintPure, Category = "Antilatency|Hardware Extension Interface|Constants")
    static int32 MaxInputPinsCount();

    UFUNCTION(BlueprintPure, Category = "Antilatency|Hardware Extension Interface|Constants")
    static int32 MaxOutputPinsCount();

    UFUNCTION(BlueprintPure, Category = "Antilatency|Hardware Extension Interface|Constants")
    static int32 MaxAnalogPinsCount();

    UFUNCTION(BlueprintPure, Category = "Antilatency|Hardware Extension Interface|Constants")
    static int32 MaxPulseCounterPinsCount();

    UFUNCTION(BlueprintPure, Category = "Antilatency|Hardware Extension Interface|Constants")
    static int32 MaxPwmPinsCount();
#pragma endregion 
};
