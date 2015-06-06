main: main.c recipe.c
	gcc -Wall -O2 -o main main.c recipe.c

clean:
	rm main