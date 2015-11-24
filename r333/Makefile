CC=gcc
CFLAGS=-std=c++11
# -Wall -O3
LIBS=-lstdc++
EXE = main1.exe

all: $(EXE)

run: $(EXE)
	./$(EXE)

clean:
	$(RM) *.o *~ $(EXE)

%.exe: main.o
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

%.o: %.cc
	$(CC) $(CFLAGS) -c $< -o $@
