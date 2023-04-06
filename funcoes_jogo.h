/*Ficheiro "funcoes_jogo.h"*/

/*utiliza o typedef struct{}FUNCOES definido no ficheiro "main_arg.h"*/

#define sul 0
#define norte 1
#define leste 2
#define oeste 3
#define sudeste 4
#define sudoeste 5
#define nordeste 6
#define noroeste 7


typedef struct{
	int v, h; /*vetores direcao*/
	int n_trocas; /*numero de trocas nessa direcao*/
	}POSSIBILIDADE;

typedef struct{
	POSSIBILIDADE x[8];
	}DIRECOES;

void jogo(FUNCOES ativas);

