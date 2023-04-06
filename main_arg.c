#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main_arg.h"

void print_arg_opcoes(void){
	printf("\nOpcoes:\n");
	printf("\t-u para ativar undo\n");
	printf("\t-f filename.txt para ativar guardar jogadas no ficheiro filename.txt\n");
	printf("\t-p X ou -p O para mudar a peca\n");
	exit(0);
	}

FUNCOES iniciar_funcoes(FUNCOES desativar){
	desativar.f = 0;
	desativar.u = 0;
	desativar.p = 'X';
	desativar.f_save = NULL;
	return desativar;
	}

int procurar_nome_file(char filename[]){/*devolve 1 se encontrar o nome, 0 se nao*/
	int fim = strlen(filename);
	if(fim < 5){
		return 0;
		}
	/*verifica se termina em ".txt"*/
	if((*(filename+(fim-4))=='.')&&(*(filename+(fim-3))=='t')
		&&(*(filename+(fim-2))=='x')&&(*(filename+(fim-1))=='t')){
		return 1;
		}
	return 0;
	}

char procurar_peca(char peca[]){
	if(strcmp(peca,"X")==0){
		printf("\nPeca \"X\" ativa\n");
		return 'X';
		}
	if(strcmp(peca,"O")==0){
		printf("\nPeca \"O\" ativa\n");
		return 'O';
		}
	printf("\nPeca \"%s\" idisponivel.\tDefault \"X\" ativa\n", peca);
	return 'X';
	}

FUNCOES check_arg(int argc, char *argv[], FUNCOES ativar){
	int i;
	
	for(i=1; i<argc; i++){/*i comeca em 1 pois argv[0] = "./main"*/
		
		if(strcmp(argv[i],"-u")==0){
			printf("\nOpcao undo ativa (tecla \"u\")\n");
			ativar.u = 1;
			}
		else if(strcmp(argv[i],"-f")==0){
			ativar.f = 1;
			if((i+1 == argc)||(procurar_nome_file(*(argv+i+1))!=1)){/*arg seguinte nao corresponde a nome de ficheiro .txt*/
				printf("\nSalvar no ficheiro default \"jogo.txt\" ativo\n");
				ativar.f_save = fopen("jogo.txt", "w");
				}
			else{/*se o arg seguinte for o nome do ficheiro*/
				printf("\nSalvar no ficheiro \"%s\" ativo\n", *(argv+i+1));
				ativar.f_save = fopen((*(argv+i+1)), "w");
				i++;/*nao voltar a ler arg seguinte*/
				}
			if(ativar.f_save==NULL){
				printf("\nErro na abertura do ficheiro\n");
				exit(0);
				}
			}		
		else if(strcmp(argv[i],"-p")==0){
			if(i+1 != argc){
				ativar.p = procurar_peca(*(argv+i+1));
				i++;
				}
			else{
				printf("\nPeca default \"X\" ativa\n");
				}
		}else{
			printf("\nArgumento \"%s\" inválido\n", argv[i]);
			print_arg_opcoes();
			}
		}
	return ativar;
	}

