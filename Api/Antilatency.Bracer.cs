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
namespace Antilatency.Bracer {
	[System.Serializable]
	[System.Runtime.InteropServices.StructLayout(LayoutKind.Sequential)]
	public partial struct Vibration {
		public float intensity;
		public float duration;
	}
}

namespace Antilatency.Bracer {
	[Guid("36f3603d-32d8-4f36-9ebd-a06a3f188466")]
	[Antilatency.InterfaceContract.InterfaceId("36f3603d-32d8-4f36-9ebd-a06a3f188466")]
	public interface ICotask : Antilatency.DeviceNetwork.ICotaskBatteryPowered {
		uint getTouchChannelsCount();
		uint getTouchNativeValue(uint channel);
		float getTouch(uint channel);
		void executeVibrationSequence(Antilatency.Bracer.Vibration[] sequence);
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_Bracer_ICotask_InterfaceID = new System.Guid("36f3603d-32d8-4f36-9ebd-a06a3f188466");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.Bracer.ICotask result) {
		var guid = Antilatency_Bracer_ICotask_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.Bracer.Details.ICotaskWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.Bracer.ICotask result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_Bracer_ICotask_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.Bracer.Details.ICotaskWrapper(ptr);
		}
	}
}
namespace Antilatency.Bracer {
	namespace Details {
		public class ICotaskWrapper : Antilatency.DeviceNetwork.Details.ICotaskBatteryPoweredWrapper, ICotask {
			private ICotaskRemap.VMT _VMT = new ICotaskRemap.VMT();
			protected new int GetTotalNativeMethodsCount() {
			    return base.GetTotalNativeMethodsCount() + typeof(ICotaskRemap.VMT).GetFields().Length;
			}
			public ICotaskWrapper(System.IntPtr obj) : base(obj) {
			    _VMT = LoadVMT<ICotaskRemap.VMT>(base.GetTotalNativeMethodsCount());
			}
			public uint getTouchChannelsCount() {
				uint result;
				uint resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.getTouchChannelsCount(_object, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public uint getTouchNativeValue(uint channel) {
				uint result;
				uint resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.getTouchNativeValue(_object, channel, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public float getTouch(uint channel) {
				float result;
				float resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.getTouch(_object, channel, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public void executeVibrationSequence(Antilatency.Bracer.Vibration[] sequence) {
				var sequenceMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(sequence);
				var interfaceContractExceptionCode = (_VMT.executeVibrationSequence(_object, sequenceMarshaler));
				sequenceMarshaler.Dispose();
				HandleExceptionCode(interfaceContractExceptionCode);
			}
		}
		public class ICotaskRemap : Antilatency.DeviceNetwork.Details.ICotaskBatteryPoweredRemap {
			public new struct VMT {
				public delegate Antilatency.InterfaceContract.ExceptionCode getTouchChannelsCountDelegate(System.IntPtr _this, out uint result);
				public delegate Antilatency.InterfaceContract.ExceptionCode getTouchNativeValueDelegate(System.IntPtr _this, uint channel, out uint result);
				public delegate Antilatency.InterfaceContract.ExceptionCode getTouchDelegate(System.IntPtr _this, uint channel, out float result);
				public delegate Antilatency.InterfaceContract.ExceptionCode executeVibrationSequenceDelegate(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate sequence);
				#pragma warning disable 0649
				public getTouchChannelsCountDelegate getTouchChannelsCount;
				public getTouchNativeValueDelegate getTouchNativeValue;
				public getTouchDelegate getTouch;
				public executeVibrationSequenceDelegate executeVibrationSequence;
				#pragma warning restore 0649
			}
			public new static readonly NativeInterfaceVmt NativeVmt;
			static ICotaskRemap() {
				var vmtBlocks = new System.Collections.Generic.List<object>();
				AppendVmt(vmtBlocks);
				NativeVmt = new NativeInterfaceVmt(vmtBlocks);
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getTouchChannelsCountDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getTouchChannelsCount(System.IntPtr _this, out uint result) {
				try {
					var obj = GetContext(_this) as ICotask;
					var resultMarshaler = obj.getTouchChannelsCount();
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(uint);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getTouchNativeValueDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getTouchNativeValue(System.IntPtr _this, uint channel, out uint result) {
				try {
					var obj = GetContext(_this) as ICotask;
					var resultMarshaler = obj.getTouchNativeValue(channel);
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(uint);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getTouchDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getTouch(System.IntPtr _this, uint channel, out float result) {
				try {
					var obj = GetContext(_this) as ICotask;
					var resultMarshaler = obj.getTouch(channel);
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(float);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.executeVibrationSequenceDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode executeVibrationSequence(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate sequence) {
				try {
					var obj = GetContext(_this) as ICotask;
					obj.executeVibrationSequence(sequence.toArray<Antilatency.Bracer.Vibration>());
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			protected static new void AppendVmt(System.Collections.Generic.List<object> buffer) {
				Antilatency.DeviceNetwork.Details.ICotaskBatteryPoweredRemap.AppendVmt(buffer);
				var vmt = new VMT();
				vmt.getTouchChannelsCount = getTouchChannelsCount;
				vmt.getTouchNativeValue = getTouchNativeValue;
				vmt.getTouch = getTouch;
				vmt.executeVibrationSequence = executeVibrationSequence;
				buffer.Add(vmt);
			}
			public ICotaskRemap() { }
			public ICotaskRemap(System.IntPtr context, ushort lifetimeId) {
				AllocateNativeInterface(NativeVmt.Handle, context, lifetimeId);
			}
		}
	}
}

namespace Antilatency.Bracer {
	[Guid("28ab49e0-a878-4664-b26e-6543f1e11f92")]
	[Antilatency.InterfaceContract.InterfaceId("28ab49e0-a878-4664-b26e-6543f1e11f92")]
	public interface ICotaskConstructor : Antilatency.DeviceNetwork.ICotaskConstructor {
		Antilatency.Bracer.ICotask startTask(Antilatency.DeviceNetwork.INetwork network, Antilatency.DeviceNetwork.NodeHandle node);
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_Bracer_ICotaskConstructor_InterfaceID = new System.Guid("28ab49e0-a878-4664-b26e-6543f1e11f92");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.Bracer.ICotaskConstructor result) {
		var guid = Antilatency_Bracer_ICotaskConstructor_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.Bracer.Details.ICotaskConstructorWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.Bracer.ICotaskConstructor result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_Bracer_ICotaskConstructor_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.Bracer.Details.ICotaskConstructorWrapper(ptr);
		}
	}
}
namespace Antilatency.Bracer {
	namespace Details {
		public class ICotaskConstructorWrapper : Antilatency.DeviceNetwork.Details.ICotaskConstructorWrapper, ICotaskConstructor {
			private ICotaskConstructorRemap.VMT _VMT = new ICotaskConstructorRemap.VMT();
			protected new int GetTotalNativeMethodsCount() {
			    return base.GetTotalNativeMethodsCount() + typeof(ICotaskConstructorRemap.VMT).GetFields().Length;
			}
			public ICotaskConstructorWrapper(System.IntPtr obj) : base(obj) {
			    _VMT = LoadVMT<ICotaskConstructorRemap.VMT>(base.GetTotalNativeMethodsCount());
			}
			public Antilatency.Bracer.ICotask startTask(Antilatency.DeviceNetwork.INetwork network, Antilatency.DeviceNetwork.NodeHandle node) {
				Antilatency.Bracer.ICotask result;
				System.IntPtr resultMarshaler;
				var networkMarshaler = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.DeviceNetwork.INetwork>(network);
				var interfaceContractExceptionCode = (_VMT.startTask(_object, networkMarshaler, node, out resultMarshaler));
				result = (resultMarshaler==System.IntPtr.Zero) ? null : new Antilatency.Bracer.Details.ICotaskWrapper(resultMarshaler);
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
					result = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.Bracer.ICotask>(resultMarshaler);
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

namespace Antilatency.Bracer {
	[Guid("8c3ad766-5af7-4c13-baa1-e98cbdfa671e")]
	[Antilatency.InterfaceContract.InterfaceId("8c3ad766-5af7-4c13-baa1-e98cbdfa671e")]
	public interface ILibrary : Antilatency.InterfaceContract.IInterface {
		string getVersion();
		Antilatency.Bracer.ICotaskConstructor getCotaskConstructor();
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_Bracer_ILibrary_InterfaceID = new System.Guid("8c3ad766-5af7-4c13-baa1-e98cbdfa671e");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.Bracer.ILibrary result) {
		var guid = Antilatency_Bracer_ILibrary_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.Bracer.Details.ILibraryWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.Bracer.ILibrary result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_Bracer_ILibrary_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.Bracer.Details.ILibraryWrapper(ptr);
		}
	}
}
namespace Antilatency.Bracer {
	public static class Library{
	    #if ANTILATENCY_INTERFACECONTRACT_CUSTOMLIBPATHS
	    [DllImport(Antilatency.InterfaceContract.LibraryPaths.AntilatencyBracer)]
	    #else
	    [DllImport("AntilatencyBracer")]
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
			public Antilatency.Bracer.ICotaskConstructor getCotaskConstructor() {
				Antilatency.Bracer.ICotaskConstructor result;
				System.IntPtr resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.getCotaskConstructor(_object, out resultMarshaler));
				result = (resultMarshaler==System.IntPtr.Zero) ? null : new Antilatency.Bracer.Details.ICotaskConstructorWrapper(resultMarshaler);
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
					result = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.Bracer.ICotaskConstructor>(resultMarshaler);
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

namespace Antilatency.Bracer {
	public static partial class Constants {
		public const string TouchChannelsCountPropertyName = "sys/TouchChannelsCount";
		public const string TouchWindowBaseName = "touch/Window";
	}
}


