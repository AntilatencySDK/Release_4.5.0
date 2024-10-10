// Copyright 2022, ALT LLC. All Rights Reserved.
// This file is part of Antilatency SDK.
// It is subject to the license terms in the LICENSE file found in the top-level directory
// of this distribution and at http://www.antilatency.com/eula
// You may not use this file except in compliance with the License.
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "CoreMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(BracerLog, Log, All);

//Uncomment to view additional log messages related to ADN module
#define BRACERLOG

#ifdef BRACERLOG
#define BRACER_LOG(verbosity, message, ...) UE_LOG(BracerLog, verbosity, message, ##__VA_ARGS__)
#else
#define BRACER_LOG(verbosity, message) 
#endif
