#ifndef STANDALONE_HPP
#define STANDALONE_HPP

#include "Chess.hpp"
#include "controllers/modules/game/local/logic/LocalGameLogic.hpp"

using controllers::modules::game::local::logic::LocalGameLogic;

class Logic;

class View;

class Standalone : public Chess
{
public:
    Standalone();

    ~Standalone();

    Logic *getLogic() override;

    View *getView() override;

private:
    LocalGameLogic *logic;
};

#endif
