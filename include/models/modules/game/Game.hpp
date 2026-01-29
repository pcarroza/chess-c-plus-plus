#ifndef GAME_H
#define GAME_H

#include "models/modules/game/pieces/Coordinate.hpp"
#include "models/modules/game/LogicObserver.hpp"
#include "models/modules/game/Player.hpp"

namespace models::modules::game
{
    class Board;

    using models::modules::game::pieces::Coordinate;

    class Game
    {
    public:
        Game(LogicObserver *observer);

        ~Game();

        void getValidMovements();

        void selectPiece(const Coordinate &coordinate);

        void putPiece(const Coordinate &coordinate);

        bool isEmpty(const Coordinate &coordinate);

        bool isMovementValid(const Coordinate &coordinate);

        void changeTurn();

        void removeCurrentPlayerPiece(const Coordinate &coordinate);

        void removeRivalPlayerPiece(const Coordinate &coordinate);

        Player getCurrentPlayer();

        Player getRivalPlayer();

        void initialize();

        void begin();

        void end();

        void finalize();

    public:
        static const int NUMBER_OF_PLAYERS = 2;

    private:
        Board *board;
    };
}

#endif