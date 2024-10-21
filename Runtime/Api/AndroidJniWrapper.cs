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
namespace AndroidJniWrapper {
	[Guid("bd9f72ed-f6e0-44dd-b642-57801f568cea")]
	[Antilatency.InterfaceContract.InterfaceId("bd9f72ed-f6e0-44dd-b642-57801f568cea")]
	public interface IAndroidJni : Antilatency.InterfaceContract.IInterface {
		void initJni(System.IntPtr vm, System.IntPtr context);
	}
}
public static partial class QueryInterfaceExtensions {
	public static readonly System.Guid AndroidJniWrapper_IAndroidJni_InterfaceID = new System.Guid("bd9f72ed-f6e0-44dd-b642-57801f568cea");
	public static void QueryInterface(this Antilatency.InterfaceContract.IUnsafe _this, out AndroidJniWrapper.IAndroidJni result) {
		var guid = AndroidJniWrapper_IAndroidJni_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new AndroidJniWrapper.Details.IAndroidJniWrapper(ptr);
		}
		else {
			result = null;
		}
	}
	public static void QueryInterfaceSafe(this Antilatency.InterfaceContract.IUnsafe _this, ref AndroidJniWrapper.IAndroidJni result) {
		Antilatency.Utils.SafeDispose(ref result);
		var guid = AndroidJniWrapper_IAndroidJni_InterfaceID;
		System.IntPtr ptr = System.IntPtr.Zero;
		_this.QueryInterface(ref guid, out ptr);
		if (ptr != System.IntPtr.Zero) {
			result = new AndroidJniWrapper.Details.IAndroidJniWrapper(ptr);
		}
	}
}
namespace AndroidJniWrapper {
	namespace Details {
		public class IAndroidJniWrapper : Antilatency.InterfaceContract.Details.IInterfaceWrapper, IAndroidJni {
			private IAndroidJniRemap.VMT _VMT = new IAndroidJniRemap.VMT();
			protected new int GetTotalNativeMethodsCount() {
			    return base.GetTotalNativeMethodsCount() + typeof(IAndroidJniRemap.VMT).GetFields().Length;
			}
			public IAndroidJniWrapper(System.IntPtr obj) : base(obj) {
			    _VMT = LoadVMT<IAndroidJniRemap.VMT>(base.GetTotalNativeMethodsCount());
			}
			public void initJni(System.IntPtr vm, System.IntPtr context) {
				var interfaceContractExceptionCode = (_VMT.initJni(_object, vm, context));
				HandleExceptionCode(interfaceContractExceptionCode);
			}
		}
		public class IAndroidJniRemap : Antilatency.InterfaceContract.Details.IInterfaceRemap {
			public new struct VMT {
				public delegate Antilatency.InterfaceContract.ExceptionCode initJniDelegate(System.IntPtr _this, System.IntPtr vm, System.IntPtr context);
				#pragma warning disable 0649
				public initJniDelegate initJni;
				#pragma warning restore 0649
			}
			public new static readonly NativeInterfaceVmt NativeVmt;
			static IAndroidJniRemap() {
				var vmtBlocks = new System.Collections.Generic.List<object>();
				AppendVmt(vmtBlocks);
				NativeVmt = new NativeInterfaceVmt(vmtBlocks);
			}
			#if __MonoCS__
				[MonoPInvokeCallback(typeof(VMT.initJniDelegate))]
			#endif
			private static Antilatency.InterfaceContract.ExceptionCode initJni(System.IntPtr _this, System.IntPtr vm, System.IntPtr context) {
				try {
					var obj = GetContext(_this) as IAndroidJni;
					obj.initJni(vm, context);
				}
				catch (System.Exception ex) {
					return handleRemapException(ex, _this);
				}
				return Antilatency.InterfaceContract.ExceptionCode.Ok;
			}
			protected static new void AppendVmt(System.Collections.Generic.List<object> buffer) {
				Antilatency.InterfaceContract.Details.IInterfaceRemap.AppendVmt(buffer);
				var vmt = new VMT();
				vmt.initJni = initJni;
				buffer.Add(vmt);
			}
			public IAndroidJniRemap() { }
			public IAndroidJniRemap(System.IntPtr context, ushort lifetimeId) {
				AllocateNativeInterface(NativeVmt.Handle, context, lifetimeId);
			}
		}
	}
}


