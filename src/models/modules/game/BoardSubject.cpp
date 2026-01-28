#include "models/modules/game/BoardSubject.hpp"

namespace models::modules::game::pieces
{
    void BoardSubject::subscribe(LogicObserver *logicObserver)
    {
        this->observer = logicObserver;
    }

    void BoardSubject::initialize()
    {
        observer->initialize();
    }

    void BoardSubject::begin()
    {
        observer->begin();
    }

    void BoardSubject::finalize()
    {
        observer->finalize();
    }

    void BoardSubject::end()
    {
        observer->end();
    }
}
