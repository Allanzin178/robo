#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "robo.h"

// Struct Ponto armazena cada ponto onde o robô girou 90 graus no sentido anti horario
// Struct Caminho (lista encadeada) armazena cada ponto onde o robô teve que realizar esse movimento
Caminho *iniciarCaminho(int N)
{
    Caminho *caminho = (Caminho *)malloc(sizeof(Caminho));
    if (caminho == NULL)
    {
        printf("Erro ao alocar memória para a lista.\n");
        exit(1);
    }

    caminho->Origem = (Ponto *)malloc(sizeof(Ponto));
    if (caminho->Origem == NULL)
    {
        printf("Erro ao alocar memória para o ponto de origem.\n");
        free(caminho);
        exit(1);
    }

    // Ponto *ponto = (Ponto *)malloc(sizeof(Ponto));
    // if (ponto == NULL){
    //     printf("Erro ao alocar memória para o ponto.\n");
    //     free(caminho);
    //     exit(1);
    // }

    caminho->N = N;
    caminho->Distancia = 0;
    caminho->Origem->X = 0;
    caminho->Origem->Y = 0;

    return caminho;
}

Ponto Final(Caminho *C)
{
    int ciclos;
    int sinal = 0;
    int z = 0;
    int k = 1;
    Ponto Final;

    if (C->N == 0)
    {
        Final.X = 0;
        Final.Y = 0;
        return Final;
    }

    if (C->N < 0)
    {
        Final.X = 0;
        Final.Y = 0;
        Final.Próximo = NULL;
        return Final;
    }

    Ponto *anterior = C->Origem;

    for (ciclos = 1; ciclos <= C->N; ciclos++)
    {
        Ponto *atual = (Ponto *)malloc(sizeof(Ponto));
        if (atual == NULL)
        {
            printf("Erro ao alocar memoria ao novo ponto\n");
            exit(1);
        }
        atual->X = anterior->X;
        atual->Y = anterior->Y;
        anterior->Próximo = atual;

        // printf("%d e %d\n", ciclos%2, ciclos);
        // printf("X = %d e Y = %d e K = %d e sinal = %d\n", anterior->X, anterior->Y, k, sinal);
        if (ciclos % 2 != 0)
        {
            if (sinal == 0)
            {
                atual->X = atual->X + k;
            }
            else
            {
                atual->X = atual->X - k;
            }
        }
        else
        {
            if (sinal == 0)
            {
                atual->Y = atual->Y + k;
            }
            else
            {
                atual->Y = atual->Y - k;
            }
        }
        z++;
        if (z == 2)
        {
            sinal = 1;
            k++;
        }
        if (z == 4)
        {
            sinal = 0;
            k++;
            z = 0;
        }

        anterior = atual;
    }
    Final.X = anterior->X;
    Final.Y = anterior->Y;

    return Final;
}

int Distancia(Caminho *C)
{
    int distancia = 0;
    int j = 1;

    if (C->N <= 0)
    {
        return 0;
    }

    for (int i = 1; i <= C->N; i++)
    {
        distancia += j;
        if (i % 2 == 0)
        {
            j++;
        }
    }
    return distancia;
}
