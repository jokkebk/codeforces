CC=gcc
CFLAGS=-std=c++11
# -Wall -O3
LIBS=-lstdc++
<<<<<<< HEAD
EXE = main.exe
=======
EXE = main1.exe
>>>>>>> 17d8421e16fb007fb05a805c3cb20c62a077e718

all: $(EXE)

run: $(EXE)
	./$(EXE)

clean:
	$(RM) *.o *~ $(EXE)

<<<<<<< HEAD
%.exe: %.o
=======
%.exe: main.o
>>>>>>> 17d8421e16fb007fb05a805c3cb20c62a077e718
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

%.o: %.cc
	$(CC) $(CFLAGS) -c $< -o $@
