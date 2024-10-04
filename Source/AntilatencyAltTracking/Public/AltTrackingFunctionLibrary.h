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
#include "Kismet/BlueprintFunctionLibrary.h"

#include "AltTrackingLibrary.h"
#include "AltTrackingCotask.h"
#include "AltEnvironment.h"
#include "EnvironmentConstructor.h"
#include "TrackingCotaskConstructor.h"

#include "AltTrackingFunctionLibrary.generated.h"

/** An additional enum that is used by the blueprint methods to allow user to check if called method has been executed successfully or not. */
UENUM(BlueprintType)
enum class EAltTrackingExceptionResult : uint8 {
    /** The method executed successfully. */
    Success = 1 UMETA(DisplayName = "Success"),
    /** The method execution failed with some exception. */
    Fail = 0 UMETA(DisplayName = "Fail"),
};

/**
 * Provides Alt Tracking module's methods wrappers for the UE blueprint system.
 */
UCLASS()
class ANTILATENCYALTTRACKING_API UAltTrackingFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()

public:

#pragma region UAltTrackingLibrary
    /**
     * Get the native tracking library object.
     * @param result The native tracking library object.
     * @param exception Method execution result.
     */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|Alt|Tracking|Library", Meta = (ExpandEnumAsExecs = "exception"))
    static void GetTrackingLibrary(UAltTrackingLibrary*& result, EAltTrackingExceptionResult& exception);

    /** 
     * Create a placement pose from the code.
     * @param altTrackingLibrary A pointer to the UAltTrackingLibrary object.
     * @param code Placement serialized value.
     * @param result Result placement pose.
     * @param exception Method execution result.
     */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|Alt|Tracking|Library", Meta = (ExpandEnumAsExecs = "exception"))
    static void CreatePlacement(UPARAM(ref) UAltTrackingLibrary* altTrackingLibrary, const FString& code, FAltPose& result, EAltTrackingExceptionResult& exception);

    /**
     * Creates placement code from FAltPose.
     * @param altTrackingLibrary A pointer to the UAltTrackingLibrary object.
     * @param placement A source placement pose.
     * @param result The result placement code (pose serialized value).
     * @param exception Method execution result.
     * @param exception Method execution result.
     */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|Alt|Tracking|Library", Meta = (ExpandEnumAsExecs = "exception"))
    static void EncodePlacement(UPARAM(ref) UAltTrackingLibrary* altTrackingLibrary, const FAltPose& placement, FString& result, EAltTrackingExceptionResult& exception);

    UFUNCTION(BlueprintCallable, Category = "Antilatency|Alt|Tracking|Library", Meta = (ExpandEnumAsExecs = "exception"))
    static void CreateTrackingCotaskConstructor(UPARAM(ref) UAltTrackingLibrary* altTrackingLibrary, UTrackingCotaskConstructor*& result, EAltTrackingExceptionResult& exception);

    /**
    * Check if UAltTrackingLibrary has been initialized properly (the UAltTrackingLibrary is not nullptr and the native Antilatency::Alt::Tracking::ILibrary is not nullptr).
    * @param altTrackingLibrary A pointer to the UAltTrackingLibrary object.
    * @return True if object is initialized properly, otherwise false.
    */
    UFUNCTION(BlueprintPure, Category = "Antilatency|Alt|Tracking|Library")
    static bool IsLibraryValid(const UAltTrackingLibrary* altTrackingLibrary);
#pragma endregion

#pragma region UTrackingCotaskConstructor
    /** 
    * Start the tracking task on the node.
    * @param constructor A pointer to the UTrackingCotaskConstructor object.
    * @param network A pointer to the UDeviceNetwork object.
    * @param node A node to start the tracking task on.
    * @param environment A pointer to AAltEnvironment object.
    * @param result A result pointer to the tracking cotask.
    * @param exception Method execution result.
    */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|Alt|Tracking|Cotask Constructor", Meta = (ExpandEnumAsExecs = "exception"))
    static void StartTrackingTask(UPARAM(ref) UTrackingCotaskConstructor* constructor, UPARAM(ref) UDeviceNetwork* network, const FAdnNode& node, UPARAM(ref) UAltEnvironment* environment, UAltTrackingCotask*& result, EAltTrackingExceptionResult& exception);
