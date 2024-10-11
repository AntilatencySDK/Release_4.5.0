//Copyright 2022, ALT LLC. All Rights Reserved.
//This file is part of Antilatency SDK.
//It is subject to the license terms in the LICENSE file found in the top-level directory
//of this distribution and at http://www.antilatency.com/eula
//You may not use this file except in compliance with the License.
//Unless required by applicable law or agreed to in writing, software
//distributed under the License is distributed on an "AS IS" BASIS,
//WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//See the License for the specific language governing permissions and
//limitations under the License.
#pragma once
#include <Antilatency.InterfaceContract.h>
#include <cstdint>
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4946)
#pragma warning(disable: 4265)
#endif
namespace Antilatency {
	namespace StorageClient {
		/* copy and paste this to implementer
		Antilatency::InterfaceContract::ExceptionCode read(const std::string& group, const std::string& key, std::string& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode write(const std::string& group, const std::string& key, const std::string& data) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode remove(const std::string& group, const std::string& key) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode next(const std::string& group, const std::string& key, std::string& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode exists(Antilatency::InterfaceContract::LongBool& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		*/
		struct IStorage : Antilatency::InterfaceContract::IInterface {
			struct VMT : Antilatency::InterfaceContract::IInterface::VMT {
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL read(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate group, Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate key, Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL write(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate group, Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate key, Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate data) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL remove(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate group, Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate key) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL next(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate group, Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate key, Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL exists(Antilatency::InterfaceContract::LongBool& result) = 0;
				static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
					return Antilatency::InterfaceContract::InterfaceID{0x792d9d14,0xa2d2,0x42ad,{0xae,0xec,0x7f,0x8a,0x6b,0xa6,0x2b,0xd0}};
				}
			private:
				~VMT() = delete;
			};
			
			static bool isInterfaceSupported(const Antilatency::InterfaceContract::InterfaceID& id) {
			    if (id == IStorage::VMT::ID()) {
			        return true;
			    }
			    return Antilatency::InterfaceContract::IInterface::isInterfaceSupported(id);
			}
			IStorage() = default;
			IStorage(std::nullptr_t) {}
			explicit IStorage(VMT* pointer) : Antilatency::InterfaceContract::IInterface(pointer) {}
			template<typename T, typename = typename std::enable_if<std::is_base_of<IStorage, T>::value>::type>
			IStorage& operator = (const T& other) {
			    Antilatency::InterfaceContract::IInterface::operator=(other);
			    return *this;
			}
			template<class Implementer, class ... TArgs>
			static IStorage create(TArgs&&... args) {
			    return *new Implementer(std::forward<TArgs>(args)...);
			}
			void attach(VMT* other) ANTILATENCY_NOEXCEPT {
			    Antilatency::InterfaceContract::IInterface::attach(other);
			}
			VMT* detach() ANTILATENCY_NOEXCEPT {
			    return reinterpret_cast<VMT*>(Antilatency::InterfaceContract::IInterface::detach());
			}
			Antilatency::InterfaceContract::ExceptionCode read(const std::string& group, const std::string& key, std::string& result) {
				auto groupMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(group);
				auto keyMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(key);
				auto resultMarshaler = Antilatency::InterfaceContract::Details::ArrayOutMarshaler::create(result);
				return (reinterpret_cast<VMT*>(this->_object))->read(groupMarshaler, keyMarshaler, resultMarshaler);
			}
			Antilatency::InterfaceContract::ExceptionCode write(const std::string& group, const std::string& key, const std::string& data) {
				auto groupMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(group);
				auto keyMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(key);
				auto dataMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(data);
				return (reinterpret_cast<VMT*>(this->_object))->write(groupMarshaler, keyMarshaler, dataMarshaler);
			}
			Antilatency::InterfaceContract::ExceptionCode remove(const std::string& group, const std::string& key) {
				auto groupMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(group);
				auto keyMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(key);
				return (reinterpret_cast<VMT*>(this->_object))->remove(groupMarshaler, keyMarshaler);
			}
			Antilatency::InterfaceContract::ExceptionCode next(const std::string& group, const std::string& key, std::string& result) {
				auto groupMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(group);
				auto keyMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(key);
				auto resultMarshaler = Antilatency::InterfaceContract::Details::ArrayOutMarshaler::create(result);
				return (reinterpret_cast<VMT*>(this->_object))->next(groupMarshaler, keyMarshaler, resultMarshaler);
			}
			Antilatency::InterfaceContract::ExceptionCode exists(Antilatency::InterfaceContract::LongBool& result) {
				return (reinterpret_cast<VMT*>(this->_object))->exists(result);
			}
		};
	} //namespace StorageClient
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::StorageClient::IStorage, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::InterfaceContract::IInterface, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL read(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate group, Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate key, Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) {
					std::string resultMarshaler;
					auto exceptionCode_ = this->_object->read(group, key, resultMarshaler);
					result = resultMarshaler;
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL write(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate group, Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate key, Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate data) {
					auto exceptionCode_ = this->_object->write(group, key, data);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL remove(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate group, Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate key) {
					auto exceptionCode_ = this->_object->remove(group, key);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL next(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate group, Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate key, Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) {
					std::string resultMarshaler;
					auto exceptionCode_ = this->_object->next(group, key, resultMarshaler);
					result = resultMarshaler;
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL exists(Antilatency::InterfaceContract::LongBool& result) {
					auto exceptionCode_ = this->_object->exists(result);
					return exceptionCode_;
				}
			};
		} //namespace Details
	} //namespace InterfaceContract
} //namespace Antilatency

namespace Antilatency {
	namespace StorageClient {
		/* copy and paste this to implementer
		Antilatency::InterfaceContract::ExceptionCode getRemoteStorage(const std::string& ipAddress, uint32_t port, Antilatency::StorageClient::IStorage& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode getLocalStorage(Antilatency::StorageClient::IStorage& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		*/
		struct ILibrary : Antilatency::InterfaceContract::IInterface {
			struct VMT : Antilatency::InterfaceContract::IInterface::VMT {
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getRemoteStorage(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate ipAddress, uint32_t port, Antilatency::StorageClient::IStorage& result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getLocalStorage(Antilatency::StorageClient::IStorage& result) = 0;
				static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
					return Antilatency::InterfaceContract::InterfaceID{0x85abab02,0xbe0f,0x4836,{0x9c,0x1c,0x3c,0x73,0x0b,0xbd,0x02,0x51}};
				}
			private:
				~VMT() = delete;
			};
			
