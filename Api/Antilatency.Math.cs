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
namespace Antilatency.Math {
	[System.Serializable]
	[System.Runtime.InteropServices.StructLayout(LayoutKind.Sequential)]
	public partial struct float3 {
		public float x;
		public float y;
		public float z;
	}
}

namespace Antilatency.Math {
	[System.Serializable]
	[System.Runtime.InteropServices.StructLayout(LayoutKind.Sequential)]
	public partial struct floatQ {
		public float x;
		public float y;
		public float z;
		public float w;
	}
}

namespace Antilatency.Math {
	[System.Serializable]
	[System.Runtime.InteropServices.StructLayout(LayoutKind.Sequential)]
	public partial struct floatP3Q {
		public Antilatency.Math.float3 position;
		public Antilatency.Math.floatQ rotation;
	}
}

namespace Antilatency.Math {
	[System.Serializable]
	[System.Runtime.InteropServices.StructLayout(LayoutKind.Sequential)]
	public partial struct float2 {
		public float x;
		public float y;
	}
}

namespace Antilatency.Math {
	[System.Serializable]
	[System.Runtime.InteropServices.StructLayout(LayoutKind.Sequential)]
	public partial struct float2x3 {
		public Antilatency.Math.float3 x;
		public Antilatency.Math.float3 y;
	}
}

namespace Antilatency.Math {
	[System.Serializable]
	[System.Runtime.InteropServices.StructLayout(LayoutKind.Sequential)]
	public partial struct float3x3 {
		public Antilatency.Math.float3 x;
		public Antilatency.Math.float3 y;
		public Antilatency.Math.float3 z;
	}
}


