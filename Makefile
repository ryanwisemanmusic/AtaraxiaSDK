CC = clang
CFLAGS = -framework Cocoa \
		 -fobjc-arc \
         -I src/windowlibrary \
         -I src/windowlibrary/translationlayer \
		 -I src/windowlibrary/delegate \
         -I ataraxia_app_c/window/c_translation \
		 -I ataraxia_app_c/window/screenLogic

TARGET = SimpleWindow

SRC = src/windowlibrary/main.m \
      src/windowlibrary/colorFill.m \
      src/windowlibrary/translationlayer/windowCWrapper.m \
	  src/windowlibrary/delegate/WindowDelegate.m \
	  src/windowlibrary/delegate/MouseDelegate.m \
      ataraxia_app_c/window/main.c \
	  ataraxia_app_c/window/screenLogic/screen_management.m

HEADERS = src/windowlibrary/basicWindow.h \
          src/windowlibrary/colorFill.h \
          src/windowlibrary/translationlayer/windowCWrapper.h \
		  src/windowlibrary/delegate/WindowDelegate.h \
		  src/windowlibrary/delegate/MouseDelegate.h \
          ataraxia_app_c/window/c_translation/window_ObjCTrans.h \
		  ataraxia_app_c/window/screenLogic/screen_management.h

vpath %.h src/windowlibrary src/windowlibrary/translationlayer src/windowlibrary/delegate ataraxia_app_c/window/c_translation ataraxia_app_c/window/screenLogic

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)




