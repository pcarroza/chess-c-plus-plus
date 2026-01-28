#ifndef SPECIAL_MOVEMENTS_CONTROLLER_VISITOR_HPP
#define SPECIAL_MOVEMENTS_CONTROLLER_VISITOR_HPP

namespace controllers::modules::game
{
    class EnPassantPawnController;
    class PromotionPawnController;
    class CastlingMovesController;
}

namespace controllers::modules::game
{
    class SpecialMovementsControllerVisitor
    {
    public:
        virtual ~SpecialMovementsControllerVisitor() = default;

        virtual void visit(EnPassantPawnController *enPassantPawnController) = 0;

        virtual void visit(PromotionPawnController *promotionPawnController) = 0;

        virtual void visit(CastlingMovesController *castlingMovesController) = 0;
    };
}

#endif
