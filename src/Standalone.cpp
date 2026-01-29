#include "Standalone.hpp"
#include "views/console/ConsoleView.hpp"

using views::console::ConsoleView;

Standalone::Standalone()
{
    logic = new LocalLogic();
}

Standalone::~Standalone()
{
}

Logic *Standalone::getLogic()
{
    return logic;
}

View *Standalone::getView()
{
    return new ConsoleView();
}
