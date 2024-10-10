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

#include "PillarsFunctionLibrary.h"
#include "PillarsLog.h"

#include "Math/NumericLimits.h"

void UPillarsFunctionLibrary::GetPillarsLibrary(UPillarsLibrary*& result, EPillarsExceptionResult& exception) {
    result = UPillarsLibrary::GetPillarsLibrary();
    exception = static_cast<EPillarsExceptionResult>(result != nullptr);
}

void UPillarsFunctionLibrary::SerializeEnvironment(UPillarsLibrary* pillarsLibrary, const TArray<FPillarsData>& pillars, UPillarsScheme* scheme, FString& result,
    EPillarsExceptionResult& exception) {
    if (pillarsLibrary == nullptr) {
        exception = EPillarsExceptionResult::Fail;
        return;
    }

    const auto callResult = pillarsLibrary->SerializeEnvironment(pillars, scheme, result);
    exception = static_cast<EPillarsExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UPillarsFunctionLibrary::DeserializeEnvironment(UPillarsLibrary* pillarsLibrary, const FString& environmentData, UDeserializedEnvironment*& result, EPillarsExceptionResult& exception) {
    if (pillarsLibrary == nullptr) {
        exception = EPillarsExceptionResult::Fail;
        return;
    }

    const auto callResult = pillarsLibrary->DeserializeEnvironment(environmentData, result);
    exception = static_cast<EPillarsExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UPillarsFunctionLibrary::GetPillars(UDeserializedEnvironment* deserializedEnvironment, TArray<FPillarsData>& result, EPillarsExceptionResult& exception) {
    if (deserializedEnvironment == nullptr) {
        exception = EPillarsExceptionResult::Fail;
        return;
    }

    const auto callResult = deserializedEnvironment->GetPillars(result);
    exception = static_cast<EPillarsExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

void UPillarsFunctionLibrary::GetScheme(UDeserializedEnvironment* deserializedEnvironment, UPillarsScheme*& result, EPillarsExceptionResult& exception) {
    if (deserializedEnvironment == nullptr) {
        exception = EPillarsExceptionResult::Fail;
        return;
    }

    const auto callResult = deserializedEnvironment->GetScheme(result);
    exception = static_cast<EPillarsExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

bool UPillarsFunctionLibrary::IsValid(const UDeserializedEnvironment* deserializedEnvironment) {
    if (deserializedEnvironment == nullptr) {
        return false;
    }

    return deserializedEnvironment->IsValid();
}

int32 UPillarsFunctionLibrary::GetNumMarkersPerPillar(UPillarsScheme* scheme, EPillarsExceptionResult& exception) {
    if (scheme == nullptr) {
        exception = EPillarsExceptionResult::Fail;
        return 0;
    }
    
    uint32_t result = 0;
    const auto callResult = scheme->GetNumMarkersPerPillar(result);
    exception = static_cast<EPillarsExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);

    if (static_cast<uint32_t>(TNumericLimits<int32>::Max()) < result) {
        PILLARS_LOG(Error, TEXT("UPillarsFunctionLibrary::GetNumMarkersPerPillar: value is out of range of int32"));
        exception = EPillarsExceptionResult::Fail;
        return 0;
    }
    
    return static_cast<int32>(result);
}

void UPillarsFunctionLibrary::SetNumMarkersPerPillar(UPillarsScheme* scheme, int32 numMarkersPerPillar, EPillarsExceptionResult& exception) {
    if (scheme == nullptr) {
        exception = EPillarsExceptionResult::Fail;
        return;
    }

    if (numMarkersPerPillar < 1) {
        PILLARS_LOG(Error, TEXT("UPillarsFunctionLibrary::SetNumMarkersPerPillar: markers count cannot be less than 1"));
        exception = EPillarsExceptionResult::Fail;
        return;
    }

    const auto callResult = scheme->SetNumMarkersPerPillar(static_cast<uint32_t>(numMarkersPerPillar));
    exception = static_cast<EPillarsExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

float UPillarsFunctionLibrary::GetPillarLength(UPillarsScheme* scheme, EPillarsExceptionResult& exception) {
    if (scheme == nullptr) {
        exception = EPillarsExceptionResult::Fail;
        return 0.0f;
    }
    
    float result = 0.0f;
    const auto callResult = scheme->GetPillarLength(result);
    exception = static_cast<EPillarsExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
    return result;
}

void UPillarsFunctionLibrary::SetPillarLength(UPillarsScheme* scheme, float pillarLength, EPillarsExceptionResult& exception) {
    if (scheme == nullptr) {
        exception = EPillarsExceptionResult::Fail;
        return;
    }

    const auto callResult = scheme->SetPillarLength(pillarLength);
    exception = static_cast<EPillarsExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

float UPillarsFunctionLibrary::GetDefaultFovDeg(UPillarsScheme* scheme, EPillarsExceptionResult& exception) {
    if (scheme == nullptr) {
        exception = EPillarsExceptionResult::Fail;
        return 0.0f;
    }

    float result = 0.0f;
    const auto callResult = scheme->GetDefaultFovDeg(result);
    exception = static_cast<EPillarsExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);

    return result;
}

void UPillarsFunctionLibrary::SetDefaultFovDeg(UPillarsScheme* scheme, float defaultFovDeg, EPillarsExceptionResult& exception) {
    if (scheme == nullptr) {
        exception = EPillarsExceptionResult::Fail;
        return;
    }

    const auto callResult = scheme->SetDefaultFovDeg(defaultFovDeg);
    exception = static_cast<EPillarsExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

float UPillarsFunctionLibrary::GetPillarsVerticalOffset(UPillarsScheme* scheme, EPillarsExceptionResult& exception) {
    if (scheme == nullptr) {
        exception = EPillarsExceptionResult::Fail;
        return 0.0f;
    }

    float result = 0.0f;
    const auto callResult = scheme->GetPillarsVerticalOffset(result);
    exception = static_cast<EPillarsExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
    return result;
}

void UPillarsFunctionLibrary::SetPillarsVerticalOffset(UPillarsScheme* scheme, float pillarsVerticalOffset, EPillarsExceptionResult& exception) {
    if (scheme == nullptr) {
        exception = EPillarsExceptionResult::Fail;
        return;
    }

    const auto callResult = scheme->SetPillarsVerticalOffset(pillarsVerticalOffset);
    exception = static_cast<EPillarsExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

bool UPillarsFunctionLibrary::GetStrictMatch(UPillarsScheme* scheme, EPillarsExceptionResult& exception) {
    if (scheme == nullptr) {
        exception = EPillarsExceptionResult::Fail;
        return false;
    }

    bool result = false;
    const auto callResult = scheme->GetStrictMatch(result);
    exception = static_cast<EPillarsExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);

    return result;
}

void UPillarsFunctionLibrary::SetStrictMatch(UPillarsScheme* scheme, bool strictMatch, EPillarsExceptionResult& exception) {
    if (scheme == nullptr) {
        exception = EPillarsExceptionResult::Fail;
        return;
    }

    const auto callResult = scheme->SetStrictMatch(strictMatch);
    exception = static_cast<EPillarsExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

int32 UPillarsFunctionLibrary::GetNumPillarsKinds(UPillarsScheme* scheme, EPillarsExceptionResult& exception) {
    if (scheme == nullptr) {
        exception = EPillarsExceptionResult::Fail;
        return 0;
    }

    uint32_t result;
    const auto callResult = scheme->GetNumPillarsKinds(result);

    if (static_cast<uint32_t>(TNumericLimits<int32>::Max()) < result) {
        PILLARS_LOG(Error, TEXT("UPillarsFunctionLibrary::GetNumPillarsKinds: value is out of range of int32"));
        exception = EPillarsExceptionResult::Fail;
        return 0;
    }
    
    exception = static_cast<EPillarsExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
    
    return static_cast<int32>(result);
}

void UPillarsFunctionLibrary::SetNumPillarsKinds(UPillarsScheme* scheme, int32 numPillarsKinds, EPillarsExceptionResult& exception) {
    if (scheme == nullptr) {
        exception = EPillarsExceptionResult::Fail;
        return;
    }

    if (numPillarsKinds < 1) {
        PILLARS_LOG(Error, TEXT("UPillarsFunctionLibrary::SetNumMarkersPerPillar: markers count cannot be less than 1"));
        exception = EPillarsExceptionResult::Fail;
        return;
    }

    const auto callResult = scheme->SetNumPillarsKinds(numPillarsKinds);
    exception = static_cast<EPillarsExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}

TArray<float> UPillarsFunctionLibrary::GetProportions(UPillarsScheme* scheme, int32 pillarKind, EPillarsExceptionResult& exception) {
    TArray<float> result = {};
    
    if (scheme == nullptr) {
        exception = EPillarsExceptionResult::Fail;
        return result;
    }

    if (pillarKind < 0) {
        PILLARS_LOG(Error, TEXT("UPillarsFunctionLibrary::GetProportions: pillar kind cannot be less than 0"));
        exception = EPillarsExceptionResult::Fail;
        return result;
    }
    
    const auto callResult = scheme->GetProportions(static_cast<uint32_t>(pillarKind), result);
    exception = static_cast<EPillarsExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);

    return result;
}

void UPillarsFunctionLibrary::SetProportions(UPillarsScheme* scheme, TArray<float> proportions, int32 pillarKind, EPillarsExceptionResult& exception) {
    if (scheme == nullptr) {
        exception = EPillarsExceptionResult::Fail;
        return;
    }

    if (pillarKind < 0) {
        PILLARS_LOG(Error, TEXT("UPillarsFunctionLibrary::SetProportions: pillar kind cannot be less than 0"));
        exception = EPillarsExceptionResult::Fail;
        return;
    }

    const auto callResult = scheme->SetProportions(proportions, static_cast<uint32_t>(pillarKind));
    exception = static_cast<EPillarsExceptionResult>(callResult == Antilatency::InterfaceContract::ExceptionCode::Ok);
}






