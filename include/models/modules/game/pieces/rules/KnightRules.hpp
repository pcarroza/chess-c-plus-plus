#ifndef KNIGHT_RULES_HPP
#define KNIGHT_RULES_HPP

#include "MovementRulesGenerator.hpp"

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

        std::list<std::shared_ptr<Coordinate>> generate(const Piece &piece) const override;

    private:
        KnightRules() = default;
    };
}

#endif
