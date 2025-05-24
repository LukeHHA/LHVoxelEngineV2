#pragma once

namespace Core
{
    class Application
    {
    public:
        Application();
        ~Application();

        virtual void Run();

    private:
    };

    // non-member function in the core namespace that returns
    // a pointer to an application class which is defined by
    // the client
    Application *CreateApplication();
}