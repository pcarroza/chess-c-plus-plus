#include "models/pieces/Pawn.hpp"
#include "models/pieces/rulesOfMovements/MovementRulesBaseGeneratorFacade.hpp"
#include "models/pieces/specialRuleMovements/EnPassantPawnSpecialRuleGenerator.hpp"
#include "Pawn.hpp"

using models::pieces::rulesOfMovements::MovementRulesBaseGeneratorFacade;
using models::pieces::specialRuleMovements::EnPassantPawnSpecialRuleGenerator;

Pawn::Pawn(Coordinate *coordinate, Player color)
    : Piece(coordinate, color),
      initialState(true),
      isItPromoted(false),
      vulnerablePawn(false),
      specialGenerator(new EnPassantPawnSpecialRuleGenerator(this))
{
    basedGenerator = MovementRulesBaseGeneratorFacade::createPawnRuleBasedCoordinateGenerator(this);
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
        addPassantPawn(this);
    }
    else
    {
        vulnerablePawn = false;
    }

    if (isThePawnPromoted(*target))
    {
        changeToPromoted();
    }

    Piece::put(target);
}

bool Pawn::isInitialState()
{
    return false;
}

void Pawn::close()
{
    initialState = false;
}

bool Pawn::inStep(Coordinate &target)
{
    return false;
}

bool Pawn::isMovementValid(const Coordinate &target)
{
    return Piece::isMovementValid(target) || specialGenerator->isMovementValid(target);
}

void Pawn::generateMovements()
{
    Piece::generateMovements();
}

bool Pawn::isThePawnPromoted()
{
    return false;
}

bool Pawn::isThePawnPromoted(Coordinate &coordinate)
{
    return false;
}

void Pawn::changeToPromoted()
{
    isItPromoted = true;
}

bool Pawn::isWhite()
{
    return color == Player::WHITE;
}

bool Pawn::isBlack()
{
    return color == Player::BLACK;
}

bool Pawn::isVulnerablePawn()
{
    return vulnerablePawn;
}

bool Pawn::canAdvanceOne() const
{
    auto forward = getForwardOne();
    return !isBoxOccupied(*forward);
}

bool Pawn::canAdvanceTwo() const
{
    if (!isInitialState())
    {
        return false;
    }
    auto forwardOne = getForwardTwo();
    if (!isBoxOccupied(*forwardOne))
    {
        return false;
    }
    auto forwardTwo = getForwardOne();
    return !isBoxOccupied(*forwardTwo);
}

bool Pawn::canCaptureLeft() const
{
    auto left = getDiagonalLeft();
    return isItEnemy(*left);
}

bool Pawn::canCaptureRight() const
{
    auto right = getDiagonalRight();
    return isItEnemy(*right);
}

bool Pawn::isItPromoted()
{
    return false;
}

std::shared_ptr<Coordinate> Pawn::getForwardOne() const
{
    return std::shared_ptr<Coordinate>();
}

std::shared_ptr<Coordinate> Pawn::getForwardTwo() const
{
    return std::shared_ptr<Coordinate>();
}

std::shared_ptr<Coordinate> Pawn::getDiagonalLeft() const
{
    return std::shared_ptr<Coordinate>();
}

std::shared_ptr<Coordinate> Pawn::getDiagonalRight() const
{
    return std::shared_ptr<Coordinate>();
}

std::string Pawn::toString() const
{
    return "Pawn()";
}
