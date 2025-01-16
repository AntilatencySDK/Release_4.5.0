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
namespace Antilatency.DeviceNetwork {
	[System.Serializable]
	[System.Runtime.InteropServices.StructLayout(LayoutKind.Sequential)]
	public partial struct UsbVendorId {
		public static readonly UsbVendorId Antilatency = new UsbVendorId(){ value = 0x3237 };
		[System.Diagnostics.DebuggerBrowsable(global::System.Diagnostics.DebuggerBrowsableState.Never)]
		public ushort value;
		public override string ToString() {
			switch (value) {
				case 0x3237: return "Antilatency";
			}
			return value.ToString();
		}
		public static implicit operator ushort(UsbVendorId value) { return value.value;}
		public static explicit operator UsbVendorId(ushort value) { return new UsbVendorId() { value = value }; }
	}
}

namespace Antilatency.DeviceNetwork {
	[System.Serializable]
	[System.Runtime.InteropServices.StructLayout(LayoutKind.Sequential)]
	public partial struct UsbDeviceFilter {
		public Antilatency.DeviceNetwork.UsbVendorId vid;
		public ushort pid;
		public ushort pidMask;
	}
}

namespace Antilatency.DeviceNetwork {
	[Guid("9e6bdb45-e7cb-4f46-a5ee-ce7353a734c9")]
	[Antilatency.InterfaceContract.InterfaceId("9e6bdb45-e7cb-4f46-a5ee-ce7353a734c9")]
	public interface IDeviceFilter : Antilatency.InterfaceContract.IInterface {
		void addUsbDevice(Antilatency.DeviceNetwork.UsbDeviceFilter usbDeviceType);
		void addIpDevice(string ip, string mask);
		Antilatency.DeviceNetwork.UsbDeviceFilter getUsbDevice(uint index);
		string getIpDevice(uint index);
		string getIpDeviceMask(uint index);
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_DeviceNetwork_IDeviceFilter_InterfaceID = new System.Guid("9e6bdb45-e7cb-4f46-a5ee-ce7353a734c9");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.DeviceNetwork.IDeviceFilter result) {
		var guid = Antilatency_DeviceNetwork_IDeviceFilter_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.DeviceNetwork.Details.IDeviceFilterWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.DeviceNetwork.IDeviceFilter result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_DeviceNetwork_IDeviceFilter_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.DeviceNetwork.Details.IDeviceFilterWrapper(ptr);
		}
	}
}
namespace Antilatency.DeviceNetwork {
	namespace Details {
		public class IDeviceFilterWrapper : Antilatency.InterfaceContract.Details.IInterfaceWrapper, IDeviceFilter {
			private IDeviceFilterRemap.VMT _VMT = new IDeviceFilterRemap.VMT();
			protected new int GetTotalNativeMethodsCount() {
			    return base.GetTotalNativeMethodsCount() + typeof(IDeviceFilterRemap.VMT).GetFields().Length;
			}
			public IDeviceFilterWrapper(System.IntPtr obj) : base(obj) {
			    _VMT = LoadVMT<IDeviceFilterRemap.VMT>(base.GetTotalNativeMethodsCount());
			}
			public void addUsbDevice(Antilatency.DeviceNetwork.UsbDeviceFilter usbDeviceType) {
				var interfaceContractExceptionCode = (_VMT.addUsbDevice(_object, usbDeviceType));
				HandleExceptionCode(interfaceContractExceptionCode);
			}
			public void addIpDevice(string ip, string mask) {
				var ipMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(ip);
				var maskMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(mask);
				var interfaceContractExceptionCode = (_VMT.addIpDevice(_object, ipMarshaler, maskMarshaler));
				ipMarshaler.Dispose();
				maskMarshaler.Dispose();
				HandleExceptionCode(interfaceContractExceptionCode);
			}
			public Antilatency.DeviceNetwork.UsbDeviceFilter getUsbDevice(uint index) {
				Antilatency.DeviceNetwork.UsbDeviceFilter result;
				Antilatency.DeviceNetwork.UsbDeviceFilter resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.getUsbDevice(_object, index, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public string getIpDevice(uint index) {
				string result;
				var resultMarshaler = Antilatency.InterfaceContract.Details.ArrayOutMarshaler.create();
				var interfaceContractExceptionCode = (_VMT.getIpDevice(_object, index, resultMarshaler));
				result = resultMarshaler.value;
				resultMarshaler.Dispose();
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public string getIpDeviceMask(uint index) {
				string result;
				var resultMarshaler = Antilatency.InterfaceContract.Details.ArrayOutMarshaler.create();
				var interfaceContractExceptionCode = (_VMT.getIpDeviceMask(_object, index, resultMarshaler));
				result = resultMarshaler.value;
				resultMarshaler.Dispose();
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
		}
		public class IDeviceFilterRemap : Antilatency.InterfaceContract.Details.IInterfaceRemap {
			public new struct VMT {
				public delegate Antilatency.InterfaceContract.ExceptionCode addUsbDeviceDelegate(System.IntPtr _this, Antilatency.DeviceNetwork.UsbDeviceFilter usbDeviceType);
				public delegate Antilatency.InterfaceContract.ExceptionCode addIpDeviceDelegate(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate ip, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate mask);
				public delegate Antilatency.InterfaceContract.ExceptionCode getUsbDeviceDelegate(System.IntPtr _this, uint index, out Antilatency.DeviceNetwork.UsbDeviceFilter result);
				public delegate Antilatency.InterfaceContract.ExceptionCode getIpDeviceDelegate(System.IntPtr _this, uint index, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result);
				public delegate Antilatency.InterfaceContract.ExceptionCode getIpDeviceMaskDelegate(System.IntPtr _this, uint index, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result);
				#pragma warning disable 0649
				public addUsbDeviceDelegate addUsbDevice;
				public addIpDeviceDelegate addIpDevice;
				public getUsbDeviceDelegate getUsbDevice;
				public getIpDeviceDelegate getIpDevice;
				public getIpDeviceMaskDelegate getIpDeviceMask;
				#pragma warning restore 0649
			}
			public new static readonly NativeInterfaceVmt NativeVmt;
			static IDeviceFilterRemap() {
				var vmtBlocks = new System.Collections.Generic.List<object>();
				AppendVmt(vmtBlocks);
				NativeVmt = new NativeInterfaceVmt(vmtBlocks);
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.addUsbDeviceDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode addUsbDevice(System.IntPtr _this, Antilatency.DeviceNetwork.UsbDeviceFilter usbDeviceType) {
				try {
					var obj = GetContext(_this) as IDeviceFilter;
					obj.addUsbDevice(usbDeviceType);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.addIpDeviceDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode addIpDevice(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate ip, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate mask) {
				try {
					var obj = GetContext(_this) as IDeviceFilter;
					obj.addIpDevice(ip, mask);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getUsbDeviceDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getUsbDevice(System.IntPtr _this, uint index, out Antilatency.DeviceNetwork.UsbDeviceFilter result) {
				try {
					var obj = GetContext(_this) as IDeviceFilter;
					var resultMarshaler = obj.getUsbDevice(index);
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(Antilatency.DeviceNetwork.UsbDeviceFilter);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getIpDeviceDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getIpDevice(System.IntPtr _this, uint index, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result) {
				try {
					var obj = GetContext(_this) as IDeviceFilter;
					var resultMarshaler = obj.getIpDevice(index);
					result.assign(resultMarshaler);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getIpDeviceMaskDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getIpDeviceMask(System.IntPtr _this, uint index, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result) {
				try {
					var obj = GetContext(_this) as IDeviceFilter;
					var resultMarshaler = obj.getIpDeviceMask(index);
					result.assign(resultMarshaler);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			protected static new void AppendVmt(System.Collections.Generic.List<object> buffer) {
				Antilatency.InterfaceContract.Details.IInterfaceRemap.AppendVmt(buffer);
				var vmt = new VMT();
				vmt.addUsbDevice = addUsbDevice;
				vmt.addIpDevice = addIpDevice;
				vmt.getUsbDevice = getUsbDevice;
				vmt.getIpDevice = getIpDevice;
				vmt.getIpDeviceMask = getIpDeviceMask;
				buffer.Add(vmt);
			}
			public IDeviceFilterRemap() { }
			public IDeviceFilterRemap(System.IntPtr context, ushort lifetimeId) {
				AllocateNativeInterface(NativeVmt.Handle, context, lifetimeId);
			}
		}
	}
}

namespace Antilatency.DeviceNetwork {
	[System.Serializable]
	[System.Runtime.InteropServices.StructLayout(LayoutKind.Sequential)]
	public partial struct NodeHandle {
		public static readonly NodeHandle Null = new NodeHandle(){ value = 0x0 };
		[System.Diagnostics.DebuggerBrowsable(global::System.Diagnostics.DebuggerBrowsableState.Never)]
		public uint value;
		public override string ToString() {
			switch (value) {
				case 0x0: return "Null";
			}
			return value.ToString();
		}
		public static implicit operator uint(NodeHandle value) { return value.value;}
		public static explicit operator NodeHandle(uint value) { return new NodeHandle() { value = value }; }
	}
}

namespace Antilatency.DeviceNetwork {
	[System.Serializable]
	[System.Runtime.InteropServices.StructLayout(LayoutKind.Sequential)]
	public partial struct NodeStatus {
		public static readonly NodeStatus Idle = new NodeStatus(){ value = 0x0 };
		public static readonly NodeStatus TaskRunning = new NodeStatus(){ value = 0x1 };
		public static readonly NodeStatus Invalid = new NodeStatus(){ value = 0x2 };
		[System.Diagnostics.DebuggerBrowsable(global::System.Diagnostics.DebuggerBrowsableState.Never)]
		public int value;
		public override string ToString() {
			switch (value) {
				case 0x0: return "Idle";
				case 0x1: return "TaskRunning";
				case 0x2: return "Invalid";
			}
			return value.ToString();
		}
		public static implicit operator int(NodeStatus value) { return value.value;}
		public static explicit operator NodeStatus(int value) { return new NodeStatus() { value = value }; }
	}
}

namespace Antilatency.DeviceNetwork {
	[Guid("af7402e8-2a23-442b-8230-d41f55ef5dc0")]
	[Antilatency.InterfaceContract.InterfaceId("af7402e8-2a23-442b-8230-d41f55ef5dc0")]
	public interface ISynchronousConnection : Antilatency.InterfaceContract.IInterface {
		Antilatency.DeviceNetwork.Interop.Packet[] getPackets();
		Antilatency.DeviceNetwork.Interop.Packet[] getAvailablePackets(out Antilatency.InterfaceContract.Bool taskFinished);
		Antilatency.InterfaceContract.Bool writePacket(Antilatency.DeviceNetwork.Interop.Packet packet);
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_DeviceNetwork_ISynchronousConnection_InterfaceID = new System.Guid("af7402e8-2a23-442b-8230-d41f55ef5dc0");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.DeviceNetwork.ISynchronousConnection result) {
		var guid = Antilatency_DeviceNetwork_ISynchronousConnection_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.DeviceNetwork.Details.ISynchronousConnectionWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.DeviceNetwork.ISynchronousConnection result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_DeviceNetwork_ISynchronousConnection_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.DeviceNetwork.Details.ISynchronousConnectionWrapper(ptr);
		}
	}
}
namespace Antilatency.DeviceNetwork {
	namespace Details {
		public class ISynchronousConnectionWrapper : Antilatency.InterfaceContract.Details.IInterfaceWrapper, ISynchronousConnection {
			private ISynchronousConnectionRemap.VMT _VMT = new ISynchronousConnectionRemap.VMT();
			protected new int GetTotalNativeMethodsCount() {
			    return base.GetTotalNativeMethodsCount() + typeof(ISynchronousConnectionRemap.VMT).GetFields().Length;
			}
			public ISynchronousConnectionWrapper(System.IntPtr obj) : base(obj) {
			    _VMT = LoadVMT<ISynchronousConnectionRemap.VMT>(base.GetTotalNativeMethodsCount());
			}
			public Antilatency.DeviceNetwork.Interop.Packet[] getPackets() {
				Antilatency.DeviceNetwork.Interop.Packet[] result;
				var resultMarshaler = Antilatency.InterfaceContract.Details.ArrayOutMarshaler.create<Antilatency.DeviceNetwork.Interop.Packet>();
				var interfaceContractExceptionCode = (_VMT.getPackets(_object, resultMarshaler));
				result = resultMarshaler.value;
				resultMarshaler.Dispose();
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public Antilatency.DeviceNetwork.Interop.Packet[] getAvailablePackets(out Antilatency.InterfaceContract.Bool taskFinished) {
				Antilatency.DeviceNetwork.Interop.Packet[] result;
				var resultMarshaler = Antilatency.InterfaceContract.Details.ArrayOutMarshaler.create<Antilatency.DeviceNetwork.Interop.Packet>();
				Antilatency.InterfaceContract.Bool taskFinishedMarshaler;
				var interfaceContractExceptionCode = (_VMT.getAvailablePackets(_object, out taskFinishedMarshaler, resultMarshaler));
				taskFinished = taskFinishedMarshaler;
				result = resultMarshaler.value;
				resultMarshaler.Dispose();
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public Antilatency.InterfaceContract.Bool writePacket(Antilatency.DeviceNetwork.Interop.Packet packet) {
				Antilatency.InterfaceContract.Bool result;
				Antilatency.InterfaceContract.Bool resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.writePacket(_object, packet, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
		}
		public class ISynchronousConnectionRemap : Antilatency.InterfaceContract.Details.IInterfaceRemap {
			public new struct VMT {
				public delegate Antilatency.InterfaceContract.ExceptionCode getPacketsDelegate(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result);
				public delegate Antilatency.InterfaceContract.ExceptionCode getAvailablePacketsDelegate(System.IntPtr _this, out Antilatency.InterfaceContract.Bool taskFinished, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result);
				public delegate Antilatency.InterfaceContract.ExceptionCode writePacketDelegate(System.IntPtr _this, Antilatency.DeviceNetwork.Interop.Packet packet, out Antilatency.InterfaceContract.Bool result);
				#pragma warning disable 0649
				public getPacketsDelegate getPackets;
				public getAvailablePacketsDelegate getAvailablePackets;
				public writePacketDelegate writePacket;
				#pragma warning restore 0649
			}
			public new static readonly NativeInterfaceVmt NativeVmt;
			static ISynchronousConnectionRemap() {
				var vmtBlocks = new System.Collections.Generic.List<object>();
				AppendVmt(vmtBlocks);
				NativeVmt = new NativeInterfaceVmt(vmtBlocks);
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getPacketsDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getPackets(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result) {
				try {
					var obj = GetContext(_this) as ISynchronousConnection;
					var resultMarshaler = obj.getPackets();
					result.assign(resultMarshaler);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getAvailablePacketsDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getAvailablePackets(System.IntPtr _this, out Antilatency.InterfaceContract.Bool taskFinished, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result) {
				try {
					var obj = GetContext(_this) as ISynchronousConnection;
					Antilatency.InterfaceContract.Bool taskFinishedMarshaler;
					taskFinished = default(Antilatency.InterfaceContract.Bool);
					var resultMarshaler = obj.getAvailablePackets(out taskFinishedMarshaler);
					taskFinished = taskFinishedMarshaler;
					result.assign(resultMarshaler);
				}
				catch (System.Exception ex) {
					taskFinished = default(Antilatency.InterfaceContract.Bool);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.writePacketDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode writePacket(System.IntPtr _this, Antilatency.DeviceNetwork.Interop.Packet packet, out Antilatency.InterfaceContract.Bool result) {
				try {
					var obj = GetContext(_this) as ISynchronousConnection;
					var resultMarshaler = obj.writePacket(packet);
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
				vmt.getPackets = getPackets;
				vmt.getAvailablePackets = getAvailablePackets;
				vmt.writePacket = writePacket;
				buffer.Add(vmt);
			}
			public ISynchronousConnectionRemap() { }
			public ISynchronousConnectionRemap(System.IntPtr context, ushort lifetimeId) {
				AllocateNativeInterface(NativeVmt.Handle, context, lifetimeId);
			}
		}
	}
}

namespace Antilatency.DeviceNetwork {
	[Guid("fd95f649-562a-4819-a816-26b76cd9d8d6")]
	[Antilatency.InterfaceContract.InterfaceId("fd95f649-562a-4819-a816-26b76cd9d8d6")]
	public interface ICotask : Antilatency.InterfaceContract.IInterface {
		Antilatency.InterfaceContract.Bool isTaskFinished();
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_DeviceNetwork_ICotask_InterfaceID = new System.Guid("fd95f649-562a-4819-a816-26b76cd9d8d6");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.DeviceNetwork.ICotask result) {
		var guid = Antilatency_DeviceNetwork_ICotask_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.DeviceNetwork.Details.ICotaskWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.DeviceNetwork.ICotask result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_DeviceNetwork_ICotask_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.DeviceNetwork.Details.ICotaskWrapper(ptr);
		}
	}
}
namespace Antilatency.DeviceNetwork {
	namespace Details {
		public class ICotaskWrapper : Antilatency.InterfaceContract.Details.IInterfaceWrapper, ICotask {
			private ICotaskRemap.VMT _VMT = new ICotaskRemap.VMT();
			protected new int GetTotalNativeMethodsCount() {
			    return base.GetTotalNativeMethodsCount() + typeof(ICotaskRemap.VMT).GetFields().Length;
			}
			public ICotaskWrapper(System.IntPtr obj) : base(obj) {
			    _VMT = LoadVMT<ICotaskRemap.VMT>(base.GetTotalNativeMethodsCount());
			}
			public Antilatency.InterfaceContract.Bool isTaskFinished() {
				Antilatency.InterfaceContract.Bool result;
				Antilatency.InterfaceContract.Bool resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.isTaskFinished(_object, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
		}
		public class ICotaskRemap : Antilatency.InterfaceContract.Details.IInterfaceRemap {
			public new struct VMT {
				public delegate Antilatency.InterfaceContract.ExceptionCode isTaskFinishedDelegate(System.IntPtr _this, out Antilatency.InterfaceContract.Bool result);
				#pragma warning disable 0649
				public isTaskFinishedDelegate isTaskFinished;
				#pragma warning restore 0649
			}
			public new static readonly NativeInterfaceVmt NativeVmt;
			static ICotaskRemap() {
				var vmtBlocks = new System.Collections.Generic.List<object>();
				AppendVmt(vmtBlocks);
				NativeVmt = new NativeInterfaceVmt(vmtBlocks);
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.isTaskFinishedDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode isTaskFinished(System.IntPtr _this, out Antilatency.InterfaceContract.Bool result) {
				try {
					var obj = GetContext(_this) as ICotask;
					var resultMarshaler = obj.isTaskFinished();
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
				vmt.isTaskFinished = isTaskFinished;
				buffer.Add(vmt);
			}
			public ICotaskRemap() { }
			public ICotaskRemap(System.IntPtr context, ushort lifetimeId) {
				AllocateNativeInterface(NativeVmt.Handle, context, lifetimeId);
			}
		}
	}
}

namespace Antilatency.DeviceNetwork {
	[Guid("c46779e1-0741-40a7-a146-301e8273b33f")]
	[Antilatency.InterfaceContract.InterfaceId("c46779e1-0741-40a7-a146-301e8273b33f")]
	public interface IPropertyCotask : Antilatency.DeviceNetwork.ICotask {
		string getPropertyKey(uint index);
		string getStringProperty(string key);
		void setStringProperty(string key, string value);
		byte[] getBinaryProperty(string key);
		void setBinaryProperty(string key, byte[] value);
		void deleteProperty(string key);
		Antilatency.IFutureString getPropertyKeyDeferred(uint index);
		Antilatency.IFutureString getStringPropertyDeferred(string key);
		Antilatency.IFuture setStringPropertyDeferred(string key, string value);
		Antilatency.IFutureArrayOfByte getBinaryPropertyDeferred(string key);
		Antilatency.IFuture setBinaryPropertyDeferred(string key, byte[] value);
		Antilatency.IFuture deletePropertyDeferred(string key);
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_DeviceNetwork_IPropertyCotask_InterfaceID = new System.Guid("c46779e1-0741-40a7-a146-301e8273b33f");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.DeviceNetwork.IPropertyCotask result) {
		var guid = Antilatency_DeviceNetwork_IPropertyCotask_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.DeviceNetwork.Details.IPropertyCotaskWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.DeviceNetwork.IPropertyCotask result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_DeviceNetwork_IPropertyCotask_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.DeviceNetwork.Details.IPropertyCotaskWrapper(ptr);
		}
	}
}
namespace Antilatency.DeviceNetwork {
	namespace Details {
		public class IPropertyCotaskWrapper : Antilatency.DeviceNetwork.Details.ICotaskWrapper, IPropertyCotask {
			private IPropertyCotaskRemap.VMT _VMT = new IPropertyCotaskRemap.VMT();
			protected new int GetTotalNativeMethodsCount() {
			    return base.GetTotalNativeMethodsCount() + typeof(IPropertyCotaskRemap.VMT).GetFields().Length;
			}
			public IPropertyCotaskWrapper(System.IntPtr obj) : base(obj) {
			    _VMT = LoadVMT<IPropertyCotaskRemap.VMT>(base.GetTotalNativeMethodsCount());
			}
			public string getPropertyKey(uint index) {
				string result;
				var resultMarshaler = Antilatency.InterfaceContract.Details.ArrayOutMarshaler.create();
				var interfaceContractExceptionCode = (_VMT.getPropertyKey(_object, index, resultMarshaler));
				result = resultMarshaler.value;
				resultMarshaler.Dispose();
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public string getStringProperty(string key) {
				string result;
				var resultMarshaler = Antilatency.InterfaceContract.Details.ArrayOutMarshaler.create();
				var keyMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(key);
				var interfaceContractExceptionCode = (_VMT.getStringProperty(_object, keyMarshaler, resultMarshaler));
				keyMarshaler.Dispose();
				result = resultMarshaler.value;
				resultMarshaler.Dispose();
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public void setStringProperty(string key, string value) {
				var keyMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(key);
				var valueMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(value);
				var interfaceContractExceptionCode = (_VMT.setStringProperty(_object, keyMarshaler, valueMarshaler));
				keyMarshaler.Dispose();
				valueMarshaler.Dispose();
				HandleExceptionCode(interfaceContractExceptionCode);
			}
			public byte[] getBinaryProperty(string key) {
				byte[] result;
				var resultMarshaler = Antilatency.InterfaceContract.Details.ArrayOutMarshaler.create<byte>();
				var keyMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(key);
				var interfaceContractExceptionCode = (_VMT.getBinaryProperty(_object, keyMarshaler, resultMarshaler));
				keyMarshaler.Dispose();
				result = resultMarshaler.value;
				resultMarshaler.Dispose();
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public void setBinaryProperty(string key, byte[] value) {
				var keyMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(key);
				var valueMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(value);
				var interfaceContractExceptionCode = (_VMT.setBinaryProperty(_object, keyMarshaler, valueMarshaler));
				keyMarshaler.Dispose();
				valueMarshaler.Dispose();
				HandleExceptionCode(interfaceContractExceptionCode);
			}
			public void deleteProperty(string key) {
				var keyMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(key);
				var interfaceContractExceptionCode = (_VMT.deleteProperty(_object, keyMarshaler));
				keyMarshaler.Dispose();
				HandleExceptionCode(interfaceContractExceptionCode);
			}
			public Antilatency.IFutureString getPropertyKeyDeferred(uint index) {
				Antilatency.IFutureString result;
				System.IntPtr resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.getPropertyKeyDeferred(_object, index, out resultMarshaler));
				result = (resultMarshaler==System.IntPtr.Zero) ? null : new Antilatency.Details.IFutureStringWrapper(resultMarshaler);
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public Antilatency.IFutureString getStringPropertyDeferred(string key) {
				Antilatency.IFutureString result;
				System.IntPtr resultMarshaler;
				var keyMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(key);
				var interfaceContractExceptionCode = (_VMT.getStringPropertyDeferred(_object, keyMarshaler, out resultMarshaler));
				keyMarshaler.Dispose();
				result = (resultMarshaler==System.IntPtr.Zero) ? null : new Antilatency.Details.IFutureStringWrapper(resultMarshaler);
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public Antilatency.IFuture setStringPropertyDeferred(string key, string value) {
				Antilatency.IFuture result;
				System.IntPtr resultMarshaler;
				var keyMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(key);
				var valueMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(value);
				var interfaceContractExceptionCode = (_VMT.setStringPropertyDeferred(_object, keyMarshaler, valueMarshaler, out resultMarshaler));
				keyMarshaler.Dispose();
				valueMarshaler.Dispose();
				result = (resultMarshaler==System.IntPtr.Zero) ? null : new Antilatency.Details.IFutureWrapper(resultMarshaler);
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public Antilatency.IFutureArrayOfByte getBinaryPropertyDeferred(string key) {
				Antilatency.IFutureArrayOfByte result;
				System.IntPtr resultMarshaler;
				var keyMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(key);
				var interfaceContractExceptionCode = (_VMT.getBinaryPropertyDeferred(_object, keyMarshaler, out resultMarshaler));
				keyMarshaler.Dispose();
				result = (resultMarshaler==System.IntPtr.Zero) ? null : new Antilatency.Details.IFutureArrayOfByteWrapper(resultMarshaler);
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public Antilatency.IFuture setBinaryPropertyDeferred(string key, byte[] value) {
				Antilatency.IFuture result;
				System.IntPtr resultMarshaler;
				var keyMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(key);
				var valueMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(value);
				var interfaceContractExceptionCode = (_VMT.setBinaryPropertyDeferred(_object, keyMarshaler, valueMarshaler, out resultMarshaler));
				keyMarshaler.Dispose();
				valueMarshaler.Dispose();
				result = (resultMarshaler==System.IntPtr.Zero) ? null : new Antilatency.Details.IFutureWrapper(resultMarshaler);
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public Antilatency.IFuture deletePropertyDeferred(string key) {
				Antilatency.IFuture result;
				System.IntPtr resultMarshaler;
				var keyMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(key);
				var interfaceContractExceptionCode = (_VMT.deletePropertyDeferred(_object, keyMarshaler, out resultMarshaler));
				keyMarshaler.Dispose();
				result = (resultMarshaler==System.IntPtr.Zero) ? null : new Antilatency.Details.IFutureWrapper(resultMarshaler);
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
		}
		public class IPropertyCotaskRemap : Antilatency.DeviceNetwork.Details.ICotaskRemap {
			public new struct VMT {
				public delegate Antilatency.InterfaceContract.ExceptionCode getPropertyKeyDelegate(System.IntPtr _this, uint index, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result);
				public delegate Antilatency.InterfaceContract.ExceptionCode getStringPropertyDelegate(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate key, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result);
				public delegate Antilatency.InterfaceContract.ExceptionCode setStringPropertyDelegate(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate key, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate value);
				public delegate Antilatency.InterfaceContract.ExceptionCode getBinaryPropertyDelegate(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate key, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result);
				public delegate Antilatency.InterfaceContract.ExceptionCode setBinaryPropertyDelegate(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate key, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate value);
				public delegate Antilatency.InterfaceContract.ExceptionCode deletePropertyDelegate(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate key);
				public delegate Antilatency.InterfaceContract.ExceptionCode getPropertyKeyDeferredDelegate(System.IntPtr _this, uint index, out System.IntPtr result);
				public delegate Antilatency.InterfaceContract.ExceptionCode getStringPropertyDeferredDelegate(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate key, out System.IntPtr result);
				public delegate Antilatency.InterfaceContract.ExceptionCode setStringPropertyDeferredDelegate(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate key, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate value, out System.IntPtr result);
				public delegate Antilatency.InterfaceContract.ExceptionCode getBinaryPropertyDeferredDelegate(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate key, out System.IntPtr result);
				public delegate Antilatency.InterfaceContract.ExceptionCode setBinaryPropertyDeferredDelegate(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate key, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate value, out System.IntPtr result);
				public delegate Antilatency.InterfaceContract.ExceptionCode deletePropertyDeferredDelegate(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate key, out System.IntPtr result);
				#pragma warning disable 0649
				public getPropertyKeyDelegate getPropertyKey;
				public getStringPropertyDelegate getStringProperty;
				public setStringPropertyDelegate setStringProperty;
				public getBinaryPropertyDelegate getBinaryProperty;
				public setBinaryPropertyDelegate setBinaryProperty;
				public deletePropertyDelegate deleteProperty;
				public getPropertyKeyDeferredDelegate getPropertyKeyDeferred;
				public getStringPropertyDeferredDelegate getStringPropertyDeferred;
				public setStringPropertyDeferredDelegate setStringPropertyDeferred;
				public getBinaryPropertyDeferredDelegate getBinaryPropertyDeferred;
				public setBinaryPropertyDeferredDelegate setBinaryPropertyDeferred;
				public deletePropertyDeferredDelegate deletePropertyDeferred;
				#pragma warning restore 0649
			}
			public new static readonly NativeInterfaceVmt NativeVmt;
			static IPropertyCotaskRemap() {
				var vmtBlocks = new System.Collections.Generic.List<object>();
				AppendVmt(vmtBlocks);
				NativeVmt = new NativeInterfaceVmt(vmtBlocks);
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getPropertyKeyDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getPropertyKey(System.IntPtr _this, uint index, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result) {
				try {
					var obj = GetContext(_this) as IPropertyCotask;
					var resultMarshaler = obj.getPropertyKey(index);
					result.assign(resultMarshaler);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getStringPropertyDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getStringProperty(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate key, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result) {
				try {
					var obj = GetContext(_this) as IPropertyCotask;
					var resultMarshaler = obj.getStringProperty(key);
					result.assign(resultMarshaler);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.setStringPropertyDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode setStringProperty(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate key, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate value) {
				try {
					var obj = GetContext(_this) as IPropertyCotask;
					obj.setStringProperty(key, value);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getBinaryPropertyDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getBinaryProperty(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate key, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result) {
				try {
					var obj = GetContext(_this) as IPropertyCotask;
					var resultMarshaler = obj.getBinaryProperty(key);
					result.assign(resultMarshaler);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.setBinaryPropertyDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode setBinaryProperty(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate key, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate value) {
				try {
					var obj = GetContext(_this) as IPropertyCotask;
					obj.setBinaryProperty(key, value.toArray<byte>());
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.deletePropertyDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode deleteProperty(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate key) {
				try {
					var obj = GetContext(_this) as IPropertyCotask;
					obj.deleteProperty(key);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getPropertyKeyDeferredDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getPropertyKeyDeferred(System.IntPtr _this, uint index, out System.IntPtr result) {
				try {
					var obj = GetContext(_this) as IPropertyCotask;
					var resultMarshaler = obj.getPropertyKeyDeferred(index);
					result = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.IFutureString>(resultMarshaler);
				}
				catch (System.Exception ex) {
					result = default(System.IntPtr);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getStringPropertyDeferredDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getStringPropertyDeferred(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate key, out System.IntPtr result) {
				try {
					var obj = GetContext(_this) as IPropertyCotask;
					var resultMarshaler = obj.getStringPropertyDeferred(key);
					result = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.IFutureString>(resultMarshaler);
				}
				catch (System.Exception ex) {
					result = default(System.IntPtr);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.setStringPropertyDeferredDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode setStringPropertyDeferred(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate key, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate value, out System.IntPtr result) {
				try {
					var obj = GetContext(_this) as IPropertyCotask;
					var resultMarshaler = obj.setStringPropertyDeferred(key, value);
					result = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.IFuture>(resultMarshaler);
				}
				catch (System.Exception ex) {
					result = default(System.IntPtr);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getBinaryPropertyDeferredDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getBinaryPropertyDeferred(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate key, out System.IntPtr result) {
				try {
					var obj = GetContext(_this) as IPropertyCotask;
					var resultMarshaler = obj.getBinaryPropertyDeferred(key);
					result = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.IFutureArrayOfByte>(resultMarshaler);
				}
				catch (System.Exception ex) {
					result = default(System.IntPtr);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.setBinaryPropertyDeferredDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode setBinaryPropertyDeferred(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate key, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate value, out System.IntPtr result) {
				try {
					var obj = GetContext(_this) as IPropertyCotask;
					var resultMarshaler = obj.setBinaryPropertyDeferred(key, value.toArray<byte>());
					result = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.IFuture>(resultMarshaler);
				}
				catch (System.Exception ex) {
					result = default(System.IntPtr);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.deletePropertyDeferredDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode deletePropertyDeferred(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate key, out System.IntPtr result) {
				try {
					var obj = GetContext(_this) as IPropertyCotask;
					var resultMarshaler = obj.deletePropertyDeferred(key);
					result = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.IFuture>(resultMarshaler);
				}
				catch (System.Exception ex) {
					result = default(System.IntPtr);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			protected static new void AppendVmt(System.Collections.Generic.List<object> buffer) {
				Antilatency.DeviceNetwork.Details.ICotaskRemap.AppendVmt(buffer);
				var vmt = new VMT();
				vmt.getPropertyKey = getPropertyKey;
				vmt.getStringProperty = getStringProperty;
				vmt.setStringProperty = setStringProperty;
				vmt.getBinaryProperty = getBinaryProperty;
				vmt.setBinaryProperty = setBinaryProperty;
				vmt.deleteProperty = deleteProperty;
				vmt.getPropertyKeyDeferred = getPropertyKeyDeferred;
				vmt.getStringPropertyDeferred = getStringPropertyDeferred;
				vmt.setStringPropertyDeferred = setStringPropertyDeferred;
				vmt.getBinaryPropertyDeferred = getBinaryPropertyDeferred;
				vmt.setBinaryPropertyDeferred = setBinaryPropertyDeferred;
				vmt.deletePropertyDeferred = deletePropertyDeferred;
				buffer.Add(vmt);
			}
			public IPropertyCotaskRemap() { }
			public IPropertyCotaskRemap(System.IntPtr context, ushort lifetimeId) {
				AllocateNativeInterface(NativeVmt.Handle, context, lifetimeId);
			}
		}
	}
}

namespace Antilatency.DeviceNetwork {
	[Guid("eb7f3989-5cb7-42ea-9110-52d712f39ce8")]
	[Antilatency.InterfaceContract.InterfaceId("eb7f3989-5cb7-42ea-9110-52d712f39ce8")]
	public interface INetwork : Antilatency.InterfaceContract.IInterface {
		uint getUpdateId();
		ulong getCurrentTime();
		Antilatency.DeviceNetwork.IDeviceFilter getDeviceFilter();
		Antilatency.DeviceNetwork.NodeHandle[] getNodes();
		Antilatency.DeviceNetwork.NodeStatus nodeGetStatus(Antilatency.DeviceNetwork.NodeHandle node);
		float nodeGetCurrentOutofsyncTime(Antilatency.DeviceNetwork.NodeHandle node);
		Antilatency.InterfaceContract.Bool nodeIsTaskSupported(Antilatency.DeviceNetwork.NodeHandle node, System.Guid taskId);
		Antilatency.DeviceNetwork.NodeHandle nodeGetParent(Antilatency.DeviceNetwork.NodeHandle node);
		string nodeGetPhysicalPath(Antilatency.DeviceNetwork.NodeHandle node);
		Antilatency.DeviceNetwork.Interop.IDataReceiver nodeStartTask(Antilatency.DeviceNetwork.NodeHandle node, System.Guid taskId, Antilatency.DeviceNetwork.Interop.IDataReceiver taskDataReceiver);
		Antilatency.DeviceNetwork.ISynchronousConnection nodeStartTask2(Antilatency.DeviceNetwork.NodeHandle node, System.Guid taskId);
		string nodeGetStringProperty(Antilatency.DeviceNetwork.NodeHandle node, string key);
		byte[] nodeGetBinaryProperty(Antilatency.DeviceNetwork.NodeHandle node, string key);
		Antilatency.DeviceNetwork.IPropertyCotask nodeStartPropertyTask(Antilatency.DeviceNetwork.NodeHandle node);
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_DeviceNetwork_INetwork_InterfaceID = new System.Guid("eb7f3989-5cb7-42ea-9110-52d712f39ce8");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.DeviceNetwork.INetwork result) {
		var guid = Antilatency_DeviceNetwork_INetwork_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.DeviceNetwork.Details.INetworkWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.DeviceNetwork.INetwork result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_DeviceNetwork_INetwork_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.DeviceNetwork.Details.INetworkWrapper(ptr);
		}
	}
}
namespace Antilatency.DeviceNetwork {
	namespace Details {
		public class INetworkWrapper : Antilatency.InterfaceContract.Details.IInterfaceWrapper, INetwork {
			private INetworkRemap.VMT _VMT = new INetworkRemap.VMT();
			protected new int GetTotalNativeMethodsCount() {
			    return base.GetTotalNativeMethodsCount() + typeof(INetworkRemap.VMT).GetFields().Length;
			}
			public INetworkWrapper(System.IntPtr obj) : base(obj) {
			    _VMT = LoadVMT<INetworkRemap.VMT>(base.GetTotalNativeMethodsCount());
			}
			public uint getUpdateId() {
				uint result;
				uint resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.getUpdateId(_object, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public ulong getCurrentTime() {
				ulong result;
				ulong resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.getCurrentTime(_object, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public Antilatency.DeviceNetwork.IDeviceFilter getDeviceFilter() {
				Antilatency.DeviceNetwork.IDeviceFilter result;
				System.IntPtr resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.getDeviceFilter(_object, out resultMarshaler));
				result = (resultMarshaler==System.IntPtr.Zero) ? null : new Antilatency.DeviceNetwork.Details.IDeviceFilterWrapper(resultMarshaler);
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public Antilatency.DeviceNetwork.NodeHandle[] getNodes() {
				Antilatency.DeviceNetwork.NodeHandle[] result;
				var resultMarshaler = Antilatency.InterfaceContract.Details.ArrayOutMarshaler.create<Antilatency.DeviceNetwork.NodeHandle>();
				var interfaceContractExceptionCode = (_VMT.getNodes(_object, resultMarshaler));
				result = resultMarshaler.value;
				resultMarshaler.Dispose();
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public Antilatency.DeviceNetwork.NodeStatus nodeGetStatus(Antilatency.DeviceNetwork.NodeHandle node) {
				Antilatency.DeviceNetwork.NodeStatus result;
				Antilatency.DeviceNetwork.NodeStatus resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.nodeGetStatus(_object, node, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public float nodeGetCurrentOutofsyncTime(Antilatency.DeviceNetwork.NodeHandle node) {
				float result;
				float resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.nodeGetCurrentOutofsyncTime(_object, node, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public Antilatency.InterfaceContract.Bool nodeIsTaskSupported(Antilatency.DeviceNetwork.NodeHandle node, System.Guid taskId) {
				Antilatency.InterfaceContract.Bool result;
				Antilatency.InterfaceContract.Bool resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.nodeIsTaskSupported(_object, node, taskId, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public Antilatency.DeviceNetwork.NodeHandle nodeGetParent(Antilatency.DeviceNetwork.NodeHandle node) {
				Antilatency.DeviceNetwork.NodeHandle result;
				Antilatency.DeviceNetwork.NodeHandle resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.nodeGetParent(_object, node, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public string nodeGetPhysicalPath(Antilatency.DeviceNetwork.NodeHandle node) {
				string result;
				var resultMarshaler = Antilatency.InterfaceContract.Details.ArrayOutMarshaler.create();
				var interfaceContractExceptionCode = (_VMT.nodeGetPhysicalPath(_object, node, resultMarshaler));
				result = resultMarshaler.value;
				resultMarshaler.Dispose();
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public Antilatency.DeviceNetwork.Interop.IDataReceiver nodeStartTask(Antilatency.DeviceNetwork.NodeHandle node, System.Guid taskId, Antilatency.DeviceNetwork.Interop.IDataReceiver taskDataReceiver) {
				Antilatency.DeviceNetwork.Interop.IDataReceiver result;
				System.IntPtr resultMarshaler;
				var taskDataReceiverMarshaler = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.DeviceNetwork.Interop.IDataReceiver>(taskDataReceiver);
				var interfaceContractExceptionCode = (_VMT.nodeStartTask(_object, node, taskId, taskDataReceiverMarshaler, out resultMarshaler));
				result = (resultMarshaler==System.IntPtr.Zero) ? null : new Antilatency.DeviceNetwork.Interop.Details.IDataReceiverWrapper(resultMarshaler);
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public Antilatency.DeviceNetwork.ISynchronousConnection nodeStartTask2(Antilatency.DeviceNetwork.NodeHandle node, System.Guid taskId) {
				Antilatency.DeviceNetwork.ISynchronousConnection result;
				System.IntPtr resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.nodeStartTask2(_object, node, taskId, out resultMarshaler));
				result = (resultMarshaler==System.IntPtr.Zero) ? null : new Antilatency.DeviceNetwork.Details.ISynchronousConnectionWrapper(resultMarshaler);
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public string nodeGetStringProperty(Antilatency.DeviceNetwork.NodeHandle node, string key) {
				string result;
				var resultMarshaler = Antilatency.InterfaceContract.Details.ArrayOutMarshaler.create();
				var keyMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(key);
				var interfaceContractExceptionCode = (_VMT.nodeGetStringProperty(_object, node, keyMarshaler, resultMarshaler));
				keyMarshaler.Dispose();
				result = resultMarshaler.value;
				resultMarshaler.Dispose();
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public byte[] nodeGetBinaryProperty(Antilatency.DeviceNetwork.NodeHandle node, string key) {
				byte[] result;
				var resultMarshaler = Antilatency.InterfaceContract.Details.ArrayOutMarshaler.create<byte>();
				var keyMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(key);
				var interfaceContractExceptionCode = (_VMT.nodeGetBinaryProperty(_object, node, keyMarshaler, resultMarshaler));
				keyMarshaler.Dispose();
				result = resultMarshaler.value;
				resultMarshaler.Dispose();
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public Antilatency.DeviceNetwork.IPropertyCotask nodeStartPropertyTask(Antilatency.DeviceNetwork.NodeHandle node) {
				Antilatency.DeviceNetwork.IPropertyCotask result;
				System.IntPtr resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.nodeStartPropertyTask(_object, node, out resultMarshaler));
				result = (resultMarshaler==System.IntPtr.Zero) ? null : new Antilatency.DeviceNetwork.Details.IPropertyCotaskWrapper(resultMarshaler);
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
		}
		public class INetworkRemap : Antilatency.InterfaceContract.Details.IInterfaceRemap {
			public new struct VMT {
				public delegate Antilatency.InterfaceContract.ExceptionCode getUpdateIdDelegate(System.IntPtr _this, out uint result);
				public delegate Antilatency.InterfaceContract.ExceptionCode getCurrentTimeDelegate(System.IntPtr _this, out ulong result);
				public delegate Antilatency.InterfaceContract.ExceptionCode getDeviceFilterDelegate(System.IntPtr _this, out System.IntPtr result);
				public delegate Antilatency.InterfaceContract.ExceptionCode getNodesDelegate(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result);
				public delegate Antilatency.InterfaceContract.ExceptionCode nodeGetStatusDelegate(System.IntPtr _this, Antilatency.DeviceNetwork.NodeHandle node, out Antilatency.DeviceNetwork.NodeStatus result);
				public delegate Antilatency.InterfaceContract.ExceptionCode nodeGetCurrentOutofsyncTimeDelegate(System.IntPtr _this, Antilatency.DeviceNetwork.NodeHandle node, out float result);
				public delegate Antilatency.InterfaceContract.ExceptionCode nodeIsTaskSupportedDelegate(System.IntPtr _this, Antilatency.DeviceNetwork.NodeHandle node, System.Guid taskId, out Antilatency.InterfaceContract.Bool result);
				public delegate Antilatency.InterfaceContract.ExceptionCode nodeGetParentDelegate(System.IntPtr _this, Antilatency.DeviceNetwork.NodeHandle node, out Antilatency.DeviceNetwork.NodeHandle result);
				public delegate Antilatency.InterfaceContract.ExceptionCode nodeGetPhysicalPathDelegate(System.IntPtr _this, Antilatency.DeviceNetwork.NodeHandle node, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result);
				public delegate Antilatency.InterfaceContract.ExceptionCode nodeStartTaskDelegate(System.IntPtr _this, Antilatency.DeviceNetwork.NodeHandle node, System.Guid taskId, System.IntPtr taskDataReceiver, out System.IntPtr result);
				public delegate Antilatency.InterfaceContract.ExceptionCode nodeStartTask2Delegate(System.IntPtr _this, Antilatency.DeviceNetwork.NodeHandle node, System.Guid taskId, out System.IntPtr result);
				public delegate Antilatency.InterfaceContract.ExceptionCode nodeGetStringPropertyDelegate(System.IntPtr _this, Antilatency.DeviceNetwork.NodeHandle node, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate key, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result);
				public delegate Antilatency.InterfaceContract.ExceptionCode nodeGetBinaryPropertyDelegate(System.IntPtr _this, Antilatency.DeviceNetwork.NodeHandle node, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate key, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result);
				public delegate Antilatency.InterfaceContract.ExceptionCode nodeStartPropertyTaskDelegate(System.IntPtr _this, Antilatency.DeviceNetwork.NodeHandle node, out System.IntPtr result);
				#pragma warning disable 0649
				public getUpdateIdDelegate getUpdateId;
				public getCurrentTimeDelegate getCurrentTime;
				public getDeviceFilterDelegate getDeviceFilter;
				public getNodesDelegate getNodes;
				public nodeGetStatusDelegate nodeGetStatus;
				public nodeGetCurrentOutofsyncTimeDelegate nodeGetCurrentOutofsyncTime;
				public nodeIsTaskSupportedDelegate nodeIsTaskSupported;
				public nodeGetParentDelegate nodeGetParent;
				public nodeGetPhysicalPathDelegate nodeGetPhysicalPath;
				public nodeStartTaskDelegate nodeStartTask;
				public nodeStartTask2Delegate nodeStartTask2;
				public nodeGetStringPropertyDelegate nodeGetStringProperty;
				public nodeGetBinaryPropertyDelegate nodeGetBinaryProperty;
				public nodeStartPropertyTaskDelegate nodeStartPropertyTask;
				#pragma warning restore 0649
			}
			public new static readonly NativeInterfaceVmt NativeVmt;
			static INetworkRemap() {
				var vmtBlocks = new System.Collections.Generic.List<object>();
				AppendVmt(vmtBlocks);
				NativeVmt = new NativeInterfaceVmt(vmtBlocks);
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getUpdateIdDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getUpdateId(System.IntPtr _this, out uint result) {
				try {
					var obj = GetContext(_this) as INetwork;
					var resultMarshaler = obj.getUpdateId();
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(uint);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getCurrentTimeDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getCurrentTime(System.IntPtr _this, out ulong result) {
				try {
					var obj = GetContext(_this) as INetwork;
					var resultMarshaler = obj.getCurrentTime();
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(ulong);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getDeviceFilterDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getDeviceFilter(System.IntPtr _this, out System.IntPtr result) {
				try {
					var obj = GetContext(_this) as INetwork;
					var resultMarshaler = obj.getDeviceFilter();
					result = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.DeviceNetwork.IDeviceFilter>(resultMarshaler);
				}
				catch (System.Exception ex) {
					result = default(System.IntPtr);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getNodesDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getNodes(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result) {
				try {
					var obj = GetContext(_this) as INetwork;
					var resultMarshaler = obj.getNodes();
					result.assign(resultMarshaler);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.nodeGetStatusDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode nodeGetStatus(System.IntPtr _this, Antilatency.DeviceNetwork.NodeHandle node, out Antilatency.DeviceNetwork.NodeStatus result) {
				try {
					var obj = GetContext(_this) as INetwork;
					var resultMarshaler = obj.nodeGetStatus(node);
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(Antilatency.DeviceNetwork.NodeStatus);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.nodeGetCurrentOutofsyncTimeDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode nodeGetCurrentOutofsyncTime(System.IntPtr _this, Antilatency.DeviceNetwork.NodeHandle node, out float result) {
				try {
					var obj = GetContext(_this) as INetwork;
					var resultMarshaler = obj.nodeGetCurrentOutofsyncTime(node);
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(float);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.nodeIsTaskSupportedDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode nodeIsTaskSupported(System.IntPtr _this, Antilatency.DeviceNetwork.NodeHandle node, System.Guid taskId, out Antilatency.InterfaceContract.Bool result) {
				try {
					var obj = GetContext(_this) as INetwork;
					var resultMarshaler = obj.nodeIsTaskSupported(node, taskId);
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(Antilatency.InterfaceContract.Bool);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.nodeGetParentDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode nodeGetParent(System.IntPtr _this, Antilatency.DeviceNetwork.NodeHandle node, out Antilatency.DeviceNetwork.NodeHandle result) {
				try {
					var obj = GetContext(_this) as INetwork;
					var resultMarshaler = obj.nodeGetParent(node);
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(Antilatency.DeviceNetwork.NodeHandle);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.nodeGetPhysicalPathDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode nodeGetPhysicalPath(System.IntPtr _this, Antilatency.DeviceNetwork.NodeHandle node, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result) {
				try {
					var obj = GetContext(_this) as INetwork;
					var resultMarshaler = obj.nodeGetPhysicalPath(node);
					result.assign(resultMarshaler);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.nodeStartTaskDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode nodeStartTask(System.IntPtr _this, Antilatency.DeviceNetwork.NodeHandle node, System.Guid taskId, System.IntPtr taskDataReceiver, out System.IntPtr result) {
				try {
					var obj = GetContext(_this) as INetwork;
					var taskDataReceiverMarshaler = taskDataReceiver == System.IntPtr.Zero ? null : new Antilatency.DeviceNetwork.Interop.Details.IDataReceiverWrapper(taskDataReceiver);
					var resultMarshaler = obj.nodeStartTask(node, taskId, taskDataReceiverMarshaler);
					result = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.DeviceNetwork.Interop.IDataReceiver>(resultMarshaler);
				}
				catch (System.Exception ex) {
					result = default(System.IntPtr);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.nodeStartTask2Delegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode nodeStartTask2(System.IntPtr _this, Antilatency.DeviceNetwork.NodeHandle node, System.Guid taskId, out System.IntPtr result) {
				try {
					var obj = GetContext(_this) as INetwork;
					var resultMarshaler = obj.nodeStartTask2(node, taskId);
					result = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.DeviceNetwork.ISynchronousConnection>(resultMarshaler);
				}
				catch (System.Exception ex) {
					result = default(System.IntPtr);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.nodeGetStringPropertyDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode nodeGetStringProperty(System.IntPtr _this, Antilatency.DeviceNetwork.NodeHandle node, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate key, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result) {
				try {
					var obj = GetContext(_this) as INetwork;
					var resultMarshaler = obj.nodeGetStringProperty(node, key);
					result.assign(resultMarshaler);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.nodeGetBinaryPropertyDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode nodeGetBinaryProperty(System.IntPtr _this, Antilatency.DeviceNetwork.NodeHandle node, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate key, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result) {
				try {
					var obj = GetContext(_this) as INetwork;
					var resultMarshaler = obj.nodeGetBinaryProperty(node, key);
					result.assign(resultMarshaler);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.nodeStartPropertyTaskDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode nodeStartPropertyTask(System.IntPtr _this, Antilatency.DeviceNetwork.NodeHandle node, out System.IntPtr result) {
				try {
					var obj = GetContext(_this) as INetwork;
					var resultMarshaler = obj.nodeStartPropertyTask(node);
					result = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.DeviceNetwork.IPropertyCotask>(resultMarshaler);
				}
				catch (System.Exception ex) {
					result = default(System.IntPtr);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			protected static new void AppendVmt(System.Collections.Generic.List<object> buffer) {
				Antilatency.InterfaceContract.Details.IInterfaceRemap.AppendVmt(buffer);
				var vmt = new VMT();
				vmt.getUpdateId = getUpdateId;
				vmt.getCurrentTime = getCurrentTime;
				vmt.getDeviceFilter = getDeviceFilter;
				vmt.getNodes = getNodes;
				vmt.nodeGetStatus = nodeGetStatus;
				vmt.nodeGetCurrentOutofsyncTime = nodeGetCurrentOutofsyncTime;
				vmt.nodeIsTaskSupported = nodeIsTaskSupported;
				vmt.nodeGetParent = nodeGetParent;
				vmt.nodeGetPhysicalPath = nodeGetPhysicalPath;
				vmt.nodeStartTask = nodeStartTask;
				vmt.nodeStartTask2 = nodeStartTask2;
				vmt.nodeGetStringProperty = nodeGetStringProperty;
				vmt.nodeGetBinaryProperty = nodeGetBinaryProperty;
				vmt.nodeStartPropertyTask = nodeStartPropertyTask;
				buffer.Add(vmt);
			}
			public INetworkRemap() { }
			public INetworkRemap(System.IntPtr context, ushort lifetimeId) {
				AllocateNativeInterface(NativeVmt.Handle, context, lifetimeId);
			}
		}
	}
}

namespace Antilatency.DeviceNetwork {
	[Guid("9ecfa909-d13c-4c29-a87e-8925b7846638")]
	[Antilatency.InterfaceContract.InterfaceId("9ecfa909-d13c-4c29-a87e-8925b7846638")]
	public interface ICotaskConstructor : Antilatency.InterfaceContract.IInterface {
		Antilatency.InterfaceContract.Bool isSupported(Antilatency.DeviceNetwork.INetwork network, Antilatency.DeviceNetwork.NodeHandle node);
		Antilatency.DeviceNetwork.NodeHandle[] findSupportedNodes(Antilatency.DeviceNetwork.INetwork network);
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_DeviceNetwork_ICotaskConstructor_InterfaceID = new System.Guid("9ecfa909-d13c-4c29-a87e-8925b7846638");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.DeviceNetwork.ICotaskConstructor result) {
		var guid = Antilatency_DeviceNetwork_ICotaskConstructor_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.DeviceNetwork.Details.ICotaskConstructorWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.DeviceNetwork.ICotaskConstructor result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_DeviceNetwork_ICotaskConstructor_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.DeviceNetwork.Details.ICotaskConstructorWrapper(ptr);
		}
	}
}
namespace Antilatency.DeviceNetwork {
	namespace Details {
		public class ICotaskConstructorWrapper : Antilatency.InterfaceContract.Details.IInterfaceWrapper, ICotaskConstructor {
			private ICotaskConstructorRemap.VMT _VMT = new ICotaskConstructorRemap.VMT();
			protected new int GetTotalNativeMethodsCount() {
			    return base.GetTotalNativeMethodsCount() + typeof(ICotaskConstructorRemap.VMT).GetFields().Length;
			}
			public ICotaskConstructorWrapper(System.IntPtr obj) : base(obj) {
			    _VMT = LoadVMT<ICotaskConstructorRemap.VMT>(base.GetTotalNativeMethodsCount());
			}
			public Antilatency.InterfaceContract.Bool isSupported(Antilatency.DeviceNetwork.INetwork network, Antilatency.DeviceNetwork.NodeHandle node) {
				Antilatency.InterfaceContract.Bool result;
				Antilatency.InterfaceContract.Bool resultMarshaler;
				var networkMarshaler = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.DeviceNetwork.INetwork>(network);
				var interfaceContractExceptionCode = (_VMT.isSupported(_object, networkMarshaler, node, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public Antilatency.DeviceNetwork.NodeHandle[] findSupportedNodes(Antilatency.DeviceNetwork.INetwork network) {
				Antilatency.DeviceNetwork.NodeHandle[] result;
				var resultMarshaler = Antilatency.InterfaceContract.Details.ArrayOutMarshaler.create<Antilatency.DeviceNetwork.NodeHandle>();
				var networkMarshaler = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.DeviceNetwork.INetwork>(network);
				var interfaceContractExceptionCode = (_VMT.findSupportedNodes(_object, networkMarshaler, resultMarshaler));
				result = resultMarshaler.value;
				resultMarshaler.Dispose();
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
		}
		public class ICotaskConstructorRemap : Antilatency.InterfaceContract.Details.IInterfaceRemap {
			public new struct VMT {
				public delegate Antilatency.InterfaceContract.ExceptionCode isSupportedDelegate(System.IntPtr _this, System.IntPtr network, Antilatency.DeviceNetwork.NodeHandle node, out Antilatency.InterfaceContract.Bool result);
				public delegate Antilatency.InterfaceContract.ExceptionCode findSupportedNodesDelegate(System.IntPtr _this, System.IntPtr network, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result);
				#pragma warning disable 0649
				public isSupportedDelegate isSupported;
				public findSupportedNodesDelegate findSupportedNodes;
				#pragma warning restore 0649
			}
			public new static readonly NativeInterfaceVmt NativeVmt;
			static ICotaskConstructorRemap() {
				var vmtBlocks = new System.Collections.Generic.List<object>();
				AppendVmt(vmtBlocks);
				NativeVmt = new NativeInterfaceVmt(vmtBlocks);
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.isSupportedDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode isSupported(System.IntPtr _this, System.IntPtr network, Antilatency.DeviceNetwork.NodeHandle node, out Antilatency.InterfaceContract.Bool result) {
				try {
					var obj = GetContext(_this) as ICotaskConstructor;
					var networkMarshaler = network == System.IntPtr.Zero ? null : new Antilatency.DeviceNetwork.Details.INetworkWrapper(network);
					var resultMarshaler = obj.isSupported(networkMarshaler, node);
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(Antilatency.InterfaceContract.Bool);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.findSupportedNodesDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode findSupportedNodes(System.IntPtr _this, System.IntPtr network, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result) {
				try {
					var obj = GetContext(_this) as ICotaskConstructor;
					var networkMarshaler = network == System.IntPtr.Zero ? null : new Antilatency.DeviceNetwork.Details.INetworkWrapper(network);
					var resultMarshaler = obj.findSupportedNodes(networkMarshaler);
					result.assign(resultMarshaler);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			protected static new void AppendVmt(System.Collections.Generic.List<object> buffer) {
				Antilatency.InterfaceContract.Details.IInterfaceRemap.AppendVmt(buffer);
				var vmt = new VMT();
				vmt.isSupported = isSupported;
				vmt.findSupportedNodes = findSupportedNodes;
				buffer.Add(vmt);
			}
			public ICotaskConstructorRemap() { }
			public ICotaskConstructorRemap(System.IntPtr context, ushort lifetimeId) {
				AllocateNativeInterface(NativeVmt.Handle, context, lifetimeId);
			}
		}
	}
}

namespace Antilatency.DeviceNetwork {
	[Guid("1f3f7579-813e-4528-82f9-5a5fc35a9295")]
	[Antilatency.InterfaceContract.InterfaceId("1f3f7579-813e-4528-82f9-5a5fc35a9295")]
	public interface ICotaskBatteryPowered : Antilatency.DeviceNetwork.ICotask {
		float getBatteryLevel();
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_DeviceNetwork_ICotaskBatteryPowered_InterfaceID = new System.Guid("1f3f7579-813e-4528-82f9-5a5fc35a9295");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.DeviceNetwork.ICotaskBatteryPowered result) {
		var guid = Antilatency_DeviceNetwork_ICotaskBatteryPowered_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.DeviceNetwork.Details.ICotaskBatteryPoweredWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.DeviceNetwork.ICotaskBatteryPowered result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_DeviceNetwork_ICotaskBatteryPowered_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.DeviceNetwork.Details.ICotaskBatteryPoweredWrapper(ptr);
		}
	}
}
namespace Antilatency.DeviceNetwork {
	namespace Details {
		public class ICotaskBatteryPoweredWrapper : Antilatency.DeviceNetwork.Details.ICotaskWrapper, ICotaskBatteryPowered {
			private ICotaskBatteryPoweredRemap.VMT _VMT = new ICotaskBatteryPoweredRemap.VMT();
			protected new int GetTotalNativeMethodsCount() {
			    return base.GetTotalNativeMethodsCount() + typeof(ICotaskBatteryPoweredRemap.VMT).GetFields().Length;
			}
			public ICotaskBatteryPoweredWrapper(System.IntPtr obj) : base(obj) {
			    _VMT = LoadVMT<ICotaskBatteryPoweredRemap.VMT>(base.GetTotalNativeMethodsCount());
			}
			public float getBatteryLevel() {
				float result;
				float resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.getBatteryLevel(_object, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
		}
		public class ICotaskBatteryPoweredRemap : Antilatency.DeviceNetwork.Details.ICotaskRemap {
			public new struct VMT {
				public delegate Antilatency.InterfaceContract.ExceptionCode getBatteryLevelDelegate(System.IntPtr _this, out float result);
				#pragma warning disable 0649
				public getBatteryLevelDelegate getBatteryLevel;
				#pragma warning restore 0649
			}
			public new static readonly NativeInterfaceVmt NativeVmt;
			static ICotaskBatteryPoweredRemap() {
				var vmtBlocks = new System.Collections.Generic.List<object>();
				AppendVmt(vmtBlocks);
				NativeVmt = new NativeInterfaceVmt(vmtBlocks);
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getBatteryLevelDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getBatteryLevel(System.IntPtr _this, out float result) {
				try {
					var obj = GetContext(_this) as ICotaskBatteryPowered;
					var resultMarshaler = obj.getBatteryLevel();
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(float);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			protected static new void AppendVmt(System.Collections.Generic.List<object> buffer) {
				Antilatency.DeviceNetwork.Details.ICotaskRemap.AppendVmt(buffer);
				var vmt = new VMT();
				vmt.getBatteryLevel = getBatteryLevel;
				buffer.Add(vmt);
			}
			public ICotaskBatteryPoweredRemap() { }
			public ICotaskBatteryPoweredRemap(System.IntPtr context, ushort lifetimeId) {
				AllocateNativeInterface(NativeVmt.Handle, context, lifetimeId);
			}
		}
	}
}

namespace Antilatency.DeviceNetwork {
	[System.Serializable]
	[System.Runtime.InteropServices.StructLayout(LayoutKind.Sequential)]
	public partial struct LogLevel {
		public static readonly LogLevel Trace = new LogLevel(){ value = 0x0 };
		public static readonly LogLevel Debug = new LogLevel(){ value = 0x1 };
		public static readonly LogLevel Info = new LogLevel(){ value = 0x2 };
		public static readonly LogLevel Warning = new LogLevel(){ value = 0x3 };
		public static readonly LogLevel Error = new LogLevel(){ value = 0x4 };
		public static readonly LogLevel Critical = new LogLevel(){ value = 0x5 };
		public static readonly LogLevel Off = new LogLevel(){ value = 0x6 };
		[System.Diagnostics.DebuggerBrowsable(global::System.Diagnostics.DebuggerBrowsableState.Never)]
		public int value;
		public override string ToString() {
			switch (value) {
				case 0x0: return "Trace";
				case 0x1: return "Debug";
				case 0x2: return "Info";
				case 0x3: return "Warning";
				case 0x4: return "Error";
				case 0x5: return "Critical";
				case 0x6: return "Off";
			}
			return value.ToString();
		}
		public static implicit operator int(LogLevel value) { return value.value;}
		public static explicit operator LogLevel(int value) { return new LogLevel() { value = value }; }
	}
}

namespace Antilatency.DeviceNetwork {
	[Guid("70680993-4a03-46a1-971f-80ecaec693ec")]
	[Antilatency.InterfaceContract.InterfaceId("70680993-4a03-46a1-971f-80ecaec693ec")]
	public interface ILibrary : Antilatency.InterfaceContract.IInterface {
		Antilatency.DeviceNetwork.IDeviceFilter createFilter();
		Antilatency.DeviceNetwork.INetwork createNetwork(Antilatency.DeviceNetwork.IDeviceFilter deviceFilter);
		string getVersion();
		void setLogLevel(Antilatency.DeviceNetwork.LogLevel level);
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_DeviceNetwork_ILibrary_InterfaceID = new System.Guid("70680993-4a03-46a1-971f-80ecaec693ec");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.DeviceNetwork.ILibrary result) {
		var guid = Antilatency_DeviceNetwork_ILibrary_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.DeviceNetwork.Details.ILibraryWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.DeviceNetwork.ILibrary result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_DeviceNetwork_ILibrary_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.DeviceNetwork.Details.ILibraryWrapper(ptr);
		}
	}
}
namespace Antilatency.DeviceNetwork {
	public static class Library{
	    #if ANTILATENCY_INTERFACECONTRACT_CUSTOMLIBPATHS
	    [DllImport(Antilatency.InterfaceContract.LibraryPaths.AntilatencyDeviceNetwork)]
	    #else
	    [DllImport("AntilatencyDeviceNetwork")]
	    #endif
	    private static extern Antilatency.InterfaceContract.ExceptionCode getLibraryInterface(System.IntPtr unloader, out System.IntPtr result);
	    public static ILibrary load(){
	        System.IntPtr libraryAsIInterfaceIntermediate;
	        getLibraryInterface(System.IntPtr.Zero, out libraryAsIInterfaceIntermediate);
	        Antilatency.InterfaceContract.IInterface libraryAsIInterface = new Antilatency.InterfaceContract.Details.IInterfaceWrapper(libraryAsIInterfaceIntermediate);
	        ILibrary library;
	        libraryAsIInterface.QueryInterface(out library);
	        libraryAsIInterface.Dispose();
	        return library;
	    }
	}
	namespace Details {
		public class ILibraryWrapper : Antilatency.InterfaceContract.Details.IInterfaceWrapper, ILibrary {
			private ILibraryRemap.VMT _VMT = new ILibraryRemap.VMT();
			protected new int GetTotalNativeMethodsCount() {
			    return base.GetTotalNativeMethodsCount() + typeof(ILibraryRemap.VMT).GetFields().Length;
			}
			public ILibraryWrapper(System.IntPtr obj) : base(obj) {
			    _VMT = LoadVMT<ILibraryRemap.VMT>(base.GetTotalNativeMethodsCount());
			}
			public Antilatency.DeviceNetwork.IDeviceFilter createFilter() {
				Antilatency.DeviceNetwork.IDeviceFilter result;
				System.IntPtr resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.createFilter(_object, out resultMarshaler));
				result = (resultMarshaler==System.IntPtr.Zero) ? null : new Antilatency.DeviceNetwork.Details.IDeviceFilterWrapper(resultMarshaler);
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public Antilatency.DeviceNetwork.INetwork createNetwork(Antilatency.DeviceNetwork.IDeviceFilter deviceFilter) {
				Antilatency.DeviceNetwork.INetwork result;
				System.IntPtr resultMarshaler;
				var deviceFilterMarshaler = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.DeviceNetwork.IDeviceFilter>(deviceFilter);
				var interfaceContractExceptionCode = (_VMT.createNetwork(_object, deviceFilterMarshaler, out resultMarshaler));
				result = (resultMarshaler==System.IntPtr.Zero) ? null : new Antilatency.DeviceNetwork.Details.INetworkWrapper(resultMarshaler);
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public string getVersion() {
				string result;
				var resultMarshaler = Antilatency.InterfaceContract.Details.ArrayOutMarshaler.create();
				var interfaceContractExceptionCode = (_VMT.getVersion(_object, resultMarshaler));
				result = resultMarshaler.value;
				resultMarshaler.Dispose();
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public void setLogLevel(Antilatency.DeviceNetwork.LogLevel level) {
				var interfaceContractExceptionCode = (_VMT.setLogLevel(_object, level));
				HandleExceptionCode(interfaceContractExceptionCode);
			}
		}
		public class ILibraryRemap : Antilatency.InterfaceContract.Details.IInterfaceRemap {
			public new struct VMT {
				public delegate Antilatency.InterfaceContract.ExceptionCode createFilterDelegate(System.IntPtr _this, out System.IntPtr result);
				public delegate Antilatency.InterfaceContract.ExceptionCode createNetworkDelegate(System.IntPtr _this, System.IntPtr deviceFilter, out System.IntPtr result);
				public delegate Antilatency.InterfaceContract.ExceptionCode getVersionDelegate(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result);
				public delegate Antilatency.InterfaceContract.ExceptionCode setLogLevelDelegate(System.IntPtr _this, Antilatency.DeviceNetwork.LogLevel level);
				#pragma warning disable 0649
				public createFilterDelegate createFilter;
				public createNetworkDelegate createNetwork;
				public getVersionDelegate getVersion;
				public setLogLevelDelegate setLogLevel;
				#pragma warning restore 0649
			}
			public new static readonly NativeInterfaceVmt NativeVmt;
			static ILibraryRemap() {
				var vmtBlocks = new System.Collections.Generic.List<object>();
				AppendVmt(vmtBlocks);
				NativeVmt = new NativeInterfaceVmt(vmtBlocks);
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.createFilterDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode createFilter(System.IntPtr _this, out System.IntPtr result) {
				try {
					var obj = GetContext(_this) as ILibrary;
					var resultMarshaler = obj.createFilter();
					result = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.DeviceNetwork.IDeviceFilter>(resultMarshaler);
				}
				catch (System.Exception ex) {
					result = default(System.IntPtr);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.createNetworkDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode createNetwork(System.IntPtr _this, System.IntPtr deviceFilter, out System.IntPtr result) {
				try {
					var obj = GetContext(_this) as ILibrary;
					var deviceFilterMarshaler = deviceFilter == System.IntPtr.Zero ? null : new Antilatency.DeviceNetwork.Details.IDeviceFilterWrapper(deviceFilter);
					var resultMarshaler = obj.createNetwork(deviceFilterMarshaler);
					result = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.DeviceNetwork.INetwork>(resultMarshaler);
				}
				catch (System.Exception ex) {
					result = default(System.IntPtr);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getVersionDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getVersion(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result) {
				try {
					var obj = GetContext(_this) as ILibrary;
					var resultMarshaler = obj.getVersion();
					result.assign(resultMarshaler);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.setLogLevelDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode setLogLevel(System.IntPtr _this, Antilatency.DeviceNetwork.LogLevel level) {
				try {
					var obj = GetContext(_this) as ILibrary;
					obj.setLogLevel(level);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			protected static new void AppendVmt(System.Collections.Generic.List<object> buffer) {
				Antilatency.InterfaceContract.Details.IInterfaceRemap.AppendVmt(buffer);
				var vmt = new VMT();
				vmt.createFilter = createFilter;
				vmt.createNetwork = createNetwork;
				vmt.getVersion = getVersion;
				vmt.setLogLevel = setLogLevel;
				buffer.Add(vmt);
			}
			public ILibraryRemap() { }
			public ILibraryRemap(System.IntPtr context, ushort lifetimeId) {
				AllocateNativeInterface(NativeVmt.Handle, context, lifetimeId);
			}
		}
	}
}

namespace Antilatency.DeviceNetwork {
	public static partial class Constants {
		public static Antilatency.DeviceNetwork.UsbDeviceFilter AllUsbDevices {
			get {
				byte[] data = new byte[]{55, 50, 0, 0, 0, 240};
				var handle = GCHandle.Alloc(data, GCHandleType.Pinned);
				Antilatency.DeviceNetwork.UsbDeviceFilter result = (Antilatency.DeviceNetwork.UsbDeviceFilter)Marshal.PtrToStructure(handle.AddrOfPinnedObject(), typeof(Antilatency.DeviceNetwork.UsbDeviceFilter));
				handle.Free();
				return result;
			}
		}
		public const string AllIpDevicesIp = "0.0.0.0";
		public const string AllIpDevicesMask = "0.0.0.0";
		public const ushort UsbAllDeviceMask = 61440;
		public const ushort UsbOneDeviceMask = 65535;
	}
}


