# ===========================================
# CMakeLists para Proyecto C++ Grande
# ===========================================

# Versión mínima de CMake y definición del proyecto
cmake_minimum_required(VERSION 3.14)
project(Chess VERSION 0.0.1 LANGUAGES CXX)

# ===========================================
# Configuración del Compilador y Build
# ===========================================

# Establecer el estándar C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Flags de compilación (warnings)
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra)
endif()

# Directorio de salida para los ejecutables
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# ===========================================
# Archivos del Proyecto y Biblioteca Principal
# ===========================================

# Encontrar todos los archivos fuente, excluyendo main.cpp
file(GLOB_RECURSE LIB_SOURCES "src/*.cpp")
list(FILTER LIB_SOURCES EXCLUDE REGEX ".*/main\\.cpp$")

# Crear la biblioteca estática con la lógica del juego
add_library(chess_lib STATIC ${LIB_SOURCES})

# Hacer que el directorio 'include' esté disponible para quienes usen esta biblioteca
target_include_directories(chess_lib PUBLIC include)

# ===========================================
# Ejecutable Principal
# ===========================================

# Crear el ejecutable principal usando main.cpp
add_executable(chess src/main.cpp)

# Enlazar el ejecutable con la biblioteca de lógica
target_link_libraries(chess PRIVATE chess_lib)

# ===========================================
# Configuración de Google Test
# ===========================================

# Habilitar los tests
enable_testing()

# Incluir FetchContent para dependencias externas
include(FetchContent)

# Declarar la dependencia de Google Test
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG      release-1.12.1 # Usando una etiqueta más estable
)

# Hacer que Google Test esté disponible (lo descarga y configura)
FetchContent_MakeAvailable(googletest)

# Encontrar todos los archivos fuente de los tests
file(GLOB_RECURSE TEST_SOURCES "tests/*.cpp")

# Crear el ejecutable para los tests
add_executable(run_tests ${TEST_SOURCES})

# Vincular las librerías de Google Test y la lógica del juego al ejecutable de tests
target_link_libraries(run_tests PRIVATE GTest::gtest_main chess_lib)

# Añadir el test al runner de CTest
add_test(NAME AllTests COMMAND run_tests)

# ===========================================
# Mensajes informativos
# ===========================================

message(STATUS "Proyecto: ${PROJECT_NAME}")
message(STATUS "Versión: ${PROJECT_VERSION}")
message(STATUS "Directorio de Build: ${CMAKE_BINARY_DIR}")