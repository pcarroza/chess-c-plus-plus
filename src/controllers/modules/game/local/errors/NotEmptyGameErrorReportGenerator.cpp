#include "controllers/modules/game/local/errors/NotEmptyGameErrorReportGenerator.hpp"

namespace controllers::modules::game::local::errors
{
    GameErrorReport NotEmptyGameErrorReportGenerator::getErrorReport(const Game &game) const
    {
        return GameErrorReport("The origin coordinate is empty.");
    }
}
