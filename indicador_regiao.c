#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define X 0
#define Y 1

#define DENTRO_AREA 1
#define FORA_AREA 0

#define LINHA_TABELA 25
#define COLUNA_TABELA 9



typedef char(Target)[COLUNA_TABELA][LINHA_TABELA];

void printar_matriz(size_t linha, size_t coluna,Target *matriz);

int indicador_regiao(Target (*matriz2D), int *elemento, int *ponto, int area)
{
    int definir_linha,definir_coluna = 0;
    char passo = '+';

    //definindo a area
    for(definir_coluna=0;definir_coluna<=area;definir_coluna++)
    {
        for(definir_linha=0;definir_linha<=area;definir_linha++)
        {

            if(((*matriz2D)[ponto[Y]-definir_coluna][ponto[X]-definir_linha]>LINHA_TABELA)||((*matriz2D)[ponto[Y]-definir_coluna][ponto[X]+definir_linha]>LINHA_TABELA)||((*matriz2D)[ponto[Y]+definir_coluna][ponto[X]-definir_linha]>LINHA_TABELA)||((*matriz2D)[ponto[Y]+definir_coluna][ponto[X]+definir_linha]>LINHA_TABELA)||((*matriz2D)[ponto[Y]-definir_coluna][ponto[X]-definir_linha]>COLUNA_TABELA)||((*matriz2D)[ponto[Y]-definir_coluna][ponto[X]+definir_linha]>COLUNA_TABELA)||((*matriz2D)[ponto[Y]+definir_coluna][ponto[X]-definir_linha]>COLUNA_TABELA)||((*matriz2D)[ponto[Y]+definir_coluna][ponto[X]+definir_linha]>COLUNA_TABELA))
            {
                printf("Area fora da matriz! Ignorando...\n");
            }else
                {
                    if((*matriz2D)[ponto[Y]-definir_coluna][ponto[X]-definir_linha]=='\0')
                    {
                        (*matriz2D)[ponto[Y]-definir_coluna][ponto[X]-definir_linha] = passo;
                    }else
                        {
                            printf("Area ocupada!\n");
                        }

                    if((*matriz2D)[ponto[Y]+definir_coluna][ponto[X]-definir_linha]=='\0')
                    {
                        (*matriz2D)[ponto[Y]+definir_coluna][ponto[X]-definir_linha] = passo;
                    }else
                        {
                            printf("Area ocupada!\n");
                        }

                    if((*matriz2D)[ponto[Y]-definir_coluna][ponto[X]+definir_linha]=='\0')
                    {
                        (*matriz2D)[ponto[Y]-definir_coluna][ponto[X]+definir_linha] = passo;
                    }else
                        {
                            printf("Area ocupada!\n");
                        }

                    if((*matriz2D)[ponto[Y]+definir_coluna][ponto[X]+definir_linha]=='\0')
                    {
                        (*matriz2D)[ponto[Y]+definir_coluna][ponto[X]+definir_linha] = passo;
                    }else
                        {
                            printf("Area ocupada!\n");
                        }

                }

        }
    }

    printar_matriz(COLUNA_TABELA,LINHA_TABELA,matriz2D);

    if((*matriz2D)[elemento[Y]][elemento[X]]=='X')
    {
        printf("O elemento esta dentro da area!\n");
        return DENTRO_AREA;
    }else
        {
            printf("O elemento esta fora da area!\n");
            return FORA_AREA;
        }

    return FORA_AREA;
}

void printar_matriz(size_t linha, size_t coluna,Target *matriz)
{
    if (matriz == NULL)
    {
        printf("Erro! Erro nº %i, do tipo: %s", errno, strerror(errno));
        return;
    }

    size_t leitor1 = 0;
    size_t leitor2 = 0;

    for(leitor1=0;leitor1<linha;leitor1++)
    {
        printf("\n");
        for(leitor2=0;leitor2<coluna;leitor2++)
        {
            printf("%c", (*matriz)[leitor1][leitor2]);
        }
    }

    printf("\n Final da Leitura! \n");

    return;
}
