CC = clang
CFLAGS = -framework Cocoa

TARGET = SimpleWindow
SRC = src/main.m src/basicWindow.m src/colorFill.m
HEADERS = src/basicWindow.h src/colorFill.h

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)
