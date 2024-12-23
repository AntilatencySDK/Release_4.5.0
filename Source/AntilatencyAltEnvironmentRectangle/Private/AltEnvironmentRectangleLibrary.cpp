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

#include "AltEnvironmentRectangleLibrary.h"
#include "AltEnvironmentRectangleLog.h"

#include <Antilatency.Alt.Environment.h>

#include "IAntilatencyAltEnvironmentRectangleModule.h"

UAltEnvironmentRectangleLibrary* UAltEnvironmentRectangleLibrary::GetLibrary() {
    auto module = IAntilatencyAltEnvironmentRectangleModule::Get();
    auto native = module.GetNativeLibrary();

    if (native == nullptr) {
        return nullptr;
    }

    return ObjectConstructor<UAltEnvironmentRectangleLibrary>::create(native);
}

Antilatency::InterfaceContract::ExceptionCode UAltEnvironmentRectangleLibrary::GetRotation(UAltEnvironment* environment, FQuat& result) {
    if (!IsValid()) {
        ALTENVIRONMENTRECTANGLE_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    if (environment == nullptr || !environment->IsValid()) {
        ALTENVIRONMENTRECTANGLE_LOG(Warning, TEXT("Environment is nullptr or invalid"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    auto orientationAwareInterface = environment->GetNative().queryInterface<Antilatency::Alt::Environment::IOrientationAwareEnvironment>();
    if (orientationAwareInterface == nullptr) {
        return Antilatency::InterfaceContract::ExceptionCode::NoInterface;
    }

    Antilatency::Math::floatQ nativeResult;
    orientationAwareInterface.getRotation(nativeResult);

    result.X = nativeResult.x;
    result.Y = nativeResult.y;
    result.Z = nativeResult.z;
    result.W = nativeResult.w;

    return Antilatency::InterfaceContract::ExceptionCode::Ok;
}
