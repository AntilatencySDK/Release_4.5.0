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

#include "HardwareExtensionInterfaceCotaskConstructor.h"

#include <Antilatency.HardwareExtensionInterface.h>
#include <ObjectConstructor.h>

#include "HardwareExtensionInterfaceLibrary.generated.h"

/** 
 * Provides methods to work with Antilatency Hardware Extension Interface library.
 * Do not instantiate this class directly by calling NewObject<UHardwareExtensionInterfaceLibrary> method,
 * use UHardwareExtensionInterfaceLibrary::GetLibrary instead.
 */
UCLASS(BlueprintType)
class ANTILATENCYHARDWAREEXTENSIONINTERFACE_API UHardwareExtensionInterfaceLibrary : public UObject {
    GENERATED_BODY()

public:
    typedef Antilatency::HardwareExtensionInterface::ILibrary TInterface;
    
    template<class TInterfacedObject>
    friend class ObjectConstructor;
    
    /** @return UHardwareExtensionInterfaceLibrary library object */
    static UHardwareExtensionInterfaceLibrary* GetLibrary();

    /** @return true if library initialized properly */
    bool IsValid() const;

    Antilatency::InterfaceContract::ExceptionCode GetVersion(FString& result);

    Antilatency::InterfaceContract::ExceptionCode GetCotaskConstructor(UHardwareExtensionInterfaceCotaskConstructor*& result);

protected:
    template<class TSpecificInterface>
    TSpecificInterface& AsInterface() {
        return *static_cast<TSpecificInterface*>(&_native);
    }  

    /** Pointer to native object */
    TInterface _native;
};