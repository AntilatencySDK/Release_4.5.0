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
namespace Antilatency.Alt.Environment {
	[System.Serializable]
	[System.Runtime.InteropServices.StructLayout(LayoutKind.Sequential)]
	public partial struct MarkerIndex {
		public static readonly MarkerIndex MaximumValidMarkerIndex = new MarkerIndex(){ value = 0xFFFFFFF0 };
		public static readonly MarkerIndex Invalid = new MarkerIndex(){ value = 0xFFFFFFFE };
		public static readonly MarkerIndex Unknown = new MarkerIndex(){ value = 0xFFFFFFFF };
		[System.Diagnostics.DebuggerBrowsable(global::System.Diagnostics.DebuggerBrowsableState.Never)]
		public uint value;
		public override string ToString() {
			switch (value) {
				case 0xFFFFFFF0: return "MaximumValidMarkerIndex";
				case 0xFFFFFFFE: return "Invalid";
				case 0xFFFFFFFF: return "Unknown";
			}
			return value.ToString();
		}
		public static implicit operator uint(MarkerIndex value) { return value.value;}
		public static explicit operator MarkerIndex(uint value) { return new MarkerIndex() { value = value }; }
	}
}

namespace Antilatency.Alt.Environment {
	[Guid("c257c858-f296-43b7-b6b5-c14b9afb1a13")]
	[Antilatency.InterfaceContract.InterfaceId("c257c858-f296-43b7-b6b5-c14b9afb1a13")]
	public interface IEnvironment : Antilatency.InterfaceContract.IInterface {
		Antilatency.InterfaceContract.Bool isMutable();
		Antilatency.Math.float3[] getMarkers();
		Antilatency.InterfaceContract.Bool filterRay(Antilatency.Math.float3 up, Antilatency.Math.float3 ray);
		/// <param name = "raysUpSpace">
		/// rays directions. Normalized
		/// </param>
		Antilatency.InterfaceContract.Bool match(Antilatency.Math.float3[] raysUpSpace, out Antilatency.Alt.Environment.MarkerIndex[] markersIndices, out Antilatency.Math.floatP3Q poseOfUpSpace);
		/// <summary>Match rays to markers by known position</summary>
		/// <param name = "rays">
		/// rays directions world space. Normalized
		/// </param>
		/// <param name = "origin">
		/// Common rays origin world space
		/// </param>
		/// <returns>Indices of corresponding markers. result.size == rays.size</returns>
		Antilatency.Alt.Environment.MarkerIndex[] matchByPosition(Antilatency.Math.float3[] rays, Antilatency.Math.float3 origin);
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_Alt_Environment_IEnvironment_InterfaceID = new System.Guid("c257c858-f296-43b7-b6b5-c14b9afb1a13");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.Alt.Environment.IEnvironment result) {
		var guid = Antilatency_Alt_Environment_IEnvironment_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.Alt.Environment.Details.IEnvironmentWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.Alt.Environment.IEnvironment result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_Alt_Environment_IEnvironment_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.Alt.Environment.Details.IEnvironmentWrapper(ptr);
		}
	}
}
namespace Antilatency.Alt.Environment {
	namespace Details {
		public class IEnvironmentWrapper : Antilatency.InterfaceContract.Details.IInterfaceWrapper, IEnvironment {
			private IEnvironmentRemap.VMT _VMT = new IEnvironmentRemap.VMT();
			protected new int GetTotalNativeMethodsCount() {
			    return base.GetTotalNativeMethodsCount() + typeof(IEnvironmentRemap.VMT).GetFields().Length;
			}
			public IEnvironmentWrapper(System.IntPtr obj) : base(obj) {
			    _VMT = LoadVMT<IEnvironmentRemap.VMT>(base.GetTotalNativeMethodsCount());
			}
			public Antilatency.InterfaceContract.Bool isMutable() {
				Antilatency.InterfaceContract.Bool result;
				Antilatency.InterfaceContract.Bool resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.isMutable(_object, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
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
			public Antilatency.InterfaceContract.Bool filterRay(Antilatency.Math.float3 up, Antilatency.Math.float3 ray) {
				Antilatency.InterfaceContract.Bool result;
				Antilatency.InterfaceContract.Bool resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.filterRay(_object, up, ray, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public Antilatency.InterfaceContract.Bool match(Antilatency.Math.float3[] raysUpSpace, out Antilatency.Alt.Environment.MarkerIndex[] markersIndices, out Antilatency.Math.floatP3Q poseOfUpSpace) {
				Antilatency.InterfaceContract.Bool result;
				Antilatency.InterfaceContract.Bool resultMarshaler;
				var raysUpSpaceMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(raysUpSpace);
				var markersIndicesMarshaler = Antilatency.InterfaceContract.Details.ArrayOutMarshaler.create<Antilatency.Alt.Environment.MarkerIndex>();
				Antilatency.Math.floatP3Q poseOfUpSpaceMarshaler;
				var interfaceContractExceptionCode = (_VMT.match(_object, raysUpSpaceMarshaler, markersIndicesMarshaler, out poseOfUpSpaceMarshaler, out resultMarshaler));
				raysUpSpaceMarshaler.Dispose();
				markersIndices = markersIndicesMarshaler.value;
				markersIndicesMarshaler.Dispose();
				poseOfUpSpace = poseOfUpSpaceMarshaler;
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public Antilatency.Alt.Environment.MarkerIndex[] matchByPosition(Antilatency.Math.float3[] rays, Antilatency.Math.float3 origin) {
				Antilatency.Alt.Environment.MarkerIndex[] result;
				var resultMarshaler = Antilatency.InterfaceContract.Details.ArrayOutMarshaler.create<Antilatency.Alt.Environment.MarkerIndex>();
				var raysMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(rays);
				var interfaceContractExceptionCode = (_VMT.matchByPosition(_object, raysMarshaler, origin, resultMarshaler));
				raysMarshaler.Dispose();
				result = resultMarshaler.value;
				resultMarshaler.Dispose();
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
		}
		public class IEnvironmentRemap : Antilatency.InterfaceContract.Details.IInterfaceRemap {
			public new struct VMT {
				public delegate Antilatency.InterfaceContract.ExceptionCode isMutableDelegate(System.IntPtr _this, out Antilatency.InterfaceContract.Bool result);
				public delegate Antilatency.InterfaceContract.ExceptionCode getMarkersDelegate(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result);
				public delegate Antilatency.InterfaceContract.ExceptionCode filterRayDelegate(System.IntPtr _this, Antilatency.Math.float3 up, Antilatency.Math.float3 ray, out Antilatency.InterfaceContract.Bool result);
				public delegate Antilatency.InterfaceContract.ExceptionCode matchDelegate(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate raysUpSpace, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate markersIndices, out Antilatency.Math.floatP3Q poseOfUpSpace, out Antilatency.InterfaceContract.Bool result);
				public delegate Antilatency.InterfaceContract.ExceptionCode matchByPositionDelegate(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate rays, Antilatency.Math.float3 origin, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result);
				#pragma warning disable 0649
				public isMutableDelegate isMutable;
				public getMarkersDelegate getMarkers;
				public filterRayDelegate filterRay;
				public matchDelegate match;
				public matchByPositionDelegate matchByPosition;
				#pragma warning restore 0649
			}
			public new static readonly NativeInterfaceVmt NativeVmt;
			static IEnvironmentRemap() {
				var vmtBlocks = new System.Collections.Generic.List<object>();
				AppendVmt(vmtBlocks);
				NativeVmt = new NativeInterfaceVmt(vmtBlocks);
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.isMutableDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode isMutable(System.IntPtr _this, out Antilatency.InterfaceContract.Bool result) {
				try {
					var obj = GetContext(_this) as IEnvironment;
					var resultMarshaler = obj.isMutable();
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(Antilatency.InterfaceContract.Bool);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getMarkersDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getMarkers(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result) {
				try {
					var obj = GetContext(_this) as IEnvironment;
					var resultMarshaler = obj.getMarkers();
					result.assign(resultMarshaler);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.filterRayDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode filterRay(System.IntPtr _this, Antilatency.Math.float3 up, Antilatency.Math.float3 ray, out Antilatency.InterfaceContract.Bool result) {
				try {
					var obj = GetContext(_this) as IEnvironment;
					var resultMarshaler = obj.filterRay(up, ray);
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(Antilatency.InterfaceContract.Bool);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.matchDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode match(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate raysUpSpace, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate markersIndices, out Antilatency.Math.floatP3Q poseOfUpSpace, out Antilatency.InterfaceContract.Bool result) {
				try {
					var obj = GetContext(_this) as IEnvironment;
					Antilatency.Alt.Environment.MarkerIndex[] markersIndicesMarshaler;
					Antilatency.Math.floatP3Q poseOfUpSpaceMarshaler;
					poseOfUpSpace = default(Antilatency.Math.floatP3Q);
					var resultMarshaler = obj.match(raysUpSpace.toArray<Antilatency.Math.float3>(), out markersIndicesMarshaler, out poseOfUpSpaceMarshaler);
					markersIndices.assign(markersIndicesMarshaler);
					poseOfUpSpace = poseOfUpSpaceMarshaler;
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(Antilatency.InterfaceContract.Bool);
					poseOfUpSpace = default(Antilatency.Math.floatP3Q);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.matchByPositionDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode matchByPosition(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate rays, Antilatency.Math.float3 origin, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result) {
				try {
					var obj = GetContext(_this) as IEnvironment;
					var resultMarshaler = obj.matchByPosition(rays.toArray<Antilatency.Math.float3>(), origin);
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
				vmt.isMutable = isMutable;
				vmt.getMarkers = getMarkers;
				vmt.filterRay = filterRay;
				vmt.match = match;
				vmt.matchByPosition = matchByPosition;
				buffer.Add(vmt);
			}
			public IEnvironmentRemap() { }
			public IEnvironmentRemap(System.IntPtr context, ushort lifetimeId) {
				AllocateNativeInterface(NativeVmt.Handle, context, lifetimeId);
			}
		}
	}
}

namespace Antilatency.Alt.Environment {
	[Guid("b691107e-d628-4c62-8003-e4d784b342e7")]
	[Antilatency.InterfaceContract.InterfaceId("b691107e-d628-4c62-8003-e4d784b342e7")]
	public interface IEnvironmentConstructor : Antilatency.InterfaceContract.IInterface {
		Antilatency.Alt.Environment.IEnvironment createEnvironment(string data);
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_Alt_Environment_IEnvironmentConstructor_InterfaceID = new System.Guid("b691107e-d628-4c62-8003-e4d784b342e7");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.Alt.Environment.IEnvironmentConstructor result) {
		var guid = Antilatency_Alt_Environment_IEnvironmentConstructor_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.Alt.Environment.Details.IEnvironmentConstructorWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.Alt.Environment.IEnvironmentConstructor result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_Alt_Environment_IEnvironmentConstructor_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.Alt.Environment.Details.IEnvironmentConstructorWrapper(ptr);
		}
	}
}
namespace Antilatency.Alt.Environment {
	namespace Details {
		public class IEnvironmentConstructorWrapper : Antilatency.InterfaceContract.Details.IInterfaceWrapper, IEnvironmentConstructor {
			private IEnvironmentConstructorRemap.VMT _VMT = new IEnvironmentConstructorRemap.VMT();
			protected new int GetTotalNativeMethodsCount() {
			    return base.GetTotalNativeMethodsCount() + typeof(IEnvironmentConstructorRemap.VMT).GetFields().Length;
			}
			public IEnvironmentConstructorWrapper(System.IntPtr obj) : base(obj) {
			    _VMT = LoadVMT<IEnvironmentConstructorRemap.VMT>(base.GetTotalNativeMethodsCount());
			}
			public Antilatency.Alt.Environment.IEnvironment createEnvironment(string data) {
				Antilatency.Alt.Environment.IEnvironment result;
				System.IntPtr resultMarshaler;
				var dataMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(data);
				var interfaceContractExceptionCode = (_VMT.createEnvironment(_object, dataMarshaler, out resultMarshaler));
				dataMarshaler.Dispose();
				result = (resultMarshaler==System.IntPtr.Zero) ? null : new Antilatency.Alt.Environment.Details.IEnvironmentWrapper(resultMarshaler);
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
		}
		public class IEnvironmentConstructorRemap : Antilatency.InterfaceContract.Details.IInterfaceRemap {
			public new struct VMT {
				public delegate Antilatency.InterfaceContract.ExceptionCode createEnvironmentDelegate(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate data, out System.IntPtr result);
				#pragma warning disable 0649
				public createEnvironmentDelegate createEnvironment;
				#pragma warning restore 0649
			}
			public new static readonly NativeInterfaceVmt NativeVmt;
			static IEnvironmentConstructorRemap() {
				var vmtBlocks = new System.Collections.Generic.List<object>();
				AppendVmt(vmtBlocks);
				NativeVmt = new NativeInterfaceVmt(vmtBlocks);
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.createEnvironmentDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode createEnvironment(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate data, out System.IntPtr result) {
				try {
					var obj = GetContext(_this) as IEnvironmentConstructor;
					var resultMarshaler = obj.createEnvironment(data);
					result = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.Alt.Environment.IEnvironment>(resultMarshaler);
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
				vmt.createEnvironment = createEnvironment;
				buffer.Add(vmt);
			}
			public IEnvironmentConstructorRemap() { }
			public IEnvironmentConstructorRemap(System.IntPtr context, ushort lifetimeId) {
				AllocateNativeInterface(NativeVmt.Handle, context, lifetimeId);
			}
		}
	}
}

namespace Antilatency.Alt.Environment {
	[Guid("b789cd05-f845-4237-bc97-9bc8168190e4")]
	[Antilatency.InterfaceContract.InterfaceId("b789cd05-f845-4237-bc97-9bc8168190e4")]
	public interface IOrientationAwareEnvironment : Antilatency.InterfaceContract.IInterface {
		Antilatency.Math.floatQ getRotation();
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_Alt_Environment_IOrientationAwareEnvironment_InterfaceID = new System.Guid("b789cd05-f845-4237-bc97-9bc8168190e4");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.Alt.Environment.IOrientationAwareEnvironment result) {
		var guid = Antilatency_Alt_Environment_IOrientationAwareEnvironment_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.Alt.Environment.Details.IOrientationAwareEnvironmentWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.Alt.Environment.IOrientationAwareEnvironment result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_Alt_Environment_IOrientationAwareEnvironment_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.Alt.Environment.Details.IOrientationAwareEnvironmentWrapper(ptr);
		}
	}
}
namespace Antilatency.Alt.Environment {
	namespace Details {
		public class IOrientationAwareEnvironmentWrapper : Antilatency.InterfaceContract.Details.IInterfaceWrapper, IOrientationAwareEnvironment {
			private IOrientationAwareEnvironmentRemap.VMT _VMT = new IOrientationAwareEnvironmentRemap.VMT();
			protected new int GetTotalNativeMethodsCount() {
			    return base.GetTotalNativeMethodsCount() + typeof(IOrientationAwareEnvironmentRemap.VMT).GetFields().Length;
			}
			public IOrientationAwareEnvironmentWrapper(System.IntPtr obj) : base(obj) {
			    _VMT = LoadVMT<IOrientationAwareEnvironmentRemap.VMT>(base.GetTotalNativeMethodsCount());
			}
			public Antilatency.Math.floatQ getRotation() {
				Antilatency.Math.floatQ result;
				Antilatency.Math.floatQ resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.getRotation(_object, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
		}
		public class IOrientationAwareEnvironmentRemap : Antilatency.InterfaceContract.Details.IInterfaceRemap {
			public new struct VMT {
				public delegate Antilatency.InterfaceContract.ExceptionCode getRotationDelegate(System.IntPtr _this, out Antilatency.Math.floatQ result);
				#pragma warning disable 0649
				public getRotationDelegate getRotation;
				#pragma warning restore 0649
			}
			public new static readonly NativeInterfaceVmt NativeVmt;
			static IOrientationAwareEnvironmentRemap() {
				var vmtBlocks = new System.Collections.Generic.List<object>();
				AppendVmt(vmtBlocks);
				NativeVmt = new NativeInterfaceVmt(vmtBlocks);
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getRotationDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getRotation(System.IntPtr _this, out Antilatency.Math.floatQ result) {
				try {
					var obj = GetContext(_this) as IOrientationAwareEnvironment;
					var resultMarshaler = obj.getRotation();
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(Antilatency.Math.floatQ);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			protected static new void AppendVmt(System.Collections.Generic.List<object> buffer) {
				Antilatency.InterfaceContract.Details.IInterfaceRemap.AppendVmt(buffer);
				var vmt = new VMT();
				vmt.getRotation = getRotation;
				buffer.Add(vmt);
			}
			public IOrientationAwareEnvironmentRemap() { }
			public IOrientationAwareEnvironmentRemap(System.IntPtr context, ushort lifetimeId) {
				AllocateNativeInterface(NativeVmt.Handle, context, lifetimeId);
			}
		}
	}
}

namespace Antilatency.Alt.Environment {
	[Guid("e664544b-afd5-4723-949a-9a888526ef97")]
	[Antilatency.InterfaceContract.InterfaceId("e664544b-afd5-4723-949a-9a888526ef97")]
	public interface IEnvironmentMutable : Antilatency.InterfaceContract.IInterface {
		Antilatency.InterfaceContract.Bool mutate(float[] powers, Antilatency.Math.float3[] rays, float sphereD, Antilatency.Math.float2[] x, Antilatency.Math.float2x3[] xOverPosition, Antilatency.Math.float3 up);
		int getUpdateId();
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_Alt_Environment_IEnvironmentMutable_InterfaceID = new System.Guid("e664544b-afd5-4723-949a-9a888526ef97");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.Alt.Environment.IEnvironmentMutable result) {
		var guid = Antilatency_Alt_Environment_IEnvironmentMutable_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.Alt.Environment.Details.IEnvironmentMutableWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.Alt.Environment.IEnvironmentMutable result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_Alt_Environment_IEnvironmentMutable_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.Alt.Environment.Details.IEnvironmentMutableWrapper(ptr);
		}
	}
}
namespace Antilatency.Alt.Environment {
	namespace Details {
		public class IEnvironmentMutableWrapper : Antilatency.InterfaceContract.Details.IInterfaceWrapper, IEnvironmentMutable {
			private IEnvironmentMutableRemap.VMT _VMT = new IEnvironmentMutableRemap.VMT();
			protected new int GetTotalNativeMethodsCount() {
			    return base.GetTotalNativeMethodsCount() + typeof(IEnvironmentMutableRemap.VMT).GetFields().Length;
			}
			public IEnvironmentMutableWrapper(System.IntPtr obj) : base(obj) {
			    _VMT = LoadVMT<IEnvironmentMutableRemap.VMT>(base.GetTotalNativeMethodsCount());
			}
			public Antilatency.InterfaceContract.Bool mutate(float[] powers, Antilatency.Math.float3[] rays, float sphereD, Antilatency.Math.float2[] x, Antilatency.Math.float2x3[] xOverPosition, Antilatency.Math.float3 up) {
				Antilatency.InterfaceContract.Bool result;
				Antilatency.InterfaceContract.Bool resultMarshaler;
				var powersMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(powers);
				var raysMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(rays);
				var xMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(x);
				var xOverPositionMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(xOverPosition);
				var interfaceContractExceptionCode = (_VMT.mutate(_object, powersMarshaler, raysMarshaler, sphereD, xMarshaler, xOverPositionMarshaler, up, out resultMarshaler));
				powersMarshaler.Dispose();
				raysMarshaler.Dispose();
				xMarshaler.Dispose();
				xOverPositionMarshaler.Dispose();
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public int getUpdateId() {
				int result;
				int resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.getUpdateId(_object, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
		}
		public class IEnvironmentMutableRemap : Antilatency.InterfaceContract.Details.IInterfaceRemap {
			public new struct VMT {
				public delegate Antilatency.InterfaceContract.ExceptionCode mutateDelegate(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate powers, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate rays, float sphereD, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate x, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate xOverPosition, Antilatency.Math.float3 up, out Antilatency.InterfaceContract.Bool result);
				public delegate Antilatency.InterfaceContract.ExceptionCode getUpdateIdDelegate(System.IntPtr _this, out int result);
				#pragma warning disable 0649
				public mutateDelegate mutate;
				public getUpdateIdDelegate getUpdateId;
				#pragma warning restore 0649
			}
			public new static readonly NativeInterfaceVmt NativeVmt;
			static IEnvironmentMutableRemap() {
				var vmtBlocks = new System.Collections.Generic.List<object>();
				AppendVmt(vmtBlocks);
				NativeVmt = new NativeInterfaceVmt(vmtBlocks);
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.mutateDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode mutate(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate powers, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate rays, float sphereD, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate x, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate xOverPosition, Antilatency.Math.float3 up, out Antilatency.InterfaceContract.Bool result) {
				try {
					var obj = GetContext(_this) as IEnvironmentMutable;
					var resultMarshaler = obj.mutate(powers.toArray<float>(), rays.toArray<Antilatency.Math.float3>(), sphereD, x.toArray<Antilatency.Math.float2>(), xOverPosition.toArray<Antilatency.Math.float2x3>(), up);
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(Antilatency.InterfaceContract.Bool);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getUpdateIdDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getUpdateId(System.IntPtr _this, out int result) {
				try {
					var obj = GetContext(_this) as IEnvironmentMutable;
					var resultMarshaler = obj.getUpdateId();
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(int);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			protected static new void AppendVmt(System.Collections.Generic.List<object> buffer) {
				Antilatency.InterfaceContract.Details.IInterfaceRemap.AppendVmt(buffer);
				var vmt = new VMT();
				vmt.mutate = mutate;
				vmt.getUpdateId = getUpdateId;
				buffer.Add(vmt);
			}
			public IEnvironmentMutableRemap() { }
			public IEnvironmentMutableRemap(System.IntPtr context, ushort lifetimeId) {
				AllocateNativeInterface(NativeVmt.Handle, context, lifetimeId);
			}
		}
	}
}


