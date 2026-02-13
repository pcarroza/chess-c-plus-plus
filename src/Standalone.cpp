#include "Standalone.hpp"
#include "views/modules/console/modules/game/ConsoleView.hpp"

using views::modules::console::modules::game::ConsoleView;

Standalone::Standalone()
{
    logic = new LocalGameLogic();
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
