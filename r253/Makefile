CC=gcc
CFLAGS=-Wall -O3
# -Wall -O3
LIBS=-lstdc++
EXE = main.exe

all: $(EXE)

run: $(EXE)
	./$(EXE)

clean:
	$(RM) *.o *~ $(EXE)

$(EXE): main.o
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

%.o: %.c	
	$(CC) $(CFLAGS) -c $< -o $@
