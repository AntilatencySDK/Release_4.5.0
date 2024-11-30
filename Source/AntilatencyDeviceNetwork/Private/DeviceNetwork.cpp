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

#include "DeviceNetwork.h"
#include "AdnLog.h"
#include "InterfaceIdUtils.h"

#include <ExceptionCheck.h>
#include <ObjectConstructor.h>

UDeviceNetwork::TInterface UDeviceNetwork::GetNative() {
    return _native;
}

Antilatency::InterfaceContract::ExceptionCode UDeviceNetwork::GetUpdateId(uint32& result) {
    if (!IsValid()) {
        ADN_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    uint32_t updateId;

    auto exception = _native.getUpdateId(updateId);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    result = static_cast<uint32>(updateId);
    return exception;
}

Antilatency::InterfaceContract::ExceptionCode UDeviceNetwork::GetDeviceFilter(UDeviceFilter*& result) {
    if (!IsValid()) {
        ADN_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    Antilatency::DeviceNetwork::IDeviceFilter nativeResult;
    auto exception = _native.getDeviceFilter(nativeResult);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    result = ObjectConstructor<UDeviceFilter>::create(nativeResult);

    return exception;
}

Antilatency::InterfaceContract::ExceptionCode UDeviceNetwork::GetNodes(TArray<FAdnNode>& result) {
    if (!IsValid()) {
        ADN_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    std::vector<Antilatency::DeviceNetwork::NodeHandle> nodes;
    auto exception = _native.getNodes(nodes);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    for (size_t i = 0; i < nodes.size(); ++i) {
        result.Add(FAdnNode(nodes[i]));
    }

    return exception;
}

Antilatency::InterfaceContract::ExceptionCode UDeviceNetwork::NodeGetStatus(const FAdnNode& node, ENodeStatus& result) {
    if (!IsValid()) {
        ADN_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    Antilatency::DeviceNetwork::NodeStatus status;
    auto exception = _native.nodeGetStatus(node.ToNative(), status);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    result = static_cast<ENodeStatus>(status);
    return exception;
}


Antilatency::InterfaceContract::ExceptionCode UDeviceNetwork::NodeIsTaskSupported(const FAdnNode& node, const FGuid& interfaceId, bool& result) {
    if (!IsValid()) {
		ADN_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    const auto nativeId = FGuidToInterfaceID(interfaceId);

    Antilatency::InterfaceContract::LongBool tmp;
    auto exception = _native.nodeIsTaskSupported(node.ToNative(), nativeId, tmp);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    result = tmp;
    return exception;
}

Antilatency::InterfaceContract::ExceptionCode UDeviceNetwork::NodeGetParent(const FAdnNode& node, FAdnNode& result) {
    if (!IsValid()) {
        ADN_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    Antilatency::DeviceNetwork::NodeHandle parent;
    auto exception = _native.nodeGetParent(node.ToNative(), parent);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    result = FAdnNode(parent);
    return exception;
}

Antilatency::InterfaceContract::ExceptionCode UDeviceNetwork::NodeGetPhysicalPath(const FAdnNode& node, FString& result) {
    if (!IsValid()) {
        ADN_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    std::string path;
    auto exception = _native.nodeGetPhysicalPath(node.ToNative(), path);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    result = { path.c_str() };
    return exception;
}

Antilatency::InterfaceContract::ExceptionCode UDeviceNetwork::NodeGetStringProperty(const FAdnNode& node, const FString& key, FString& result) {
    if (!IsValid()) {
        ADN_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    std::string propValue;
    auto exception = _native.nodeGetStringProperty(node.ToNative(), TCHAR_TO_UTF8(*key), propValue);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    result = { propValue.c_str() };
    return exception;
}

Antilatency::InterfaceContract::ExceptionCode UDeviceNetwork::NodeGetBinaryProperty(const FAdnNode& node, const FString& key, TArray<uint8>& result) {
    if (!IsValid()) {
        ADN_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    std::vector<uint8_t> nativeResult;
    auto exception = _native.nodeGetBinaryProperty(node.ToNative(), TCHAR_TO_UTF8(*key), nativeResult);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    result.Reserve(nativeResult.size());
    for(auto prop : nativeResult) {
        result.Add(static_cast<uint8>(prop));
    }
    
    return exception;
}

Antilatency::InterfaceContract::ExceptionCode UDeviceNetwork::NodeStartPropertyTask(const FAdnNode& node, UPropertyCotask*& result) {
    if (!IsValid()) {
        ADN_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    Antilatency::DeviceNetwork::IPropertyCotask nativeResult;
    auto exception = _native.nodeStartPropertyTask(node.ToNative(), nativeResult);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    if (nativeResult == nullptr) {
        ADN_LOG(Warning, TEXT("Failed to start property task on node"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    result = ObjectConstructor<UPropertyCotask>::create(nativeResult);
    
    return exception;
}

bool UDeviceNetwork::IsValid() const {
    if (_native == nullptr) {
        return false;
    }

    return true;
}
