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
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4946)
#pragma warning(disable: 4265)
#endif
namespace Antilatency {
	namespace DeviceNetwork {
		namespace Tasks {
			namespace Illumetry {
				namespace Display {
					struct PowerState {
						float vbus;
						float irLedsConsumption;
					};
				} //namespace Display
			} //namespace Illumetry
		} //namespace Tasks
	} //namespace DeviceNetwork
} //namespace Antilatency

namespace Antilatency {
	namespace DeviceNetwork {
		namespace Tasks {
			namespace Illumetry {
				namespace Display {
					namespace Constants {
						constexpr Antilatency::InterfaceContract::InterfaceID TaskID = "f1f80117-f2a2-43ec-8317-bf381f45920c";
					} //namespace Constants
				} //namespace Display
			} //namespace Illumetry
		} //namespace Tasks
	} //namespace DeviceNetwork
} //namespace Antilatency


#ifdef _MSC_VER
#pragma warning(pop)
#endif
