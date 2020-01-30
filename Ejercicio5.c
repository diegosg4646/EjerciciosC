#include "stdio.h"

/*
1. Dolor de cabeza -> Nada
2. Dolor de cabeza + Fiebre -> Gripe
3. Dolor de cabeza + Fiebre + Vienes de China -> Coronavirus
*/

int main(int argc, char const *argv[])
{
    int dolorDeCabeza = 0;
    int fiebre = 0;
    int origenChina = 0;

    printf("¿Te duele la cabeza? [0-No, 1-Si]");
    scanf("%d", &dolorDeCabeza);

    printf("¿Tienes fiebre? [0-No, 1-Si]");
    scanf("%d", &fiebre);

    printf("¿Has estado en China recientemente? [0-No, 1-Si]");
    scanf("%d", &origenChina);

    if (dolorDeCabeza == 1 && fiebre == 0 && origenChina == 0)
    {
        printf("No te pasa nada. Es solo un dolor de cabeza");
    }
    else if (fiebre == 1 && origenChina == 0)
    {
        printf("Tienes una gripe");
    }
    else if (origenChina == 1)
    {
        printf("Lo siento");
    }

    return 0;
}
