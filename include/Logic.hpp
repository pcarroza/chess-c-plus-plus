#ifndef LOGIC_HPP
#define LOGIC_HPP

namespace controllers::modules::game
{
    class OperationController;
}

class Logic
{
public:
    virtual ~Logic() = default;

    virtual controllers::modules::game::OperationController *getController() = 0;
};

#endif
