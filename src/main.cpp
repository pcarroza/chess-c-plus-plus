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
#include "models/modules/game/pieces/Coordinate.hpp"
#include "./Logic.hpp"

#include "controllers/modules/game/local/LocalStartController.hpp"
#include "views/console/ConsoleView.hpp"
#include "controllers/modules/game/local/errors/GameErrorTypeGenerator.hpp"

using controllers::modules::game::local::LocalStartController;
using controllers::modules::game::local::errors::GameErrorTypeGenerator;
using controllers::modules::game::local::logic::LocalLogic;
using models::modules::game::Board;
using models::modules::game::Game;
using models::modules::game::Player;
using models::modules::game::pieces::Bishop;
using models::modules::game::pieces::Coordinate;
using models::modules::game::pieces::King;
using models::modules::game::pieces::Knight;
using models::modules::game::pieces::Pawn;
using models::modules::game::pieces::Piece;
using models::modules::game::pieces::PiecesMapBuilder;
using models::modules::game::pieces::Queen;
using models::modules::game::pieces::Rook;
using views::console::ConsoleView;

int main()
{
    LocalLogic *logic = new LocalLogic();
    Game *game = new Game(logic);

    game->selectPiece(Coordinate(1,1));

    delete logic;
    delete game;


    auto report1 = GameErrorTypeGenerator::NOT_EMPTY.getErrorReport(*game);
    auto report2 = GameErrorTypeGenerator::REPEATED_COORDINATE.getErrorReport(*game);
    auto report3 = GameErrorTypeGenerator::NOT_PROPERTY.getErrorReport(*game);



    return 0;
}