/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace MiniAudio
{
    class MiniAudioRequests
    {
    public:
        AZ_RTTI(MiniAudioRequests, "{3726A215-EF3D-44E0-8847-FBA15A8B1F84}");
        virtual ~MiniAudioRequests() = default;

        virtual ma_engine* GetSoundEngine() = 0;
    };

    class MiniAudioBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using MiniAudioRequestBus = AZ::EBus<MiniAudioRequests, MiniAudioBusTraits>;
    using MiniAudioInterface = AZ::Interface<MiniAudioRequests>;

} // namespace MiniAudio