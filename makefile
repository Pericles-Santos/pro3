#makefile
all: jogo

main_arg.o: main_arg.c main_arg.h
	gcc -g -Wall -pedantic -ansi -Werror -c main_arg.c

funcoes_jogo.o: funcoes_jogo.c main_arg.h funcoes_jogo.h
	gcc -g -Wall -pedantic -ansi -Werror -c funcoes_jogo.c

main.o: main.c main_arg.h funcoes_jogo.h
	gcc -g -Wall -pedantic -ansi -Werror -c main.c

jogo: main_arg.o funcoes_jogo.o main.o
	gcc -g -Wall -pedantic -ansi -Werror main.c main_arg.c funcoes_jogo.c -o jogo

clean:
	rm main_arg.o funcoes_jogo.o main.o jogo

