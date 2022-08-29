
#pragma once

#include <AzCore/Component/Component.h>

#include <o3de-dccsi-test-project/o3de-dccsi-test-projectBus.h>

namespace o3de_dccsi_test_project
{
    class o3de_dccsi_test_projectSystemComponent
        : public AZ::Component
        , protected o3de_dccsi_test_projectRequestBus::Handler
    {
    public:
        AZ_COMPONENT(o3de_dccsi_test_projectSystemComponent, "{EA95B644-A5A1-4826-9D45-88DF12927D40}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        o3de_dccsi_test_projectSystemComponent();
        ~o3de_dccsi_test_projectSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // o3de_dccsi_test_projectRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
