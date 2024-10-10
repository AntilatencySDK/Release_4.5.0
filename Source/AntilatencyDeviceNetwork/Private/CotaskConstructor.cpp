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

#include "CotaskConstructor.h"
#include "AdnLog.h"

#include <ExceptionCheck.h>


UCotaskConstructor::TInterface UCotaskConstructor::GetNative() {
    return _native;
}

bool UCotaskConstructor::IsValid() const {
    return _native != nullptr;
}

Antilatency::InterfaceContract::ExceptionCode UCotaskConstructor::IsSupported(UDeviceNetwork* network, const FAdnNode& node, bool& result) {
    if (!IsValid()) {
        ADN_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    Antilatency::InterfaceContract::LongBool nativeResult;
    auto exception = _native.isSupported(network->GetNative(), node.ToNative(), nativeResult);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    result = static_cast<bool>(nativeResult);
    return exception;
}

Antilatency::InterfaceContract::ExceptionCode UCotaskConstructor::FindSupportedNodes(UDeviceNetwork* network, TArray<FAdnNode>& result) {
    if (!IsValid()) {
        ADN_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    std::vector<Antilatency::DeviceNetwork::NodeHandle> nativeResult;
    auto exception = _native.findSupportedNodes(network->GetNative(), nativeResult);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    result.Empty();
    result.Reserve(nativeResult.size());
    for (auto node : nativeResult) {
        result.Add(node);
    }
    
    return exception;
}

