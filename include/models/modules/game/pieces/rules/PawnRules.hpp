#ifndef PAWN_RULES_HPP
#define PAWN_RULES_HPP

#include "MovementRulesGenerator.hpp"
#include <vector>

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

        void generate(const Piece &piece, std::vector<Coordinate> &movements) const override;

    private:
        PawnRules() = default;
    };

}
#endif
