question2: ./q2/q2.c ./utils/bitmap.c ./utils/fileio.c
	gcc ./q2/q2.c ./utils/bitmap.c ./utils/fileio.c -o bin/question2 -I.

clean:
	rm bin/*
