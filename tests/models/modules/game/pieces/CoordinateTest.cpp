#include <gtest/gtest.h>
#include "models/modules/game/pieces/Coordinate.hpp"

// Usar el namespace para hacer el código más limpio
using models::modules::game::pieces::Coordinate;

// Test para el constructor y los getters
TEST(CoordinateTest, ConstructorAndGetters) {
    Coordinate coord(3, 5);
    EXPECT_EQ(coord.getRow(), 3);
    EXPECT_EQ(coord.getColumn(), 5);
}

// Test para el constructor por defecto
TEST(CoordinateTest, DefaultConstructorInitializesToZero) {
    Coordinate coord;
    EXPECT_EQ(coord.getRow(), 0);
    EXPECT_EQ(coord.getColumn(), 0);
}

// Test para el operador de igualdad
TEST(CoordinateTest, EqualityOperator) {
    Coordinate coord1(4, 2);
    Coordinate coord2(4, 2);
    Coordinate coord3(2, 4);
    Coordinate coord4(4, 3);

    EXPECT_TRUE(coord1 == coord2);
    EXPECT_FALSE(coord1 == coord3);
    EXPECT_FALSE(coord1 == coord4);
}

// Test para el método getDisplacedBy con un solo entero
TEST(CoordinateTest, GetDisplacedByInt) {
    Coordinate coord(3, 4);
    Coordinate* displaced = coord.getDisplacedBy(2);
    Coordinate expected(5, 6);
    
    ASSERT_NE(displaced, nullptr);
    EXPECT_TRUE(*displaced == expected);
    
    delete displaced;
}

// Test para el método getDisplacedBy con otro Coordinate
TEST(CoordinateTest, GetDisplacedByCoordinate) {
    Coordinate coord(3, 4);
    Coordinate displacement(1, -2);
    Coordinate* displaced = coord.getDisplacedBy(displacement);
    Coordinate expected(4, 2);

    ASSERT_NE(displaced, nullptr);
    EXPECT_TRUE(*displaced == expected);

    delete displaced;
}

// Test para el método scaleBy
TEST(CoordinateTest, ScaleBy) {
    Coordinate coord(2, 3);
    Coordinate factor(-2, 3);
    Coordinate* scaled = coord.scaleBy(factor);
    Coordinate expected(-4, 9);
    
    ASSERT_NE(scaled, nullptr);
    EXPECT_TRUE(*scaled == expected);
    
    delete scaled;
}

// Test para getDisplacedBy con vector (simula el comportamiento de scaleBy)
TEST(CoordinateTest, GetDisplacedByWithVector) {
    Coordinate coord(2, 3); // Representa un factor
    Coordinate displacement(4, 5); // Representa la coordenada a escalar
    // La implementación actual de getDisplacedBy(coord, vector) llama a scaleBy(vector)
    // en la coordenada `displacement`. Es un poco confuso, pero testeamos la implementación actual.
    Coordinate* result = displacement.getDisplacedBy(Coordinate(), coord); // La primera coord no se usa
    Coordinate expected(8, 15); // 4*2, 5*3
    
    ASSERT_NE(result, nullptr);
    EXPECT_TRUE(*result == expected);
    
    delete result;
}

// Test con coordenadas negativas
TEST(CoordinateTest, NegativeCoordinates) {
    Coordinate coord(-1, -8);
    EXPECT_EQ(coord.getRow(), -1);
    EXPECT_EQ(coord.getColumn(), -8);

    Coordinate displacement(2, -3);
    Coordinate* displaced = coord.getDisplacedBy(displacement);
    Coordinate expected(1, -11);

    ASSERT_NE(displaced, nullptr);
    EXPECT_TRUE(*displaced == expected);

    delete displaced;
}
