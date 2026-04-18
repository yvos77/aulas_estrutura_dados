CC      = gcc
CFLAGS  = -Wall -Wextra -g
TARGET  = a.out
SRCS    = main.c conta.c

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)
	rm -f *.o

run: all
	./$(TARGET)

clean:
	rm -f *.o $(TARGET)