CC := gcc
CFLAGS := -Wall -pedantic -std=c17
LDFLAGS := 
LIBS := x11
SRC := src
OBJ := obj

SRCS := $(wildcard $(SRC)/*.c)
OBJS := $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

EXE := xautoclicker

.PHONY:
	$(EXE)

$(EXE): $(OBJ) $(OBJS) 
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(EXE) `pkg-config --libs --cflags $(LIBS)` 

$(OBJ): 
	mkdir $@

$(OBJS): $(OBJ)/%.o : $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ `pkg-config --libs --cflags $(LIBS)` 

clean:
	rm -rf obj $(EXE)
