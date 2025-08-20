#ifndef BOARD_SUBJECT_HPP
#define BOARD_SUBJECT_HPP

#include "LogicObserver.hpp"
#include "models/pieces/Coordinate.hpp"

#include <list>
#include <memory>

namespace models
{
    class LogicObserver;
}

using models::LogicObserver;

class BoardSubject
{
public:
    virtual ~BoardSubject() = default;

    void subscribe(LogicObserver *logicObserver);

    void initialize();

    void begin();

    void finalize();

    void end();

private:
    LogicObserver *observer;
};

#endif
