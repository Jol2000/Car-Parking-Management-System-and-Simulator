CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -pthread -lrt # Show all reasonable warnings
LDFLAGS = 

all: simulator manager firealarm

simulator: simulator.c
	gcc -o simulator.exe simulator.c $(CFLAGS)

manager: manager.c
	gcc -o manager.exe manager.c $(CFLAGS)

firealarm: firealarm.c
	gcc -o firealarm.exe firealarm.c $(CFLAGS)

clean:
	rm -f manager simulator firealarm *.o

.PHONY: all clean
