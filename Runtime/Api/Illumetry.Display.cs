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
namespace Illumetry.Display {
	[Guid("89f325cc-cc61-42fa-8086-d41ec3af44c0")]
	[Antilatency.InterfaceContract.InterfaceId("89f325cc-cc61-42fa-8086-d41ec3af44c0")]
	public interface ICotask : Antilatency.DeviceNetwork.ICotask {
		void setFrameScheduleReceiver(Antilatency.PulseWave.IPulseWaveReceiver pulseWaveReceiver);
		Antilatency.PulseWave.Description getFrameSchedule();
		Antilatency.DeviceNetwork.Tasks.Illumetry.Display.PowerState getPowerState();
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Illumetry_Display_ICotask_InterfaceID = new System.Guid("89f325cc-cc61-42fa-8086-d41ec3af44c0");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Illumetry.Display.ICotask result) {
		var guid = Illumetry_Display_ICotask_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Illumetry.Display.Details.ICotaskWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Illumetry.Display.ICotask result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Illumetry_Display_ICotask_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Illumetry.Display.Details.ICotaskWrapper(ptr);
		}
	}
}
namespace Illumetry.Display {
	namespace Details {
		public class ICotaskWrapper : Antilatency.DeviceNetwork.Details.ICotaskWrapper, ICotask {
			private ICotaskRemap.VMT _VMT = new ICotaskRemap.VMT();
			protected new int GetTotalNativeMethodsCount() {
			    return base.GetTotalNativeMethodsCount() + typeof(ICotaskRemap.VMT).GetFields().Length;
			}
			public ICotaskWrapper(System.IntPtr obj) : base(obj) {
			    _VMT = LoadVMT<ICotaskRemap.VMT>(base.GetTotalNativeMethodsCount());
			}
			public void setFrameScheduleReceiver(Antilatency.PulseWave.IPulseWaveReceiver pulseWaveReceiver) {
				var pulseWaveReceiverMarshaler = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.PulseWave.IPulseWaveReceiver>(pulseWaveReceiver);
				var interfaceContractExceptionCode = (_VMT.setFrameScheduleReceiver(_object, pulseWaveReceiverMarshaler));
				HandleExceptionCode(interfaceContractExceptionCode);
			}
			public Antilatency.PulseWave.Description getFrameSchedule() {
				Antilatency.PulseWave.Description result;
				Antilatency.PulseWave.Description resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.getFrameSchedule(_object, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public Antilatency.DeviceNetwork.Tasks.Illumetry.Display.PowerState getPowerState() {
				Antilatency.DeviceNetwork.Tasks.Illumetry.Display.PowerState result;
				Antilatency.DeviceNetwork.Tasks.Illumetry.Display.PowerState resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.getPowerState(_object, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
		}
		public class ICotaskRemap : Antilatency.DeviceNetwork.Details.ICotaskRemap {
			public new struct VMT {
				public delegate Antilatency.InterfaceContract.ExceptionCode setFrameScheduleReceiverDelegate(System.IntPtr _this, System.IntPtr pulseWaveReceiver);
				public delegate Antilatency.InterfaceContract.ExceptionCode getFrameScheduleDelegate(System.IntPtr _this, out Antilatency.PulseWave.Description result);
				public delegate Antilatency.InterfaceContract.ExceptionCode getPowerStateDelegate(System.IntPtr _this, out Antilatency.DeviceNetwork.Tasks.Illumetry.Display.PowerState result);
				#pragma warning disable 0649
				public setFrameScheduleReceiverDelegate setFrameScheduleReceiver;
				public getFrameScheduleDelegate getFrameSchedule;
				public getPowerStateDelegate getPowerState;
				#pragma warning restore 0649
			}
			public new static readonly NativeInterfaceVmt NativeVmt;
			static ICotaskRemap() {
				var vmtBlocks = new System.Collections.Generic.List<object>();
				AppendVmt(vmtBlocks);
				NativeVmt = new NativeInterfaceVmt(vmtBlocks);
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.setFrameScheduleReceiverDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode setFrameScheduleReceiver(System.IntPtr _this, System.IntPtr pulseWaveReceiver) {
				try {
					var obj = GetContext(_this) as ICotask;
					var pulseWaveReceiverMarshaler = pulseWaveReceiver == System.IntPtr.Zero ? null : new Antilatency.PulseWave.Details.IPulseWaveReceiverWrapper(pulseWaveReceiver);
					obj.setFrameScheduleReceiver(pulseWaveReceiverMarshaler);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getFrameScheduleDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getFrameSchedule(System.IntPtr _this, out Antilatency.PulseWave.Description result) {
				try {
					var obj = GetContext(_this) as ICotask;
					var resultMarshaler = obj.getFrameSchedule();
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(Antilatency.PulseWave.Description);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getPowerStateDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getPowerState(System.IntPtr _this, out Antilatency.DeviceNetwork.Tasks.Illumetry.Display.PowerState result) {
				try {
					var obj = GetContext(_this) as ICotask;
					var resultMarshaler = obj.getPowerState();
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(Antilatency.DeviceNetwork.Tasks.Illumetry.Display.PowerState);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			protected static new void AppendVmt(System.Collections.Generic.List<object> buffer) {
				Antilatency.DeviceNetwork.Details.ICotaskRemap.AppendVmt(buffer);
				var vmt = new VMT();
				vmt.setFrameScheduleReceiver = setFrameScheduleReceiver;
				vmt.getFrameSchedule = getFrameSchedule;
				vmt.getPowerState = getPowerState;
				buffer.Add(vmt);
			}
			public ICotaskRemap() { }
			public ICotaskRemap(System.IntPtr context, ushort lifetimeId) {
				AllocateNativeInterface(NativeVmt.Handle, context, lifetimeId);
			}
		}
	}
}

namespace Illumetry.Display {
	[Guid("47bf48da-1b39-434d-8583-89d37b829d7a")]
	[Antilatency.InterfaceContract.InterfaceId("47bf48da-1b39-434d-8583-89d37b829d7a")]
	public interface ICotaskConstructor : Antilatency.DeviceNetwork.ICotaskConstructor {
		Illumetry.Display.ICotask startTask(Antilatency.DeviceNetwork.INetwork network, Antilatency.DeviceNetwork.NodeHandle node);
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Illumetry_Display_ICotaskConstructor_InterfaceID = new System.Guid("47bf48da-1b39-434d-8583-89d37b829d7a");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Illumetry.Display.ICotaskConstructor result) {
		var guid = Illumetry_Display_ICotaskConstructor_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Illumetry.Display.Details.ICotaskConstructorWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Illumetry.Display.ICotaskConstructor result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Illumetry_Display_ICotaskConstructor_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Illumetry.Display.Details.ICotaskConstructorWrapper(ptr);
		}
	}
}
namespace Illumetry.Display {
	namespace Details {
		public class ICotaskConstructorWrapper : Antilatency.DeviceNetwork.Details.ICotaskConstructorWrapper, ICotaskConstructor {
			private ICotaskConstructorRemap.VMT _VMT = new ICotaskConstructorRemap.VMT();
			protected new int GetTotalNativeMethodsCount() {
			    return base.GetTotalNativeMethodsCount() + typeof(ICotaskConstructorRemap.VMT).GetFields().Length;
			}
			public ICotaskConstructorWrapper(System.IntPtr obj) : base(obj) {
			    _VMT = LoadVMT<ICotaskConstructorRemap.VMT>(base.GetTotalNativeMethodsCount());
			}
			public Illumetry.Display.ICotask startTask(Antilatency.DeviceNetwork.INetwork network, Antilatency.DeviceNetwork.NodeHandle node) {
				Illumetry.Display.ICotask result;
				System.IntPtr resultMarshaler;
				var networkMarshaler = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.DeviceNetwork.INetwork>(network);
				var interfaceContractExceptionCode = (_VMT.startTask(_object, networkMarshaler, node, out resultMarshaler));
				result = (resultMarshaler==System.IntPtr.Zero) ? null : new Illumetry.Display.Details.ICotaskWrapper(resultMarshaler);
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
					result = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Illumetry.Display.ICotask>(resultMarshaler);
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

namespace Illumetry.Display {
	[Guid("bb93c48c-2d96-42c4-a5ff-144395199f05")]
	[Antilatency.InterfaceContract.InterfaceId("bb93c48c-2d96-42c4-a5ff-144395199f05")]
	public interface ILibrary : Antilatency.InterfaceContract.IInterface {
		string getVersion();
		Illumetry.Display.ICotaskConstructor getCotaskConstructor();
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Illumetry_Display_ILibrary_InterfaceID = new System.Guid("bb93c48c-2d96-42c4-a5ff-144395199f05");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Illumetry.Display.ILibrary result) {
		var guid = Illumetry_Display_ILibrary_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Illumetry.Display.Details.ILibraryWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Illumetry.Display.ILibrary result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Illumetry_Display_ILibrary_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Illumetry.Display.Details.ILibraryWrapper(ptr);
		}
	}
}
namespace Illumetry.Display {
	public static class Library{
	    #if ANTILATENCY_INTERFACECONTRACT_CUSTOMLIBPATHS
	    [DllImport(Antilatency.InterfaceContract.LibraryPaths.IllumetryDisplay)]
	    #else
	    [DllImport("IllumetryDisplay")]
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
			public Illumetry.Display.ICotaskConstructor getCotaskConstructor() {
				Illumetry.Display.ICotaskConstructor result;
				System.IntPtr resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.getCotaskConstructor(_object, out resultMarshaler));
				result = (resultMarshaler==System.IntPtr.Zero) ? null : new Illumetry.Display.Details.ICotaskConstructorWrapper(resultMarshaler);
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
					result = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Illumetry.Display.ICotaskConstructor>(resultMarshaler);
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

namespace Illumetry.Display {
	public static partial class Constants {
		public const string ResolutionPropertyName = "sys/Resolution";
		public const string BlankPropertyName = "sys/Blank";
		public const string FpsPropertyName = "sys/Fps";
		public const string StrobeOffsetPropertyName = "sys/StrobeOffset";
		public const string StrobeDurationPropertyName = "sys/StrobeDuration";
	}
}


