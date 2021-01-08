/*
|| Projeto Gest�o de Reservas de Parque de Campismo
||============================================================================
|| Autores : +Rodrigo Nogueira - 200262002 - 200262002@estudantes.ips.pt
||           +Ricardo Reis     - 200262024 - 200262024@estudantes.ips.pt
||============================================================================
|| 1� Fase de Entrega
*/

#ifndef CAMPISTA_H_INCLUDED
#define CAMPISTA_H_INCLUDED

typedef struct{
    char nome[101];
    int idade;
} campista;

campista criarCampista(char *nome, int idade);

#endif // CAMPISTA_H_INCLUDED
