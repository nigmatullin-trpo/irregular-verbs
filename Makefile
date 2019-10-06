CC := gcc
COMPILE_FLAGS := -Wall -Werror 

SRC_PATH := src
TEST_PATH := test

INCLUDES := -I $(SRC_PATH)/ -I thirdparty/

.PHONY: all
all: mkDir verbs

test: mkDir verbs_test

.PHONY: verbs
verbs: main.o verbs.o
	$(CC) build/$(SRC_PATH)/main.o build/$(SRC_PATH)/verbs.o -o bin/verbs
	./bin/verbs

verbs_test: main_test.o verbs_test.o
	$(CC) $(INCLUDES) build/$(TEST_PATH)/main.o build/$(TEST_PATH)/verbs_test.o -o bin/verbs-test
	./bin/verbs-test

mkDir:
	mkdir -p bin
	mkdir -p build
	mkdir -p build/$(SRC_PATH)
	mkdir -p build/$(TEST_PATH)

main.o: $(SRC_PATH)/main.c
	$(CC) $(COMPILE_FLAGS) $(INCLUDES) -c $(SRC_PATH)/main.c -o build/$(SRC_PATH)/main.o

verbs.o: $(SRC_PATH)/verbs.c
	$(CC) $(COMPILE_FLAGS) $(INCLUDES) -c $(SRC_PATH)/verbs.c -o build/$(SRC_PATH)/verbs.o

main_test.o: $(TEST_PATH)/main.c
	$(CC) $(COMPILE_FLAGS) $(INCLUDES) -c $(TEST_PATH)/main.c -o build/$(TEST_PATH)/main.o

verbs_test.o: $(TEST_PATH)/verbs_test.c
	$(CC) $(COMPILE_FLAGS) $(INCLUDES) -c $(TEST_PATH)/verbs_test.c -o build/$(TEST_PATH)/verbs_test.o

.PHONY: clean
clean:
	rm -r -f bin/*
	rm -r -f build/*