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

#include <Antilatency.RadioMetrics.h>

#include "RadioMetricsTypes.generated.h"

/**
 * The UE wrapper for the Antilatency::RadioMetrics::Metrics - a simplified metrics.
 */
USTRUCT(BlueprintType, Category = "Antilatency|Radio Metrics|Types|Metrics")
struct FRadioMetrics {
	GENERATED_BODY()

	FRadioMetrics() : AverageRssi(0), PacketLossRate(0.0f) {}
	FRadioMetrics(Antilatency::RadioMetrics::Metrics native) : AverageRssi(static_cast<int32>(native.averageRssi)), PacketLossRate(native.packetLossRate) {}
	
	/** Average rssi value in dBm between two call URadioMetricsCotask::GetMetrics(). */
	UPROPERTY(BlueprintReadOnly, Category = "Antilatency|Radio Metrics|Types|Metrics")
	int32 AverageRssi;
	
	/** Packet loss rate in range 0..1. Value 0 - no lost packets. */
	UPROPERTY(BlueprintReadOnly, Category = "Antilatency|Radio Metrics|Types|Metrics")
	float PacketLossRate;
};

/**
 * The UE wrapper for the Antilatency::RadioMetrics::Interop::ExtendedMetrics - an extended metrics.
 */
USTRUCT(BlueprintType, Category = "Antilatency|Radio Metrics|Types|Extended Metrics")
struct FExtendedMetrics {
    GENERATED_BODY()

    FExtendedMetrics() : TxBytes(0), TxPacketsCount(0), RxBytes(0), RxPacketsCount(0), FlowCount(0), AverageRssi(0), MinRssi(0), MaxRssi(0), MissedPacketsCount(0), FailedPacketsCount(0) {}
    FExtendedMetrics(Antilatency::RadioMetrics::Interop::ExtendedMetrics native) : 
		TxBytes(static_cast<int32>(native.txBytes)),
		TxPacketsCount(static_cast<int32>(native.txPacketsCount)), 
		RxBytes(static_cast<int32>(native.rxBytes)), 
		RxPacketsCount(static_cast<int32>(native.rxPacketsCount)), 
		FlowCount(static_cast<int32>(native.flowCount)), 
		AverageRssi(static_cast<uint8>(native.averageRssi)), 
		MinRssi(static_cast<uint8>(native.minRssi)), 
		MaxRssi(static_cast<uint8>(native.maxRssi)), 
		MissedPacketsCount(static_cast<int32>(native.missedPacketsCount)), 
		FailedPacketsCount(static_cast<int32>(native.failedPacketsCount)) {}

    /** The number of bytes that were sent to targetNode */
    UPROPERTY(BlueprintReadOnly, Category = "Antilatency|Radio Metrics|Types|Extended Metrics")
    int32 TxBytes;

    /** The number of radio packets that were sent to targetNode */
    UPROPERTY(BlueprintReadOnly, Category = "Antilatency|Radio Metrics|Types|Extended Metrics")
    int32 TxPacketsCount;
	
	/** The number of bytes that were received from targetNode */
    UPROPERTY(BlueprintReadOnly, Category = "Antilatency|Radio Metrics|Types|Extended Metrics")
    int32 RxBytes;
	
	/** The number of radio packets that were received from targetNode */
    UPROPERTY(BlueprintReadOnly, Category = "Antilatency|Radio Metrics|Types|Extended Metrics")
    int32 RxPacketsCount;
	
	/** 
	 * The number of packets without data that were received from targetNode, 
	 * since there was not enough buffer space on the wired socket. 
	 * In a normal situation, it is always 0, otherwise, there are problems with USB 
	 */
    UPROPERTY(BlueprintReadOnly, Category = "Antilatency|Radio Metrics|Types|Extended Metrics")
    int32 FlowCount;
	
	/** Averaged RSSI value in dBm. */
    UPROPERTY(BlueprintReadOnly, Category = "Antilatency|Radio Metrics|Types|Extended Metrics")
    uint8 AverageRssi;
	
	/** Min RSSI value in dBm.(worse) */
    UPROPERTY(BlueprintReadOnly, Category = "Antilatency|Radio Metrics|Types|Extended Metrics")
    uint8 MinRssi;
	
	/** Max RSSI value in dBm.(best) */
    UPROPERTY(BlueprintReadOnly, Category = "Antilatency|Radio Metrics|Types|Extended Metrics")
    uint8 MaxRssi;
	
	/** The number of lost packets without a response */
    UPROPERTY(BlueprintReadOnly, Category = "Antilatency|Radio Metrics|Types|Extended Metrics")
    int32 MissedPacketsCount;
	
	/** The number of packets that were corrupted */
    UPROPERTY(BlueprintReadOnly, Category = "Antilatency|Radio Metrics|Types|Extended Metrics")
    int32 FailedPacketsCount;
};