#pragma endregion

#pragma region UAltTrackingCotask
    /**
     * Get raw tracking state without extrapolation and placement applied.
     * @param trackingCotask A pointer to the UAltTrackingCotask object.
     * @param result Result raw tracking state.
     * @param exception Method execution result.
     */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|Alt|Tracking|Tracking Cotask", Meta = (ExpandEnumAsExecs = "exception"))
    static void GetState(UPARAM(ref) UAltTrackingCotask* trackingCotask, FTrackingState& result, EAltTrackingExceptionResult& exception);

    /**
     * Get tracking state with placement and extrapolation corrections applied.
     * @param trackingCotask A pointer to the UAltTrackingCotask object.
     * @param placement A placement pose that will be used for the tracking pose correction.
     * @param deltaTime An tracking extrapolation time.
     * @param result Result tracking state.
     * @param exception Method execution result.
     */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|Alt|Tracking|Tracking Cotask", Meta = (ExpandEnumAsExecs = "exception"))
    static void GetExtrapolatedState(UPARAM(ref) UAltTrackingCotask* trackingCotask, const FAltPose& placement, const float deltaTime, FTrackingState& result, EAltTrackingExceptionResult& exception);
#pragma endregion 

#pragma region UAltEnvironment
    /**
    * Is current environment is mutable (IR markers pattern is not constantly defined).
    * @param environment A pointer to the environment object.
    * @param result True if environment is mutable, otherwise false.
    * @param exception Method execution result.
    */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|Alt|Environment", Meta = (ExpandEnumAsExecs = "exception"))
    static void IsMutable(UPARAM(ref) UAltEnvironment* environment, bool& result, EAltTrackingExceptionResult& exception);
    
    /** 
     * Get environment's markers coordinates.
     * @param environment A pointer to the environment object.
     * @param result The result array of FVector coordinates that represents environment IR markers positions.
     * @param exception Method execution result.
     */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|Alt|Environment", Meta = (ExpandEnumAsExecs = "exception"))
    static void GetMarkers(UPARAM(ref) UAltEnvironment* environment, TArray<FVector>& result, EAltTrackingExceptionResult& exception);

    UFUNCTION(BlueprintCallable, Category = "Antilatency|Alt|Environment", Meta = (ExpandEnumAsExecs = "exception"))
    static void FilterRay(UPARAM(ref) UAltEnvironment* environment, FVector up, FVector ray, bool& result, EAltTrackingExceptionResult& exception);

    UFUNCTION(BlueprintCallable, Category = "Antilatency|Alt|Environment", Meta = (ExpandEnumAsExecs = "exception"))
    static void Match(UPARAM(ref) UAltEnvironment* environment, const TArray<FVector>& raysUpSpace, const TArray<int32>& markersIndices, const FAltPose& poseOfUpSpace, bool& result, EAltTrackingExceptionResult& exception);

    UFUNCTION(BlueprintCallable, Category = "Antilatency|Alt|Environment", Meta = (ExpandEnumAsExecs = "exception"))
    static void MatchByPosition(UPARAM(ref) UAltEnvironment* environment, const TArray<FVector>& rays, FVector origin, TArray<int32>& result, EAltTrackingExceptionResult& exception);
    
    /** 
     * Check if environment initialized properly.
     * @return true if environment initialized properly, otherwise false.
     */
    UFUNCTION(BlueprintPure, Category = "Antilatency|Alt|Environment")
    static bool IsAltEnvironmentValid(const UAltEnvironment* environment);
#pragma endregion

#pragma region UEnvironmentConstructor
    UFUNCTION(BlueprintCallable, Category = "Antilatency|Alt|Environment|Environment Constructor", Meta = (ExpandEnumAsExecs = "exception"))
    static void CreateEnvironment(UPARAM(ref) UEnvironmentConstructor* constructor, const FString& data, UAltEnvironment*& result, EAltTrackingExceptionResult& exception);

    UFUNCTION(BlueprintPure, Category = "Antilatency|Alt|Environment|Environment Constructor")
    static bool IsValid(const UEnvironmentConstructor* constructor);
#pragma endregion 
};