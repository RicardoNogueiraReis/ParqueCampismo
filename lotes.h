/*
|| Projeto Gest�o de Reservas de Parque de Campismo
||============================================================================
|| Autores : +Rodrigo Nogueira - 200262002 - 200262002@estudantes.ips.pt
||           +Ricardo Reis     - 200262024 - 200262024@estudantes.ips.pt
||============================================================================
|| 1� Fase de Entrega
*/
#ifndef LOTES_H_INCLUDED
#define LOTES_H_INCLUDED
#include "campista.h"
#include "mapa.h"



typedef struct{
    campista pessoaCampista;
    char tipoAlojamento; // T - tenda, C - caravana ou A - autocaravana
    char redeEletrica; // e - Se tem rede eletrica, x - Se n�o tem rede eletrica
    int numeroCampistas; // N�mero de campistas por lote
    float preco;
    /* Tenda - 4,50�
     * Caravana - 6,00�
     * Autocaravana - 14,90�
     * Eletricidade - 3,00�
     * Campista - 3,50�
     */
} lote;

void pedirCoordenadasLote(int *linha, int *coluna);
void pedirDadosLotes(lote *reservaLote[][10]);

#endif // LOTES_H_INCLUDED
