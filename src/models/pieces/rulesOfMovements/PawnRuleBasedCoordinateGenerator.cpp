#include "models/pieces/rulesOfMovements/PawnRuleBasedCoordinateGenerator.hpp"

#include <vector>
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

        using CalculateFn = std::list<std::shared_ptr<Coordinate>> (PawnRuleBasedCoordinateGenerator::*)(Player);

        std::vector<CalculateFn> calculators = {
            &PawnRuleBasedCoordinateGenerator::calculateForwardMoves,
            &PawnRuleBasedCoordinateGenerator::calculateDiagonalCaptureMoves};

        for (auto fn : calculators)
        {
            auto moves = (this->*fn)(color);
            possibleMoves.splice(possibleMoves.end(), moves);
        }

        
    }

    std::list<std::shared_ptr<Coordinate>> PawnRuleBasedCoordinateGenerator::calculateForwardMoves(Player color)
    {
        return std::list<std::shared_ptr<Coordinate>>();
    }

    std::list<std::shared_ptr<Coordinate>> PawnRuleBasedCoordinateGenerator::calculateDiagonalCaptureMoves(Player player)
    {
        return std::list<std::shared_ptr<Coordinate>>();
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
