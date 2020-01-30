#include <stdio.h>
#define MAYORIA_DE_EDAD 18

int main(int argc, char const *argv[])
{
    int edad = 0;

    printf("Introduce tu edad:");
    scanf("%d", &edad);

    if (edad > 0)
    {
        if (edad >= MAYORIA_DE_EDAD)
        {
            printf("Eres mayor de edad");
        }
        else
        {
            printf("No eres mayor de edad");
        }
        }
    else
    {
        printf("no has nacido");
    }
    return 0;
}
