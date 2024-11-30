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
#include <Antilatency.DeviceNetwork.Interop.h>
#include <Antilatency.h>
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4946)
#pragma warning(disable: 4265)
#endif
namespace Antilatency {
	namespace DeviceNetwork {
		enum class UsbVendorId : uint16_t {
			Antilatency = 0x3237
		};
	} //namespace DeviceNetwork
} //namespace Antilatency
namespace Antilatency {
	inline const char* enumToString(const Antilatency::DeviceNetwork::UsbVendorId& x) {
		switch (x) {
			case Antilatency::DeviceNetwork::UsbVendorId::Antilatency: return "Antilatency";
		}
		return "";
	}
} //namespace Antilatency

namespace Antilatency {
	namespace DeviceNetwork {
		struct UsbDeviceFilter {
			Antilatency::DeviceNetwork::UsbVendorId vid;
			uint16_t pid;
			uint16_t pidMask;
		};
	} //namespace DeviceNetwork
} //namespace Antilatency

namespace Antilatency {
	namespace DeviceNetwork {
		/* copy and paste this to implementer
		Antilatency::InterfaceContract::ExceptionCode addUsbDevice(Antilatency::DeviceNetwork::UsbDeviceFilter usbDeviceType) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode addIpDevice(const std::string& ip, const std::string& mask) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode getUsbDevice(uint32_t index, Antilatency::DeviceNetwork::UsbDeviceFilter& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode getIpDevice(uint32_t index, std::string& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode getIpDeviceMask(uint32_t index, std::string& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		*/
		struct IDeviceFilter : Antilatency::InterfaceContract::IInterface {
			struct VMT : Antilatency::InterfaceContract::IInterface::VMT {
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL addUsbDevice(Antilatency::DeviceNetwork::UsbDeviceFilter usbDeviceType) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL addIpDevice(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate ip, Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate mask) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getUsbDevice(uint32_t index, Antilatency::DeviceNetwork::UsbDeviceFilter& result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getIpDevice(uint32_t index, Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getIpDeviceMask(uint32_t index, Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) = 0;
				static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
					return Antilatency::InterfaceContract::InterfaceID{0x9e6bdb45,0xe7cb,0x4f46,{0xa5,0xee,0xce,0x73,0x53,0xa7,0x34,0xc9}};
				}
			private:
				~VMT() = delete;
			};
			
			static bool isInterfaceSupported(const Antilatency::InterfaceContract::InterfaceID& id) {
			    if (id == IDeviceFilter::VMT::ID()) {
			        return true;
			    }
			    return Antilatency::InterfaceContract::IInterface::isInterfaceSupported(id);
			}
			IDeviceFilter() = default;
			IDeviceFilter(std::nullptr_t) {}
			explicit IDeviceFilter(VMT* pointer) : Antilatency::InterfaceContract::IInterface(pointer) {}
			template<typename T, typename = typename std::enable_if<std::is_base_of<IDeviceFilter, T>::value>::type>
			IDeviceFilter& operator = (const T& other) {
			    Antilatency::InterfaceContract::IInterface::operator=(other);
			    return *this;
			}
			template<class Implementer, class ... TArgs>
			static IDeviceFilter create(TArgs&&... args) {
			    return *new Implementer(std::forward<TArgs>(args)...);
			}
			void attach(VMT* other) ANTILATENCY_NOEXCEPT {
			    Antilatency::InterfaceContract::IInterface::attach(other);
			}
			VMT* detach() ANTILATENCY_NOEXCEPT {
			    return reinterpret_cast<VMT*>(Antilatency::InterfaceContract::IInterface::detach());
			}
			Antilatency::InterfaceContract::ExceptionCode addUsbDevice(Antilatency::DeviceNetwork::UsbDeviceFilter usbDeviceType) {
				return (reinterpret_cast<VMT*>(this->_object))->addUsbDevice(usbDeviceType);
			}
			Antilatency::InterfaceContract::ExceptionCode addIpDevice(const std::string& ip, const std::string& mask) {
				auto ipMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(ip);
				auto maskMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(mask);
				return (reinterpret_cast<VMT*>(this->_object))->addIpDevice(ipMarshaler, maskMarshaler);
			}
			Antilatency::InterfaceContract::ExceptionCode getUsbDevice(uint32_t index, Antilatency::DeviceNetwork::UsbDeviceFilter& result) {
				return (reinterpret_cast<VMT*>(this->_object))->getUsbDevice(index, result);
			}
			Antilatency::InterfaceContract::ExceptionCode getIpDevice(uint32_t index, std::string& result) {
				auto resultMarshaler = Antilatency::InterfaceContract::Details::ArrayOutMarshaler::create(result);
				return (reinterpret_cast<VMT*>(this->_object))->getIpDevice(index, resultMarshaler);
			}
			Antilatency::InterfaceContract::ExceptionCode getIpDeviceMask(uint32_t index, std::string& result) {
				auto resultMarshaler = Antilatency::InterfaceContract::Details::ArrayOutMarshaler::create(result);
				return (reinterpret_cast<VMT*>(this->_object))->getIpDeviceMask(index, resultMarshaler);
			}
		};
	} //namespace DeviceNetwork
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::DeviceNetwork::IDeviceFilter, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::InterfaceContract::IInterface, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL addUsbDevice(Antilatency::DeviceNetwork::UsbDeviceFilter usbDeviceType) {
					auto exceptionCode_ = this->_object->addUsbDevice(usbDeviceType);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL addIpDevice(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate ip, Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate mask) {
					auto exceptionCode_ = this->_object->addIpDevice(ip, mask);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getUsbDevice(uint32_t index, Antilatency::DeviceNetwork::UsbDeviceFilter& result) {
					auto exceptionCode_ = this->_object->getUsbDevice(index, result);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getIpDevice(uint32_t index, Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) {
					std::string resultMarshaler;
					auto exceptionCode_ = this->_object->getIpDevice(index, resultMarshaler);
					result = resultMarshaler;
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getIpDeviceMask(uint32_t index, Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) {
					std::string resultMarshaler;
					auto exceptionCode_ = this->_object->getIpDeviceMask(index, resultMarshaler);
					result = resultMarshaler;
					return exceptionCode_;
				}
			};
		} //namespace Details
	} //namespace InterfaceContract
} //namespace Antilatency

namespace Antilatency {
	namespace DeviceNetwork {
		enum class NodeHandle : uint32_t {
			Null = 0x0
		};
		ANTILATENCY_ENUM_INTEGER_BEHAVIOUR_UNSIGNED(NodeHandle,uint32_t)
	} //namespace DeviceNetwork
} //namespace Antilatency
namespace Antilatency {
	inline const char* enumToString(const Antilatency::DeviceNetwork::NodeHandle& x) {
		switch (x) {
			case Antilatency::DeviceNetwork::NodeHandle::Null: return "Null";
		}
		return "";
	}
} //namespace Antilatency

namespace Antilatency {
	namespace DeviceNetwork {
		enum class NodeStatus : int32_t {
			Idle = 0x0,
			TaskRunning = 0x1,
			Invalid = 0x2
		};
	} //namespace DeviceNetwork
} //namespace Antilatency
namespace Antilatency {
	inline const char* enumToString(const Antilatency::DeviceNetwork::NodeStatus& x) {
		switch (x) {
			case Antilatency::DeviceNetwork::NodeStatus::Idle: return "Idle";
			case Antilatency::DeviceNetwork::NodeStatus::TaskRunning: return "TaskRunning";
			case Antilatency::DeviceNetwork::NodeStatus::Invalid: return "Invalid";
		}
		return "";
	}
} //namespace Antilatency

namespace Antilatency {
	namespace DeviceNetwork {
		/* copy and paste this to implementer
		Antilatency::InterfaceContract::ExceptionCode getPackets(std::vector<Antilatency::DeviceNetwork::Interop::Packet>& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode getAvailablePackets(Antilatency::InterfaceContract::LongBool& taskFinished, std::vector<Antilatency::DeviceNetwork::Interop::Packet>& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode writePacket(Antilatency::DeviceNetwork::Interop::Packet packet, Antilatency::InterfaceContract::LongBool& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		*/
		struct ISynchronousConnection : Antilatency::InterfaceContract::IInterface {
			struct VMT : Antilatency::InterfaceContract::IInterface::VMT {
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getPackets(Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getAvailablePackets(Antilatency::InterfaceContract::LongBool& taskFinished, Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL writePacket(Antilatency::DeviceNetwork::Interop::Packet packet, Antilatency::InterfaceContract::LongBool& result) = 0;
				static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
					return Antilatency::InterfaceContract::InterfaceID{0xaf7402e8,0x2a23,0x442b,{0x82,0x30,0xd4,0x1f,0x55,0xef,0x5d,0xc0}};
				}
			private:
				~VMT() = delete;
			};
			
