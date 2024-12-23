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
#include <Antilatency.Math.h>
#include <Antilatency.DeviceNetwork.h>
#include <Antilatency.Alt.Environment.h>
#include <cstdint>
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4946)
#pragma warning(disable: 4265)
#endif
namespace Antilatency {
	namespace Alt {
		namespace Tracking {
			enum class Stage : int32_t {
				InertialDataInitialization = 0x0,
				Tracking3Dof = 0x1,
				Tracking6Dof = 0x2,
				TrackingBlind6Dof = 0x3
			};
		} //namespace Tracking
	} //namespace Alt
} //namespace Antilatency
namespace Antilatency {
	inline const char* enumToString(const Antilatency::Alt::Tracking::Stage& x) {
		switch (x) {
			case Antilatency::Alt::Tracking::Stage::InertialDataInitialization: return "InertialDataInitialization";
			case Antilatency::Alt::Tracking::Stage::Tracking3Dof: return "Tracking3Dof";
			case Antilatency::Alt::Tracking::Stage::Tracking6Dof: return "Tracking6Dof";
			case Antilatency::Alt::Tracking::Stage::TrackingBlind6Dof: return "TrackingBlind6Dof";
		}
		return "";
	}
} //namespace Antilatency

namespace Antilatency {
	namespace Alt {
		namespace Tracking {
			struct Stability {
				Antilatency::Alt::Tracking::Stage stage;
				float value;
			};
		} //namespace Tracking
	} //namespace Alt
} //namespace Antilatency

namespace Antilatency {
	namespace Alt {
		namespace Tracking {
			struct State {
				Antilatency::Math::floatP3Q pose;
				Antilatency::Math::float3 velocity;
				Antilatency::Math::float3 localAngularVelocity;
				Antilatency::Alt::Tracking::Stability stability;
			};
		} //namespace Tracking
	} //namespace Alt
} //namespace Antilatency

namespace Antilatency {
	namespace Alt {
		namespace Tracking {
			/* copy and paste this to implementer
			Antilatency::InterfaceContract::ExceptionCode getExtrapolatedState(Antilatency::Math::floatP3Q placement, float deltaTime, Antilatency::Alt::Tracking::State& result) {
				return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
			}
			Antilatency::InterfaceContract::ExceptionCode getState(float angularVelocityAvgTimeInSeconds, Antilatency::Alt::Tracking::State& result) {
				return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
			}
			*/
			struct ITrackingCotask : Antilatency::DeviceNetwork::ICotask {
				struct VMT : Antilatency::DeviceNetwork::ICotask::VMT {
					virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getExtrapolatedState(Antilatency::Math::floatP3Q placement, float deltaTime, Antilatency::Alt::Tracking::State& result) = 0;
					virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getState(float angularVelocityAvgTimeInSeconds, Antilatency::Alt::Tracking::State& result) = 0;
					static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
						return Antilatency::InterfaceContract::InterfaceID{0x7f8b603c,0xfa91,0x4168,{0x92,0xb7,0xaf,0x16,0x44,0xd0,0x87,0xdb}};
					}
				private:
					~VMT() = delete;
				};
				
