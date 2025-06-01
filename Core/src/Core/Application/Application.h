// Modified from Hazel’s Application (Apache 2.0);
// renamed namespace hz → Core and prefixed macros with CORE_…

/**
 * @file Application.h
 * @brief Core application entry‐point and run‐loop.
 *
 * This is the central class of the Core engine.  It owns
 * the main window, dispatches events, and manages the
 * LayerStack for drawing and updates.
 */

#pragma once

#include <memory>

#include "Core/Window/Window.h"
#include "Core/Events/KeyEvents.h"
#include "Core/Layers/Layer.h"
#include "Core/Layers/LayerStack.h"
#include "Core/Events/ApplicationEvents.h"

#include "Core/Renderer/Shader/Shader.h"
#include "Core/Renderer/Buffers.h"
#include "Core/Renderer/VertexArray.h"

namespace Core
{
    /**
     * @class Application
     * @brief The main engine application.
     *
     * Manages the window, event loop, and a stack of Layer
     * objects (game logic, UI, debug overlays).  Users
     * implement `CreateApplication()` to return their subclass.
     *
     * @note You must call `PushLayer()`/`PushOverlay()` before `Run()`.
     */
    class Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event &event);
        static Application &Get() { return *s_Instance; }
        Window &GetWindow() { return *m_Window; }

        void PushLayer(Layer *layer);
        void PushOverlay(Layer *layer);

    private:
        bool
        OnWindowClose(WindowCloseEvent &event);
        bool OnESCKeyPress(KeyPressedEvent &e);

    private:
        static Application *s_Instance;
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;

        std::shared_ptr<Shader> m_Shader;
        std::shared_ptr<VertexArray> m_VertexArray;
        std::shared_ptr<VertexBuffer> m_VertexBuffer;
        std::shared_ptr<IndexBuffer> m_IndexBuffer;
    };

    /**
     * @brief Factory function the client must implement.
     *
     * Returns a pointer to the user’s subclass of Application,
     * which the engine will take ownership of and run.
     */
    Application *CreateApplication();
}