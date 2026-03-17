#ifndef ROOK_RULES_HPP
#define ROOK_RULES_HPP

#include "MovementRulesGenerator.hpp"
#include <vector>

namespace models::modules::game::pieces::rules
{
    class RookRules : public MovementRulesGenerator
    {
    public:
        static const RookRules &getInstance()
        {
            static RookRules instance;
            return instance;
        }

        void generate(const Piece &piece, std::vector<Coordinate> &movements) const override;

    private:
        RookRules() = default;
    };
}

#endif
