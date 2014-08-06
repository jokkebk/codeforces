CC=gcc
CFLAGS=-Wall -O3 -std=c++11
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

%.o: %.cc
	$(CC) $(CFLAGS) -c $< -o $@
