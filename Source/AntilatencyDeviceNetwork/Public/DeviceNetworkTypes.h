// Copyright 2022, ALT LLC. All Rights Reserved.
// This file is part of Antilatency SDK.
// It is subject to the license terms in the LICENSE file found in the top-level directory
// of this distribution and at http://www.antilatency.com/eula
// You may not use this file except in compliance with the License.
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include <Antilatency.DeviceNetwork.h>

#include "DeviceNetworkTypes.generated.h"

/**
 * The UE wrapper for the Antilatency::DeviceNetwork::NodeHandle. Every time device is connected,
 * the unique handle will be applied to it, so, when device disconnects,
 * ENodeStatus for its node becomes Invalid, after reconnection this devices receives new handle.
 */
USTRUCT(BlueprintType, Category = "Antilatency|DeviceNetwork|Library|AdnNode")
struct FAdnNode {
    GENERATED_BODY()

    FAdnNode() : NativeHandleValue(static_cast<int32>(Antilatency::DeviceNetwork::NodeHandle::Null)) {}
    FAdnNode(Antilatency::DeviceNetwork::NodeHandle native) : NativeHandleValue(static_cast<int32>(native)) {}
    FAdnNode(int32 value) : NativeHandleValue(value) {}

    UPROPERTY(BlueprintReadOnly, Category = "Antilatency|DeviceNetwork|Library|AdnNode")
    int32 NativeHandleValue;

    FORCEINLINE bool operator==(const FAdnNode& other) const {
        return NativeHandleValue == other.NativeHandleValue;
    }

    FORCEINLINE bool operator!=(const FAdnNode& other) const {
        return NativeHandleValue != other.NativeHandleValue;
    }

    friend uint32 GetTypeHash(const FAdnNode& Other) {
        return GetTypeHash(Other.NativeHandleValue);
    }

    Antilatency::DeviceNetwork::NodeHandle ToNative() const {
        return static_cast<Antilatency::DeviceNetwork::NodeHandle>(NativeHandleValue);
    }
};

/**
 * USB device identifier.
 */
USTRUCT(BlueprintType, Category = "Antilatency|DeviceNetwork|USB Device Filter")
struct FUsbDeviceFilter {
    GENERATED_BODY()

    FUsbDeviceFilter() {
        Vid = static_cast<int32>(Antilatency::DeviceNetwork::Constants::AllUsbDevices.vid);
        Pid = static_cast<int32>(Antilatency::DeviceNetwork::Constants::AllUsbDevices.pid);
        PidMask = static_cast<int32>(Antilatency::DeviceNetwork::Constants::AllUsbDevices.pidMask);
    }
    
    FUsbDeviceFilter(Antilatency::DeviceNetwork::UsbDeviceFilter native) :
        Vid(static_cast<int32>(native.vid)),
        Pid(static_cast<int32>(native.pid)),
        PidMask(static_cast<int32>(native.pidMask)){}

    FORCEINLINE bool operator==(const FUsbDeviceFilter& other) const {
        return Vid == other.Vid && Pid == other.Pid && PidMask == other.PidMask;
    }

    FORCEINLINE bool operator!=(const FUsbDeviceFilter& other) const {
        return Vid != other.Vid || Pid != other.Pid || PidMask != other.PidMask;
    }

    Antilatency::DeviceNetwork::UsbDeviceFilter ToNative() const {
        Antilatency::DeviceNetwork::UsbDeviceFilter result;
        result.vid = static_cast<Antilatency::DeviceNetwork::UsbVendorId>(Vid & 0xFFFF);
        result.pid = static_cast<uint16_t>(Pid & 0xFFFF);
        result.pidMask = static_cast<uint16_t>(PidMask & 0xFFFF);
        return result;
    }

    /** USB device vendor ID. */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Antilatency|DeviceNetwork|USB Device Type")
    int32 Vid;

    /** USB device product ID. */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Antilatency|DeviceNetwork|USB Device Type")
    int32 Pid;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Antilatency|DeviceNetwork|USB Device Type")
    int32 PidMask;
};

/** Defines different node conditions. */
UENUM(BlueprintType, Category = "Antilatency|DeviceNetwork|Node Status")
enum class ENodeStatus : uint8 {
    /** The node in connected and no task is currently running on it. Any supported task can be started on it. */
    Idle,
    /** The node in connected and a task is currently running on it. Before running any task on such node, you need to stop the current task first. */
    TaskRunning,
    /** The node in not valid, no tasks can be executed on it. */
    Invalid
};

// TODO: Original type is int32_t!!!!
/**
* Antilatency Device Network library Log Level
*/
UENUM(BlueprintType)
enum class EDeviceNetworkLogLevel : uint8 {
    Trace,
    Debug,
    Info,
    Warning,
    Error,
    Critical,
    Off
};