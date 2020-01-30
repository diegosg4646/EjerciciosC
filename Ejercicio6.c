#include "stdio.h"

int main(int argc, char const *argv[])
{
    int idPelicula = 0;
    printf("1. El Irlandes\n");
    printf("2. Origen\n");
    printf("3. El Golpe\n");
    printf("4. Kick Ass\n");
    printf("5. El Padrino\n");

    printf("Introduce el numero de pelicula:");
    scanf("%d", &idPelicula);

   /* if (idPelicula == 1)
    {
        printf("Es la pelicula favorita de Miguel Angel");
    }
    else if (idPelicula == 2)
    {
        printf("Es la película favorita de Alejandro (columna 0");
    }
    else if (idPelicula == 3)
    {
        printf("Es la pelicula favorita de Alberto");
    }
    else if (idPelicula == 4)
    {
        printf("Es la pelicula favorita de Puri ");
    }
    else if (idPelicula == 5)
    {
        printf("Es la pelicula favorita de Pascual");
    }
    else
    {
        printf("No te gusta el cine");
    }
    */



// EVALUACION ANTERIOR ELSE IF CON SWITCH
// el break es opcional. Si no lo ponemos se ejecuta todo lo siguiente a la evaluación correcta sin evaluar mas.

    switch (idPelicula)
    {

    case 1:
        printf("Es la pelicula favorita de Miguel Angel");
        break;

    case 2:
        printf("Es la película favorita de Alejandro (columna 0");
        break;

    case 3:
        printf("Es la pelicula favorita de Alberto");
        break;

    case 4:
        printf("Es la pelicula favorita de Puri ");
        break;

    case 5:
        printf("Es la pelicula favorita de Pascual");
        break;

    default://es opcional 
        printf("No te gusta el cine");
        break;
    }

    return 0;
}