				static bool isInterfaceSupported(const Antilatency::InterfaceContract::InterfaceID& id) {
				    if (id == ITrackingCotask::VMT::ID()) {
				        return true;
				    }
				    return Antilatency::DeviceNetwork::ICotask::isInterfaceSupported(id);
				}
				ITrackingCotask() = default;
				ITrackingCotask(std::nullptr_t) {}
				explicit ITrackingCotask(VMT* pointer) : Antilatency::DeviceNetwork::ICotask(pointer) {}
				template<typename T, typename = typename std::enable_if<std::is_base_of<ITrackingCotask, T>::value>::type>
				ITrackingCotask& operator = (const T& other) {
				    Antilatency::DeviceNetwork::ICotask::operator=(other);
				    return *this;
				}
				template<class Implementer, class ... TArgs>
				static ITrackingCotask create(TArgs&&... args) {
				    return *new Implementer(std::forward<TArgs>(args)...);
				}
				void attach(VMT* other) ANTILATENCY_NOEXCEPT {
				    Antilatency::DeviceNetwork::ICotask::attach(other);
				}
				VMT* detach() ANTILATENCY_NOEXCEPT {
				    return reinterpret_cast<VMT*>(Antilatency::DeviceNetwork::ICotask::detach());
				}
				Antilatency::InterfaceContract::ExceptionCode getExtrapolatedState(Antilatency::Math::floatP3Q placement, float deltaTime, Antilatency::Alt::Tracking::State& result) {
					return (reinterpret_cast<VMT*>(this->_object))->getExtrapolatedState(placement, deltaTime, result);
				}
				Antilatency::InterfaceContract::ExceptionCode getState(float angularVelocityAvgTimeInSeconds, Antilatency::Alt::Tracking::State& result) {
					return (reinterpret_cast<VMT*>(this->_object))->getState(angularVelocityAvgTimeInSeconds, result);
				}
			};
		} //namespace Tracking
	} //namespace Alt
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::Alt::Tracking::ITrackingCotask, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::DeviceNetwork::ICotask, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getExtrapolatedState(Antilatency::Math::floatP3Q placement, float deltaTime, Antilatency::Alt::Tracking::State& result) {
					auto exceptionCode_ = this->_object->getExtrapolatedState(placement, deltaTime, result);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getState(float angularVelocityAvgTimeInSeconds, Antilatency::Alt::Tracking::State& result) {
					auto exceptionCode_ = this->_object->getState(angularVelocityAvgTimeInSeconds, result);
					return exceptionCode_;
				}
			};
		} //namespace Details
	} //namespace InterfaceContract
} //namespace Antilatency

namespace Antilatency {
	namespace Alt {
		namespace Tracking {
			/* copy and paste this to implementer
			Antilatency::InterfaceContract::ExceptionCode startTask(Antilatency::DeviceNetwork::INetwork network, Antilatency::DeviceNetwork::NodeHandle node, Antilatency::Alt::Environment::IEnvironment environment, Antilatency::Alt::Tracking::ITrackingCotask& result) {
				return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
			}
			*/
			struct ITrackingCotaskConstructor : Antilatency::DeviceNetwork::ICotaskConstructor {
				struct VMT : Antilatency::DeviceNetwork::ICotaskConstructor::VMT {
					virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL startTask(Antilatency::DeviceNetwork::INetwork::VMT* network, Antilatency::DeviceNetwork::NodeHandle node, Antilatency::Alt::Environment::IEnvironment::VMT* environment, Antilatency::Alt::Tracking::ITrackingCotask& result) = 0;
					static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
						return Antilatency::InterfaceContract::InterfaceID{0x009ebfe1,0xf85c,0x4638,{0xbe,0x9d,0xaf,0x79,0x90,0xa8,0xcd,0x04}};
					}
				private:
					~VMT() = delete;
				};
				
