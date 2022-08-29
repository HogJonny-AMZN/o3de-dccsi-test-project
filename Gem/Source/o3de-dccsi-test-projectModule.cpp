
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "o3de-dccsi-test-projectSystemComponent.h"

namespace o3de_dccsi_test_project
{
    class o3de_dccsi_test_projectModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(o3de_dccsi_test_projectModule, "{1C77095A-CEC6-4BE2-8E8F-B9050D6DF888}", AZ::Module);
        AZ_CLASS_ALLOCATOR(o3de_dccsi_test_projectModule, AZ::SystemAllocator, 0);

        o3de_dccsi_test_projectModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                o3de_dccsi_test_projectSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<o3de_dccsi_test_projectSystemComponent>(),
            };
        }
    };
}// namespace o3de_dccsi_test_project

AZ_DECLARE_MODULE_CLASS(Gem_o3de_dccsi_test_project, o3de_dccsi_test_project::o3de_dccsi_test_projectModule)
