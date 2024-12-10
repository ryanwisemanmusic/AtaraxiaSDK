CC = clang
CFLAGS = -framework Cocoa

TARGET = SimpleWindow
SRC = main.m

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)
