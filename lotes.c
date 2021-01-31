/*
|| Projeto Gest�o de Reservas de Parque de Campismo
||============================================================================
|| Autores : +Rodrigo Nogueira - 200262002 - 200262002@estudantes.ips.pt
||           +Ricardo Reis     - 200262024 - 200262024@estudantes.ips.pt
||============================================================================
|| 2� Fase de Entrega
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "campista.h"
#include "lotes.h"
#include "mapa.h"

/*
 * =>*pedirLinha e *pedirColuna
 * S�o as coordenadas do lote que o utilizador pretende reservar.
 * NOTA: esta fun��o N�O verifica se o lote est� ocupado,
 *isso estar� para o "pedirDadosLotes()"
 *
*/

void informacaoLotes(int linha, int coluna);
void libertarReserva(int linha, int coluna);

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
        else if(*pedirLinha > MAX_LINHAS)
            printf("\n==ERRO! N�mero de linhas n�o pode exceder o m�ximo de %d==\n", MAX_LINHAS);

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

void definirTipoAlojamento(int linha, int coluna){
    char tipoAloj;
    do{
        menuReservaLote();
        printf("Tipo de alojamento [ (T)enda // (C)aravana // (A)utocaravana ]: ");
        scanf("%c", &tipoAloj);
        fflush(stdin);

        switch(tolower(tipoAloj)){
            case 't':
                criarLote[linha-1][coluna-1].reservaAtual.tipoAlojamento = 'T';
                break;
            case 'c':
                criarLote[linha-1][coluna-1].reservaAtual.tipoAlojamento = 'C';
                break;
            case 'a':
                criarLote[linha-1][coluna-1].reservaAtual.tipoAlojamento = 'A';
                break;
            default:
                printf("\n==ERRO! Caract�r inv�lido!==\n\n");
        }

    }while(tolower(tipoAloj) !='t' && tolower(tipoAloj) !='c' && tolower(tipoAloj) !='a');
}

void definirRedeEletrica(int linha, int coluna){
    char eletricidade;
    do{
        printf("Tem liga��o � rede eletrica (S/N): ");
        scanf("%c", &eletricidade);
        fflush(stdin);

        switch(tolower(eletricidade)){
            case 's':
                criarLote[linha-1][coluna-1].reservaAtual.redeEletrica = 'e';
                break;

            case 'n':
                criarLote[linha-1][coluna-1].reservaAtual.redeEletrica = 'x';
                break;

            default:
                printf("\n==ERRO! Caract�r inv�lido!==\n");
        }

    }while(tolower(eletricidade) !='s' && tolower(eletricidade) !='n');
}

void definirNumeroCampistas(int linha, int coluna){
    int numCampistas = 0;
    criarLote[linha-1][coluna-1].reservaAtual.numeroCampistas = 0;
    do{
        printf("===== Dados do(s) campista(s) =====");
        printf("\nN�mero de campistas: ");
        scanf("%d", &numCampistas);
        fflush(stdin);

        //
        if(isalpha(numCampistas) != 0)
            printf("\n==ERRO! Valor inserido n�o � um n�mero!==\n");
        else if(numCampistas > 6)
            printf("\n==ERRO! N�mero m�ximo campistas � 6!==\n");
        else if(numCampistas <= 0)
            printf("\n==ERRO! Valor inserido n�o pode ser menor ou igual a zero!==\n");
        else{
            criarLote[linha-1][coluna-1].reservaAtual.numeroCampistas = numCampistas;
        }

    }while(numCampistas <= 0 || numCampistas > 6 || isdigit(numCampistas) != 0 );
}

void definirCampistas(int linha, int coluna){
    char nomeCampista[101];
    int idade = 0;;

    for(int i = 0 ; i < criarLote[linha-1][coluna-1].reservaAtual.numeroCampistas; i++){
        do{
            printf("Nome do %d� campista: ", i+1);
            gets(nomeCampista);

            if (strlen(nomeCampista) > 100)
                printf("\n==ERRO! Nome excede o limite de 100 caracteres!==\n");

        }while(strlen(nomeCampista) > 100);

        strcpy(criarLote[linha-1][coluna-1].reservaAtual.pessoaCampista[i].nome, nomeCampista);

        do{
            printf("Idade do %d� campista: ", i+1);
            scanf("%d", &idade);
            fflush(stdin);

            if(idade <= 0)
                printf("\n==ERRO! Idade tem de ser maior que zero!==\n");
            else if(isalpha(idade) != 0)
                printf("\n==ERRO! Idade tem de ser um numero!==\n");


        }while(idade <= 0 || isalpha(idade) != 0);

        criarLote[linha-1][coluna-1].reservaAtual.pessoaCampista[i].idade = idade;
    }
}

