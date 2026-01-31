#include "controllers/modules/game/local/errors/GameErrorTypeGenerator.hpp"
#include "controllers/modules/game/local/errors/NotEmptyGameErrorReportGenerator.hpp"
#include "controllers/modules/game/local/errors/RepeatedCoordinateGameErrorReportGenerator.hpp"
#include "controllers/modules/game/local/errors/NotPropertyGameErrorReportGenerator.hpp"

namespace controllers::modules::game::local::errors
{
    GameErrorTypeGenerator::GameErrorTypeGenerator(
        GameErrorType type,
        std::shared_ptr<GameErrorReportGenerator> generator)
        : type(type), generator(generator) {}

    const GameErrorTypeGenerator GameErrorTypeGenerator::NOT_EMPTY(
        GameErrorType::NOT_EMPTY,
        std::make_shared<NotEmptyGameErrorReportGenerator>());

    const GameErrorTypeGenerator GameErrorTypeGenerator::REPEATED_COORDINATE(
        GameErrorType::REPEATED_COORDINATE,
        std::make_shared<RepeatedCoordinateGameErrorReportGenerator>());

    const GameErrorTypeGenerator GameErrorTypeGenerator::NOT_PROPERTY(
        GameErrorType::NOT_PROPERTY,
        std::make_shared<NotPropertyGameErrorReportGenerator>());

    GameErrorReport GameErrorTypeGenerator::getErrorReport(const Game &game) const
    {
        return generator->getErrorReport(game);
    }
}
