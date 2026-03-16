#ifndef BISHOP_RULES_HPP
#define BISHOP_RULES_HPP

#include "MovementRulesGenerator.hpp"

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

        std::list<std::shared_ptr<Coordinate>> generate(const Piece &piece) const override;

    private:
        BishopRules() = default;
    };
}

#endif
