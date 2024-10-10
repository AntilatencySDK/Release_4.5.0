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

#include "IAntilatencyAltEnvironmentAdditionalMarkersModule.h"
#include "Modules/ModuleManager.h"
#include <Interfaces/IPluginManager.h>
#include "Misc/Paths.h"

#include "AdditionalMarkersLog.h"

#include <Antilatency.InterfaceContract.UELibraryLoader.h>

class FAntilatencyAltEnvironmentAdditionalMarkersModule : public IAntilatencyAltEnvironmentAdditionalMarkersModule {
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	virtual bool SupportsDynamicReloading() override { return true; }
};

IMPLEMENT_MODULE(FAntilatencyAltEnvironmentAdditionalMarkersModule, AntilatencyAltEnvironmentAdditionalMarkers)


void FAntilatencyAltEnvironmentAdditionalMarkersModule::StartupModule() {
	// This code will execute after your module is loaded into memory (but after global variables are initialized, of course.)
}


void FAntilatencyAltEnvironmentAdditionalMarkersModule::ShutdownModule() {
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

FString IAntilatencyAltEnvironmentAdditionalMarkersModule::GetPluginName() {
	return TEXT("AntilatencySDK");
}

FString IAntilatencyAltEnvironmentAdditionalMarkersModule::GetPluginDirectory() {
	return IPluginManager::Get().FindPlugin(GetPluginName())->GetBaseDir();
}

FString IAntilatencyAltEnvironmentAdditionalMarkersModule::GetPluginBinariesDirectory() {
	//return FPaths::Combine(GetPluginDirectory(), TEXT("Binaries"));
	const auto pluginDir = GetPluginDirectory();
	const auto libDir = FPaths::Combine(*pluginDir, TEXT("ThirdParty"), TEXT("Antilatency"), TEXT("Bin"));

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

void IAntilatencyAltEnvironmentAdditionalMarkersModule::PreUnloadCallback() {
    if (_nativeLibrary != nullptr) {
        _nativeLibrary = Antilatency::Alt::Environment::AdditionalMarkers::ILibrary{};
    }
}

Antilatency::Alt::Environment::AdditionalMarkers::ILibrary IAntilatencyAltEnvironmentAdditionalMarkersModule::GetNativeLibrary() {
    if (_nativeLibrary == nullptr) {
        _nativeLibrary = LoadAntilatencyLibrary<Antilatency::Alt::Environment::AdditionalMarkers::ILibrary>(FString("AntilatencyAltEnvironmentAdditionalMarkers"), IAntilatencyAltEnvironmentAdditionalMarkersModule::GetPluginBinariesDirectory());
    }

    if (_nativeLibrary == nullptr) {
        ADDITIONALMARKERS_LOG(Warning, TEXT("Failed to get Antilatency Alt Environment Additional Markers ILibrary"));
    }

    return _nativeLibrary;
}