BUILD_DIR := build
SRC_DIR := src
TARGET_EXEC := $(BUILD_DIR)/waydevil
SRC := src/main.c src/prettyprint.c
CC := gcc
CFLAGS := -I ./include -Wall -Wextra -O3

waydevil: $(SRC)
	mkdir -p $(BUILD_DIR)
	gcc $(SRC) $(CFLAGS) -o $(TARGET_EXEC)

builddir:
	mkdir -p $(BUILD_DIR)

run: waydevil
	$(TARGET_EXEC)

clean:
	rm -f build/waydevil
