OBJS = thing1.c

OBJ_NAME = game

all : $(OBJS)
	gcc $(OBJS) -w  -lncurses  -o $(OBJ_NAME)
