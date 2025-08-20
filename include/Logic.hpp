#ifndef LOGIC_HPP
#define LOGIC_HPP

namespace controllers
{
    class OperationController;
}

using controllers::OperationController;

class Logic
{
public:
    virtual ~Logic() = default;

    virtual OperationController *getController() = 0;
};

#endif
