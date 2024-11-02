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
namespace Antilatency.Alt.Environment.Selector {
	[Guid("2ef251c9-e0d5-46ad-8ae0-967ded908f2a")]
	[Antilatency.InterfaceContract.InterfaceId("2ef251c9-e0d5-46ad-8ae0-967ded908f2a")]
	public interface ILibrary : Antilatency.InterfaceContract.IInterface {
		void registerEnvironmentProvider(string name, Antilatency.Alt.Environment.IEnvironmentConstructor provider);
		void unregisterEnvironmentProvider(string name);
		Antilatency.Alt.Environment.IEnvironment createEnvironment(string data);
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_Alt_Environment_Selector_ILibrary_InterfaceID = new System.Guid("2ef251c9-e0d5-46ad-8ae0-967ded908f2a");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.Alt.Environment.Selector.ILibrary result) {
		var guid = Antilatency_Alt_Environment_Selector_ILibrary_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.Alt.Environment.Selector.Details.ILibraryWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.Alt.Environment.Selector.ILibrary result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_Alt_Environment_Selector_ILibrary_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.Alt.Environment.Selector.Details.ILibraryWrapper(ptr);
		}
	}
}
namespace Antilatency.Alt.Environment.Selector {
	public static class Library{
	    #if ANTILATENCY_INTERFACECONTRACT_CUSTOMLIBPATHS
	    [DllImport(Antilatency.InterfaceContract.LibraryPaths.AntilatencyAltEnvironmentSelector)]
	    #else
	    [DllImport("AntilatencyAltEnvironmentSelector")]
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
			public void registerEnvironmentProvider(string name, Antilatency.Alt.Environment.IEnvironmentConstructor provider) {
				var nameMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(name);
				var providerMarshaler = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.Alt.Environment.IEnvironmentConstructor>(provider);
				var interfaceContractExceptionCode = (_VMT.registerEnvironmentProvider(_object, nameMarshaler, providerMarshaler));
				nameMarshaler.Dispose();
				HandleExceptionCode(interfaceContractExceptionCode);
			}
			public void unregisterEnvironmentProvider(string name) {
				var nameMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(name);
				var interfaceContractExceptionCode = (_VMT.unregisterEnvironmentProvider(_object, nameMarshaler));
				nameMarshaler.Dispose();
				HandleExceptionCode(interfaceContractExceptionCode);
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
		public class ILibraryRemap : Antilatency.InterfaceContract.Details.IInterfaceRemap {
			public new struct VMT {
				public delegate Antilatency.InterfaceContract.ExceptionCode registerEnvironmentProviderDelegate(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate name, System.IntPtr provider);
				public delegate Antilatency.InterfaceContract.ExceptionCode unregisterEnvironmentProviderDelegate(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate name);
				public delegate Antilatency.InterfaceContract.ExceptionCode createEnvironmentDelegate(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate data, out System.IntPtr result);
				#pragma warning disable 0649
				public registerEnvironmentProviderDelegate registerEnvironmentProvider;
				public unregisterEnvironmentProviderDelegate unregisterEnvironmentProvider;
				public createEnvironmentDelegate createEnvironment;
				#pragma warning restore 0649
			}
			public new static readonly NativeInterfaceVmt NativeVmt;
			static ILibraryRemap() {
				var vmtBlocks = new System.Collections.Generic.List<object>();
				AppendVmt(vmtBlocks);
				NativeVmt = new NativeInterfaceVmt(vmtBlocks);
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.registerEnvironmentProviderDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode registerEnvironmentProvider(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate name, System.IntPtr provider) {
				try {
					var obj = GetContext(_this) as ILibrary;
					var providerMarshaler = provider == System.IntPtr.Zero ? null : new Antilatency.Alt.Environment.Details.IEnvironmentConstructorWrapper(provider);
					obj.registerEnvironmentProvider(name, providerMarshaler);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.unregisterEnvironmentProviderDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode unregisterEnvironmentProvider(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate name) {
				try {
					var obj = GetContext(_this) as ILibrary;
					obj.unregisterEnvironmentProvider(name);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.createEnvironmentDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode createEnvironment(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate data, out System.IntPtr result) {
				try {
					var obj = GetContext(_this) as ILibrary;
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
				vmt.registerEnvironmentProvider = registerEnvironmentProvider;
				vmt.unregisterEnvironmentProvider = unregisterEnvironmentProvider;
				vmt.createEnvironment = createEnvironment;
				buffer.Add(vmt);
			}
			public ILibraryRemap() { }
			public ILibraryRemap(System.IntPtr context, ushort lifetimeId) {
				AllocateNativeInterface(NativeVmt.Handle, context, lifetimeId);
			}
		}
	}
}