			static bool isInterfaceSupported(const Antilatency::InterfaceContract::InterfaceID& id) {
			    if (id == ISynchronousConnection::VMT::ID()) {
			        return true;
			    }
			    return Antilatency::InterfaceContract::IInterface::isInterfaceSupported(id);
			}
			ISynchronousConnection() = default;
			ISynchronousConnection(std::nullptr_t) {}
			explicit ISynchronousConnection(VMT* pointer) : Antilatency::InterfaceContract::IInterface(pointer) {}
			template<typename T, typename = typename std::enable_if<std::is_base_of<ISynchronousConnection, T>::value>::type>
			ISynchronousConnection& operator = (const T& other) {
			    Antilatency::InterfaceContract::IInterface::operator=(other);
			    return *this;
			}
			template<class Implementer, class ... TArgs>
			static ISynchronousConnection create(TArgs&&... args) {
			    return *new Implementer(std::forward<TArgs>(args)...);
			}
			void attach(VMT* other) ANTILATENCY_NOEXCEPT {
			    Antilatency::InterfaceContract::IInterface::attach(other);
			}
			VMT* detach() ANTILATENCY_NOEXCEPT {
			    return reinterpret_cast<VMT*>(Antilatency::InterfaceContract::IInterface::detach());
			}
			Antilatency::InterfaceContract::ExceptionCode getPackets(std::vector<Antilatency::DeviceNetwork::Interop::Packet>& result) {
				auto resultMarshaler = Antilatency::InterfaceContract::Details::ArrayOutMarshaler::create(result);
				return (reinterpret_cast<VMT*>(this->_object))->getPackets(resultMarshaler);
			}
			Antilatency::InterfaceContract::ExceptionCode getAvailablePackets(Antilatency::InterfaceContract::LongBool& taskFinished, std::vector<Antilatency::DeviceNetwork::Interop::Packet>& result) {
				auto resultMarshaler = Antilatency::InterfaceContract::Details::ArrayOutMarshaler::create(result);
				return (reinterpret_cast<VMT*>(this->_object))->getAvailablePackets(taskFinished, resultMarshaler);
			}
			Antilatency::InterfaceContract::ExceptionCode writePacket(Antilatency::DeviceNetwork::Interop::Packet packet, Antilatency::InterfaceContract::LongBool& result) {
				return (reinterpret_cast<VMT*>(this->_object))->writePacket(packet, result);
			}
		};
	} //namespace DeviceNetwork
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::DeviceNetwork::ISynchronousConnection, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::InterfaceContract::IInterface, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getPackets(Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) {
					std::vector<Antilatency::DeviceNetwork::Interop::Packet> resultMarshaler;
					auto exceptionCode_ = this->_object->getPackets(resultMarshaler);
					result = resultMarshaler;
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getAvailablePackets(Antilatency::InterfaceContract::LongBool& taskFinished, Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) {
					std::vector<Antilatency::DeviceNetwork::Interop::Packet> resultMarshaler;
					auto exceptionCode_ = this->_object->getAvailablePackets(taskFinished, resultMarshaler);
					result = resultMarshaler;
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL writePacket(Antilatency::DeviceNetwork::Interop::Packet packet, Antilatency::InterfaceContract::LongBool& result) {
					auto exceptionCode_ = this->_object->writePacket(packet, result);
					return exceptionCode_;
				}
			};
		} //namespace Details
	} //namespace InterfaceContract
} //namespace Antilatency

namespace Antilatency {
	namespace DeviceNetwork {
		/* copy and paste this to implementer
		Antilatency::InterfaceContract::ExceptionCode isTaskFinished(Antilatency::InterfaceContract::LongBool& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		*/
		struct ICotask : Antilatency::InterfaceContract::IInterface {
			struct VMT : Antilatency::InterfaceContract::IInterface::VMT {
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL isTaskFinished(Antilatency::InterfaceContract::LongBool& result) = 0;
				static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
					return Antilatency::InterfaceContract::InterfaceID{0xfd95f649,0x562a,0x4819,{0xa8,0x16,0x26,0xb7,0x6c,0xd9,0xd8,0xd6}};
				}
			private:
				~VMT() = delete;
			};
			
