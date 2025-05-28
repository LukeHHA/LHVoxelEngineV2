// Modified from Hazel’s Layer (Apache 2.0);
// renamed namespace hz → Core and prefixed macros with CORE_…

#include "Core/Core.h"
#include "Layer.h"

namespace Core
{
    Layer::Layer(const std::string &debugName) : m_DebugName(debugName)
    {
    }
}