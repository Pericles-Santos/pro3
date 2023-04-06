#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main_arg.h"
#include "funcoes_jogo.h"

int main(int argc, char *argv[]){
	FUNCOES ativas;
	
	ativas = iniciar_funcoes(ativas);
	
	if(argc>6){
		printf("Numero invalido de argumentos\n");
		print_arg_opcoes();
		}
	if(argc>0){
		ativas = check_arg(argc, argv, ativas);
		}
	
	jogo(ativas);
	
	if(ativas.f==1){fclose(ativas.f_save);}
	return EXIT_SUCCESS;
	}
