CC = gcc
C_FLAGS = -g
EXE = generate-terrain
HEADERS = $(wildcard *.h)

all: $(EXE)

$(EXE): main.o types.o heightmap.o color.o
	$(CC) $^ ${C_FLAGS} -lSDL2 -o $@

%.o: %.c ${HEADERS}
	$(CC) ${C_FLAGS} -c $< -o $@

clean:
	rm -f *o $(EXE)
