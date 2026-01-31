#include "controllers/modules/game/local/errors/RepeatedCoordinateGameErrorReportGenerator.hpp"

namespace controllers::modules::game::local::errors
{
    GameErrorReport RepeatedCoordinateGameErrorReportGenerator::getErrorReport(const Game &game) const
    {
        return GameErrorReport("The origin and destination coordinates are the same.");
    }
}
