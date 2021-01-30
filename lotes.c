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
#include <ctype.h>
#include "campista.h"
#include "lotes.h"
#include "Mapa.h"

/*
 * =>*pedirLinha e *pedirColuna
 * S�o as coordenadas do lote que o utilizador pretende reservar.
 * NOTA: esta fun��o N�O verifica se o lote est� ocupado,
 *isso estar� para o "pedirDadosLotes()"
 *
*/

void consultarLotes(int linha, int coluna);

void pedirCoordenadasLote(int *pedirLinha, int *pedirColuna){
    mapa Mapa;
    /* Impede que os valores sejam nulos ou excedam dimens�es do Mapa lotes */
    do{
        printf("Introduza a coluna onde se encontra o lote: ");
        scanf("%d", pedirColuna);

        if(*pedirColuna > Mapa.coluna)
            printf("\n==ERRO! N�mero da coluna inserido excede o n�mero m�ximo de colunas do mapa==\n");
        else if(*pedirColuna < 0)
            printf("\n==ERRO! N�mero da coluna inserido n�o pode ser menor que 0 ==\n");
        else if(*pedirColuna == 0)
            printf("\n==ERRO! N�mero da coluna n�o pode ser 0==\n");

    }while(*pedirColuna > Mapa.coluna || *pedirColuna < 1);

    do{
        printf("Introduza a linha onde se encontra o lote: ");
        scanf("%d", pedirLinha);
        fflush(stdin);

        if(*pedirLinha > Mapa.linha)
            printf("\n==ERRO! N�mero da linha inserido excede o n�mero m�ximo de linhas do Mapa==\n");
        else if(*pedirLinha < 0)
            printf("\n==ERRO! N�mero da linha inserido n�o pode ser menor que 0==\n");
        else if(*pedirLinha == 0)
            printf("\n==ERRO! N�mero da linha n�o pode ser 0==\n");

    }while(*pedirLinha > Mapa.linha || *pedirLinha < 1);
}

void menuReservaLote(){
    printf("===   MENU DE RESERVA DO LOTE   ===\n");
    printf(":: Tenda              4,50 Euros ::\n");
    printf(":: Caravana           6,00 Euros ::\n");
    printf(":: Autocaravana      14,50 Euros ::\n");
    printf(":: ----------------------------- ::\n");
    printf(":: +Eletricidade      3,00 Euros ::\n");
    printf(":: Cada campista      3,50 Euros ::\n");
    printf("===================================\n");
}

//void registaDadosParque(){//regista os dados do lote na reservaAtual
//
//    if (parque[pedeLinha][pedeColuna].reservaAtual.tipo != NULL){
//        parque[pedeLinha][pedeColuna].ultimasReservas[0] = parque[pedeLinha][pedeColuna].reservaAtual;
//    }
//
//    if (lerDadosEletricidade()){//se a eletricidade for true regista na reservaAtual como true
//        parque[pedeLinha-1][pedeColuna-1].reservaAtual.eletricidade = true;
//    }else{//caso contrario regista como false
//        parque[pedeLinha-1][pedeColuna-1].reservaAtual.eletricidade = false;
//    }
//    //regista os dados do lote na reservaAtual
//    parque[pedeLinha-1][pedeColuna-1].reservaAtual.tipo = criarLote.tipo;
//    parque[pedeLinha-1][pedeColuna-1].reservaAtual.custoTotal = criarLote.custoTotal;
//    parque[pedeLinha-1][pedeColuna-1].reservaAtual.numCampista = criarLote.numCampista;
//
//    for (int i = 0; i < parque[pedeLinha-1][pedeColuna-1].reservaAtual.numCampista; ++i){//regista os dados do utilizador na reservaAtual
//        strcpy(parque[pedeLinha-1][pedeColuna-1].reservaAtual.dados[i].nome, criarLote.dados[i].nome);
//        parque[pedeLinha-1][pedeColuna-1].reservaAtual.dados[i].idade = criarLote.dados[i].idade;
//    }
//}

