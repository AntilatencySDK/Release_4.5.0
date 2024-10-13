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
#include <cstdint>
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4946)
#pragma warning(disable: 4265)
#endif
namespace Antilatency {
	namespace Bracer {
		struct Vibration {
			float intensity;
			float duration;
		};
	} //namespace Bracer
} //namespace Antilatency

namespace Antilatency {
	namespace Bracer {
		/* copy and paste this to implementer
		Antilatency::InterfaceContract::ExceptionCode getTouchChannelsCount(uint32_t& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode getTouchNativeValue(uint32_t channel, uint32_t& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode getTouch(uint32_t channel, float& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode executeVibrationSequence(const std::vector<Antilatency::Bracer::Vibration>& sequence) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		*/
		struct ICotask : Antilatency::DeviceNetwork::ICotaskBatteryPowered {
			struct VMT : Antilatency::DeviceNetwork::ICotaskBatteryPowered::VMT {
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getTouchChannelsCount(uint32_t& result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getTouchNativeValue(uint32_t channel, uint32_t& result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getTouch(uint32_t channel, float& result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL executeVibrationSequence(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate sequence) = 0;
				static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
					return Antilatency::InterfaceContract::InterfaceID{0x36f3603d,0x32d8,0x4f36,{0x9e,0xbd,0xa0,0x6a,0x3f,0x18,0x84,0x66}};
				}
			private:
				~VMT() = delete;
			};
			
			static bool isInterfaceSupported(const Antilatency::InterfaceContract::InterfaceID& id) {
			    if (id == ICotask::VMT::ID()) {
			        return true;
			    }
			    return Antilatency::DeviceNetwork::ICotaskBatteryPowered::isInterfaceSupported(id);
			}
			ICotask() = default;
			ICotask(std::nullptr_t) {}
			explicit ICotask(VMT* pointer) : Antilatency::DeviceNetwork::ICotaskBatteryPowered(pointer) {}
			template<typename T, typename = typename std::enable_if<std::is_base_of<ICotask, T>::value>::type>
			ICotask& operator = (const T& other) {
			    Antilatency::DeviceNetwork::ICotaskBatteryPowered::operator=(other);
			    return *this;
			}
			template<class Implementer, class ... TArgs>
			static ICotask create(TArgs&&... args) {
			    return *new Implementer(std::forward<TArgs>(args)...);
			}
			void attach(VMT* other) ANTILATENCY_NOEXCEPT {
			    Antilatency::DeviceNetwork::ICotaskBatteryPowered::attach(other);
			}
			VMT* detach() ANTILATENCY_NOEXCEPT {
			    return reinterpret_cast<VMT*>(Antilatency::DeviceNetwork::ICotaskBatteryPowered::detach());
			}
			Antilatency::InterfaceContract::ExceptionCode getTouchChannelsCount(uint32_t& result) {
				return (reinterpret_cast<VMT*>(this->_object))->getTouchChannelsCount(result);
			}
			Antilatency::InterfaceContract::ExceptionCode getTouchNativeValue(uint32_t channel, uint32_t& result) {
				return (reinterpret_cast<VMT*>(this->_object))->getTouchNativeValue(channel, result);
			}
			Antilatency::InterfaceContract::ExceptionCode getTouch(uint32_t channel, float& result) {
				return (reinterpret_cast<VMT*>(this->_object))->getTouch(channel, result);
			}
			Antilatency::InterfaceContract::ExceptionCode executeVibrationSequence(const std::vector<Antilatency::Bracer::Vibration>& sequence) {
				auto sequenceMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(sequence);
				return (reinterpret_cast<VMT*>(this->_object))->executeVibrationSequence(sequenceMarshaler);
			}
		};
	} //namespace Bracer
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::Bracer::ICotask, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::DeviceNetwork::ICotaskBatteryPowered, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getTouchChannelsCount(uint32_t& result) {
					auto exceptionCode_ = this->_object->getTouchChannelsCount(result);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getTouchNativeValue(uint32_t channel, uint32_t& result) {
					auto exceptionCode_ = this->_object->getTouchNativeValue(channel, result);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getTouch(uint32_t channel, float& result) {
					auto exceptionCode_ = this->_object->getTouch(channel, result);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL executeVibrationSequence(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate sequence) {
					auto exceptionCode_ = this->_object->executeVibrationSequence(sequence);
					return exceptionCode_;
				}
			};
		} //namespace Details
	} //namespace InterfaceContract
} //namespace Antilatency

namespace Antilatency {
	namespace Bracer {
		/* copy and paste this to implementer
		Antilatency::InterfaceContract::ExceptionCode startTask(Antilatency::DeviceNetwork::INetwork network, Antilatency::DeviceNetwork::NodeHandle node, Antilatency::Bracer::ICotask& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		*/
		struct ICotaskConstructor : Antilatency::DeviceNetwork::ICotaskConstructor {
			struct VMT : Antilatency::DeviceNetwork::ICotaskConstructor::VMT {
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL startTask(Antilatency::DeviceNetwork::INetwork::VMT* network, Antilatency::DeviceNetwork::NodeHandle node, Antilatency::Bracer::ICotask& result) = 0;
				static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
					return Antilatency::InterfaceContract::InterfaceID{0x28ab49e0,0xa878,0x4664,{0xb2,0x6e,0x65,0x43,0xf1,0xe1,0x1f,0x92}};
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
			Antilatency::InterfaceContract::ExceptionCode startTask(Antilatency::DeviceNetwork::INetwork network, Antilatency::DeviceNetwork::NodeHandle node, Antilatency::Bracer::ICotask& result) {
				return (reinterpret_cast<VMT*>(this->_object))->startTask(network.detach(), node, result);
			}
		};
	} //namespace Bracer
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::Bracer::ICotaskConstructor, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::DeviceNetwork::ICotaskConstructor, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL startTask(Antilatency::DeviceNetwork::INetwork::VMT* network, Antilatency::DeviceNetwork::NodeHandle node, Antilatency::Bracer::ICotask& result) {
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
	namespace Bracer {
		/* copy and paste this to implementer
		Antilatency::InterfaceContract::ExceptionCode getVersion(std::string& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode getCotaskConstructor(Antilatency::Bracer::ICotaskConstructor& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		*/
		struct ILibrary : Antilatency::InterfaceContract::IInterface {
			struct VMT : Antilatency::InterfaceContract::IInterface::VMT {
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getVersion(Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getCotaskConstructor(Antilatency::Bracer::ICotaskConstructor& result) = 0;
				static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
					return Antilatency::InterfaceContract::InterfaceID{0x8c3ad766,0x5af7,0x4c13,{0xba,0xa1,0xe9,0x8c,0xbd,0xfa,0x67,0x1e}};
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
			Antilatency::InterfaceContract::ExceptionCode getCotaskConstructor(Antilatency::Bracer::ICotaskConstructor& result) {
				return (reinterpret_cast<VMT*>(this->_object))->getCotaskConstructor(result);
			}
		};
	} //namespace Bracer
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::Bracer::ILibrary, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::InterfaceContract::IInterface, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getVersion(Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) {
					std::string resultMarshaler;
					auto exceptionCode_ = this->_object->getVersion(resultMarshaler);
					result = resultMarshaler;
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getCotaskConstructor(Antilatency::Bracer::ICotaskConstructor& result) {
					auto exceptionCode_ = this->_object->getCotaskConstructor(result);
					return exceptionCode_;
				}
			};
		} //namespace Details
	} //namespace InterfaceContract
} //namespace Antilatency

namespace Antilatency {
	namespace Bracer {
		namespace Constants {
			static constexpr const char* TouchChannelsCountPropertyName = "sys/TouchChannelsCount";
			static constexpr const char* TouchWindowBaseName = "touch/Window";
		} //namespace Constants
	} //namespace Bracer
} //namespace Antilatency


#ifdef _MSC_VER
#pragma warning(pop)
#endif
