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

#include "IAntilatencyAltEnvironmentSelectorModule.h"
#include "Modules/ModuleManager.h"
#include <Interfaces/IPluginManager.h>
#include "Misc/Paths.h"

#include "EnvironmentSelectorLog.h"
#include <Antilatency.InterfaceContract.UELibraryLoader.h>

class FAntilatencyAltEnvironmentSelectorModule : public IAntilatencyAltEnvironmentSelectorModule {
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	virtual bool SupportsDynamicReloading() override { return true; }
};

IMPLEMENT_MODULE(FAntilatencyAltEnvironmentSelectorModule, AntilatencyAltEnvironmentSelector)


void FAntilatencyAltEnvironmentSelectorModule::StartupModule() {
	// This code will execute after your module is loaded into memory (but after global variables are initialized, of course.)
}


void FAntilatencyAltEnvironmentSelectorModule::ShutdownModule() {
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

FString IAntilatencyAltEnvironmentSelectorModule::GetPluginName() {
	return TEXT("AntilatencySDK");
}

FString IAntilatencyAltEnvironmentSelectorModule::GetPluginDirectory() {
	return IPluginManager::Get().FindPlugin(GetPluginName())->GetBaseDir();
}

FString IAntilatencyAltEnvironmentSelectorModule::GetPluginBinariesDirectory() {
	//return FPaths::Combine(GetPluginDirectory(), TEXT("Binaries"));
	auto pluginDir = GetPluginDirectory();
	auto libDir = FPaths::Combine(*pluginDir, TEXT("ThirdParty"), TEXT("Antilatency"), TEXT("Bin"));

	FString result;
	//TODO: Add linux, mac, etc.
#if PLATFORM_WINDOWS
	#if PLATFORM_64BITS
		result =  FPaths::Combine(*libDir, TEXT("Win64"));
	#else
		result = FPaths::Combine(*libDir, TEXT("Win32"));
	#endif
#else
	result = TEXT("");
#endif
	return result;
}

void IAntilatencyAltEnvironmentSelectorModule::PreUnloadCallback() {
    if (_nativeLibrary != nullptr) {
        _nativeLibrary = Antilatency::Alt::Environment::Selector::ILibrary{};
    }
}

Antilatency::Alt::Environment::Selector::ILibrary IAntilatencyAltEnvironmentSelectorModule::GetNativeLibrary() {
    if (_nativeLibrary == nullptr) {
        _nativeLibrary = LoadAntilatencyLibrary<Antilatency::Alt::Environment::Selector::ILibrary>(FString("AntilatencyAltEnvironmentSelector"), IAntilatencyAltEnvironmentSelectorModule::GetPluginBinariesDirectory());
    }

    if (_nativeLibrary == nullptr) {
        ENVIRONMENTSELECTOR_LOG(Warning, TEXT("Failed to get Antilatecy Alt Environment Selector ILibrary"));
    }

    return _nativeLibrary;
}