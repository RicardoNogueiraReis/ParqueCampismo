/*
|| Projeto Gest�o de Reservas de Parque de Campismo
||============================================================================
|| Autores : +Rodrigo Nogueira - 200262002 - 200262002@estudantes.ips.pt
||           +Ricardo Reis     - 200262024 - 200262024@estudantes.ips.pt
||============================================================================
|| 1� Fase de Entrega
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include "campista.h"
#include "lotes.h"
#include "menu.h"
#include "mapa.h"

void apresentarMapa(int linha, int coluna){

    // Dimens�o do parque de campismo, LinhaXColuna
    int dimLin = linha, dimCol = coluna;


    printf("\n\nMapa dos lotes:\n\n");

    /*Forma��o das colunas*/
    printf("%3s", ""); // Espa�o esquerdo inicial da coluna da tabela
    for(int l=0; l<dimCol; l++){
        printf("%5d ", l+1);
    }

    /*N�mero de linhas*/
    for(int l=0; l<dimLin; l++){
        printf("\n");
        printf("%2d    ", l+1);

        for (int c=0; c<dimCol; c++)
            printf("%s %2s", "...", " ");
    }
    puts("\n");
}

void mudarDimensoesLote(int *linha, int *coluna){
    // As dimens�es do lote n�o est�o definidas por padr�o,
    //cabe ao utilizador de as definir quando vai visualiza-lo
    //pela primeira vez.

    printf("\n== A dimens�o do lote n�o est� definida ==\n");
    do{
        printf("++Introduza o n�mero de colunas para o mapa do lote: ");
        scanf("%d", coluna);
        printf("\n%d\n", *coluna);

        if(coluna <= 0)
            printf("\n==ERRO! N�mero de coluna tem de ser maior que 0, sen�o n�o existe==\n");
    }while(*coluna != 0 && *coluna < 0);

    do{
        printf("++Introduza o n�mero de linhas para o mapa do lote: ");
        scanf("%d", linha);
        if(coluna <= 0)
            printf("\n==ERRO! N�mero de linhas tem de ser maior que 0, sen�o n�o existe==\n");
    }while(*linha != 0 && *linha < 0);
}
