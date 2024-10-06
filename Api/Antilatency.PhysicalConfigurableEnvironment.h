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
#include <Antilatency.DeviceNetwork.h>
#include <cstdint>
#include <Antilatency.Math.h>
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4946)
#pragma warning(disable: 4265)
#endif
namespace Antilatency {
	namespace PhysicalConfigurableEnvironment {
		/* copy and paste this to implementer
		uint32_t getConfigId() {
			throw std::logic_error{"Method ICotask.getConfigId() is not implemented."};
		}
		void setConfigId(uint32_t configId) {
			throw std::logic_error{"Method ICotask.setConfigId() is not implemented."};
		}
		uint32_t getConfigCount() {
			throw std::logic_error{"Method ICotask.getConfigCount() is not implemented."};
		}
		std::string getEnvironment(uint32_t configId) {
			throw std::logic_error{"Method ICotask.getEnvironment() is not implemented."};
		}
		std::vector<Antilatency::InterfaceContract::LongBool> getMarkersConfig(uint32_t configId) {
			throw std::logic_error{"Method ICotask.getMarkersConfig() is not implemented."};
		}
		Antilatency::Math::float3 getScreenPosition() {
			throw std::logic_error{"Method ICotask.getScreenPosition() is not implemented."};
		}
		Antilatency::Math::float3 getScreenX() {
			throw std::logic_error{"Method ICotask.getScreenX() is not implemented."};
		}
		Antilatency::Math::float3 getScreenY() {
			throw std::logic_error{"Method ICotask.getScreenY() is not implemented."};
		}
		*/
		struct ICotask : Antilatency::DeviceNetwork::ICotask {
			struct VMT : Antilatency::DeviceNetwork::ICotask::VMT {
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getConfigId(uint32_t& result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setConfigId(uint32_t configId) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getConfigCount(uint32_t& result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getEnvironment(uint32_t configId, Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getMarkersConfig(uint32_t configId, Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getScreenPosition(Antilatency::Math::float3& result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getScreenX(Antilatency::Math::float3& result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getScreenY(Antilatency::Math::float3& result) = 0;
				static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
					return Antilatency::InterfaceContract::InterfaceID{0xd470d7b5,0x922a,0x44be,{0x9c,0xbf,0x3d,0xc1,0xd6,0x81,0x51,0x43}};
				}
			private:
				~VMT() = delete;
			};
			
			static bool isInterfaceSupported(const Antilatency::InterfaceContract::InterfaceID& id) {
			    if (id == ICotask::VMT::ID()) {
			        return true;
			    }
			    return Antilatency::DeviceNetwork::ICotask::isInterfaceSupported(id);
			}
			ICotask() = default;
			ICotask(std::nullptr_t) {}
			explicit ICotask(VMT* pointer) : Antilatency::DeviceNetwork::ICotask(pointer) {}
			template<typename T, typename = typename std::enable_if<std::is_base_of<ICotask, T>::value>::type>
			ICotask& operator = (const T& other) {
			    Antilatency::DeviceNetwork::ICotask::operator=(other);
			    return *this;
			}
			template<class Implementer, class ... TArgs>
			static ICotask create(TArgs&&... args) {
			    return *new Implementer(std::forward<TArgs>(args)...);
			}
			void attach(VMT* other) ANTILATENCY_NOEXCEPT {
			    Antilatency::DeviceNetwork::ICotask::attach(other);
			}
			VMT* detach() ANTILATENCY_NOEXCEPT {
			    return reinterpret_cast<VMT*>(Antilatency::DeviceNetwork::ICotask::detach());
			}
			uint32_t getConfigId() {
				uint32_t result;
				handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->getConfigId(result));
				return result;
			}
			void setConfigId(uint32_t configId) {
				handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->setConfigId(configId));
			}
			uint32_t getConfigCount() {
				uint32_t result;
				handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->getConfigCount(result));
				return result;
			}
			std::string getEnvironment(uint32_t configId) {
				std::string result;
				auto resultMarshaler = Antilatency::InterfaceContract::Details::ArrayOutMarshaler::create(result);
				handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->getEnvironment(configId, resultMarshaler));
				return result;
			}
			std::vector<Antilatency::InterfaceContract::LongBool> getMarkersConfig(uint32_t configId) {
				std::vector<Antilatency::InterfaceContract::LongBool> result;
				auto resultMarshaler = Antilatency::InterfaceContract::Details::ArrayOutMarshaler::create(result);
				handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->getMarkersConfig(configId, resultMarshaler));
				return result;
			}
			Antilatency::Math::float3 getScreenPosition() {
				Antilatency::Math::float3 result;
				handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->getScreenPosition(result));
				return result;
			}
			Antilatency::Math::float3 getScreenX() {
				Antilatency::Math::float3 result;
				handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->getScreenX(result));
				return result;
			}
			Antilatency::Math::float3 getScreenY() {
				Antilatency::Math::float3 result;
				handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->getScreenY(result));
				return result;
			}
		};
	} //namespace PhysicalConfigurableEnvironment
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::PhysicalConfigurableEnvironment::ICotask, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::DeviceNetwork::ICotask, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getConfigId(uint32_t& result) {
					try {
						result = this->_object->getConfigId();
					}
					catch (...) {
						return Antilatency::InterfaceContract::handleRemapException(this->_object);
					}
					return Antilatency::InterfaceContract::ExceptionCode::Ok;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setConfigId(uint32_t configId) {
					try {
						this->_object->setConfigId(configId);
					}
					catch (...) {
						return Antilatency::InterfaceContract::handleRemapException(this->_object);
					}
					return Antilatency::InterfaceContract::ExceptionCode::Ok;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getConfigCount(uint32_t& result) {
					try {
						result = this->_object->getConfigCount();
					}
					catch (...) {
						return Antilatency::InterfaceContract::handleRemapException(this->_object);
					}
					return Antilatency::InterfaceContract::ExceptionCode::Ok;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getEnvironment(uint32_t configId, Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) {
					try {
						result = this->_object->getEnvironment(configId);
					}
					catch (...) {
						return Antilatency::InterfaceContract::handleRemapException(this->_object);
					}
					return Antilatency::InterfaceContract::ExceptionCode::Ok;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getMarkersConfig(uint32_t configId, Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) {
					try {
						result = this->_object->getMarkersConfig(configId);
					}
					catch (...) {
						return Antilatency::InterfaceContract::handleRemapException(this->_object);
					}
					return Antilatency::InterfaceContract::ExceptionCode::Ok;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getScreenPosition(Antilatency::Math::float3& result) {
					try {
						result = this->_object->getScreenPosition();
					}
					catch (...) {
						return Antilatency::InterfaceContract::handleRemapException(this->_object);
					}
					return Antilatency::InterfaceContract::ExceptionCode::Ok;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getScreenX(Antilatency::Math::float3& result) {
					try {
						result = this->_object->getScreenX();
					}
					catch (...) {
						return Antilatency::InterfaceContract::handleRemapException(this->_object);
					}
					return Antilatency::InterfaceContract::ExceptionCode::Ok;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getScreenY(Antilatency::Math::float3& result) {
					try {
						result = this->_object->getScreenY();
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
	namespace PhysicalConfigurableEnvironment {
		/* copy and paste this to implementer
		Antilatency::PhysicalConfigurableEnvironment::ICotask startTask(Antilatency::DeviceNetwork::INetwork network, Antilatency::DeviceNetwork::NodeHandle node) {
			throw std::logic_error{"Method ICotaskConstructor.startTask() is not implemented."};
		}
		*/
		struct ICotaskConstructor : Antilatency::DeviceNetwork::ICotaskConstructor {
			struct VMT : Antilatency::DeviceNetwork::ICotaskConstructor::VMT {
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL startTask(Antilatency::DeviceNetwork::INetwork::VMT* network, Antilatency::DeviceNetwork::NodeHandle node, Antilatency::PhysicalConfigurableEnvironment::ICotask& result) = 0;
				static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
					return Antilatency::InterfaceContract::InterfaceID{0x1afbefdf,0x9104,0x4092,{0x84,0x59,0xb4,0x4e,0x24,0x95,0x43,0xa5}};
				}
			private:
				~VMT() = delete;
			};
			
			static bool isInterfaceSupported(const Antilatency::InterfaceContract::InterfaceID& id) {
			    if (id == ICotaskConstructor::VMT::ID()) {
			        return true;
			    }
			    return Antilatency::DeviceNetwork::ICotaskConstructor::isInterfaceSupported(id);
			}
			ICotaskConstructor() = default;
			ICotaskConstructor(std::nullptr_t) {}
			explicit ICotaskConstructor(VMT* pointer) : Antilatency::DeviceNetwork::ICotaskConstructor(pointer) {}
			template<typename T, typename = typename std::enable_if<std::is_base_of<ICotaskConstructor, T>::value>::type>
			ICotaskConstructor& operator = (const T& other) {
			    Antilatency::DeviceNetwork::ICotaskConstructor::operator=(other);
			    return *this;
			}
			template<class Implementer, class ... TArgs>
			static ICotaskConstructor create(TArgs&&... args) {
			    return *new Implementer(std::forward<TArgs>(args)...);
			}
			void attach(VMT* other) ANTILATENCY_NOEXCEPT {
			    Antilatency::DeviceNetwork::ICotaskConstructor::attach(other);
			}
			VMT* detach() ANTILATENCY_NOEXCEPT {
			    return reinterpret_cast<VMT*>(Antilatency::DeviceNetwork::ICotaskConstructor::detach());
			}
			Antilatency::PhysicalConfigurableEnvironment::ICotask startTask(Antilatency::DeviceNetwork::INetwork network, Antilatency::DeviceNetwork::NodeHandle node) {
				Antilatency::PhysicalConfigurableEnvironment::ICotask result;
				handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->startTask(network.detach(), node, result));
				return result;
			}
		};
	} //namespace PhysicalConfigurableEnvironment
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::PhysicalConfigurableEnvironment::ICotaskConstructor, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::DeviceNetwork::ICotaskConstructor, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL startTask(Antilatency::DeviceNetwork::INetwork::VMT* network, Antilatency::DeviceNetwork::NodeHandle node, Antilatency::PhysicalConfigurableEnvironment::ICotask& result) {
					try {
						Antilatency::DeviceNetwork::INetwork networkMarshaler;
						networkMarshaler.attach(network);
						result = this->_object->startTask(networkMarshaler, node);
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
	namespace PhysicalConfigurableEnvironment {
		/* copy and paste this to implementer
		Antilatency::PhysicalConfigurableEnvironment::ICotaskConstructor createCotaskConstructor() {
			throw std::logic_error{"Method ILibrary.createCotaskConstructor() is not implemented."};
		}
		*/
		struct ILibrary : Antilatency::InterfaceContract::IInterface {
			struct VMT : Antilatency::InterfaceContract::IInterface::VMT {
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL createCotaskConstructor(Antilatency::PhysicalConfigurableEnvironment::ICotaskConstructor& result) = 0;
				static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
					return Antilatency::InterfaceContract::InterfaceID{0x95b59518,0xc83f,0x4f9b,{0xbf,0x53,0x5f,0x88,0x54,0x2b,0x32,0x1e}};
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
			Antilatency::PhysicalConfigurableEnvironment::ICotaskConstructor createCotaskConstructor() {
				Antilatency::PhysicalConfigurableEnvironment::ICotaskConstructor result;
				handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->createCotaskConstructor(result));
				return result;
			}
		};
	} //namespace PhysicalConfigurableEnvironment
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::PhysicalConfigurableEnvironment::ILibrary, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::InterfaceContract::IInterface, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL createCotaskConstructor(Antilatency::PhysicalConfigurableEnvironment::ICotaskConstructor& result) {
					try {
						result = this->_object->createCotaskConstructor();
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
