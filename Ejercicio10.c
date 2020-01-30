#include <stdio.h>
#define NUM_ELEMENTOS 5
#define PAR 2

//Array - Vector
int main(int argc, char const *argv[])
{

    int edades[NUM_ELEMENTOS];

    for (int i = 0; i < NUM_ELEMENTOS; i++)
    {
        edades[i] = i * PAR;
        printf("Posiciones [%d]:%d\n",i,edades[i]);

    }

    return 0;
}
