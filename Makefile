CC = clang
CFLAGS = -framework Cocoa -I src/windowlibrary -I src/windowlibrary/translationlayer

TARGET = SimpleWindow
SRC = src/windowlibrary/main.m \
      src/windowlibrary/colorFill.m \
      src/windowlibrary/translationlayer/windowCWrapper.m \

HEADERS = src/windowlibrary/basicWindow.h \
          src/windowlibrary/colorFill.h \
          src/windowlibrary/translationlayer/windowCWrapper.h

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)
