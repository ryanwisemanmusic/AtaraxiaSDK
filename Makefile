# Compiler and flags
CC = clang
CFLAGS = -framework Cocoa \
         -fobjc-arc \
		 -I src/audio/filehandling \
         -I src/debugging \
		 -I src/windowlibrary \
         -I src/windowlibrary/translationlayer \
         -I src/windowlibrary/delegate \
		 -I src/windowlibrary/events \
		 -I src/windowlibrary/mainmenu \
         -I ataraxia_app_c/window/c_translation \
         -I ataraxia_app_c/window/screenLogic

# Linker flags (add any other frameworks or libraries here if needed)
LDFLAGS = -framework Cocoa

# Target name (your executable)
TARGET = SimpleWindow
BUNDLE = $(TARGET).app
EXECUTABLE = MyApp

# Source files
SRC = src/debugging/logLogic.m \
	  src/debugging/LogViewer.m \
	  src/windowlibrary/main.m \
      src/windowlibrary/colorFill.m \
      src/windowlibrary/translationlayer/windowCWrapper.m \
	  src/windowlibrary/delegate/LogDelegate.m \
      src/windowlibrary/delegate/WindowDelegate.m \
      src/windowlibrary/delegate/MouseDelegate.m \
	  src/windowlibrary/delegate/SpacebarDelegate.m \
	  src/windowlibrary/events/EventHandling.m \
	  src/windowlibrary/mainmenu/AppDelegate.m \
      ataraxia_app_c/window/main.c \
      ataraxia_app_c/window/screenLogic/screen_management.m

# Default target to build
all: $(BUNDLE)

# Rule for creating the target
$(BUNDLE): $(SRC)
	@echo "Creating $(BUNDLE)..."

	mkdir -p $(BUNDLE)/Contents/MacOS
	mkdir -p $(BUNDLE)/Contents/Resources

	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $(BUNDLE)/Contents/MacOS/$(EXECUTABLE)

	@echo "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" > $(BUNDLE)/Contents/Info.plist
	@echo "<!DOCTYPE plist PUBLIC \"-//Apple//DTD PLIST 1.0//EN\" \"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">" >> $(BUNDLE)/Contents/Info.plist
	@echo "<plist version=\"1.0\">" >> $(BUNDLE)/Contents/Info.plist
	@echo "<dict>" >> $(BUNDLE)/Contents/Info.plist
	@echo "    <key>CFBundleName</key>" >> $(BUNDLE)/Contents/Info.plist
	@echo "    <string>SimpleWindow</string>" >> $(BUNDLE)/Contents/Info.plist
	@echo "    <key>CFBundleIdentifier</key>" >> $(BUNDLE)/Contents/Info.plist
	@echo "    <string>com.yourcompany.SimpleWindow</string>" >> $(BUNDLE)/Contents/Info.plist
	@echo "    <key>CFBundleVersion</key>" >> $(BUNDLE)/Contents/Info.plist
	@echo "    <string>1.0</string>" >> $(BUNDLE)/Contents/Info.plist
	@echo "    <key>CFBundleExecutable</key>" >> $(BUNDLE)/Contents/Info.plist
	@echo "    <string>MyApp</string>" >> $(BUNDLE)/Contents/Info.plist
	@echo "</dict>" >> $(BUNDLE)/Contents/Info.plist
	@echo "</plist>" >> $(BUNDLE)/Contents/Info.plist

# Clean target to remove generated files
clean:
	rm -rf $(BUNDLE)

# Run target to execute the built app
run: $(BUNDLE)
	open $(BUNDLE)
