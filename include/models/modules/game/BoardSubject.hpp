#ifndef BOARD_SUBJECT_HPP
#define BOARD_SUBJECT_HPP

#include "LogicObserver.hpp"
#include <list>
#include <memory>

namespace models::modules::game::pieces
{
    class BoardSubject
    {
    public:
        virtual ~BoardSubject() = default;

        void subscribe(::models::modules::game::LogicObserver *logicObserver);

        void initialize();

        void begin();

        void finalize();

        void end();

    private:
        ::models::modules::game::LogicObserver *observer;
    };
}

#endif
