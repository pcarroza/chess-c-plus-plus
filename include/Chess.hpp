#ifndef CHESS_HPP
#define CHESS_HPP

#include "Logic.hpp"
#include "View.hpp"

class Logic;

class View;

class Chess
{
public:
    Chess();

    ~Chess();

    void run();

    virtual Logic *getLogic() = 0;

    virtual View *getView() = 0;

private:
    Logic *logic;

    View *view;
};

#endif
