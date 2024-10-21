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
namespace Antilatency.HardwareExtensionInterface {
	[Guid("39e6527d-82db-4615-af8f-0fad4c79f15e")]
	[Antilatency.InterfaceContract.InterfaceId("39e6527d-82db-4615-af8f-0fad4c79f15e")]
	public interface IInputPin : Antilatency.InterfaceContract.IInterface {
		Antilatency.HardwareExtensionInterface.Interop.PinState getState();
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_HardwareExtensionInterface_IInputPin_InterfaceID = new System.Guid("39e6527d-82db-4615-af8f-0fad4c79f15e");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.HardwareExtensionInterface.IInputPin result) {
		var guid = Antilatency_HardwareExtensionInterface_IInputPin_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.HardwareExtensionInterface.Details.IInputPinWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.HardwareExtensionInterface.IInputPin result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_HardwareExtensionInterface_IInputPin_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.HardwareExtensionInterface.Details.IInputPinWrapper(ptr);
		}
	}
}
namespace Antilatency.HardwareExtensionInterface {
	namespace Details {
		public class IInputPinWrapper : Antilatency.InterfaceContract.Details.IInterfaceWrapper, IInputPin {
			private IInputPinRemap.VMT _VMT = new IInputPinRemap.VMT();
			protected new int GetTotalNativeMethodsCount() {
			    return base.GetTotalNativeMethodsCount() + typeof(IInputPinRemap.VMT).GetFields().Length;
			}
			public IInputPinWrapper(System.IntPtr obj) : base(obj) {
			    _VMT = LoadVMT<IInputPinRemap.VMT>(base.GetTotalNativeMethodsCount());
			}
			public Antilatency.HardwareExtensionInterface.Interop.PinState getState() {
				Antilatency.HardwareExtensionInterface.Interop.PinState result;
				Antilatency.HardwareExtensionInterface.Interop.PinState resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.getState(_object, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
		}
		public class IInputPinRemap : Antilatency.InterfaceContract.Details.IInterfaceRemap {
			public new struct VMT {
				public delegate Antilatency.InterfaceContract.ExceptionCode getStateDelegate(System.IntPtr _this, out Antilatency.HardwareExtensionInterface.Interop.PinState result);
				#pragma warning disable 0649
				public getStateDelegate getState;
				#pragma warning restore 0649
			}
			public new static readonly NativeInterfaceVmt NativeVmt;
			static IInputPinRemap() {
				var vmtBlocks = new System.Collections.Generic.List<object>();
				AppendVmt(vmtBlocks);
				NativeVmt = new NativeInterfaceVmt(vmtBlocks);
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getStateDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getState(System.IntPtr _this, out Antilatency.HardwareExtensionInterface.Interop.PinState result) {
				try {
					var obj = GetContext(_this) as IInputPin;
					var resultMarshaler = obj.getState();
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(Antilatency.HardwareExtensionInterface.Interop.PinState);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			protected static new void AppendVmt(System.Collections.Generic.List<object> buffer) {
				Antilatency.InterfaceContract.Details.IInterfaceRemap.AppendVmt(buffer);
				var vmt = new VMT();
				vmt.getState = getState;
				buffer.Add(vmt);
			}
			public IInputPinRemap() { }
			public IInputPinRemap(System.IntPtr context, ushort lifetimeId) {
				AllocateNativeInterface(NativeVmt.Handle, context, lifetimeId);
			}
		}
	}
}

namespace Antilatency.HardwareExtensionInterface {
	[Guid("20d12574-3ae9-4921-80d3-95217e61f4b2")]
	[Antilatency.InterfaceContract.InterfaceId("20d12574-3ae9-4921-80d3-95217e61f4b2")]
	public interface IOutputPin : Antilatency.InterfaceContract.IInterface {
		void setState(Antilatency.HardwareExtensionInterface.Interop.PinState state);
		Antilatency.HardwareExtensionInterface.Interop.PinState getState();
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_HardwareExtensionInterface_IOutputPin_InterfaceID = new System.Guid("20d12574-3ae9-4921-80d3-95217e61f4b2");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.HardwareExtensionInterface.IOutputPin result) {
		var guid = Antilatency_HardwareExtensionInterface_IOutputPin_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.HardwareExtensionInterface.Details.IOutputPinWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.HardwareExtensionInterface.IOutputPin result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_HardwareExtensionInterface_IOutputPin_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.HardwareExtensionInterface.Details.IOutputPinWrapper(ptr);
		}
	}
}
namespace Antilatency.HardwareExtensionInterface {
	namespace Details {
		public class IOutputPinWrapper : Antilatency.InterfaceContract.Details.IInterfaceWrapper, IOutputPin {
			private IOutputPinRemap.VMT _VMT = new IOutputPinRemap.VMT();
			protected new int GetTotalNativeMethodsCount() {
			    return base.GetTotalNativeMethodsCount() + typeof(IOutputPinRemap.VMT).GetFields().Length;
			}
			public IOutputPinWrapper(System.IntPtr obj) : base(obj) {
			    _VMT = LoadVMT<IOutputPinRemap.VMT>(base.GetTotalNativeMethodsCount());
			}
			public void setState(Antilatency.HardwareExtensionInterface.Interop.PinState state) {
				var interfaceContractExceptionCode = (_VMT.setState(_object, state));
				HandleExceptionCode(interfaceContractExceptionCode);
			}
			public Antilatency.HardwareExtensionInterface.Interop.PinState getState() {
				Antilatency.HardwareExtensionInterface.Interop.PinState result;
				Antilatency.HardwareExtensionInterface.Interop.PinState resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.getState(_object, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
		}
		public class IOutputPinRemap : Antilatency.InterfaceContract.Details.IInterfaceRemap {
			public new struct VMT {
				public delegate Antilatency.InterfaceContract.ExceptionCode setStateDelegate(System.IntPtr _this, Antilatency.HardwareExtensionInterface.Interop.PinState state);
				public delegate Antilatency.InterfaceContract.ExceptionCode getStateDelegate(System.IntPtr _this, out Antilatency.HardwareExtensionInterface.Interop.PinState result);
				#pragma warning disable 0649
				public setStateDelegate setState;
				public getStateDelegate getState;
				#pragma warning restore 0649
			}
			public new static readonly NativeInterfaceVmt NativeVmt;
			static IOutputPinRemap() {
				var vmtBlocks = new System.Collections.Generic.List<object>();
				AppendVmt(vmtBlocks);
				NativeVmt = new NativeInterfaceVmt(vmtBlocks);
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.setStateDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode setState(System.IntPtr _this, Antilatency.HardwareExtensionInterface.Interop.PinState state) {
				try {
					var obj = GetContext(_this) as IOutputPin;
					obj.setState(state);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getStateDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getState(System.IntPtr _this, out Antilatency.HardwareExtensionInterface.Interop.PinState result) {
				try {
					var obj = GetContext(_this) as IOutputPin;
					var resultMarshaler = obj.getState();
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(Antilatency.HardwareExtensionInterface.Interop.PinState);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			protected static new void AppendVmt(System.Collections.Generic.List<object> buffer) {
				Antilatency.InterfaceContract.Details.IInterfaceRemap.AppendVmt(buffer);
				var vmt = new VMT();
				vmt.setState = setState;
				vmt.getState = getState;
				buffer.Add(vmt);
			}
			public IOutputPinRemap() { }
			public IOutputPinRemap(System.IntPtr context, ushort lifetimeId) {
				AllocateNativeInterface(NativeVmt.Handle, context, lifetimeId);
			}
		}
	}
}

namespace Antilatency.HardwareExtensionInterface {
	[Guid("e927972f-10e5-43e2-9502-74bcfed32482")]
	[Antilatency.InterfaceContract.InterfaceId("e927972f-10e5-43e2-9502-74bcfed32482")]
	public interface IAnalogPin : Antilatency.InterfaceContract.IInterface {
		float getValue();
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_HardwareExtensionInterface_IAnalogPin_InterfaceID = new System.Guid("e927972f-10e5-43e2-9502-74bcfed32482");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.HardwareExtensionInterface.IAnalogPin result) {
		var guid = Antilatency_HardwareExtensionInterface_IAnalogPin_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.HardwareExtensionInterface.Details.IAnalogPinWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.HardwareExtensionInterface.IAnalogPin result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_HardwareExtensionInterface_IAnalogPin_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.HardwareExtensionInterface.Details.IAnalogPinWrapper(ptr);
		}
	}
}
namespace Antilatency.HardwareExtensionInterface {
	namespace Details {
		public class IAnalogPinWrapper : Antilatency.InterfaceContract.Details.IInterfaceWrapper, IAnalogPin {
			private IAnalogPinRemap.VMT _VMT = new IAnalogPinRemap.VMT();
			protected new int GetTotalNativeMethodsCount() {
			    return base.GetTotalNativeMethodsCount() + typeof(IAnalogPinRemap.VMT).GetFields().Length;
			}
			public IAnalogPinWrapper(System.IntPtr obj) : base(obj) {
			    _VMT = LoadVMT<IAnalogPinRemap.VMT>(base.GetTotalNativeMethodsCount());
			}
			public float getValue() {
				float result;
				float resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.getValue(_object, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
		}
		public class IAnalogPinRemap : Antilatency.InterfaceContract.Details.IInterfaceRemap {
			public new struct VMT {
				public delegate Antilatency.InterfaceContract.ExceptionCode getValueDelegate(System.IntPtr _this, out float result);
				#pragma warning disable 0649
				public getValueDelegate getValue;
				#pragma warning restore 0649
			}
			public new static readonly NativeInterfaceVmt NativeVmt;
			static IAnalogPinRemap() {
				var vmtBlocks = new System.Collections.Generic.List<object>();
				AppendVmt(vmtBlocks);
				NativeVmt = new NativeInterfaceVmt(vmtBlocks);
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getValueDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getValue(System.IntPtr _this, out float result) {
				try {
					var obj = GetContext(_this) as IAnalogPin;
					var resultMarshaler = obj.getValue();
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(float);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			protected static new void AppendVmt(System.Collections.Generic.List<object> buffer) {
				Antilatency.InterfaceContract.Details.IInterfaceRemap.AppendVmt(buffer);
				var vmt = new VMT();
				vmt.getValue = getValue;
				buffer.Add(vmt);
			}
			public IAnalogPinRemap() { }
			public IAnalogPinRemap(System.IntPtr context, ushort lifetimeId) {
				AllocateNativeInterface(NativeVmt.Handle, context, lifetimeId);
			}
		}
	}
}

namespace Antilatency.HardwareExtensionInterface {
	[Guid("8998b746-5d17-4a47-9c8b-01d5a959536c")]
	[Antilatency.InterfaceContract.InterfaceId("8998b746-5d17-4a47-9c8b-01d5a959536c")]
	public interface IPulseCounterPin : Antilatency.InterfaceContract.IInterface {
		ushort getValue();
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_HardwareExtensionInterface_IPulseCounterPin_InterfaceID = new System.Guid("8998b746-5d17-4a47-9c8b-01d5a959536c");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.HardwareExtensionInterface.IPulseCounterPin result) {
		var guid = Antilatency_HardwareExtensionInterface_IPulseCounterPin_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.HardwareExtensionInterface.Details.IPulseCounterPinWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.HardwareExtensionInterface.IPulseCounterPin result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_HardwareExtensionInterface_IPulseCounterPin_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.HardwareExtensionInterface.Details.IPulseCounterPinWrapper(ptr);
		}
	}
}
namespace Antilatency.HardwareExtensionInterface {
	namespace Details {
		public class IPulseCounterPinWrapper : Antilatency.InterfaceContract.Details.IInterfaceWrapper, IPulseCounterPin {
			private IPulseCounterPinRemap.VMT _VMT = new IPulseCounterPinRemap.VMT();
			protected new int GetTotalNativeMethodsCount() {
			    return base.GetTotalNativeMethodsCount() + typeof(IPulseCounterPinRemap.VMT).GetFields().Length;
			}
			public IPulseCounterPinWrapper(System.IntPtr obj) : base(obj) {
			    _VMT = LoadVMT<IPulseCounterPinRemap.VMT>(base.GetTotalNativeMethodsCount());
			}
			public ushort getValue() {
				ushort result;
				ushort resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.getValue(_object, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
		}
		public class IPulseCounterPinRemap : Antilatency.InterfaceContract.Details.IInterfaceRemap {
			public new struct VMT {
				public delegate Antilatency.InterfaceContract.ExceptionCode getValueDelegate(System.IntPtr _this, out ushort result);
				#pragma warning disable 0649
				public getValueDelegate getValue;
				#pragma warning restore 0649
			}
			public new static readonly NativeInterfaceVmt NativeVmt;
			static IPulseCounterPinRemap() {
				var vmtBlocks = new System.Collections.Generic.List<object>();
				AppendVmt(vmtBlocks);
				NativeVmt = new NativeInterfaceVmt(vmtBlocks);
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getValueDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getValue(System.IntPtr _this, out ushort result) {
				try {
					var obj = GetContext(_this) as IPulseCounterPin;
					var resultMarshaler = obj.getValue();
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(ushort);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			protected static new void AppendVmt(System.Collections.Generic.List<object> buffer) {
				Antilatency.InterfaceContract.Details.IInterfaceRemap.AppendVmt(buffer);
				var vmt = new VMT();
				vmt.getValue = getValue;
				buffer.Add(vmt);
			}
			public IPulseCounterPinRemap() { }
			public IPulseCounterPinRemap(System.IntPtr context, ushort lifetimeId) {
				AllocateNativeInterface(NativeVmt.Handle, context, lifetimeId);
			}
		}
	}
}

namespace Antilatency.HardwareExtensionInterface {
	[Guid("0793b2f5-2f6f-4a01-8b25-f2ff98360441")]
	[Antilatency.InterfaceContract.InterfaceId("0793b2f5-2f6f-4a01-8b25-f2ff98360441")]
	public interface IPwmPin : Antilatency.InterfaceContract.IInterface {
		void setDuty(float value);
		float getDuty();
		/// <summary>Get actual pwm frequency.</summary>
		uint getFrequency();
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_HardwareExtensionInterface_IPwmPin_InterfaceID = new System.Guid("0793b2f5-2f6f-4a01-8b25-f2ff98360441");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.HardwareExtensionInterface.IPwmPin result) {
		var guid = Antilatency_HardwareExtensionInterface_IPwmPin_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.HardwareExtensionInterface.Details.IPwmPinWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.HardwareExtensionInterface.IPwmPin result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_HardwareExtensionInterface_IPwmPin_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.HardwareExtensionInterface.Details.IPwmPinWrapper(ptr);
		}
	}
}
namespace Antilatency.HardwareExtensionInterface {
	namespace Details {
		public class IPwmPinWrapper : Antilatency.InterfaceContract.Details.IInterfaceWrapper, IPwmPin {
			private IPwmPinRemap.VMT _VMT = new IPwmPinRemap.VMT();
			protected new int GetTotalNativeMethodsCount() {
			    return base.GetTotalNativeMethodsCount() + typeof(IPwmPinRemap.VMT).GetFields().Length;
			}
			public IPwmPinWrapper(System.IntPtr obj) : base(obj) {
			    _VMT = LoadVMT<IPwmPinRemap.VMT>(base.GetTotalNativeMethodsCount());
			}
			public void setDuty(float value) {
				var interfaceContractExceptionCode = (_VMT.setDuty(_object, value));
				HandleExceptionCode(interfaceContractExceptionCode);
			}
			public float getDuty() {
				float result;
				float resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.getDuty(_object, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public uint getFrequency() {
				uint result;
				uint resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.getFrequency(_object, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
		}
		public class IPwmPinRemap : Antilatency.InterfaceContract.Details.IInterfaceRemap {
			public new struct VMT {
				public delegate Antilatency.InterfaceContract.ExceptionCode setDutyDelegate(System.IntPtr _this, float value);
				public delegate Antilatency.InterfaceContract.ExceptionCode getDutyDelegate(System.IntPtr _this, out float result);
				public delegate Antilatency.InterfaceContract.ExceptionCode getFrequencyDelegate(System.IntPtr _this, out uint result);
				#pragma warning disable 0649
				public setDutyDelegate setDuty;
				public getDutyDelegate getDuty;
				public getFrequencyDelegate getFrequency;
				#pragma warning restore 0649
			}
			public new static readonly NativeInterfaceVmt NativeVmt;
			static IPwmPinRemap() {
				var vmtBlocks = new System.Collections.Generic.List<object>();
				AppendVmt(vmtBlocks);
				NativeVmt = new NativeInterfaceVmt(vmtBlocks);
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.setDutyDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode setDuty(System.IntPtr _this, float value) {
				try {
					var obj = GetContext(_this) as IPwmPin;
					obj.setDuty(value);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getDutyDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getDuty(System.IntPtr _this, out float result) {
				try {
					var obj = GetContext(_this) as IPwmPin;
					var resultMarshaler = obj.getDuty();
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(float);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getFrequencyDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getFrequency(System.IntPtr _this, out uint result) {
				try {
					var obj = GetContext(_this) as IPwmPin;
					var resultMarshaler = obj.getFrequency();
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(uint);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			protected static new void AppendVmt(System.Collections.Generic.List<object> buffer) {
				Antilatency.InterfaceContract.Details.IInterfaceRemap.AppendVmt(buffer);
				var vmt = new VMT();
				vmt.setDuty = setDuty;
				vmt.getDuty = getDuty;
				vmt.getFrequency = getFrequency;
				buffer.Add(vmt);
			}
			public IPwmPinRemap() { }
			public IPwmPinRemap(System.IntPtr context, ushort lifetimeId) {
				AllocateNativeInterface(NativeVmt.Handle, context, lifetimeId);
			}
		}
	}
}

namespace Antilatency.HardwareExtensionInterface {
	[Guid("acd1daa9-9394-4d3a-95ce-177a23bd9b89")]
	[Antilatency.InterfaceContract.InterfaceId("acd1daa9-9394-4d3a-95ce-177a23bd9b89")]
	public interface ICotask : Antilatency.DeviceNetwork.ICotask {
		Antilatency.HardwareExtensionInterface.IInputPin createInputPin(Antilatency.HardwareExtensionInterface.Interop.Pins pin);
		Antilatency.HardwareExtensionInterface.IOutputPin createOutputPin(Antilatency.HardwareExtensionInterface.Interop.Pins pin, Antilatency.HardwareExtensionInterface.Interop.PinState initialState);
		Antilatency.HardwareExtensionInterface.IAnalogPin createAnalogPin(Antilatency.HardwareExtensionInterface.Interop.Pins pin, uint refreshIntervalMs);
		Antilatency.HardwareExtensionInterface.IPulseCounterPin createPulseCounterPin(Antilatency.HardwareExtensionInterface.Interop.Pins pin, uint refreshIntervalMs);
		Antilatency.HardwareExtensionInterface.IPwmPin createPwmPin(Antilatency.HardwareExtensionInterface.Interop.Pins pin, uint frequency, float initialDuty);
		void run();
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_HardwareExtensionInterface_ICotask_InterfaceID = new System.Guid("acd1daa9-9394-4d3a-95ce-177a23bd9b89");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.HardwareExtensionInterface.ICotask result) {
		var guid = Antilatency_HardwareExtensionInterface_ICotask_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.HardwareExtensionInterface.Details.ICotaskWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.HardwareExtensionInterface.ICotask result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_HardwareExtensionInterface_ICotask_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.HardwareExtensionInterface.Details.ICotaskWrapper(ptr);
		}
	}
}
namespace Antilatency.HardwareExtensionInterface {
	namespace Details {
		public class ICotaskWrapper : Antilatency.DeviceNetwork.Details.ICotaskWrapper, ICotask {
			private ICotaskRemap.VMT _VMT = new ICotaskRemap.VMT();
			protected new int GetTotalNativeMethodsCount() {
			    return base.GetTotalNativeMethodsCount() + typeof(ICotaskRemap.VMT).GetFields().Length;
			}
			public ICotaskWrapper(System.IntPtr obj) : base(obj) {
			    _VMT = LoadVMT<ICotaskRemap.VMT>(base.GetTotalNativeMethodsCount());
			}
			public Antilatency.HardwareExtensionInterface.IInputPin createInputPin(Antilatency.HardwareExtensionInterface.Interop.Pins pin) {
				Antilatency.HardwareExtensionInterface.IInputPin result;
				System.IntPtr resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.createInputPin(_object, pin, out resultMarshaler));
				result = (resultMarshaler==System.IntPtr.Zero) ? null : new Antilatency.HardwareExtensionInterface.Details.IInputPinWrapper(resultMarshaler);
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public Antilatency.HardwareExtensionInterface.IOutputPin createOutputPin(Antilatency.HardwareExtensionInterface.Interop.Pins pin, Antilatency.HardwareExtensionInterface.Interop.PinState initialState) {
				Antilatency.HardwareExtensionInterface.IOutputPin result;
				System.IntPtr resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.createOutputPin(_object, pin, initialState, out resultMarshaler));
				result = (resultMarshaler==System.IntPtr.Zero) ? null : new Antilatency.HardwareExtensionInterface.Details.IOutputPinWrapper(resultMarshaler);
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public Antilatency.HardwareExtensionInterface.IAnalogPin createAnalogPin(Antilatency.HardwareExtensionInterface.Interop.Pins pin, uint refreshIntervalMs) {
				Antilatency.HardwareExtensionInterface.IAnalogPin result;
				System.IntPtr resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.createAnalogPin(_object, pin, refreshIntervalMs, out resultMarshaler));
				result = (resultMarshaler==System.IntPtr.Zero) ? null : new Antilatency.HardwareExtensionInterface.Details.IAnalogPinWrapper(resultMarshaler);
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public Antilatency.HardwareExtensionInterface.IPulseCounterPin createPulseCounterPin(Antilatency.HardwareExtensionInterface.Interop.Pins pin, uint refreshIntervalMs) {
				Antilatency.HardwareExtensionInterface.IPulseCounterPin result;
				System.IntPtr resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.createPulseCounterPin(_object, pin, refreshIntervalMs, out resultMarshaler));
				result = (resultMarshaler==System.IntPtr.Zero) ? null : new Antilatency.HardwareExtensionInterface.Details.IPulseCounterPinWrapper(resultMarshaler);
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public Antilatency.HardwareExtensionInterface.IPwmPin createPwmPin(Antilatency.HardwareExtensionInterface.Interop.Pins pin, uint frequency, float initialDuty) {
				Antilatency.HardwareExtensionInterface.IPwmPin result;
				System.IntPtr resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.createPwmPin(_object, pin, frequency, initialDuty, out resultMarshaler));
				result = (resultMarshaler==System.IntPtr.Zero) ? null : new Antilatency.HardwareExtensionInterface.Details.IPwmPinWrapper(resultMarshaler);
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public void run() {
				var interfaceContractExceptionCode = (_VMT.run(_object));
				HandleExceptionCode(interfaceContractExceptionCode);
			}
		}
		public class ICotaskRemap : Antilatency.DeviceNetwork.Details.ICotaskRemap {
			public new struct VMT {
				public delegate Antilatency.InterfaceContract.ExceptionCode createInputPinDelegate(System.IntPtr _this, Antilatency.HardwareExtensionInterface.Interop.Pins pin, out System.IntPtr result);
				public delegate Antilatency.InterfaceContract.ExceptionCode createOutputPinDelegate(System.IntPtr _this, Antilatency.HardwareExtensionInterface.Interop.Pins pin, Antilatency.HardwareExtensionInterface.Interop.PinState initialState, out System.IntPtr result);
				public delegate Antilatency.InterfaceContract.ExceptionCode createAnalogPinDelegate(System.IntPtr _this, Antilatency.HardwareExtensionInterface.Interop.Pins pin, uint refreshIntervalMs, out System.IntPtr result);
				public delegate Antilatency.InterfaceContract.ExceptionCode createPulseCounterPinDelegate(System.IntPtr _this, Antilatency.HardwareExtensionInterface.Interop.Pins pin, uint refreshIntervalMs, out System.IntPtr result);
				public delegate Antilatency.InterfaceContract.ExceptionCode createPwmPinDelegate(System.IntPtr _this, Antilatency.HardwareExtensionInterface.Interop.Pins pin, uint frequency, float initialDuty, out System.IntPtr result);
				public delegate Antilatency.InterfaceContract.ExceptionCode runDelegate(System.IntPtr _this);
				#pragma warning disable 0649
				public createInputPinDelegate createInputPin;
				public createOutputPinDelegate createOutputPin;
				public createAnalogPinDelegate createAnalogPin;
				public createPulseCounterPinDelegate createPulseCounterPin;
				public createPwmPinDelegate createPwmPin;
				public runDelegate run;
				#pragma warning restore 0649
			}
			public new static readonly NativeInterfaceVmt NativeVmt;
			static ICotaskRemap() {
				var vmtBlocks = new System.Collections.Generic.List<object>();
				AppendVmt(vmtBlocks);
				NativeVmt = new NativeInterfaceVmt(vmtBlocks);
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.createInputPinDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode createInputPin(System.IntPtr _this, Antilatency.HardwareExtensionInterface.Interop.Pins pin, out System.IntPtr result) {
				try {
					var obj = GetContext(_this) as ICotask;
					var resultMarshaler = obj.createInputPin(pin);
					result = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.HardwareExtensionInterface.IInputPin>(resultMarshaler);
				}
				catch (System.Exception ex) {
					result = default(System.IntPtr);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.createOutputPinDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode createOutputPin(System.IntPtr _this, Antilatency.HardwareExtensionInterface.Interop.Pins pin, Antilatency.HardwareExtensionInterface.Interop.PinState initialState, out System.IntPtr result) {
				try {
					var obj = GetContext(_this) as ICotask;
					var resultMarshaler = obj.createOutputPin(pin, initialState);
					result = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.HardwareExtensionInterface.IOutputPin>(resultMarshaler);
				}
				catch (System.Exception ex) {
					result = default(System.IntPtr);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.createAnalogPinDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode createAnalogPin(System.IntPtr _this, Antilatency.HardwareExtensionInterface.Interop.Pins pin, uint refreshIntervalMs, out System.IntPtr result) {
				try {
					var obj = GetContext(_this) as ICotask;
					var resultMarshaler = obj.createAnalogPin(pin, refreshIntervalMs);
					result = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.HardwareExtensionInterface.IAnalogPin>(resultMarshaler);
				}
				catch (System.Exception ex) {
					result = default(System.IntPtr);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.createPulseCounterPinDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode createPulseCounterPin(System.IntPtr _this, Antilatency.HardwareExtensionInterface.Interop.Pins pin, uint refreshIntervalMs, out System.IntPtr result) {
				try {
					var obj = GetContext(_this) as ICotask;
					var resultMarshaler = obj.createPulseCounterPin(pin, refreshIntervalMs);
					result = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.HardwareExtensionInterface.IPulseCounterPin>(resultMarshaler);
				}
				catch (System.Exception ex) {
					result = default(System.IntPtr);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.createPwmPinDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode createPwmPin(System.IntPtr _this, Antilatency.HardwareExtensionInterface.Interop.Pins pin, uint frequency, float initialDuty, out System.IntPtr result) {
				try {
					var obj = GetContext(_this) as ICotask;
					var resultMarshaler = obj.createPwmPin(pin, frequency, initialDuty);
					result = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.HardwareExtensionInterface.IPwmPin>(resultMarshaler);
				}
				catch (System.Exception ex) {
					result = default(System.IntPtr);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.runDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode run(System.IntPtr _this) {
				try {
					var obj = GetContext(_this) as ICotask;
					obj.run();
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			protected static new void AppendVmt(System.Collections.Generic.List<object> buffer) {
				Antilatency.DeviceNetwork.Details.ICotaskRemap.AppendVmt(buffer);
				var vmt = new VMT();
				vmt.createInputPin = createInputPin;
				vmt.createOutputPin = createOutputPin;
				vmt.createAnalogPin = createAnalogPin;
				vmt.createPulseCounterPin = createPulseCounterPin;
				vmt.createPwmPin = createPwmPin;
				vmt.run = run;
				buffer.Add(vmt);
			}
			public ICotaskRemap() { }
			public ICotaskRemap(System.IntPtr context, ushort lifetimeId) {
				AllocateNativeInterface(NativeVmt.Handle, context, lifetimeId);
			}
		}
	}
}

namespace Antilatency.HardwareExtensionInterface {
	[Guid("53b72a7a-c61e-4946-8a06-564a7171d477")]
	[Antilatency.InterfaceContract.InterfaceId("53b72a7a-c61e-4946-8a06-564a7171d477")]
	public interface ICotaskConstructor : Antilatency.DeviceNetwork.ICotaskConstructor {
		Antilatency.HardwareExtensionInterface.ICotask startTask(Antilatency.DeviceNetwork.INetwork network, Antilatency.DeviceNetwork.NodeHandle node);
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_HardwareExtensionInterface_ICotaskConstructor_InterfaceID = new System.Guid("53b72a7a-c61e-4946-8a06-564a7171d477");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.HardwareExtensionInterface.ICotaskConstructor result) {
		var guid = Antilatency_HardwareExtensionInterface_ICotaskConstructor_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.HardwareExtensionInterface.Details.ICotaskConstructorWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.HardwareExtensionInterface.ICotaskConstructor result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_HardwareExtensionInterface_ICotaskConstructor_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.HardwareExtensionInterface.Details.ICotaskConstructorWrapper(ptr);
		}
	}
}
namespace Antilatency.HardwareExtensionInterface {
	namespace Details {
		public class ICotaskConstructorWrapper : Antilatency.DeviceNetwork.Details.ICotaskConstructorWrapper, ICotaskConstructor {
			private ICotaskConstructorRemap.VMT _VMT = new ICotaskConstructorRemap.VMT();
			protected new int GetTotalNativeMethodsCount() {
			    return base.GetTotalNativeMethodsCount() + typeof(ICotaskConstructorRemap.VMT).GetFields().Length;
			}
			public ICotaskConstructorWrapper(System.IntPtr obj) : base(obj) {
			    _VMT = LoadVMT<ICotaskConstructorRemap.VMT>(base.GetTotalNativeMethodsCount());
			}
			public Antilatency.HardwareExtensionInterface.ICotask startTask(Antilatency.DeviceNetwork.INetwork network, Antilatency.DeviceNetwork.NodeHandle node) {
				Antilatency.HardwareExtensionInterface.ICotask result;
				System.IntPtr resultMarshaler;
				var networkMarshaler = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.DeviceNetwork.INetwork>(network);
				var interfaceContractExceptionCode = (_VMT.startTask(_object, networkMarshaler, node, out resultMarshaler));
				result = (resultMarshaler==System.IntPtr.Zero) ? null : new Antilatency.HardwareExtensionInterface.Details.ICotaskWrapper(resultMarshaler);
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
					result = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.HardwareExtensionInterface.ICotask>(resultMarshaler);
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

namespace Antilatency.HardwareExtensionInterface {
	[Guid("ef1b555b-bbf4-4514-829b-b0cd15b6fc8d")]
	[Antilatency.InterfaceContract.InterfaceId("ef1b555b-bbf4-4514-829b-b0cd15b6fc8d")]
	public interface ILibrary : Antilatency.InterfaceContract.IInterface {
		string getVersion();
		Antilatency.HardwareExtensionInterface.ICotaskConstructor getCotaskConstructor();
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_HardwareExtensionInterface_ILibrary_InterfaceID = new System.Guid("ef1b555b-bbf4-4514-829b-b0cd15b6fc8d");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.HardwareExtensionInterface.ILibrary result) {
		var guid = Antilatency_HardwareExtensionInterface_ILibrary_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.HardwareExtensionInterface.Details.ILibraryWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.HardwareExtensionInterface.ILibrary result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_HardwareExtensionInterface_ILibrary_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.HardwareExtensionInterface.Details.ILibraryWrapper(ptr);
		}
	}
}
namespace Antilatency.HardwareExtensionInterface {
	public static class Library{
	    #if ANTILATENCY_INTERFACECONTRACT_CUSTOMLIBPATHS
	    [DllImport(Antilatency.InterfaceContract.LibraryPaths.AntilatencyHardwareExtensionInterface)]
	    #else
	    [DllImport("AntilatencyHardwareExtensionInterface")]
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
			public Antilatency.HardwareExtensionInterface.ICotaskConstructor getCotaskConstructor() {
				Antilatency.HardwareExtensionInterface.ICotaskConstructor result;
				System.IntPtr resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.getCotaskConstructor(_object, out resultMarshaler));
				result = (resultMarshaler==System.IntPtr.Zero) ? null : new Antilatency.HardwareExtensionInterface.Details.ICotaskConstructorWrapper(resultMarshaler);
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
					result = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.HardwareExtensionInterface.ICotaskConstructor>(resultMarshaler);
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

namespace Antilatency.HardwareExtensionInterface {
	public static partial class Constants {
		public const uint AnalogMinRefreshIntervalMs = 1;
		public const uint AnalogMaxRefreshIntervalMs = 65535;
		public const uint PulseCounterMinRefreshIntervalMs = 1;
		public const uint PulseCounterMaxRefreshIntervalMs = 125;
		public const uint PwmMinFrequency = 20;
		public const uint PwmMaxFrequency = 10000;
	}
}


