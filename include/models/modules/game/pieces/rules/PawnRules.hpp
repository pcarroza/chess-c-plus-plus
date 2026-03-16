#ifndef PAWN_RULES_HPP
#define PAWN_RULES_HPP

#include "MovementRulesGenerator.hpp"

namespace models::modules::game::pieces::rules
{
    class PawnRules : public MovementRulesGenerator
    {
    public:
        static const PawnRules &getInstance()
        {
            static PawnRules instance;
            return instance;
        }

        std::list<std::shared_ptr<Coordinate>> generate(const Piece &piece) const override;

    private:
        PawnRules() = default;
    };

}
#endif
