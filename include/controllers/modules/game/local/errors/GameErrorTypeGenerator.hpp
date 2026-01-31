#ifndef GAME_ERROR_TYPE_GENERATOR_HPP
#define GAME_ERROR_TYPE_GENERATOR_HPP

#include "controllers/modules/game/local/errors/GameErrorType.hpp"
#include "controllers/modules/game/local/errors/GameErrorReportGenerator.hpp"
#include <memory>

namespace controllers::modules::game::local::errors
{
    class GameErrorTypeGenerator
    {
    private:
        GameErrorType type;

        std::shared_ptr<GameErrorReportGenerator> generator;

        GameErrorTypeGenerator(GameErrorType type, std::shared_ptr<GameErrorReportGenerator> generator);

    public:
        GameErrorReport getErrorReport(const Game &game) const;

    public:
        static const GameErrorTypeGenerator NOT_EMPTY;

        static const GameErrorTypeGenerator REPEATED_COORDINATE;

        static const GameErrorTypeGenerator NOT_PROPERTY;
    };
}

#endif
