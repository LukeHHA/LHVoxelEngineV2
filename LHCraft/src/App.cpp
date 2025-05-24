#include "LHCraft.h"
#include <iostream>

class LHCraft : public Core::Application
{
public:
    LHCraft()
    {
    }

    ~LHCraft()
    {
    }
};

Core::Application *Core::CreateApplication()
{
    return new LHCraft();
}