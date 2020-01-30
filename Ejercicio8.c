#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMERO_DE_OPORTUNIDADES 5
#define NUMERO_MAXIMO 50

int getRandom();

int main(int argc, char const *argv[])
{
    int numero = getRandom();
    int numeroErrores = 0;
    int tuNumero = 0;

    for (int i = NUMERO_DE_OPORTUNIDADES; i >= 0; i--)
    {
        printf("Que numero estoy pensando... del 1 al %d", NUMERO_MAXIMO);
        scanf("%d", &tuNumero);

        if (tuNumero == numero)
        {
            printf("Enhorabuena... Acertaste\n");
            break;
        }
        else
        {
            printf("Fallaste... Intentos restantes... %d\n", i);
            numeroErrores++;
        }
    }

    if (numeroErrores == NUMERO_DE_OPORTUNIDADES)
    {
        printf("\n\nEl numero que habia pensado era:... \n");
        printf("%d", numero);
    }

    return 0;
}

int getRandom()
{
    int aleatorio;
    srand(time(NULL));
    aleatorio = rand() % NUMERO_MAXIMO;

    return aleatorio;
}