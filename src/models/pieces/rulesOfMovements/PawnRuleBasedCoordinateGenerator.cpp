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
}
