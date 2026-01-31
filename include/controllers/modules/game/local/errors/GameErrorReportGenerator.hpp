#ifndef GAME_ERROR_REPORT_GENERATOR_HPP
#define GAME_ERROR_REPORT_GENERATOR_HPP

#include "models/modules/game/Game.hpp"
#include "controllers/modules/game/local/errors/GameErrorReport.hpp"

namespace models::modules::game
{
    class Game;
}

using models::modules::game::Game;

namespace controllers::modules::game::local::errors
{
    class GameErrorReportGenerator
    {
    public:
        virtual ~GameErrorReportGenerator() = default;

        virtual GameErrorReport getErrorReport(const Game &game) const = 0;
    };
}

#endif
