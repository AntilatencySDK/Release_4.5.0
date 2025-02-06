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
			namespace Rectangle {
				/* copy and paste this to implementer
				std::vector<Antilatency::Math::float3> getMarkers() {
					throw std::logic_error{"Method IEnvironmentData.getMarkers() is not implemented."};
				}
				float getHeight() {
					throw std::logic_error{"Method IEnvironmentData.getHeight() is not implemented."};
				}
				void setHeight(float height) {
					throw std::logic_error{"Method IEnvironmentData.setHeight() is not implemented."};
				}
				float getWidth() {
					throw std::logic_error{"Method IEnvironmentData.getWidth() is not implemented."};
				}
				void setWidth(float width) {
					throw std::logic_error{"Method IEnvironmentData.setWidth() is not implemented."};
				}
				void setEdgeMarkers(int32_t edgeIdCcw, const std::vector<float>& positions) {
					throw std::logic_error{"Method IEnvironmentData.setEdgeMarkers() is not implemented."};
				}
				std::string serialize() {
					throw std::logic_error{"Method IEnvironmentData.serialize() is not implemented."};
				}
				*/
				struct IEnvironmentData : Antilatency::InterfaceContract::IInterface {
					struct VMT : Antilatency::InterfaceContract::IInterface::VMT {
						virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getMarkers(Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) = 0;
						virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getHeight(float& result) = 0;
						virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setHeight(float height) = 0;
						virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getWidth(float& result) = 0;
						virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setWidth(float width) = 0;
						virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setEdgeMarkers(int32_t edgeIdCcw, Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate positions) = 0;
						virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL serialize(Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) = 0;
						static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
							return Antilatency::InterfaceContract::InterfaceID{0xf0596bc5,0x599a,0x4d06,{0xb7,0xac,0x78,0x2b,0x5b,0xbe,0xb5,0x49}};
						}
					private:
						~VMT() = delete;
					};
					
					static bool isInterfaceSupported(const Antilatency::InterfaceContract::InterfaceID& id) {
					    if (id == IEnvironmentData::VMT::ID()) {
					        return true;
					    }
					    return Antilatency::InterfaceContract::IInterface::isInterfaceSupported(id);
					}
					IEnvironmentData() = default;
					IEnvironmentData(std::nullptr_t) {}
					explicit IEnvironmentData(VMT* pointer) : Antilatency::InterfaceContract::IInterface(pointer) {}
					template<typename T, typename = typename std::enable_if<std::is_base_of<IEnvironmentData, T>::value>::type>
					IEnvironmentData& operator = (const T& other) {
					    Antilatency::InterfaceContract::IInterface::operator=(other);
					    return *this;
					}
					template<class Implementer, class ... TArgs>
					static IEnvironmentData create(TArgs&&... args) {
					    return *new Implementer(std::forward<TArgs>(args)...);
					}
					void attach(VMT* other) ANTILATENCY_NOEXCEPT {
					    Antilatency::InterfaceContract::IInterface::attach(other);
					}
					VMT* detach() ANTILATENCY_NOEXCEPT {
					    return reinterpret_cast<VMT*>(Antilatency::InterfaceContract::IInterface::detach());
					}
					std::vector<Antilatency::Math::float3> getMarkers() {
						std::vector<Antilatency::Math::float3> result;
						auto resultMarshaler = Antilatency::InterfaceContract::Details::ArrayOutMarshaler::create(result);
						handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->getMarkers(resultMarshaler));
						return result;
					}
					float getHeight() {
						float result;
						handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->getHeight(result));
						return result;
					}
					void setHeight(float height) {
						handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->setHeight(height));
					}
					float getWidth() {
						float result;
						handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->getWidth(result));
						return result;
					}
					void setWidth(float width) {
						handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->setWidth(width));
					}
					void setEdgeMarkers(int32_t edgeIdCcw, const std::vector<float>& positions) {
						auto positionsMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(positions);
						handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->setEdgeMarkers(edgeIdCcw, positionsMarshaler));
					}
					std::string serialize() {
						std::string result;
						auto resultMarshaler = Antilatency::InterfaceContract::Details::ArrayOutMarshaler::create(result);
						handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->serialize(resultMarshaler));
						return result;
					}
				};
			} //namespace Rectangle
		} //namespace Environment
	} //namespace Alt
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::Alt::Environment::Rectangle::IEnvironmentData, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::InterfaceContract::IInterface, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getMarkers(Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) {
					try {
						result = this->_object->getMarkers();
					}
					catch (...) {
						return Antilatency::InterfaceContract::handleRemapException(this->_object);
					}
					return Antilatency::InterfaceContract::ExceptionCode::Ok;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getHeight(float& result) {
					try {
						result = this->_object->getHeight();
					}
					catch (...) {
						return Antilatency::InterfaceContract::handleRemapException(this->_object);
					}
					return Antilatency::InterfaceContract::ExceptionCode::Ok;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setHeight(float height) {
					try {
						this->_object->setHeight(height);
					}
					catch (...) {
						return Antilatency::InterfaceContract::handleRemapException(this->_object);
					}
					return Antilatency::InterfaceContract::ExceptionCode::Ok;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL getWidth(float& result) {
					try {
						result = this->_object->getWidth();
					}
					catch (...) {
						return Antilatency::InterfaceContract::handleRemapException(this->_object);
					}
					return Antilatency::InterfaceContract::ExceptionCode::Ok;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setWidth(float width) {
					try {
						this->_object->setWidth(width);
					}
					catch (...) {
						return Antilatency::InterfaceContract::handleRemapException(this->_object);
					}
					return Antilatency::InterfaceContract::ExceptionCode::Ok;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setEdgeMarkers(int32_t edgeIdCcw, Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate positions) {
					try {
						this->_object->setEdgeMarkers(edgeIdCcw, positions);
					}
					catch (...) {
						return Antilatency::InterfaceContract::handleRemapException(this->_object);
					}
					return Antilatency::InterfaceContract::ExceptionCode::Ok;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL serialize(Antilatency::InterfaceContract::Details::ArrayOutMarshaler::Intermediate result) {
					try {
						result = this->_object->serialize();
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
			namespace Rectangle {
				/* copy and paste this to implementer
				Antilatency::Alt::Environment::Rectangle::IEnvironmentData createEnvironmentData() {
					throw std::logic_error{"Method ILibrary.createEnvironmentData() is not implemented."};
				}
				Antilatency::Alt::Environment::Rectangle::IEnvironmentData deserialize(const std::string& environmentData) {
					throw std::logic_error{"Method ILibrary.deserialize() is not implemented."};
				}
				*/
				struct ILibrary : Antilatency::Alt::Environment::IEnvironmentConstructor {
					struct VMT : Antilatency::Alt::Environment::IEnvironmentConstructor::VMT {
						virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL createEnvironmentData(Antilatency::Alt::Environment::Rectangle::IEnvironmentData& result) = 0;
						virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL deserialize(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate environmentData, Antilatency::Alt::Environment::Rectangle::IEnvironmentData& result) = 0;
						static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
							return Antilatency::InterfaceContract::InterfaceID{0x109fc69e,0x29c8,0x4168,{0xac,0xd3,0x03,0x6e,0x6f,0x04,0x59,0xc9}};
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
					Antilatency::Alt::Environment::Rectangle::IEnvironmentData createEnvironmentData() {
						Antilatency::Alt::Environment::Rectangle::IEnvironmentData result;
						handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->createEnvironmentData(result));
						return result;
					}
					Antilatency::Alt::Environment::Rectangle::IEnvironmentData deserialize(const std::string& environmentData) {
						Antilatency::Alt::Environment::Rectangle::IEnvironmentData result;
						auto environmentDataMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(environmentData);
						handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->deserialize(environmentDataMarshaler, result));
						return result;
					}
				};
			} //namespace Rectangle
		} //namespace Environment
	} //namespace Alt
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::Alt::Environment::Rectangle::ILibrary, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::Alt::Environment::IEnvironmentConstructor, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL createEnvironmentData(Antilatency::Alt::Environment::Rectangle::IEnvironmentData& result) {
					try {
						result = this->_object->createEnvironmentData();
					}
					catch (...) {
						return Antilatency::InterfaceContract::handleRemapException(this->_object);
					}
					return Antilatency::InterfaceContract::ExceptionCode::Ok;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL deserialize(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate environmentData, Antilatency::Alt::Environment::Rectangle::IEnvironmentData& result) {
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
