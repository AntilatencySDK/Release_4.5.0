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
#include <Antilatency.PulseWave.h>
#include <Antilatency.DeviceNetwork.Tasks.Illumetry.Display.h>
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4946)
#pragma warning(disable: 4265)
#endif
namespace Illumetry {
	namespace Display {
		/* copy and paste this to implementer
		void setFrameScheduleReceiver(Antilatency::PulseWave::IPulseWaveReceiver pulseWaveReceiver) {
			throw std::logic_error{"Method ICotask.setFrameScheduleReceiver() is not implemented."};
		}
		Antilatency::PulseWave::Description getFrameSchedule() {
			throw std::logic_error{"Method ICotask.getFrameSchedule() is not implemented."};
		}
		Antilatency::DeviceNetwork::Tasks::Illumetry::Display::PowerState getPowerState() {
			throw std::logic_error{"Method ICotask.getPowerState() is not implemented."};
		}
		*/
		struct ICotask : Antilatency::DeviceNetwork::ICotask {
			struct VMT : Antilatency::DeviceNetwork::ICotask::VMT {
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setFrameScheduleReceiver(Antilatency::PulseWave::IPulseWaveReceiver::VMT* pulseWaveReceiver) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getFrameSchedule(Antilatency::PulseWave::Description& result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getPowerState(Antilatency::DeviceNetwork::Tasks::Illumetry::Display::PowerState& result) = 0;
				static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
					return Antilatency::InterfaceContract::InterfaceID{0x89f325cc,0xcc61,0x42fa,{0x80,0x86,0xd4,0x1e,0xc3,0xaf,0x44,0xc0}};
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
			void setFrameScheduleReceiver(Antilatency::PulseWave::IPulseWaveReceiver pulseWaveReceiver) {
				handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->setFrameScheduleReceiver(pulseWaveReceiver.detach()));
			}
			Antilatency::PulseWave::Description getFrameSchedule() {
				Antilatency::PulseWave::Description result;
				handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->getFrameSchedule(result));
				return result;
			}
			Antilatency::DeviceNetwork::Tasks::Illumetry::Display::PowerState getPowerState() {
				Antilatency::DeviceNetwork::Tasks::Illumetry::Display::PowerState result;
				handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->getPowerState(result));
				return result;
			}
		};
	} //namespace Display
} //namespace Illumetry
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Illumetry::Display::ICotask, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::DeviceNetwork::ICotask, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setFrameScheduleReceiver(Antilatency::PulseWave::IPulseWaveReceiver::VMT* pulseWaveReceiver) {
					try {
						Antilatency::PulseWave::IPulseWaveReceiver pulseWaveReceiverMarshaler;
						pulseWaveReceiverMarshaler.attach(pulseWaveReceiver);
						this->_object->setFrameScheduleReceiver(pulseWaveReceiverMarshaler);
					}
					catch (...) {
						return Antilatency::InterfaceContract::handleRemapException(this->_object);
					}
					return Antilatency::InterfaceContract::ExceptionCode::Ok;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getFrameSchedule(Antilatency::PulseWave::Description& result) {
					try {
						result = this->_object->getFrameSchedule();
					}
					catch (...) {
						return Antilatency::InterfaceContract::handleRemapException(this->_object);
					}
					return Antilatency::InterfaceContract::ExceptionCode::Ok;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getPowerState(Antilatency::DeviceNetwork::Tasks::Illumetry::Display::PowerState& result) {
					try {
						result = this->_object->getPowerState();
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

namespace Illumetry {
	namespace Display {
		/* copy and paste this to implementer
		Illumetry::Display::ICotask startTask(Antilatency::DeviceNetwork::INetwork network, Antilatency::DeviceNetwork::NodeHandle node) {
			throw std::logic_error{"Method ICotaskConstructor.startTask() is not implemented."};
		}
		*/
		struct ICotaskConstructor : Antilatency::DeviceNetwork::ICotaskConstructor {
			struct VMT : Antilatency::DeviceNetwork::ICotaskConstructor::VMT {
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL startTask(Antilatency::DeviceNetwork::INetwork::VMT* network, Antilatency::DeviceNetwork::NodeHandle node, Illumetry::Display::ICotask& result) = 0;
				static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
					return Antilatency::InterfaceContract::InterfaceID{0x47bf48da,0x1b39,0x434d,{0x85,0x83,0x89,0xd3,0x7b,0x82,0x9d,0x7a}};
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
			Illumetry::Display::ICotask startTask(Antilatency::DeviceNetwork::INetwork network, Antilatency::DeviceNetwork::NodeHandle node) {
				Illumetry::Display::ICotask result;
				handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->startTask(network.detach(), node, result));
				return result;
			}
		};
	} //namespace Display
} //namespace Illumetry
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Illumetry::Display::ICotaskConstructor, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::DeviceNetwork::ICotaskConstructor, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL startTask(Antilatency::DeviceNetwork::INetwork::VMT* network, Antilatency::DeviceNetwork::NodeHandle node, Illumetry::Display::ICotask& result) {
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

namespace Illumetry {
	namespace Display {
		/* copy and paste this to implementer
		std::string getVersion() {
			throw std::logic_error{"Method ILibrary.getVersion() is not implemented."};
		}
		Illumetry::Display::ICotaskConstructor getCotaskConstructor() {
			throw std::logic_error{"Method ILibrary.getCotaskConstructor() is not implemented."};
		}
		*/
		struct ILibrary : Antilatency::InterfaceContract::IInterface {
			struct VMT : Antilatency::InterfaceContract::IInterface::VMT {
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getVersion(Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getCotaskConstructor(Illumetry::Display::ICotaskConstructor& result) = 0;
				static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
					return Antilatency::InterfaceContract::InterfaceID{0xbb93c48c,0x2d96,0x42c4,{0xa5,0xff,0x14,0x43,0x95,0x19,0x9f,0x05}};
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
			std::string getVersion() {
				std::string result;
				auto resultMarshaler = Antilatency::InterfaceContract::Details::ArrayOutMarshaler::create(result);
				handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->getVersion(resultMarshaler));
				return result;
			}
			Illumetry::Display::ICotaskConstructor getCotaskConstructor() {
				Illumetry::Display::ICotaskConstructor result;
				handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->getCotaskConstructor(result));
				return result;
			}
		};
	} //namespace Display
} //namespace Illumetry
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Illumetry::Display::ILibrary, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::InterfaceContract::IInterface, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getVersion(Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) {
					try {
						result = this->_object->getVersion();
					}
					catch (...) {
						return Antilatency::InterfaceContract::handleRemapException(this->_object);
					}
					return Antilatency::InterfaceContract::ExceptionCode::Ok;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getCotaskConstructor(Illumetry::Display::ICotaskConstructor& result) {
					try {
						result = this->_object->getCotaskConstructor();
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

namespace Illumetry {
	namespace Display {
		namespace Constants {
			static constexpr const char* ResolutionPropertyName = "sys/Resolution";
			static constexpr const char* BlankPropertyName = "sys/Blank";
			static constexpr const char* FpsPropertyName = "sys/Fps";
			static constexpr const char* StrobeOffsetPropertyName = "sys/StrobeOffset";
			static constexpr const char* StrobeDurationPropertyName = "sys/StrobeDuration";
		} //namespace Constants
	} //namespace Display
} //namespace Illumetry


#ifdef _MSC_VER
#pragma warning(pop)
#endif
