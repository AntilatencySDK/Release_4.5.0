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
#include <Antilatency.Alt.Environment.h>
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
			namespace Pillars {
				struct PillarData {
					Antilatency::Math::float3 position;
					uint32_t kind;
					float angle01;
					float fov01;
				};
			} //namespace Pillars
		} //namespace Environment
	} //namespace Alt
} //namespace Antilatency

namespace Antilatency {
	namespace Alt {
		namespace Environment {
			namespace Pillars {
				/* copy and paste this to implementer
				Antilatency::InterfaceContract::ExceptionCode getNumMarkersPerPillar(uint32_t& result) {
					return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
				}
				Antilatency::InterfaceContract::ExceptionCode setNumMarkersPerPillar(uint32_t numMarkersPerPillar) {
					return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
				}
				Antilatency::InterfaceContract::ExceptionCode getPillarLength(float& result) {
					return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
				}
				Antilatency::InterfaceContract::ExceptionCode setPillarLength(float pillarLength) {
					return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
				}
				Antilatency::InterfaceContract::ExceptionCode getDefaultFovDeg(float& result) {
					return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
				}
				Antilatency::InterfaceContract::ExceptionCode setDefaultFovDeg(float defaultFovDeg) {
					return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
				}
				Antilatency::InterfaceContract::ExceptionCode getPillarsVerticalOffset(float& result) {
					return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
				}
				Antilatency::InterfaceContract::ExceptionCode setPillarsVerticalOffset(float pillarsVerticalOffset) {
					return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
				}
				Antilatency::InterfaceContract::ExceptionCode getStrictMatch(Antilatency::InterfaceContract::LongBool& result) {
					return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
				}
				Antilatency::InterfaceContract::ExceptionCode setStrictMatch(Antilatency::InterfaceContract::LongBool strictMatch) {
					return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
				}
				Antilatency::InterfaceContract::ExceptionCode setNumPillarsKinds(uint32_t numPillarsKinds) {
					return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
				}
				Antilatency::InterfaceContract::ExceptionCode getNumPillarsKinds(uint32_t& result) {
					return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
				}
				Antilatency::InterfaceContract::ExceptionCode getProportions(uint32_t pillarKind, std::vector<float>& result) {
					return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
				}
				Antilatency::InterfaceContract::ExceptionCode setProportions(const std::vector<float>& proportions, uint32_t pillarKind) {
					return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
				}
				*/
				struct IScheme : Antilatency::InterfaceContract::IInterface {
					struct VMT : Antilatency::InterfaceContract::IInterface::VMT {
						virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getNumMarkersPerPillar(uint32_t& result) = 0;
						virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setNumMarkersPerPillar(uint32_t numMarkersPerPillar) = 0;
						virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getPillarLength(float& result) = 0;
						virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setPillarLength(float pillarLength) = 0;
						virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getDefaultFovDeg(float& result) = 0;
						virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setDefaultFovDeg(float defaultFovDeg) = 0;
						virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getPillarsVerticalOffset(float& result) = 0;
						virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setPillarsVerticalOffset(float pillarsVerticalOffset) = 0;
						virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getStrictMatch(Antilatency::InterfaceContract::LongBool& result) = 0;
						virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setStrictMatch(Antilatency::InterfaceContract::LongBool strictMatch) = 0;
						virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setNumPillarsKinds(uint32_t numPillarsKinds) = 0;
						virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getNumPillarsKinds(uint32_t& result) = 0;
						virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getProportions(uint32_t pillarKind, Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) = 0;
						virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setProportions(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate proportions, uint32_t pillarKind) = 0;
						static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
							return Antilatency::InterfaceContract::InterfaceID{0x143f0dac,0x4ba6,0x44c3,{0xab,0x3f,0xe0,0x96,0xa4,0x8c,0x24,0xe5}};
						}
					private:
						~VMT() = delete;
					};
					
