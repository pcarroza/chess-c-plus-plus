#include "controllers/modules/game/local/errors/GameErrorReport.hpp"

namespace controllers::modules::game::local::errors
{
    GameErrorReport::GameErrorReport(const std::string &message) : message(message) {}

    std::string GameErrorReport::getMessage() const
    {
        return message;
    }
}
