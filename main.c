#include <stdio.h>
#include <stdlib.h>
#include "robo.h"

int main(){
    Caminho *c1 = iniciarCaminho(16);
    Ponto final = Final(c1);
    printf("Posição final: X = %d, Y = %d\n", final.X, final.Y);
    printf("Primeira posição: X = %d, Y = %d\n", c1->Origem->Próximo->X, c1->Origem->Próximo->Y);
    printf("Segunda posição: X = %d, Y = %d\n", c1->Origem->Próximo->Próximo->X, c1->Origem->Próximo->Próximo->Y);
    printf("Distância: %d", Distancia(c1));
    // printf("Distância total percorrida: %d\n", Distancia(c1));
    
    // Liberar memória
    free(c1->Origem);
    free(c1);

    return 0;
}