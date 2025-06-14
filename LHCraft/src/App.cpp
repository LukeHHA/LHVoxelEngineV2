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
        PushLayer(new TestLayer());
        // PushLayer(new TestOverlay());
    }

    ~LHCraft()
    {
    }
};

Core::Application *Core::CreateApplication()
{
    return new LHCraft();
}