				static bool isInterfaceSupported(const Antilatency::InterfaceContract::InterfaceID& id) {
				    if (id == ITrackingCotaskConstructor::VMT::ID()) {
				        return true;
				    }
				    return Antilatency::DeviceNetwork::ICotaskConstructor::isInterfaceSupported(id);
				}
				ITrackingCotaskConstructor() = default;
				ITrackingCotaskConstructor(std::nullptr_t) {}
				explicit ITrackingCotaskConstructor(VMT* pointer) : Antilatency::DeviceNetwork::ICotaskConstructor(pointer) {}
				template<typename T, typename = typename std::enable_if<std::is_base_of<ITrackingCotaskConstructor, T>::value>::type>
				ITrackingCotaskConstructor& operator = (const T& other) {
				    Antilatency::DeviceNetwork::ICotaskConstructor::operator=(other);
				    return *this;
				}
				template<class Implementer, class ... TArgs>
				static ITrackingCotaskConstructor create(TArgs&&... args) {
				    return *new Implementer(std::forward<TArgs>(args)...);
				}
				void attach(VMT* other) ANTILATENCY_NOEXCEPT {
				    Antilatency::DeviceNetwork::ICotaskConstructor::attach(other);
				}
				VMT* detach() ANTILATENCY_NOEXCEPT {
				    return reinterpret_cast<VMT*>(Antilatency::DeviceNetwork::ICotaskConstructor::detach());
				}
				Antilatency::InterfaceContract::ExceptionCode startTask(Antilatency::DeviceNetwork::INetwork network, Antilatency::DeviceNetwork::NodeHandle node, Antilatency::Alt::Environment::IEnvironment environment, Antilatency::Alt::Tracking::ITrackingCotask& result) {
					return (reinterpret_cast<VMT*>(this->_object))->startTask(network.detach(), node, environment.detach(), result);
				}
			};
		} //namespace Tracking
	} //namespace Alt
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::Alt::Tracking::ITrackingCotaskConstructor, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::DeviceNetwork::ICotaskConstructor, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL startTask(Antilatency::DeviceNetwork::INetwork::VMT* network, Antilatency::DeviceNetwork::NodeHandle node, Antilatency::Alt::Environment::IEnvironment::VMT* environment, Antilatency::Alt::Tracking::ITrackingCotask& result) {
					Antilatency::DeviceNetwork::INetwork networkMarshaler;
					networkMarshaler.attach(network);
					Antilatency::Alt::Environment::IEnvironment environmentMarshaler;
					environmentMarshaler.attach(environment);
					auto exceptionCode_ = this->_object->startTask(networkMarshaler, node, environmentMarshaler, result);
					return exceptionCode_;
				}
			};
		} //namespace Details
	} //namespace InterfaceContract
} //namespace Antilatency

namespace Antilatency {
	namespace Alt {
		namespace Tracking {
			struct OpticRay {
				Antilatency::Math::float2 middleSpacePoint;
				Antilatency::Math::float2x3 middleSpacePointDerivativeByLocalPosition;
				Antilatency::Math::float3 direction;
				float power;
			};
		} //namespace Tracking
	} //namespace Alt
} //namespace Antilatency

namespace Antilatency {
	namespace Alt {
		namespace Tracking {
			struct InertialLeap {
				float timeLeap;
				Antilatency::Math::float3 positionLeap;
				Antilatency::Math::float3 velocityLeap;
				Antilatency::Math::floatQ rotationLeap;
				Antilatency::Math::float3x3 positionLeapByAcceleration;
				Antilatency::Math::float3x3 velocityLeapByAcceleration;
			};
		} //namespace Tracking
	} //namespace Alt
} //namespace Antilatency

namespace Antilatency {
	namespace Alt {
		namespace Tracking {
			/* copy and paste this to implementer
			Antilatency::InterfaceContract::ExceptionCode onTrackingFrame(const std::vector<Antilatency::Alt::Tracking::OpticRay>& rays, Antilatency::Math::float3 inertialUp, Antilatency::Alt::Tracking::InertialLeap inertialLeap, Antilatency::InterfaceContract::LongBool accelerometerOverflowOccured, Antilatency::InterfaceContract::LongBool gyroscopeOverflowOccured) {
				return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
			}
			Antilatency::InterfaceContract::ExceptionCode onIncompleteLeap(Antilatency::Alt::Tracking::InertialLeap leap) {
				return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
			}
			Antilatency::InterfaceContract::ExceptionCode onAdnFinalize() {
				return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
			}
			*/
			struct ITrackingDataCallback : Antilatency::InterfaceContract::IInterface {
				struct VMT : Antilatency::InterfaceContract::IInterface::VMT {
					virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL onTrackingFrame(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate rays, Antilatency::Math::float3 inertialUp, Antilatency::Alt::Tracking::InertialLeap inertialLeap, Antilatency::InterfaceContract::LongBool accelerometerOverflowOccured, Antilatency::InterfaceContract::LongBool gyroscopeOverflowOccured) = 0;
					virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL onIncompleteLeap(Antilatency::Alt::Tracking::InertialLeap leap) = 0;
					virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL onAdnFinalize() = 0;
					static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
						return Antilatency::InterfaceContract::InterfaceID{0x8f2dab91,0x8ba5,0x40a3,{0xae,0x73,0xe3,0xf8,0xef,0x1f,0xb8,0x76}};
					}
				private:
					~VMT() = delete;
				};
				
