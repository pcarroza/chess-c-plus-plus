#include <benchmark/benchmark.h>
#include "models/modules/game/Board.hpp"
#include "models/modules/game/pieces/Coordinate.hpp"
#include "models/modules/game/Player.hpp"
#include "models/modules/game/pieces/Pawn.hpp"
#include "models/modules/game/pieces/Knight.hpp"
#include "models/modules/game/pieces/Bishop.hpp"
#include "models/modules/game/pieces/Rook.hpp"
#include "models/modules/game/pieces/Queen.hpp"
#include "models/modules/game/pieces/King.hpp"

using namespace models::modules::game;
using namespace models::modules::game::pieces;

template <typename T>
static void BM_PieceMovementGeneration(benchmark::State &state)
{
    Board board;
    // Colocamos la pieza en el centro (4,4) para que tenga el máximo de movimientos posibles
    T piece(Coordinate(4, 4), Player::WHITE);
    piece.subscribe(&board);

    for (auto _ : state)
    {
        piece.generateMovements();
        benchmark::DoNotOptimize(piece.getValidMovements());
    }
}

// Registro de Benchmarks
BENCHMARK_TEMPLATE(BM_PieceMovementGeneration, King)->Name("BM_KingMoveGen");
BENCHMARK_TEMPLATE(BM_PieceMovementGeneration, Queen)->Name("BM_QueenMoveGen");
BENCHMARK_TEMPLATE(BM_PieceMovementGeneration, Rook)->Name("BM_RookMoveGen");
BENCHMARK_TEMPLATE(BM_PieceMovementGeneration, Bishop)->Name("BM_BishopMoveGen");
BENCHMARK_TEMPLATE(BM_PieceMovementGeneration, Knight)->Name("BM_KnightMoveGen");
BENCHMARK_TEMPLATE(BM_PieceMovementGeneration, Pawn)->Name("BM_PawnMoveGen");

BENCHMARK_MAIN();
