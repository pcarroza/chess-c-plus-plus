#include "controllers/modules/game/local/errors/NotPropertyGameErrorReportGenerator.hpp"

namespace controllers::modules::game::local::errors
{
    GameErrorReport NotPropertyGameErrorReportGenerator::getErrorReport(const Game &game) const
    {
        return GameErrorReport("The piece at the origin does not belong to the current player.");
    }
}
