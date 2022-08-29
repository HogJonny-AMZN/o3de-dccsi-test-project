
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

#include "o3de-dccsi-test-projectSystemComponent.h"

namespace o3de_dccsi_test_project
{
    void o3de_dccsi_test_projectSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<o3de_dccsi_test_projectSystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<o3de_dccsi_test_projectSystemComponent>("o3de_dccsi_test_project", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void o3de_dccsi_test_projectSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("o3de_dccsi_test_projectService"));
    }

    void o3de_dccsi_test_projectSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("o3de_dccsi_test_projectService"));
    }

    void o3de_dccsi_test_projectSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void o3de_dccsi_test_projectSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    o3de_dccsi_test_projectSystemComponent::o3de_dccsi_test_projectSystemComponent()
    {
        if (o3de_dccsi_test_projectInterface::Get() == nullptr)
        {
            o3de_dccsi_test_projectInterface::Register(this);
        }
    }

    o3de_dccsi_test_projectSystemComponent::~o3de_dccsi_test_projectSystemComponent()
    {
        if (o3de_dccsi_test_projectInterface::Get() == this)
        {
            o3de_dccsi_test_projectInterface::Unregister(this);
        }
    }

    void o3de_dccsi_test_projectSystemComponent::Init()
    {
    }

    void o3de_dccsi_test_projectSystemComponent::Activate()
    {
        o3de_dccsi_test_projectRequestBus::Handler::BusConnect();
    }

    void o3de_dccsi_test_projectSystemComponent::Deactivate()
    {
        o3de_dccsi_test_projectRequestBus::Handler::BusDisconnect();
    }
}
