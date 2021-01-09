/*
|| Projeto Gest�o de Reservas de Parque de Campismo
||============================================================================
|| Autores : +Rodrigo Nogueira - 200262002 - 200262002@estudantes.ips.pt
||           +Ricardo Reis     - 200262024 - 200262024@estudantes.ips.pt
||============================================================================
|| 1� Fase de Entrega
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "campista.h"
#include "lotes.h"
#include "mapa.h"

//lote criarLoteTemp(campista pessoaCampista[], char tipoAlojamento, char redeEletrica, int numeroCampistas, float preco, int coordenadasLin, int coordenadasCol){
//    lote criarLoteTemp;
//    campista criarCampista;
//    criarLoteTemp.pessoaCampista.nome = pessoaCampista->nome;
//
//    criarLoteTemp.tipoAlojamento = tipoAlojamento;
//    criarLoteTemp.redeEletrica = redeEletrica;
//    criarLoteTemp.numeroCampistas = numeroCampistas;
//    criarLoteTemp.preco = preco;
//    criarLoteTemp.coordenadasLin = coordenadasLin;
//    criarLoteTemp.coordenadasCol = coordenadasCol;
//
//    return criarLoteTemp;
//}

/*
 * =>*pedirLinha e *pedirColuna
 * S�o as coordenadas do lote que o utilizador pretende reservar.
 * NOTA: esta fun��o N�O verifica se o lote est� ocupado,
 *isso estar� para o "pedirDadosLotes()"
 *
*/
void pedirCoordenadasLote(int *pedirLinha, int *pedirColuna){

    mapa mapa;

    /* Impede que os valores sejam nulos ou excedam dimens�es do mapa lotes */
    do{
        printf("Introduza a coluna onde se encontra o lote: ");
        scanf("%d", pedirColuna);

        if(*pedirColuna > mapa.coluna)
            printf("\n==ERRO! N�mero da coluna inserido excede o n�mero m�ximo de colunas do mapa==\n");
        else if(*pedirColuna < 0)
            printf("\n==ERRO! N�mero da coluna inserido n�o pode ser menor que 0 ==\n");
        else if(*pedirColuna == 0)
            printf("\n==ERRO! N�mero da coluna n�o pode ser 0==\n");

    }while(*pedirColuna > mapa.coluna || *pedirColuna < 1);

    do{
        printf("Introduza a linha onde se encontra o lote: ");
        scanf("%d", pedirLinha);
        fflush(stdin);

        if(*pedirLinha > mapa.linha)
            printf("\n==ERRO! N�mero da linha inserido excede o n�mero m�ximo de linhas do mapa==\n");
        else if(*pedirLinha < 0)
            printf("\n==ERRO! N�mero da linha inserido n�o pode ser menor que 0==\n");
        else if(*pedirLinha == 0)
            printf("\n==ERRO! N�mero da linha n�o pode ser 0==\n");

    }while(*pedirLinha > mapa.linha || *pedirLinha < 1);

    if(criarLoteTemp[*pedirLinha-1][*pedirColuna-1].tipoAlojamento != NULL){
        printf("\n==ERRO! Lote j� est� reservado!==\n");
    }else
        pedirDadosLotes(*pedirLinha, *pedirColuna);
}

