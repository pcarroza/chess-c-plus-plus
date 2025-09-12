#include "models/Player.hpp"
#include "models/pieces/Pawn.hpp"
#include "models/pieces/Coordinate.hpp"
#include "models/pieces/rulesOfMovements/MovementRulesBaseGeneratorFacade.hpp"
#include "models/pieces/specialRuleMovements/EnPassantPawnSpecialRuleGenerator.hpp"

using models::pieces::rulesOfMovements::MovementRulesBaseGeneratorFacade;
using models::pieces::specialRuleMovements::EnPassantPawnSpecialRuleGenerator;

namespace
{
  
}

Pawn::Pawn(Coordinate *coordinate, Player color)
    : Piece(coordinate, color),
      initialState(true),
      isItPromoted(false),
      vulnerablePawn(false),
      specialGenerator(new EnPassantPawnSpecialRuleGenerator(this))
{
    basedGenerator = MovementRulesBaseGeneratorFacade::createPawnRuleBasedCoordinateGenerator(this);
}

Pawn::~Pawn()
{
    delete specialGenerator;
}

void Pawn::put(Coordinate *target)
{
    if (isInitialState())
    {
        close();
    }

    if (inStep(*target))
    {
        vulnerablePawn = true;
        notifyEnPassantPawn(this);
    }
    else
    {
        notifyDeletedEnPassantPawn(this);
        vulnerablePawn = false;
    }

    if (isThePawnPromoted(*target))
    {
        changeToPromoted();
    }

    Piece::put(target);
}

bool Pawn::isMovementValid(const Coordinate &target)
{
    return Piece::isMovementValid(target) || specialGenerator->isMovementValid(target);
}

void Pawn::generateMovements()
{
    Piece::generateMovements();
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

void Pawn::close()
{
    initialState = false;
}

bool Pawn::inStep(Coordinate &target)
{
    const int doubleStep = 2;
    Coordinate *displaced = getDisplacedBy(Coordinate(doubleStep, 0));
    bool isEquals = *displaced == target;
    delete displaced;
    return isEquals;
}

bool Pawn::isThePawnPromoted(Coordinate &coordinate)
{
    return ValidatorLimitsBoard::getInstance().isPieceEndBoardAt(coordinate);
}

void Pawn::changeToPromoted()
{
    isItPromoted = true;
}

bool Pawn::canAdvanceOne() const
{
    return !isSquareOccupied(*getForwardOne());
}

bool Pawn::canAdvanceTwo() const
{
    return isInitialState() && !isSquareOccupied(*getForwardOne()) && !isSquareOccupied(*getForwardTwo());
}

bool Pawn::canCaptureLeft() const
{
    return isEnemy(*getDiagonalLeft());
}

bool Pawn::canCaptureRight() const
{
    return isEnemy(*getDiagonalRight());
}

std::shared_ptr<Coordinate> Pawn::getForwardOne() const
{
    const int SINGLE_STEP = 1;
    const int singleStep = SINGLE_STEP * getPlayerDirection(player);
    return std::shared_ptr<Coordinate>(getDisplacedBy(Coordinate(singleStep, 0)));
}

std::shared_ptr<Coordinate> Pawn::getForwardTwo() const
{
    const int DOUBLE_STEP = 2;
    const int doubleStep = DOUBLE_STEP * getPlayerDirection(player);
    return std::shared_ptr<Coordinate>(getDisplacedBy(Coordinate(doubleStep, 0)));
}

std::shared_ptr<Coordinate> Pawn::getDiagonalLeft() const
{
    const int LEFT_DIAGONAL_OFFSET = -1;
    return std::shared_ptr<Coordinate>(getDisplacedBy(Coordinate(getPlayerDirection(player), LEFT_DIAGONAL_OFFSET)));
}

std::shared_ptr<Coordinate> Pawn::getDiagonalRight() const
{
    const int RIGHT_DIAGONAL_OFFSET = 1;
    return std::shared_ptr<Coordinate>(getDisplacedBy(Coordinate(getPlayerDirection(player), RIGHT_DIAGONAL_OFFSET)));
}

void Pawn::accept(PieceVisitor &visitor)
{
    visitor.visit(*this);
}

std::string Pawn::toString() const
{
    std::string colorStr = player == Player::WHITE ? "White" : "Black";
    std::string stateStr = isInitialState() ? "Initial" : "Moved";
    std::string promotedStr = isItPromoted ? "Promoted" : "Normal";
    return "Pawn(" + colorStr + ", " + stateStr + ", " + promotedStr + ")";
}