#ifndef KNIGHT_RULES_HPP
#define KNIGHT_RULES_HPP

#include "MovementRulesGenerator.hpp"
#include <vector>

namespace models::modules::game::pieces::rules
{
    class KnightRules : public MovementRulesGenerator
    {
    public:
        static const KnightRules &getInstance()
        {
            static KnightRules instance;
            return instance;
        }

        void generate(const Piece &piece, std::vector<Coordinate> &movements) const override;

    private:
        KnightRules() = default;
    };
}

#endif
