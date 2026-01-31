#ifndef NOT_PROPERTY_GAME_ERROR_REPORT_GENERATOR_HPP
#define NOT_PROPERTY_GAME_ERROR_REPORT_GENERATOR_HPP

#include "controllers/modules/game/local/errors/GameErrorReportGenerator.hpp"

namespace controllers::modules::game::local::errors
{
    class NotPropertyGameErrorReportGenerator : public GameErrorReportGenerator
    {
    public:
        GameErrorReport getErrorReport(const Game &game) const override;
    };
}

#endif
