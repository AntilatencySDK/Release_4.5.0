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
namespace Antilatency.Alt.Environment.Pillars {
	[System.Serializable]
	[System.Runtime.InteropServices.StructLayout(LayoutKind.Sequential)]
	public partial struct PillarData {
		public Antilatency.Math.float3 position;
		public uint kind;
		public float angle01;
		public float fov01;
	}
}

namespace Antilatency.Alt.Environment.Pillars {
	[Guid("143f0dac-4ba6-44c3-ab3f-e096a48c24e5")]
	[Antilatency.InterfaceContract.InterfaceId("143f0dac-4ba6-44c3-ab3f-e096a48c24e5")]
	public interface IScheme : Antilatency.InterfaceContract.IInterface {
		uint getNumMarkersPerPillar();
		void setNumMarkersPerPillar(uint numMarkersPerPillar);
		float getPillarLength();
		void setPillarLength(float pillarLength);
		float getDefaultFovDeg();
		void setDefaultFovDeg(float defaultFovDeg);
		float getPillarsVerticalOffset();
		void setPillarsVerticalOffset(float pillarsVerticalOffset);
		Antilatency.InterfaceContract.Bool getStrictMatch();
		void setStrictMatch(Antilatency.InterfaceContract.Bool strictMatch);
		void setNumPillarsKinds(uint numPillarsKinds);
		uint getNumPillarsKinds();
		float[] getProportions(uint pillarKind);
		void setProportions(float[] proportions, uint pillarKind);
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_Alt_Environment_Pillars_IScheme_InterfaceID = new System.Guid("143f0dac-4ba6-44c3-ab3f-e096a48c24e5");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.Alt.Environment.Pillars.IScheme result) {
		var guid = Antilatency_Alt_Environment_Pillars_IScheme_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.Alt.Environment.Pillars.Details.ISchemeWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.Alt.Environment.Pillars.IScheme result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_Alt_Environment_Pillars_IScheme_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.Alt.Environment.Pillars.Details.ISchemeWrapper(ptr);
		}
	}
}
namespace Antilatency.Alt.Environment.Pillars {
	namespace Details {
		public class ISchemeWrapper : Antilatency.InterfaceContract.Details.IInterfaceWrapper, IScheme {
			private ISchemeRemap.VMT _VMT = new ISchemeRemap.VMT();
			protected new int GetTotalNativeMethodsCount() {
			    return base.GetTotalNativeMethodsCount() + typeof(ISchemeRemap.VMT).GetFields().Length;
			}
			public ISchemeWrapper(System.IntPtr obj) : base(obj) {
			    _VMT = LoadVMT<ISchemeRemap.VMT>(base.GetTotalNativeMethodsCount());
			}
			public uint getNumMarkersPerPillar() {
				uint result;
				uint resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.getNumMarkersPerPillar(_object, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public void setNumMarkersPerPillar(uint numMarkersPerPillar) {
				var interfaceContractExceptionCode = (_VMT.setNumMarkersPerPillar(_object, numMarkersPerPillar));
				HandleExceptionCode(interfaceContractExceptionCode);
			}
			public float getPillarLength() {
				float result;
				float resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.getPillarLength(_object, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public void setPillarLength(float pillarLength) {
				var interfaceContractExceptionCode = (_VMT.setPillarLength(_object, pillarLength));
				HandleExceptionCode(interfaceContractExceptionCode);
			}
			public float getDefaultFovDeg() {
				float result;
				float resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.getDefaultFovDeg(_object, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public void setDefaultFovDeg(float defaultFovDeg) {
				var interfaceContractExceptionCode = (_VMT.setDefaultFovDeg(_object, defaultFovDeg));
				HandleExceptionCode(interfaceContractExceptionCode);
			}
			public float getPillarsVerticalOffset() {
				float result;
				float resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.getPillarsVerticalOffset(_object, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public void setPillarsVerticalOffset(float pillarsVerticalOffset) {
				var interfaceContractExceptionCode = (_VMT.setPillarsVerticalOffset(_object, pillarsVerticalOffset));
				HandleExceptionCode(interfaceContractExceptionCode);
			}
			public Antilatency.InterfaceContract.Bool getStrictMatch() {
				Antilatency.InterfaceContract.Bool result;
				Antilatency.InterfaceContract.Bool resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.getStrictMatch(_object, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public void setStrictMatch(Antilatency.InterfaceContract.Bool strictMatch) {
				var interfaceContractExceptionCode = (_VMT.setStrictMatch(_object, strictMatch));
				HandleExceptionCode(interfaceContractExceptionCode);
			}
			public void setNumPillarsKinds(uint numPillarsKinds) {
				var interfaceContractExceptionCode = (_VMT.setNumPillarsKinds(_object, numPillarsKinds));
				HandleExceptionCode(interfaceContractExceptionCode);
			}
			public uint getNumPillarsKinds() {
				uint result;
				uint resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.getNumPillarsKinds(_object, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public float[] getProportions(uint pillarKind) {
				float[] result;
				var resultMarshaler = Antilatency.InterfaceContract.Details.ArrayOutMarshaler.create<float>();
				var interfaceContractExceptionCode = (_VMT.getProportions(_object, pillarKind, resultMarshaler));
				result = resultMarshaler.value;
				resultMarshaler.Dispose();
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public void setProportions(float[] proportions, uint pillarKind) {
				var proportionsMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(proportions);
				var interfaceContractExceptionCode = (_VMT.setProportions(_object, proportionsMarshaler, pillarKind));
				proportionsMarshaler.Dispose();
				HandleExceptionCode(interfaceContractExceptionCode);
			}
		}
		public class ISchemeRemap : Antilatency.InterfaceContract.Details.IInterfaceRemap {
			public new struct VMT {
				public delegate Antilatency.InterfaceContract.ExceptionCode getNumMarkersPerPillarDelegate(System.IntPtr _this, out uint result);
				public delegate Antilatency.InterfaceContract.ExceptionCode setNumMarkersPerPillarDelegate(System.IntPtr _this, uint numMarkersPerPillar);
				public delegate Antilatency.InterfaceContract.ExceptionCode getPillarLengthDelegate(System.IntPtr _this, out float result);
				public delegate Antilatency.InterfaceContract.ExceptionCode setPillarLengthDelegate(System.IntPtr _this, float pillarLength);
				public delegate Antilatency.InterfaceContract.ExceptionCode getDefaultFovDegDelegate(System.IntPtr _this, out float result);
				public delegate Antilatency.InterfaceContract.ExceptionCode setDefaultFovDegDelegate(System.IntPtr _this, float defaultFovDeg);
				public delegate Antilatency.InterfaceContract.ExceptionCode getPillarsVerticalOffsetDelegate(System.IntPtr _this, out float result);
				public delegate Antilatency.InterfaceContract.ExceptionCode setPillarsVerticalOffsetDelegate(System.IntPtr _this, float pillarsVerticalOffset);
				public delegate Antilatency.InterfaceContract.ExceptionCode getStrictMatchDelegate(System.IntPtr _this, out Antilatency.InterfaceContract.Bool result);
				public delegate Antilatency.InterfaceContract.ExceptionCode setStrictMatchDelegate(System.IntPtr _this, Antilatency.InterfaceContract.Bool strictMatch);
				public delegate Antilatency.InterfaceContract.ExceptionCode setNumPillarsKindsDelegate(System.IntPtr _this, uint numPillarsKinds);
				public delegate Antilatency.InterfaceContract.ExceptionCode getNumPillarsKindsDelegate(System.IntPtr _this, out uint result);
				public delegate Antilatency.InterfaceContract.ExceptionCode getProportionsDelegate(System.IntPtr _this, uint pillarKind, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result);
				public delegate Antilatency.InterfaceContract.ExceptionCode setProportionsDelegate(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate proportions, uint pillarKind);
				#pragma warning disable 0649
				public getNumMarkersPerPillarDelegate getNumMarkersPerPillar;
				public setNumMarkersPerPillarDelegate setNumMarkersPerPillar;
				public getPillarLengthDelegate getPillarLength;
				public setPillarLengthDelegate setPillarLength;
				public getDefaultFovDegDelegate getDefaultFovDeg;
				public setDefaultFovDegDelegate setDefaultFovDeg;
				public getPillarsVerticalOffsetDelegate getPillarsVerticalOffset;
				public setPillarsVerticalOffsetDelegate setPillarsVerticalOffset;
				public getStrictMatchDelegate getStrictMatch;
				public setStrictMatchDelegate setStrictMatch;
				public setNumPillarsKindsDelegate setNumPillarsKinds;
				public getNumPillarsKindsDelegate getNumPillarsKinds;
				public getProportionsDelegate getProportions;
				public setProportionsDelegate setProportions;
				#pragma warning restore 0649
			}
			public new static readonly NativeInterfaceVmt NativeVmt;
			static ISchemeRemap() {
				var vmtBlocks = new System.Collections.Generic.List<object>();
				AppendVmt(vmtBlocks);
				NativeVmt = new NativeInterfaceVmt(vmtBlocks);
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getNumMarkersPerPillarDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getNumMarkersPerPillar(System.IntPtr _this, out uint result) {
				try {
					var obj = GetContext(_this) as IScheme;
					var resultMarshaler = obj.getNumMarkersPerPillar();
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(uint);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.setNumMarkersPerPillarDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode setNumMarkersPerPillar(System.IntPtr _this, uint numMarkersPerPillar) {
				try {
					var obj = GetContext(_this) as IScheme;
					obj.setNumMarkersPerPillar(numMarkersPerPillar);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getPillarLengthDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getPillarLength(System.IntPtr _this, out float result) {
				try {
					var obj = GetContext(_this) as IScheme;
					var resultMarshaler = obj.getPillarLength();
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(float);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.setPillarLengthDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode setPillarLength(System.IntPtr _this, float pillarLength) {
				try {
					var obj = GetContext(_this) as IScheme;
					obj.setPillarLength(pillarLength);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getDefaultFovDegDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getDefaultFovDeg(System.IntPtr _this, out float result) {
				try {
					var obj = GetContext(_this) as IScheme;
					var resultMarshaler = obj.getDefaultFovDeg();
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(float);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.setDefaultFovDegDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode setDefaultFovDeg(System.IntPtr _this, float defaultFovDeg) {
				try {
					var obj = GetContext(_this) as IScheme;
					obj.setDefaultFovDeg(defaultFovDeg);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getPillarsVerticalOffsetDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getPillarsVerticalOffset(System.IntPtr _this, out float result) {
				try {
					var obj = GetContext(_this) as IScheme;
					var resultMarshaler = obj.getPillarsVerticalOffset();
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(float);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.setPillarsVerticalOffsetDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode setPillarsVerticalOffset(System.IntPtr _this, float pillarsVerticalOffset) {
				try {
					var obj = GetContext(_this) as IScheme;
					obj.setPillarsVerticalOffset(pillarsVerticalOffset);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getStrictMatchDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getStrictMatch(System.IntPtr _this, out Antilatency.InterfaceContract.Bool result) {
				try {
					var obj = GetContext(_this) as IScheme;
					var resultMarshaler = obj.getStrictMatch();
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(Antilatency.InterfaceContract.Bool);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.setStrictMatchDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode setStrictMatch(System.IntPtr _this, Antilatency.InterfaceContract.Bool strictMatch) {
				try {
					var obj = GetContext(_this) as IScheme;
					obj.setStrictMatch(strictMatch);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.setNumPillarsKindsDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode setNumPillarsKinds(System.IntPtr _this, uint numPillarsKinds) {
				try {
					var obj = GetContext(_this) as IScheme;
					obj.setNumPillarsKinds(numPillarsKinds);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getNumPillarsKindsDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getNumPillarsKinds(System.IntPtr _this, out uint result) {
				try {
					var obj = GetContext(_this) as IScheme;
					var resultMarshaler = obj.getNumPillarsKinds();
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(uint);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getProportionsDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getProportions(System.IntPtr _this, uint pillarKind, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result) {
				try {
					var obj = GetContext(_this) as IScheme;
					var resultMarshaler = obj.getProportions(pillarKind);
					result.assign(resultMarshaler);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.setProportionsDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode setProportions(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate proportions, uint pillarKind) {
				try {
					var obj = GetContext(_this) as IScheme;
					obj.setProportions(proportions.toArray<float>(), pillarKind);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			protected static new void AppendVmt(System.Collections.Generic.List<object> buffer) {
				Antilatency.InterfaceContract.Details.IInterfaceRemap.AppendVmt(buffer);
				var vmt = new VMT();
				vmt.getNumMarkersPerPillar = getNumMarkersPerPillar;
				vmt.setNumMarkersPerPillar = setNumMarkersPerPillar;
				vmt.getPillarLength = getPillarLength;
				vmt.setPillarLength = setPillarLength;
				vmt.getDefaultFovDeg = getDefaultFovDeg;
				vmt.setDefaultFovDeg = setDefaultFovDeg;
				vmt.getPillarsVerticalOffset = getPillarsVerticalOffset;
				vmt.setPillarsVerticalOffset = setPillarsVerticalOffset;
				vmt.getStrictMatch = getStrictMatch;
				vmt.setStrictMatch = setStrictMatch;
				vmt.setNumPillarsKinds = setNumPillarsKinds;
				vmt.getNumPillarsKinds = getNumPillarsKinds;
				vmt.getProportions = getProportions;
				vmt.setProportions = setProportions;
				buffer.Add(vmt);
			}
			public ISchemeRemap() { }
			public ISchemeRemap(System.IntPtr context, ushort lifetimeId) {
				AllocateNativeInterface(NativeVmt.Handle, context, lifetimeId);
			}
		}
	}
}

namespace Antilatency.Alt.Environment.Pillars {
	[Guid("28eb9cd7-28dc-4318-aa95-32886161e14b")]
	[Antilatency.InterfaceContract.InterfaceId("28eb9cd7-28dc-4318-aa95-32886161e14b")]
	public interface IDeserializedEnvironment : Antilatency.InterfaceContract.IInterface {
		Antilatency.Alt.Environment.Pillars.PillarData[] getPillars();
		Antilatency.Alt.Environment.Pillars.IScheme getScheme();
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_Alt_Environment_Pillars_IDeserializedEnvironment_InterfaceID = new System.Guid("28eb9cd7-28dc-4318-aa95-32886161e14b");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.Alt.Environment.Pillars.IDeserializedEnvironment result) {
		var guid = Antilatency_Alt_Environment_Pillars_IDeserializedEnvironment_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.Alt.Environment.Pillars.Details.IDeserializedEnvironmentWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.Alt.Environment.Pillars.IDeserializedEnvironment result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_Alt_Environment_Pillars_IDeserializedEnvironment_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.Alt.Environment.Pillars.Details.IDeserializedEnvironmentWrapper(ptr);
		}
	}
}
namespace Antilatency.Alt.Environment.Pillars {
	namespace Details {
		public class IDeserializedEnvironmentWrapper : Antilatency.InterfaceContract.Details.IInterfaceWrapper, IDeserializedEnvironment {
			private IDeserializedEnvironmentRemap.VMT _VMT = new IDeserializedEnvironmentRemap.VMT();
			protected new int GetTotalNativeMethodsCount() {
			    return base.GetTotalNativeMethodsCount() + typeof(IDeserializedEnvironmentRemap.VMT).GetFields().Length;
			}
			public IDeserializedEnvironmentWrapper(System.IntPtr obj) : base(obj) {
			    _VMT = LoadVMT<IDeserializedEnvironmentRemap.VMT>(base.GetTotalNativeMethodsCount());
			}
			public Antilatency.Alt.Environment.Pillars.PillarData[] getPillars() {
				Antilatency.Alt.Environment.Pillars.PillarData[] result;
				var resultMarshaler = Antilatency.InterfaceContract.Details.ArrayOutMarshaler.create<Antilatency.Alt.Environment.Pillars.PillarData>();
				var interfaceContractExceptionCode = (_VMT.getPillars(_object, resultMarshaler));
				result = resultMarshaler.value;
				resultMarshaler.Dispose();
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public Antilatency.Alt.Environment.Pillars.IScheme getScheme() {
				Antilatency.Alt.Environment.Pillars.IScheme result;
				System.IntPtr resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.getScheme(_object, out resultMarshaler));
				result = (resultMarshaler==System.IntPtr.Zero) ? null : new Antilatency.Alt.Environment.Pillars.Details.ISchemeWrapper(resultMarshaler);
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
		}
		public class IDeserializedEnvironmentRemap : Antilatency.InterfaceContract.Details.IInterfaceRemap {
			public new struct VMT {
				public delegate Antilatency.InterfaceContract.ExceptionCode getPillarsDelegate(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result);
				public delegate Antilatency.InterfaceContract.ExceptionCode getSchemeDelegate(System.IntPtr _this, out System.IntPtr result);
				#pragma warning disable 0649
				public getPillarsDelegate getPillars;
				public getSchemeDelegate getScheme;
				#pragma warning restore 0649
			}
			public new static readonly NativeInterfaceVmt NativeVmt;
			static IDeserializedEnvironmentRemap() {
				var vmtBlocks = new System.Collections.Generic.List<object>();
				AppendVmt(vmtBlocks);
				NativeVmt = new NativeInterfaceVmt(vmtBlocks);
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getPillarsDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getPillars(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result) {
				try {
					var obj = GetContext(_this) as IDeserializedEnvironment;
					var resultMarshaler = obj.getPillars();
					result.assign(resultMarshaler);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getSchemeDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getScheme(System.IntPtr _this, out System.IntPtr result) {
				try {
					var obj = GetContext(_this) as IDeserializedEnvironment;
					var resultMarshaler = obj.getScheme();
					result = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.Alt.Environment.Pillars.IScheme>(resultMarshaler);
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
				vmt.getPillars = getPillars;
				vmt.getScheme = getScheme;
				buffer.Add(vmt);
			}
			public IDeserializedEnvironmentRemap() { }
			public IDeserializedEnvironmentRemap(System.IntPtr context, ushort lifetimeId) {
				AllocateNativeInterface(NativeVmt.Handle, context, lifetimeId);
			}
		}
	}
}

namespace Antilatency.Alt.Environment.Pillars {
	[Guid("8c5671c0-07d0-4ca0-8666-39eb75d7f073")]
	[Antilatency.InterfaceContract.InterfaceId("8c5671c0-07d0-4ca0-8666-39eb75d7f073")]
	public interface ILibrary : Antilatency.Alt.Environment.IEnvironmentConstructor {
		string serialize(Antilatency.Alt.Environment.Pillars.PillarData[] pillars, Antilatency.Alt.Environment.Pillars.IScheme scheme);
		Antilatency.Alt.Environment.Pillars.IDeserializedEnvironment deserialize(string environmentData);
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_Alt_Environment_Pillars_ILibrary_InterfaceID = new System.Guid("8c5671c0-07d0-4ca0-8666-39eb75d7f073");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.Alt.Environment.Pillars.ILibrary result) {
		var guid = Antilatency_Alt_Environment_Pillars_ILibrary_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.Alt.Environment.Pillars.Details.ILibraryWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.Alt.Environment.Pillars.ILibrary result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_Alt_Environment_Pillars_ILibrary_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.Alt.Environment.Pillars.Details.ILibraryWrapper(ptr);
		}
	}
}
namespace Antilatency.Alt.Environment.Pillars {
	public static class Library{
	    #if ANTILATENCY_INTERFACECONTRACT_CUSTOMLIBPATHS
	    [DllImport(Antilatency.InterfaceContract.LibraryPaths.AntilatencyAltEnvironmentPillars)]
	    #else
	    [DllImport("AntilatencyAltEnvironmentPillars")]
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
			public string serialize(Antilatency.Alt.Environment.Pillars.PillarData[] pillars, Antilatency.Alt.Environment.Pillars.IScheme scheme) {
				string result;
				var resultMarshaler = Antilatency.InterfaceContract.Details.ArrayOutMarshaler.create();
				var pillarsMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(pillars);
				var schemeMarshaler = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.Alt.Environment.Pillars.IScheme>(scheme);
				var interfaceContractExceptionCode = (_VMT.serialize(_object, pillarsMarshaler, schemeMarshaler, resultMarshaler));
				pillarsMarshaler.Dispose();
				result = resultMarshaler.value;
				resultMarshaler.Dispose();
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public Antilatency.Alt.Environment.Pillars.IDeserializedEnvironment deserialize(string environmentData) {
				Antilatency.Alt.Environment.Pillars.IDeserializedEnvironment result;
				System.IntPtr resultMarshaler;
				var environmentDataMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(environmentData);
				var interfaceContractExceptionCode = (_VMT.deserialize(_object, environmentDataMarshaler, out resultMarshaler));
				environmentDataMarshaler.Dispose();
				result = (resultMarshaler==System.IntPtr.Zero) ? null : new Antilatency.Alt.Environment.Pillars.Details.IDeserializedEnvironmentWrapper(resultMarshaler);
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
		}
		public class ILibraryRemap : Antilatency.Alt.Environment.Details.IEnvironmentConstructorRemap {
			public new struct VMT {
				public delegate Antilatency.InterfaceContract.ExceptionCode serializeDelegate(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate pillars, System.IntPtr scheme, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result);
				public delegate Antilatency.InterfaceContract.ExceptionCode deserializeDelegate(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate environmentData, out System.IntPtr result);
				#pragma warning disable 0649
				public serializeDelegate serialize;
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
				[MonoPInvokeCallback(typeof(VMT.serializeDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode serialize(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate pillars, System.IntPtr scheme, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result) {
				try {
					var obj = GetContext(_this) as ILibrary;
					var schemeMarshaler = scheme == System.IntPtr.Zero ? null : new Antilatency.Alt.Environment.Pillars.Details.ISchemeWrapper(scheme);
					var resultMarshaler = obj.serialize(pillars.toArray<Antilatency.Alt.Environment.Pillars.PillarData>(), schemeMarshaler);
					result.assign(resultMarshaler);
				}
				catch (System.Exception ex) {
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
					result = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.Alt.Environment.Pillars.IDeserializedEnvironment>(resultMarshaler);
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
				vmt.serialize = serialize;
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


