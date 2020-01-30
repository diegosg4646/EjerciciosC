#include <stdio.h>
#define NUM_DE_ELEMENTOS 5

int main(int argc, char const *argv[])
{
    /* Introducir por teclado 5 valores y ponerlos en un array y calcular su suma */
    int numeros[NUM_DE_ELEMENTOS];
    int suma=0;

    for (int i = 0; i < NUM_DE_ELEMENTOS; i++)
    {
        printf("Introduce el numero de la posicion %d: \n", i);
        scanf("%d", &numeros[i]);
        suma = suma + numeros[i];
    }

    printf("\nEl resultado de la suma es: %d\n\n", suma);

    return 0;
}
