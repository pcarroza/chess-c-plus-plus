#pragma once

#include "BishopRules.hpp"
#include "KingRules.hpp"
#include "KnightRules.hpp"
#include "PawnRules.hpp"
#include "QueenRules.hpp"
#include "RookRules.hpp"

namespace models::modules::game::pieces::rules
{
    class MovementRulesFacade
    {
    public:
        static const MovementRulesGenerator &getBishopRules()
        {
            return BishopRules::getInstance();
        }

        static const MovementRulesGenerator &getKingRules()
        {
            return KingRules::getInstance();
        }

        static const MovementRulesGenerator &getKnightRules()
        {
            return KnightRules::getInstance();
        }

        static const MovementRulesGenerator &getPawnRules()
        {
            return PawnRules::getInstance();
        }

        static const MovementRulesGenerator &getQueenRules()
        {
            return QueenRules::getInstance();
        }

        static const MovementRulesGenerator &getRookRules()
        {
            return RookRules::getInstance();
        }
    };
}
