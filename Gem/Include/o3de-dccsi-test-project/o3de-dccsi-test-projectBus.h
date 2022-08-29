
#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace o3de_dccsi_test_project
{
    class o3de_dccsi_test_projectRequests
    {
    public:
        AZ_RTTI(o3de_dccsi_test_projectRequests, "{1440AAAD-65DF-4170-A75E-618D3B08A998}");
        virtual ~o3de_dccsi_test_projectRequests() = default;
        // Put your public methods here
    };

    class o3de_dccsi_test_projectBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using o3de_dccsi_test_projectRequestBus = AZ::EBus<o3de_dccsi_test_projectRequests, o3de_dccsi_test_projectBusTraits>;
    using o3de_dccsi_test_projectInterface = AZ::Interface<o3de_dccsi_test_projectRequests>;

} // namespace o3de_dccsi_test_project
