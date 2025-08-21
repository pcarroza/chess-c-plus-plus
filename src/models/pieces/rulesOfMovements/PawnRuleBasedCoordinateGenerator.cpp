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
        Color color = getColor();

        assert(color != Color::NONE && "Error. The 'Color' should not be 'NONE'");

        possibleMoves.clear();

        possibleMoves = calculateForwardMoves(color);
    }

    std::list<std::shared_ptr<Coordinate>> PawnRuleBasedCoordinateGenerator::calculateForwardMoves(Color color)
    {
        return std::list<std::shared_ptr<Coordinate>>();
    }

    void PawnRuleBasedCoordinateGenerator::addCaptureMoveIfValid(Coordinate coordinate)
    {
    }

    Color PawnRuleBasedCoordinateGenerator::getColor()
    {
        if (pawn->isWhite())
        {
            return Color::WHITE;
        }
        if (pawn->isBlack())
        {
            return Color::BLACK;
        }
        return Color::NONE;
    }
}
