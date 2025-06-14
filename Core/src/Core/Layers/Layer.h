// Modified from Hazel’s Layer (Apache 2.0);
// renamed namespace hz → Core and prefixed macros with CORE_…

#pragma once

#include "Core/Events/Events.h"
#include "Core/TimeStep.h"

namespace Core
{
    class Layer
    {
    public:
        Layer(const std::string &name = "Layer");
        virtual ~Layer() = default;

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate(TimeStep ts) {}
        // virtual void OnImGuiRender() {} // unused for now
        virtual void OnEvent(Event &event) {}

        const std::string &GetName() const { return m_DebugName; }

    protected:
        std::string m_DebugName;
    };
}