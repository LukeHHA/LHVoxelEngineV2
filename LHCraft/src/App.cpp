#include "Core/LHCraft.h"
#include <iostream>
#include <string>

class TestLayer : public Core::Layer
{
public:
    TestLayer() : Layer("TestLayer") {}

    void OnUpdate() override
    {
    }

    void OnEvent(Core::Event &event) override
    {
    }
};

class LHCraft : public Core::Application
{
public:
    LHCraft()
    {
        PushLayer(new TestLayer());
    }

    ~LHCraft()
    {
    }
};

Core::Application *Core::CreateApplication()
{
    return new LHCraft();
}