					static bool isInterfaceSupported(const Antilatency::InterfaceContract::InterfaceID& id) {
					    if (id == IScheme::VMT::ID()) {
					        return true;
					    }
					    return Antilatency::InterfaceContract::IInterface::isInterfaceSupported(id);
					}
					IScheme() = default;
					IScheme(std::nullptr_t) {}
					explicit IScheme(VMT* pointer) : Antilatency::InterfaceContract::IInterface(pointer) {}
					template<typename T, typename = typename std::enable_if<std::is_base_of<IScheme, T>::value>::type>
					IScheme& operator = (const T& other) {
					    Antilatency::InterfaceContract::IInterface::operator=(other);
					    return *this;
					}
					template<class Implementer, class ... TArgs>
					static IScheme create(TArgs&&... args) {
					    return *new Implementer(std::forward<TArgs>(args)...);
					}
					void attach(VMT* other) ANTILATENCY_NOEXCEPT {
					    Antilatency::InterfaceContract::IInterface::attach(other);
					}
					VMT* detach() ANTILATENCY_NOEXCEPT {
					    return reinterpret_cast<VMT*>(Antilatency::InterfaceContract::IInterface::detach());
					}
					Antilatency::InterfaceContract::ExceptionCode getNumMarkersPerPillar(uint32_t& result) {
						return (reinterpret_cast<VMT*>(this->_object))->getNumMarkersPerPillar(result);
					}
					Antilatency::InterfaceContract::ExceptionCode setNumMarkersPerPillar(uint32_t numMarkersPerPillar) {
						return (reinterpret_cast<VMT*>(this->_object))->setNumMarkersPerPillar(numMarkersPerPillar);
					}
					Antilatency::InterfaceContract::ExceptionCode getPillarLength(float& result) {
						return (reinterpret_cast<VMT*>(this->_object))->getPillarLength(result);
					}
					Antilatency::InterfaceContract::ExceptionCode setPillarLength(float pillarLength) {
						return (reinterpret_cast<VMT*>(this->_object))->setPillarLength(pillarLength);
					}
					Antilatency::InterfaceContract::ExceptionCode getDefaultFovDeg(float& result) {
						return (reinterpret_cast<VMT*>(this->_object))->getDefaultFovDeg(result);
					}
					Antilatency::InterfaceContract::ExceptionCode setDefaultFovDeg(float defaultFovDeg) {
						return (reinterpret_cast<VMT*>(this->_object))->setDefaultFovDeg(defaultFovDeg);
					}
					Antilatency::InterfaceContract::ExceptionCode getPillarsVerticalOffset(float& result) {
						return (reinterpret_cast<VMT*>(this->_object))->getPillarsVerticalOffset(result);
					}
					Antilatency::InterfaceContract::ExceptionCode setPillarsVerticalOffset(float pillarsVerticalOffset) {
						return (reinterpret_cast<VMT*>(this->_object))->setPillarsVerticalOffset(pillarsVerticalOffset);
					}
					Antilatency::InterfaceContract::ExceptionCode getStrictMatch(Antilatency::InterfaceContract::LongBool& result) {
						return (reinterpret_cast<VMT*>(this->_object))->getStrictMatch(result);
					}
					Antilatency::InterfaceContract::ExceptionCode setStrictMatch(Antilatency::InterfaceContract::LongBool strictMatch) {
						return (reinterpret_cast<VMT*>(this->_object))->setStrictMatch(strictMatch);
					}
					Antilatency::InterfaceContract::ExceptionCode setNumPillarsKinds(uint32_t numPillarsKinds) {
						return (reinterpret_cast<VMT*>(this->_object))->setNumPillarsKinds(numPillarsKinds);
					}
					Antilatency::InterfaceContract::ExceptionCode getNumPillarsKinds(uint32_t& result) {
						return (reinterpret_cast<VMT*>(this->_object))->getNumPillarsKinds(result);
					}
					Antilatency::InterfaceContract::ExceptionCode getProportions(uint32_t pillarKind, std::vector<float>& result) {
						auto resultMarshaler = Antilatency::InterfaceContract::Details::ArrayOutMarshaler::create(result);
						return (reinterpret_cast<VMT*>(this->_object))->getProportions(pillarKind, resultMarshaler);
					}
					Antilatency::InterfaceContract::ExceptionCode setProportions(const std::vector<float>& proportions, uint32_t pillarKind) {
						auto proportionsMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(proportions);
						return (reinterpret_cast<VMT*>(this->_object))->setProportions(proportionsMarshaler, pillarKind);
					}
				};
			} //namespace Pillars
		} //namespace Environment
	} //namespace Alt
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::Alt::Environment::Pillars::IScheme, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::InterfaceContract::IInterface, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getNumMarkersPerPillar(uint32_t& result) {
					auto exceptionCode_ = this->_object->getNumMarkersPerPillar(result);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setNumMarkersPerPillar(uint32_t numMarkersPerPillar) {
					auto exceptionCode_ = this->_object->setNumMarkersPerPillar(numMarkersPerPillar);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getPillarLength(float& result) {
					auto exceptionCode_ = this->_object->getPillarLength(result);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setPillarLength(float pillarLength) {
					auto exceptionCode_ = this->_object->setPillarLength(pillarLength);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getDefaultFovDeg(float& result) {
					auto exceptionCode_ = this->_object->getDefaultFovDeg(result);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setDefaultFovDeg(float defaultFovDeg) {
					auto exceptionCode_ = this->_object->setDefaultFovDeg(defaultFovDeg);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getPillarsVerticalOffset(float& result) {
					auto exceptionCode_ = this->_object->getPillarsVerticalOffset(result);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setPillarsVerticalOffset(float pillarsVerticalOffset) {
					auto exceptionCode_ = this->_object->setPillarsVerticalOffset(pillarsVerticalOffset);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getStrictMatch(Antilatency::InterfaceContract::LongBool& result) {
					auto exceptionCode_ = this->_object->getStrictMatch(result);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setStrictMatch(Antilatency::InterfaceContract::LongBool strictMatch) {
					auto exceptionCode_ = this->_object->setStrictMatch(strictMatch);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setNumPillarsKinds(uint32_t numPillarsKinds) {
					auto exceptionCode_ = this->_object->setNumPillarsKinds(numPillarsKinds);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getNumPillarsKinds(uint32_t& result) {
					auto exceptionCode_ = this->_object->getNumPillarsKinds(result);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getProportions(uint32_t pillarKind, Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) {
					std::vector<float> resultMarshaler;
					auto exceptionCode_ = this->_object->getProportions(pillarKind, resultMarshaler);
					result = resultMarshaler;
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setProportions(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate proportions, uint32_t pillarKind) {
					auto exceptionCode_ = this->_object->setProportions(proportions, pillarKind);
					return exceptionCode_;
				}
			};
		} //namespace Details
	} //namespace InterfaceContract
} //namespace Antilatency

namespace Antilatency {
	namespace Alt {
		namespace Environment {
			namespace Pillars {
				/* copy and paste this to implementer
				Antilatency::InterfaceContract::ExceptionCode getPillars(std::vector<Antilatency::Alt::Environment::Pillars::PillarData>& result) {
					return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
				}
				Antilatency::InterfaceContract::ExceptionCode getScheme(Antilatency::Alt::Environment::Pillars::IScheme& result) {
					return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
				}
				*/
				struct IDeserializedEnvironment : Antilatency::InterfaceContract::IInterface {
					struct VMT : Antilatency::InterfaceContract::IInterface::VMT {
						virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getPillars(Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) = 0;
						virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getScheme(Antilatency::Alt::Environment::Pillars::IScheme& result) = 0;
						static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
							return Antilatency::InterfaceContract::InterfaceID{0x28eb9cd7,0x28dc,0x4318,{0xaa,0x95,0x32,0x88,0x61,0x61,0xe1,0x4b}};
						}
					private:
						~VMT() = delete;
					};
					
					static bool isInterfaceSupported(const Antilatency::InterfaceContract::InterfaceID& id) {
					    if (id == IDeserializedEnvironment::VMT::ID()) {
					        return true;
					    }
					    return Antilatency::InterfaceContract::IInterface::isInterfaceSupported(id);
					}
					IDeserializedEnvironment() = default;
					IDeserializedEnvironment(std::nullptr_t) {}
					explicit IDeserializedEnvironment(VMT* pointer) : Antilatency::InterfaceContract::IInterface(pointer) {}
					template<typename T, typename = typename std::enable_if<std::is_base_of<IDeserializedEnvironment, T>::value>::type>
					IDeserializedEnvironment& operator = (const T& other) {
					    Antilatency::InterfaceContract::IInterface::operator=(other);
					    return *this;
					}
					template<class Implementer, class ... TArgs>
					static IDeserializedEnvironment create(TArgs&&... args) {
					    return *new Implementer(std::forward<TArgs>(args)...);
					}
					void attach(VMT* other) ANTILATENCY_NOEXCEPT {
					    Antilatency::InterfaceContract::IInterface::attach(other);
					}
					VMT* detach() ANTILATENCY_NOEXCEPT {
					    return reinterpret_cast<VMT*>(Antilatency::InterfaceContract::IInterface::detach());
					}
					Antilatency::InterfaceContract::ExceptionCode getPillars(std::vector<Antilatency::Alt::Environment::Pillars::PillarData>& result) {
						auto resultMarshaler = Antilatency::InterfaceContract::Details::ArrayOutMarshaler::create(result);
						return (reinterpret_cast<VMT*>(this->_object))->getPillars(resultMarshaler);
					}
					Antilatency::InterfaceContract::ExceptionCode getScheme(Antilatency::Alt::Environment::Pillars::IScheme& result) {
						return (reinterpret_cast<VMT*>(this->_object))->getScheme(result);
					}
				};
			} //namespace Pillars
		} //namespace Environment
	} //namespace Alt
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::Alt::Environment::Pillars::IDeserializedEnvironment, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::InterfaceContract::IInterface, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getPillars(Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) {
					std::vector<Antilatency::Alt::Environment::Pillars::PillarData> resultMarshaler;
					auto exceptionCode_ = this->_object->getPillars(resultMarshaler);
					result = resultMarshaler;
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getScheme(Antilatency::Alt::Environment::Pillars::IScheme& result) {
					auto exceptionCode_ = this->_object->getScheme(result);
					return exceptionCode_;
				}
			};
		} //namespace Details
	} //namespace InterfaceContract
} //namespace Antilatency

namespace Antilatency {
	namespace Alt {
		namespace Environment {
			namespace Pillars {
				/* copy and paste this to implementer
				Antilatency::InterfaceContract::ExceptionCode serialize(const std::vector<Antilatency::Alt::Environment::Pillars::PillarData>& pillars, Antilatency::Alt::Environment::Pillars::IScheme scheme, std::string& result) {
					return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
				}
				Antilatency::InterfaceContract::ExceptionCode deserialize(const std::string& environmentData, Antilatency::Alt::Environment::Pillars::IDeserializedEnvironment& result) {
					return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
				}
				*/
				struct ILibrary : Antilatency::Alt::Environment::IEnvironmentConstructor {
					struct VMT : Antilatency::Alt::Environment::IEnvironmentConstructor::VMT {
						virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL serialize(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate pillars, Antilatency::Alt::Environment::Pillars::IScheme::VMT* scheme, Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) = 0;
						virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL deserialize(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate environmentData, Antilatency::Alt::Environment::Pillars::IDeserializedEnvironment& result) = 0;
						static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
							return Antilatency::InterfaceContract::InterfaceID{0x8c5671c0,0x07d0,0x4ca0,{0x86,0x66,0x39,0xeb,0x75,0xd7,0xf0,0x73}};
						}
					private:
						~VMT() = delete;
					};
					
					static bool isInterfaceSupported(const Antilatency::InterfaceContract::InterfaceID& id) {
					    if (id == ILibrary::VMT::ID()) {
					        return true;
					    }
					    return Antilatency::Alt::Environment::IEnvironmentConstructor::isInterfaceSupported(id);
					}
					ILibrary() = default;
					ILibrary(std::nullptr_t) {}
					explicit ILibrary(VMT* pointer) : Antilatency::Alt::Environment::IEnvironmentConstructor(pointer) {}
					template<typename T, typename = typename std::enable_if<std::is_base_of<ILibrary, T>::value>::type>
					ILibrary& operator = (const T& other) {
					    Antilatency::Alt::Environment::IEnvironmentConstructor::operator=(other);
					    return *this;
					}
					template<class Implementer, class ... TArgs>
					static ILibrary create(TArgs&&... args) {
					    return *new Implementer(std::forward<TArgs>(args)...);
					}
					void attach(VMT* other) ANTILATENCY_NOEXCEPT {
					    Antilatency::Alt::Environment::IEnvironmentConstructor::attach(other);
					}
					VMT* detach() ANTILATENCY_NOEXCEPT {
					    return reinterpret_cast<VMT*>(Antilatency::Alt::Environment::IEnvironmentConstructor::detach());
					}
					Antilatency::InterfaceContract::ExceptionCode serialize(const std::vector<Antilatency::Alt::Environment::Pillars::PillarData>& pillars, Antilatency::Alt::Environment::Pillars::IScheme scheme, std::string& result) {
						auto pillarsMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(pillars);
						auto resultMarshaler = Antilatency::InterfaceContract::Details::ArrayOutMarshaler::create(result);
						return (reinterpret_cast<VMT*>(this->_object))->serialize(pillarsMarshaler, scheme.detach(), resultMarshaler);
					}
					Antilatency::InterfaceContract::ExceptionCode deserialize(const std::string& environmentData, Antilatency::Alt::Environment::Pillars::IDeserializedEnvironment& result) {
						auto environmentDataMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(environmentData);
						return (reinterpret_cast<VMT*>(this->_object))->deserialize(environmentDataMarshaler, result);
					}
				};
			} //namespace Pillars
		} //namespace Environment
	} //namespace Alt
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::Alt::Environment::Pillars::ILibrary, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::Alt::Environment::IEnvironmentConstructor, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL serialize(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate pillars, Antilatency::Alt::Environment::Pillars::IScheme::VMT* scheme, Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) {
					Antilatency::Alt::Environment::Pillars::IScheme schemeMarshaler;
					schemeMarshaler.attach(scheme);
					std::string resultMarshaler;
					auto exceptionCode_ = this->_object->serialize(pillars, schemeMarshaler, resultMarshaler);
					result = resultMarshaler;
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL deserialize(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate environmentData, Antilatency::Alt::Environment::Pillars::IDeserializedEnvironment& result) {
					auto exceptionCode_ = this->_object->deserialize(environmentData, result);
					return exceptionCode_;
				}
			};
		} //namespace Details
	} //namespace InterfaceContract
} //namespace Antilatency


#ifdef _MSC_VER
#pragma warning(pop)
#endif
