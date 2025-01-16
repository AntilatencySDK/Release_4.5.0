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
namespace Antilatency.RadioMetrics {
	[System.Serializable]
	[System.Runtime.InteropServices.StructLayout(LayoutKind.Sequential)]
	public partial struct Metrics {
		public sbyte averageRssi;
		public float packetLossRate;
	}
}

namespace Antilatency.RadioMetrics {
	[Guid("a7d915ca-0fa2-409a-ba2c-0aa72577bac0")]
	[Antilatency.InterfaceContract.InterfaceId("a7d915ca-0fa2-409a-ba2c-0aa72577bac0")]
	public interface ICotask : Antilatency.DeviceNetwork.ICotask {
		Antilatency.RadioMetrics.Metrics getMetrics(Antilatency.DeviceNetwork.NodeHandle targetNode);
		Antilatency.RadioMetrics.Interop.ExtendedMetrics getExtendedMetrics(Antilatency.DeviceNetwork.NodeHandle targetNode);
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_RadioMetrics_ICotask_InterfaceID = new System.Guid("a7d915ca-0fa2-409a-ba2c-0aa72577bac0");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.RadioMetrics.ICotask result) {
		var guid = Antilatency_RadioMetrics_ICotask_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.RadioMetrics.Details.ICotaskWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.RadioMetrics.ICotask result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_RadioMetrics_ICotask_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.RadioMetrics.Details.ICotaskWrapper(ptr);
		}
	}
}
namespace Antilatency.RadioMetrics {
	namespace Details {
		public class ICotaskWrapper : Antilatency.DeviceNetwork.Details.ICotaskWrapper, ICotask {
			private ICotaskRemap.VMT _VMT = new ICotaskRemap.VMT();
			protected new int GetTotalNativeMethodsCount() {
			    return base.GetTotalNativeMethodsCount() + typeof(ICotaskRemap.VMT).GetFields().Length;
			}
			public ICotaskWrapper(System.IntPtr obj) : base(obj) {
			    _VMT = LoadVMT<ICotaskRemap.VMT>(base.GetTotalNativeMethodsCount());
			}
			public Antilatency.RadioMetrics.Metrics getMetrics(Antilatency.DeviceNetwork.NodeHandle targetNode) {
				Antilatency.RadioMetrics.Metrics result;
				Antilatency.RadioMetrics.Metrics resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.getMetrics(_object, targetNode, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public Antilatency.RadioMetrics.Interop.ExtendedMetrics getExtendedMetrics(Antilatency.DeviceNetwork.NodeHandle targetNode) {
				Antilatency.RadioMetrics.Interop.ExtendedMetrics result;
				Antilatency.RadioMetrics.Interop.ExtendedMetrics resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.getExtendedMetrics(_object, targetNode, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
		}
		public class ICotaskRemap : Antilatency.DeviceNetwork.Details.ICotaskRemap {
			public new struct VMT {
				public delegate Antilatency.InterfaceContract.ExceptionCode getMetricsDelegate(System.IntPtr _this, Antilatency.DeviceNetwork.NodeHandle targetNode, out Antilatency.RadioMetrics.Metrics result);
				public delegate Antilatency.InterfaceContract.ExceptionCode getExtendedMetricsDelegate(System.IntPtr _this, Antilatency.DeviceNetwork.NodeHandle targetNode, out Antilatency.RadioMetrics.Interop.ExtendedMetrics result);
				#pragma warning disable 0649
				public getMetricsDelegate getMetrics;
				public getExtendedMetricsDelegate getExtendedMetrics;
				#pragma warning restore 0649
			}
			public new static readonly NativeInterfaceVmt NativeVmt;
			static ICotaskRemap() {
				var vmtBlocks = new System.Collections.Generic.List<object>();
				AppendVmt(vmtBlocks);
				NativeVmt = new NativeInterfaceVmt(vmtBlocks);
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getMetricsDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getMetrics(System.IntPtr _this, Antilatency.DeviceNetwork.NodeHandle targetNode, out Antilatency.RadioMetrics.Metrics result) {
				try {
					var obj = GetContext(_this) as ICotask;
					var resultMarshaler = obj.getMetrics(targetNode);
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(Antilatency.RadioMetrics.Metrics);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getExtendedMetricsDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getExtendedMetrics(System.IntPtr _this, Antilatency.DeviceNetwork.NodeHandle targetNode, out Antilatency.RadioMetrics.Interop.ExtendedMetrics result) {
				try {
					var obj = GetContext(_this) as ICotask;
					var resultMarshaler = obj.getExtendedMetrics(targetNode);
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(Antilatency.RadioMetrics.Interop.ExtendedMetrics);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			protected static new void AppendVmt(System.Collections.Generic.List<object> buffer) {
				Antilatency.DeviceNetwork.Details.ICotaskRemap.AppendVmt(buffer);
				var vmt = new VMT();
				vmt.getMetrics = getMetrics;
				vmt.getExtendedMetrics = getExtendedMetrics;
				buffer.Add(vmt);
			}
			public ICotaskRemap() { }
			public ICotaskRemap(System.IntPtr context, ushort lifetimeId) {
				AllocateNativeInterface(NativeVmt.Handle, context, lifetimeId);
			}
		}
	}
}

namespace Antilatency.RadioMetrics {
	[Guid("fb930a9b-8b0d-4f74-bfb5-89a301ce8533")]
	[Antilatency.InterfaceContract.InterfaceId("fb930a9b-8b0d-4f74-bfb5-89a301ce8533")]
	public interface ICotaskConstructor : Antilatency.DeviceNetwork.ICotaskConstructor {
		Antilatency.RadioMetrics.ICotask startTask(Antilatency.DeviceNetwork.INetwork network, Antilatency.DeviceNetwork.NodeHandle node);
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_RadioMetrics_ICotaskConstructor_InterfaceID = new System.Guid("fb930a9b-8b0d-4f74-bfb5-89a301ce8533");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.RadioMetrics.ICotaskConstructor result) {
		var guid = Antilatency_RadioMetrics_ICotaskConstructor_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.RadioMetrics.Details.ICotaskConstructorWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.RadioMetrics.ICotaskConstructor result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_RadioMetrics_ICotaskConstructor_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.RadioMetrics.Details.ICotaskConstructorWrapper(ptr);
		}
	}
}
namespace Antilatency.RadioMetrics {
	namespace Details {
		public class ICotaskConstructorWrapper : Antilatency.DeviceNetwork.Details.ICotaskConstructorWrapper, ICotaskConstructor {
			private ICotaskConstructorRemap.VMT _VMT = new ICotaskConstructorRemap.VMT();
			protected new int GetTotalNativeMethodsCount() {
			    return base.GetTotalNativeMethodsCount() + typeof(ICotaskConstructorRemap.VMT).GetFields().Length;
			}
			public ICotaskConstructorWrapper(System.IntPtr obj) : base(obj) {
			    _VMT = LoadVMT<ICotaskConstructorRemap.VMT>(base.GetTotalNativeMethodsCount());
			}
			public Antilatency.RadioMetrics.ICotask startTask(Antilatency.DeviceNetwork.INetwork network, Antilatency.DeviceNetwork.NodeHandle node) {
				Antilatency.RadioMetrics.ICotask result;
				System.IntPtr resultMarshaler;
				var networkMarshaler = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.DeviceNetwork.INetwork>(network);
				var interfaceContractExceptionCode = (_VMT.startTask(_object, networkMarshaler, node, out resultMarshaler));
				result = (resultMarshaler==System.IntPtr.Zero) ? null : new Antilatency.RadioMetrics.Details.ICotaskWrapper(resultMarshaler);
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
		}
		public class ICotaskConstructorRemap : Antilatency.DeviceNetwork.Details.ICotaskConstructorRemap {
			public new struct VMT {
				public delegate Antilatency.InterfaceContract.ExceptionCode startTaskDelegate(System.IntPtr _this, System.IntPtr network, Antilatency.DeviceNetwork.NodeHandle node, out System.IntPtr result);
				#pragma warning disable 0649
				public startTaskDelegate startTask;
				#pragma warning restore 0649
			}
			public new static readonly NativeInterfaceVmt NativeVmt;
			static ICotaskConstructorRemap() {
				var vmtBlocks = new System.Collections.Generic.List<object>();
				AppendVmt(vmtBlocks);
				NativeVmt = new NativeInterfaceVmt(vmtBlocks);
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.startTaskDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode startTask(System.IntPtr _this, System.IntPtr network, Antilatency.DeviceNetwork.NodeHandle node, out System.IntPtr result) {
				try {
					var obj = GetContext(_this) as ICotaskConstructor;
					var networkMarshaler = network == System.IntPtr.Zero ? null : new Antilatency.DeviceNetwork.Details.INetworkWrapper(network);
					var resultMarshaler = obj.startTask(networkMarshaler, node);
					result = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.RadioMetrics.ICotask>(resultMarshaler);
				}
				catch (System.Exception ex) {
					result = default(System.IntPtr);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			protected static new void AppendVmt(System.Collections.Generic.List<object> buffer) {
				Antilatency.DeviceNetwork.Details.ICotaskConstructorRemap.AppendVmt(buffer);
				var vmt = new VMT();
				vmt.startTask = startTask;
				buffer.Add(vmt);
			}
			public ICotaskConstructorRemap() { }
			public ICotaskConstructorRemap(System.IntPtr context, ushort lifetimeId) {
				AllocateNativeInterface(NativeVmt.Handle, context, lifetimeId);
			}
		}
	}
}

namespace Antilatency.RadioMetrics {
	[Guid("d0369d42-fed4-48b5-a767-13caf89a3fef")]
	[Antilatency.InterfaceContract.InterfaceId("d0369d42-fed4-48b5-a767-13caf89a3fef")]
	public interface ILibrary : Antilatency.InterfaceContract.IInterface {
		string getVersion();
		Antilatency.RadioMetrics.ICotaskConstructor getCotaskConstructor();
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_RadioMetrics_ILibrary_InterfaceID = new System.Guid("d0369d42-fed4-48b5-a767-13caf89a3fef");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.RadioMetrics.ILibrary result) {
		var guid = Antilatency_RadioMetrics_ILibrary_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.RadioMetrics.Details.ILibraryWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.RadioMetrics.ILibrary result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_RadioMetrics_ILibrary_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.RadioMetrics.Details.ILibraryWrapper(ptr);
		}
	}
}
namespace Antilatency.RadioMetrics {
	public static class Library{
	    #if ANTILATENCY_INTERFACECONTRACT_CUSTOMLIBPATHS
	    [DllImport(Antilatency.InterfaceContract.LibraryPaths.AntilatencyRadioMetrics)]
	    #else
	    [DllImport("AntilatencyRadioMetrics")]
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
			public string getVersion() {
				string result;
				var resultMarshaler = Antilatency.InterfaceContract.Details.ArrayOutMarshaler.create();
				var interfaceContractExceptionCode = (_VMT.getVersion(_object, resultMarshaler));
				result = resultMarshaler.value;
				resultMarshaler.Dispose();
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public Antilatency.RadioMetrics.ICotaskConstructor getCotaskConstructor() {
				Antilatency.RadioMetrics.ICotaskConstructor result;
				System.IntPtr resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.getCotaskConstructor(_object, out resultMarshaler));
				result = (resultMarshaler==System.IntPtr.Zero) ? null : new Antilatency.RadioMetrics.Details.ICotaskConstructorWrapper(resultMarshaler);
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
		}
		public class ILibraryRemap : Antilatency.InterfaceContract.Details.IInterfaceRemap {
			public new struct VMT {
				public delegate Antilatency.InterfaceContract.ExceptionCode getVersionDelegate(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result);
				public delegate Antilatency.InterfaceContract.ExceptionCode getCotaskConstructorDelegate(System.IntPtr _this, out System.IntPtr result);
				#pragma warning disable 0649
				public getVersionDelegate getVersion;
				public getCotaskConstructorDelegate getCotaskConstructor;
				#pragma warning restore 0649
			}
			public new static readonly NativeInterfaceVmt NativeVmt;
			static ILibraryRemap() {
				var vmtBlocks = new System.Collections.Generic.List<object>();
				AppendVmt(vmtBlocks);
				NativeVmt = new NativeInterfaceVmt(vmtBlocks);
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
				[MonoPInvokeCallback(typeof(VMT.getCotaskConstructorDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getCotaskConstructor(System.IntPtr _this, out System.IntPtr result) {
				try {
					var obj = GetContext(_this) as ILibrary;
					var resultMarshaler = obj.getCotaskConstructor();
					result = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.RadioMetrics.ICotaskConstructor>(resultMarshaler);
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
				vmt.getVersion = getVersion;
				vmt.getCotaskConstructor = getCotaskConstructor;
				buffer.Add(vmt);
			}
			public ILibraryRemap() { }
			public ILibraryRemap(System.IntPtr context, ushort lifetimeId) {
				AllocateNativeInterface(NativeVmt.Handle, context, lifetimeId);
			}
		}
	}
}


