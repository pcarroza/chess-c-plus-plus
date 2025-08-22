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
        Player player = getPlayer();

        assert(player != Player::NONE && "Error. The 'Player' should not be 'Player::NONE'");

        possibleMoves.clear();

        possibleMoves.splice(possibleMoves.end(), calculateForwardMoves(player));

        possibleMoves.splice(possibleMoves.end(), calculateDiagonalCaptureMoves(player));

        possibleMoves.remove_if([](const std::shared_ptr<Coordinate> &coordinate)
                                { return !ValidatorLimitsBoard::getInstance().isWithinLimits(*coordinate); });
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
