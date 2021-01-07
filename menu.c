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

//lote reservaLote;
//
//void pedirDadosLotes(lote *reservaLote);


void menu(){
    int opcao; // Utilizado para verficar a op��o escolhida do menu principal
    char opcaoSair; // Utilizado para verficar a op��o escolhida na confirma��o se o utilizador deseja mesmo sair.
    int linha=0, coluna=0;
//    lote reservaLote[l][c];

    do{
        printf("1 - Visualizar o mapa do parque\n");
        printf("2 - Reservar lote\n");
        printf("3 - Consultar informa��o de lote\n");
        printf("4 - Pesquisar lote do nome de campista\n");
        printf("5 - Editar a reserva de um lote\n");
        printf("6 - Libertar reserva\n");
        printf("\n0 - Sair\n\n");
        scanf("%d", &opcao);
        fflush(stdin);

        switch(opcao){
            case 0:
                do{
                    printf("Deseja sair da aplica��o? (s/n): ");
                    scanf("%c", &opcaoSair);
                    fflush(stdin);

                    switch(tolower(opcaoSair)){
                        case 's':
                            printf("Adeus!\n");
                            break;
                        case 'n':
                            opcao=1;
                            puts("");
                            break;
                        default:
                            printf("Erro: Insira uma op��o v�lida!\n");
                    }
                }while(opcao!=1 && (tolower(opcaoSair)!='s'));

                break;

            //Visualizar o mapa do parque
            case 1:
                // Verifica se e coluna � zero
                //(n�o definida porque o lote n�o pode ter 0 colunas nem zero linhas)
                switch(coluna){
                    case 0:
                        mudarDimensoesLote(&linha, &coluna);
                        break;
                    default:
                        apresentarMapa(linha, coluna);
                }
                break;
            case 2:

                apresentarMapa(linha, coluna);
//                pedirCoordenadasLote(&l, &c);

//                reservaLote[l][c];
//                pedirDadosLotes(&reservaLote[l][c]);
                break;
            case 3:
                printf("3� op��o escolhida");
                break;
            case 4:
                printf("4� op��o escolhida");
                break;
            case 7:
                system("cls"); // Limpar o ecr�
                break;
            default:
                printf("Erro: Insira uma op��o v�lida!\n");
        }
    }while(opcao!=0);
}
