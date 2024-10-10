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

#include "TrackingAlignmentTypes.h"

#include <Antilatency.TrackingAlignment.h>
#include <ObjectConstructor.h>

#include "TrackingAlignment.generated.h"

/**
 * The UE wrapper for the Antilatency::TrackingAlignment::ITrackingAlignment object.
 * Do not instantiate this class directly by calling the NewObject<UTrackingAlignment> method,
 * use the URadioMetricsLibrary::CreateTrackingAlignment instead.
 */
UCLASS(BlueprintType)
class ANTILATENCYTRACKINGALIGNMENT_API UTrackingAlignment : public UObject {
	GENERATED_BODY()

public:
    typedef Antilatency::TrackingAlignment::ITrackingAlignment TInterface;
    
    template<class TInterfacedObject>
    friend class ObjectConstructor;
    
    /**
     * @param a Alt rotation without extrapolation.
	 * @param b Third-party tracker's rotation as is.
	 * @param time Application's time since startup in seconds.
	 * @param result Result Tracking Alignment state.
     * @return ExceptionCode::Ok if the method execution is successful, otherwise returns the appropriate error code.
     */
    Antilatency::InterfaceContract::ExceptionCode Update(const FQuat& a, const FQuat& b, const float time, FTrackingAlignmentState& result);

    /**
     * Check if the cotask wrapper initialized properly.
     * @return True if the cotask wrapper initialized properly, otherwise false.
     */
    bool IsValid() const;

protected:
    template<class TSpecificInterface>
    TSpecificInterface& AsInterface() {
        return *static_cast<TSpecificInterface*>(&_native);
    }

    /** Pointer to native object */
    TInterface _native;
};
