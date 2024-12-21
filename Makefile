# Compiler and flags
CC = clang
CFLAGS = -framework Cocoa \
         -fobjc-arc \
         -I src/windowlibrary \
         -I src/windowlibrary/translationlayer \
         -I src/windowlibrary/delegate \
         -I ataraxia_app_c/window/c_translation \
         -I ataraxia_app_c/window/screenLogic

# Linker flags (add any other frameworks or libraries here if needed)
LDFLAGS = -framework Cocoa

# Target name (your executable)
TARGET = SimpleWindow

# Source files
SRC = src/windowlibrary/main.m \
      src/windowlibrary/colorFill.m \
      src/windowlibrary/translationlayer/windowCWrapper.m \
      src/windowlibrary/delegate/WindowDelegate.m \
      src/windowlibrary/delegate/MouseDelegate.m \
      ataraxia_app_c/window/main.c \
      ataraxia_app_c/window/screenLogic/screen_management.m

# Header files (not used in the Makefile directly, but might be helpful for IDEs)
HEADERS = src/windowlibrary/basicWindow.h \
          src/windowlibrary/colorFill.h \
          src/windowlibrary/translationlayer/windowCWrapper.h \
          src/windowlibrary/delegate/WindowDelegate.h \
          src/windowlibrary/delegate/MouseDelegate.h \
          ataraxia_app_c/window/c_translation/window_ObjCTrans.h \
          ataraxia_app_c/window/screenLogic/screen_management.h

# Add header search paths
vpath %.h src/windowlibrary src/windowlibrary/translationlayer src/windowlibrary/delegate ataraxia_app_c/window/c_translation ataraxia_app_c/window/screenLogic

# Default target to build
all: $(TARGET)

# Rule for creating the target
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

# Clean target to remove generated files
clean:
	rm -f $(TARGET)

# Run target to execute the built app
run: $(TARGET)
	./$(TARGET)





