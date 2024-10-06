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
#ifndef ANTILATENCY_INTERFACE_CONTRACT_EXCEPTIONS_ENABLED
#define ANTILATENCY_INTERFACE_CONTRACT_EXCEPTIONS_ENABLED
#endif
#include <Antilatency.InterfaceContract.h>
#include <cstdint>
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4946)
#pragma warning(disable: 4265)
#endif
namespace Antilatency {
	/* copy and paste this to implementer
	Antilatency::InterfaceContract::LongBool isDone() {
		throw std::logic_error{"Method IFuture.isDone() is not implemented."};
	}
	void wait() {
		throw std::logic_error{"Method IFuture.wait() is not implemented."};
	}
	*/
	struct IFuture : Antilatency::InterfaceContract::IInterface {
		struct VMT : Antilatency::InterfaceContract::IInterface::VMT {
			virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL isDone(Antilatency::InterfaceContract::LongBool& result) = 0;
			virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL wait() = 0;
			static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
				return Antilatency::InterfaceContract::InterfaceID{0xd405dd81,0xeb71,0x4f4e,{0xb7,0x6a,0x73,0x95,0x9c,0xa7,0xb2,0xb3}};
			}
		private:
			~VMT() = delete;
		};
		
		static bool isInterfaceSupported(const Antilatency::InterfaceContract::InterfaceID& id) {
		    if (id == IFuture::VMT::ID()) {
		        return true;
		    }
		    return Antilatency::InterfaceContract::IInterface::isInterfaceSupported(id);
		}
		IFuture() = default;
		IFuture(std::nullptr_t) {}
		explicit IFuture(VMT* pointer) : Antilatency::InterfaceContract::IInterface(pointer) {}
		template<typename T, typename = typename std::enable_if<std::is_base_of<IFuture, T>::value>::type>
		IFuture& operator = (const T& other) {
		    Antilatency::InterfaceContract::IInterface::operator=(other);
		    return *this;
		}
		template<class Implementer, class ... TArgs>
		static IFuture create(TArgs&&... args) {
		    return *new Implementer(std::forward<TArgs>(args)...);
		}
		void attach(VMT* other) ANTILATENCY_NOEXCEPT {
		    Antilatency::InterfaceContract::IInterface::attach(other);
		}
		VMT* detach() ANTILATENCY_NOEXCEPT {
		    return reinterpret_cast<VMT*>(Antilatency::InterfaceContract::IInterface::detach());
		}
		Antilatency::InterfaceContract::LongBool isDone() {
			Antilatency::InterfaceContract::LongBool result;
			handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->isDone(result));
			return result;
		}
		void wait() {
			handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->wait());
		}
	};
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::IFuture, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::InterfaceContract::IInterface, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL isDone(Antilatency::InterfaceContract::LongBool& result) {
					try {
						result = this->_object->isDone();
					}
					catch (...) {
						return Antilatency::InterfaceContract::handleRemapException(this->_object);
					}
					return Antilatency::InterfaceContract::ExceptionCode::Ok;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL wait() {
					try {
						this->_object->wait();
					}
					catch (...) {
						return Antilatency::InterfaceContract::handleRemapException(this->_object);
					}
					return Antilatency::InterfaceContract::ExceptionCode::Ok;
				}
			};
		} //namespace Details
	} //namespace InterfaceContract
} //namespace Antilatency

namespace Antilatency {
	/* copy and paste this to implementer
	std::string get() {
		throw std::logic_error{"Method IFutureString.get() is not implemented."};
	}
	*/
	struct IFutureString : Antilatency::IFuture {
		struct VMT : Antilatency::IFuture::VMT {
			virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL get(Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) = 0;
			static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
				return Antilatency::InterfaceContract::InterfaceID{0xe8c201d1,0xfadc,0x551c,{0x81,0xcc,0x7e,0xd6,0x46,0xc2,0x29,0x87}};
			}
		private:
			~VMT() = delete;
		};
		
