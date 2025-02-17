# Compiler
CXX = clang++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
OBJCPPFLAGS = $(CXXFLAGS) -ObjC++

# SDL2 paths
SDL2_INCLUDE = /opt/homebrew/Cellar/sdl2/2.30.9/include
SDL2_LIB = /opt/homebrew/Cellar/sdl2/2.30.9/lib

# SDL2_image paths
SDL2_IMAGE_INCLUDE = /opt/homebrew/Cellar/sdl2_image/2.8.2_2/include
SDL2_IMAGE_LIB = /opt/homebrew/Cellar/sdl2_image/2.8.2_2/lib

# Combined header directories (system and project-specific)
HEADER = -isystem $(SDL2_INCLUDE)/SDL2 \
         -isystem $(SDL2_INCLUDE) \
         -isystem $(SDL2_IMAGE_INCLUDE) \
         -Iinclude/cpp_headers \
         -Iinclude/objc_headers \
         -Isrc/objc

# Library flags
LIB_FLAGS = -L$(SDL2_LIB) -L$(SDL2_IMAGE_LIB) -lSDL2 -lSDL2_image -framework Cocoa

# Target executable
TARGET = AtaraxiaSDK

# Source files
SRC_CPP = src/cpp/main.cpp
SRC_OBJC = src/objc/cocoaToolbarUI.mm

# Object files
OBJ_CPP = $(SRC_CPP:.cpp=.o)
OBJ_OBJC = src/objc/cocoaToolbarUI.o
OBJS = $(OBJ_CPP) $(OBJ_OBJC)

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(LIB_FLAGS) -o $(TARGET)

# Compile C++ source files
src/cpp/%.o: src/cpp/%.cpp
	$(CXX) $(CXXFLAGS) $(HEADER) -c $< -o $@

# Compile Objective-C++ source files
src/objc/%.o: src/objc/%.mm
	$(CXX) $(OBJCPPFLAGS) $(HEADER) -c $< -o $@

# Run the application
run: $(TARGET)
	./$(TARGET)

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean run
