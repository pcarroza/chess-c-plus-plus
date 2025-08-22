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

    std::list<std::shared_ptr<Coordinate>> PawnRuleBasedCoordinateGenerator::calculateForwardMoves(Player player)
    {
        auto coordinateFirstBox = pawn->getDisplacedBy(Coordinate(getPlayerValue(player), 0));
        if (pawn->isBoxOccupied(*coordinateFirstBox))
        {
            return {};
        }
        const int singleStep = 1;
        const int doubleStep = 2;
        int maximumAdvance = pawn->isInitialState() ? doubleStep : singleStep;
        if (maximumAdvance == singleStep)
        {
            return {std::shared_ptr<Coordinate>(coordinateFirstBox)};
        }
        auto coordinateSecondBox = pawn->getDisplacedBy(Coordinate(doubleStep * getPlayerValue(player), 0));
        if (pawn->isBoxOccupied(*coordinateSecondBox))
        {
            return {std::shared_ptr<Coordinate>(coordinateFirstBox)};
        }
        return {std::shared_ptr<Coordinate>(coordinateFirstBox), std::shared_ptr<Coordinate>(coordinateSecondBox)};
    }

    std::list<std::shared_ptr<Coordinate>> PawnRuleBasedCoordinateGenerator::calculateDiagonalCaptureMoves(Player player)
    {
        std::list<std::shared_ptr<Coordinate>> captures;

        const int letfDiagonal = -1;
        const int rightDiagonal = 1;

        std::vector<int> offsets = {letfDiagonal, rightDiagonal};

        for (int offset : offsets)
        {
            auto coordinate = pawn->getDisplacedBy(Coordinate(getPlayerValue(player), 1));
            if (pawn->isItEnemy(*coordinate))
            {
                captures.push_back(std::shared_ptr<Coordinate>(coordinate));
            }
        }

        return captures;
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
