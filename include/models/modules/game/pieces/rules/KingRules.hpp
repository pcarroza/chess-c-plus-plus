#ifndef KING_RULES_HPP
#define KING_RULES_HPP

#include "MovementRulesGenerator.hpp"

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

        std::list<std::shared_ptr<Coordinate>> generate(const Piece &piece) const override;

    private:
        KingRules() = default;
    };
}

#endif