void pedirDadosLotes(int linha, int coluna){
    char eletricidade, tipoAloj;
    lote criarLoteTemp[linha][coluna];;

    do{
        printf("=== MENU DE ALOJAMENTO ===\n");
        printf("++ Tenda           4,50E ++\n");
        printf("++ Caravana        6,00� ++\n");
        printf("++ Autocaravana   14,50� ++\n");
        printf("++ Eletricidade    3,00� ++\n");
        printf("++ Campista        3,50� ++\n");
        printf("==========================\n");

        printf("Tipo de alojamento [Tenda (T) // Caravana (C) // Autocaravana (A)]: ");
        scanf("%c", &tipoAloj);
        fflush(stdin);

        switch(tolower(tipoAloj)){
            case 't':
                criarLoteTemp[linha][coluna].tipoAlojamento = 'T';
                break;
            case 'c':
                criarLoteTemp[linha][coluna].tipoAlojamento = 'C';
                break;
            case 'a':
                criarLoteTemp[linha][coluna].tipoAlojamento = 'A';
                break;
            default:
                printf("\n==ERRO! Caract�r inv�lido!==\n\n");
        }

    }while(tolower(tipoAloj) !='t' && tolower(tipoAloj) !='c' && tolower(tipoAloj) !='a');

    do{
        printf("Tem liga��o � rede eletrica(S/N): ");
        scanf("%c", &eletricidade/*reservaLote->redeEletrica*/);
        fflush(stdin);

        switch(tolower(eletricidade)){
            case 's':
                criarLoteTemp[linha][coluna].redeEletrica='e';
                break;

            case 'n':
                criarLoteTemp[linha][coluna].redeEletrica ='x';
                break;

            default:
                printf("\n==ERRO! Caract�r inv�lido!==\n");
        }

    }while(tolower(eletricidade) !='s' && tolower(eletricidade) !='n');

    printf("===== Dados do(s) campista(s) =====");
    printf("\nN�mero de campistas: ");
    scanf("%d", &criarLoteTemp[linha][coluna].numeroCampistas);
    fflush(stdin);

    for(int i=0;i<criarLoteTemp[linha][coluna].numeroCampistas;i++){
        printf("Nome do %d� campista: ", i+1);
        gets(criarLoteTemp[linha][coluna].pessoaCampista->nome);

        printf("Idade do campista: ");
        scanf("%d", &criarLoteTemp[linha][coluna].pessoaCampista->idade);
        fflush(stdin);
}

    //Pre�os com eletricidade
    if(tolower(eletricidade='e')){
        if(tolower(criarLoteTemp[linha][coluna].tipoAlojamento)=='t'){
            criarLoteTemp[linha][coluna].preco=3.00 /*Pre�o da eletricidade*/ + (3.50*(criarLoteTemp[linha][coluna].numeroCampistas)) /*Pre�o por n�mero de campistas*/ + 4.50; // Pre�o da tenta
            printf("Pre�o a pagar: %.2f", criarLoteTemp[linha][coluna].preco);
        }
    }

    if(tolower(eletricidade='e')){
        if(tolower(criarLoteTemp[linha][coluna].tipoAlojamento)=='c'){
            criarLoteTemp[linha][coluna].preco=3.00 /*Pre�o da eletricidade*/ + (3.50*(criarLoteTemp[linha][coluna].numeroCampistas)) /*Pre�o por n�mero de campistas*/ + 6.00; // Pre�o da caravana
            printf("Pre�o a pagar: %.2f", criarLoteTemp[linha][coluna].preco);
        }
    }

    if(tolower(eletricidade='e')){
        if(tolower(criarLoteTemp[linha][coluna].tipoAlojamento=='a')){
            criarLoteTemp[linha][coluna].preco=3.00 /*Pre�o da eletricidade*/ + (3.50*(criarLoteTemp[linha][coluna].numeroCampistas)) /*Pre�o por n�mero de campistas*/ + 14.90; // Pre�o da autocaravana
            printf("Pre�o a pagar: %.2f", criarLoteTemp[linha][coluna].preco);
        }
    }

    //Pre�os sem eletricidade
    if(tolower(eletricidade='x')){
        if(tolower(criarLoteTemp[linha][coluna].tipoAlojamento=='t')){
            criarLoteTemp[linha][coluna].preco=(3.50*(criarLoteTemp[linha][coluna].numeroCampistas)) /*Pre�o por n�mero de campistas*/ + 4.50; // Pre�o da tenta
            printf("Pre�o a pagar: %.2f", criarLoteTemp[linha][coluna].preco);
        }
    }

    if(tolower(eletricidade='x')){
        if(tolower(criarLoteTemp[linha][coluna].tipoAlojamento=='c')){
            criarLoteTemp[linha][coluna].preco=(3.50*(criarLoteTemp[linha][coluna].numeroCampistas)) /*Pre�o por n�mero de campistas*/ + 6.00; // Pre�o da caravana
            printf("Pre�o a pagar: %.2f", criarLoteTemp[linha][coluna].preco);
        }
    }

    if(tolower(eletricidade='x')){
        if(tolower(criarLoteTemp[linha][coluna].tipoAlojamento=='a')){
            criarLoteTemp[linha][coluna].preco=(3.50*(criarLoteTemp[linha][coluna].numeroCampistas)) /*Pre�o por n�mero de campistas*/ + 14.90; // Pre�o da autocaravana
            printf("Pre�o a pagar: %.2f", criarLoteTemp[linha][coluna].preco);
        }
    }
}
