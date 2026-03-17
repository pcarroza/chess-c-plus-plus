#ifndef BISHOP_RULES_HPP
#define BISHOP_RULES_HPP

#include "MovementRulesGenerator.hpp"
#include <vector>

namespace models::modules::game::pieces::rules
{
    class BishopRules : public MovementRulesGenerator
    {
    public:
        static const BishopRules &getInstance()
        {
            static BishopRules instance;
            return instance;
        }

        void generate(const Piece &piece, std::vector<Coordinate> &movements) const override;

    private:
        BishopRules() = default;
    };
}

#endif
