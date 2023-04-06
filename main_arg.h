/*Ficheiro "main_arg.h"*/

typedef struct{
	int f, u;
	char p;
	FILE *f_save;
	}FUNCOES;

void print_arg_opcoes(void);

FUNCOES iniciar_funcoes(FUNCOES desativar);

int procurar_nome_file(char filename[]);

char procurar_peca(char peca[]);

FUNCOES check_arg(int argc, char *argv[], FUNCOES ativar);

