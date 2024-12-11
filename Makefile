CC = clang
CFLAGS = -framework Cocoa \
         -I src/windowlibrary \
         -I src/windowlibrary/translationlayer \
         -I atarxia_app_c/window/c_translation

TARGET = SimpleWindow

SRC = src/windowlibrary/main.m \
      src/windowlibrary/colorFill.m \
      src/windowlibrary/translationlayer/windowCWrapper.m \
      ataraxia_app_c/window/main.c

# Update the HEADERS paths similarly.
HEADERS = src/windowlibrary/basicWindow.h \
          src/windowlibrary/colorFill.h \
          src/windowlibrary/translationlayer/windowCWrapper.h \
          atarxia_app_c/window/c_translation/windowObjCTrans.h

# Add vpath to help make find the source and header files.
vpath %.m src/windowlibrary src/windowlibrary/translationlayer atarxia_app_c/window
vpath %.h src/windowlibrary src/windowlibrary/translationlayer atarxia_app_c/window/c_translation

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)



