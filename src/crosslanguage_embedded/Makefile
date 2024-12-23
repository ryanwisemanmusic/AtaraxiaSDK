# Compiler and flags
CXX = clang++
CXXFLAGS = -std=c++17 -fobjc-arc -I src/audio/handling
LDFLAGS = -framework Cocoa

# Directories
SRC_DIR = src/audio/handling
CROSSLANGUAGE_DIR = src/crosslanguage_embedded
BUILD_DIR = build

# Source files
OBJCXX_SRC = $(CROSSLANGUAGE_DIR)/main.mm src/audio/filehandling/AudioProcessing.mm
CPP_SRC = $(wildcard $(SRC_DIR)/*.cpp) src/audio/filehandling/m4aPassThrough.cpp

# Object files
OBJCXX_OBJ = $(OBJCXX_SRC:.mm=.o)
CPP_OBJ = $(CPP_SRC:.cpp=.o)

# Target
TARGET = CrossLanguageEmbedded

# Default target
all: $(BUILD_DIR) $(TARGET)

# Rule to create the build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Rule to build the target
$(TARGET): $(OBJCXX_OBJ) $(CPP_OBJ)
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $(BUILD_DIR)/$(TARGET)

# Rule to compile Objective-C++ files
%.o: %.mm
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to compile C++ files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create target for testing
.PHONY: create
create: clean $(BUILD_DIR) $(TARGET)
	@echo "Running $(TARGET)..."
	$(BUILD_DIR)/$(TARGET)

# Clean target
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)/*.o $(BUILD_DIR)/$(TARGET)




