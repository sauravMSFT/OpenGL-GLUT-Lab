BIN         = sierpinski
CFLAGS      = $(INCLUDE) -lGL -lGLU -lglut -lm
SRC    		= $(wildcard *.c)
OBJECTS       = $(SRC:.c=.o)
MODULES     = *.o

all: $(BIN) clean

$(BIN): $(OBJECTS)
	gcc $(MODULES) -o $(BIN) $(CFLAGS) $(LIBS)

%.o: %.c
	gcc -g -c $^ $(CFLAGS) -o $(basename $(<F)).o --std=c99

clean:
	rm *.o -rf
	rm .f* -rf