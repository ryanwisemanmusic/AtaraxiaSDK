# Compiler
CXX = clang++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# SDL2 paths
SDL2_INCLUDE = /opt/homebrew/Cellar/sdl2/2.30.9/include
SDL2_LIB = /opt/homebrew/Cellar/sdl2/2.30.9/lib

# SDL2_image paths
SDL2_IMAGE_INCLUDE = /opt/homebrew/Cellar/sdl2_image/2.8.2_2/include
SDL2_IMAGE_LIB = /opt/homebrew/Cellar/sdl2_image/2.8.2_2/lib

# Include and library flags
INCLUDE_FLAGS = -isystem $(SDL2_INCLUDE)/SDL2 -isystem $(SDL2_INCLUDE) -isystem $(SDL2_IMAGE_INCLUDE)
LIB_FLAGS = -L$(SDL2_LIB) -L$(SDL2_IMAGE_LIB) -lSDL2 -lSDL2_image

# Target executable
TARGET = sdl_window

# Source files
SRCS = main.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(LIB_FLAGS) -o $(TARGET)

# Compile the source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

# Run the application
run: $(TARGET)
	./$(TARGET)

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean run