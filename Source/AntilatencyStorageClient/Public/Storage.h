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

#include <Antilatency.StorageClient.h>
#include <ObjectConstructor.h>

#include "Storage.generated.h"

/**
 * Provides methods to work with Antilatency Storage, such as
 * reading and writing placements and environments.
 * Do not instantiate this class directly by calling NewObject<UStorage> method,
 * use UStorageClientLibrary::GetRemoteStorage or UStorageClientLibrary::GetLocalStorage instead.
 */
UCLASS(BlueprintType)
class ANTILATENCYSTORAGECLIENT_API UStorage : public UObject {
    GENERATED_BODY()

public:
    typedef Antilatency::StorageClient::IStorage TInterface;
    
    template<class TInterfacedObject>
    friend class ObjectConstructor;

    /**
     * Read the code (serialized value) from the Antilatency Storage.
     * @param group Element group name, "environment" or "placement" values can be used now.
     * @param key Element key - name of the required environment or placement. 
                  You can use "default" value to get the value of element that is marked as default in Antilatency Service,
                  ".default" value will return the name of element that is marked as default in Antilatency Service.
     * @param result The element code, or default element name if the ".default" key has been used.
     * @return ExceptionCode::Ok if the method execution is successful, otherwise returns the appropriate error code.
     */
    Antilatency::InterfaceContract::ExceptionCode Read(const FString& group, const FString& key, FString& result);

    /**
     * Set the code (serialized value) to the Antilatency Storage.
     * @param group Element group name, "environment" or "placement" values can be used now.
     * @param key Element key - name of the required environment or placement.
     * @param data Serialized value to set.
     * @return ExceptionCode::Ok if the method execution is successful, otherwise returns the appropriate error code.
     */
    Antilatency::InterfaceContract::ExceptionCode Write(const FString& group, const FString& key, const FString& data);

    /**
     * Remove element from the Antilatency Storage.
     * @param group Element group name, "environment" or "placement" values can be used now.
     * @param key Element key - name of the required environment or placement.
     * @return ExceptionCode::Ok if the method execution is successful, otherwise returns the appropriate error code.
     */
    Antilatency::InterfaceContract::ExceptionCode Remove(const FString& group, const FString& key);

    /**
     * Get the next element name from the Antilatency Storage.
     * @param group Element group name, "environment" or "placement" values can be used now.
     * @param key Current element name, empty string to get the first element name.
     * @param result The next element name, empty string if the element with provided name is last element in this group.
     * @return ExceptionCode::Ok if the method execution is successful, otherwise returns the appropriate error code.
     */
    Antilatency::InterfaceContract::ExceptionCode Next(const FString& group, const FString& key, FString& result);

    /**
     * @brief Check if storage exists.
     * @param result True if storage exists, otherwise false. 
     * @return ExceptionCode::Ok if the method execution is successful, otherwise returns the appropriate error code.
     */
    Antilatency::InterfaceContract::ExceptionCode Exists(bool& result);

    /**
     * Check if the storage wrapper initialized properly.
     * @return True if the storage wrapper initialized properly, otherwise false.
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
