#ifndef NOT_EMPTY_GAME_ERROR_REPORT_HPP
#define NOT_EMPTY_GAME_ERROR_REPORT_HPP

#include "controllers/modules/game/local/errors/GameErrorReport.hpp"

namespace controllers::modules::game::local::errors
{
    class NotEmptyGameErrorReport : public GameErrorReport
    {
    public:
        NotEmptyGameErrorReport();
    };
}

#endif