				static bool isInterfaceSupported(const Antilatency::InterfaceContract::InterfaceID& id) {
				    if (id == ITrackingDataCallback::VMT::ID()) {
				        return true;
				    }
				    return Antilatency::InterfaceContract::IInterface::isInterfaceSupported(id);
				}
				ITrackingDataCallback() = default;
				ITrackingDataCallback(std::nullptr_t) {}
				explicit ITrackingDataCallback(VMT* pointer) : Antilatency::InterfaceContract::IInterface(pointer) {}
				template<typename T, typename = typename std::enable_if<std::is_base_of<ITrackingDataCallback, T>::value>::type>
				ITrackingDataCallback& operator = (const T& other) {
				    Antilatency::InterfaceContract::IInterface::operator=(other);
				    return *this;
				}
				template<class Implementer, class ... TArgs>
				static ITrackingDataCallback create(TArgs&&... args) {
				    return *new Implementer(std::forward<TArgs>(args)...);
				}
				void attach(VMT* other) ANTILATENCY_NOEXCEPT {
				    Antilatency::InterfaceContract::IInterface::attach(other);
				}
				VMT* detach() ANTILATENCY_NOEXCEPT {
				    return reinterpret_cast<VMT*>(Antilatency::InterfaceContract::IInterface::detach());
				}
				Antilatency::InterfaceContract::ExceptionCode onTrackingFrame(const std::vector<Antilatency::Alt::Tracking::OpticRay>& rays, Antilatency::Math::float3 inertialUp, Antilatency::Alt::Tracking::InertialLeap inertialLeap, Antilatency::InterfaceContract::LongBool accelerometerOverflowOccured, Antilatency::InterfaceContract::LongBool gyroscopeOverflowOccured) {
					auto raysMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(rays);
					return (reinterpret_cast<VMT*>(this->_object))->onTrackingFrame(raysMarshaler, inertialUp, inertialLeap, accelerometerOverflowOccured, gyroscopeOverflowOccured);
				}
				Antilatency::InterfaceContract::ExceptionCode onIncompleteLeap(Antilatency::Alt::Tracking::InertialLeap leap) {
					return (reinterpret_cast<VMT*>(this->_object))->onIncompleteLeap(leap);
				}
				Antilatency::InterfaceContract::ExceptionCode onAdnFinalize() {
					return (reinterpret_cast<VMT*>(this->_object))->onAdnFinalize();
				}
			};
		} //namespace Tracking
	} //namespace Alt
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::Alt::Tracking::ITrackingDataCallback, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::InterfaceContract::IInterface, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL onTrackingFrame(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate rays, Antilatency::Math::float3 inertialUp, Antilatency::Alt::Tracking::InertialLeap inertialLeap, Antilatency::InterfaceContract::LongBool accelerometerOverflowOccured, Antilatency::InterfaceContract::LongBool gyroscopeOverflowOccured) {
					auto exceptionCode_ = this->_object->onTrackingFrame(rays, inertialUp, inertialLeap, accelerometerOverflowOccured, gyroscopeOverflowOccured);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL onIncompleteLeap(Antilatency::Alt::Tracking::InertialLeap leap) {
					auto exceptionCode_ = this->_object->onIncompleteLeap(leap);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL onAdnFinalize() {
					auto exceptionCode_ = this->_object->onAdnFinalize();
					return exceptionCode_;
				}
			};
		} //namespace Details
	} //namespace InterfaceContract
} //namespace Antilatency

