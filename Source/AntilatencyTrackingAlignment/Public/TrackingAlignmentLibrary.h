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

#include "TrackingAlignment.h"

#include <Antilatency.TrackingAlignment.h>
#include <ObjectConstructor.h>

#include "TrackingAlignmentLibrary.generated.h"

/** 
 * Antilatency::Alt::TrackingAlignment::ILibrary wrapper for UE.
 * Do not instantiate this class directly by calling NewObject<UAltTrackingAlignmentLibrary> method,
 * use UAltTrackingAlignmentLibrary::GetLibrary instead.
 */
UCLASS(BlueprintType)
class ANTILATENCYTRACKINGALIGNMENT_API UTrackingAlignmentLibrary : public UObject {
    GENERATED_BODY()

public:
    typedef Antilatency::TrackingAlignment::ILibrary TInterface;
    
    template<class TInterfacedObject>
    friend class ObjectConstructor;
    
    /** 
     * Get UAltTrackingAlignmentLibrary instance.
     * @return The UAltTrackingAlignmentLibrary wrapper object. If native Antilatency::Alt::TrackingAlignment::ILibrary creation fails, returns nullptr.
     */
    static UTrackingAlignmentLibrary* GetLibrary();

    /** 
     * Run tracking task on node.
     * @param initialARelativeToB
     * @param initialTimeBAheadOfA
     * @param result The wrapper of the Antilatency::Alt::TrackingAlignment::ITrackingAlignment object.
     * @return ExceptionCode::Ok if the method execution is successful, otherwise returns the appropriate error code.
     */
    Antilatency::InterfaceContract::ExceptionCode CreateTrackingAlignment(const FQuat& initialARelativeToB, const float initialTimeBAheadOfA, UTrackingAlignment*& result);

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

    /** Pointer to native object */
    TInterface _native;
};
