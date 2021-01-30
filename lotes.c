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
    printf("%c", criarLote[linha-1][coluna-1].reservaAtual.tipoAlojamento);
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
    int info;
    do{
        consultarLotes(linha, coluna);
        printf("\n====================================\n");
        printf("\n||Qual � o detalhe que deseja alterar?||\n");
        printf("\n====================================\n");
        printf("1 - Tipo de alojamento\n");
        printf("2 - Rede eletrica\n");
        printf("3 - Adicionar campista\n");
        printf("4 - Remover campista\n");
        printf("0 - Sair\n");
        scanf("%d", &info);
    }while(isalpha(info) == 0 && info != 0);
}

void anularInfo(int linha, int coluna){
    if(criarLote[linha-1][coluna-1].reservaAtual.tipoAlojamento != NULL){
        criarLote[linha-1][coluna-1].reservaAtual.tipoAlojamento = NULL;
        criarLote[linha-1][coluna-1].reservaAtual.redeEletrica = NULL;
        criarLote[linha-1][coluna-1].reservaAtual.numeroCampistas = NULL;
        criarLote[linha-1][coluna-1].reservaAtual.preco = 0;
        criarLote[linha-1][coluna-1].reservaAtual.coordenadasCol = NULL;
        criarLote[linha-1][coluna-1].reservaAtual.coordenadasLin = NULL;

        for(int i=0; i<criarLote[linha-1][coluna-1].reservaAtual.numeroCampistas; i+1){
            strcpy(criarLote[linha-1][coluna-1].reservaAtual.pessoaCampista[i].nome, NULL);
            criarLote[linha-1][coluna-1].reservaAtual.pessoaCampista[i].idade = NULL;
        }
    }
}

void libertarReserva(int linha, int coluna){

    if(criarLote[linha-1][coluna-1].reservaAtual.tipoAlojamento == NULL){
        printf("\n==ERRO! Este lote n�o est� reservado!==\n");
        return;
    }

    if(criarLote[linha-1][coluna-1].ultimasReservas[0].tipoAlojamento == NULL)
    {
        criarLote[linha-1][coluna-1].ultimasReservas[0] = criarLote[linha][coluna].reservaAtual;
        anularInfo(linha, coluna);
    }
    else if (criarLote[linha-1][coluna-1].ultimasReservas[1].tipoAlojamento == NULL)
    {
        criarLote[linha-1][coluna-1].ultimasReservas[1] = criarLote[linha-1][coluna-1].ultimasReservas[0];
        criarLote[linha-1][coluna-1].ultimasReservas[0] = criarLote[linha][coluna].reservaAtual;
        anularInfo(linha, coluna);
    }
    else if(criarLote[linha-1][coluna-1].ultimasReservas[2].tipoAlojamento == NULL)
    {
        criarLote[linha-1][coluna-1].ultimasReservas[2] = criarLote[linha-1][coluna-1].ultimasReservas[1];
        criarLote[linha-1][coluna-1].ultimasReservas[1] = criarLote[linha-1][coluna-1].ultimasReservas[0];
        criarLote[linha-1][coluna-1].ultimasReservas[0] = criarLote[linha][coluna].reservaAtual;
        anularInfo(linha, coluna);
    }
    else if(criarLote[linha-1][coluna-1].ultimasReservas[2].tipoAlojamento != NULL)
    {
        criarLote[linha-1][coluna-1].ultimasReservas[2] = criarLote[linha-1][coluna-1].ultimasReservas[1];
        criarLote[linha-1][coluna-1].ultimasReservas[1] = criarLote[linha-1][coluna-1].ultimasReservas[0];
        criarLote[linha-1][coluna-1].ultimasReservas[0] = criarLote[linha][coluna].reservaAtual;
        anularInfo(linha, coluna);
    }

    printf("\n-- Reserva de lote libertada com sucesso! --\n");
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

