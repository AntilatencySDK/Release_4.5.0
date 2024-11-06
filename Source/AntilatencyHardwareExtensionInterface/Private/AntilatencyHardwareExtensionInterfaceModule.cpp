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

#include "IAntilatencyHardwareExtensionInterfaceModule.h"
#include "Modules/ModuleManager.h"
#include <Interfaces/IPluginManager.h>
#include "Misc/Paths.h"

#include "HardwareExtensionInterfaceLog.h"

#include <Antilatency.InterfaceContract.UELibraryLoader.h>

class FAntilatencyHardwareExtensionInterfaceModule : public IAntilatencyHardwareExtensionInterfaceModule {
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	virtual bool SupportsDynamicReloading() override { return true; }
};

IMPLEMENT_MODULE(FAntilatencyHardwareExtensionInterfaceModule, AntilatencyHardwareExtensionInterface)

void FAntilatencyHardwareExtensionInterfaceModule::StartupModule() {
	HARDWAREEXTENSIONINTERFACE_LOG(Log, TEXT("IAntilatencyHardwareExtensionInterfaceModule: Start"));
	// This code will execute after your module is loaded into memory (but after global variables are initialized, of course.)
}

void FAntilatencyHardwareExtensionInterfaceModule::ShutdownModule() {
	HARDWAREEXTENSIONINTERFACE_LOG(Log, TEXT("IAntilatencyHardwareExtensionInterfaceModule: Shutdown"));
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

FString IAntilatencyHardwareExtensionInterfaceModule::GetPluginName() {
	return TEXT("AntilatencySDK");
}

FString IAntilatencyHardwareExtensionInterfaceModule::GetPluginDirectory() {
	return IPluginManager::Get().FindPlugin(GetPluginName())->GetBaseDir();
}

FString IAntilatencyHardwareExtensionInterfaceModule::GetPluginBinariesDirectory() {
    const auto pluginDir = GetPluginDirectory();
    const auto libDir = FPaths::Combine(*pluginDir, TEXT("ThirdParty"), TEXT("Antilatency"), TEXT("Bin"));

	FString result;
#if PLATFORM_WINDOWS
#if PLATFORM_64BITS
    result = FPaths::Combine(*libDir, TEXT("Win64"));
#else
    result = FPaths::Combine(*libDir, TEXT("Win32"));
#endif
#else
	result = TEXT("");
#endif
	return result;
}

void IAntilatencyHardwareExtensionInterfaceModule::PreUnloadCallback() {
	if (_library != nullptr) {
        _library = Antilatency::HardwareExtensionInterface::ILibrary{};
    }
}

Antilatency::HardwareExtensionInterface::ILibrary IAntilatencyHardwareExtensionInterfaceModule::GetNativeLibrary() {
	if (_library == nullptr) {
		_library = LoadAntilatencyLibrary<Antilatency::HardwareExtensionInterface::ILibrary>(FString("AntilatencyHardwareExtensionInterface"), IAntilatencyHardwareExtensionInterfaceModule::GetPluginBinariesDirectory());
	}

    if (_library == nullptr) {
		HARDWAREEXTENSIONINTERFACE_LOG(Warning, TEXT("Failed to get Antilatecy Hardware Extension Interface ILibrary"));
    }

    return _library;
}