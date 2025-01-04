CC = gcc
CFLAGS = -Wall -Werror
TARGET = rtos
SRC = src/main.c src/scheduler.c  
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET):$(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

clean:
	rm -f $(OBJ) $(TARGET)