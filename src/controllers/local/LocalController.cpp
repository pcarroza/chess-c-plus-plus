#include "controllers/local/LocalController.hpp"

namespace controllers::local
{
    LocalController::LocalController(Game &game) : game(game)
    {
    }

    void LocalController::getValidMovements()
    {
        game.getValidMovements();
    }

    void LocalController::select(Coordinate &coordinate)
    {
        game.selectPieceTo(coordinate);
    }

    void LocalController::put(Coordinate &coordinate)
    {
        game.putPieceTo(coordinate);
    }

    bool LocalController::isEmpty(Coordinate &coordinate)
    {
        return game.isEmpty(coordinate);
    }

    bool LocalController::isMovementValid(Coordinate coordinate)
    {
        return game.isMovementValid(coordinate);
    }

    void LocalController::removeCurrentPlayerPiece(Coordinate &coordinate)
    {
        game.removeCurrentPlayerPiece(coordinate);
    }

    void LocalController::removeRivalPlayerPiece(Coordinate &coordinate)
    {
        game.removeRivalPlayerPiece(coordinate);
    }

    Player LocalController::getCurrentPlayer()
    {
        return Player::WHITE;
    }

    Player LocalController::getRivalPlayer()
    {
        return Player::BLACK;
    }

    bool LocalController::isTheWhitePieceSelected(Coordinate &/*coordinate*/)
    {
        return false;
    }

    bool LocalController::isTheBlackPieceSelected(Coordinate &/*coordinate*/)
    {
        return false;
    }

    void LocalController::changeTurn()
    {
        game.changeTurn();
    }

    void LocalController::initialize()
    {
        game.initialize();
    }

    void LocalController::begin()
    {
        game.begin();
    }

    void LocalController::finalize()
    {
        game.finalize();
    }

    void LocalController::end()
    {
        game.end();
    }
}