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

#include <Antilatency.Alt.Environment.Pillars.h>

#include <ObjectConstructor.h>

#include "PillarsScheme.generated.h"

/**
* Antilatency::Alt::Environment::Pillars::IScheme wrapper for UE.
* Do not instantiate this class directly by calling NewObject<UPillarsScheme> method.
 */
UCLASS(BlueprintType)
class UPillarsScheme : public UObject {
	GENERATED_BODY()
public:
	typedef Antilatency::Alt::Environment::Pillars::IScheme TInterface;

	template<class TInterfacedObject>
	friend class ObjectConstructor;

	TInterface GetNative();
	bool IsValid() const;

	Antilatency::InterfaceContract::ExceptionCode GetNumMarkersPerPillar(uint32_t& result);
	Antilatency::InterfaceContract::ExceptionCode SetNumMarkersPerPillar(const uint32_t numMarkersPerPillar);

	Antilatency::InterfaceContract::ExceptionCode GetPillarLength(float& result);
	Antilatency::InterfaceContract::ExceptionCode SetPillarLength(const float pillarLength);

	Antilatency::InterfaceContract::ExceptionCode GetDefaultFovDeg(float& result);
	Antilatency::InterfaceContract::ExceptionCode SetDefaultFovDeg(const float defaultFovDeg);
	
	Antilatency::InterfaceContract::ExceptionCode GetPillarsVerticalOffset(float& result);
	Antilatency::InterfaceContract::ExceptionCode SetPillarsVerticalOffset(const float pillarsVerticalOffset);

	Antilatency::InterfaceContract::ExceptionCode GetStrictMatch(bool& result);
	Antilatency::InterfaceContract::ExceptionCode SetStrictMatch(const bool strictMatch);

	Antilatency::InterfaceContract::ExceptionCode GetNumPillarsKinds(uint32_t& result);
	Antilatency::InterfaceContract::ExceptionCode SetNumPillarsKinds(const uint32_t numPillarsKinds);

	Antilatency::InterfaceContract::ExceptionCode GetProportions(const uint32_t pillarKind, TArray<float>& result);
	Antilatency::InterfaceContract::ExceptionCode SetProportions(const TArray<float>& proportions, const uint32_t pillarKind);
	

protected:
	template<class TSpecificInterface>
	TSpecificInterface& AsInterface() {
		return *static_cast<TSpecificInterface*>(&_native);
	}
    
private:
	TInterface _native;
};