namespace Antilatency {
	namespace Alt {
		namespace Tracking {
			/* copy and paste this to implementer
			Antilatency::InterfaceContract::ExceptionCode getOpticsToBodyRotation(Antilatency::Math::floatQ& result) {
				return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
			}
			Antilatency::InterfaceContract::ExceptionCode setExposure(uint32_t exposure) {
				return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
			}
			*/
			struct ITrackingDataCotask : Antilatency::DeviceNetwork::ICotask {
				struct VMT : Antilatency::DeviceNetwork::ICotask::VMT {
					virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getOpticsToBodyRotation(Antilatency::Math::floatQ& result) = 0;
					virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setExposure(uint32_t exposure) = 0;
					static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
						return Antilatency::InterfaceContract::InterfaceID{0x91b0a5be,0xa9c7,0x4d29,{0xa0,0x3a,0x44,0xff,0xf8,0xe9,0x1c,0x68}};
					}
				private:
					~VMT() = delete;
				};
				
				static bool isInterfaceSupported(const Antilatency::InterfaceContract::InterfaceID& id) {
				    if (id == ITrackingDataCotask::VMT::ID()) {
				        return true;
				    }
				    return Antilatency::DeviceNetwork::ICotask::isInterfaceSupported(id);
				}
				ITrackingDataCotask() = default;
				ITrackingDataCotask(std::nullptr_t) {}
				explicit ITrackingDataCotask(VMT* pointer) : Antilatency::DeviceNetwork::ICotask(pointer) {}
				template<typename T, typename = typename std::enable_if<std::is_base_of<ITrackingDataCotask, T>::value>::type>
				ITrackingDataCotask& operator = (const T& other) {
				    Antilatency::DeviceNetwork::ICotask::operator=(other);
				    return *this;
				}
				template<class Implementer, class ... TArgs>
				static ITrackingDataCotask create(TArgs&&... args) {
				    return *new Implementer(std::forward<TArgs>(args)...);
				}
				void attach(VMT* other) ANTILATENCY_NOEXCEPT {
				    Antilatency::DeviceNetwork::ICotask::attach(other);
				}
				VMT* detach() ANTILATENCY_NOEXCEPT {
				    return reinterpret_cast<VMT*>(Antilatency::DeviceNetwork::ICotask::detach());
				}
				Antilatency::InterfaceContract::ExceptionCode getOpticsToBodyRotation(Antilatency::Math::floatQ& result) {
					return (reinterpret_cast<VMT*>(this->_object))->getOpticsToBodyRotation(result);
				}
				Antilatency::InterfaceContract::ExceptionCode setExposure(uint32_t exposure) {
					return (reinterpret_cast<VMT*>(this->_object))->setExposure(exposure);
				}
			};
		} //namespace Tracking
	} //namespace Alt
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::Alt::Tracking::ITrackingDataCotask, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::DeviceNetwork::ICotask, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getOpticsToBodyRotation(Antilatency::Math::floatQ& result) {
					auto exceptionCode_ = this->_object->getOpticsToBodyRotation(result);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setExposure(uint32_t exposure) {
					auto exceptionCode_ = this->_object->setExposure(exposure);
					return exceptionCode_;
				}
			};
		} //namespace Details
	} //namespace InterfaceContract
} //namespace Antilatency

namespace Antilatency {
	namespace Alt {
		namespace Tracking {
			/* copy and paste this to implementer
			Antilatency::InterfaceContract::ExceptionCode startTask(Antilatency::DeviceNetwork::INetwork network, Antilatency::DeviceNetwork::NodeHandle node, Antilatency::Alt::Tracking::ITrackingDataCallback callback, Antilatency::Alt::Tracking::ITrackingDataCotask& result) {
				return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
			}
			*/
			struct ITrackingDataCotaskConstructor : Antilatency::DeviceNetwork::ICotaskConstructor {
				struct VMT : Antilatency::DeviceNetwork::ICotaskConstructor::VMT {
					virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL startTask(Antilatency::DeviceNetwork::INetwork::VMT* network, Antilatency::DeviceNetwork::NodeHandle node, Antilatency::Alt::Tracking::ITrackingDataCallback::VMT* callback, Antilatency::Alt::Tracking::ITrackingDataCotask& result) = 0;
					static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
						return Antilatency::InterfaceContract::InterfaceID{0xb3032673,0x093a,0x47c5,{0xa0,0x49,0x31,0x57,0x6d,0xcb,0xe8,0x94}};
					}
				private:
					~VMT() = delete;
				};
				
