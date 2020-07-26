CC = gcc
C_FLAGS = -lSDL2
EXE = generate-terrain
HEADERS = $(wildcard *.h)

all: $(EXE)

$(EXE): main.o types.o heightmap.o color.o
	$(CC) $^ $(C_FLAGS) -o $@

%.o: %.c ${HEADERS}
	$(CC) -c $< -o $@

clean:
	rm *o $(EXE)
