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

#pragma once

template<class TInterfacedObject>
class ObjectConstructor {
public:
    static TInterfacedObject* create(typename TInterfacedObject::TInterface native) {
        TInterfacedObject* result = NewObject<TInterfacedObject>();
        using TNative = decltype(result->_native);
        using TNativeVMT = typename TNative::VMT;
        result->_native.attach(static_cast<TNativeVMT*>(native.detach()));
        return result;
    }
};