				static bool isInterfaceSupported(const Antilatency::InterfaceContract::InterfaceID& id) {
				    if (id == ITrackingDataCotaskConstructor::VMT::ID()) {
				        return true;
				    }
				    return Antilatency::DeviceNetwork::ICotaskConstructor::isInterfaceSupported(id);
				}
				ITrackingDataCotaskConstructor() = default;
				ITrackingDataCotaskConstructor(std::nullptr_t) {}
				explicit ITrackingDataCotaskConstructor(VMT* pointer) : Antilatency::DeviceNetwork::ICotaskConstructor(pointer) {}
				template<typename T, typename = typename std::enable_if<std::is_base_of<ITrackingDataCotaskConstructor, T>::value>::type>
				ITrackingDataCotaskConstructor& operator = (const T& other) {
				    Antilatency::DeviceNetwork::ICotaskConstructor::operator=(other);
				    return *this;
				}
				template<class Implementer, class ... TArgs>
				static ITrackingDataCotaskConstructor create(TArgs&&... args) {
				    return *new Implementer(std::forward<TArgs>(args)...);
				}
				void attach(VMT* other) ANTILATENCY_NOEXCEPT {
				    Antilatency::DeviceNetwork::ICotaskConstructor::attach(other);
				}
				VMT* detach() ANTILATENCY_NOEXCEPT {
				    return reinterpret_cast<VMT*>(Antilatency::DeviceNetwork::ICotaskConstructor::detach());
				}
				Antilatency::InterfaceContract::ExceptionCode startTask(Antilatency::DeviceNetwork::INetwork network, Antilatency::DeviceNetwork::NodeHandle node, Antilatency::Alt::Tracking::ITrackingDataCallback callback, Antilatency::Alt::Tracking::ITrackingDataCotask& result) {
					return (reinterpret_cast<VMT*>(this->_object))->startTask(network.detach(), node, callback.detach(), result);
				}
			};
		} //namespace Tracking
	} //namespace Alt
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::Alt::Tracking::ITrackingDataCotaskConstructor, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::DeviceNetwork::ICotaskConstructor, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL startTask(Antilatency::DeviceNetwork::INetwork::VMT* network, Antilatency::DeviceNetwork::NodeHandle node, Antilatency::Alt::Tracking::ITrackingDataCallback::VMT* callback, Antilatency::Alt::Tracking::ITrackingDataCotask& result) {
					Antilatency::DeviceNetwork::INetwork networkMarshaler;
					networkMarshaler.attach(network);
					Antilatency::Alt::Tracking::ITrackingDataCallback callbackMarshaler;
					callbackMarshaler.attach(callback);
					auto exceptionCode_ = this->_object->startTask(networkMarshaler, node, callbackMarshaler, result);
					return exceptionCode_;
				}
			};
		} //namespace Details
	} //namespace InterfaceContract
} //namespace Antilatency

