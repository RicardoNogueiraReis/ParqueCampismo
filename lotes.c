/*
|| Projeto Gest�o de Reservas de Parque de Campismo
||============================================================================
|| Autores : +Rodrigo Nogueira - 200262002 - 200262002@estudantes.ips.pt
||           +Ricardo Reis     - 200262024 - 200262024@estudantes.ips.pt
||============================================================================
|| 1� Fase de Entrega
*/

#include "campista.h"
#include "lotes.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void pedirDadosLotes(lote *reservaLote){
    char eletricidade;

    do{
        printf("Tipo de alojamento [Tenda (T) // Caravana (C) // Autocaravana (A)]: ");
        scanf("%c", &reservaLote->tipoAlojamento);
        fflush(stdin);

        switch(tolower(eletricidade)){
            case 't': case 'c': case 'a':
                break;

            default:
                printf("==ERRO! Caract�r inv�lido!==\n");
        }

    }while(tolower(reservaLote->tipoAlojamento) !='t' && tolower(reservaLote->tipoAlojamento) !='c' && tolower(reservaLote->tipoAlojamento) !='a');

    do{
        printf("Tem liga��o � rede eletrica(S/N): ");
        scanf("%c", &eletricidade/*reservaLote->redeEletrica*/);
        fflush(stdin);

        switch(tolower(eletricidade)){
            case 's':
                reservaLote->redeEletrica='e';
                break;

            case 'n':
                reservaLote->redeEletrica ='x';
                break;

            default:
                printf("==ERRO! Caract�r inv�lido!==\n");
        }

    }while(tolower(eletricidade) !='s' && tolower(eletricidade) !='n');

    printf("===== Dados do(s) campista(s) =====");
    printf("N�mero de campistas: ");
    scanf("%d", &reservaLote->numeroCampistas);
    fflush(stdin);
    for(int i=0;i<reservaLote->numeroCampistas;i++){

        printf("Nome do campista: ");
        gets(reservaLote->pessoaCampista.nome);

        printf("Idade do campista :");
        scanf("%d", &reservaLote->pessoaCampista.idade);
        fflush(stdin);
    }

    //Pre�os com eletricidade
    if(tolower(eletricidade='e')){
        if(tolower(reservaLote->tipoAlojamento=='t')){
            reservaLote->preco=3.00 /*Pre�o da eletricidade*/ + (3.50*(reservaLote->numeroCampistas)) /*Pre�o por n�mero de campistas*/ + 4.50; // Pre�o da tenta
            printf("Pre�o a pagar: %.2f", reservaLote->preco);
        }
    }

    if(tolower(eletricidade='e')){
        if(tolower(reservaLote->tipoAlojamento=='c')){
            reservaLote->preco=3.00 /*Pre�o da eletricidade*/ + (3.50*(reservaLote->numeroCampistas)) /*Pre�o por n�mero de campistas*/ + 6.00; // Pre�o da caravana
            printf("Pre�o a pagar: %.2f", reservaLote->preco);
        }
    }

    if(tolower(eletricidade='e')){
        if(tolower(reservaLote->tipoAlojamento=='a')){
            reservaLote->preco=3.00 /*Pre�o da eletricidade*/ + (3.50*(reservaLote->numeroCampistas)) /*Pre�o por n�mero de campistas*/ + 14.90; // Pre�o da autocaravana
            printf("Pre�o a pagar: %.2f", reservaLote->preco);
        }
    }

    //Pre�os sem eletricidade
    if(tolower(eletricidade='x')){
        if(tolower(reservaLote->tipoAlojamento=='t')){
            reservaLote->preco=(3.50*(reservaLote->numeroCampistas)) /*Pre�o por n�mero de campistas*/ + 4.50; // Pre�o da tenta
            printf("Pre�o a pagar: %.2f", reservaLote->preco);
        }
    }

    if(tolower(eletricidade='x')){
        if(tolower(reservaLote->tipoAlojamento=='c')){
            reservaLote->preco=(3.50*(reservaLote->numeroCampistas)) /*Pre�o por n�mero de campistas*/ + 6.00; // Pre�o da caravana
            printf("Pre�o a pagar: %.2f", reservaLote->preco);
        }
    }

    if(tolower(eletricidade='x')){
        if(tolower(reservaLote->tipoAlojamento=='a')){
            reservaLote->preco=(3.50*(reservaLote->numeroCampistas)) /*Pre�o por n�mero de campistas*/ + 14.90; // Pre�o da autocaravana
            printf("Pre�o a pagar: %.2f", reservaLote->preco);
        }
    }
}

void pedirCoordenadasLote(int *linha, int *coluna){
    do{
        printf("Introduza a coluna onde se encontra o lote: ");
        scanf("%d", coluna);

    }while(coluna > 5);
    // PARA FAZER: Em vez de 5, deve ir buscar o valor das colunas no mapa dos lotes,
    //talvez numa struct propria para se poder mudar isso? mapaLote->Coluna?

    do{
        printf("\nIntroduza a linha onde se encontra o lote: ");
        scanf("%d", linha);
        fflush(stdin);
    }while(linha > 5);

}
