#include <benchmark/benchmark.h>
#include "models/modules/game/Board.hpp"
#include "models/modules/game/pieces/Coordinate.hpp"
#include <vector>

using namespace models::modules::game;
using namespace models::modules::game::pieces;

// 1. Benchmark de búsqueda: ¿Qué tan rápido detectamos si una casilla está vacía?
static void BM_Board_SquareLookup(benchmark::State& state) {
    Board board;
    Coordinate coordinate(4, 4); // Casilla central usualmente vacía al inicio
    for (auto _ : state) {
        benchmark::DoNotOptimize(board.isSquareEmpty(coordinate));
    }
}
BENCHMARK(BM_Board_SquareLookup);

// 2. Benchmark de Selección: Búsqueda + Generación de movimientos
static void BM_Board_SelectPiece(benchmark::State& state) {
    Board board;
    Coordinate coordinate(2, 1); // Un peón blanco inicial (fila 2, col 1)
    for (auto _ : state) {
        board.selectPiece(coordinate);
        benchmark::DoNotOptimize(board.getValidMovements());
        board.clearSelectedPiece();
    }
}
BENCHMARK(BM_Board_SelectPiece);

// 3. Benchmark de inicialización completa
static void BM_Board_Creation(benchmark::State& state) {
    for (auto _ : state) {
        Board board;
        benchmark::DoNotOptimize(board);
    }
}
BENCHMARK(BM_Board_Creation);

// 4. Benchmark de cambio de turno (operación muy frecuente)
static void BM_Board_ChangeTurn(benchmark::State& state) {
    Board board;
    for (auto _ : state) {
        board.changeTurn();
    }
}
BENCHMARK(BM_Board_ChangeTurn);

BENCHMARK_MAIN();