		static bool isInterfaceSupported(const Antilatency::InterfaceContract::InterfaceID& id) {
		    if (id == IFutureString::VMT::ID()) {
		        return true;
		    }
		    return Antilatency::IFuture::isInterfaceSupported(id);
		}
		IFutureString() = default;
		IFutureString(std::nullptr_t) {}
		explicit IFutureString(VMT* pointer) : Antilatency::IFuture(pointer) {}
		template<typename T, typename = typename std::enable_if<std::is_base_of<IFutureString, T>::value>::type>
		IFutureString& operator = (const T& other) {
		    Antilatency::IFuture::operator=(other);
		    return *this;
		}
		template<class Implementer, class ... TArgs>
		static IFutureString create(TArgs&&... args) {
		    return *new Implementer(std::forward<TArgs>(args)...);
		}
		void attach(VMT* other) ANTILATENCY_NOEXCEPT {
		    Antilatency::IFuture::attach(other);
		}
		VMT* detach() ANTILATENCY_NOEXCEPT {
		    return reinterpret_cast<VMT*>(Antilatency::IFuture::detach());
		}
		std::string get() {
			std::string result;
			auto resultMarshaler = Antilatency::InterfaceContract::Details::ArrayOutMarshaler::create(result);
			handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->get(resultMarshaler));
			return result;
		}
	};
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::IFutureString, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::IFuture, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL get(Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) {
					try {
						result = this->_object->get();
					}
					catch (...) {
						return Antilatency::InterfaceContract::handleRemapException(this->_object);
					}
					return Antilatency::InterfaceContract::ExceptionCode::Ok;
				}
			};
		} //namespace Details
	} //namespace InterfaceContract
} //namespace Antilatency

namespace Antilatency {
	/* copy and paste this to implementer
	std::vector<uint8_t> get() {
		throw std::logic_error{"Method IFutureArrayOfByte.get() is not implemented."};
	}
	*/
	struct IFutureArrayOfByte : Antilatency::IFuture {
		struct VMT : Antilatency::IFuture::VMT {
			virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL get(Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) = 0;
			static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
				return Antilatency::InterfaceContract::InterfaceID{0x0825dab8,0x5c73,0x5c8d,{0xa7,0x53,0x82,0x8e,0x4f,0xac,0x84,0x34}};
			}
		private:
			~VMT() = delete;
		};
		
		static bool isInterfaceSupported(const Antilatency::InterfaceContract::InterfaceID& id) {
		    if (id == IFutureArrayOfByte::VMT::ID()) {
		        return true;
		    }
		    return Antilatency::IFuture::isInterfaceSupported(id);
		}
		IFutureArrayOfByte() = default;
		IFutureArrayOfByte(std::nullptr_t) {}
		explicit IFutureArrayOfByte(VMT* pointer) : Antilatency::IFuture(pointer) {}
		template<typename T, typename = typename std::enable_if<std::is_base_of<IFutureArrayOfByte, T>::value>::type>
		IFutureArrayOfByte& operator = (const T& other) {
		    Antilatency::IFuture::operator=(other);
		    return *this;
		}
		template<class Implementer, class ... TArgs>
		static IFutureArrayOfByte create(TArgs&&... args) {
		    return *new Implementer(std::forward<TArgs>(args)...);
		}
		void attach(VMT* other) ANTILATENCY_NOEXCEPT {
		    Antilatency::IFuture::attach(other);
		}
		VMT* detach() ANTILATENCY_NOEXCEPT {
		    return reinterpret_cast<VMT*>(Antilatency::IFuture::detach());
		}
		std::vector<uint8_t> get() {
			std::vector<uint8_t> result;
			auto resultMarshaler = Antilatency::InterfaceContract::Details::ArrayOutMarshaler::create(result);
			handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->get(resultMarshaler));
			return result;
		}
	};
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::IFutureArrayOfByte, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::IFuture, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL get(Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) {
					try {
						result = this->_object->get();
					}
					catch (...) {
						return Antilatency::InterfaceContract::handleRemapException(this->_object);
					}
					return Antilatency::InterfaceContract::ExceptionCode::Ok;
				}
			};
		} //namespace Details
	} //namespace InterfaceContract
} //namespace Antilatency


#ifdef _MSC_VER
#pragma warning(pop)
#endif
