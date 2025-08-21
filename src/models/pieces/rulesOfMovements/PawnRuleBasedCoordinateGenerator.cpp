#include "models/pieces/rulesOfMovements/PawnRuleBasedCoordinateGenerator.hpp"

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
        return Color::WHITE;
    }
}
