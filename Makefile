all: src/main.c
	gcc -g -Wall -Werror -o bin/main src/main.c
clean:
	rm -r -f bin/main