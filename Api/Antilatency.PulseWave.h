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
#include <cstdint>
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4946)
#pragma warning(disable: 4265)
#endif
namespace Antilatency {
	namespace PulseWave {
		struct Description {
			uint64_t start;
			uint32_t duration;
			uint32_t period;
		};
	} //namespace PulseWave
} //namespace Antilatency

namespace Antilatency {
	namespace PulseWave {
		/* copy and paste this to implementer
		Antilatency::InterfaceContract::LongBool setPulseWave(Antilatency::PulseWave::Description pulseWave) {
			throw std::logic_error{"Method IPulseWaveReceiver.setPulseWave() is not implemented."};
		}
		*/
		struct IPulseWaveReceiver : Antilatency::InterfaceContract::IInterface {
			struct VMT : Antilatency::InterfaceContract::IInterface::VMT {
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setPulseWave(Antilatency::PulseWave::Description pulseWave, Antilatency::InterfaceContract::LongBool& result) = 0;
				static constexpr Antilatency::InterfaceContract::InterfaceID ID() {
					return Antilatency::InterfaceContract::InterfaceID{0x9cfb93ff,0xe050,0x41d1,{0xae,0x4f,0xe8,0xf5,0x09,0xae,0xd8,0xbd}};
				}
			private:
				~VMT() = delete;
			};
			
			static bool isInterfaceSupported(const Antilatency::InterfaceContract::InterfaceID& id) {
			    if (id == IPulseWaveReceiver::VMT::ID()) {
			        return true;
			    }
			    return Antilatency::InterfaceContract::IInterface::isInterfaceSupported(id);
			}
			IPulseWaveReceiver() = default;
			IPulseWaveReceiver(std::nullptr_t) {}
			explicit IPulseWaveReceiver(VMT* pointer) : Antilatency::InterfaceContract::IInterface(pointer) {}
			template<typename T, typename = typename std::enable_if<std::is_base_of<IPulseWaveReceiver, T>::value>::type>
			IPulseWaveReceiver& operator = (const T& other) {
			    Antilatency::InterfaceContract::IInterface::operator=(other);
			    return *this;
			}
			template<class Implementer, class ... TArgs>
			static IPulseWaveReceiver create(TArgs&&... args) {
			    return *new Implementer(std::forward<TArgs>(args)...);
			}
			void attach(VMT* other) ANTILATENCY_NOEXCEPT {
			    Antilatency::InterfaceContract::IInterface::attach(other);
			}
			VMT* detach() ANTILATENCY_NOEXCEPT {
			    return reinterpret_cast<VMT*>(Antilatency::InterfaceContract::IInterface::detach());
			}
			Antilatency::InterfaceContract::LongBool setPulseWave(Antilatency::PulseWave::Description pulseWave) {
				Antilatency::InterfaceContract::LongBool result;
				handleExceptionCode((reinterpret_cast<VMT*>(this->_object))->setPulseWave(pulseWave, result));
				return result;
			}
		};
	} //namespace PulseWave
} //namespace Antilatency
namespace Antilatency {
	namespace InterfaceContract {
		namespace Details {
			template<typename Implementer, typename LifeTimeController>
			struct InterfaceRemap<Antilatency::PulseWave::IPulseWaveReceiver, Implementer, LifeTimeController> : Antilatency::InterfaceContract::Details::InterfaceRemap<Antilatency::InterfaceContract::IInterface, Implementer, LifeTimeController> {
			public:
			    InterfaceRemap() = default;
			public:
				virtual Antilatency::InterfaceContract::ExceptionCode ANTILATENCY_INTERFACE_CALL setPulseWave(Antilatency::PulseWave::Description pulseWave, Antilatency::InterfaceContract::LongBool& result) {
					try {
						result = this->_object->setPulseWave(pulseWave);
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
