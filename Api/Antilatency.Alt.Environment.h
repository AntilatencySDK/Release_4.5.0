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
#include <Antilatency.Math.h>
#include <cstdint>
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4946)
#pragma warning(disable: 4265)
#endif
namespace Antilatency {
	namespace Alt {
		namespace Environment {
			enum class MarkerIndex : uint32_t {
				MaximumValidMarkerIndex = 0xFFFFFFF0,
				Invalid = 0xFFFFFFFE,
				Unknown = 0xFFFFFFFF
			};
			ANTILATENCY_ENUM_INTEGER_BEHAVIOUR_UNSIGNED(MarkerIndex,uint32_t)
		} //namespace Environment
	} //namespace Alt
} //namespace Antilatency
namespace Antilatency {
	inline const char* enumToString(const Antilatency::Alt::Environment::MarkerIndex& x) {
		switch (x) {
			case Antilatency::Alt::Environment::MarkerIndex::MaximumValidMarkerIndex: return "MaximumValidMarkerIndex";
			case Antilatency::Alt::Environment::MarkerIndex::Invalid: return "Invalid";
			case Antilatency::Alt::Environment::MarkerIndex::Unknown: return "Unknown";
		}
		return "";
	}
} //namespace Antilatency

namespace Antilatency {
	namespace Alt {
		namespace Environment {
			/* copy and paste this to implementer
			Antilatency::InterfaceContract::LongBool isMutable() {
				throw std::logic_error{"Method IEnvironment.isMutable() is not implemented."};
			}
			std::vector<Antilatency::Math::float3> getMarkers() {
				throw std::logic_error{"Method IEnvironment.getMarkers() is not implemented."};
			}
			Antilatency::InterfaceContract::LongBool filterRay(Antilatency::Math::float3 up, Antilatency::Math::float3 ray) {
				throw std::logic_error{"Method IEnvironment.filterRay() is not implemented."};
			}
			Antilatency::InterfaceContract::LongBool match(const std::vector<Antilatency::Math::float3>& raysUpSpace, std::vector<Antilatency::Alt::Environment::MarkerIndex>& markersIndices, Antilatency::Math::floatP3Q& poseOfUpSpace) {
				throw std::logic_error{"Method IEnvironment.match() is not implemented."};
			}
			std::vector<Antilatency::Alt::Environment::MarkerIndex> matchByPosition(const std::vector<Antilatency::Math::float3>& rays, Antilatency::Math::float3 origin) {
				throw std::logic_error{"Method IEnvironment.matchByPosition() is not implemented."};
			}
			*/
			struct IEnvironment : Antilatency::InterfaceContract::IInterface {
				struct VMT : Antilatency::InterfaceContract::IInterface::VMT {
					virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL isMutable(Antilatency::InterfaceContract::LongBool& result) = 0;
					virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getMarkers(Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) = 0;
					virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL filterRay(Antilatency::Math::float3 up, Antilatency::Math::float3 ray, Antilatency::InterfaceContract::LongBool& result) = 0;
					virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL match(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate raysUpSpace, Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate markersIndices, Antilatency::Math::floatP3Q& poseOfUpSpace, Antilatency::InterfaceContract::LongBool& result) = 0;
					virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL matchByPosition(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate rays, Antilatency::Math::float3 origin, Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) = 0;
					static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
						return Antilatency::InterfaceContract::InterfaceID{0xc257c858,0xf296,0x43b7,{0xb6,0xb5,0xc1,0x4b,0x9a,0xfb,0x1a,0x13}};
					}
				private:
					~VMT() = delete;
				};
				
