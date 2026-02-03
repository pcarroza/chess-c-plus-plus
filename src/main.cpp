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

#include "models/modules/game/Player.hpp"
#include <iostream>
#include <cassert>
#include <map>
#include <unordered_map>

using namespace models::modules::game;

void testPlayerBasics()
{
    std::cout << "\n=== Testing Player Basics ===" << std::endl;

    // Test valores
    assert(Player::WHITE.getValue() == 1);
    assert(Player::BLACK.getValue() == -1);
    assert(Player::NONE.getValue() == 0);
    std::cout << "✓ Values are correct" << std::endl;

    // Test nombres
    assert(std::string(Player::WHITE.getName()) == "WHITE");
    assert(std::string(Player::BLACK.getName()) == "BLACK");
    assert(std::string(Player::NONE.getName()) == "NONE");
    std::cout << "✓ Names are correct" << std::endl;

    // Test direcciones
    assert(Player::WHITE.getVectorPlayer() == 1);
    assert(Player::BLACK.getVectorPlayer() == -1);
    std::cout << "✓ Directions are correct" << std::endl;
}

void testPlayerComparison()
{
    std::cout << "\n=== Testing Player Comparison ===" << std::endl;

    // Test igualdad
    Player white1 = Player::WHITE;
    Player white2 = Player::WHITE;
    assert(white1 == white2);
    assert(!(white1 != white2));
    std::cout << "✓ Equality works" << std::endl;

    // Test desigualdad
    assert(Player::WHITE != Player::BLACK);
    assert(Player::WHITE != Player::NONE);
    std::cout << "✓ Inequality works" << std::endl;

    // Test ordenamiento
    assert(Player::BLACK < Player::NONE);
    assert(Player::NONE < Player::WHITE);
    std::cout << "✓ Ordering works" << std::endl;
}

void testPlayerMethods()
{
    std::cout << "\n=== Testing Player Methods ===" << std::endl;

    // Test isValid
    assert(Player::WHITE.isValid());
    assert(Player::BLACK.isValid());
    assert(!Player::NONE.isValid());
    std::cout << "✓ isValid() works" << std::endl;

    // Test isWhite/isBlack
    assert(Player::WHITE.isWhite());
    assert(!Player::WHITE.isBlack());
    assert(Player::BLACK.isBlack());
    assert(!Player::BLACK.isWhite());
    assert(!Player::NONE.isWhite());
    assert(!Player::NONE.isBlack());
    std::cout << "✓ isWhite() and isBlack() work" << std::endl;

    // Test getOpponent
    assert(Player::WHITE.getOpponent() == Player::BLACK);
    assert(Player::BLACK.getOpponent() == Player::WHITE);
    std::cout << "✓ getOpponent() works" << std::endl;

    // Test excepción para NONE
    try
    {
        Player::NONE.getOpponent();
        assert(false && "Should throw exception");
    }
    catch (const std::logic_error &e)
    {
        std::cout << "✓ getOpponent() throws for NONE: " << e.what() << std::endl;
    }
}

void testPlayerFactory()
{
    std::cout << "\n=== Testing Player Factory ===" << std::endl;

    // Test fromValue
    assert(Player::fromValue(1) == Player::WHITE);
    assert(Player::fromValue(-1) == Player::BLACK);
    assert(Player::fromValue(0) == Player::NONE);
    std::cout << "✓ fromValue() works" << std::endl;

    // Test excepción para valor inválido
    try
    {
        Player::fromValue(99);
        assert(false && "Should throw exception");
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "✓ fromValue() throws for invalid value: " << e.what() << std::endl;
    }
}

void testPlayerInContainers()
{
    std::cout << "\n=== Testing Player in Containers ===" << std::endl;

    // Test en std::map (requiere operator<)
    std::map<Player, int> scoreMap;
    scoreMap[Player::WHITE] = 100;
    scoreMap[Player::BLACK] = 95;
    assert(scoreMap[Player::WHITE] == 100);
    assert(scoreMap[Player::BLACK] == 95);
    std::cout << "✓ Works in std::map" << std::endl;

    // Test en std::unordered_map (requiere hash)
    std::unordered_map<Player, std::string, Player::Hash> nameMap;
    nameMap[Player::WHITE] = "Alice";
    nameMap[Player::BLACK] = "Bob";
    assert(nameMap[Player::WHITE] == "Alice");
    assert(nameMap[Player::BLACK] == "Bob");
    std::cout << "✓ Works in std::unordered_map" << std::endl;

    // Test usando std::hash
    std::unordered_map<Player, int> hashMap;
    hashMap[Player::WHITE] = 42;
    hashMap[Player::BLACK] = 24;
    assert(hashMap[Player::WHITE] == 42);
    assert(hashMap[Player::BLACK] == 24);
    std::cout << "✓ Works with std::hash specialization" << std::endl;
}

void testPlayerIteration()
{
    std::cout << "\n=== Testing Player Iteration ===" << std::endl;

    std::cout << "All valid players:" << std::endl;
    for (const auto &player : PLAYERS)
    {
        std::cout << "  - " << player.getName()
                  << " (value: " << player.getValue()
                  << ", direction: " << player.getVectorPlayer() << ")" << std::endl;
    }

    assert(PLAYERS.size() == 2);
    assert(PLAYERS[0] == Player::WHITE);
    assert(PLAYERS[1] == Player::BLACK);
    std::cout << "✓ PLAYERS array is correct" << std::endl;
}

void testRetroCompatibility()
{
    std::cout << "\n=== Testing Retrocompatibility ===" << std::endl;

    // Test función auxiliar getPlayerDirection
    assert(getPlayerDirection(Player::WHITE) == 1);
    assert(getPlayerDirection(Player::BLACK) == -1);
    assert(getPlayerDirection(Player::NONE) == 0);
    std::cout << "✓ getPlayerDirection() function works" << std::endl;
}

int main()
{
    std::cout << "Starting Player class tests..." << std::endl;

    try
    {
        testPlayerBasics();
        testPlayerComparison();
        testPlayerMethods();
        testPlayerFactory();
        testPlayerInContainers();
        testPlayerIteration();
        testRetroCompatibility();

        std::cout << "\n=== ALL TESTS PASSED ✓ ===" << std::endl;
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << "\n✗ TEST FAILED: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}