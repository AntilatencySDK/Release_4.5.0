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
namespace Antilatency.Alt.Environment.Rectangle {
	[Guid("f0596bc5-599a-4d06-b7ac-782b5bbeb549")]
	[Antilatency.InterfaceContract.InterfaceId("f0596bc5-599a-4d06-b7ac-782b5bbeb549")]
	public interface IEnvironmentData : Antilatency.InterfaceContract.IInterface {
		Antilatency.Math.float3[] getMarkers();
		float getHeight();
		void setHeight(float height);
		float getWidth();
		void setWidth(float width);
		void setEdgeMarkers(int edgeIdCcw, float[] positions);
		string serialize();
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_Alt_Environment_Rectangle_IEnvironmentData_InterfaceID = new System.Guid("f0596bc5-599a-4d06-b7ac-782b5bbeb549");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.Alt.Environment.Rectangle.IEnvironmentData result) {
		var guid = Antilatency_Alt_Environment_Rectangle_IEnvironmentData_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.Alt.Environment.Rectangle.Details.IEnvironmentDataWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.Alt.Environment.Rectangle.IEnvironmentData result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_Alt_Environment_Rectangle_IEnvironmentData_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.Alt.Environment.Rectangle.Details.IEnvironmentDataWrapper(ptr);
		}
	}
}
namespace Antilatency.Alt.Environment.Rectangle {
	namespace Details {
		public class IEnvironmentDataWrapper : Antilatency.InterfaceContract.Details.IInterfaceWrapper, IEnvironmentData {
			private IEnvironmentDataRemap.VMT _VMT = new IEnvironmentDataRemap.VMT();
			protected new int GetTotalNativeMethodsCount() {
			    return base.GetTotalNativeMethodsCount() + typeof(IEnvironmentDataRemap.VMT).GetFields().Length;
			}
			public IEnvironmentDataWrapper(System.IntPtr obj) : base(obj) {
			    _VMT = LoadVMT<IEnvironmentDataRemap.VMT>(base.GetTotalNativeMethodsCount());
			}
			public Antilatency.Math.float3[] getMarkers() {
				Antilatency.Math.float3[] result;
				var resultMarshaler = Antilatency.InterfaceContract.Details.ArrayOutMarshaler.create<Antilatency.Math.float3>();
				var interfaceContractExceptionCode = (_VMT.getMarkers(_object, resultMarshaler));
				result = resultMarshaler.value;
				resultMarshaler.Dispose();
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public float getHeight() {
				float result;
				float resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.getHeight(_object, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public void setHeight(float height) {
				var interfaceContractExceptionCode = (_VMT.setHeight(_object, height));
				HandleExceptionCode(interfaceContractExceptionCode);
			}
			public float getWidth() {
				float result;
				float resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.getWidth(_object, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public void setWidth(float width) {
				var interfaceContractExceptionCode = (_VMT.setWidth(_object, width));
				HandleExceptionCode(interfaceContractExceptionCode);
			}
			public void setEdgeMarkers(int edgeIdCcw, float[] positions) {
				var positionsMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(positions);
				var interfaceContractExceptionCode = (_VMT.setEdgeMarkers(_object, edgeIdCcw, positionsMarshaler));
				positionsMarshaler.Dispose();
				HandleExceptionCode(interfaceContractExceptionCode);
			}
			public string serialize() {
				string result;
				var resultMarshaler = Antilatency.InterfaceContract.Details.ArrayOutMarshaler.create();
				var interfaceContractExceptionCode = (_VMT.serialize(_object, resultMarshaler));
				result = resultMarshaler.value;
				resultMarshaler.Dispose();
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
		}
		public class IEnvironmentDataRemap : Antilatency.InterfaceContract.Details.IInterfaceRemap {
			public new struct VMT {
				public delegate Antilatency.InterfaceContract.ExceptionCode getMarkersDelegate(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result);
				public delegate Antilatency.InterfaceContract.ExceptionCode getHeightDelegate(System.IntPtr _this, out float result);
				public delegate Antilatency.InterfaceContract.ExceptionCode setHeightDelegate(System.IntPtr _this, float height);
				public delegate Antilatency.InterfaceContract.ExceptionCode getWidthDelegate(System.IntPtr _this, out float result);
				public delegate Antilatency.InterfaceContract.ExceptionCode setWidthDelegate(System.IntPtr _this, float width);
				public delegate Antilatency.InterfaceContract.ExceptionCode setEdgeMarkersDelegate(System.IntPtr _this, int edgeIdCcw, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate positions);
				public delegate Antilatency.InterfaceContract.ExceptionCode serializeDelegate(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result);
				#pragma warning disable 0649
				public getMarkersDelegate getMarkers;
				public getHeightDelegate getHeight;
				public setHeightDelegate setHeight;
				public getWidthDelegate getWidth;
				public setWidthDelegate setWidth;
				public setEdgeMarkersDelegate setEdgeMarkers;
				public serializeDelegate serialize;
				#pragma warning restore 0649
			}
			public new static readonly NativeInterfaceVmt NativeVmt;
			static IEnvironmentDataRemap() {
				var vmtBlocks = new System.Collections.Generic.List<object>();
				AppendVmt(vmtBlocks);
				NativeVmt = new NativeInterfaceVmt(vmtBlocks);
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getMarkersDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getMarkers(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result) {
				try {
					var obj = GetContext(_this) as IEnvironmentData;
					var resultMarshaler = obj.getMarkers();
					result.assign(resultMarshaler);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getHeightDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getHeight(System.IntPtr _this, out float result) {
				try {
					var obj = GetContext(_this) as IEnvironmentData;
					var resultMarshaler = obj.getHeight();
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(float);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.setHeightDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode setHeight(System.IntPtr _this, float height) {
				try {
					var obj = GetContext(_this) as IEnvironmentData;
					obj.setHeight(height);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getWidthDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getWidth(System.IntPtr _this, out float result) {
				try {
					var obj = GetContext(_this) as IEnvironmentData;
					var resultMarshaler = obj.getWidth();
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(float);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.setWidthDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode setWidth(System.IntPtr _this, float width) {
				try {
					var obj = GetContext(_this) as IEnvironmentData;
					obj.setWidth(width);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.setEdgeMarkersDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode setEdgeMarkers(System.IntPtr _this, int edgeIdCcw, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate positions) {
				try {
					var obj = GetContext(_this) as IEnvironmentData;
					obj.setEdgeMarkers(edgeIdCcw, positions.toArray<float>());
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.serializeDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode serialize(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result) {
				try {
					var obj = GetContext(_this) as IEnvironmentData;
					var resultMarshaler = obj.serialize();
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
				vmt.getMarkers = getMarkers;
				vmt.getHeight = getHeight;
				vmt.setHeight = setHeight;
				vmt.getWidth = getWidth;
				vmt.setWidth = setWidth;
				vmt.setEdgeMarkers = setEdgeMarkers;
				vmt.serialize = serialize;
				buffer.Add(vmt);
			}
			public IEnvironmentDataRemap() { }
			public IEnvironmentDataRemap(System.IntPtr context, ushort lifetimeId) {
				AllocateNativeInterface(NativeVmt.Handle, context, lifetimeId);
			}
		}
	}
}

namespace Antilatency.Alt.Environment.Rectangle {
	[Guid("109fc69e-29c8-4168-acd3-036e6f0459c9")]
	[Antilatency.InterfaceContract.InterfaceId("109fc69e-29c8-4168-acd3-036e6f0459c9")]
	public interface ILibrary : Antilatency.Alt.Environment.IEnvironmentConstructor {
		Antilatency.Alt.Environment.Rectangle.IEnvironmentData createEnvironmentData();
		Antilatency.Alt.Environment.Rectangle.IEnvironmentData deserialize(string environmentData);
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_Alt_Environment_Rectangle_ILibrary_InterfaceID = new System.Guid("109fc69e-29c8-4168-acd3-036e6f0459c9");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.Alt.Environment.Rectangle.ILibrary result) {
		var guid = Antilatency_Alt_Environment_Rectangle_ILibrary_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.Alt.Environment.Rectangle.Details.ILibraryWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.Alt.Environment.Rectangle.ILibrary result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_Alt_Environment_Rectangle_ILibrary_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.Alt.Environment.Rectangle.Details.ILibraryWrapper(ptr);
		}
	}
}
namespace Antilatency.Alt.Environment.Rectangle {
	public static class Library{
	    #if ANTILATENCY_INTERFACECONTRACT_CUSTOMLIBPATHS
	    [DllImport(Antilatency.InterfaceContract.LibraryPaths.AntilatencyAltEnvironmentRectangle)]
	    #else
	    [DllImport("AntilatencyAltEnvironmentRectangle")]
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
		public class ILibraryWrapper : Antilatency.Alt.Environment.Details.IEnvironmentConstructorWrapper, ILibrary {
			private ILibraryRemap.VMT _VMT = new ILibraryRemap.VMT();
			protected new int GetTotalNativeMethodsCount() {
			    return base.GetTotalNativeMethodsCount() + typeof(ILibraryRemap.VMT).GetFields().Length;
			}
			public ILibraryWrapper(System.IntPtr obj) : base(obj) {
			    _VMT = LoadVMT<ILibraryRemap.VMT>(base.GetTotalNativeMethodsCount());
			}
			public Antilatency.Alt.Environment.Rectangle.IEnvironmentData createEnvironmentData() {
				Antilatency.Alt.Environment.Rectangle.IEnvironmentData result;
				System.IntPtr resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.createEnvironmentData(_object, out resultMarshaler));
				result = (resultMarshaler==System.IntPtr.Zero) ? null : new Antilatency.Alt.Environment.Rectangle.Details.IEnvironmentDataWrapper(resultMarshaler);
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public Antilatency.Alt.Environment.Rectangle.IEnvironmentData deserialize(string environmentData) {
				Antilatency.Alt.Environment.Rectangle.IEnvironmentData result;
				System.IntPtr resultMarshaler;
				var environmentDataMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(environmentData);
				var interfaceContractExceptionCode = (_VMT.deserialize(_object, environmentDataMarshaler, out resultMarshaler));
				environmentDataMarshaler.Dispose();
				result = (resultMarshaler==System.IntPtr.Zero) ? null : new Antilatency.Alt.Environment.Rectangle.Details.IEnvironmentDataWrapper(resultMarshaler);
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
		}
		public class ILibraryRemap : Antilatency.Alt.Environment.Details.IEnvironmentConstructorRemap {
			public new struct VMT {
				public delegate Antilatency.InterfaceContract.ExceptionCode createEnvironmentDataDelegate(System.IntPtr _this, out System.IntPtr result);
				public delegate Antilatency.InterfaceContract.ExceptionCode deserializeDelegate(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate environmentData, out System.IntPtr result);
				#pragma warning disable 0649
				public createEnvironmentDataDelegate createEnvironmentData;
				public deserializeDelegate deserialize;
				#pragma warning restore 0649
			}
			public new static readonly NativeInterfaceVmt NativeVmt;
			static ILibraryRemap() {
				var vmtBlocks = new System.Collections.Generic.List<object>();
				AppendVmt(vmtBlocks);
				NativeVmt = new NativeInterfaceVmt(vmtBlocks);
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.createEnvironmentDataDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode createEnvironmentData(System.IntPtr _this, out System.IntPtr result) {
				try {
					var obj = GetContext(_this) as ILibrary;
					var resultMarshaler = obj.createEnvironmentData();
					result = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.Alt.Environment.Rectangle.IEnvironmentData>(resultMarshaler);
				}
				catch (System.Exception ex) {
					result = default(System.IntPtr);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.deserializeDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode deserialize(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate environmentData, out System.IntPtr result) {
				try {
					var obj = GetContext(_this) as ILibrary;
					var resultMarshaler = obj.deserialize(environmentData);
					result = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.Alt.Environment.Rectangle.IEnvironmentData>(resultMarshaler);
				}
				catch (System.Exception ex) {
					result = default(System.IntPtr);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			protected static new void AppendVmt(System.Collections.Generic.List<object> buffer) {
				Antilatency.Alt.Environment.Details.IEnvironmentConstructorRemap.AppendVmt(buffer);
				var vmt = new VMT();
				vmt.createEnvironmentData = createEnvironmentData;
				vmt.deserialize = deserialize;
				buffer.Add(vmt);
			}
			public ILibraryRemap() { }
			public ILibraryRemap(System.IntPtr context, ushort lifetimeId) {
				AllocateNativeInterface(NativeVmt.Handle, context, lifetimeId);
			}
		}
	}
}


