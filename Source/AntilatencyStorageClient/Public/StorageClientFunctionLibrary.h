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

#include "StorageClientLibrary.h"
#include "Storage.h"

#include "StorageClientFunctionLibrary.generated.h"

 /** An additional enum that is used by the blueprint methods to allow user to check if called method has been executed successfully or not. */
UENUM(BlueprintType)
enum class EStorageClientExceptionResult : uint8 {
    /** The method executed successfully. */
    Success = 1 UMETA(DisplayName = "Success"),
    /** The method execution failed with some exception. */
    Fail = 0 UMETA(DisplayName = "Fail")
};

/**
 * Provides Storage Client module's methods wrappers for the UE blueprint system.
 */
UCLASS()
class ANTILATENCYSTORAGECLIENT_API UStorageClientFunctionLibrary : public UBlueprintFunctionLibrary {
	GENERATED_BODY()

public:

#pragma region UStorageClientLibrary
    /**
     * Get the native storage client library object.
     * @param result The native storage client library object.
     * @param exception Method execution result.
     */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|StorageClient|Library", Meta = (ExpandEnumAsExecs = "exception"))
    static void GetLibrary(UStorageClientLibrary*& result, EStorageClientExceptionResult& exception);

    /**
     * Get the remote storage.
     * @param storageClientLibrary A pointer to the UStorageClientLibrary object.
     * @param ipAddress IP address of the remote storage client.
     * @param port Port of the remote storage client.
     * @param result The result storage client wrapper to work with the remote storage.
     * @param exception Method execution result.
     */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|StorageClient|Library", Meta = (ExpandEnumAsExecs = "exception"))
    static void GetRemoteStorage(UPARAM(ref) UStorageClientLibrary* storageClientLibrary, const FString& ipAddress, int32 port, UStorage*& result, EStorageClientExceptionResult& exception);

    /**
     * Get the local storage client.
     * @param storageClientLibrary A pointer to the UStorageClientLibrary object.
     * @param result The result storage client wrapper to work with the local storage.
     * @param exception Method execution result.
     */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|StorageClient|Library", Meta = (ExpandEnumAsExecs = "exception"))
    static void GetLocalStorage(UPARAM(ref) UStorageClientLibrary* storageClientLibrary, UStorage*& result, EStorageClientExceptionResult& exception);
    
    /**
    * Check if UStorageClientLibrary has been initialized properly (the UStorageClientLibrary is not nullptr and the native Antilatency::StorageClient::ILibrary is not nullptr).
    * @param storageClientLibrary A pointer to the UStorageClientLibrary object.
    * @return True if object is initialized properly, otherwise false.
    */
    UFUNCTION(BlueprintPure, Category = "Antilatency|StorageClient|Library")
    static bool IsLibraryValid(const UStorageClientLibrary* storageClientLibrary);
#pragma endregion

#pragma region UStorage
    /**
     * Read the code (serialized value) from the Antilatency Storage.
     * @param storage A pointer to the UStorage object.
     * @param group Element group name, "environment" or "placement" values can be used now.
     * @param key Element key - name of the required environment or placement.
                  You can use "default" value to get the value of element that is marked as default in Antilatency Service,
                  ".default" value will return the name of element that is marked as default in Antilatency Service.
     * @param result The element code, or default element name if the ".default" key has been used.
     * @param exception Method execution result.
     */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|StorageClient|Storage", Meta = (ExpandEnumAsExecs = "exception"))
    static void Read(UPARAM(ref) UStorage* storage, const FString& group, const FString& key, FString& result, EStorageClientExceptionResult& exception);

    /**
     * Set the code (serialized value) to the Antilatency Storage.
     * @param storage A pointer to the UStorage object.
     * @param group Element group name, "environment" or "placement" values can be used now.
     * @param key Element key - name of the required environment or placement.
     * @param data Serialized value to set.
     * @param exception Method execution result.
     */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|StorageClient|Storage", Meta = (ExpandEnumAsExecs = "exception"))
    static void Write(UPARAM(ref) UStorage* storage, const FString& group, const FString& key, const FString& data, EStorageClientExceptionResult& exception);

    /**
     * Remove element from the Antilatency Storage.
     * @param storage A pointer to the UStorage object.
     * @param group Element group name, "environment" or "placement" values can be used now.
     * @param key Element key - name of the required environment or placement.
     * @param exception Method execution result.
     */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|StorageClient|Storage", Meta = (ExpandEnumAsExecs = "exception"))
    static void Remove(UPARAM(ref) UStorage* storage, const FString& group, const FString& key, EStorageClientExceptionResult& exception);

    /**
     * Get the next element name from the Antilatency Storage.
     * @param storage A pointer to the UStorage object.
     * @param group Element group name, "environment" or "placement" values can be used now.
     * @param key Current element name, empty string to get the first element name.
     * @param result The next element name, empty string if the element with provided name is last element in this group.
     * @param exception Method execution result.
     */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|StorageClient|Storage", Meta = (ExpandEnumAsExecs = "exception"))
    static void Next(UPARAM(ref) UStorage* storage, const FString& group, const FString& key, FString& result, EStorageClientExceptionResult& exception);

    /**
     * @brief Check if storage exists.
     * @param storage A pointer to the UStorage object.
     * @param result True if storage exists, otherwise false.
     * @param exception ExceptionCode::Ok if the method execution is successful, otherwise returns the appropriate error code.
     */
    UFUNCTION(BlueprintCallable, Category = "Antilatency|StorageClient|Storage", Meta = (ExpandEnumAsExecs = "exception"))
    static void Exists(UPARAM(ref) UStorage* storage, bool& result, EStorageClientExceptionResult& exception);

    /**
     * Check if the storage wrapper initialized properly.
     * @param storage A pointer to the UStorage object.
     * @return True if the storage wrapper initialized properly, otherwise false.
     */
    UFUNCTION(BlueprintPure, Category = "Antilatency|StorageClient|Storage")
    static bool IsStorageValid(const UStorage* storage);
#pragma endregion 
};
