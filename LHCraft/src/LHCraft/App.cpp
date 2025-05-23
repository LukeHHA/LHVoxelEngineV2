#include "Core/Core.h"
#include <iostream>

int main()
{
    std::unique_ptr<Core::Run> run = std::make_unique<Core::Run>();
    run->PrintHello();
}