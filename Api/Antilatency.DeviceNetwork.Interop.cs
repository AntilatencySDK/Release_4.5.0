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
namespace Antilatency.DeviceNetwork.Interop {
	[System.Serializable]
	[System.Runtime.InteropServices.StructLayout(LayoutKind.Sequential)]
	public partial struct Packet {
		public byte id;
		public System.IntPtr data;
		public uint size;
	}
}

namespace Antilatency.DeviceNetwork.Interop {
	[Guid("d86ef57e-603e-4d3d-9ffe-b145abd9c0aa")]
	[Antilatency.InterfaceContract.InterfaceId("d86ef57e-603e-4d3d-9ffe-b145abd9c0aa")]
	public interface IDataReceiver : Antilatency.InterfaceContract.IInterface {
		void packet(Antilatency.DeviceNetwork.Interop.Packet packet);
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_DeviceNetwork_Interop_IDataReceiver_InterfaceID = new System.Guid("d86ef57e-603e-4d3d-9ffe-b145abd9c0aa");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.DeviceNetwork.Interop.IDataReceiver result) {
		var guid = Antilatency_DeviceNetwork_Interop_IDataReceiver_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.DeviceNetwork.Interop.Details.IDataReceiverWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.DeviceNetwork.Interop.IDataReceiver result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_DeviceNetwork_Interop_IDataReceiver_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.DeviceNetwork.Interop.Details.IDataReceiverWrapper(ptr);
		}
	}
}
namespace Antilatency.DeviceNetwork.Interop {
	namespace Details {
		public class IDataReceiverWrapper : Antilatency.InterfaceContract.Details.IInterfaceWrapper, IDataReceiver {
			private IDataReceiverRemap.VMT _VMT = new IDataReceiverRemap.VMT();
			protected new int GetTotalNativeMethodsCount() {
			    return base.GetTotalNativeMethodsCount() + typeof(IDataReceiverRemap.VMT).GetFields().Length;
			}
			public IDataReceiverWrapper(System.IntPtr obj) : base(obj) {
			    _VMT = LoadVMT<IDataReceiverRemap.VMT>(base.GetTotalNativeMethodsCount());
			}
			public void packet(Antilatency.DeviceNetwork.Interop.Packet packet) {
				var interfaceContractExceptionCode = (_VMT.packet(_object, packet));
				HandleExceptionCode(interfaceContractExceptionCode);
			}
		}
		public class IDataReceiverRemap : Antilatency.InterfaceContract.Details.IInterfaceRemap {
			public new struct VMT {
				public delegate Antilatency.InterfaceContract.ExceptionCode packetDelegate(System.IntPtr _this, Antilatency.DeviceNetwork.Interop.Packet packet);
				#pragma warning disable 0649
				public packetDelegate packet;
				#pragma warning restore 0649
			}
			public new static readonly NativeInterfaceVmt NativeVmt;
			static IDataReceiverRemap() {
				var vmtBlocks = new System.Collections.Generic.List<object>();
				AppendVmt(vmtBlocks);
				NativeVmt = new NativeInterfaceVmt(vmtBlocks);
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.packetDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode packet(System.IntPtr _this, Antilatency.DeviceNetwork.Interop.Packet packet) {
				try {
					var obj = GetContext(_this) as IDataReceiver;
					obj.packet(packet);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			protected static new void AppendVmt(System.Collections.Generic.List<object> buffer) {
				Antilatency.InterfaceContract.Details.IInterfaceRemap.AppendVmt(buffer);
				var vmt = new VMT();
				vmt.packet = packet;
				buffer.Add(vmt);
			}
			public IDataReceiverRemap() { }
			public IDataReceiverRemap(System.IntPtr context, ushort lifetimeId) {
				AllocateNativeInterface(NativeVmt.Handle, context, lifetimeId);
			}
		}
	}
}

namespace Antilatency.DeviceNetwork.Interop {
	public static partial class Constants {
		public const string FirmwareNameKey = "sys/FirmwareName";
		public const string FirmwareVersionKey = "sys/FirmwareVersion";
		public const string HardwareNameKey = "sys/HardwareName";
		public const string HardwareVersionKey = "sys/HardwareVersion";
		public const string HardwareSerialNumberKey = "sys/HardwareSerialNumber";
		public const string ImageVersionKey = "sys/ImageVersion";
		public const ushort IpBroadcastSenderPort = 48100;
		public const ushort IpBroadcastReceiverPort = 48101;
		public const ushort IpDefaultStreamPort = 48052;
	}
}


