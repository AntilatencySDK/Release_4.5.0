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
#include <Antilatency.DeviceNetwork.h>
#include <Antilatency.HardwareExtensionInterface.Interop.h>
#include <cstdint>
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4946)
#pragma warning(disable: 4265)
#endif
namespace Antilatency {
	namespace HardwareExtensionInterface {
		/* copy and paste this to implementer
		Antilatency::InterfaceContract::ExceptionCode getState(Antilatency::HardwareExtensionInterface::Interop::PinState& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		*/
		struct IInputPin : Antilatency::InterfaceContract::IInterface {
			struct VMT : Antilatency::InterfaceContract::IInterface::VMT {
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getState(Antilatency::HardwareExtensionInterface::Interop::PinState& result) = 0;
				static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
					return Antilatency::InterfaceContract::InterfaceID{0x39e6527d,0x82db,0x4615,{0xaf,0x8f,0x0f,0xad,0x4c,0x79,0xf1,0x5e}};
				}
			private:
				~VMT() = delete;
			};
			
			static bool isInterfaceSupported(const Antilatency::InterfaceContract::InterfaceID& id) {
			    if (id == IInputPin::VMT::ID()) {
			        return true;
			    }
			    return Antilatency::InterfaceContract::IInterface::isInterfaceSupported(id);
			}
			IInputPin() = default;
			IInputPin(std::nullptr_t) {}
			explicit IInputPin(VMT* pointer) : Antilatency::InterfaceContract::IInterface(pointer) {}
			template<typename T, typename = typename std::enable_if<std::is_base_of<IInputPin, T>::value>::type>
			IInputPin& operator = (const T& other) {
			    Antilatency::InterfaceContract::IInterface::operator=(other);
			    return *this;
			}
			template<class Implementer, class ... TArgs>
			static IInputPin create(TArgs&&... args) {
			    return *new Implementer(std::forward<TArgs>(args)...);
			}
			void attach(VMT* other) ANTILATENCY_NOEXCEPT {
			    Antilatency::InterfaceContract::IInterface::attach(other);
			}
			VMT* detach() ANTILATENCY_NOEXCEPT {
			    return reinterpret_cast<VMT*>(Antilatency::InterfaceContract::IInterface::detach());
			}
			Antilatency::InterfaceContract::ExceptionCode getState(Antilatency::HardwareExtensionInterface::Interop::PinState& result) {
				return (reinterpret_cast<VMT*>(this->_object))->getState(result);
			}
		};
	} //namespace HardwareExtensionInterface
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::HardwareExtensionInterface::IInputPin, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::InterfaceContract::IInterface, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getState(Antilatency::HardwareExtensionInterface::Interop::PinState& result) {
					auto exceptionCode_ = this->_object->getState(result);
					return exceptionCode_;
				}
			};
		} //namespace Details
	} //namespace InterfaceContract
} //namespace Antilatency

namespace Antilatency {
	namespace HardwareExtensionInterface {
		/* copy and paste this to implementer
		Antilatency::InterfaceContract::ExceptionCode setState(Antilatency::HardwareExtensionInterface::Interop::PinState state) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode getState(Antilatency::HardwareExtensionInterface::Interop::PinState& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		*/
		struct IOutputPin : Antilatency::InterfaceContract::IInterface {
			struct VMT : Antilatency::InterfaceContract::IInterface::VMT {
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setState(Antilatency::HardwareExtensionInterface::Interop::PinState state) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getState(Antilatency::HardwareExtensionInterface::Interop::PinState& result) = 0;
				static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
					return Antilatency::InterfaceContract::InterfaceID{0x20d12574,0x3ae9,0x4921,{0x80,0xd3,0x95,0x21,0x7e,0x61,0xf4,0xb2}};
				}
			private:
				~VMT() = delete;
			};
			
