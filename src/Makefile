
CC=gcc

CFLAGS=-Wall -Wextra -pedantic

TARGET=arc

SRCS=arc.c terminal.c input.c

OBJS=$(SRCS:.c=.o)

all: $(TARGET) run

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(CFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: 
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

-include $(OBJS:.o=.d)

%.d: %.c
	$(CC) $(CFLAGS) -MM $< -o $@
