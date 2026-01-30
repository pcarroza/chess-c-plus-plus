#include "models/modules/game/Player.hpp"
#include "models/modules/game/pieces/Pawn.hpp"
#include "models/modules/game/pieces/Coordinate.hpp"
#include "models/modules/game/pieces/rulesOfMovements/MovementRulesBaseGeneratorFacade.hpp"
#include "models/modules/game/pieces/specialRuleMovements/EnPassantPawnSpecialRuleGenerator.hpp"
#include "models/modules/game/pieces/PieceVisitor.hpp"

using models::modules::game::pieces::rulesOfMovements::MovementRulesBaseGeneratorFacade;
using models::modules::game::pieces::specialRuleMovements::EnPassantPawnSpecialRuleGenerator;
using models::modules::game::pieces::specialRuleMovements::SpecialMovesRulesGenerator;

namespace models::modules::game::pieces
{
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
        //  hay error en la logica de negocio
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
            vulnerablePawn = false;
            notifyDeletedEnPassantPawn(this);
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
        return not isSquareOccupied(*getForwardOne());
    }

    bool Pawn::canAdvanceTwo() const
    {
        return isInitialState() and not isSquareOccupied(*getForwardOne()) and not isSquareOccupied(*getForwardTwo());
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
        const int singgleStep = 1;
        const int direction = singgleStep * getPlayerDirection(player);
        return std::shared_ptr<Coordinate>(getDisplacedBy(Coordinate(direction, 0)));
    }

    std::shared_ptr<Coordinate> Pawn::getForwardTwo() const
    {
        const int doubleStep = 2;
        const int direction = doubleStep * getPlayerDirection(player);
        return std::shared_ptr<Coordinate>(getDisplacedBy(Coordinate(direction, 0)));
    }

    std::shared_ptr<Coordinate> Pawn::getDiagonalLeft() const
    {
        const int leftDiagonalOffset = -1;
        return std::shared_ptr<Coordinate>(getDisplacedBy(Coordinate(getPlayerDirection(player), leftDiagonalOffset)));
    }

    std::shared_ptr<Coordinate> Pawn::getDiagonalRight() const
    {
        const int rightDiagonalOffset = 1;
        return std::shared_ptr<Coordinate>(getDisplacedBy(Coordinate(getPlayerDirection(player), rightDiagonalOffset)));
    }

    void Pawn::accept(PieceVisitor &pieceVisitor)
    {
        pieceVisitor.visit(*this);
    }

    std::string Pawn::toString() const
    {
        std::string colorStr = player == Player::WHITE ? "White" : "Black";
        std::string stateStr = isInitialState() ? "Initial" : "Moved";
        std::string promotedStr = isItPromoted ? "Promoted" : "Normal";
        return "Pawn(" + colorStr + ", " + stateStr + ", " + promotedStr + ")";
    }
}
