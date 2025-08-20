#ifndef VIEW_HPP
#define VIEW_HPP

namespace controllers
{
    class OperationController;
}

using controllers::OperationController;

class View
{
public:
    virtual ~View() = default;

    virtual void interact(OperationController *operationController) = 0;
};

#endif
