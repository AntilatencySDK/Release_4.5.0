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
#include <Antilatency.Alt.Environment.h>
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4946)
#pragma warning(disable: 4265)
#endif
namespace Antilatency {
	namespace Alt {
		namespace Environment {
			namespace Selector {
				/* copy and paste this to implementer
				Antilatency::InterfaceContract::ExceptionCode registerEnvironmentProvider(const std::string& name, Antilatency::Alt::Environment::IEnvironmentConstructor provider) {
					return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
				}
				Antilatency::InterfaceContract::ExceptionCode unregisterEnvironmentProvider(const std::string& name) {
					return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
				}
				Antilatency::InterfaceContract::ExceptionCode createEnvironment(const std::string& data, Antilatency::Alt::Environment::IEnvironment& result) {
					return Antilatency::InterfaceContract::ExceptionCode::NotImplemented;
				}
				*/
				struct ILibrary : Antilatency::InterfaceContract::IInterface {
					struct VMT : Antilatency::InterfaceContract::IInterface::VMT {
						virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL registerEnvironmentProvider(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate name, Antilatency::Alt::Environment::IEnvironmentConstructor::VMT* provider) = 0;
						virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL unregisterEnvironmentProvider(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate name) = 0;
						virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL createEnvironment(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate data, Antilatency::Alt::Environment::IEnvironment& result) = 0;
						static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
							return Antilatency::InterfaceContract::InterfaceID{0x2ef251c9,0xe0d5,0x46ad,{0x8a,0xe0,0x96,0x7d,0xed,0x90,0x8f,0x2a}};
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
					Antilatency::InterfaceContract::ExceptionCode registerEnvironmentProvider(const std::string& name, Antilatency::Alt::Environment::IEnvironmentConstructor provider) {
						auto nameMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(name);
						return (reinterpret_cast<VMT*>(this->_object))->registerEnvironmentProvider(nameMarshaler, provider.detach());
					}
					Antilatency::InterfaceContract::ExceptionCode unregisterEnvironmentProvider(const std::string& name) {
						auto nameMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(name);
						return (reinterpret_cast<VMT*>(this->_object))->unregisterEnvironmentProvider(nameMarshaler);
					}
					Antilatency::InterfaceContract::ExceptionCode createEnvironment(const std::string& data, Antilatency::Alt::Environment::IEnvironment& result) {
						auto dataMarshaler = Antilatency::InterfaceContract::Details::ArrayInMarshaler::create(data);
						return (reinterpret_cast<VMT*>(this->_object))->createEnvironment(dataMarshaler, result);
					}
				};
			} //namespace Selector
		} //namespace Environment
	} //namespace Alt
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::Alt::Environment::Selector::ILibrary, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::InterfaceContract::IInterface, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL registerEnvironmentProvider(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate name, Antilatency::Alt::Environment::IEnvironmentConstructor::VMT* provider) {
					Antilatency::Alt::Environment::IEnvironmentConstructor providerMarshaler;
					providerMarshaler.attach(provider);
					auto exceptionCode_ = this->_object->registerEnvironmentProvider(name, providerMarshaler);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL unregisterEnvironmentProvider(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate name) {
					auto exceptionCode_ = this->_object->unregisterEnvironmentProvider(name);
					return exceptionCode_;
				}
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL createEnvironment(Antilatency::InterfaceContract::Details::ArrayInMarshaler::Intermediate data, Antilatency::Alt::Environment::IEnvironment& result) {
					auto exceptionCode_ = this->_object->createEnvironment(data, result);
					return exceptionCode_;
				}
			};
		} //namespace Details
	} //namespace InterfaceContract
} //namespace Antilatency


#ifdef _MSC_VER
#pragma warning(pop)
#endif
