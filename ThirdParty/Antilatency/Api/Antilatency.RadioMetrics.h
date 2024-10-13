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
#include <Antilatency.RadioMetrics.Interop.h>
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4946)
#pragma warning(disable: 4265)
#endif
namespace Antilatency {
	namespace RadioMetrics {
		struct Metrics {
			int8_t averageRssi;
			float packetLossRate;
		};
	} //namespace RadioMetrics
} //namespace Antilatency

namespace Antilatency {
	namespace RadioMetrics {
		/* copy and paste this to implementer
		Antilatency::InterfaceContract::ExceptionCode getMetrics(Antilatency::DeviceNetwork::NodeHandle targetNode, Antilatency::RadioMetrics::Metrics& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode getExtendedMetrics(Antilatency::DeviceNetwork::NodeHandle targetNode, Antilatency::RadioMetrics::Interop::ExtendedMetrics& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		*/
		struct ICotask : Antilatency::DeviceNetwork::ICotask {
			struct VMT : Antilatency::DeviceNetwork::ICotask::VMT {
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getMetrics(Antilatency::DeviceNetwork::NodeHandle targetNode, Antilatency::RadioMetrics::Metrics& result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getExtendedMetrics(Antilatency::DeviceNetwork::NodeHandle targetNode, Antilatency::RadioMetrics::Interop::ExtendedMetrics& result) = 0;
				static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
					return Antilatency::InterfaceContract::InterfaceID{0xa7d915ca,0x0fa2,0x409a,{0xba,0x2c,0x0a,0xa7,0x25,0x77,0xba,0xc0}};
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
			Antilatency::InterfaceContract::ExceptionCode getMetrics(Antilatency::DeviceNetwork::NodeHandle targetNode, Antilatency::RadioMetrics::Metrics& result) {
				return (reinterpret_cast<VMT*>(this->_object))->getMetrics(targetNode, result);
			}
			Antilatency::InterfaceContract::ExceptionCode getExtendedMetrics(Antilatency::DeviceNetwork::NodeHandle targetNode, Antilatency::RadioMetrics::Interop::ExtendedMetrics& result) {
				return (reinterpret_cast<VMT*>(this->_object))->getExtendedMetrics(targetNode, result);
			}
		};
	} //namespace RadioMetrics
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::RadioMetrics::ICotask, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::DeviceNetwork::ICotask, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getMetrics(Antilatency::DeviceNetwork::NodeHandle targetNode, Antilatency::RadioMetrics::Metrics& result) {
					auto exceptionCode_ = this->_object->getMetrics(targetNode, result);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getExtendedMetrics(Antilatency::DeviceNetwork::NodeHandle targetNode, Antilatency::RadioMetrics::Interop::ExtendedMetrics& result) {
					auto exceptionCode_ = this->_object->getExtendedMetrics(targetNode, result);
					return exceptionCode_;
				}
			};
		} //namespace Details
	} //namespace InterfaceContract
} //namespace Antilatency

namespace Antilatency {
	namespace RadioMetrics {
		/* copy and paste this to implementer
		Antilatency::InterfaceContract::ExceptionCode startTask(Antilatency::DeviceNetwork::INetwork network, Antilatency::DeviceNetwork::NodeHandle node, Antilatency::RadioMetrics::ICotask& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		*/
		struct ICotaskConstructor : Antilatency::DeviceNetwork::ICotaskConstructor {
			struct VMT : Antilatency::DeviceNetwork::ICotaskConstructor::VMT {
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL startTask(Antilatency::DeviceNetwork::INetwork::VMT* network, Antilatency::DeviceNetwork::NodeHandle node, Antilatency::RadioMetrics::ICotask& result) = 0;
				static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
					return Antilatency::InterfaceContract::InterfaceID{0xfb930a9b,0x8b0d,0x4f74,{0xbf,0xb5,0x89,0xa3,0x01,0xce,0x85,0x33}};
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
			Antilatency::InterfaceContract::ExceptionCode startTask(Antilatency::DeviceNetwork::INetwork network, Antilatency::DeviceNetwork::NodeHandle node, Antilatency::RadioMetrics::ICotask& result) {
				return (reinterpret_cast<VMT*>(this->_object))->startTask(network.detach(), node, result);
			}
		};
	} //namespace RadioMetrics
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::RadioMetrics::ICotaskConstructor, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::DeviceNetwork::ICotaskConstructor, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL startTask(Antilatency::DeviceNetwork::INetwork::VMT* network, Antilatency::DeviceNetwork::NodeHandle node, Antilatency::RadioMetrics::ICotask& result) {
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
	namespace RadioMetrics {
		/* copy and paste this to implementer
		Antilatency::InterfaceContract::ExceptionCode getVersion(std::string& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode getCotaskConstructor(Antilatency::RadioMetrics::ICotaskConstructor& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		*/
		struct ILibrary : Antilatency::InterfaceContract::IInterface {
			struct VMT : Antilatency::InterfaceContract::IInterface::VMT {
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getVersion(Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getCotaskConstructor(Antilatency::RadioMetrics::ICotaskConstructor& result) = 0;
				static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
					return Antilatency::InterfaceContract::InterfaceID{0xd0369d42,0xfed4,0x48b5,{0xa7,0x67,0x13,0xca,0xf8,0x9a,0x3f,0xef}};
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
			Antilatency::InterfaceContract::ExceptionCode getCotaskConstructor(Antilatency::RadioMetrics::ICotaskConstructor& result) {
				return (reinterpret_cast<VMT*>(this->_object))->getCotaskConstructor(result);
			}
		};
	} //namespace RadioMetrics
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::RadioMetrics::ILibrary, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::InterfaceContract::IInterface, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getVersion(Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) {
					std::string resultMarshaler;
					auto exceptionCode_ = this->_object->getVersion(resultMarshaler);
					result = resultMarshaler;
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getCotaskConstructor(Antilatency::RadioMetrics::ICotaskConstructor& result) {
					auto exceptionCode_ = this->_object->getCotaskConstructor(result);
					return exceptionCode_;
				}
			};
		} //namespace Details
	} //namespace InterfaceContract
} //namespace Antilatency


#ifdef _MSC_VER
#pragma warning(pop)
#endif