void pedirDadosLotes(int linha, int coluna){
    char eletricidade, tipoAloj;
    int numCampistas = 0;

    //temporario
    if(criarLote[linha-1][coluna-1].reservaAtual.tipoAlojamento != NULL){
        printf("\n==ERRO! Lote j� est� reservado!==\n");
        return;
    }

    criarLote[linha-1][coluna-1].reservaAtual.coordenadasLin = linha;
    criarLote[linha-1][coluna-1].reservaAtual.coordenadasCol = coluna;
    criarLote[linha-1][coluna-1].reservaAtual.preco = 0;

    do{
        menuReservaLote();
        printf("Tipo de alojamento [ (T)enda // (C)aravana // (A)utocaravana ]: ");
        scanf("%c", &tipoAloj);
        fflush(stdin);

        switch(tolower(tipoAloj)){
            case 't':
                criarLote[linha-1][coluna-1].reservaAtual.tipoAlojamento = 'T';
                criarLote[linha-1][coluna-1].reservaAtual.preco += 4.50;
                break;

            case 'c':
                criarLote[linha-1][coluna-1].reservaAtual.tipoAlojamento = 'C';
                criarLote[linha-1][coluna-1].reservaAtual.preco += 6.00;
                break;

            case 'a':
                criarLote[linha-1][coluna-1].reservaAtual.tipoAlojamento = 'A';
                criarLote[linha-1][coluna-1].reservaAtual.preco += 14.90;

                break;
            default:
                printf("\n==ERRO! Caract�r inv�lido!==\n\n");
        }

    }while(tolower(tipoAloj) !='t' && tolower(tipoAloj) !='c' && tolower(tipoAloj) !='a');

    do{
        printf("Tem liga��o � rede eletrica (S/N): ");
        scanf("%c", &eletricidade);
        fflush(stdin);

        switch(tolower(eletricidade)){
            case 's':
                criarLote[linha-1][coluna-1].reservaAtual.redeEletrica = 'e';
                criarLote[linha-1][coluna-1].reservaAtual.preco += 3.00;
                break;

            case 'n':
                criarLote[linha-1][coluna-1].reservaAtual.redeEletrica = 'x';
                break;

            default:
                printf("\n==ERRO! Caract�r inv�lido!==\n");
        }

    }while(tolower(eletricidade) !='s' && tolower(eletricidade) !='n');

    do{
        printf("===== Dados do(s) campista(s) =====");
        printf("\nN�mero de campistas: ");
        scanf("%d", &numCampistas);
        fflush(stdin);

        if(numCampistas > 6)
            printf("\n==ERRO! N�mero m�ximo campistas � 6!==\n");
        else if(numCampistas <= 0)
            printf("\n==ERRO! Valor inserido n�o pode ser menor ou igual a zero!==\n");
        else if(isalpha(numCampistas) != 0)
            printf("\n==ERRO! Valor inserido n�o � um n�mero!==\n");
        else{
            criarLote[linha-1][coluna-1].reservaAtual.numeroCampistas = numCampistas;
            criarLote[linha-1][coluna-1].reservaAtual.preco += numCampistas * 3.50;
        }

    }while(numCampistas <= 0 && numCampistas > 6 && isalpha(numCampistas) == 0 );

    for(int i = 0 ; i < numCampistas; i++){
        printf("Nome do %d� campista: ", i+1);
        gets(criarLote[linha-1][coluna-1].reservaAtual.pessoaCampista[i].nome);

        do{
            printf("Idade do %d� campista: ", i+1);
            scanf("%d", &criarLote[linha-1][coluna-1].reservaAtual.pessoaCampista[i].idade);
            fflush(stdin);
        }while(criarLote[linha-1][coluna-1].reservaAtual.pessoaCampista[i].idade <= 0);
    }

    consultarLotes(linha, coluna);

}

void consultarLotes(int linha, int coluna){

    if(criarLote[linha-1][coluna-1].reservaAtual.tipoAlojamento == NULL){
        printf("\n==ERRO! Este lote n�o est� reservado!==\n");
        return;
    }

    printf("\n\n===   INFORMA��O DO LOTE   ===");
    printf("\n::Tipo de alojamento: ");
    switch(criarLote[linha-1][coluna-1].reservaAtual.tipoAlojamento){
        case 'T':
            printf("Tenda");
            break;
        case 'C':
            printf("Caravana");
            break;
        default:
            printf("Autocaravana");
    }

    printf("\n::Rede eletrica: ");
    switch(criarLote[linha-1][coluna-1].reservaAtual.redeEletrica){
        case 'e':
            printf("Sim");
            break;
        default:
            printf("N�o");
    }

    printf("\n::N�mero de campistas: %d", criarLote[linha-1][coluna-1].reservaAtual.numeroCampistas);
    for(int i = 0; i < criarLote[linha-1][coluna-1].reservaAtual.numeroCampistas; i++){
        printf("\n::Campista n�%d: %s", i+1, criarLote[linha-1][coluna-1].reservaAtual.pessoaCampista[i].nome);
        printf("\n::Idade%9s%d", ": ", criarLote[linha-1][coluna-1].reservaAtual.pessoaCampista[i].idade);
    }

    printf("\n::Pre�o: %.2f Euro(s)\n", criarLote[linha-1][coluna-1].reservaAtual.preco);

    printf("==============================\n\n");

}

void editarReservaLote(int linha, int coluna){

}

void libertarReserva(int linha, int coluna){
    if(criarLote[linha][coluna].ultimasReservas[i] != NULL)
        criarLote[linha][coluna].ultimasReservas[i] = criarLote[linha][coluna].reservaAtual;
    }
    printf("-- Reserva de lote libertada com sucesso! --")
}


void escreverDadosFicheirosLotes(){
    FILE *f;
    f = fopen("reservaLote.bin", "wb");

    if(f == NULL){
        printf("\n==ERRO! Ficheiro n�o existe.==\n");
        return;
    }

    fwrite(&criarLote, sizeof(reserva), MAX_LINHAS*MAX_COLUNAS, f);
    fwrite(&Mapa, sizeof(mapa), MAX_LINHAS*MAX_COLUNAS, f);
    fclose(f);
}

void lerDadosFicheiroLotes(){
    FILE *f;
    f = fopen("reservaLote.bin", "rb");

    if(f == NULL){
        printf("\n==ERRO! Ficheiro n�o existe.==\n");
        return;
    }

    fread(&criarLote, sizeof(reserva), MAX_LINHAS*MAX_COLUNAS, f);
    fread(&Mapa, sizeof(mapa), MAX_LINHAS*MAX_COLUNAS, f);
    fclose(f);
}

