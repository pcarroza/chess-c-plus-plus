#ifndef STANDALONE_HPP
#define STANDALONE_HPP

#include "Chess.hpp"
#include "controllers/modules/game/local/logic/LocalLogic.hpp"

using controllers::modules::game::local::logic::LocalLogic;

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
    LocalLogic *logic;
};

#endif