void adicionarCampista(int linha, int coluna){
    int maisCampistas = 0, campistasAMais = 0, idade;
    char nomeCampista[101];

    if(criarLote[linha-1][coluna-1].reservaAtual.numeroCampistas == 6){
        printf("==ERRO! Neste lote o numero de campistas esta no limite!==\n");
        return;
    }

    do{
        printf("Quantos campistas pretende adicionar?\n");
        scanf("%d", &maisCampistas);
        fflush(stdin);

        campistasAMais = maisCampistas + criarLote[linha-1][coluna-1].reservaAtual.numeroCampistas;

        if(isalpha(maisCampistas) != 0)
            printf("==ERRO! Valor introduzido n�o e um numero!==\n");
        else if (campistasAMais > 6)
            printf("==ERRO! N�mero de campistas excede o limite de 6 campistas! (%d a mais)==\n", campistasAMais - 6);

    }while(campistasAMais > 6 || isalpha(maisCampistas) != 0);


    for(int i = criarLote[linha-1][coluna-1].reservaAtual.numeroCampistas; i < campistasAMais; i++){

        do{
            printf("Nome do %d� campista: ", i+1);
            gets(nomeCampista);

            if(strlen(nomeCampista) > 100)
                printf("\n==ERRO! Nome excede o limite de 100 caracteres!==\n");

        }while(strlen(nomeCampista) > 100);

        criarLote[linha-1][coluna-1].reservaAtual.numeroCampistas++;
        strcpy(criarLote[linha-1][coluna-1].reservaAtual.pessoaCampista[i].nome, nomeCampista);

        do{
            printf("Idade do %d� campista: ", i+1);
            scanf("%d", &idade);
            fflush(stdin);

            if(idade <= 0)
                printf("\n==ERRO! Idade tem de ser maior que zero!==\n");
            else if(isalpha(idade) != 0)
                printf("\n==ERRO! Idade tem de ser um numero!==\n");


        }while(idade <= 0 || isalpha(idade) != 0);

        criarLote[linha-1][coluna-1].reservaAtual.pessoaCampista[i].idade = idade;
    }
}
// Por fazer
//void removerCampista(int linha, int coluna){
//    int campistaARemover;
//
//    printf("\nQual � o campista que deseja remover?\n");
//    printf("--------------------\n");
//    for(int i = 0; i < criarLote[linha-1][coluna-1].reservaAtual.numeroCampistas; i++)
//        printf("%d %s\n", i+1, criarLote[linha-1][coluna-1].reservaAtual.pessoaCampista[i].nome);
//
//    do{
//        scanf("%d", &campistaARemover);
//
//        if(campistaARemover > criarLote[linha-1][coluna-1].reservaAtual.numeroCampistas)
//            printf("\n==ERRO! O numero do campista esta fora do limite!==\n");
//        else if(campistaARemover <= 0)
//            printf("\n==ERRO! O numero do campista esta fora do limite!==\n");
//        else if(isalpha(campistaARemover) != 0)
//            printf("\n==ERRO! Valor inserido nao � um numero!==\n");
//
//
//    }while(campistaARemover <= 0 || isalpha(campistaARemover) != 0 || campistaARemover > 6);
//
//    for(int i = campistaARemover; i < criarLote[linha-1][coluna-1].reservaAtual.numeroCampistas; i++){
//        criarLote[linha-1][coluna-1].reservaAtual.pessoaCampista[i] = criarLote[linha-1][coluna-1].reservaAtual.pessoaCampista[i+1];
//        criarLote[linha-1][coluna-1].reservaAtual.pessoaCampista[i+1] = NULL;
//
//    }
//
//}

void verificarPreco(int linha, int coluna){
    float preco = 0, mais = 0;
    switch(criarLote[linha-1][coluna-1].reservaAtual.tipoAlojamento){
        case 'T':
            preco += 4.5;
            break;
        case 'C':
            preco += 6.00;
            break;
        case 'A':
            preco += 14.9;
            break;
    }

    if(criarLote[linha-1][coluna-1].reservaAtual.redeEletrica == 'e')
        preco += 3.00;

    mais = 3.50 * criarLote[linha-1][coluna-1].reservaAtual.numeroCampistas;
    preco += mais;


    criarLote[linha-1][coluna-1].reservaAtual.preco = 0;
    criarLote[linha-1][coluna-1].reservaAtual.preco = preco;
}

