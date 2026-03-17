#ifndef QUEEN_RULES_HPP
#define QUEEN_RULES_HPP

#include "MovementRulesGenerator.hpp"
#include <vector>

namespace models::modules::game::pieces::rules
{
    class QueenRules : public MovementRulesGenerator
    {
    public:
        static const QueenRules &getInstance()
        {
            static QueenRules instance;
            return instance;
        }

        void generate(const Piece &piece, std::vector<Coordinate> &movements) const override;

    private:
        QueenRules() = default;
    };

}
#endif
