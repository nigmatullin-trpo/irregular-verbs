all:  verbs

verbs: mkDir main.o verbs.o
	gcc build/main.o build/verbs.o -o bin/verbs
mkDir:
	mkdir -p bin
	mkdir -p build
main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/main.o
verbs.o: src/verbs.c
	gcc -Wall -Werror -c src/verbs.c -o build/verbs.o
.PHONY:  clean	
clean:
	rm -r -f bin/*
	rm -r -f build/*
rmDir: 
	rm -r bin
	rm -r build
