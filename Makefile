CC = clang
CFLAGS = -framework Cocoa

TARGET = SimpleWindow
SRC = src/main.m src/basicWindow.m
HEADERS = src/basicWindow.h

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)
