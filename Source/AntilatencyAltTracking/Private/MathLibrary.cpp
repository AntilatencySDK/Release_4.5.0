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

#include "MathLibrary.h"

FVector MathLibrary::AntilatencyVectorToUe(const FVector& source) {
    return FVector(source.Z * 100.0f, source.X * 100.0f, source.Y * 100.0f);
}

FVector MathLibrary::UeVectorToAntilatency(const FVector& source) {
    return FVector(source.Y / 100.0f, source.Z / 100.0f, source.X / 100.0f);
}

FQuat MathLibrary::AntilatencyQuatToUe(const FQuat& source) {
    return FQuat(source.Z, source.X, source.Y, source.W);
}

FQuat MathLibrary::UeQuatToAntilatency(const FQuat& source) {
    return FQuat(source.Y, source.Z, source.X, source.W);
}



