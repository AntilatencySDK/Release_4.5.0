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
namespace Antilatency.StorageClient {
	[Guid("792d9d14-a2d2-42ad-aeec-7f8a6ba62bd0")]
	[Antilatency.InterfaceContract.InterfaceId("792d9d14-a2d2-42ad-aeec-7f8a6ba62bd0")]
	public interface IStorage : Antilatency.InterfaceContract.IInterface {
		string read(string group, string key);
		void write(string group, string key, string data);
		void remove(string group, string key);
		string next(string group, string key);
		Antilatency.InterfaceContract.Bool exists();
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_StorageClient_IStorage_InterfaceID = new System.Guid("792d9d14-a2d2-42ad-aeec-7f8a6ba62bd0");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.StorageClient.IStorage result) {
		var guid = Antilatency_StorageClient_IStorage_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.StorageClient.Details.IStorageWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.StorageClient.IStorage result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_StorageClient_IStorage_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.StorageClient.Details.IStorageWrapper(ptr);
		}
	}
}
namespace Antilatency.StorageClient {
	namespace Details {
		public class IStorageWrapper : Antilatency.InterfaceContract.Details.IInterfaceWrapper, IStorage {
			private IStorageRemap.VMT _VMT = new IStorageRemap.VMT();
			protected new int GetTotalNativeMethodsCount() {
			    return base.GetTotalNativeMethodsCount() + typeof(IStorageRemap.VMT).GetFields().Length;
			}
			public IStorageWrapper(System.IntPtr obj) : base(obj) {
			    _VMT = LoadVMT<IStorageRemap.VMT>(base.GetTotalNativeMethodsCount());
			}
			public string read(string group, string key) {
				string result;
				var resultMarshaler = Antilatency.InterfaceContract.Details.ArrayOutMarshaler.create();
				var groupMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(group);
				var keyMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(key);
				var interfaceContractExceptionCode = (_VMT.read(_object, groupMarshaler, keyMarshaler, resultMarshaler));
				groupMarshaler.Dispose();
				keyMarshaler.Dispose();
				result = resultMarshaler.value;
				resultMarshaler.Dispose();
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public void write(string group, string key, string data) {
				var groupMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(group);
				var keyMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(key);
				var dataMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(data);
				var interfaceContractExceptionCode = (_VMT.write(_object, groupMarshaler, keyMarshaler, dataMarshaler));
				groupMarshaler.Dispose();
				keyMarshaler.Dispose();
				dataMarshaler.Dispose();
				HandleExceptionCode(interfaceContractExceptionCode);
			}
			public void remove(string group, string key) {
				var groupMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(group);
				var keyMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(key);
				var interfaceContractExceptionCode = (_VMT.remove(_object, groupMarshaler, keyMarshaler));
				groupMarshaler.Dispose();
				keyMarshaler.Dispose();
				HandleExceptionCode(interfaceContractExceptionCode);
			}
			public string next(string group, string key) {
				string result;
				var resultMarshaler = Antilatency.InterfaceContract.Details.ArrayOutMarshaler.create();
				var groupMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(group);
				var keyMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(key);
				var interfaceContractExceptionCode = (_VMT.next(_object, groupMarshaler, keyMarshaler, resultMarshaler));
				groupMarshaler.Dispose();
				keyMarshaler.Dispose();
				result = resultMarshaler.value;
				resultMarshaler.Dispose();
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public Antilatency.InterfaceContract.Bool exists() {
				Antilatency.InterfaceContract.Bool result;
				Antilatency.InterfaceContract.Bool resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.exists(_object, out resultMarshaler));
				result = resultMarshaler;
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
		}
		public class IStorageRemap : Antilatency.InterfaceContract.Details.IInterfaceRemap {
			public new struct VMT {
				public delegate Antilatency.InterfaceContract.ExceptionCode readDelegate(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate group, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate key, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result);
				public delegate Antilatency.InterfaceContract.ExceptionCode writeDelegate(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate group, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate key, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate data);
				public delegate Antilatency.InterfaceContract.ExceptionCode removeDelegate(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate group, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate key);
				public delegate Antilatency.InterfaceContract.ExceptionCode nextDelegate(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate group, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate key, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result);
				public delegate Antilatency.InterfaceContract.ExceptionCode existsDelegate(System.IntPtr _this, out Antilatency.InterfaceContract.Bool result);
				#pragma warning disable 0649
				public readDelegate read;
				public writeDelegate write;
				public removeDelegate remove;
				public nextDelegate next;
				public existsDelegate exists;
				#pragma warning restore 0649
			}
			public new static readonly NativeInterfaceVmt NativeVmt;
			static IStorageRemap() {
				var vmtBlocks = new System.Collections.Generic.List<object>();
				AppendVmt(vmtBlocks);
				NativeVmt = new NativeInterfaceVmt(vmtBlocks);
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.readDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode read(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate group, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate key, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result) {
				try {
					var obj = GetContext(_this) as IStorage;
					var resultMarshaler = obj.read(group, key);
					result.assign(resultMarshaler);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.writeDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode write(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate group, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate key, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate data) {
				try {
					var obj = GetContext(_this) as IStorage;
					obj.write(group, key, data);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.removeDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode remove(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate group, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate key) {
				try {
					var obj = GetContext(_this) as IStorage;
					obj.remove(group, key);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.nextDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode next(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate group, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate key, Antilatency.InterfaceContract.Details.ArrayOutMarshaler.Intermediate result) {
				try {
					var obj = GetContext(_this) as IStorage;
					var resultMarshaler = obj.next(group, key);
					result.assign(resultMarshaler);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.existsDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode exists(System.IntPtr _this, out Antilatency.InterfaceContract.Bool result) {
				try {
					var obj = GetContext(_this) as IStorage;
					var resultMarshaler = obj.exists();
					result = resultMarshaler;
				}
				catch (System.Exception ex) {
					result = default(Antilatency.InterfaceContract.Bool);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			protected static new void AppendVmt(System.Collections.Generic.List<object> buffer) {
				Antilatency.InterfaceContract.Details.IInterfaceRemap.AppendVmt(buffer);
				var vmt = new VMT();
				vmt.read = read;
				vmt.write = write;
				vmt.remove = remove;
				vmt.next = next;
				vmt.exists = exists;
				buffer.Add(vmt);
			}
			public IStorageRemap() { }
			public IStorageRemap(System.IntPtr context, ushort lifetimeId) {
				AllocateNativeInterface(NativeVmt.Handle, context, lifetimeId);
			}
		}
	}
}

namespace Antilatency.StorageClient {
	[Guid("85abab02-be0f-4836-9c1c-3c730bbd0251")]
	[Antilatency.InterfaceContract.InterfaceId("85abab02-be0f-4836-9c1c-3c730bbd0251")]
	public interface ILibrary : Antilatency.InterfaceContract.IInterface {
		Antilatency.StorageClient.IStorage getRemoteStorage(string ipAddress, uint port);
		Antilatency.StorageClient.IStorage getLocalStorage();
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid Antilatency_StorageClient_ILibrary_InterfaceID = new System.Guid("85abab02-be0f-4836-9c1c-3c730bbd0251");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out Antilatency.StorageClient.ILibrary result) {
		var guid = Antilatency_StorageClient_ILibrary_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.StorageClient.Details.ILibraryWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref Antilatency.StorageClient.ILibrary result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = Antilatency_StorageClient_ILibrary_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new Antilatency.StorageClient.Details.ILibraryWrapper(ptr);
		}
	}
}
namespace Antilatency.StorageClient {
	public static class Library{
	    #if ANTILATENCY_INTERFACECONTRACT_CUSTOMLIBPATHS
	    [DllImport(Antilatency.InterfaceContract.LibraryPaths.AntilatencyStorageClient)]
	    #else
	    [DllImport("AntilatencyStorageClient")]
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
			public Antilatency.StorageClient.IStorage getRemoteStorage(string ipAddress, uint port) {
				Antilatency.StorageClient.IStorage result;
				System.IntPtr resultMarshaler;
				var ipAddressMarshaler = Antilatency.InterfaceContract.Details.ArrayInMarshaler.create(ipAddress);
				var interfaceContractExceptionCode = (_VMT.getRemoteStorage(_object, ipAddressMarshaler, port, out resultMarshaler));
				ipAddressMarshaler.Dispose();
				result = (resultMarshaler==System.IntPtr.Zero) ? null : new Antilatency.StorageClient.Details.IStorageWrapper(resultMarshaler);
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
			public Antilatency.StorageClient.IStorage getLocalStorage() {
				Antilatency.StorageClient.IStorage result;
				System.IntPtr resultMarshaler;
				var interfaceContractExceptionCode = (_VMT.getLocalStorage(_object, out resultMarshaler));
				result = (resultMarshaler==System.IntPtr.Zero) ? null : new Antilatency.StorageClient.Details.IStorageWrapper(resultMarshaler);
				HandleExceptionCode(interfaceContractExceptionCode);
				return result;
			}
		}
		public class ILibraryRemap : Antilatency.InterfaceContract.Details.IInterfaceRemap {
			public new struct VMT {
				public delegate Antilatency.InterfaceContract.ExceptionCode getRemoteStorageDelegate(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate ipAddress, uint port, out System.IntPtr result);
				public delegate Antilatency.InterfaceContract.ExceptionCode getLocalStorageDelegate(System.IntPtr _this, out System.IntPtr result);
				#pragma warning disable 0649
				public getRemoteStorageDelegate getRemoteStorage;
				public getLocalStorageDelegate getLocalStorage;
				#pragma warning restore 0649
			}
			public new static readonly NativeInterfaceVmt NativeVmt;
			static ILibraryRemap() {
				var vmtBlocks = new System.Collections.Generic.List<object>();
				AppendVmt(vmtBlocks);
				NativeVmt = new NativeInterfaceVmt(vmtBlocks);
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getRemoteStorageDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getRemoteStorage(System.IntPtr _this, Antilatency.InterfaceContract.Details.ArrayInMarshaler.Intermediate ipAddress, uint port, out System.IntPtr result) {
				try {
					var obj = GetContext(_this) as ILibrary;
					var resultMarshaler = obj.getRemoteStorage(ipAddress, port);
					result = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.StorageClient.IStorage>(resultMarshaler);
				}
				catch (System.Exception ex) {
					result = default(System.IntPtr);
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.getLocalStorageDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode getLocalStorage(System.IntPtr _this, out System.IntPtr result) {
				try {
					var obj = GetContext(_this) as ILibrary;
					var resultMarshaler = obj.getLocalStorage();
					result = Antilatency.InterfaceContract.Details.InterfaceMarshaler.ManagedToNative<Antilatency.StorageClient.IStorage>(resultMarshaler);
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
				vmt.getRemoteStorage = getRemoteStorage;
				vmt.getLocalStorage = getLocalStorage;
				buffer.Add(vmt);
			}
			public ILibraryRemap() { }
			public ILibraryRemap(System.IntPtr context, ushort lifetimeId) {
				AllocateNativeInterface(NativeVmt.Handle, context, lifetimeId);
			}
		}
	}
}


