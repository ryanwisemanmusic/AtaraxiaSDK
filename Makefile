CC = clang
CFLAGS = -framework Cocoa \
		 -fobjc-arc \
         -I src/windowlibrary \
         -I src/windowlibrary/translationlayer \
         -I ataraxia_app_c/window/c_translation \
		 -I ataraxia_app_c/window/screenLogic

TARGET = SimpleWindow

SRC = src/windowlibrary/main.m \
      src/windowlibrary/colorFill.m \
      src/windowlibrary/translationlayer/windowCWrapper.m \
      ataraxia_app_c/window/main.c \
	  ataraxia_app_c/window/screenLogic/screen_management.c

# Update the HEADERS paths similarly.
HEADERS = src/windowlibrary/basicWindow.h \
          src/windowlibrary/colorFill.h \
          src/windowlibrary/translationlayer/windowCWrapper.h \
          ataraxia_app_c/window/c_translation/windowObjCTrans.h \
		  ataraxia_app_c/window/screenLogic/screen_management.h

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



