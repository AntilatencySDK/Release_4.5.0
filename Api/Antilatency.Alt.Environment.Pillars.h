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
#include <Antilatency.Alt.Environment.h>
#include <Antilatency.Math.h>
#include <cstdint>
#include <Antilatency.InterfaceContract.h>
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
				uint32_t getNumMarkersPerPillar() {
					throw std::logic_error{"Method IScheme.getNumMarkersPerPillar() is not implemented."};
				}
				void setNumMarkersPerPillar(uint32_t numMarkersPerPillar) {
					throw std::logic_error{"Method IScheme.setNumMarkersPerPillar() is not implemented."};
				}
				float getPillarLength() {
					throw std::logic_error{"Method IScheme.getPillarLength() is not implemented."};
				}
				void setPillarLength(float pillarLength) {
					throw std::logic_error{"Method IScheme.setPillarLength() is not implemented."};
				}
				float getDefaultFovDeg() {
					throw std::logic_error{"Method IScheme.getDefaultFovDeg() is not implemented."};
				}
				void setDefaultFovDeg(float defaultFovDeg) {
					throw std::logic_error{"Method IScheme.setDefaultFovDeg() is not implemented."};
				}
				float getPillarsVerticalOffset() {
					throw std::logic_error{"Method IScheme.getPillarsVerticalOffset() is not implemented."};
				}
				void setPillarsVerticalOffset(float pillarsVerticalOffset) {
					throw std::logic_error{"Method IScheme.setPillarsVerticalOffset() is not implemented."};
				}
				Antilatency::InterfaceContract::LongBool getStrictMatch() {
					throw std::logic_error{"Method IScheme.getStrictMatch() is not implemented."};
				}
				void setStrictMatch(Antilatency::InterfaceContract::LongBool strictMatch) {
					throw std::logic_error{"Method IScheme.setStrictMatch() is not implemented."};
				}
				void setNumPillarsKinds(uint32_t numPillarsKinds) {
					throw std::logic_error{"Method IScheme.setNumPillarsKinds() is not implemented."};
				}
				uint32_t getNumPillarsKinds() {
					throw std::logic_error{"Method IScheme.getNumPillarsKinds() is not implemented."};
				}
				std::vector<float> getProportions(uint32_t pillarKind) {
					throw std::logic_error{"Method IScheme.getProportions() is not implemented."};
				}
				void setProportions(const std::vector<float>& proportions, uint32_t pillarKind) {
					throw std::logic_error{"Method IScheme.setProportions() is not implemented."};
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
					uint32_t getNumMarkersPerPillar() {
						uint32_t result;
						handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->getNumMarkersPerPillar(result));
						return result;
					}
					void setNumMarkersPerPillar(uint32_t numMarkersPerPillar) {
						handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->setNumMarkersPerPillar(numMarkersPerPillar));
					}
					float getPillarLength() {
						float result;
						handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->getPillarLength(result));
						return result;
					}
					void setPillarLength(float pillarLength) {
						handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->setPillarLength(pillarLength));
					}
					float getDefaultFovDeg() {
						float result;
						handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->getDefaultFovDeg(result));
						return result;
					}
					void setDefaultFovDeg(float defaultFovDeg) {
						handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->setDefaultFovDeg(defaultFovDeg));
					}
					float getPillarsVerticalOffset() {
						float result;
						handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->getPillarsVerticalOffset(result));
						return result;
					}
					void setPillarsVerticalOffset(float pillarsVerticalOffset) {
						handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->setPillarsVerticalOffset(pillarsVerticalOffset));
					}
					Antilatency::InterfaceContract::LongBool getStrictMatch() {
						Antilatency::InterfaceContract::LongBool result;
						handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->getStrictMatch(result));
						return result;
					}
					void setStrictMatch(Antilatency::InterfaceContract::LongBool strictMatch) {
						handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->setStrictMatch(strictMatch));
					}
					void setNumPillarsKinds(uint32_t numPillarsKinds) {
						handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->setNumPillarsKinds(numPillarsKinds));
					}
					uint32_t getNumPillarsKinds() {
						uint32_t result;
						handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->getNumPillarsKinds(result));
						return result;
					}
					std::vector<float> getProportions(uint32_t pillarKind) {
						std::vector<float> result;
						auto resultMarshaler = Antilatency::InterfaceContract::Details::ArrayOutMarshaler::create(result);
						handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->getProportions(pillarKind, resultMarshaler));
						return result;
					}
					void setProportions(const std::vector<float>& proportions, uint32_t pillarKind) {
						auto proportionsMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(proportions);
						handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->setProportions(proportionsMarshaler, pillarKind));
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
					try {
						result = this->_object->getNumMarkersPerPillar();
					}
					catch (...) {
						return Antilatency::InterfaceContract::handleRemapException(this->_object);
					}
					return Antilatency::InterfaceContract::ExceptionCode::Ok;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setNumMarkersPerPillar(uint32_t numMarkersPerPillar) {
					try {
						this->_object->setNumMarkersPerPillar(numMarkersPerPillar);
					}
					catch (...) {
						return Antilatency::InterfaceContract::handleRemapException(this->_object);
					}
					return Antilatency::InterfaceContract::ExceptionCode::Ok;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getPillarLength(float& result) {
					try {
						result = this->_object->getPillarLength();
					}
					catch (...) {
						return Antilatency::InterfaceContract::handleRemapException(this->_object);
					}
					return Antilatency::InterfaceContract::ExceptionCode::Ok;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setPillarLength(float pillarLength) {
					try {
						this->_object->setPillarLength(pillarLength);
					}
					catch (...) {
						return Antilatency::InterfaceContract::handleRemapException(this->_object);
					}
					return Antilatency::InterfaceContract::ExceptionCode::Ok;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getDefaultFovDeg(float& result) {
					try {
						result = this->_object->getDefaultFovDeg();
					}
					catch (...) {
						return Antilatency::InterfaceContract::handleRemapException(this->_object);
					}
					return Antilatency::InterfaceContract::ExceptionCode::Ok;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setDefaultFovDeg(float defaultFovDeg) {
					try {
						this->_object->setDefaultFovDeg(defaultFovDeg);
					}
					catch (...) {
						return Antilatency::InterfaceContract::handleRemapException(this->_object);
					}
					return Antilatency::InterfaceContract::ExceptionCode::Ok;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getPillarsVerticalOffset(float& result) {
					try {
						result = this->_object->getPillarsVerticalOffset();
					}
					catch (...) {
						return Antilatency::InterfaceContract::handleRemapException(this->_object);
					}
					return Antilatency::InterfaceContract::ExceptionCode::Ok;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setPillarsVerticalOffset(float pillarsVerticalOffset) {
					try {
						this->_object->setPillarsVerticalOffset(pillarsVerticalOffset);
					}
					catch (...) {
						return Antilatency::InterfaceContract::handleRemapException(this->_object);
					}
					return Antilatency::InterfaceContract::ExceptionCode::Ok;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getStrictMatch(Antilatency::InterfaceContract::LongBool& result) {
					try {
						result = this->_object->getStrictMatch();
					}
					catch (...) {
						return Antilatency::InterfaceContract::handleRemapException(this->_object);
					}
					return Antilatency::InterfaceContract::ExceptionCode::Ok;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setStrictMatch(Antilatency::InterfaceContract::LongBool strictMatch) {
					try {
						this->_object->setStrictMatch(strictMatch);
					}
					catch (...) {
						return Antilatency::InterfaceContract::handleRemapException(this->_object);
					}
					return Antilatency::InterfaceContract::ExceptionCode::Ok;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setNumPillarsKinds(uint32_t numPillarsKinds) {
					try {
						this->_object->setNumPillarsKinds(numPillarsKinds);
					}
					catch (...) {
						return Antilatency::InterfaceContract::handleRemapException(this->_object);
					}
					return Antilatency::InterfaceContract::ExceptionCode::Ok;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getNumPillarsKinds(uint32_t& result) {
					try {
						result = this->_object->getNumPillarsKinds();
					}
					catch (...) {
						return Antilatency::InterfaceContract::handleRemapException(this->_object);
					}
					return Antilatency::InterfaceContract::ExceptionCode::Ok;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getProportions(uint32_t pillarKind, Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) {
					try {
						result = this->_object->getProportions(pillarKind);
					}
					catch (...) {
						return Antilatency::InterfaceContract::handleRemapException(this->_object);
					}
					return Antilatency::InterfaceContract::ExceptionCode::Ok;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setProportions(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate proportions, uint32_t pillarKind) {
					try {
						this->_object->setProportions(proportions, pillarKind);
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
			namespace Pillars {
				/* copy and paste this to implementer
				std::vector<Antilatency::Alt::Environment::Pillars::PillarData> getPillars() {
					throw std::logic_error{"Method IDeserializedEnvironment.getPillars() is not implemented."};
				}
				Antilatency::Alt::Environment::Pillars::IScheme getScheme() {
					throw std::logic_error{"Method IDeserializedEnvironment.getScheme() is not implemented."};
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
					std::vector<Antilatency::Alt::Environment::Pillars::PillarData> getPillars() {
						std::vector<Antilatency::Alt::Environment::Pillars::PillarData> result;
						auto resultMarshaler = Antilatency::InterfaceContract::Details::ArrayOutMarshaler::create(result);
						handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->getPillars(resultMarshaler));
						return result;
					}
					Antilatency::Alt::Environment::Pillars::IScheme getScheme() {
						Antilatency::Alt::Environment::Pillars::IScheme result;
						handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->getScheme(result));
						return result;
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
					try {
						result = this->_object->getPillars();
					}
					catch (...) {
						return Antilatency::InterfaceContract::handleRemapException(this->_object);
					}
					return Antilatency::InterfaceContract::ExceptionCode::Ok;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getScheme(Antilatency::Alt::Environment::Pillars::IScheme& result) {
					try {
						result = this->_object->getScheme();
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
			namespace Pillars {
				/* copy and paste this to implementer
				std::string serialize(const std::vector<Antilatency::Alt::Environment::Pillars::PillarData>& pillars, Antilatency::Alt::Environment::Pillars::IScheme scheme) {
					throw std::logic_error{"Method ILibrary.serialize() is not implemented."};
				}
				Antilatency::Alt::Environment::Pillars::IDeserializedEnvironment deserialize(const std::string& environmentData) {
					throw std::logic_error{"Method ILibrary.deserialize() is not implemented."};
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
					std::string serialize(const std::vector<Antilatency::Alt::Environment::Pillars::PillarData>& pillars, Antilatency::Alt::Environment::Pillars::IScheme scheme) {
						std::string result;
						auto pillarsMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(pillars);
						auto resultMarshaler = Antilatency::InterfaceContract::Details::ArrayOutMarshaler::create(result);
						handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->serialize(pillarsMarshaler, scheme.detach(), resultMarshaler));
						return result;
					}
					Antilatency::Alt::Environment::Pillars::IDeserializedEnvironment deserialize(const std::string& environmentData) {
						Antilatency::Alt::Environment::Pillars::IDeserializedEnvironment result;
						auto environmentDataMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(environmentData);
						handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->deserialize(environmentDataMarshaler, result));
						return result;
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
					try {
						Antilatency::Alt::Environment::Pillars::IScheme schemeMarshaler;
						schemeMarshaler.attach(scheme);
						result = this->_object->serialize(pillars, schemeMarshaler);
					}
					catch (...) {
						return Antilatency::InterfaceContract::handleRemapException(this->_object);
					}
					return Antilatency::InterfaceContract::ExceptionCode::Ok;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL deserialize(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate environmentData, Antilatency::Alt::Environment::Pillars::IDeserializedEnvironment& result) {
					try {
						result = this->_object->deserialize(environmentData);
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
