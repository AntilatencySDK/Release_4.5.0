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

#include "EnvironmentSelectorLibrary.h"
#include "IAntilatencyAltEnvironmentSelectorModule.h"
#include "EnvironmentSelectorLog.h"

#include <AltEnvironment.h>

#include <ExceptionCheck.h>

UEnvironmentSelectorLibrary* UEnvironmentSelectorLibrary::GetLibrary() {
	auto module = IAntilatencyAltEnvironmentSelectorModule::Get();
	auto native = module.GetNativeLibrary();

	if (native == nullptr) {
		return nullptr;
	}

	return ObjectConstructor<UEnvironmentSelectorLibrary>::create(native);
}

bool UEnvironmentSelectorLibrary::IsValid() const {
    return _native != nullptr;
}

Antilatency::InterfaceContract::ExceptionCode UEnvironmentSelectorLibrary::CreateEnvironment(const FString& data, UAltEnvironment*& result) {
	if (!IsValid()) {
	    ENVIRONMENTSELECTOR_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
		return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
	}
	
	Antilatency::Alt::Environment::IEnvironment native;
	auto exception = _native.createEnvironment(std::string(TCHAR_TO_UTF8(*data)), native);
	ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

	result = ObjectConstructor<UAltEnvironment>::create(native);
	return exception;
}


