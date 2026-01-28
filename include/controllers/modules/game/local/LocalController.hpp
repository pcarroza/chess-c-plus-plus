#ifndef LOCAL_CONTROLLER_HPP
#define LOCAL_CONTROLLER_HPP

#include "models/modules/game/pieces/Coordinate.hpp"
#include "models/modules/game/Player.hpp"
#include "models/modules/game/Game.hpp"

using models::modules::game::Game;

namespace controllers::modules::game::local
{
    class LocalController
    {
    public:
        LocalController(Game &game);

        void getValidMovements();

        void selectPiece(Coordinate &coordinate);

        void putPiece(Coordinate &coordinate);

        bool isEmpty(Coordinate &coordinate);

        bool isMovementValid(Coordinate &coordinate);

        void removeCurrentPlayerPiece(Coordinate &coordinate);

        void removeRivalPlayerPiece(Coordinate &coordinate);

        Player getCurrentPlayer();

        Player getRivalPlayer();

        bool isTheWhitePieceSelected(Coordinate &coordinate);

        bool isTheBlackPieceSelected(Coordinate &coordinate);

        void changeTurn();

        void initialize();

        void begin();

        void finalize();

        void end();

    private:
        Game &game;
    };
}

#endif