			static bool isInterfaceSupported(const Antilatency::InterfaceContract::InterfaceID& id) {
			    if (id == ICotask::VMT::ID()) {
			        return true;
			    }
			    return Antilatency::InterfaceContract::IInterface::isInterfaceSupported(id);
			}
			ICotask() = default;
			ICotask(std::nullptr_t) {}
			explicit ICotask(VMT* pointer) : Antilatency::InterfaceContract::IInterface(pointer) {}
			template<typename T, typename = typename std::enable_if<std::is_base_of<ICotask, T>::value>::type>
			ICotask& operator = (const T& other) {
			    Antilatency::InterfaceContract::IInterface::operator=(other);
			    return *this;
			}
			template<class Implementer, class ... TArgs>
			static ICotask create(TArgs&&... args) {
			    return *new Implementer(std::forward<TArgs>(args)...);
			}
			void attach(VMT* other) ANTILATENCY_NOEXCEPT {
			    Antilatency::InterfaceContract::IInterface::attach(other);
			}
			VMT* detach() ANTILATENCY_NOEXCEPT {
			    return reinterpret_cast<VMT*>(Antilatency::InterfaceContract::IInterface::detach());
			}
			Antilatency::InterfaceContract::ExceptionCode isTaskFinished(Antilatency::InterfaceContract::LongBool& result) {
				return (reinterpret_cast<VMT*>(this->_object))->isTaskFinished(result);
			}
		};
	} //namespace DeviceNetwork
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::DeviceNetwork::ICotask, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::InterfaceContract::IInterface, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL isTaskFinished(Antilatency::InterfaceContract::LongBool& result) {
					auto exceptionCode_ = this->_object->isTaskFinished(result);
					return exceptionCode_;
				}
			};
		} //namespace Details
	} //namespace InterfaceContract
} //namespace Antilatency

