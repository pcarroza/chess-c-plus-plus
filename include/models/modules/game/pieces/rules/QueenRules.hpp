#ifndef QUEEN_RULES_HPP
#define QUEEN_RULES_HPP

#include "MovementRulesGenerator.hpp"

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

        std::list<std::shared_ptr<Coordinate>> generate(const Piece &piece) const override;

    private:
        QueenRules() = default;
    };

}
#endif