void pedirDadosLotes(int linha, int coluna){
    char confirmacao;
    if(criarLote[linha-1][coluna-1].reservaAtual.tipoAlojamento != NULL){
        do{
            printf("\n**ATEN��O! Lote j� est� reservado. Deseja apagar o atual e reservar aqui um novo?[S/n]**\n");
            scanf("%c", &confirmacao);
            fflush(stdin);

            if(tolower(confirmacao) != 's' && tolower(confirmacao) != 'n')
                printf("\n==ERRO! Caract�r inv�lido!==\n\n");
            else if (tolower(confirmacao) == 'n')
                return;

        }while(tolower(confirmacao) != 's');

        libertarReserva(linha, coluna);
    }

    criarLote[linha-1][coluna-1].reservaAtual.coordenadasLin = linha;
    criarLote[linha-1][coluna-1].reservaAtual.coordenadasCol = coluna;
    criarLote[linha-1][coluna-1].reservaAtual.preco = 0;

    definirTipoAlojamento(linha, coluna);

    definirRedeEletrica(linha, coluna);

    definirNumeroCampistas(linha, coluna);

    definirCampistas(linha, coluna);

    verificarPreco(linha, coluna);

    if(criarLote[linha-1][coluna-1].reservaAtual.tipoAlojamento == NULL)
        printf("\n==ERRO! N�o foi possivel guardar informa��o de lote por algum motivo==\n");
    else{
        printf("\n++Lote reservado com sucesso!++\n");
        informacaoLotes(linha, coluna);
    }
}

void consultarLotes(int linha, int coluna){
    char consulta;
    do{
        printf("\n*Quer consultar a reserva [a]tual ou o seu [h]istorico?");
        scanf("%c", &consulta);
        switch(tolower(consulta)){
            case 'a':
                informacaoLotes(linha, coluna);
                break;
            case 'h':
                mostrarHistoricoDoLote(linha, coluna);
                break;
            default:
                printf("\n==ERRO! Caracter invalido!==\n\n");
        }

    }while(tolower(consulta) !='a' && tolower(consulta) !='h');
}

void mostrarHistoricoDoLote(int linha, int coluna){

    if(criarLote[linha][coluna].ultimasReservas[0].tipoAlojamento == NULL){
        printf("\nEsta reserva ainda nao tem historico\n");
        return;
    }

    for(int i = 0; i < 3; i++){
        printf("\n Entrada do historico numero [%d] do lote [%d][%d]", i+1, linha, coluna);
        printf("\n =================================================\n");
        printf("Tipo de alojamento: ", criarLote[linha][coluna].ultimasReservas[i].tipoAlojamento);

        if(criarLote[linha][coluna].ultimasReservas[i].redeEletrica = 'e')
            printf("\nTinha rede eletrica? Sim");
        else
            printf("\nTinha rede eletrica? Nao");

        printf("\nNumero de campistas: ", criarLote[linha][coluna].ultimasReservas[i].numeroCampistas);
        for(int c = 0; c < criarLote[linha][coluna].ultimasReservas[i].numeroCampistas; c++){
            printf("\n%s (%d)", criarLote[linha][coluna].ultimasReservas[i].pessoaCampista[c].nome, criarLote[linha][coluna].ultimasReservas[i].pessoaCampista[c].idade);
        }

    }
}

void informacaoLotes(int linha, int coluna){
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
        printf("\n+:Campista n�%d: %s", i+1, criarLote[linha-1][coluna-1].reservaAtual.pessoaCampista[i].nome);
        printf("\n+:Idade%9s%d", ": ", criarLote[linha-1][coluna-1].reservaAtual.pessoaCampista[i].idade);
    }

    printf("\n::Pre�o: %.2f Euro(s)\n", criarLote[linha-1][coluna-1].reservaAtual.preco);

    printf("==============================\n");

}

