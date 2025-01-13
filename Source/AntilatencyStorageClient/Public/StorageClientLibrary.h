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

#include "Storage.h"

#include <Antilatency.StorageClient.h>
#include <ObjectConstructor.h>

#include "StorageClientLibrary.generated.h"

/**
 * Provides methods to work with the Antilatency Storage Client library.
 * Do not instantiate this class directly by calling NewObject<UStorageClientLibrary> method,
 * use UStorageClientLibrary::GetLibrary instead.
 */
UCLASS(BlueprintType)
class ANTILATENCYSTORAGECLIENT_API UStorageClientLibrary : public UObject {
    GENERATED_BODY()

public:
    typedef Antilatency::StorageClient::ILibrary TInterface;
    
    template<class TInterfacedObject>
    friend class ObjectConstructor;
    
    /**
     * Get UStorageClientLibrary instance.
     * @return The UStorageClientLibrary wrapper object. If native Antilatency::StorageClient::ILibrary creation fails, returns nullptr.
     */
    static UStorageClientLibrary* GetLibrary();    

    /**
     * Get the remote storage.
     * @param ipAddress IP address of the remote storage client.
     * @param port Port of the remote storage client.
     * @param result The result storage client wrapper to work with the remote storage.
     * @return ExceptionCode::Ok if the method execution is successful, otherwise returns the appropriate error code.
     */
    Antilatency::InterfaceContract::ExceptionCode GetRemoteStorage(const FString& ipAddress, const uint32 port, UStorage*& result);

    /**
     * Get the local storage client.
     * @param result The result storage client wrapper to work with the local storage.
     * @return ExceptionCode::Ok if the method execution is successful, otherwise returns the appropriate error code.
     */
    Antilatency::InterfaceContract::ExceptionCode GetLocalStorage(UStorage*& result);

    /**
     * Check if UStorageClientLibrary has been initialized properly (the native Antilatency::StorageClient::ILibrary is not nullptr).
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
