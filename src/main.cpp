#include <iostream>
#include <memory>
#include <list>
#include <vector>
#include <algorithm>
#include <map>

#include "models/pieces/Coordinate.hpp"
#include "models/pieces/PiecesMapBuilder.hpp"
#include "models/pieces/Pawn.hpp"
#include "models/pieces/Rook.hpp"
#include "models/pieces/Queen.hpp"
#include "models/pieces/Bishop.hpp"
#include "models/pieces/King.hpp"
#include "models/pieces/Knight.hpp"
#include "models/pieces/King.hpp"

#include "controllers/local/logic/LocalLogic.hpp"
#include "controllers/local/logic/StateBuilder.hpp"
#include "models/Game.hpp"
#include "models/Board.hpp"
#include "models/pieces/Coordinate.hpp"
#include "./Logic.hpp"

#include "views/console/ConsoleView.hpp"
#include "models/Game.hpp"

using controllers::local::logic::LocalLogic;
using views::console::ConsoleView;

int main()
{
    ConsoleView *consoleView = new ConsoleView();
    delete consoleView;

    Board *board = new Board();
    std::map<Player, std::list<std::shared_ptr<Piece>>> piecesMap = PiecesMapBuilder::build(board);

    board->selectPiece(Coordinate(1, 2));

    for (auto &color : piecesMap)
    {
        for (auto &piece : color.second)
        {
            std::cout << piece->toString() << std::endl;
        }
    }

    Piece *pawn = new Pawn(new Coordinate(1, 2), Player::BLACK);
    std::cout << pawn->toString() << std::endl;
    pawn->put(new Coordinate(2, 2));
    std::cout << pawn->toString() << std::endl;
    pawn->put(new Coordinate(3, 2));
    std::cout << pawn->toString() << std::endl;
    pawn->put(new Coordinate(4, 2));
    std::cout << pawn->toString() << std::endl;
    pawn->put(new Coordinate(5, 2));
    std::cout << pawn->toString() << std::endl;
    pawn->put(new Coordinate(6, 2));
    std::cout << pawn->toString() << std::endl;
    pawn->put(new Coordinate(7, 2));
    std::cout << pawn->toString() << std::endl;

    bool isValid = pawn->isMovementValid(Coordinate(8, 2));
    std::cout << isValid << std::endl;

    delete pawn;

    Piece *rook1 = new Rook(new Coordinate(1, 2), Player::BLACK);
    std::cout << rook1->toString() << std::endl;
    delete rook1;

    Piece *rook2 = new Rook(new Coordinate(1, 2), Player::BLACK);
    std::cout << rook2->toString() << std::endl;
    delete rook2;

    Piece *rook3 = new Rook(new Coordinate(1, 2), Player::BLACK);
    std::cout << rook3->toString() << std::endl;
    delete rook3;

    Piece *rook4 = new Rook(new Coordinate(1, 2), Player::BLACK);
    std::cout << rook4->toString() << std::endl;
    delete rook4;

    Piece *rook5 = new Rook(new Coordinate(1, 2), Player::BLACK);
    std::cout << rook5->toString() << std::endl;
    delete rook5;

    Piece *rook6 = new Rook(new Coordinate(1, 2), Player::BLACK);
    std::cout << rook6->toString() << std::endl;
    delete rook6;

    Piece *queen = new Queen(new Coordinate(1, 2), Player::BLACK);
    std::cout << queen->toString() << std::endl;
    delete queen;

    Piece *king = new King(new Coordinate(1, 2), Player::BLACK);
    std::cout << king->toString() << std::endl;
    delete king;

    Piece *knight = new Knight(new Coordinate(1, 2), Player::BLACK);
    std::cout << knight->toString() << std::endl;
    delete knight;

    Piece *bishop = new Queen(new Coordinate(1, 2), Player::BLACK);
    std::cout << bishop->toString() << std::endl;
    delete bishop;

    delete board;

    LocalLogic *logic = new LocalLogic();
    Game *game = new Game(logic);
    game->select(Coordinate(1, 2));
    game->put(Coordinate(2, 2));
    game->put(Coordinate(3, 2));
    game->put(Coordinate(4, 2));
    game->put(Coordinate(5, 2));
    game->put(Coordinate(6, 2));

    game->begin();
    game->finalize();
    game->initialize();
    game->begin();
    game->finalize();
    game->end();

    delete game;
    delete logic;

    return 0;
}
