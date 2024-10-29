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
namespace Antilatency.PhysicalConfigurableEnvironment {
	[Guid("d470d7b5-922a-44be-9cbf-3dc1d6815143")]
	[Antilatency.InterfaceContract.InterfaceId("d470d7b5-922a-44be-9cbf-3dc1d6815143")]
	public interface ICotask : Antilatency.DeviceNetwork.ICotask {
		uint getConfigId();
		void setConfigId(uint configId);
		uint getConfigCount();
		string getEnvironment(uint configId);
		Antilatency.InterfaceContract.Bool[] getMarkersConfig(uint configId);
		Antilatency.Math.float3 getScreenPosition();
		Antilatency.Math.float3 getScreenX();
		Antilatency.Math.float3 getScreenY();
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_PhysicalConfigurableEnvironment_ICotask_InterfaceID = new System.Guid("d470d7b5-922a-44be-9cbf-3dc1d6815143");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.PhysicalConfigurableEnvironment.ICotask result) {
		var guid = Antilatency_PhysicalConfigurableEnvironment_ICotask_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.PhysicalConfigurableEnvironment.Details.ICotaskWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.PhysicalConfigurableEnvironment.ICotask result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_PhysicalConfigurableEnvironment_ICotask_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.PhysicalConfigurableEnvironment.Details.ICotaskWrapper(ptr);
		}
	}
}
namespace Antilatency.PhysicalConfigurableEnvironment {
	namespace Details {
		public class ICotaskWrapper : Antilatency.DeviceNetwork.Details.ICotaskWrapper, ICotask {
			private ICotaskRemap.VMT _VMT = new ICotaskRemap.VMT();
			protected new int GetTotalNativeMethodsCount() {
			    return base.GetTotalNativeMethodsCount() + typeof(ICotaskRemap.VMT).GetFields().Length;
			}
			public ICotaskWrapper(System.IntPtr obj) : base(obj) {
			    _VMT = LoadVMT<ICotaskRemap.VMT>(base.GetTotalNativeMethodsCount());
			}
			public uint getConfigId() {
				uint result;
				uint resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.getConfigId(_object, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public void setConfigId(uint configId) {
				var interfaceContractExceptionCode = (_VMT.setConfigId(_object, configId));
				HandleExceptionCode(interfaceContractExceptionCode);
			}
			public uint getConfigCount() {
				uint result;
				uint resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.getConfigCount(_object, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public string getEnvironment(uint configId) {
				string result;
				var resultMarshaler = Antilatency.InterfaceContract.Details.ArrayOutMarshaler.create();
				var interfaceContractExceptionCode = (_VMT.getEnvironment(_object, configId, resultMarshaler));
				result = resultMarshaler.value;
				resultMarshaler.Dispose();
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public Antilatency.InterfaceContract.Bool[] getMarkersConfig(uint configId) {
				Antilatency.InterfaceContract.Bool[] result;
				var resultMarshaler = Antilatency.InterfaceContract.Details.ArrayOutMarshaler.create<Antilatency.InterfaceContract.Bool>();
				var interfaceContractExceptionCode = (_VMT.getMarkersConfig(_object, configId, resultMarshaler));
				result = resultMarshaler.value;
				resultMarshaler.Dispose();
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public Antilatency.Math.float3 getScreenPosition() {
				Antilatency.Math.float3 result;
				Antilatency.Math.float3 resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.getScreenPosition(_object, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public Antilatency.Math.float3 getScreenX() {
				Antilatency.Math.float3 result;
				Antilatency.Math.float3 resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.getScreenX(_object, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public Antilatency.Math.float3 getScreenY() {
				Antilatency.Math.float3 result;
				Antilatency.Math.float3 resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.getScreenY(_object, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
		}
		public class ICotaskRemap : Antilatency.DeviceNetwork.Details.ICotaskRemap {
			public new struct VMT {
				public delegate Antilatency.InterfaceContract.ExceptionCode getConfigIdDelegate(System.IntPtr _this, out uint result);
				public delegate Antilatency.InterfaceContract.ExceptionCode setConfigIdDelegate(System.IntPtr _this, uint configId);
				public delegate Antilatency.InterfaceContract.ExceptionCode getConfigCountDelegate(System.IntPtr _this, out uint result);
				public delegate Antilatency.InterfaceContract.ExceptionCode getEnvironmentDelegate(System.IntPtr _this, uint configId, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result);
				public delegate Antilatency.InterfaceContract.ExceptionCode getMarkersConfigDelegate(System.IntPtr _this, uint configId, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result);
				public delegate Antilatency.InterfaceContract.ExceptionCode getScreenPositionDelegate(System.IntPtr _this, out Antilatency.Math.float3 result);
				public delegate Antilatency.InterfaceContract.ExceptionCode getScreenXDelegate(System.IntPtr _this, out Antilatency.Math.float3 result);
				public delegate Antilatency.InterfaceContract.ExceptionCode getScreenYDelegate(System.IntPtr _this, out Antilatency.Math.float3 result);
				#pragma warning disable 0649
				public getConfigIdDelegate getConfigId;
				public setConfigIdDelegate setConfigId;
				public getConfigCountDelegate getConfigCount;
				public getEnvironmentDelegate getEnvironment;
				public getMarkersConfigDelegate getMarkersConfig;
				public getScreenPositionDelegate getScreenPosition;
				public getScreenXDelegate getScreenX;
				public getScreenYDelegate getScreenY;
				#pragma warning restore 0649
			}
			public new static readonly NativeInterfaceVmt NativeVmt;
			static ICotaskRemap() {
				var vmtBlocks = new System.Collections.Generic.List<object>();
				AppendVmt(vmtBlocks);
				NativeVmt = new NativeInterfaceVmt(vmtBlocks);
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getConfigIdDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getConfigId(System.IntPtr _this, out uint result) {
				try {
					var obj = GetContext(_this) as ICotask;
					var resultMarshaler = obj.getConfigId();
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(uint);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.setConfigIdDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode setConfigId(System.IntPtr _this, uint configId) {
				try {
					var obj = GetContext(_this) as ICotask;
					obj.setConfigId(configId);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getConfigCountDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getConfigCount(System.IntPtr _this, out uint result) {
				try {
					var obj = GetContext(_this) as ICotask;
					var resultMarshaler = obj.getConfigCount();
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(uint);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getEnvironmentDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getEnvironment(System.IntPtr _this, uint configId, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result) {
				try {
					var obj = GetContext(_this) as ICotask;
					var resultMarshaler = obj.getEnvironment(configId);
					result.assign(resultMarshaler);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getMarkersConfigDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getMarkersConfig(System.IntPtr _this, uint configId, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result) {
				try {
					var obj = GetContext(_this) as ICotask;
					var resultMarshaler = obj.getMarkersConfig(configId);
					result.assign(resultMarshaler);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getScreenPositionDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getScreenPosition(System.IntPtr _this, out Antilatency.Math.float3 result) {
				try {
					var obj = GetContext(_this) as ICotask;
					var resultMarshaler = obj.getScreenPosition();
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(Antilatency.Math.float3);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getScreenXDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getScreenX(System.IntPtr _this, out Antilatency.Math.float3 result) {
				try {
					var obj = GetContext(_this) as ICotask;
					var resultMarshaler = obj.getScreenX();
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(Antilatency.Math.float3);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getScreenYDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getScreenY(System.IntPtr _this, out Antilatency.Math.float3 result) {
				try {
					var obj = GetContext(_this) as ICotask;
					var resultMarshaler = obj.getScreenY();
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(Antilatency.Math.float3);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			protected static new void AppendVmt(System.Collections.Generic.List<object> buffer) {
				Antilatency.DeviceNetwork.Details.ICotaskRemap.AppendVmt(buffer);
				var vmt = new VMT();
				vmt.getConfigId = getConfigId;
				vmt.setConfigId = setConfigId;
				vmt.getConfigCount = getConfigCount;
				vmt.getEnvironment = getEnvironment;
				vmt.getMarkersConfig = getMarkersConfig;
				vmt.getScreenPosition = getScreenPosition;
				vmt.getScreenX = getScreenX;
				vmt.getScreenY = getScreenY;
				buffer.Add(vmt);
			}
			public ICotaskRemap() { }
			public ICotaskRemap(System.IntPtr context, ushort lifetimeId) {
				AllocateNativeInterface(NativeVmt.Handle, context, lifetimeId);
			}
		}
	}
}

namespace Antilatency.PhysicalConfigurableEnvironment {
	[Guid("1afbefdf-9104-4092-8459-b44e249543a5")]
	[Antilatency.InterfaceContract.InterfaceId("1afbefdf-9104-4092-8459-b44e249543a5")]
	public interface ICotaskConstructor : Antilatency.DeviceNetwork.ICotaskConstructor {
		Antilatency.PhysicalConfigurableEnvironment.ICotask startTask(Antilatency.DeviceNetwork.INetwork network, Antilatency.DeviceNetwork.NodeHandle node);
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_PhysicalConfigurableEnvironment_ICotaskConstructor_InterfaceID = new System.Guid("1afbefdf-9104-4092-8459-b44e249543a5");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.PhysicalConfigurableEnvironment.ICotaskConstructor result) {
		var guid = Antilatency_PhysicalConfigurableEnvironment_ICotaskConstructor_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.PhysicalConfigurableEnvironment.Details.ICotaskConstructorWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.PhysicalConfigurableEnvironment.ICotaskConstructor result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_PhysicalConfigurableEnvironment_ICotaskConstructor_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.PhysicalConfigurableEnvironment.Details.ICotaskConstructorWrapper(ptr);
		}
	}
}
namespace Antilatency.PhysicalConfigurableEnvironment {
	namespace Details {
		public class ICotaskConstructorWrapper : Antilatency.DeviceNetwork.Details.ICotaskConstructorWrapper, ICotaskConstructor {
			private ICotaskConstructorRemap.VMT _VMT = new ICotaskConstructorRemap.VMT();
			protected new int GetTotalNativeMethodsCount() {
			    return base.GetTotalNativeMethodsCount() + typeof(ICotaskConstructorRemap.VMT).GetFields().Length;
			}
			public ICotaskConstructorWrapper(System.IntPtr obj) : base(obj) {
			    _VMT = LoadVMT<ICotaskConstructorRemap.VMT>(base.GetTotalNativeMethodsCount());
			}
			public Antilatency.PhysicalConfigurableEnvironment.ICotask startTask(Antilatency.DeviceNetwork.INetwork network, Antilatency.DeviceNetwork.NodeHandle node) {
				Antilatency.PhysicalConfigurableEnvironment.ICotask result;
				System.IntPtr resultMarshaler;
				var networkMarshaler = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.DeviceNetwork.INetwork>(network);
				var interfaceContractExceptionCode = (_VMT.startTask(_object, networkMarshaler, node, out resultMarshaler));
				result = (resultMarshaler==System.IntPtr.Zero) ? null : new Antilatency.PhysicalConfigurableEnvironment.Details.ICotaskWrapper(resultMarshaler);
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
					result = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.PhysicalConfigurableEnvironment.ICotask>(resultMarshaler);
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

namespace Antilatency.PhysicalConfigurableEnvironment {
	[Guid("95b59518-c83f-4f9b-bf53-5f88542b321e")]
	[Antilatency.InterfaceContract.InterfaceId("95b59518-c83f-4f9b-bf53-5f88542b321e")]
	public interface ILibrary : Antilatency.InterfaceContract.IInterface {
		Antilatency.PhysicalConfigurableEnvironment.ICotaskConstructor createCotaskConstructor();
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_PhysicalConfigurableEnvironment_ILibrary_InterfaceID = new System.Guid("95b59518-c83f-4f9b-bf53-5f88542b321e");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.PhysicalConfigurableEnvironment.ILibrary result) {
		var guid = Antilatency_PhysicalConfigurableEnvironment_ILibrary_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.PhysicalConfigurableEnvironment.Details.ILibraryWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.PhysicalConfigurableEnvironment.ILibrary result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_PhysicalConfigurableEnvironment_ILibrary_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.PhysicalConfigurableEnvironment.Details.ILibraryWrapper(ptr);
		}
	}
}
namespace Antilatency.PhysicalConfigurableEnvironment {
	public static class Library{
	    #if ANTILATENCY_INTERFACECONTRACT_CUSTOMLIBPATHS
	    [DllImport(Antilatency.InterfaceContract.LibraryPaths.AntilatencyPhysicalConfigurableEnvironment)]
	    #else
	    [DllImport("AntilatencyPhysicalConfigurableEnvironment")]
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
			public Antilatency.PhysicalConfigurableEnvironment.ICotaskConstructor createCotaskConstructor() {
				Antilatency.PhysicalConfigurableEnvironment.ICotaskConstructor result;
				System.IntPtr resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.createCotaskConstructor(_object, out resultMarshaler));
				result = (resultMarshaler==System.IntPtr.Zero) ? null : new Antilatency.PhysicalConfigurableEnvironment.Details.ICotaskConstructorWrapper(resultMarshaler);
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
		}
		public class ILibraryRemap : Antilatency.InterfaceContract.Details.IInterfaceRemap {
			public new struct VMT {
				public delegate Antilatency.InterfaceContract.ExceptionCode createCotaskConstructorDelegate(System.IntPtr _this, out System.IntPtr result);
				#pragma warning disable 0649
				public createCotaskConstructorDelegate createCotaskConstructor;
				#pragma warning restore 0649
			}
			public new static readonly NativeInterfaceVmt NativeVmt;
			static ILibraryRemap() {
				var vmtBlocks = new System.Collections.Generic.List<object>();
				AppendVmt(vmtBlocks);
				NativeVmt = new NativeInterfaceVmt(vmtBlocks);
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.createCotaskConstructorDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode createCotaskConstructor(System.IntPtr _this, out System.IntPtr result) {
				try {
					var obj = GetContext(_this) as ILibrary;
					var resultMarshaler = obj.createCotaskConstructor();
					result = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.PhysicalConfigurableEnvironment.ICotaskConstructor>(resultMarshaler);
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
				vmt.createCotaskConstructor = createCotaskConstructor;
				buffer.Add(vmt);
			}
			public ILibraryRemap() { }
			public ILibraryRemap(System.IntPtr context, ushort lifetimeId) {
				AllocateNativeInterface(NativeVmt.Handle, context, lifetimeId);
			}
		}
	}
}


