#ifndef VIEW_HPP
#define VIEW_HPP

namespace controllers::modules::game
{
    class OperationController;
}

class View
{
public:
    virtual ~View() = default;

    virtual void interact(controllers::modules::game::OperationController *operationController) = 0;
};

#endif
