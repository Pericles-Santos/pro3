#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main_arg.h"
#include "funcoes_jogo.h"

DIRECOES inciciar_direcoes(DIRECOES d){
	d.x[sul].v = 1; d.x[sul].h = 0;
	d.x[sul].n_trocas = 0;
	
	d.x[norte].v = -1; d.x[norte].h = 0;
	d.x[norte].n_trocas = 0;
	
	d.x[leste].v = 0; d.x[leste].h = 1;
	d.x[leste].n_trocas = 0;
	
	d.x[oeste].v = 0; d.x[oeste].h = 1;
	d.x[oeste].n_trocas = 0;
	
	d.x[sudeste].v = 1; d.x[sudeste].h = 1;
	d.x[sudeste].n_trocas = 0;
	
	d.x[sudoeste].v = 1; d.x[sudoeste].h = -1;
	d.x[sudoeste].n_trocas = 0;
	
	d.x[nordeste].v = -1; d.x[nordeste].h = 1;
	d.x[nordeste].n_trocas = 0;
	
	d.x[noroeste].v = -1; d.x[noroeste].h = -1;
	d.x[noroeste].n_trocas = 0;

	return d;
	}

void print_tabuleiro(char tb[8][8]){
	int i, j;
	
	printf("\n  1 2 3 4 5 6 7 8\n");
	for(i=0; i<8; i++){
		printf("%d ", i+1);
		for(j=0; j<8; j++){
			printf("%c ", tb[i][j]);
			}
		printf("\n");
		}
	}

int n_trocas(char peca, char tb[8][8], int i, int j, POSSIBILIDADE mover){
	int a, b, c;
	
	if(mover.v!=0){
		if((i==0)||(i==7)){	return 0; }
		
		}
	if(mover.h!=0){
		if((j==0)||(j==7)){	return 0; }
		}
	if(tb[i+x.v][j+x.h]!='.'){ return 0; }
	
	return 0;
	}

void procurar_possiveis(char tb[8][8], char peca){
	int i, j;
	int S, N, E, O, SE, SO, NE, NO;
	int 
	
	
	DIRECOES dir = inciciar_direcoes(dir);
	/*[1][0](baixo); [0][1](dir); [-1][0](cima); [0][-1](esq); [1][1](baixo+dir);
	[1][-1](baixo+esq); [-1][1](cim+dir); [-1][-1](cim+esq);<=[a][b]*/
	
	
	for(i=0; i<8; i++){
		for(j=0; j<8; j++){
			
			if(tb[i][j]=='.'){
				
				S = n_trocas(peca, tb, i, j, dir.x[sul]);
				N = n_trocas(peca, tb, i, j, dir.x[norte]);
				E = n_trocas(peca, tb, i, j, dir.x[leste]);
				O = n_trocas(peca, tb, i, j, dir.x[oeste]);
				
				SE = n_trocas(peca, tb, i, j, dir.x[sudeste]);
				SO = n_trocas(peca, tb, i, j, dir.x[sudoeste]);
				NE = n_trocas(peca, tb, i, j, dir.x[nordeste]);
				NO = n_trocas(peca, tb, i, j, dir.x[noroeste]);
				
				}
			
			}
		
		}
	}

void jogar_X(char tb[8][8], FUNCOES ativas){
	procurar_possiveis(tb, 'X');
	
	}

void jogar_O(char tb[8][8], FUNCOES ativas){
	procurar_possiveis(tb, 'O');
	
	}

void iniciar_tabuleiro(char tb[8][8]){
	int i, j;
	
	for(i=0; i<8; i++){
		for(j=0; j<8; j++){
			tb[i][j]='.';
			}
		}
	tb[3][4]='X';
	tb[4][3]='X';
	tb[3][3]='O';
	tb[4][4]='O';
	}

void jogo(FUNCOES ativas){
	char tb[8][8];
	int jogador = 1;
	int fim_do_jogo = 0;
	
	iniciar_tabuleiro(tb);
	print_tabuleiro(tb);
	
	while(fim_do_jogo == 0){
		if(jogador==1){
			jogar_X(tb, ativas);
			
			jogador=2;
			jogar_O(tb, ativas);
			
			}
		else if(jogador==2){
			
			
			jogador=1;
			}
		fim_do_jogo=1;
		}
	
	
	
	
	printf("\nu = %d\tf = %d\tpeca = %c\n", ativas.u, ativas.f, ativas.p);
	if(ativas.f==1){fprintf(ativas.f_save,"\tficheiro para salvar cenas\n");}
	}