			static bool isInterfaceSupported(const Antilatency::InterfaceContract::InterfaceID& id) {
			    if (id == ILibrary::VMT::ID()) {
			        return true;
			    }
			    return Antilatency::InterfaceContract::IInterface::isInterfaceSupported(id);
			}
			ILibrary() = default;
			ILibrary(std::nullptr_t) {}
			explicit ILibrary(VMT* pointer) : Antilatency::InterfaceContract::IInterface(pointer) {}
			template<typename T, typename = typename std::enable_if<std::is_base_of<ILibrary, T>::value>::type>
			ILibrary& operator = (const T& other) {
			    Antilatency::InterfaceContract::IInterface::operator=(other);
			    return *this;
			}
			template<class Implementer, class ... TArgs>
			static ILibrary create(TArgs&&... args) {
			    return *new Implementer(std::forward<TArgs>(args)...);
			}
			void attach(VMT* other) ANTILATENCY_NOEXCEPT {
			    Antilatency::InterfaceContract::IInterface::attach(other);
			}
			VMT* detach() ANTILATENCY_NOEXCEPT {
			    return reinterpret_cast<VMT*>(Antilatency::InterfaceContract::IInterface::detach());
			}
			Antilatency::InterfaceContract::ExceptionCode getRemoteStorage(const std::string& ipAddress, uint32_t port, Antilatency::StorageClient::IStorage& result) {
				auto ipAddressMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(ipAddress);
				return (reinterpret_cast<VMT*>(this->_object))->getRemoteStorage(ipAddressMarshaler, port, result);
			}
			Antilatency::InterfaceContract::ExceptionCode getLocalStorage(Antilatency::StorageClient::IStorage& result) {
				return (reinterpret_cast<VMT*>(this->_object))->getLocalStorage(result);
			}
		};
	} //namespace StorageClient
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::StorageClient::ILibrary, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::InterfaceContract::IInterface, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getRemoteStorage(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate ipAddress, uint32_t port, Antilatency::StorageClient::IStorage& result) {
					auto exceptionCode_ = this->_object->getRemoteStorage(ipAddress, port, result);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getLocalStorage(Antilatency::StorageClient::IStorage& result) {
					auto exceptionCode_ = this->_object->getLocalStorage(result);
					return exceptionCode_;
				}
			};
		} //namespace Details
	} //namespace InterfaceContract
} //namespace Antilatency


#ifdef _MSC_VER
#pragma warning(pop)
#endif
