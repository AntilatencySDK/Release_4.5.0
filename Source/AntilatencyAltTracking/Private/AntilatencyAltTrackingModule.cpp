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

#include "IAntilatencyAltTrackingModule.h"
#include "Modules/ModuleManager.h"
#include "Misc/Paths.h"
#include "AltTrackingLog.h"

#include <Interfaces/IPluginManager.h>
#include <Antilatency.InterfaceContract.UELibraryLoader.h>

class FAntilatencyAltTrackingModule : public IAntilatencyAltTrackingModule {
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	virtual bool SupportsDynamicReloading() override { return true; }
};

IMPLEMENT_MODULE(FAntilatencyAltTrackingModule, AntilatencyAltTracking)


void FAntilatencyAltTrackingModule::StartupModule() {
	// This code will execute after your module is loaded into memory (but after global variables are initialized, of course.)
}


void FAntilatencyAltTrackingModule::ShutdownModule() {
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

FString IAntilatencyAltTrackingModule::GetPluginName() {
	return TEXT("AntilatencySDK");
}

FString IAntilatencyAltTrackingModule::GetPluginDirectory() {
	return IPluginManager::Get().FindPlugin(GetPluginName())->GetBaseDir();
}

FString IAntilatencyAltTrackingModule::GetPluginBinariesDirectory() {
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

void IAntilatencyAltTrackingModule::PreUnloadCallback() {
    if (_native != nullptr) {
        _native = Antilatency::Alt::Tracking::ILibrary{};
    }
}

Antilatency::Alt::Tracking::ILibrary IAntilatencyAltTrackingModule::GetNativeLibrary() {
    if (_native == nullptr) {
        _native = LoadAntilatencyLibrary<Antilatency::Alt::Tracking::ILibrary>(FString("AntilatencyAltTracking"), IAntilatencyAltTrackingModule::GetPluginBinariesDirectory());
    }

    if (_native == nullptr) {
        ALTTRACKING_LOG(Warning, TEXT("Failed to get Antilatecy Alt Tracking ILibrary"));
    }

    return _native;
}