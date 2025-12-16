CC=gcc
CFLAGS=-Wall -Wextra # -Werror
LDFLAGS=
SOURCES=main.c alg_lin.c

OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=programa

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

run: $(EXECUTABLE)
	./$(EXECUTABLE)

.PHONY: all clean

test: $(EXECUTABLE)
	./$(EXECUTABLE) < input.txt > output.txt
	diff output.txt expected_output.txt
	@echo "Test passed!"

debug: CFLAGS += -g
debug: all
	@echo "Debug build complete."
