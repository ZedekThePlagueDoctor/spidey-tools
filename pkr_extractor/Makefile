CC= gcc
LIBS = -lz
OBJ = pkr.o walk.o extract.o
CFLAGS = -std=c11 -g -static
all: pkr 

%.o: %.c
		$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

pkr: $(OBJ)
		gcc -o $@ $^ $(CFLAGS) $(LIBS)

clean:
		rm -rf *.o
