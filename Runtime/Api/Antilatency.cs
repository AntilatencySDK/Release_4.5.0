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
namespace Antilatency {
	[Guid("d405dd81-eb71-4f4e-b76a-73959ca7b2b3")]
	[Antilatency.InterfaceContract.InterfaceId("d405dd81-eb71-4f4e-b76a-73959ca7b2b3")]
	public interface IFuture : Antilatency.InterfaceContract.IInterface {
		Antilatency.InterfaceContract.Bool isDone();
		void wait();
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_IFuture_InterfaceID = new System.Guid("d405dd81-eb71-4f4e-b76a-73959ca7b2b3");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.IFuture result) {
		var guid = Antilatency_IFuture_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.Details.IFutureWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.IFuture result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_IFuture_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.Details.IFutureWrapper(ptr);
		}
	}
}
namespace Antilatency {
	namespace Details {
		public class IFutureWrapper : Antilatency.InterfaceContract.Details.IInterfaceWrapper, IFuture {
			private IFutureRemap.VMT _VMT = new IFutureRemap.VMT();
			protected new int GetTotalNativeMethodsCount() {
			    return base.GetTotalNativeMethodsCount() + typeof(IFutureRemap.VMT).GetFields().Length;
			}
			public IFutureWrapper(System.IntPtr obj) : base(obj) {
			    _VMT = LoadVMT<IFutureRemap.VMT>(base.GetTotalNativeMethodsCount());
			}
			public Antilatency.InterfaceContract.Bool isDone() {
				Antilatency.InterfaceContract.Bool result;
				Antilatency.InterfaceContract.Bool resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.isDone(_object, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public void wait() {
				var interfaceContractExceptionCode = (_VMT.wait(_object));
				HandleExceptionCode(interfaceContractExceptionCode);
			}
		}
		public class IFutureRemap : Antilatency.InterfaceContract.Details.IInterfaceRemap {
			public new struct VMT {
				public delegate Antilatency.InterfaceContract.ExceptionCode isDoneDelegate(System.IntPtr _this, out Antilatency.InterfaceContract.Bool result);
				public delegate Antilatency.InterfaceContract.ExceptionCode waitDelegate(System.IntPtr _this);
				#pragma warning disable 0649
				public isDoneDelegate isDone;
				public waitDelegate wait;
				#pragma warning restore 0649
			}
			public new static readonly NativeInterfaceVmt NativeVmt;
			static IFutureRemap() {
				var vmtBlocks = new System.Collections.Generic.List<object>();
				AppendVmt(vmtBlocks);
				NativeVmt = new NativeInterfaceVmt(vmtBlocks);
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.isDoneDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode isDone(System.IntPtr _this, out Antilatency.InterfaceContract.Bool result) {
				try {
					var obj = GetContext(_this) as IFuture;
					var resultMarshaler = obj.isDone();
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(Antilatency.InterfaceContract.Bool);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.waitDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode wait(System.IntPtr _this) {
				try {
					var obj = GetContext(_this) as IFuture;
					obj.wait();
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			protected static new void AppendVmt(System.Collections.Generic.List<object> buffer) {
				Antilatency.InterfaceContract.Details.IInterfaceRemap.AppendVmt(buffer);
				var vmt = new VMT();
				vmt.isDone = isDone;
				vmt.wait = wait;
				buffer.Add(vmt);
			}
			public IFutureRemap() { }
			public IFutureRemap(System.IntPtr context, ushort lifetimeId) {
				AllocateNativeInterface(NativeVmt.Handle, context, lifetimeId);
			}
		}
	}
}

namespace Antilatency {
	[Guid("e8c201d1-fadc-551c-81cc-7ed646c22987")]
	[Antilatency.InterfaceContract.InterfaceId("e8c201d1-fadc-551c-81cc-7ed646c22987")]
	public interface IFutureString : Antilatency.IFuture {
		string get();
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_IFutureString_InterfaceID = new System.Guid("e8c201d1-fadc-551c-81cc-7ed646c22987");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.IFutureString result) {
		var guid = Antilatency_IFutureString_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.Details.IFutureStringWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.IFutureString result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_IFutureString_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.Details.IFutureStringWrapper(ptr);
		}
	}
}
namespace Antilatency {
	namespace Details {
		public class IFutureStringWrapper : Antilatency.Details.IFutureWrapper, IFutureString {
			private IFutureStringRemap.VMT _VMT = new IFutureStringRemap.VMT();
			protected new int GetTotalNativeMethodsCount() {
			    return base.GetTotalNativeMethodsCount() + typeof(IFutureStringRemap.VMT).GetFields().Length;
			}
			public IFutureStringWrapper(System.IntPtr obj) : base(obj) {
			    _VMT = LoadVMT<IFutureStringRemap.VMT>(base.GetTotalNativeMethodsCount());
			}
			public string get() {
				string result;
				var resultMarshaler = Antilatency.InterfaceContract.Details.ArrayOutMarshaler.create();
				var interfaceContractExceptionCode = (_VMT.get(_object, resultMarshaler));
				result = resultMarshaler.value;
				resultMarshaler.Dispose();
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
		}
		public class IFutureStringRemap : Antilatency.Details.IFutureRemap {
			public new struct VMT {
				public delegate Antilatency.InterfaceContract.ExceptionCode getDelegate(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result);
				#pragma warning disable 0649
				public getDelegate get;
				#pragma warning restore 0649
			}
			public new static readonly NativeInterfaceVmt NativeVmt;
			static IFutureStringRemap() {
				var vmtBlocks = new System.Collections.Generic.List<object>();
				AppendVmt(vmtBlocks);
				NativeVmt = new NativeInterfaceVmt(vmtBlocks);
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode get(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result) {
				try {
					var obj = GetContext(_this) as IFutureString;
					var resultMarshaler = obj.get();
					result.assign(resultMarshaler);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			protected static new void AppendVmt(System.Collections.Generic.List<object> buffer) {
				Antilatency.Details.IFutureRemap.AppendVmt(buffer);
				var vmt = new VMT();
				vmt.get = get;
				buffer.Add(vmt);
			}
			public IFutureStringRemap() { }
			public IFutureStringRemap(System.IntPtr context, ushort lifetimeId) {
				AllocateNativeInterface(NativeVmt.Handle, context, lifetimeId);
			}
		}
	}
}

namespace Antilatency {
	[Guid("0825dab8-5c73-5c8d-a753-828e4fac8434")]
	[Antilatency.InterfaceContract.InterfaceId("0825dab8-5c73-5c8d-a753-828e4fac8434")]
	public interface IFutureArrayOfByte : Antilatency.IFuture {
		byte[] get();
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_IFutureArrayOfByte_InterfaceID = new System.Guid("0825dab8-5c73-5c8d-a753-828e4fac8434");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.IFutureArrayOfByte result) {
		var guid = Antilatency_IFutureArrayOfByte_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.Details.IFutureArrayOfByteWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.IFutureArrayOfByte result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_IFutureArrayOfByte_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.Details.IFutureArrayOfByteWrapper(ptr);
		}
	}
}
namespace Antilatency {
	namespace Details {
		public class IFutureArrayOfByteWrapper : Antilatency.Details.IFutureWrapper, IFutureArrayOfByte {
			private IFutureArrayOfByteRemap.VMT _VMT = new IFutureArrayOfByteRemap.VMT();
			protected new int GetTotalNativeMethodsCount() {
			    return base.GetTotalNativeMethodsCount() + typeof(IFutureArrayOfByteRemap.VMT).GetFields().Length;
			}
			public IFutureArrayOfByteWrapper(System.IntPtr obj) : base(obj) {
			    _VMT = LoadVMT<IFutureArrayOfByteRemap.VMT>(base.GetTotalNativeMethodsCount());
			}
			public byte[] get() {
				byte[] result;
				var resultMarshaler = Antilatency.InterfaceContract.Details.ArrayOutMarshaler.create<byte>();
				var interfaceContractExceptionCode = (_VMT.get(_object, resultMarshaler));
				result = resultMarshaler.value;
				resultMarshaler.Dispose();
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
		}
		public class IFutureArrayOfByteRemap : Antilatency.Details.IFutureRemap {
			public new struct VMT {
				public delegate Antilatency.InterfaceContract.ExceptionCode getDelegate(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result);
				#pragma warning disable 0649
				public getDelegate get;
				#pragma warning restore 0649
			}
			public new static readonly NativeInterfaceVmt NativeVmt;
			static IFutureArrayOfByteRemap() {
				var vmtBlocks = new System.Collections.Generic.List<object>();
				AppendVmt(vmtBlocks);
				NativeVmt = new NativeInterfaceVmt(vmtBlocks);
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode get(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result) {
				try {
					var obj = GetContext(_this) as IFutureArrayOfByte;
					var resultMarshaler = obj.get();
					result.assign(resultMarshaler);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			protected static new void AppendVmt(System.Collections.Generic.List<object> buffer) {
				Antilatency.Details.IFutureRemap.AppendVmt(buffer);
				var vmt = new VMT();
				vmt.get = get;
				buffer.Add(vmt);
			}
			public IFutureArrayOfByteRemap() { }
			public IFutureArrayOfByteRemap(System.IntPtr context, ushort lifetimeId) {
				AllocateNativeInterface(NativeVmt.Handle, context, lifetimeId);
			}
		}
	}
}


