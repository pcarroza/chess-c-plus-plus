#ifndef NOT_PROPERTY_GAME_ERROR_REPORT_HPP
#define NOT_PROPERTY_GAME_ERROR_REPORT_HPP

#include "controllers/modules/game/local/errors/GameErrorReport.hpp"

namespace controllers::modules::game::local::errors
{
    class NotPropertyGameErrorReport : public GameErrorReport
    {
    public:
        NotPropertyGameErrorReport();
    };
}

#endif
