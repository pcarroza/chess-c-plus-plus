#ifndef NOT_EMPTY_GAME_ERROR_REPORT_GENERATOR_HPP
#define NOT_EMPTY_GAME_ERROR_REPORT_GENERATOR_HPP

#include "controllers/modules/game/local/errors/GameErrorReportGenerator.hpp"

namespace controllers::modules::game::local::errors
{
    class NotEmptyGameErrorReportGenerator : public GameErrorReportGenerator
    {
    public:
        GameErrorReport getErrorReport(const Game &game) const override;
    };
}

#endif
