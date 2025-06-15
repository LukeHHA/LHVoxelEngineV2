#include "Core/LHCraft.h"
#include "ExampleRenderLayer.h"
#include "Core/EntryPoint.h"
#include "TestOverlay.h"

#include <iostream>
#include <string>

class LHCraft : public Core::Application
{
public:
    LHCraft()
    {
        CORE_PROFILE_FUNCTION();
        PushLayer(new TestLayer());
        // PushLayer(new TestOverlay());
    }

    ~LHCraft()
    {
        CORE_PROFILE_FUNCTION();
    }
};

Core::Application *Core::CreateApplication()
{
    CORE_PROFILE_FUNCTION();
    return new LHCraft();
}
