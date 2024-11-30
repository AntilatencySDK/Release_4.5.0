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

#include "AltEnvironmentRectangleFunctionLibrary.h"

void UAltEnvironmentRectangleFunctionLibrary::GetAltEnvironmentRectangleLibrary(UAltEnvironmentRectangleLibrary*& result, EAltEnvironmentRectangleExceptionResult& exception) {
    result = UAltEnvironmentRectangleLibrary::GetLibrary();
    exception = static_cast<EAltEnvironmentRectangleExceptionResult>(result != nullptr);
}

void UAltEnvironmentRectangleFunctionLibrary::GetRotation(UAltEnvironmentRectangleLibrary* rectangleLibrary, UAltEnvironment* environment, FQuat& result, EAltEnvironmentRectangleExceptionResult& exception) {
    if (rectangleLibrary == nullptr) {
        exception = EAltEnvironmentRectangleExceptionResult::Fail;
        return;
    }

    const auto callResult = rectangleLibrary->GetRotation(environment, result);
    exception = static_cast<EAltEnvironmentRectangleExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}
