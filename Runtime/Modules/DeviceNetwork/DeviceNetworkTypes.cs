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

using System;
using System.Collections.Generic;

namespace Antilatency.DeviceNetwork {
    public partial struct UsbDeviceFilter {
        public static bool operator ==(UsbDeviceFilter u1, UsbDeviceFilter u2) {
            return u1.Equals(u2);
        }

        public static bool operator !=(UsbDeviceFilter u1, UsbDeviceFilter u2) {
            return !u1.Equals(u2);
        }

        public bool Equals(UsbDeviceFilter other) {
            return Equals(other, this);
        }

        public override bool Equals(object obj) {
            if (obj == null || GetType() != obj.GetType()) {
                return false;
            }

            var objToCompare = (UsbDeviceFilter)obj;

            return vid == objToCompare.vid && pid == objToCompare.pid && pidMask == objToCompare.pidMask;
        }

        public override int GetHashCode() {
            unchecked {
                int hash = 3;
                hash = hash * 5 + vid.GetHashCode();
                hash = hash * 7 + pid.GetHashCode();
                hash = hash * 9 + pidMask.GetHashCode();
                return hash;
            }
        }
        
        public override string ToString() {
            return $"Vid: {vid}, pid: {pid}, pid mask: {pidMask}";
        }
    }

    [System.Serializable]
    public struct IpDeviceFilter {
        public string ip;
        public string mask;

        public static IpDeviceFilter DefaultIpDeviceFilter() {
            return new IpDeviceFilter {
                ip = Antilatency.DeviceNetwork.Constants.AllIpDevicesIp,
                mask = Antilatency.DeviceNetwork.Constants.AllIpDevicesMask
            };
        }
        
        public static bool operator ==(IpDeviceFilter u1, IpDeviceFilter u2) {
            return u1.Equals(u2);
        }

        public static bool operator !=(IpDeviceFilter u1, IpDeviceFilter u2) {
            return !u1.Equals(u2);
        }

        public bool Equals(IpDeviceFilter other) {
            return Equals(other, this);
        }

        public override bool Equals(object obj) {
            if (obj == null || GetType() != obj.GetType()) {
                return false;
            }

            var objToCompare = (IpDeviceFilter)obj;

            return ip == objToCompare.ip && mask == objToCompare.mask;
        }
        
        public override int GetHashCode() {
            unchecked {
                int hash = 3;
                hash = hash * 5 + ip.GetHashCode();
                hash = hash * 7 + mask.GetHashCode();
                return hash;
            }
        }
    }
}

