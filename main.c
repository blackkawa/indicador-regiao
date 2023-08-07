#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"

#define DADOS_TABELA_COMPLETA_OBSTACULOS {{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},{'#','\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '#'},{'#','\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '#'},{'#','\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '#'},{'#','\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '#'},{'#','\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '#'},{'#','\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '#'},{'#','\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '#'},{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}}

#define LINHA_TABELA 25
#define COLUNA_TABELA 9

#define X 0
#define Y 1

/*
Este programa define um elemento em uma posição, e confere se ele esta na area em volta do ponto, e tendo esta area um tamanho determinado

Exemplo de Área do ponto:

+++
+O+
+++

++++
++++
++O++
++++
++++

*/

int main()
{
    int *posicao_elemento;

    posicao_elemento = malloc(6*sizeof(posicao_elemento));

    posicao_elemento[X] = 0;
    posicao_elemento[Y] = 0;

    int area = 0;

    char elemento = 'X';

    int *posicao_ponto;

    posicao_ponto = malloc(6*sizeof(posicao_ponto));

    posicao_ponto[X] = 0;
    posicao_ponto[Y] = 0;

    char ponto = 'O';

    Target linha_completa = DADOS_TABELA_COMPLETA_OBSTACULOS;

    printf("Alocando a matriz...\n");
    Target *matriz2D = (Target*)malloc(3*sizeof(Target));

    printf("Copiando as linhas para a matriz...\n");
    memcpy(matriz2D, linha_completa, sizeof(Target));

    if(matriz2D==NULL) return 1;

    printf("Printando matriz...\n");

    printar_matriz(COLUNA_TABELA,LINHA_TABELA,matriz2D);
    printf("\nO elemento a ser inserido e: %c\n", elemento);

    printf("\nDefina a posicao Y do elemento, de acordo com a matriz\n");
    scanf("%i", &posicao_elemento[Y]);
    fflush(stdin);

    printf("Defina a posicao X do elemento, de acordo com a matriz\n");
    scanf("%i", &posicao_elemento[X]);
    fflush(stdin);

    printf("A posicao inserida e: %i,%i\n", posicao_elemento[Y], posicao_elemento[X]);

    printf("Inserindo o elemento na matriz...\n");
    (*matriz2D)[posicao_elemento[Y]][posicao_elemento[X]] = elemento;

    printf("\n O elemento inserido foi: %c\n", (*matriz2D)[posicao_elemento[Y]][posicao_elemento[X]]);

    printf("\nDefina a posicao Y do ponto, de acordo com a matriz\n");
    scanf("%i", &posicao_ponto[Y]);
    fflush(stdin);
    printf("Defina a posicao X do ponto, de acordo com a matriz\n");
    scanf("%i", &posicao_ponto[X]);
    fflush(stdin);

    printf("A posicao inserida e: %i,%i\n", posicao_ponto[Y], posicao_ponto[X]);

    printf("Inserindo o elemento na matriz...\n");
    (*matriz2D)[posicao_ponto[Y]][posicao_ponto[X]] = ponto;

    printf("Defina a area do ponto\n");
    scanf("%i", &area);
    fflush(stdin);

    printar_matriz(COLUNA_TABELA,LINHA_TABELA,matriz2D);

    indicador_regiao((*matriz2D), posicao_elemento, posicao_ponto, area);

    printar_matriz(COLUNA_TABELA,LINHA_TABELA,matriz2D);

    free(matriz2D);

    free(posicao_elemento);

    free(posicao_ponto);

    return 0;
}