namespace Antilatency {
	namespace Alt {
		namespace Tracking {
			/* copy and paste this to implementer
			Antilatency::InterfaceContract::ExceptionCode createPlacement(const std::string& code, Antilatency::Math::floatP3Q& result) {
				return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
			}
			Antilatency::InterfaceContract::ExceptionCode encodePlacement(Antilatency::Math::float3 position, Antilatency::Math::float3 rotation, std::string& result) {
				return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
			}
			Antilatency::InterfaceContract::ExceptionCode createTrackingCotaskConstructor(Antilatency::Alt::Tracking::ITrackingCotaskConstructor& result) {
				return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
			}
			Antilatency::InterfaceContract::ExceptionCode createTrackingDataCotaskConstructor(Antilatency::Alt::Tracking::ITrackingDataCotaskConstructor& result) {
				return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
			}
			*/
			struct ILibrary : Antilatency::InterfaceContract::IInterface {
				struct VMT : Antilatency::InterfaceContract::IInterface::VMT {
					virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL createPlacement(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate code, Antilatency::Math::floatP3Q& result) = 0;
					virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL encodePlacement(Antilatency::Math::float3 position, Antilatency::Math::float3 rotation, Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) = 0;
					virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL createTrackingCotaskConstructor(Antilatency::Alt::Tracking::ITrackingCotaskConstructor& result) = 0;
					virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL createTrackingDataCotaskConstructor(Antilatency::Alt::Tracking::ITrackingDataCotaskConstructor& result) = 0;
					static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
						return Antilatency::InterfaceContract::InterfaceID{0xad4034ee,0xb77a,0x4e1f,{0xa5,0x5a,0xc4,0xb3,0x0a,0x46,0x9a,0x24}};
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
				Antilatency::InterfaceContract::ExceptionCode createPlacement(const std::string& code, Antilatency::Math::floatP3Q& result) {
					auto codeMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(code);
					return (reinterpret_cast<VMT*>(this->_object))->createPlacement(codeMarshaler, result);
				}
				Antilatency::InterfaceContract::ExceptionCode encodePlacement(Antilatency::Math::float3 position, Antilatency::Math::float3 rotation, std::string& result) {
					auto resultMarshaler = Antilatency::InterfaceContract::Details::ArrayOutMarshaler::create(result);
					return (reinterpret_cast<VMT*>(this->_object))->encodePlacement(position, rotation, resultMarshaler);
				}
				Antilatency::InterfaceContract::ExceptionCode createTrackingCotaskConstructor(Antilatency::Alt::Tracking::ITrackingCotaskConstructor& result) {
					return (reinterpret_cast<VMT*>(this->_object))->createTrackingCotaskConstructor(result);
				}
				Antilatency::InterfaceContract::ExceptionCode createTrackingDataCotaskConstructor(Antilatency::Alt::Tracking::ITrackingDataCotaskConstructor& result) {
					return (reinterpret_cast<VMT*>(this->_object))->createTrackingDataCotaskConstructor(result);
				}
			};
		} //namespace Tracking
	} //namespace Alt
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::Alt::Tracking::ILibrary, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::InterfaceContract::IInterface, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL createPlacement(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate code, Antilatency::Math::floatP3Q& result) {
					auto exceptionCode_ = this->_object->createPlacement(code, result);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL encodePlacement(Antilatency::Math::float3 position, Antilatency::Math::float3 rotation, Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) {
					std::string resultMarshaler;
					auto exceptionCode_ = this->_object->encodePlacement(position, rotation, resultMarshaler);
					result = resultMarshaler;
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL createTrackingCotaskConstructor(Antilatency::Alt::Tracking::ITrackingCotaskConstructor& result) {
					auto exceptionCode_ = this->_object->createTrackingCotaskConstructor(result);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL createTrackingDataCotaskConstructor(Antilatency::Alt::Tracking::ITrackingDataCotaskConstructor& result) {
					auto exceptionCode_ = this->_object->createTrackingDataCotaskConstructor(result);
					return exceptionCode_;
				}
			};
		} //namespace Details
	} //namespace InterfaceContract
} //namespace Antilatency

namespace Antilatency {
	namespace Alt {
		namespace Tracking {
			namespace Constants {
				const Antilatency::Math::float3 InitialPositionFor3Dof = ([](){
					Antilatency::Math::float3 result;
					(*reinterpret_cast<std::array<uint8_t, 12>*>(&result)) = {{0U, 0U, 0U, 0U, 61U, 10U, 215U, 63U, 0U, 0U, 0U, 0U}};
					return result;
				})();
				constexpr float DefaultAngularVelocityAvgTime = 0.016f;
			} //namespace Constants
		} //namespace Tracking
	} //namespace Alt
} //namespace Antilatency


#ifdef _MSC_VER
#pragma warning(pop)
#endif