			static bool isInterfaceSupported(const Antilatency::InterfaceContract::InterfaceID& id) {
			    if (id == IOutputPin::VMT::ID()) {
			        return true;
			    }
			    return Antilatency::InterfaceContract::IInterface::isInterfaceSupported(id);
			}
			IOutputPin() = default;
			IOutputPin(std::nullptr_t) {}
			explicit IOutputPin(VMT* pointer) : Antilatency::InterfaceContract::IInterface(pointer) {}
			template<typename T, typename = typename std::enable_if<std::is_base_of<IOutputPin, T>::value>::type>
			IOutputPin& operator = (const T& other) {
			    Antilatency::InterfaceContract::IInterface::operator=(other);
			    return *this;
			}
			template<class Implementer, class ... TArgs>
			static IOutputPin create(TArgs&&... args) {
			    return *new Implementer(std::forward<TArgs>(args)...);
			}
			void attach(VMT* other) ANTILATENCY_NOEXCEPT {
			    Antilatency::InterfaceContract::IInterface::attach(other);
			}
			VMT* detach() ANTILATENCY_NOEXCEPT {
			    return reinterpret_cast<VMT*>(Antilatency::InterfaceContract::IInterface::detach());
			}
			Antilatency::InterfaceContract::ExceptionCode setState(Antilatency::HardwareExtensionInterface::Interop::PinState state) {
				return (reinterpret_cast<VMT*>(this->_object))->setState(state);
			}
			Antilatency::InterfaceContract::ExceptionCode getState(Antilatency::HardwareExtensionInterface::Interop::PinState& result) {
				return (reinterpret_cast<VMT*>(this->_object))->getState(result);
			}
		};
	} //namespace HardwareExtensionInterface
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::HardwareExtensionInterface::IOutputPin, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::InterfaceContract::IInterface, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setState(Antilatency::HardwareExtensionInterface::Interop::PinState state) {
					auto exceptionCode_ = this->_object->setState(state);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getState(Antilatency::HardwareExtensionInterface::Interop::PinState& result) {
					auto exceptionCode_ = this->_object->getState(result);
					return exceptionCode_;
				}
			};
		} //namespace Details
	} //namespace InterfaceContract
} //namespace Antilatency

namespace Antilatency {
	namespace HardwareExtensionInterface {
		/* copy and paste this to implementer
		Antilatency::InterfaceContract::ExceptionCode getValue(float& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		*/
		struct IAnalogPin : Antilatency::InterfaceContract::IInterface {
			struct VMT : Antilatency::InterfaceContract::IInterface::VMT {
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getValue(float& result) = 0;
				static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
					return Antilatency::InterfaceContract::InterfaceID{0xe927972f,0x10e5,0x43e2,{0x95,0x02,0x74,0xbc,0xfe,0xd3,0x24,0x82}};
				}
			private:
				~VMT() = delete;
			};
			
			static bool isInterfaceSupported(const Antilatency::InterfaceContract::InterfaceID& id) {
			    if (id == IAnalogPin::VMT::ID()) {
			        return true;
			    }
			    return Antilatency::InterfaceContract::IInterface::isInterfaceSupported(id);
			}
			IAnalogPin() = default;
			IAnalogPin(std::nullptr_t) {}
			explicit IAnalogPin(VMT* pointer) : Antilatency::InterfaceContract::IInterface(pointer) {}
			template<typename T, typename = typename std::enable_if<std::is_base_of<IAnalogPin, T>::value>::type>
			IAnalogPin& operator = (const T& other) {
			    Antilatency::InterfaceContract::IInterface::operator=(other);
			    return *this;
			}
			template<class Implementer, class ... TArgs>
			static IAnalogPin create(TArgs&&... args) {
			    return *new Implementer(std::forward<TArgs>(args)...);
			}
			void attach(VMT* other) ANTILATENCY_NOEXCEPT {
			    Antilatency::InterfaceContract::IInterface::attach(other);
			}
			VMT* detach() ANTILATENCY_NOEXCEPT {
			    return reinterpret_cast<VMT*>(Antilatency::InterfaceContract::IInterface::detach());
			}
			Antilatency::InterfaceContract::ExceptionCode getValue(float& result) {
				return (reinterpret_cast<VMT*>(this->_object))->getValue(result);
			}
		};
	} //namespace HardwareExtensionInterface
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::HardwareExtensionInterface::IAnalogPin, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::InterfaceContract::IInterface, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getValue(float& result) {
					auto exceptionCode_ = this->_object->getValue(result);
					return exceptionCode_;
				}
			};
		} //namespace Details
	} //namespace InterfaceContract
} //namespace Antilatency

