// Modified from Hazel’s Application (Apache 2.0);
// renamed namespace hz → Core and prefixed macros with CORE_…

/**
 * @file Application.h
 * @brief Core application entry‐point and run‐loop.
 *
 * This is the central class of the Core engine.  It owns the main window,
 * dispatches events, and manages the LayerStack for drawing and updates.
 */

#pragma once

#include <memory>

#include "Core/Window/Window.h"
#include "Core/Events/KeyEvents.h"
#include "Core/Layers/Layer.h"
#include "Core/Layers/LayerStack.h"
#include "Core/Events/ApplicationEvents.h"

namespace Core
{
    /**
     * @class Application
     * @brief The main engine application.
     *
     * Manages the window, event loop, and a stack of Layer
     * objects (game logic, UI, debug overlays).  Users
     * implement `CreateApplication()` to return their subclass.
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

        /**
         * @fn void PushLayer(Layer *layer)
         * @fn void PushOverLayer(Layer *layer)
         * @brief functions to push a layer class of bundled logic
         *
         * A layer can be used to test features whilst remaining dec
         * oupled from the main layers of the application. The ordering
         * of layers does matter and thus any drawing that takes place
         * will be in order the layers where pushed. Overlay will ensure
         * the layer is push to the front of the stack.
         */
        void PushLayer(Layer *layer);
        void PushOverlay(Layer *layer);

    private:
        /**
         * @private Binded Events
         * @brief Application functions that become binded.
         *
         * Private functions can be defined here for events that dont require
         * immediate action.
         * @note Class Input does input polling but is generally not needed here.
         * @see Application() for example on how these functions are binded to the
         * event system
         */
        bool
        OnWindowClose(WindowCloseEvent &event);
        bool OnESCKeyPress(KeyPressedEvent &e);

    private:
        static Application *s_Instance;
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;

        float m_LastTime = 0.0f;
    };

    /**
     * @brief Factory function the client must implement.
     *
     * Returns a pointer to the user’s subclass of Application,
     * which the engine will take ownership of and run.
     */
    Application *CreateApplication();
}
