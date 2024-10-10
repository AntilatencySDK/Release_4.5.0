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

#include "IAntilatencyRadioMetricsModule.h"
#include "Modules/ModuleManager.h"
#include <Interfaces/IPluginManager.h>
#include "Misc/Paths.h"

#include "RadioMetricsLog.h"

#include <Antilatency.InterfaceContract.UELibraryLoader.h>

class FAntilatencyRadioMetricsModule : public IAntilatencyRadioMetricsModule {
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	virtual bool SupportsDynamicReloading() override { return true; }
};

IMPLEMENT_MODULE(FAntilatencyRadioMetricsModule, AntilatencyRadioMetrics)

void FAntilatencyRadioMetricsModule::StartupModule() {
	RADIOMETRICS_LOG(Log, TEXT("IAntilatencyRadioMetricsModule: Start"));
	// This code will execute after your module is loaded into memory (but after global variables are initialized, of course.)
}

void FAntilatencyRadioMetricsModule::ShutdownModule() {
	RADIOMETRICS_LOG(Log, TEXT("IAntilatencyRadioMetricsModule: Shutdown"));
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

FString IAntilatencyRadioMetricsModule::GetPluginName() {
	return TEXT("AntilatencySDK");
}

FString IAntilatencyRadioMetricsModule::GetPluginDirectory() {
	return IPluginManager::Get().FindPlugin(GetPluginName())->GetBaseDir();
}

FString IAntilatencyRadioMetricsModule::GetPluginBinariesDirectory() {
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

void IAntilatencyRadioMetricsModule::PreUnloadCallback() {
	if (_library != nullptr) {
        _library = Antilatency::RadioMetrics::ILibrary{};
    }
}

Antilatency::RadioMetrics::ILibrary IAntilatencyRadioMetricsModule::GetNativeLibrary() {
	if (_library == nullptr) {
		_library = LoadAntilatencyLibrary<Antilatency::RadioMetrics::ILibrary>(FString("AntilatencyRadioMetrics"), IAntilatencyRadioMetricsModule::GetPluginBinariesDirectory());
	}

    if (_library == nullptr) {
		RADIOMETRICS_LOG(Warning, TEXT("Failed to get Antilatecy Radio Metrics ILibrary"));
    }

    return _library;
}