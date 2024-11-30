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

#include "CotaskBatteryPowered.h"
#include "AdnLog.h"

#include <ExceptionCheck.h>

Antilatency::InterfaceContract::ExceptionCode UCotaskBatteryPowered::GetBatteryLevel(float& result) {
    if (!IsValid()) {
        ADN_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }
    
    auto exception = AsInterface<TInterface>().getBatteryLevel(result);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();
    
    return exception;
}
