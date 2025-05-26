// Modified from Hazel’s LayerStack (Apache 2.0);
// renamed namespace hz → Core and prefixed macros with CORE_…

#pragma once

#include "Events/Events.h"
namespace Core
{
    class Layer
    {
    public:
        Layer(const std::string &name = "Layer");
        virtual ~Layer();

        virtual void OnAttach() {};
        virtual void OnDetach() {};
        virtual void OnUpdate() {};
        virtual void OnEvent(Event &event) {};

        inline const std::string &GetName() const { return m_DebugName; };

    protected:
        std::string m_DebugName;
    };
}