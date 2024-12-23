# Define the SDK directory and target
ATARAXIA_SDK_DIR = AtaraxiaSDK
SDK_MAKEFILE = $(ATARAXIA_SDK_DIR)/Makefile
TARGET = FullProject

# Define the default target (build everything)
.PHONY: all
all: $(TARGET)

# Build the overall project by invoking the SDK's Makefile using make -f
$(TARGET):
	@echo "Building $(TARGET)..."
	@if [ ! -f $(SDK_MAKEFILE) ]; then \
		echo "Error: $(SDK_MAKEFILE) not found!"; \
		exit 1; \
	fi
	make -f $(SDK_MAKEFILE)

# Clean the entire project by invoking the SDK clean target using make -f
.PHONY: clean
clean:
	@echo "Cleaning $(TARGET)..."
	@if [ ! -f $(SDK_MAKEFILE) ]; then \
		echo "Error: $(SDK_MAKEFILE) not found!"; \
		exit 1; \
	fi
	make -f $(SDK_MAKEFILE) clean

# Run the application after building using make -f
.PHONY: run
run: $(TARGET)
	@echo "Running $(TARGET)..."
	@if [ ! -f $(SDK_MAKEFILE) ]; then \
		echo "Error: $(SDK_MAKEFILE) not found!"; \
		exit 1; \
	fi
	make -f $(SDK_MAKEFILE) run

# Install the application (if necessary)
.PHONY: install
install:
	@echo "Installing $(TARGET)..."
	# Add installation commands here if required
	# Example: cp $(TARGET) /usr/local/bin/

# Add a target for displaying help
.PHONY: help
help:
	@echo "Makefile for $(TARGET)"
	@echo "Usage:"
	@echo "  make        - Build the $(TARGET)"
	@echo "  make clean  - Clean the $(TARGET)"
	@echo "  make run    - Run the $(TARGET) after building"
	@echo "  make install - Install the $(TARGET) (customizable)"
	@echo "  make help   - Display this help message"

# Automatically create a target for the SDK Makefile if it doesn't exist
$(SDK_MAKEFILE):
	@echo "Error: $(SDK_MAKEFILE) not found!"
	@exit 1








