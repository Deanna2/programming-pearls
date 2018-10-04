question3: ./q3/main.c ./utils/bitmap.c ./utils/fileio.c
	gcc ./q3/main.c ./utils/bitmap.c ./utils/fileio.c -o bin/question3 -I.

question4: ./q4/main.c ./utils/fileio.c
	gcc ./q4/main.c ./utils/fileio.c  -o bin/question4 -I.

input: ./utils/main-input.c ./utils/fileio.c
	gcc ./utils/main-input.c ./utils/bitmap.c ./utils/fileio.c -o bin/input -I.

clean:
	rm bin/*