namespace Antilatency {
	namespace HardwareExtensionInterface {
		/* copy and paste this to implementer
		Antilatency::InterfaceContract::ExceptionCode getValue(uint16_t& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		*/
		struct IPulseCounterPin : Antilatency::InterfaceContract::IInterface {
			struct VMT : Antilatency::InterfaceContract::IInterface::VMT {
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getValue(uint16_t& result) = 0;
				static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
					return Antilatency::InterfaceContract::InterfaceID{0x8998b746,0x5d17,0x4a47,{0x9c,0x8b,0x01,0xd5,0xa9,0x59,0x53,0x6c}};
				}
			private:
				~VMT() = delete;
			};
			
			static bool isInterfaceSupported(const Antilatency::InterfaceContract::InterfaceID& id) {
			    if (id == IPulseCounterPin::VMT::ID()) {
			        return true;
			    }
			    return Antilatency::InterfaceContract::IInterface::isInterfaceSupported(id);
			}
			IPulseCounterPin() = default;
			IPulseCounterPin(std::nullptr_t) {}
			explicit IPulseCounterPin(VMT* pointer) : Antilatency::InterfaceContract::IInterface(pointer) {}
			template<typename T, typename = typename std::enable_if<std::is_base_of<IPulseCounterPin, T>::value>::type>
			IPulseCounterPin& operator = (const T& other) {
			    Antilatency::InterfaceContract::IInterface::operator=(other);
			    return *this;
			}
			template<class Implementer, class ... TArgs>
			static IPulseCounterPin create(TArgs&&... args) {
			    return *new Implementer(std::forward<TArgs>(args)...);
			}
			void attach(VMT* other) ANTILATENCY_NOEXCEPT {
			    Antilatency::InterfaceContract::IInterface::attach(other);
			}
			VMT* detach() ANTILATENCY_NOEXCEPT {
			    return reinterpret_cast<VMT*>(Antilatency::InterfaceContract::IInterface::detach());
			}
			Antilatency::InterfaceContract::ExceptionCode getValue(uint16_t& result) {
				return (reinterpret_cast<VMT*>(this->_object))->getValue(result);
			}
		};
	} //namespace HardwareExtensionInterface
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::HardwareExtensionInterface::IPulseCounterPin, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::InterfaceContract::IInterface, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getValue(uint16_t& result) {
					auto exceptionCode_ = this->_object->getValue(result);
					return exceptionCode_;
				}
			};
		} //namespace Details
	} //namespace InterfaceContract
} //namespace Antilatency

namespace Antilatency {
	namespace HardwareExtensionInterface {
		/* copy and paste this to implementer
		Antilatency::InterfaceContract::ExceptionCode setDuty(float value) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode getDuty(float& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode getFrequency(uint32_t& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		*/
		struct IPwmPin : Antilatency::InterfaceContract::IInterface {
			struct VMT : Antilatency::InterfaceContract::IInterface::VMT {
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setDuty(float value) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getDuty(float& result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getFrequency(uint32_t& result) = 0;
				static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
					return Antilatency::InterfaceContract::InterfaceID{0x0793b2f5,0x2f6f,0x4a01,{0x8b,0x25,0xf2,0xff,0x98,0x36,0x04,0x41}};
				}
			private:
				~VMT() = delete;
			};
			
