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

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include <Antilatency.DeviceNetwork.h>
#include <ObjectConstructor.h>

#include "Cotask.generated.h"

/**
 * An UE wrapper for the Antilatency::DeviceNetwork::ICotask.
 * Do not instantiate this class directly by calling NewObject<UCotask> method.
 */
UCLASS(BlueprintType)
class ANTILATENCYDEVICENETWORK_API UCotask : public UObject {
    GENERATED_BODY()
    
public:
    typedef Antilatency::DeviceNetwork::ICotask TInterface;
    
    template<class TInterfacedObject>
    friend class ObjectConstructor;

    TInterface GetNative();
    
    /**
     * @brief Check if the task is finished on node.
     * @param result True if task finished, otherwise false.
     * @return ExceptionCode::Ok if the method execution is successful, otherwise returns the appropriate error code.
     */
    Antilatency::InterfaceContract::ExceptionCode IsTaskFinished(bool& result);
    
    /**
     * @brief Stop task. Remember to free the target cotask instance after calling this method because it will be not useful at all after that moment.
     * The node which is used by that task will become free (FNodeStatus::Idle) after calling this method, so you can run another task on it.
     * IMPORTANT: there is no guarantee that this node changes status immediately after calling this method, this may take some time.
     */
    void Stop();

    /**
     * @brief Check if wrapper has valid native object.
     * @return True if "native" object is not null.
     */
    bool IsValid() const;
    
protected:
    template<class TSpecificInterface>
    TSpecificInterface& AsInterface() {
		return *static_cast<TSpecificInterface*>(&_native);
    }
    
    TInterface _native;
};
