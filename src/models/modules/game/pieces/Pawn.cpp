#include "models/modules/game/pieces/Pawn.hpp"
#include "models/modules/game/pieces/rules/MovementRulesFacade.hpp"

using models::modules::game::pieces::special::InStepSpecialRuleGenerator;
using models::modules::game::pieces::special::SpecialMovesRulesGenerator;

namespace models::modules::game::pieces
{
    Pawn::Pawn(Coordinate coordinate, Player player)
        : Piece(coordinate, player),
          initialState(true),
          isItPromoted(false),
          vulnerablePawn(false),
          specialGenerator(this)
    {
        movementRulesGenerator = &rules::MovementRulesFacade::getPawnRules();
    }

    Pawn::~Pawn()
    {
    }

    void Pawn::put(Coordinate target)
    {
        if (isInitialState())
        {
            close();
        }
        if (inStep(target))
        {
            vulnerablePawn = true;
            notifyPawnInStep(this);
        }
        else
        {
            vulnerablePawn = false;
            notifyDeletedPawnInStep(this);
        }
        if (isThePawnPromoted(target))
        {
            changeToPromoted();
        }
        Piece::put(target);
    }

    void Pawn::close()
    {
        initialState = false;
    }

    bool Pawn::inStep(Coordinate target)
    {
        const int doubleStep = 2;
        Coordinate displaced = getDisplacedBy(Coordinate(doubleStep, 0));
        return displaced == target;
    }

    bool Pawn::isThePawnPromoted(Coordinate coordinate)
    {
        return ValidatorLimitsBoard::getInstance().isPieceEndBoardAt(coordinate);
    }

    void Pawn::changeToPromoted()
    {
        isItPromoted = true;
    }

    bool Pawn::canAdvanceOne() const
    {
        return not isSquareOccupied(getForwardOne());
    }

    bool Pawn::canAdvanceTwo() const
    {
        return isInitialState() and not isSquareOccupied(getForwardOne()) and not isSquareOccupied(getForwardTwo());
    }

    bool Pawn::canCaptureLeft() const
    {
        return isEnemy(getDiagonalLeft());
    }

    bool Pawn::canCaptureRight() const
    {
        return isEnemy(getDiagonalRight());
    }

    Coordinate Pawn::getForwardOne() const
    {
        const int singgleStep = 1;
        const int direction = singgleStep * Piece::getVectorPlayer();
        return getDisplacedBy(Coordinate(direction, 0));
    }

    Coordinate Pawn::getForwardTwo() const
    {
        const int doubleStep = 2;
        const int direction = doubleStep * getPlayerDirection(player);
        return getDisplacedBy(Coordinate(direction, 0));
    }

    Coordinate Pawn::getDiagonalLeft() const
    {
        const int leftDiagonalOffset = -1;
        return getDisplacedBy(Coordinate(getPlayerDirection(player), leftDiagonalOffset));
    }

    Coordinate Pawn::getDiagonalRight() const
    {
        const int rightDiagonalOffset = 1;
        return getDisplacedBy(Coordinate(getPlayerDirection(player), rightDiagonalOffset));
    }

    std::vector<Coordinate> Pawn::getInStepDiagonals() const
    {
        return std::vector<Coordinate>();
    }

    bool Pawn::isMovementValid(const Coordinate &target) const
    {
        return Piece::isMovementValid(target) || specialGenerator.isMovementValid(target);
    }

    bool Pawn::isVulnerablePawn() const
    {
        return vulnerablePawn;
    }

    bool Pawn::isPromoted() const
    {
        return isItPromoted;
    }

    bool Pawn::isInitialState() const
    {
        return initialState;
    }

    bool Pawn::isPawn() const
    {
        return true;
    }

    PieceSymbol Pawn::getSymbol() const
    {
        return PieceSymbol::PAWN;
    }
}
