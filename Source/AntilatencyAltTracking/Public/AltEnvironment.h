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

#include "AltTrackingTypes.h"

#include <Antilatency.Alt.Tracking.h>
#include <ObjectConstructor.h>

#include "AltEnvironment.generated.h"

/**
* Antilatency::Alt::Environment::IEnvironment wrapper for UE.
* Do not instantiate this class directly by calling NewObject<UAltEnvironment> method,
* use UEnvironmentSelectorLibrary::CreateEnvironment or UEnvironmentConstructor::CreateEnvironment instead.
*/
UCLASS(BlueprintType)
class ANTILATENCYALTTRACKING_API UAltEnvironment : public UObject {
    GENERATED_BODY()

public:
    typedef Antilatency::Alt::Environment::IEnvironment TInterface;
    
    template<class TInterfacedObject>
    friend class ObjectConstructor;
    
    /**
     * Get the pointer to the native Antilatency::Alt::Tracking::IEnvironment object.
     * @return The native Antilatency::Alt::Tracking::IEnvironment object.
     */
    TInterface GetNative();

    /**
     * Get environment's markers coordinates.
     * @param result The result array of FVector coordinates that represents environment IR markers positions.
     * @return ExceptionCode::Ok if the method execution is successful, otherwise returns the appropriate error code.
     */
    Antilatency::InterfaceContract::ExceptionCode GetMarkers(TArray<FVector>& result);

    /**
     * Is current environment is mutable (IR markers pattern is not constantly defined).
     * @param result True if environment is mutable, otherwise false.
     * @return ExceptionCode::Ok if the method execution is successful, otherwise returns the appropriate error code.
     */
    Antilatency::InterfaceContract::ExceptionCode IsMutable(bool& result);

    Antilatency::InterfaceContract::ExceptionCode FilterRay(FVector up, FVector ray, bool& result);

    Antilatency::InterfaceContract::ExceptionCode Match(const TArray<FVector>& raysUpSpace, const TArray<uint32>& markersIndices, const FAltPose& poseOfUpSpace, bool& result);

    Antilatency::InterfaceContract::ExceptionCode MatchByPosition(const TArray<FVector>& rays, FVector origin, TArray<uint32>& result);

    /** @return true if the environment has been initialized properly */
    bool IsValid() const;

protected:
    template<class TSpecificInterface>
    TSpecificInterface& AsInterface() {
        return *static_cast<TSpecificInterface*>(&_native);
    }
    
    /** A pointer to the native environment object */
    TInterface _native;
};
