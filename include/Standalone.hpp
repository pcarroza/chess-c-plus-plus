#ifndef STANDALONE_HPP
#define STANDALONE_HPP

#include "Chess.hpp"
#include "controllers/local/logic/LocalLogic.hpp"

using controllers::local::logic::LocalLogic;

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
