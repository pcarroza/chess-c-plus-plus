#include "models/modules/game/BoardSubject.hpp"

namespace models::modules::game::pieces
{
    void BoardSubject::subscribe(LogicObserver *logicObserver)
    {
        this->logicObserver = logicObserver;
    }

    void BoardSubject::initialize()
    {
        logicObserver->initialize();
    }

    void BoardSubject::begin()
    {
        logicObserver->begin();
    }

    void BoardSubject::finalize()
    {
        logicObserver->finalize();
    }

    void BoardSubject::end()
    {
        logicObserver->end();
    }
}
