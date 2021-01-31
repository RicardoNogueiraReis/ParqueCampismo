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
#include <locale.h>
#include "campista.h"
#include "lotes.h"
#include "menu.h"
#include "mapa.h"

void menu(){
    char opcao; // Op��o escolhida do menu principal
    char opcaoSair; // Utilizado na confirma��o se o utilizador deseja mesmo sair. (opcao == 0)
    int pedirLinha=0, pedirColuna=0;

    do{
        fflush(stdin);
        printf("==         PARQUE DE CAMPISMO       ==\n");
        printf("1 - Visualizar o mapa do parque\n");
        printf("2 - Reservar lote\n");
        printf("3 - Consultar informa��o de lote\n");
        printf("4 - Pesquisar lote do nome de campista\n");
        printf("5 - Editar a reserva de um lote\n");
        printf("6 - Libertar reserva\n");
        printf("\n0 - Sair\n\n");
        scanf("%c", &opcao);
        fflush(stdin);

        // Algumas letras introduzidas s�o recebidas como op��es no menu,
        //isto previne a introdu��o de op��es que n�o est�o no menu
        if (opcao < '0' || opcao > '7')
            opcao = '9';

        switch(opcao){
            case '0':
                do{
                    printf("Deseja sair da aplica��o? (s/n): ");
                    scanf("%c", &opcaoSair);
                    fflush(stdin);

                    switch(tolower(opcaoSair)){
                        case 's':
                            printf("Adeus!\n");
                            escreverDadosFicheirosLotes();
                            break;
                        case 'n':
                            opcao=1;
                            puts("");
                            break;
                        default:
                            printf("==ERRO! Insira uma op��o v�lida!==\n");
                    }
                }while(opcao!=1 && (tolower(opcaoSair)!='s'));
                break;

            // Visualizar o mapa do parque
            case '1':
                // Se coluna � zero � porque o mapa dos lotes ainda n�o existe
                switch(Mapa.coluna){
                    case 0:
                        definirDimensoesLote(&Mapa.linha, &Mapa.coluna);
                    default:
                        apresentarMapa(Mapa.linha, Mapa.coluna);
                }
                break;
            // Reservar lote
            case '2':
                switch(Mapa.coluna){
                    // Se coluna � zero � porque o mapa dos lotes ainda n�o existe
                    case 0:
                        definirDimensoesLote(&Mapa.linha, &Mapa.coluna);
                    default:
                        system("cls");
                        apresentarMapa(Mapa.linha, Mapa.coluna);
                        pedirCoordenadasLote(&pedirLinha, &pedirColuna);
                        pedirDadosLotes(pedirLinha, pedirColuna);
                }
                break;
            // Consultar informa��o de lote
            case '3':
                switch(Mapa.coluna){
                    case 0:
                        definirDimensoesLote(&Mapa.linha, &Mapa.coluna);
                    default:
                        system("cls");
                        apresentarMapa(Mapa.linha, Mapa.coluna);
                        pedirCoordenadasLote(&pedirLinha, &pedirColuna);
                        consultarLotes(pedirLinha, pedirColuna);
                }
                break;
            // Pesquisar lote do nome de campista
            case '4':
                pesquisarPorNomeCampista(pedirLinha, pedirColuna);
                break;
            // Editar reserva
            case '5':
                switch(Mapa.coluna){
                    case 0:
                        definirDimensoesLote(&Mapa.linha, &Mapa.coluna);
                    default:
                        apresentarMapa(Mapa.linha, Mapa.coluna);
                        pedirCoordenadasLote(&pedirLinha, &pedirColuna);
                        system("cls");
                        editarReservaLote(pedirLinha, pedirColuna);
                }
                break;
            // Libertar reserva
            case '6':
                switch(Mapa.coluna){
                    case 0:
                        definirDimensoesLote(&Mapa.linha, &Mapa.coluna);
                    default:
                        apresentarMapa(Mapa.linha, Mapa.coluna);
                        pedirCoordenadasLote(&pedirLinha, &pedirColuna);
                        libertarReserva(pedirLinha, pedirColuna);
                }
                break;
            case '7':
                system("cls"); // Limpar o ecr�
                break;
            default:
                printf("\n==ERRO! Escolha uma op��o correspondente �s do menu!==\n");
        }
    }while(opcao!='0');
}
