# ===========================================
# Makefile Profesional para Proyecto C++ Grande
# ===========================================

# Compilador y configuración
CXX      := g++
CXXSTD   := -std=c++17
WARNINGS := -Wall -Wextra
INCLUDES := -Iinclude
VERSION  := 0.0.1

# Flags de compilación
CXXFLAGS_DEBUG   := $(CXXSTD) $(WARNINGS) $(INCLUDES) -g -O0
CXXFLAGS_RELEASE := $(CXXSTD) $(WARNINGS) $(INCLUDES) -O2

# Directorios
SRC_DIR        := src
BIN_DIR        := bin
BUILD_DIR      := build
DEPS_DIR       := $(BUILD_DIR)/deps

# Configuración de build
BUILD ?= debug
ifeq ($(BUILD),debug)
  TARGET  := $(BIN_DIR)/chess
  CXXFLAGS := $(CXXFLAGS_DEBUG)
else ifeq ($(BUILD),release)
  TARGET  := $(BIN_DIR)/chess-$(VERSION)-release
  CXXFLAGS := $(CXXFLAGS_RELEASE)
else
  $(error Valor de BUILD inválido. Usa 'debug' o 'release')
endif

# Colores
COLOR_CMP = \033[1;34m
COLOR_LNK = \033[1;32m
COLOR_RST = \033[0m

# Archivos fuente, objetos y dependencias
SRCS := $(shell find $(SRC_DIR) -name "*.cpp")
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/$(BUILD)/%.o,$(SRCS))
DEPS := $(patsubst $(SRC_DIR)/%.cpp,$(DEPS_DIR)/$(BUILD)/%.d,$(SRCS))

# Regla por defecto
all: $(TARGET)

# Enlazado
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	@echo "$(COLOR_LNK)[LINK]$(COLOR_RST) $@"
	$(CXX) $(CXXFLAGS) -o $@ $^
ifeq ($(BUILD),release)
	strip $@
endif

# Compilación con dependencias
$(BUILD_DIR)/$(BUILD)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@) $(dir $(patsubst $(BUILD_DIR)/$(BUILD)/%.o,$(DEPS_DIR)/$(BUILD)/%.d,$@))
	@echo "$(COLOR_CMP)[C++]$(COLOR_RST) $<"
	$(CXX) $(CXXFLAGS) -MMD -MP -MF $(patsubst $(BUILD_DIR)/$(BUILD)/%.o,$(DEPS_DIR)/$(BUILD)/%.d,$@) -c $< -o $@

run: $(TARGET)
	@echo "$(COLOR_LNK)[RUN]$(COLOR_RST)"
	./$(TARGET)

# Limpiar
clean:
	rm -rf $(BUILD_DIR)

distclean: clean
	rm -rf $(BIN_DIR)

# Incluir dependencias si existen
-include $(DEPS)

.PHONY: all clean distclean
