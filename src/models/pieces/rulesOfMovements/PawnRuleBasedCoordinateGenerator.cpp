#include "models/pieces/rulesOfMovements/PawnRuleBasedCoordinateGenerator.hpp"

#include <cassert>

namespace models::pieces::rulesOfMovements
{
    PawnRuleBasedCoordinateGenerator::PawnRuleBasedCoordinateGenerator(Piece *piece)
    {
        set(piece);
    }

    void PawnRuleBasedCoordinateGenerator::set(Piece *piece)
    {
        pawn = dynamic_cast<Pawn *>(piece);
    }

    void PawnRuleBasedCoordinateGenerator::generate()
    {
        Player color = getPlayer();

        assert(color != Player::NONE && "Error. The 'Color' should not be 'NONE'");

        possibleMoves.clear();

        possibleMoves = calculateForwardMoves(color);
    }

    std::list<std::shared_ptr<Coordinate>> PawnRuleBasedCoordinateGenerator::calculateForwardMoves(Player color)
    {
        return std::list<std::shared_ptr<Coordinate>>();
    }

    void PawnRuleBasedCoordinateGenerator::calculateDiagonalCaptureMoves(Player player)
    {
    }

    Player PawnRuleBasedCoordinateGenerator::getPlayer()
    {
        if (pawn->isWhite())
        {
            return Player::WHITE;
        }
        if (pawn->isBlack())
        {
            return Player::BLACK;
        }
        return Player::NONE;
    }
}
