#include <stdio.h>
#define NUM_FILAS 3
#define NUM_COLUMNAS 5
#define FILA_A_SUMAR 3

int main(int argc, char const *argv[])
//3 caategorías (alimentacion(0), moda(1) juguetes(2))
//5 días de la semana (lunes-viernes)

{
    int ventas[NUM_FILAS][NUM_COLUMNAS];
    int suma = 0;

    for (int fila = 0; fila < NUM_FILAS; fila++)
    {
        for (int col = 0; col < NUM_COLUMNAS; col++)
        {
            ventas[fila][col] = 0; //Inicializar el array con 0
        }
    }

    // asignar varios valores a distintas posiciones del array
    ventas[0][0] = 10;
    ventas[1][2] = 15;
    ventas[2][3] = 8;
    ventas[2][0] = 31;

    // mostrar todo el contenido ordenado
    for (int fila = 0; fila < NUM_FILAS; fila++)
    {
        for (int col = 0; col < NUM_COLUMNAS; col++)
        {
            printf("%d-",ventas[fila][col]);
        }
        printf("\n"); //salto de línea
    }

    //sumar los valores de la tercera fila

    for (int col = 0; col < NUM_COLUMNAS; col++)
    {
        suma = suma + ventas[FILA_A_SUMAR-1][col];
    }

    printf("La suma total de la fila %d es: %d", FILA_A_SUMAR, suma);

    return 0;
}