void editarReservaLote(int linha, int coluna){
    int detalhe, check;

    if(criarLote[linha-1][coluna-1].reservaAtual.tipoAlojamento == NULL){
        printf("\n==ERRO! Este lote n�o est� reservado!==\n");
        return;
    }

    do{
        informacaoLotes(linha, coluna);

        printf("\n*Qual � o detalhe que deseja alterar?");
        printf("\n-------------------------------------\n");
        printf("1 - Tipo de alojamento\n");
        printf("2 - Rede eletrica\n");
        printf("3 - Adicionar campista\n");
        printf("4 - Remover campista\n");
        printf("0 - Sair\n");
        scanf("%d", &detalhe);
        fflush(stdin);

        if(isalpha(detalhe) != 0){
            system("cls");
            printf("\n==ERRO! Op��o escolhida tem de ser um n�mero!==");
        }
        else if(detalhe > 4 || detalhe < 0){
            system("cls");
            printf("\n==ERRO! Op��o escolhida n�o est� no menu!==\n");
        }

        switch(detalhe){
            case 1:
                definirTipoAlojamento(linha, coluna);
                break;
            case 2:
                definirRedeEletrica(linha, coluna);
                break;
            case 3:
                adicionarCampista(linha, coluna);
                break;
            case 4:
//                removerCampista(linha, coluna);
                break;
        }

        verificarPreco(linha, coluna);

    }while(isalpha(detalhe) != 0 || detalhe != 0);
}

void anularInfo(int linha, int coluna){
    if(criarLote[linha-1][coluna-1].reservaAtual.tipoAlojamento != NULL){
        criarLote[linha-1][coluna-1].reservaAtual.tipoAlojamento = NULL;
        criarLote[linha-1][coluna-1].reservaAtual.redeEletrica = NULL;
        criarLote[linha-1][coluna-1].reservaAtual.numeroCampistas = NULL;
        criarLote[linha-1][coluna-1].reservaAtual.preco = 0;
        criarLote[linha-1][coluna-1].reservaAtual.coordenadasCol = NULL;
        criarLote[linha-1][coluna-1].reservaAtual.coordenadasLin = NULL;

        for(int i=0; i<criarLote[linha-1][coluna-1].reservaAtual.numeroCampistas; i++){
            strcpy(criarLote[linha-1][coluna-1].reservaAtual.pessoaCampista[i].nome, NULL);
            criarLote[linha-1][coluna-1].reservaAtual.pessoaCampista[i].idade = 0;
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

void pesquisarPorNomeCampista(int linha, int coluna, int i){
    char campistaAPesquisar[101];

    fflush(stdin);
    printf("Insira o nome do campista: \n");
    gets(campistaAPesquisar);
    fflush(stdin);

    for(int i=0; i<MAX_LINHAS; i++){
            for(int j=0; j<MAX_COLUNAS; j++){
                for(int a=0; a<criarLote[i][j].reservaAtual.numeroCampistas; a++){
    if(strcmp(criarLote[i][j].reservaAtual.pessoaCampista[a].nome, campistaAPesquisar) == 0){
    printf("\n===   Dados do Lote   ===\n");
    printf("Linha:[%d]  Coluna:[%d]\n", criarLote[i][j].reservaAtual.coordenadasLin,criarLote[i][j].reservaAtual.coordenadasCol);

    printf("Nome do(s) campista(s): ");
    for(int b=0; b < criarLote[i][j].reservaAtual.numeroCampistas; b++)
        printf(" %s |",criarLote[i][j].reservaAtual.pessoaCampista[b].nome);

    printf("\nIdade do(s) campista(s): ");
    for(int c = 0; c < criarLote[i][j].reservaAtual.numeroCampistas; c++)
        printf(" %d |", criarLote[i][j].reservaAtual.pessoaCampista[c].idade);

    printf("\nTipo de alojamento: ");
    if(criarLote[i][j].reservaAtual.tipoAlojamento == 'T')
        printf("Tenda\n");

    else if(criarLote[i][j].reservaAtual.tipoAlojamento == 'C')
        printf("Caravana\n");

    else if(criarLote[i][j].reservaAtual.tipoAlojamento =='A')
        printf("Autocaravana\n");


    if(criarLote[i][j].reservaAtual.redeEletrica)
        printf("Rede eletrica: Sim \n");
    else
        printf("Rede eletrica: Nao \n");


    printf("Preco da reserva: %.2f Euros\n", criarLote[i][j].reservaAtual.preco);
    printf("-----------------------------------------------------------------------\n");
}
                }
            }
        }
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
    /*Nao tem mensagem de erro caso o ficheiro nao seja encontrado porque na primeira vez que e iniciado
    *o programa, e obvio que o ficheiro ainda nao existe e como esta funcao e chamada no inicio da execucao
    *nao faz sentido avisar o utilizador de tal coisa para evitar confusao.
    */

    FILE *f;
    f = fopen("reservaLote.bin", "rb");

    fread(&criarLote, sizeof(reserva), MAX_LINHAS*MAX_COLUNAS, f);
    fread(&Mapa, sizeof(mapa), MAX_LINHAS*MAX_COLUNAS, f);
    fclose(f);
}

