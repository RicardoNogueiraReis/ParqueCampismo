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
    do{
        printf("A dimens�o ")
        printf("Introduza o n�mero de colunas para o");
        scanf("%d", &linha)
    }while(*linha >= 1 && *coluna >= 1);
}
