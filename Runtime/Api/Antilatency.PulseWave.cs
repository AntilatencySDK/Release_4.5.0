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
namespace Antilatency.PulseWave {
	[System.Serializable]
	[System.Runtime.InteropServices.StructLayout(LayoutKind.Sequential)]
	public partial struct Description {
		public ulong start;
		public uint duration;
		public uint period;
	}
}

namespace Antilatency.PulseWave {
	[Guid("9cfb93ff-e050-41d1-ae4f-e8f509aed8bd")]
	[Antilatency.InterfaceContract.InterfaceId("9cfb93ff-e050-41d1-ae4f-e8f509aed8bd")]
	public interface IPulseWaveReceiver : Antilatency.InterfaceContract.IInterface {
		Antilatency.InterfaceContract.Bool setPulseWave(Antilatency.PulseWave.Description pulseWave);
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_PulseWave_IPulseWaveReceiver_InterfaceID = new System.Guid("9cfb93ff-e050-41d1-ae4f-e8f509aed8bd");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.PulseWave.IPulseWaveReceiver result) {
		var guid = Antilatency_PulseWave_IPulseWaveReceiver_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.PulseWave.Details.IPulseWaveReceiverWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.PulseWave.IPulseWaveReceiver result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_PulseWave_IPulseWaveReceiver_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.PulseWave.Details.IPulseWaveReceiverWrapper(ptr);
		}
	}
}
namespace Antilatency.PulseWave {
	namespace Details {
		public class IPulseWaveReceiverWrapper : Antilatency.InterfaceContract.Details.IInterfaceWrapper, IPulseWaveReceiver {
			private IPulseWaveReceiverRemap.VMT _VMT = new IPulseWaveReceiverRemap.VMT();
			protected new int GetTotalNativeMethodsCount() {
			    return base.GetTotalNativeMethodsCount() + typeof(IPulseWaveReceiverRemap.VMT).GetFields().Length;
			}
			public IPulseWaveReceiverWrapper(System.IntPtr obj) : base(obj) {
			    _VMT = LoadVMT<IPulseWaveReceiverRemap.VMT>(base.GetTotalNativeMethodsCount());
			}
			public Antilatency.InterfaceContract.Bool setPulseWave(Antilatency.PulseWave.Description pulseWave) {
				Antilatency.InterfaceContract.Bool result;
				Antilatency.InterfaceContract.Bool resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.setPulseWave(_object, pulseWave, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
		}
		public class IPulseWaveReceiverRemap : Antilatency.InterfaceContract.Details.IInterfaceRemap {
			public new struct VMT {
				public delegate Antilatency.InterfaceContract.ExceptionCode setPulseWaveDelegate(System.IntPtr _this, Antilatency.PulseWave.Description pulseWave, out Antilatency.InterfaceContract.Bool result);
				#pragma warning disable 0649
				public setPulseWaveDelegate setPulseWave;
				#pragma warning restore 0649
			}
			public new static readonly NativeInterfaceVmt NativeVmt;
			static IPulseWaveReceiverRemap() {
				var vmtBlocks = new System.Collections.Generic.List<object>();
				AppendVmt(vmtBlocks);
				NativeVmt = new NativeInterfaceVmt(vmtBlocks);
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.setPulseWaveDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode setPulseWave(System.IntPtr _this, Antilatency.PulseWave.Description pulseWave, out Antilatency.InterfaceContract.Bool result) {
				try {
					var obj = GetContext(_this) as IPulseWaveReceiver;
					var resultMarshaler = obj.setPulseWave(pulseWave);
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(Antilatency.InterfaceContract.Bool);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			protected static new void AppendVmt(System.Collections.Generic.List<object> buffer) {
				Antilatency.InterfaceContract.Details.IInterfaceRemap.AppendVmt(buffer);
				var vmt = new VMT();
				vmt.setPulseWave = setPulseWave;
				buffer.Add(vmt);
			}
			public IPulseWaveReceiverRemap() { }
			public IPulseWaveReceiverRemap(System.IntPtr context, ushort lifetimeId) {
				AllocateNativeInterface(NativeVmt.Handle, context, lifetimeId);
			}
		}
	}
}


