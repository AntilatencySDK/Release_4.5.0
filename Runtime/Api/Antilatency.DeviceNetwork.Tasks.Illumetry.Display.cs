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
//Unity IL2CPP fix
#if ENABLE_IL2CPP && !__MonoCS__
	#define __MonoCS__
#endif
#if __MonoCS__
	using AOT;
#endif
#pragma warning disable IDE1006 // Do not warn about naming style violations
#pragma warning disable IDE0017 // Do not suggest to simplify object initialization
using System.Runtime.InteropServices; //GuidAttribute
namespace Antilatency.DeviceNetwork.Tasks.Illumetry.Display {
	[System.Serializable]
	[System.Runtime.InteropServices.StructLayout(LayoutKind.Sequential)]
	public partial struct PowerState {
		public float vbus;
		public float irLedsConsumption;
	}
}

namespace Antilatency.DeviceNetwork.Tasks.Illumetry.Display {
	public static partial class Constants {
		public static System.Guid TaskID {
			get {
				byte[] data = new byte[]{23, 1, 248, 241, 162, 242, 236, 67, 131, 23, 191, 56, 31, 69, 146, 12};
				var handle = GCHandle.Alloc(data, GCHandleType.Pinned);
				System.Guid result = (System.Guid)Marshal.PtrToStructure(handle.AddrOfPinnedObject(), typeof(System.Guid));
				handle.Free();
				return result;
			}
		}
	}
}


