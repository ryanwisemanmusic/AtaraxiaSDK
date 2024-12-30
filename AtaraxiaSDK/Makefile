# Compiler and flags
CC = clang
CFLAGS = -framework Cocoa \
         -framework UniformTypeIdentifiers \
		 -framework Foundation \
		 -framework Quartz \
		 -framework CoreGraphics \
		 -framework AppKit \
         -fobjc-arc \
         -I AtaraxiaSDK/src/audio/filehandling \
         -I AtaraxiaSDK/src/debugging \
		 -I AtaraxiaSDK/src/fileconversion \
		 -I AtaraxiaSDK/src/fileconversion/utility \
         -I AtaraxiaSDK/src/windowlibrary \
         -I AtaraxiaSDK/src/windowlibrary/translationlayer \
         -I AtaraxiaSDK/src/windowlibrary/delegate \
         -I AtaraxiaSDK/src/windowlibrary/events \
         -I AtaraxiaSDK/src/windowlibrary/mainmenu \
         -I AtaraxiaSDK/src/mainmenu/windowing \
         -I AtaraxiaSDK/ataraxia_app_c/window/c_translation \
         -I AtaraxiaSDK/ataraxia_app_c/window/screenLogic

# Linker flags (add any other frameworks or libraries here if needed)
LDFLAGS = -framework Cocoa \
          -framework UniformTypeIdentifiers \
		  -framework Foundation \
		  -framework Quartz \
		  -framework CoreGraphics \
		  -framework AppKit

# Target name (your executable)
TARGET = SimpleWindow
BUNDLE = $(TARGET).app
EXECUTABLE = MyApp

# Source files (adjusted with correct paths)
SRC = AtaraxiaSDK/src/debugging/logLogic.m \
      AtaraxiaSDK/src/debugging/LogViewer.m \
	  AtaraxiaSDK/src/fileconversion/DocumentConverter.m \
	  AtaraxiaSDK/src/fileconversion/ImageConverter.m \
	  AtaraxiaSDK/src/fileconversion/utility/FileConversionUtility.m \
	  AtaraxiaSDK/src/fileconversion/utility/ImageConversionUtility.m \
      AtaraxiaSDK/src/windowlibrary/main.m \
      AtaraxiaSDK/src/windowlibrary/colorFill.m \
      AtaraxiaSDK/src/windowlibrary/translationlayer/windowCWrapper.m \
	  AtaraxiaSDK/src/windowlibrary/delegate/FileConverterDelegate.m \
      AtaraxiaSDK/src/windowlibrary/delegate/LogDelegate.m \
      AtaraxiaSDK/src/windowlibrary/delegate/WindowDelegate.m \
      AtaraxiaSDK/src/windowlibrary/delegate/MouseDelegate.m \
      AtaraxiaSDK/src/windowlibrary/delegate/SpacebarDelegate.m \
      AtaraxiaSDK/src/windowlibrary/events/EventHandling.m \
      AtaraxiaSDK/src/windowlibrary/mainmenu/AppDelegate.m \
	  AtaraxiaSDK/src/windowlibrary/mainmenu/FileConverterWindow.m \
	  AtaraxiaSDK/src/windowlibrary/mainmenu/windowing/FileConverterViewer.m \
      AtaraxiaSDK/ataraxia_app_c/window/main.c \
      AtaraxiaSDK/ataraxia_app_c/window/screenLogic/screen_management.m

# Default target to build
all: $(BUNDLE)

# Rule for creating the target
$(BUNDLE): $(SRC)
	@echo "Creating $(BUNDLE)..."

	# Create the bundle directory structure
	mkdir -p $(BUNDLE)/Contents/MacOS
	mkdir -p $(BUNDLE)/Contents/Resources

	# Compile and link the source files into the app
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $(BUNDLE)/Contents/MacOS/$(EXECUTABLE)

	# Copy the Info.plist file into the app bundle from AtaraxiaSDK
	cp AtaraxiaSDK/Info.plist $(BUNDLE)/Contents/Info.plist

# Clean target to remove generated files
clean:
	rm -rf $(BUNDLE)

# Run target to execute the built app
run: $(BUNDLE)
	open $(BUNDLE)

# Force rebuild and run (always rebuild and run)
force-run: clean $(BUNDLE) run

# Clean, build, and run (alternative to force-run if you want a fresh start)
clean-run: clean $(BUNDLE) run
