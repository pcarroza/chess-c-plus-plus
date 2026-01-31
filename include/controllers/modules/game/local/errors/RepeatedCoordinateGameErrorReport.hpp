#ifndef REPEATED_COORDINATE_GAME_ERROR_REPORT_HPP
#define REPEATED_COORDINATE_GAME_ERROR_REPORT_HPP

#include "controllers/modules/game/local/errors/GameErrorReport.hpp"

namespace controllers::modules::game::local::errors
{
    class RepeatedCoordinateGameErrorReport : public GameErrorReport
    {
    public:
        RepeatedCoordinateGameErrorReport();
    };
}

#endif
