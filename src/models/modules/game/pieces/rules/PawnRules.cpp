#include "models/modules/game/pieces/rules/PawnRules.hpp"
#include "models/modules/game/pieces/Pawn.hpp"
#include "common/validators/ValidatorLimitsBoard.hpp"
#include "models/modules/game/pieces/rules/MovementState.hpp"
#include <memory>
#include <vector>

using common::validators::ValidatorLimitsBoard;

namespace models::modules::game::pieces::rules
{
    namespace
    {
        class AdvanceOneMovementState : public MovementState
        {
        public:
            void execute(const Pawn &pawn, std::vector<Coordinate> &movements) const override
            {
                if (pawn.canAdvanceOne())
                {
                    Coordinate target = pawn.getForwardOne();
                    if (ValidatorLimitsBoard::getInstance().isWithinLimits(target))
                        movements.push_back(target);
                }
            }
        };

        class AdvanceTwoMovementState : public MovementState
        {
        public:
            void execute(const Pawn &pawn, std::vector<Coordinate> &movements) const override
            {
                if (pawn.canAdvanceTwo())
                {
                    Coordinate target = pawn.getForwardTwo();
                    if (ValidatorLimitsBoard::getInstance().isWithinLimits(target))
                        movements.push_back(target);
                }
            }
        };

        class CaptureLeftMovementState : public MovementState
        {
        public:
            void execute(const Pawn &pawn, std::vector<Coordinate> &movements) const override
            {
                if (pawn.canCaptureLeft())
                {
                    Coordinate target = pawn.getDiagonalLeft();
                    if (ValidatorLimitsBoard::getInstance().isWithinLimits(target))
                        movements.push_back(target);
                }
            }
        };

        class CaptureRightMovementState : public MovementState
        {
        public:
            void execute(const Pawn &pawn, std::vector<Coordinate> &movements) const override
            {
                if (pawn.canCaptureRight())
                {
                    Coordinate target = pawn.getDiagonalRight();
                    if (ValidatorLimitsBoard::getInstance().isWithinLimits(target))
                        movements.push_back(target);
                }
            }
        };
    }

    void PawnRules::generate(const Piece &piece, std::vector<Coordinate> &movements) const
    {
        const Pawn &pawn = dynamic_cast<const Pawn &>(piece);

        std::vector<std::unique_ptr<MovementState>> states;
        states.push_back(std::make_unique<AdvanceOneMovementState>());
        states.push_back(std::make_unique<AdvanceTwoMovementState>());
        states.push_back(std::make_unique<CaptureLeftMovementState>());
        states.push_back(std::make_unique<CaptureRightMovementState>());

        for (const auto &state : states)
        {
            state->execute(pawn, movements);
        }
    }
}