			static bool isInterfaceSupported(const Antilatency::InterfaceContract::InterfaceID& id) {
			    if (id == IPwmPin::VMT::ID()) {
			        return true;
			    }
			    return Antilatency::InterfaceContract::IInterface::isInterfaceSupported(id);
			}
			IPwmPin() = default;
			IPwmPin(std::nullptr_t) {}
			explicit IPwmPin(VMT* pointer) : Antilatency::InterfaceContract::IInterface(pointer) {}
			template<typename T, typename = typename std::enable_if<std::is_base_of<IPwmPin, T>::value>::type>
			IPwmPin& operator = (const T& other) {
			    Antilatency::InterfaceContract::IInterface::operator=(other);
			    return *this;
			}
			template<class Implementer, class ... TArgs>
			static IPwmPin create(TArgs&&... args) {
			    return *new Implementer(std::forward<TArgs>(args)...);
			}
			void attach(VMT* other) ANTILATENCY_NOEXCEPT {
			    Antilatency::InterfaceContract::IInterface::attach(other);
			}
			VMT* detach() ANTILATENCY_NOEXCEPT {
			    return reinterpret_cast<VMT*>(Antilatency::InterfaceContract::IInterface::detach());
			}
			Antilatency::InterfaceContract::ExceptionCode setDuty(float value) {
				return (reinterpret_cast<VMT*>(this->_object))->setDuty(value);
			}
			Antilatency::InterfaceContract::ExceptionCode getDuty(float& result) {
				return (reinterpret_cast<VMT*>(this->_object))->getDuty(result);
			}
			Antilatency::InterfaceContract::ExceptionCode getFrequency(uint32_t& result) {
				return (reinterpret_cast<VMT*>(this->_object))->getFrequency(result);
			}
		};
	} //namespace HardwareExtensionInterface
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::HardwareExtensionInterface::IPwmPin, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::InterfaceContract::IInterface, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setDuty(float value) {
					auto exceptionCode_ = this->_object->setDuty(value);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getDuty(float& result) {
					auto exceptionCode_ = this->_object->getDuty(result);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getFrequency(uint32_t& result) {
					auto exceptionCode_ = this->_object->getFrequency(result);
					return exceptionCode_;
				}
			};
		} //namespace Details
	} //namespace InterfaceContract
} //namespace Antilatency

