#ifndef GAME_ERROR_REPORT_HPP
#define GAME_ERROR_REPORT_HPP

#include <string>

namespace controllers::modules::game::local::errors
{
    class GameErrorReport
    {
    private:
        std::string message;

    public:
        GameErrorReport(const std::string &message);

        std::string getMessage() const;
    };
}

#endif
