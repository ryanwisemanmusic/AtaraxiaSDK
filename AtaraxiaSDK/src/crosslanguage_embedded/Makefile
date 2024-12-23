# Compiler and flags
CXX = clang++
CXXFLAGS = -std=c++17 -fobjc-arc \
           -I AtaraxiaSDK/src/audio/handling \
           -I AtaraxiaSDK/src/audio/filehandling \
           -I AtaraxiaSDK/src/crosslanguage_embedded \
           -I AtaraxiaSDK/src/audio/filehandling  # Add this line to include your custom Obj-C++ headers directory
LDFLAGS = -framework Cocoa

# Directories
CROSSLANGUAGE_DIR = AtaraxiaSDK/src/crosslanguage_embedded
FILEHANDLING_DIR = AtaraxiaSDK/src/audio/filehandling
BUILD_DIR = AtaraxiaSDK/build

# Source files
OBJCXX_SRC = $(CROSSLANGUAGE_DIR)/main.mm $(FILEHANDLING_DIR)/AudioProcessing.mm
CPP_SRC = $(FILEHANDLING_DIR)/m4aPassThrough.cpp

# Object files
OBJCXX_OBJ = $(BUILD_DIR)/main.o $(BUILD_DIR)/AudioProcessing.o
CPP_OBJ = $(BUILD_DIR)/m4aPassThrough.o

# Target
TARGET = CrossLanguageEmbedded

# Default target
all: $(BUILD_DIR) $(BUILD_DIR)/$(TARGET)

# Rule to create the build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Rule to build the target
$(BUILD_DIR)/$(TARGET): $(OBJCXX_OBJ) $(CPP_OBJ)
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

# Rule to compile Objective-C++ files
$(BUILD_DIR)/%.o: $(CROSSLANGUAGE_DIR)/%.mm
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/AudioProcessing.o: $(FILEHANDLING_DIR)/AudioProcessing.mm
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to compile C++ files
$(BUILD_DIR)/%.o: $(FILEHANDLING_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create target for testing
.PHONY: create
create: clean $(BUILD_DIR) all
	@echo "Running $(TARGET)..."
	$(BUILD_DIR)/$(TARGET)

# Clean target
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)/*.o $(BUILD_DIR)/$(TARGET)







