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

using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using Antilatency.Alt.Environment;

namespace Antilatency.SDK {
    public class AltEnvironmentCode : AltEnvironmentComponent {
        public string EnvironmentCode;
        
        private IEnvironment _environment = null;
        public override IEnvironment GetEnvironment() {
            //If the environment has been already created, just return it.
            if (_environment != null) {
                return _environment;
            }
            
            using (var selectorLibrary = Antilatency.Alt.Environment.Selector.Library.load()) {
                if (selectorLibrary == null) {
                    Debug.LogError("Failed to Alt Environment Selector library");
                    return null;
                }

                //Create environment from the code.
                _environment = selectorLibrary.createEnvironment(EnvironmentCode);
                if (_environment == null) {
                    Debug.LogError("Failed to create environment");
                    return null;
                }

                return _environment;
            }
        }
    }
}