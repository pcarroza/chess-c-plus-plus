#ifndef BOARD_SUBJECT_HPP
#define BOARD_SUBJECT_HPP

#include "LogicObserver.hpp"
#include <list>
#include <memory>

using models::modules::game::LogicObserver;

namespace models::modules::game::pieces
{
    class BoardSubject
    {
    public:
        virtual ~BoardSubject() = default;

        void subscribe(LogicObserver *logicObserver);

        void initialize();

        void begin();

        void finalize();

        void save();

        void resume();

        void end();

    private:
        LogicObserver *logicObserver;
    };
}

#endif