namespace Antilatency {
	namespace DeviceNetwork {
		/* copy and paste this to implementer
		Antilatency::InterfaceContract::ExceptionCode getPropertyKey(uint32_t index, std::string& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode getStringProperty(const std::string& key, std::string& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode setStringProperty(const std::string& key, const std::string& value) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode getBinaryProperty(const std::string& key, std::vector<uint8_t>& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode setBinaryProperty(const std::string& key, const std::vector<uint8_t>& value) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode deleteProperty(const std::string& key) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode getPropertyKeyDeferred(uint32_t index, Antilatency::IFutureString& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode getStringPropertyDeferred(const std::string& key, Antilatency::IFutureString& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode setStringPropertyDeferred(const std::string& key, const std::string& value, Antilatency::IFuture& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode getBinaryPropertyDeferred(const std::string& key, Antilatency::IFutureArrayOfByte& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode setBinaryPropertyDeferred(const std::string& key, const std::vector<uint8_t>& value, Antilatency::IFuture& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode deletePropertyDeferred(const std::string& key, Antilatency::IFuture& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		*/
		struct IPropertyCotask : Antilatency::DeviceNetwork::ICotask {
			struct VMT : Antilatency::DeviceNetwork::ICotask::VMT {
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getPropertyKey(uint32_t index, Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getStringProperty(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate key, Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setStringProperty(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate key, Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate value) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getBinaryProperty(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate key, Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setBinaryProperty(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate key, Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate value) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL deleteProperty(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate key) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getPropertyKeyDeferred(uint32_t index, Antilatency::IFutureString& result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getStringPropertyDeferred(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate key, Antilatency::IFutureString& result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setStringPropertyDeferred(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate key, Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate value, Antilatency::IFuture& result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getBinaryPropertyDeferred(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate key, Antilatency::IFutureArrayOfByte& result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setBinaryPropertyDeferred(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate key, Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate value, Antilatency::IFuture& result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL deletePropertyDeferred(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate key, Antilatency::IFuture& result) = 0;
				static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
					return Antilatency::InterfaceContract::InterfaceID{0xc46779e1,0x0741,0x40a7,{0xa1,0x46,0x30,0x1e,0x82,0x73,0xb3,0x3f}};
				}
			private:
				~VMT() = delete;
			};
			
			static bool isInterfaceSupported(const Antilatency::InterfaceContract::InterfaceID& id) {
			    if (id == IPropertyCotask::VMT::ID()) {
			        return true;
			    }
			    return Antilatency::DeviceNetwork::ICotask::isInterfaceSupported(id);
			}
			IPropertyCotask() = default;
			IPropertyCotask(std::nullptr_t) {}
			explicit IPropertyCotask(VMT* pointer) : Antilatency::DeviceNetwork::ICotask(pointer) {}
			template<typename T, typename = typename std::enable_if<std::is_base_of<IPropertyCotask, T>::value>::type>
			IPropertyCotask& operator = (const T& other) {
			    Antilatency::DeviceNetwork::ICotask::operator=(other);
			    return *this;
			}
			template<class Implementer, class ... TArgs>
			static IPropertyCotask create(TArgs&&... args) {
			    return *new Implementer(std::forward<TArgs>(args)...);
			}
			void attach(VMT* other) ANTILATENCY_NOEXCEPT {
			    Antilatency::DeviceNetwork::ICotask::attach(other);
			}
			VMT* detach() ANTILATENCY_NOEXCEPT {
			    return reinterpret_cast<VMT*>(Antilatency::DeviceNetwork::ICotask::detach());
			}
			Antilatency::InterfaceContract::ExceptionCode getPropertyKey(uint32_t index, std::string& result) {
				auto resultMarshaler = Antilatency::InterfaceContract::Details::ArrayOutMarshaler::create(result);
				return (reinterpret_cast<VMT*>(this->_object))->getPropertyKey(index, resultMarshaler);
			}
			Antilatency::InterfaceContract::ExceptionCode getStringProperty(const std::string& key, std::string& result) {
				auto keyMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(key);
				auto resultMarshaler = Antilatency::InterfaceContract::Details::ArrayOutMarshaler::create(result);
				return (reinterpret_cast<VMT*>(this->_object))->getStringProperty(keyMarshaler, resultMarshaler);
			}
			Antilatency::InterfaceContract::ExceptionCode setStringProperty(const std::string& key, const std::string& value) {
				auto keyMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(key);
				auto valueMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(value);
				return (reinterpret_cast<VMT*>(this->_object))->setStringProperty(keyMarshaler, valueMarshaler);
			}
			Antilatency::InterfaceContract::ExceptionCode getBinaryProperty(const std::string& key, std::vector<uint8_t>& result) {
				auto keyMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(key);
				auto resultMarshaler = Antilatency::InterfaceContract::Details::ArrayOutMarshaler::create(result);
				return (reinterpret_cast<VMT*>(this->_object))->getBinaryProperty(keyMarshaler, resultMarshaler);
			}
			Antilatency::InterfaceContract::ExceptionCode setBinaryProperty(const std::string& key, const std::vector<uint8_t>& value) {
				auto keyMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(key);
				auto valueMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(value);
				return (reinterpret_cast<VMT*>(this->_object))->setBinaryProperty(keyMarshaler, valueMarshaler);
			}
			Antilatency::InterfaceContract::ExceptionCode deleteProperty(const std::string& key) {
				auto keyMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(key);
				return (reinterpret_cast<VMT*>(this->_object))->deleteProperty(keyMarshaler);
			}
			Antilatency::InterfaceContract::ExceptionCode getPropertyKeyDeferred(uint32_t index, Antilatency::IFutureString& result) {
				return (reinterpret_cast<VMT*>(this->_object))->getPropertyKeyDeferred(index, result);
			}
			Antilatency::InterfaceContract::ExceptionCode getStringPropertyDeferred(const std::string& key, Antilatency::IFutureString& result) {
				auto keyMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(key);
				return (reinterpret_cast<VMT*>(this->_object))->getStringPropertyDeferred(keyMarshaler, result);
			}
			Antilatency::InterfaceContract::ExceptionCode setStringPropertyDeferred(const std::string& key, const std::string& value, Antilatency::IFuture& result) {
				auto keyMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(key);
				auto valueMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(value);
				return (reinterpret_cast<VMT*>(this->_object))->setStringPropertyDeferred(keyMarshaler, valueMarshaler, result);
			}
			Antilatency::InterfaceContract::ExceptionCode getBinaryPropertyDeferred(const std::string& key, Antilatency::IFutureArrayOfByte& result) {
				auto keyMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(key);
				return (reinterpret_cast<VMT*>(this->_object))->getBinaryPropertyDeferred(keyMarshaler, result);
			}
			Antilatency::InterfaceContract::ExceptionCode setBinaryPropertyDeferred(const std::string& key, const std::vector<uint8_t>& value, Antilatency::IFuture& result) {
				auto keyMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(key);
				auto valueMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(value);
				return (reinterpret_cast<VMT*>(this->_object))->setBinaryPropertyDeferred(keyMarshaler, valueMarshaler, result);
			}
			Antilatency::InterfaceContract::ExceptionCode deletePropertyDeferred(const std::string& key, Antilatency::IFuture& result) {
				auto keyMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(key);
				return (reinterpret_cast<VMT*>(this->_object))->deletePropertyDeferred(keyMarshaler, result);
			}
		};
	} //namespace DeviceNetwork
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::DeviceNetwork::IPropertyCotask, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::DeviceNetwork::ICotask, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getPropertyKey(uint32_t index, Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) {
					std::string resultMarshaler;
					auto exceptionCode_ = this->_object->getPropertyKey(index, resultMarshaler);
					result = resultMarshaler;
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getStringProperty(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate key, Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) {
					std::string resultMarshaler;
					auto exceptionCode_ = this->_object->getStringProperty(key, resultMarshaler);
					result = resultMarshaler;
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setStringProperty(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate key, Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate value) {
					auto exceptionCode_ = this->_object->setStringProperty(key, value);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getBinaryProperty(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate key, Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) {
					std::vector<uint8_t> resultMarshaler;
					auto exceptionCode_ = this->_object->getBinaryProperty(key, resultMarshaler);
					result = resultMarshaler;
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setBinaryProperty(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate key, Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate value) {
					auto exceptionCode_ = this->_object->setBinaryProperty(key, value);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL deleteProperty(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate key) {
					auto exceptionCode_ = this->_object->deleteProperty(key);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getPropertyKeyDeferred(uint32_t index, Antilatency::IFutureString& result) {
					auto exceptionCode_ = this->_object->getPropertyKeyDeferred(index, result);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getStringPropertyDeferred(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate key, Antilatency::IFutureString& result) {
					auto exceptionCode_ = this->_object->getStringPropertyDeferred(key, result);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setStringPropertyDeferred(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate key, Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate value, Antilatency::IFuture& result) {
					auto exceptionCode_ = this->_object->setStringPropertyDeferred(key, value, result);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getBinaryPropertyDeferred(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate key, Antilatency::IFutureArrayOfByte& result) {
					auto exceptionCode_ = this->_object->getBinaryPropertyDeferred(key, result);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setBinaryPropertyDeferred(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate key, Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate value, Antilatency::IFuture& result) {
					auto exceptionCode_ = this->_object->setBinaryPropertyDeferred(key, value, result);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL deletePropertyDeferred(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate key, Antilatency::IFuture& result) {
					auto exceptionCode_ = this->_object->deletePropertyDeferred(key, result);
					return exceptionCode_;
				}
			};
		} //namespace Details
	} //namespace InterfaceContract
} //namespace Antilatency

namespace Antilatency {
	namespace DeviceNetwork {
		/* copy and paste this to implementer
		Antilatency::InterfaceContract::ExceptionCode getUpdateId(uint32_t& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode getCurrentTime(uint64_t& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode getDeviceFilter(Antilatency::DeviceNetwork::IDeviceFilter& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode getNodes(std::vector<Antilatency::DeviceNetwork::NodeHandle>& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode nodeGetStatus(Antilatency::DeviceNetwork::NodeHandle node, Antilatency::DeviceNetwork::NodeStatus& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode nodeGetCurrentOutofsyncTime(Antilatency::DeviceNetwork::NodeHandle node, float& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode nodeIsTaskSupported(Antilatency::DeviceNetwork::NodeHandle node, Antilatency::InterfaceContract::InterfaceID taskId, Antilatency::InterfaceContract::LongBool& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode nodeGetParent(Antilatency::DeviceNetwork::NodeHandle node, Antilatency::DeviceNetwork::NodeHandle& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode nodeGetPhysicalPath(Antilatency::DeviceNetwork::NodeHandle node, std::string& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode nodeStartTask(Antilatency::DeviceNetwork::NodeHandle node, Antilatency::InterfaceContract::InterfaceID taskId, Antilatency::DeviceNetwork::Interop::IDataReceiver taskDataReceiver, Antilatency::DeviceNetwork::Interop::IDataReceiver& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode nodeStartTask2(Antilatency::DeviceNetwork::NodeHandle node, Antilatency::InterfaceContract::InterfaceID taskId, Antilatency::DeviceNetwork::ISynchronousConnection& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode nodeGetStringProperty(Antilatency::DeviceNetwork::NodeHandle node, const std::string& key, std::string& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode nodeGetBinaryProperty(Antilatency::DeviceNetwork::NodeHandle node, const std::string& key, std::vector<uint8_t>& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode nodeStartPropertyTask(Antilatency::DeviceNetwork::NodeHandle node, Antilatency::DeviceNetwork::IPropertyCotask& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		*/
		struct INetwork : Antilatency::InterfaceContract::IInterface {
			struct VMT : Antilatency::InterfaceContract::IInterface::VMT {
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getUpdateId(uint32_t& result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getCurrentTime(uint64_t& result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getDeviceFilter(Antilatency::DeviceNetwork::IDeviceFilter& result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getNodes(Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL nodeGetStatus(Antilatency::DeviceNetwork::NodeHandle node, Antilatency::DeviceNetwork::NodeStatus& result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL nodeGetCurrentOutofsyncTime(Antilatency::DeviceNetwork::NodeHandle node, float& result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL nodeIsTaskSupported(Antilatency::DeviceNetwork::NodeHandle node, Antilatency::InterfaceContract::InterfaceID taskId, Antilatency::InterfaceContract::LongBool& result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL nodeGetParent(Antilatency::DeviceNetwork::NodeHandle node, Antilatency::DeviceNetwork::NodeHandle& result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL nodeGetPhysicalPath(Antilatency::DeviceNetwork::NodeHandle node, Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL nodeStartTask(Antilatency::DeviceNetwork::NodeHandle node, Antilatency::InterfaceContract::InterfaceID taskId, Antilatency::DeviceNetwork::Interop::IDataReceiver::VMT* taskDataReceiver, Antilatency::DeviceNetwork::Interop::IDataReceiver& result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL nodeStartTask2(Antilatency::DeviceNetwork::NodeHandle node, Antilatency::InterfaceContract::InterfaceID taskId, Antilatency::DeviceNetwork::ISynchronousConnection& result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL nodeGetStringProperty(Antilatency::DeviceNetwork::NodeHandle node, Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate key, Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL nodeGetBinaryProperty(Antilatency::DeviceNetwork::NodeHandle node, Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate key, Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL nodeStartPropertyTask(Antilatency::DeviceNetwork::NodeHandle node, Antilatency::DeviceNetwork::IPropertyCotask& result) = 0;
				static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
					return Antilatency::InterfaceContract::InterfaceID{0xeb7f3989,0x5cb7,0x42ea,{0x91,0x10,0x52,0xd7,0x12,0xf3,0x9c,0xe8}};
				}
			private:
				~VMT() = delete;
			};
			
			static bool isInterfaceSupported(const Antilatency::InterfaceContract::InterfaceID& id) {
			    if (id == INetwork::VMT::ID()) {
			        return true;
			    }
			    return Antilatency::InterfaceContract::IInterface::isInterfaceSupported(id);
			}
			INetwork() = default;
			INetwork(std::nullptr_t) {}
			explicit INetwork(VMT* pointer) : Antilatency::InterfaceContract::IInterface(pointer) {}
			template<typename T, typename = typename std::enable_if<std::is_base_of<INetwork, T>::value>::type>
			INetwork& operator = (const T& other) {
			    Antilatency::InterfaceContract::IInterface::operator=(other);
			    return *this;
			}
			template<class Implementer, class ... TArgs>
			static INetwork create(TArgs&&... args) {
			    return *new Implementer(std::forward<TArgs>(args)...);
			}
			void attach(VMT* other) ANTILATENCY_NOEXCEPT {
			    Antilatency::InterfaceContract::IInterface::attach(other);
			}
			VMT* detach() ANTILATENCY_NOEXCEPT {
			    return reinterpret_cast<VMT*>(Antilatency::InterfaceContract::IInterface::detach());
			}
			Antilatency::InterfaceContract::ExceptionCode getUpdateId(uint32_t& result) {
				return (reinterpret_cast<VMT*>(this->_object))->getUpdateId(result);
			}
			Antilatency::InterfaceContract::ExceptionCode getCurrentTime(uint64_t& result) {
				return (reinterpret_cast<VMT*>(this->_object))->getCurrentTime(result);
			}
			Antilatency::InterfaceContract::ExceptionCode getDeviceFilter(Antilatency::DeviceNetwork::IDeviceFilter& result) {
				return (reinterpret_cast<VMT*>(this->_object))->getDeviceFilter(result);
			}
			Antilatency::InterfaceContract::ExceptionCode getNodes(std::vector<Antilatency::DeviceNetwork::NodeHandle>& result) {
				auto resultMarshaler = Antilatency::InterfaceContract::Details::ArrayOutMarshaler::create(result);
				return (reinterpret_cast<VMT*>(this->_object))->getNodes(resultMarshaler);
			}
			Antilatency::InterfaceContract::ExceptionCode nodeGetStatus(Antilatency::DeviceNetwork::NodeHandle node, Antilatency::DeviceNetwork::NodeStatus& result) {
				return (reinterpret_cast<VMT*>(this->_object))->nodeGetStatus(node, result);
			}
			Antilatency::InterfaceContract::ExceptionCode nodeGetCurrentOutofsyncTime(Antilatency::DeviceNetwork::NodeHandle node, float& result) {
				return (reinterpret_cast<VMT*>(this->_object))->nodeGetCurrentOutofsyncTime(node, result);
			}
			Antilatency::InterfaceContract::ExceptionCode nodeIsTaskSupported(Antilatency::DeviceNetwork::NodeHandle node, Antilatency::InterfaceContract::InterfaceID taskId, Antilatency::InterfaceContract::LongBool& result) {
				return (reinterpret_cast<VMT*>(this->_object))->nodeIsTaskSupported(node, taskId, result);
			}
			Antilatency::InterfaceContract::ExceptionCode nodeGetParent(Antilatency::DeviceNetwork::NodeHandle node, Antilatency::DeviceNetwork::NodeHandle& result) {
				return (reinterpret_cast<VMT*>(this->_object))->nodeGetParent(node, result);
			}
			Antilatency::InterfaceContract::ExceptionCode nodeGetPhysicalPath(Antilatency::DeviceNetwork::NodeHandle node, std::string& result) {
				auto resultMarshaler = Antilatency::InterfaceContract::Details::ArrayOutMarshaler::create(result);
				return (reinterpret_cast<VMT*>(this->_object))->nodeGetPhysicalPath(node, resultMarshaler);
			}
			Antilatency::InterfaceContract::ExceptionCode nodeStartTask(Antilatency::DeviceNetwork::NodeHandle node, Antilatency::InterfaceContract::InterfaceID taskId, Antilatency::DeviceNetwork::Interop::IDataReceiver taskDataReceiver, Antilatency::DeviceNetwork::Interop::IDataReceiver& result) {
				return (reinterpret_cast<VMT*>(this->_object))->nodeStartTask(node, taskId, taskDataReceiver.detach(), result);
			}
			Antilatency::InterfaceContract::ExceptionCode nodeStartTask2(Antilatency::DeviceNetwork::NodeHandle node, Antilatency::InterfaceContract::InterfaceID taskId, Antilatency::DeviceNetwork::ISynchronousConnection& result) {
				return (reinterpret_cast<VMT*>(this->_object))->nodeStartTask2(node, taskId, result);
			}
			Antilatency::InterfaceContract::ExceptionCode nodeGetStringProperty(Antilatency::DeviceNetwork::NodeHandle node, const std::string& key, std::string& result) {
				auto keyMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(key);
				auto resultMarshaler = Antilatency::InterfaceContract::Details::ArrayOutMarshaler::create(result);
				return (reinterpret_cast<VMT*>(this->_object))->nodeGetStringProperty(node, keyMarshaler, resultMarshaler);
			}
			Antilatency::InterfaceContract::ExceptionCode nodeGetBinaryProperty(Antilatency::DeviceNetwork::NodeHandle node, const std::string& key, std::vector<uint8_t>& result) {
				auto keyMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(key);
				auto resultMarshaler = Antilatency::InterfaceContract::Details::ArrayOutMarshaler::create(result);
				return (reinterpret_cast<VMT*>(this->_object))->nodeGetBinaryProperty(node, keyMarshaler, resultMarshaler);
			}
			Antilatency::InterfaceContract::ExceptionCode nodeStartPropertyTask(Antilatency::DeviceNetwork::NodeHandle node, Antilatency::DeviceNetwork::IPropertyCotask& result) {
				return (reinterpret_cast<VMT*>(this->_object))->nodeStartPropertyTask(node, result);
			}
		};
	} //namespace DeviceNetwork
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::DeviceNetwork::INetwork, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::InterfaceContract::IInterface, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getUpdateId(uint32_t& result) {
					auto exceptionCode_ = this->_object->getUpdateId(result);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getCurrentTime(uint64_t& result) {
					auto exceptionCode_ = this->_object->getCurrentTime(result);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getDeviceFilter(Antilatency::DeviceNetwork::IDeviceFilter& result) {
					auto exceptionCode_ = this->_object->getDeviceFilter(result);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getNodes(Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) {
					std::vector<Antilatency::DeviceNetwork::NodeHandle> resultMarshaler;
					auto exceptionCode_ = this->_object->getNodes(resultMarshaler);
					result = resultMarshaler;
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL nodeGetStatus(Antilatency::DeviceNetwork::NodeHandle node, Antilatency::DeviceNetwork::NodeStatus& result) {
					auto exceptionCode_ = this->_object->nodeGetStatus(node, result);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL nodeGetCurrentOutofsyncTime(Antilatency::DeviceNetwork::NodeHandle node, float& result) {
					auto exceptionCode_ = this->_object->nodeGetCurrentOutofsyncTime(node, result);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL nodeIsTaskSupported(Antilatency::DeviceNetwork::NodeHandle node, Antilatency::InterfaceContract::InterfaceID taskId, Antilatency::InterfaceContract::LongBool& result) {
					auto exceptionCode_ = this->_object->nodeIsTaskSupported(node, taskId, result);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL nodeGetParent(Antilatency::DeviceNetwork::NodeHandle node, Antilatency::DeviceNetwork::NodeHandle& result) {
					auto exceptionCode_ = this->_object->nodeGetParent(node, result);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL nodeGetPhysicalPath(Antilatency::DeviceNetwork::NodeHandle node, Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) {
					std::string resultMarshaler;
					auto exceptionCode_ = this->_object->nodeGetPhysicalPath(node, resultMarshaler);
					result = resultMarshaler;
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL nodeStartTask(Antilatency::DeviceNetwork::NodeHandle node, Antilatency::InterfaceContract::InterfaceID taskId, Antilatency::DeviceNetwork::Interop::IDataReceiver::VMT* taskDataReceiver, Antilatency::DeviceNetwork::Interop::IDataReceiver& result) {
					Antilatency::DeviceNetwork::Interop::IDataReceiver taskDataReceiverMarshaler;
					taskDataReceiverMarshaler.attach(taskDataReceiver);
					auto exceptionCode_ = this->_object->nodeStartTask(node, taskId, taskDataReceiverMarshaler, result);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL nodeStartTask2(Antilatency::DeviceNetwork::NodeHandle node, Antilatency::InterfaceContract::InterfaceID taskId, Antilatency::DeviceNetwork::ISynchronousConnection& result) {
					auto exceptionCode_ = this->_object->nodeStartTask2(node, taskId, result);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL nodeGetStringProperty(Antilatency::DeviceNetwork::NodeHandle node, Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate key, Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) {
					std::string resultMarshaler;
					auto exceptionCode_ = this->_object->nodeGetStringProperty(node, key, resultMarshaler);
					result = resultMarshaler;
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL nodeGetBinaryProperty(Antilatency::DeviceNetwork::NodeHandle node, Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate key, Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) {
					std::vector<uint8_t> resultMarshaler;
					auto exceptionCode_ = this->_object->nodeGetBinaryProperty(node, key, resultMarshaler);
					result = resultMarshaler;
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL nodeStartPropertyTask(Antilatency::DeviceNetwork::NodeHandle node, Antilatency::DeviceNetwork::IPropertyCotask& result) {
					auto exceptionCode_ = this->_object->nodeStartPropertyTask(node, result);
					return exceptionCode_;
				}
			};
		} //namespace Details
	} //namespace InterfaceContract
} //namespace Antilatency

namespace Antilatency {
	namespace DeviceNetwork {
		/* copy and paste this to implementer
		Antilatency::InterfaceContract::ExceptionCode isSupported(Antilatency::DeviceNetwork::INetwork network, Antilatency::DeviceNetwork::NodeHandle node, Antilatency::InterfaceContract::LongBool& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode findSupportedNodes(Antilatency::DeviceNetwork::INetwork network, std::vector<Antilatency::DeviceNetwork::NodeHandle>& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		*/
		struct ICotaskConstructor : Antilatency::InterfaceContract::IInterface {
			struct VMT : Antilatency::InterfaceContract::IInterface::VMT {
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL isSupported(Antilatency::DeviceNetwork::INetwork::VMT* network, Antilatency::DeviceNetwork::NodeHandle node, Antilatency::InterfaceContract::LongBool& result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL findSupportedNodes(Antilatency::DeviceNetwork::INetwork::VMT* network, Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) = 0;
				static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
					return Antilatency::InterfaceContract::InterfaceID{0x9ecfa909,0xd13c,0x4c29,{0xa8,0x7e,0x89,0x25,0xb7,0x84,0x66,0x38}};
				}
			private:
				~VMT() = delete;
			};
			
			static bool isInterfaceSupported(const Antilatency::InterfaceContract::InterfaceID& id) {
			    if (id == ICotaskConstructor::VMT::ID()) {
			        return true;
			    }
			    return Antilatency::InterfaceContract::IInterface::isInterfaceSupported(id);
			}
			ICotaskConstructor() = default;
			ICotaskConstructor(std::nullptr_t) {}
			explicit ICotaskConstructor(VMT* pointer) : Antilatency::InterfaceContract::IInterface(pointer) {}
			template<typename T, typename = typename std::enable_if<std::is_base_of<ICotaskConstructor, T>::value>::type>
			ICotaskConstructor& operator = (const T& other) {
			    Antilatency::InterfaceContract::IInterface::operator=(other);
			    return *this;
			}
			template<class Implementer, class ... TArgs>
			static ICotaskConstructor create(TArgs&&... args) {
			    return *new Implementer(std::forward<TArgs>(args)...);
			}
			void attach(VMT* other) ANTILATENCY_NOEXCEPT {
			    Antilatency::InterfaceContract::IInterface::attach(other);
			}
			VMT* detach() ANTILATENCY_NOEXCEPT {
			    return reinterpret_cast<VMT*>(Antilatency::InterfaceContract::IInterface::detach());
			}
			Antilatency::InterfaceContract::ExceptionCode isSupported(Antilatency::DeviceNetwork::INetwork network, Antilatency::DeviceNetwork::NodeHandle node, Antilatency::InterfaceContract::LongBool& result) {
				return (reinterpret_cast<VMT*>(this->_object))->isSupported(network.detach(), node, result);
			}
			Antilatency::InterfaceContract::ExceptionCode findSupportedNodes(Antilatency::DeviceNetwork::INetwork network, std::vector<Antilatency::DeviceNetwork::NodeHandle>& result) {
				auto resultMarshaler = Antilatency::InterfaceContract::Details::ArrayOutMarshaler::create(result);
				return (reinterpret_cast<VMT*>(this->_object))->findSupportedNodes(network.detach(), resultMarshaler);
			}
		};
	} //namespace DeviceNetwork
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::DeviceNetwork::ICotaskConstructor, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::InterfaceContract::IInterface, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL isSupported(Antilatency::DeviceNetwork::INetwork::VMT* network, Antilatency::DeviceNetwork::NodeHandle node, Antilatency::InterfaceContract::LongBool& result) {
					Antilatency::DeviceNetwork::INetwork networkMarshaler;
					networkMarshaler.attach(network);
					auto exceptionCode_ = this->_object->isSupported(networkMarshaler, node, result);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL findSupportedNodes(Antilatency::DeviceNetwork::INetwork::VMT* network, Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) {
					Antilatency::DeviceNetwork::INetwork networkMarshaler;
					networkMarshaler.attach(network);
					std::vector<Antilatency::DeviceNetwork::NodeHandle> resultMarshaler;
					auto exceptionCode_ = this->_object->findSupportedNodes(networkMarshaler, resultMarshaler);
					result = resultMarshaler;
					return exceptionCode_;
				}
			};
		} //namespace Details
	} //namespace InterfaceContract
} //namespace Antilatency

namespace Antilatency {
	namespace DeviceNetwork {
		/* copy and paste this to implementer
		Antilatency::InterfaceContract::ExceptionCode getBatteryLevel(float& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		*/
		struct ICotaskBatteryPowered : Antilatency::DeviceNetwork::ICotask {
			struct VMT : Antilatency::DeviceNetwork::ICotask::VMT {
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getBatteryLevel(float& result) = 0;
				static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
					return Antilatency::InterfaceContract::InterfaceID{0x1f3f7579,0x813e,0x4528,{0x82,0xf9,0x5a,0x5f,0xc3,0x5a,0x92,0x95}};
				}
			private:
				~VMT() = delete;
			};
			
			static bool isInterfaceSupported(const Antilatency::InterfaceContract::InterfaceID& id) {
			    if (id == ICotaskBatteryPowered::VMT::ID()) {
			        return true;
			    }
			    return Antilatency::DeviceNetwork::ICotask::isInterfaceSupported(id);
			}
			ICotaskBatteryPowered() = default;
			ICotaskBatteryPowered(std::nullptr_t) {}
			explicit ICotaskBatteryPowered(VMT* pointer) : Antilatency::DeviceNetwork::ICotask(pointer) {}
			template<typename T, typename = typename std::enable_if<std::is_base_of<ICotaskBatteryPowered, T>::value>::type>
			ICotaskBatteryPowered& operator = (const T& other) {
			    Antilatency::DeviceNetwork::ICotask::operator=(other);
			    return *this;
			}
			template<class Implementer, class ... TArgs>
			static ICotaskBatteryPowered create(TArgs&&... args) {
			    return *new Implementer(std::forward<TArgs>(args)...);
			}
			void attach(VMT* other) ANTILATENCY_NOEXCEPT {
			    Antilatency::DeviceNetwork::ICotask::attach(other);
			}
			VMT* detach() ANTILATENCY_NOEXCEPT {
			    return reinterpret_cast<VMT*>(Antilatency::DeviceNetwork::ICotask::detach());
			}
			Antilatency::InterfaceContract::ExceptionCode getBatteryLevel(float& result) {
				return (reinterpret_cast<VMT*>(this->_object))->getBatteryLevel(result);
			}
		};
	} //namespace DeviceNetwork
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::DeviceNetwork::ICotaskBatteryPowered, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::DeviceNetwork::ICotask, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getBatteryLevel(float& result) {
					auto exceptionCode_ = this->_object->getBatteryLevel(result);
					return exceptionCode_;
				}
			};
		} //namespace Details
	} //namespace InterfaceContract
} //namespace Antilatency

namespace Antilatency {
	namespace DeviceNetwork {
		enum class LogLevel : int32_t {
			Trace = 0x0,
			Debug = 0x1,
			Info = 0x2,
			Warning = 0x3,
			Error = 0x4,
			Critical = 0x5,
			Off = 0x6
		};
	} //namespace DeviceNetwork
} //namespace Antilatency
namespace Antilatency {
	inline const char* enumToString(const Antilatency::DeviceNetwork::LogLevel& x) {
		switch (x) {
			case Antilatency::DeviceNetwork::LogLevel::Trace: return "Trace";
			case Antilatency::DeviceNetwork::LogLevel::Debug: return "Debug";
			case Antilatency::DeviceNetwork::LogLevel::Info: return "Info";
			case Antilatency::DeviceNetwork::LogLevel::Warning: return "Warning";
			case Antilatency::DeviceNetwork::LogLevel::Error: return "Error";
			case Antilatency::DeviceNetwork::LogLevel::Critical: return "Critical";
			case Antilatency::DeviceNetwork::LogLevel::Off: return "Off";
		}
		return "";
	}
} //namespace Antilatency

namespace Antilatency {
	namespace DeviceNetwork {
		/* copy and paste this to implementer
		Antilatency::InterfaceContract::ExceptionCode createFilter(Antilatency::DeviceNetwork::IDeviceFilter& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode createNetwork(Antilatency::DeviceNetwork::IDeviceFilter deviceFilter, Antilatency::DeviceNetwork::INetwork& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode getVersion(std::string& result) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		Antilatency::InterfaceContract::ExceptionCode setLogLevel(Antilatency::DeviceNetwork::LogLevel level) {
			return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
		}
		*/
		struct ILibrary : Antilatency::InterfaceContract::IInterface {
			struct VMT : Antilatency::InterfaceContract::IInterface::VMT {
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL createFilter(Antilatency::DeviceNetwork::IDeviceFilter& result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL createNetwork(Antilatency::DeviceNetwork::IDeviceFilter::VMT* deviceFilter, Antilatency::DeviceNetwork::INetwork& result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getVersion(Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) = 0;
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setLogLevel(Antilatency::DeviceNetwork::LogLevel level) = 0;
				static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
					return Antilatency::InterfaceContract::InterfaceID{0x70680993,0x4a03,0x46a1,{0x97,0x1f,0x80,0xec,0xae,0xc6,0x93,0xec}};
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
			Antilatency::InterfaceContract::ExceptionCode createFilter(Antilatency::DeviceNetwork::IDeviceFilter& result) {
				return (reinterpret_cast<VMT*>(this->_object))->createFilter(result);
			}
			Antilatency::InterfaceContract::ExceptionCode createNetwork(Antilatency::DeviceNetwork::IDeviceFilter deviceFilter, Antilatency::DeviceNetwork::INetwork& result) {
				return (reinterpret_cast<VMT*>(this->_object))->createNetwork(deviceFilter.detach(), result);
			}
			Antilatency::InterfaceContract::ExceptionCode getVersion(std::string& result) {
				auto resultMarshaler = Antilatency::InterfaceContract::Details::ArrayOutMarshaler::create(result);
				return (reinterpret_cast<VMT*>(this->_object))->getVersion(resultMarshaler);
			}
			Antilatency::InterfaceContract::ExceptionCode setLogLevel(Antilatency::DeviceNetwork::LogLevel level) {
				return (reinterpret_cast<VMT*>(this->_object))->setLogLevel(level);
			}
		};
	} //namespace DeviceNetwork
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::DeviceNetwork::ILibrary, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::InterfaceContract::IInterface, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL createFilter(Antilatency::DeviceNetwork::IDeviceFilter& result) {
					auto exceptionCode_ = this->_object->createFilter(result);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL createNetwork(Antilatency::DeviceNetwork::IDeviceFilter::VMT* deviceFilter, Antilatency::DeviceNetwork::INetwork& result) {
					Antilatency::DeviceNetwork::IDeviceFilter deviceFilterMarshaler;
					deviceFilterMarshaler.attach(deviceFilter);
					auto exceptionCode_ = this->_object->createNetwork(deviceFilterMarshaler, result);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getVersion(Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) {
					std::string resultMarshaler;
					auto exceptionCode_ = this->_object->getVersion(resultMarshaler);
					result = resultMarshaler;
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setLogLevel(Antilatency::DeviceNetwork::LogLevel level) {
					auto exceptionCode_ = this->_object->setLogLevel(level);
					return exceptionCode_;
				}
			};
		} //namespace Details
	} //namespace InterfaceContract
} //namespace Antilatency

namespace Antilatency {
	namespace DeviceNetwork {
		namespace Constants {
			const Antilatency::DeviceNetwork::UsbDeviceFilter AllUsbDevices = ([](){
				Antilatency::DeviceNetwork::UsbDeviceFilter result;
				(*reinterpret_cast<std::array<uint8_t, 6>*>(&result)) = {{55U, 50U, 0U, 0U, 0U, 240U}};
				return result;
			})();
			static constexpr const char* AllIpDevicesIp = "0.0.0.0";
			static constexpr const char* AllIpDevicesMask = "0.0.0.0";
			constexpr uint16_t UsbAllDeviceMask = 61440U;
			constexpr uint16_t UsbOneDeviceMask = 65535U;
		} //namespace Constants
	} //namespace DeviceNetwork
} //namespace Antilatency


#ifdef _MSC_VER
#pragma warning(pop)
#endif
