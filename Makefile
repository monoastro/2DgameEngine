CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -Wpedantic

BIN		:= bin
SRC 		:= src
E_SRC 	:= src/Engine

INCLUDE	:= include
E_INCLUDE 	:= include/Engine

IMGUI_DIR 	:= lib/imgui
LIB		:= 

LIBRARIES	:= -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -lsfml-network -lGL
EXECUTABLE	:= main 


run: $(BIN)/$(EXECUTABLE)
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp $(E_SRC)/*.cpp $(E_SRC)/managers/*.cpp $(E_SRC)/states/*.cpp $(IMGUI_DIR)/*.cpp $(IMGUI_DIR)/backends/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -I$(E_INCLUDE) -I$(IMGUI_DIR) -I$(IMGUI_DIR)/backends $^ -o $@ $(LIBRARIES)
