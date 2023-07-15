CC = g++
CONSERVATIVE_FLAGS = -std=c++11 -Wall -Wextra -pedantic
DEBUGGING_FLAGS = -g -O0
CFLAGS = $(CONSERVATIVE_FLAGS) $(DEBUGGING_FLAGS)

main: *.cpp
	$(CC) $(CFLAGS) *.cpp -o main $(DEBUGGING_FLAGS)

clean:
	rm -f *.o main
