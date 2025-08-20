#ifndef START_VIEW_HPP
#define START_VIEW_HPP

namespace controllers
{
    class StartController;
}

using controllers::StartController;

namespace views::console
{
    class StartView
    {
    public:
        StartView();

        ~StartView();

        void interact(StartController *startController);
    };
}

#endif
