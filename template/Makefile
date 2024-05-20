AS = nasm
ASFLAGS = -f elf64 -g -F dwarf
CC = gcc
LD = gcc
CDEF = -D LOG
CFLAGS = -pedantic-errors -Wall -Werror -Wextra -ggdb -std=c11 -march=native -I../lib $(CDEF)
DEBUGGER = gdb
DEBFLAGS =
SRC_DIR = src
LIB_DIR = ../lib
OBJ_DIR = obj
BIN_DIR = bin
RES_DIR = res
DIRS = $(SRC_DIR) $(OBJ_DIR) $(BIN_DIR) $(RES_DIR)
OUT = main
EXE = $(BIN_DIR)/$(OUT)
C_SRC = $(wildcard $(SRC_DIR)/*.c)
AS_SRC = $(wildcard $(SRC_DIR)/*.asm)
C_LIB = $(wildcard $(LIB_DIR)/*.c)
OBJ = $(C_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) $(AS_SRC:$(SRC_DIR)/%.asm=$(OBJ_DIR)/%.o) $(C_LIB:$(LIB_DIR)/%.c=$(OBJ_DIR)/%.o)
RES = $(wildcard $(RES_DIR)/*)
BIN = $(EXE) $(RES:$(RES_DIR)/%=$(BIN_DIR)/%)
OBJDUMP = $(OBJ:$(OBJ_DIR)/%.o=$(BIN_DIR)/%.o.txt)
ALL = $(DIRS) $(BIN)

all: $(ALL)

run: $(ALL)
	cd $(BIN_DIR); \
	./$(OUT); \
	dotnet fsi combine.fsx

dec: $(OBJDUMP)

gdb: $(BIN)
	$(DEBUGGER) $(EXE)

# 実行ファイル作成
$(EXE): $(OBJ)
	$(LD) -o $@ $^

# Cコンパイル
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

# ASMコンパイル
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.asm
	$(AS) $(ASFLAGS) -o $@ $<

# Cコンパイル
$(OBJ_DIR)/%.o: $(LIB_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

# デコンパイル
$(BIN_DIR)/%.o.txt: $(OBJ_DIR)/%.o
	objdump -D -M intel-mnemonic $< > $@

# リソースファイルコピー
$(BIN_DIR)/%: $(RES_DIR)/%
	cp -f $< $(BIN_DIR)/

# ディレクトリ作成
$(DIRS):
	mkdir -p $@

clean:
	rm -f obj/* bin/*

.PHONY: all run clean