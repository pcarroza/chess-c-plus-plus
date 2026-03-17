#ifndef KING_RULES_HPP
#define KING_RULES_HPP

#include "MovementRulesGenerator.hpp"
#include <vector>

namespace models::modules::game::pieces::rules
{
    class KingRules : public MovementRulesGenerator
    {
    public:
        static const KingRules &getInstance()
        {
            static KingRules instance;
            return instance;
        }

        void generate(const Piece &piece, std::vector<Coordinate> &movements) const override;

    private:
        KingRules() = default;
    };
}

#endif