				static bool isInterfaceSupported(const Antilatency::InterfaceContract::InterfaceID& id) {
				    if (id == IEnvironment::VMT::ID()) {
				        return true;
				    }
				    return Antilatency::InterfaceContract::IInterface::isInterfaceSupported(id);
				}
				IEnvironment() = default;
				IEnvironment(std::nullptr_t) {}
				explicit IEnvironment(VMT* pointer) : Antilatency::InterfaceContract::IInterface(pointer) {}
				template<typename T, typename = typename std::enable_if<std::is_base_of<IEnvironment, T>::value>::type>
				IEnvironment& operator = (const T& other) {
				    Antilatency::InterfaceContract::IInterface::operator=(other);
				    return *this;
				}
				template<class Implementer, class ... TArgs>
				static IEnvironment create(TArgs&&... args) {
				    return *new Implementer(std::forward<TArgs>(args)...);
				}
				void attach(VMT* other) ANTILATENCY_NOEXCEPT {
				    Antilatency::InterfaceContract::IInterface::attach(other);
				}
				VMT* detach() ANTILATENCY_NOEXCEPT {
				    return reinterpret_cast<VMT*>(Antilatency::InterfaceContract::IInterface::detach());
				}
				Antilatency::InterfaceContract::LongBool isMutable() {
					Antilatency::InterfaceContract::LongBool result;
					handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->isMutable(result));
					return result;
				}
				std::vector<Antilatency::Math::float3> getMarkers() {
					std::vector<Antilatency::Math::float3> result;
					auto resultMarshaler = Antilatency::InterfaceContract::Details::ArrayOutMarshaler::create(result);
					handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->getMarkers(resultMarshaler));
					return result;
				}
				Antilatency::InterfaceContract::LongBool filterRay(Antilatency::Math::float3 up, Antilatency::Math::float3 ray) {
					Antilatency::InterfaceContract::LongBool result;
					handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->filterRay(up, ray, result));
					return result;
				}
				/// <param name = "raysUpSpace">
				/// rays directions. Normalized
				/// </param>
				Antilatency::InterfaceContract::LongBool match(const std::vector<Antilatency::Math::float3>& raysUpSpace, std::vector<Antilatency::Alt::Environment::MarkerIndex>& markersIndices, Antilatency::Math::floatP3Q& poseOfUpSpace) {
					Antilatency::InterfaceContract::LongBool result;
					auto raysUpSpaceMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(raysUpSpace);
					auto markersIndicesMarshaler = Antilatency::InterfaceContract::Details::ArrayOutMarshaler::create(markersIndices);
					handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->match(raysUpSpaceMarshaler, markersIndicesMarshaler, poseOfUpSpace, result));
					return result;
				}
				/// <summary>Match rays to markers by known position</summary>
				/// <param name = "rays">
				/// rays directions world space. Normalized
				/// </param>
				/// <param name = "origin">
				/// Common rays origin world space
				/// </param>
				/// <returns>Indices of corresponding markers. result.size == rays.size</returns>
				std::vector<Antilatency::Alt::Environment::MarkerIndex> matchByPosition(const std::vector<Antilatency::Math::float3>& rays, Antilatency::Math::float3 origin) {
					std::vector<Antilatency::Alt::Environment::MarkerIndex> result;
					auto raysMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(rays);
					auto resultMarshaler = Antilatency::InterfaceContract::Details::ArrayOutMarshaler::create(result);
					handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->matchByPosition(raysMarshaler, origin, resultMarshaler));
					return result;
				}
			};
		} //namespace Environment
	} //namespace Alt
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::Alt::Environment::IEnvironment, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::InterfaceContract::IInterface, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL isMutable(Antilatency::InterfaceContract::LongBool& result) {
					try {
						result = this->_object->isMutable();
					}
					catch (...) {
						return Antilatency::InterfaceContract::handleRemapException(this->_object);
					}
					return Antilatency::InterfaceContract::ExceptionCode::Ok;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getMarkers(Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) {
					try {
						result = this->_object->getMarkers();
					}
					catch (...) {
						return Antilatency::InterfaceContract::handleRemapException(this->_object);
					}
					return Antilatency::InterfaceContract::ExceptionCode::Ok;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL filterRay(Antilatency::Math::float3 up, Antilatency::Math::float3 ray, Antilatency::InterfaceContract::LongBool& result) {
					try {
						result = this->_object->filterRay(up, ray);
					}
					catch (...) {
						return Antilatency::InterfaceContract::handleRemapException(this->_object);
					}
					return Antilatency::InterfaceContract::ExceptionCode::Ok;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL match(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate raysUpSpace, Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate markersIndices, Antilatency::Math::floatP3Q& poseOfUpSpace, Antilatency::InterfaceContract::LongBool& result) {
					try {
						std::vector<Antilatency::Alt::Environment::MarkerIndex> markersIndicesMarshaler;
						result = this->_object->match(raysUpSpace, markersIndicesMarshaler, poseOfUpSpace);
						markersIndices = markersIndicesMarshaler;
					}
					catch (...) {
						return Antilatency::InterfaceContract::handleRemapException(this->_object);
					}
					return Antilatency::InterfaceContract::ExceptionCode::Ok;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL matchByPosition(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate rays, Antilatency::Math::float3 origin, Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) {
					try {
						result = this->_object->matchByPosition(rays, origin);
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
	namespace Alt {
		namespace Environment {
			/* copy and paste this to implementer
			Antilatency::Alt::Environment::IEnvironment createEnvironment(const std::string& data) {
				throw std::logic_error{"Method IEnvironmentConstructor.createEnvironment() is not implemented."};
			}
			*/
			struct IEnvironmentConstructor : Antilatency::InterfaceContract::IInterface {
				struct VMT : Antilatency::InterfaceContract::IInterface::VMT {
					virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL createEnvironment(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate data, Antilatency::Alt::Environment::IEnvironment& result) = 0;
					static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
						return Antilatency::InterfaceContract::InterfaceID{0xb691107e,0xd628,0x4c62,{0x80,0x03,0xe4,0xd7,0x84,0xb3,0x42,0xe7}};
					}
				private:
					~VMT() = delete;
				};
				
				static bool isInterfaceSupported(const Antilatency::InterfaceContract::InterfaceID& id) {
				    if (id == IEnvironmentConstructor::VMT::ID()) {
				        return true;
				    }
				    return Antilatency::InterfaceContract::IInterface::isInterfaceSupported(id);
				}
				IEnvironmentConstructor() = default;
				IEnvironmentConstructor(std::nullptr_t) {}
				explicit IEnvironmentConstructor(VMT* pointer) : Antilatency::InterfaceContract::IInterface(pointer) {}
				template<typename T, typename = typename std::enable_if<std::is_base_of<IEnvironmentConstructor, T>::value>::type>
				IEnvironmentConstructor& operator = (const T& other) {
				    Antilatency::InterfaceContract::IInterface::operator=(other);
				    return *this;
				}
				template<class Implementer, class ... TArgs>
				static IEnvironmentConstructor create(TArgs&&... args) {
				    return *new Implementer(std::forward<TArgs>(args)...);
				}
				void attach(VMT* other) ANTILATENCY_NOEXCEPT {
				    Antilatency::InterfaceContract::IInterface::attach(other);
				}
				VMT* detach() ANTILATENCY_NOEXCEPT {
				    return reinterpret_cast<VMT*>(Antilatency::InterfaceContract::IInterface::detach());
				}
				Antilatency::Alt::Environment::IEnvironment createEnvironment(const std::string& data) {
					Antilatency::Alt::Environment::IEnvironment result;
					auto dataMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(data);
					handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->createEnvironment(dataMarshaler, result));
					return result;
				}
			};
		} //namespace Environment
	} //namespace Alt
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::Alt::Environment::IEnvironmentConstructor, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::InterfaceContract::IInterface, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL createEnvironment(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate data, Antilatency::Alt::Environment::IEnvironment& result) {
					try {
						result = this->_object->createEnvironment(data);
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
	namespace Alt {
		namespace Environment {
			/* copy and paste this to implementer
			Antilatency::Math::floatQ getRotation() {
				throw std::logic_error{"Method IOrientationAwareEnvironment.getRotation() is not implemented."};
			}
			*/
			struct IOrientationAwareEnvironment : Antilatency::InterfaceContract::IInterface {
				struct VMT : Antilatency::InterfaceContract::IInterface::VMT {
					virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getRotation(Antilatency::Math::floatQ& result) = 0;
					static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
						return Antilatency::InterfaceContract::InterfaceID{0xb789cd05,0xf845,0x4237,{0xbc,0x97,0x9b,0xc8,0x16,0x81,0x90,0xe4}};
					}
				private:
					~VMT() = delete;
				};
				
				static bool isInterfaceSupported(const Antilatency::InterfaceContract::InterfaceID& id) {
				    if (id == IOrientationAwareEnvironment::VMT::ID()) {
				        return true;
				    }
				    return Antilatency::InterfaceContract::IInterface::isInterfaceSupported(id);
				}
				IOrientationAwareEnvironment() = default;
				IOrientationAwareEnvironment(std::nullptr_t) {}
				explicit IOrientationAwareEnvironment(VMT* pointer) : Antilatency::InterfaceContract::IInterface(pointer) {}
				template<typename T, typename = typename std::enable_if<std::is_base_of<IOrientationAwareEnvironment, T>::value>::type>
				IOrientationAwareEnvironment& operator = (const T& other) {
				    Antilatency::InterfaceContract::IInterface::operator=(other);
				    return *this;
				}
				template<class Implementer, class ... TArgs>
				static IOrientationAwareEnvironment create(TArgs&&... args) {
				    return *new Implementer(std::forward<TArgs>(args)...);
				}
				void attach(VMT* other) ANTILATENCY_NOEXCEPT {
				    Antilatency::InterfaceContract::IInterface::attach(other);
				}
				VMT* detach() ANTILATENCY_NOEXCEPT {
				    return reinterpret_cast<VMT*>(Antilatency::InterfaceContract::IInterface::detach());
				}
				Antilatency::Math::floatQ getRotation() {
					Antilatency::Math::floatQ result;
					handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->getRotation(result));
					return result;
				}
			};
		} //namespace Environment
	} //namespace Alt
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::Alt::Environment::IOrientationAwareEnvironment, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::InterfaceContract::IInterface, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getRotation(Antilatency::Math::floatQ& result) {
					try {
						result = this->_object->getRotation();
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
	namespace Alt {
		namespace Environment {
			/* copy and paste this to implementer
			Antilatency::InterfaceContract::LongBool mutate(const std::vector<float>& powers, const std::vector<Antilatency::Math::float3>& rays, float sphereD, const std::vector<Antilatency::Math::float2>& x, const std::vector<Antilatency::Math::float2x3>& xOverPosition, Antilatency::Math::float3 up) {
				throw std::logic_error{"Method IEnvironmentMutable.mutate() is not implemented."};
			}
			int32_t getUpdateId() {
				throw std::logic_error{"Method IEnvironmentMutable.getUpdateId() is not implemented."};
			}
			*/
			struct IEnvironmentMutable : Antilatency::InterfaceContract::IInterface {
				struct VMT : Antilatency::InterfaceContract::IInterface::VMT {
					virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL mutate(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate powers, Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate rays, float sphereD, Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate x, Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate xOverPosition, Antilatency::Math::float3 up, Antilatency::InterfaceContract::LongBool& result) = 0;
					virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getUpdateId(int32_t& result) = 0;
					static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
						return Antilatency::InterfaceContract::InterfaceID{0xe664544b,0xafd5,0x4723,{0x94,0x9a,0x9a,0x88,0x85,0x26,0xef,0x97}};
					}
				private:
					~VMT() = delete;
				};
				
				static bool isInterfaceSupported(const Antilatency::InterfaceContract::InterfaceID& id) {
				    if (id == IEnvironmentMutable::VMT::ID()) {
				        return true;
				    }
				    return Antilatency::InterfaceContract::IInterface::isInterfaceSupported(id);
				}
				IEnvironmentMutable() = default;
				IEnvironmentMutable(std::nullptr_t) {}
				explicit IEnvironmentMutable(VMT* pointer) : Antilatency::InterfaceContract::IInterface(pointer) {}
				template<typename T, typename = typename std::enable_if<std::is_base_of<IEnvironmentMutable, T>::value>::type>
				IEnvironmentMutable& operator = (const T& other) {
				    Antilatency::InterfaceContract::IInterface::operator=(other);
				    return *this;
				}
				template<class Implementer, class ... TArgs>
				static IEnvironmentMutable create(TArgs&&... args) {
				    return *new Implementer(std::forward<TArgs>(args)...);
				}
				void attach(VMT* other) ANTILATENCY_NOEXCEPT {
				    Antilatency::InterfaceContract::IInterface::attach(other);
				}
				VMT* detach() ANTILATENCY_NOEXCEPT {
				    return reinterpret_cast<VMT*>(Antilatency::InterfaceContract::IInterface::detach());
				}
				Antilatency::InterfaceContract::LongBool mutate(const std::vector<float>& powers, const std::vector<Antilatency::Math::float3>& rays, float sphereD, const std::vector<Antilatency::Math::float2>& x, const std::vector<Antilatency::Math::float2x3>& xOverPosition, Antilatency::Math::float3 up) {
					Antilatency::InterfaceContract::LongBool result;
					auto powersMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(powers);
					auto raysMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(rays);
					auto xMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(x);
					auto xOverPositionMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(xOverPosition);
					handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->mutate(powersMarshaler, raysMarshaler, sphereD, xMarshaler, xOverPositionMarshaler, up, result));
					return result;
				}
				int32_t getUpdateId() {
					int32_t result;
					handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->getUpdateId(result));
					return result;
				}
			};
		} //namespace Environment
	} //namespace Alt
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::Alt::Environment::IEnvironmentMutable, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::InterfaceContract::IInterface, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL mutate(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate powers, Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate rays, float sphereD, Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate x, Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate xOverPosition, Antilatency::Math::float3 up, Antilatency::InterfaceContract::LongBool& result) {
					try {
						result = this->_object->mutate(powers, rays, sphereD, x, xOverPosition, up);
					}
					catch (...) {
						return Antilatency::InterfaceContract::handleRemapException(this->_object);
					}
					return Antilatency::InterfaceContract::ExceptionCode::Ok;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getUpdateId(int32_t& result) {
					try {
						result = this->_object->getUpdateId();
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
