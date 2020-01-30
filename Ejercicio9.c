#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define NUMERO_DE_OPORTUNIDADES 5
#define NUMERO_MAXIMO 50

//Uso bucle do while Solo cuando aciertas el número sale del bucle
int getRandom(); //inicialización de la función en C

int main(int argc, char const *argv[])
{
    int numeroAleatorio = getRandom();
    int tuNumero = 0;

    do
    {
        printf("Que numero estoy pensando: [del 1 al %d]:  ", NUMERO_MAXIMO );
        scanf("%d", &tuNumero);
    } while (tuNumero != numeroAleatorio);
        
        printf("\n\nAcertaste. El numero que habia pensado era:... %d\n", &numeroAleatorio);

    return 0;
}

int getRandom()
{
    int aleatorio;
    srand(time(NULL));
    aleatorio = rand() % NUMERO_MAXIMO;

    return aleatorio;
}