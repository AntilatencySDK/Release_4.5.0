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

#include "DeviceNetwork.h"
#include "AltTrackingTypes.h"
#include "TrackingCotaskConstructor.h"

#include <Antilatency.Alt.Tracking.h>
#include <ObjectConstructor.h>

#include "AltTrackingLibrary.generated.h"

/** 
 * Antilatency::Alt::Tracking::ILibrary wrapper for UE.
 * Do not instantiate this class directly by calling NewObject<UAltTrackingLibrary> method,
 * use UAltTrackingLibrary::GetLibrary instead.
 */
UCLASS(BlueprintType)
class ANTILATENCYALTTRACKING_API UAltTrackingLibrary : public UObject {
    GENERATED_BODY()

public:
    typedef Antilatency::Alt::Tracking::ILibrary TInterface;
    
    template<class TInterfacedObject>
    friend class ObjectConstructor;

    static UAltTrackingLibrary* GetLibrary();

    TInterface GetNative();

    /** 
     * Create placement from serialized value.
     * @param code Placement serialized value.
     * @param result Result FAltPose structure. If the code is incorrect, identity pose will be returned.
     * @return ExceptionCode::Ok if the method execution is successful, otherwise returns the appropriate error code.
     */
    Antilatency::InterfaceContract::ExceptionCode CreatePlacement(const FString& code, FAltPose& result);

    /** 
     * Creates a placement serialized value from the FAltPose. 
     * @param placement The placement to get serialized value from.
     * @param result Placement serialized value.
     * @return ExceptionCode::Ok if the method execution is successful, otherwise returns the appropriate error code.
     */
    Antilatency::InterfaceContract::ExceptionCode EncodePlacement(const FAltPose& placement, FString& result);

    Antilatency::InterfaceContract::ExceptionCode CreateTrackingCotaskConstructor(UTrackingCotaskConstructor*& result);

    /**
     * Check if UAltTrackingLibrary has been initialized properly (the UAltTrackingLibrary is not nullptr and the native Alt::Tracking::ILibrary is not nullptr).
     * @return True if object is initialized properly, otherwise false.
     */
    bool IsValid() const;

protected:
    template<class TSpecificInterface>
    TSpecificInterface& AsInterface() {
        return *static_cast<TSpecificInterface*>(&_native);
    }

    /** A pointer to the native tracking library object. */
    TInterface _native;
};