namespace Antilatency {
	namespace HardwareExtensionInterface {
		/* copy and paste this to implementer
		Antilatency::InterfaceContract::ExceptionCode createInputPin(Antilatency::HardwareExtensionInterface::Interop::Pins pin, Antilatency::HardwareExtensionInterface::IInputPin& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode createOutputPin(Antilatency::HardwareExtensionInterface::Interop::Pins pin, Antilatency::HardwareExtensionInterface::Interop::PinState initialState, Antilatency::HardwareExtensionInterface::IOutputPin& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode createAnalogPin(Antilatency::HardwareExtensionInterface::Interop::Pins pin, uint32_t refreshIntervalMs, Antilatency::HardwareExtensionInterface::IAnalogPin& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode createPulseCounterPin(Antilatency::HardwareExtensionInterface::Interop::Pins pin, uint32_t refreshIntervalMs, Antilatency::HardwareExtensionInterface::IPulseCounterPin& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode createPwmPin(Antilatency::HardwareExtensionInterface::Interop::Pins pin, uint32_t frequency, float initialDuty, Antilatency::HardwareExtensionInterface::IPwmPin& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode run() {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		*/
		struct ICotask : Antilatency::DeviceNetwork::ICotask {
			struct VMT : Antilatency::DeviceNetwork::ICotask::VMT {
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL createInputPin(Antilatency::HardwareExtensionInterface::Interop::Pins pin, Antilatency::HardwareExtensionInterface::IInputPin& result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL createOutputPin(Antilatency::HardwareExtensionInterface::Interop::Pins pin, Antilatency::HardwareExtensionInterface::Interop::PinState initialState, Antilatency::HardwareExtensionInterface::IOutputPin& result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL createAnalogPin(Antilatency::HardwareExtensionInterface::Interop::Pins pin, uint32_t refreshIntervalMs, Antilatency::HardwareExtensionInterface::IAnalogPin& result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL createPulseCounterPin(Antilatency::HardwareExtensionInterface::Interop::Pins pin, uint32_t refreshIntervalMs, Antilatency::HardwareExtensionInterface::IPulseCounterPin& result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL createPwmPin(Antilatency::HardwareExtensionInterface::Interop::Pins pin, uint32_t frequency, float initialDuty, Antilatency::HardwareExtensionInterface::IPwmPin& result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL run() = 0;
				static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
					return Antilatency::InterfaceContract::InterfaceID{0xacd1daa9,0x9394,0x4d3a,{0x95,0xce,0x17,0x7a,0x23,0xbd,0x9b,0x89}};
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
			Antilatency::InterfaceContract::ExceptionCode createInputPin(Antilatency::HardwareExtensionInterface::Interop::Pins pin, Antilatency::HardwareExtensionInterface::IInputPin& result) {
				return (reinterpret_cast<VMT*>(this->_object))->createInputPin(pin, result);
			}
			Antilatency::InterfaceContract::ExceptionCode createOutputPin(Antilatency::HardwareExtensionInterface::Interop::Pins pin, Antilatency::HardwareExtensionInterface::Interop::PinState initialState, Antilatency::HardwareExtensionInterface::IOutputPin& result) {
				return (reinterpret_cast<VMT*>(this->_object))->createOutputPin(pin, initialState, result);
			}
			Antilatency::InterfaceContract::ExceptionCode createAnalogPin(Antilatency::HardwareExtensionInterface::Interop::Pins pin, uint32_t refreshIntervalMs, Antilatency::HardwareExtensionInterface::IAnalogPin& result) {
				return (reinterpret_cast<VMT*>(this->_object))->createAnalogPin(pin, refreshIntervalMs, result);
			}
			Antilatency::InterfaceContract::ExceptionCode createPulseCounterPin(Antilatency::HardwareExtensionInterface::Interop::Pins pin, uint32_t refreshIntervalMs, Antilatency::HardwareExtensionInterface::IPulseCounterPin& result) {
				return (reinterpret_cast<VMT*>(this->_object))->createPulseCounterPin(pin, refreshIntervalMs, result);
			}
			Antilatency::InterfaceContract::ExceptionCode createPwmPin(Antilatency::HardwareExtensionInterface::Interop::Pins pin, uint32_t frequency, float initialDuty, Antilatency::HardwareExtensionInterface::IPwmPin& result) {
				return (reinterpret_cast<VMT*>(this->_object))->createPwmPin(pin, frequency, initialDuty, result);
			}
			Antilatency::InterfaceContract::ExceptionCode run() {
				return (reinterpret_cast<VMT*>(this->_object))->run();
			}
		};
	} //namespace HardwareExtensionInterface
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::HardwareExtensionInterface::ICotask, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::DeviceNetwork::ICotask, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL createInputPin(Antilatency::HardwareExtensionInterface::Interop::Pins pin, Antilatency::HardwareExtensionInterface::IInputPin& result) {
					auto exceptionCode_ = this->_object->createInputPin(pin, result);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL createOutputPin(Antilatency::HardwareExtensionInterface::Interop::Pins pin, Antilatency::HardwareExtensionInterface::Interop::PinState initialState, Antilatency::HardwareExtensionInterface::IOutputPin& result) {
					auto exceptionCode_ = this->_object->createOutputPin(pin, initialState, result);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL createAnalogPin(Antilatency::HardwareExtensionInterface::Interop::Pins pin, uint32_t refreshIntervalMs, Antilatency::HardwareExtensionInterface::IAnalogPin& result) {
					auto exceptionCode_ = this->_object->createAnalogPin(pin, refreshIntervalMs, result);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL createPulseCounterPin(Antilatency::HardwareExtensionInterface::Interop::Pins pin, uint32_t refreshIntervalMs, Antilatency::HardwareExtensionInterface::IPulseCounterPin& result) {
					auto exceptionCode_ = this->_object->createPulseCounterPin(pin, refreshIntervalMs, result);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL createPwmPin(Antilatency::HardwareExtensionInterface::Interop::Pins pin, uint32_t frequency, float initialDuty, Antilatency::HardwareExtensionInterface::IPwmPin& result) {
					auto exceptionCode_ = this->_object->createPwmPin(pin, frequency, initialDuty, result);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL run() {
					auto exceptionCode_ = this->_object->run();
					return exceptionCode_;
				}
			};
		} //namespace Details
	} //namespace InterfaceContract
} //namespace Antilatency

namespace Antilatency {
	namespace HardwareExtensionInterface {
		/* copy and paste this to implementer
		Antilatency::InterfaceContract::ExceptionCode startTask(Antilatency::DeviceNetwork::INetwork network, Antilatency::DeviceNetwork::NodeHandle node, Antilatency::HardwareExtensionInterface::ICotask& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		*/
		struct ICotaskConstructor : Antilatency::DeviceNetwork::ICotaskConstructor {
			struct VMT : Antilatency::DeviceNetwork::ICotaskConstructor::VMT {
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL startTask(Antilatency::DeviceNetwork::INetwork::VMT* network, Antilatency::DeviceNetwork::NodeHandle node, Antilatency::HardwareExtensionInterface::ICotask& result) = 0;
				static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
					return Antilatency::InterfaceContract::InterfaceID{0x53b72a7a,0xc61e,0x4946,{0x8a,0x06,0x56,0x4a,0x71,0x71,0xd4,0x77}};
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
			Antilatency::InterfaceContract::ExceptionCode startTask(Antilatency::DeviceNetwork::INetwork network, Antilatency::DeviceNetwork::NodeHandle node, Antilatency::HardwareExtensionInterface::ICotask& result) {
				return (reinterpret_cast<VMT*>(this->_object))->startTask(network.detach(), node, result);
			}
		};
	} //namespace HardwareExtensionInterface
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::HardwareExtensionInterface::ICotaskConstructor, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::DeviceNetwork::ICotaskConstructor, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL startTask(Antilatency::DeviceNetwork::INetwork::VMT* network, Antilatency::DeviceNetwork::NodeHandle node, Antilatency::HardwareExtensionInterface::ICotask& result) {
					Antilatency::DeviceNetwork::INetwork networkMarshaler;
					networkMarshaler.attach(network);
					auto exceptionCode_ = this->_object->startTask(networkMarshaler, node, result);
					return exceptionCode_;
				}
			};
		} //namespace Details
	} //namespace InterfaceContract
} //namespace Antilatency

namespace Antilatency {
	namespace HardwareExtensionInterface {
		/* copy and paste this to implementer
		Antilatency::InterfaceContract::ExceptionCode getVersion(std::string& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode getCotaskConstructor(Antilatency::HardwareExtensionInterface::ICotaskConstructor& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		*/
		struct ILibrary : Antilatency::InterfaceContract::IInterface {
			struct VMT : Antilatency::InterfaceContract::IInterface::VMT {
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getVersion(Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getCotaskConstructor(Antilatency::HardwareExtensionInterface::ICotaskConstructor& result) = 0;
				static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
					return Antilatency::InterfaceContract::InterfaceID{0xef1b555b,0xbbf4,0x4514,{0x82,0x9b,0xb0,0xcd,0x15,0xb6,0xfc,0x8d}};
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
			Antilatency::InterfaceContract::ExceptionCode getVersion(std::string& result) {
				auto resultMarshaler = Antilatency::InterfaceContract::Details::ArrayOutMarshaler::create(result);
				return (reinterpret_cast<VMT*>(this->_object))->getVersion(resultMarshaler);
			}
			Antilatency::InterfaceContract::ExceptionCode getCotaskConstructor(Antilatency::HardwareExtensionInterface::ICotaskConstructor& result) {
				return (reinterpret_cast<VMT*>(this->_object))->getCotaskConstructor(result);
			}
		};
	} //namespace HardwareExtensionInterface
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::HardwareExtensionInterface::ILibrary, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::InterfaceContract::IInterface, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getVersion(Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) {
					std::string resultMarshaler;
					auto exceptionCode_ = this->_object->getVersion(resultMarshaler);
					result = resultMarshaler;
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getCotaskConstructor(Antilatency::HardwareExtensionInterface::ICotaskConstructor& result) {
					auto exceptionCode_ = this->_object->getCotaskConstructor(result);
					return exceptionCode_;
				}
			};
		} //namespace Details
	} //namespace InterfaceContract
} //namespace Antilatency

namespace Antilatency {
	namespace HardwareExtensionInterface {
		namespace Constants {
			constexpr uint32_t AnalogMinRefreshIntervalMs = 1U;
			constexpr uint32_t AnalogMaxRefreshIntervalMs = 65535U;
			constexpr uint32_t PulseCounterMinRefreshIntervalMs = 1U;
			constexpr uint32_t PulseCounterMaxRefreshIntervalMs = 125U;
			constexpr uint32_t PwmMinFrequency = 20U;
			constexpr uint32_t PwmMaxFrequency = 10000U;
		} //namespace Constants
	} //namespace HardwareExtensionInterface
} //namespace Antilatency


#ifdef _MSC_VER
#pragma warning(pop)
#endif
