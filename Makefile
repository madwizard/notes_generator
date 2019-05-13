notes:
	g++ -Wall src/notes.cc -o notes

clean:
	rm notes

all:
	$(clean) $(notes)
