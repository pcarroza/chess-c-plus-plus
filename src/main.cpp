#include <iostream>
#include <memory>
#include <list>
#include <vector>
#include <algorithm>
#include <map>

#include "models/modules/game/pieces/Coordinate.hpp"
#include "models/modules/game/pieces/PiecesMapBuilder.hpp"
#include "models/modules/game/pieces/Pawn.hpp"
#include "models/modules/game/pieces/Rook.hpp"
#include "models/modules/game/pieces/Queen.hpp"
#include "models/modules/game/pieces/Bishop.hpp"
#include "models/modules/game/pieces/King.hpp"
#include "models/modules/game/pieces/Knight.hpp"
#include "models/modules/game/pieces/King.hpp"

#include "controllers/modules/game/local/logic/LocalLogic.hpp"
#include "controllers/modules/game/local/logic/StateBuilder.hpp"
#include "models/modules/game/Game.hpp"
#include "models/modules/game/Board.hpp"
#include "./Logic.hpp"

#include "controllers/modules/game/local/LocalStartController.hpp"
#include "controllers/modules/game/local/LocalOperationControllerBuilder.hpp"
#include "views/console/ConsoleView.hpp"
#include "models/modules/game/Game.hpp"

using controllers::modules::game::local::LocalOperationControllerBuilder;
using controllers::modules::game::local::LocalStartController;
using controllers::modules::game::local::logic::LocalLogic;
using views::console::ConsoleView;

using models::modules::game::Game;
using models::modules::game::Board;
using models::modules::game::pieces::Coordinate;
using models::modules::game::pieces::PiecesMapBuilder;
using models::modules::game::pieces::Pawn;
using models::modules::game::pieces::Rook;
using models::modules::game::pieces::Queen;
using models::modules::game::pieces::Bishop;
using models::modules::game::pieces::King;
using models::modules::game::pieces::Knight;
using models::modules::game::pieces::Player;
using models::modules::game::pieces::Piece;


int main()
{
    LocalLogic *logic1 = new LocalLogic();

    Game *game1 = new Game(logic1);
    ConsoleView *consoleView = new ConsoleView();
    LocalOperationControllerBuilder *builder = new LocalOperationControllerBuilder(*game1);
    builder->build();
    StartController *start = builder->getStartController();
    consoleView->interact(start);

    delete consoleView;
    delete logic1;
    delete game1;
    delete builder;

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
    pawn->subscribe(board);
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
    game->selectPiece(Coordinate(1, 2));
    game->putPiece(Coordinate(2, 2));
    game->putPiece(Coordinate(3, 2));
    game->putPiece(Coordinate(4, 2));
    game->putPiece(Coordinate(5, 2));
    game->putPiece(Coordinate(6, 2));

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
