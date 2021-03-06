#include <stdio.h>

#define DIMENSION 3
#define TRUE 1
#define FALSE 0
#define GANADOR 1
#define POSICION_VACIA 0

//********************tres en raya*****************************//

//Configuración
int tablero[DIMENSION][DIMENSION]; //Declaracion tablero
int jugadasMaximas = ((DIMENSION * DIMENSION) / 2) + 1;

int jugador1PosicionVacia = FALSE; //Inicializar
int jugador2PosicionVacia = FALSE;

int jugador1Esganador = FALSE;
int jugador2EsGanador = FALSE;

void inicializarTablero();
void mostrarTablero();
int comprobarTresEnRaya();
int validarDatosDeEntrada();
void mostrarResultado();

int filaComprobar = 0;
int columnaComprobar = 0;

int contadorDeJugadas = 0;

int comprobarDatos = FALSE;

int main(int argc, char const *argv[])
{
    inicializarTablero();
    mostrarTablero();

    do //Bucle Principal de juego Termina cuando uno de los jugadores gane o se llene el tablero
    {
        contadorDeJugadas++;
        printf("\nIntentos: %d/%d\n", contadorDeJugadas, jugadasMaximas);

        do // JUGADOR 1 (X)
        {

            do
            {
                printf("\nJugador 1: \n");
                printf("Introduce una posicion para tu ficha Jugador 1 [fila]");
                scanf("%d", &filaComprobar);

                printf("Introduce una posicion para tu ficha Jugador 1 [columna]");
                scanf("%d", &columnaComprobar);

            } while (validarDatosDeEntrada() == FALSE);


            //Comprobar que la posicion está vacia
            if (tablero[filaComprobar][columnaComprobar] == POSICION_VACIA)
            {
                tablero[filaComprobar][columnaComprobar] = 'X'; // Poner X en la posicion indicada
                mostrarTablero();

                jugador1PosicionVacia = TRUE;

                if (comprobarTresEnRaya() == TRUE)
                {
                    jugador1Esganador = GANADOR; //TRES EN RAYA JUGADOR 1
                }
            }
            else
            {
                //mensaje de error
                printf("La posicion no esta libre, elige otra\n");
                jugador1PosicionVacia = FALSE;
            }

        } while (jugador1PosicionVacia == FALSE);

        jugador2PosicionVacia = FALSE; //reiniciar su valor inicial

        //(contadorDeJugadas<jugadasMaximas) para controlar que la última jugada solo juega el jugador 1
        while ((jugador2PosicionVacia == FALSE) && (contadorDeJugadas < jugadasMaximas) && (jugador1Esganador != GANADOR))
        {
            do
            {
            //introduce una posicion en el tablero Jugador 2 (Y)
                printf("Jugador 2: \n");
                printf("Introduce una posicion para tu ficha Jugador 2 [fila]");
                scanf("%d", &filaComprobar);
                printf("Introduce una posicion para tu ficha Jugador 2 [columna]");
                scanf("%d", &columnaComprobar);

            } while (validarDatosDeEntrada() == FALSE); //Validacion datos de entrada


            //Comprobar que la posicion está vacia
            if (tablero[filaComprobar][columnaComprobar] == POSICION_VACIA)
            {
                // si esta vacia pintar una 'Y'
                tablero[filaComprobar][columnaComprobar] = 'Y';
                mostrarTablero();

                jugador2PosicionVacia = TRUE;

                //Comprobar que no es tres en raya
                if (comprobarTresEnRaya() == TRUE)
                {
                    jugador2EsGanador = GANADOR; //TRES EN RAYA JUGADOR 2
                }
            }
            else
            {
                //mensaje de error
                printf("La posicion no esta libre, elige otra\n");
                jugador2PosicionVacia = FALSE;
            }
        }

    } while ((contadorDeJugadas < jugadasMaximas) && (jugador1Esganador != GANADOR && jugador2EsGanador != GANADOR));

    mostrarResultado();

    return 0;
}

void inicializarTablero()
{
    for (int i = 0; i < DIMENSION; i++)
    {
        for (int j = 0; j < DIMENSION; j++)
        {
            tablero[i][j] = 0;
        }
    }
}

void mostrarTablero()
{
    printf("\n");
    for (int i = 0; i < DIMENSION; i++)
    {
        for (int j = 0; j < DIMENSION; j++)
        {
            if (tablero[i][j] == POSICION_VACIA)
            {
                printf("%d  ", tablero[i][j]);
            }
            else
            {
                if (tablero[i][j] == 'X')
                {
                    printf("%c  ", tablero[i][j]);
                }
                else
                {
                    printf("%c  ", tablero[i][j]);
                }
            }
        }
        printf("\n");
    }
}

void mostrarResultado()
{

    printf("\n\nSe acabo. Total jugadas: %d\n\n", contadorDeJugadas);
    printf("Resultado: ");
    if (jugador1Esganador == jugador2EsGanador)
    {
        printf(".... EMPATE ....\n\n");
    }
    else if (jugador1Esganador == GANADOR)
    {
        printf(" .... Ganador Jugador 1 ....\n\n");
    }
    else
    {
        printf(".... Ganador Jugador 2 ....\n\n");
    }
}

int comprobarTresEnRaya()
{
    int resultado = FALSE;

    // Comprobar filas y columnas
    for (int i = 0; i < DIMENSION; i++)
    {

        //Comprobar filas

        if (tablero[i][0] != POSICION_VACIA) 
        {
            if ((tablero[i][0] == tablero[i][1]) && (tablero[i][1] == tablero[i][2]) && (tablero[i][0] == tablero[i][2]))
            {
                resultado = GANADOR;
            }

        //Comprobar columnas
            if (tablero[0][i] != POSICION_VACIA)
            {
                if ((tablero[0][i] == tablero[1][i]) && (tablero[1][i] == tablero[2][i]) && (tablero[0][i] == tablero[2][i]))
                {
                    resultado = GANADOR;
                }
            }
        }
    }

    // Comprobar diagonales
    if (tablero[0][0] != POSICION_VACIA)
    {
        if ((tablero[0][0] == tablero[1][1]) && (tablero[1][1] == tablero[2][2]) && (tablero[0][0] == tablero[2][2]))
        {
            resultado = GANADOR;
        }
    }

    if (tablero[2][0] != POSICION_VACIA)
    {
        if ((tablero[2][0] == tablero[1][1]) && (tablero[1][1] == tablero[0][2]) && (tablero[2][0] == tablero[0][2]))
        {
            resultado = GANADOR;
        }
    }

    return resultado;
}

int validarDatosDeEntrada()
{
    comprobarDatos = FALSE;
    if ((filaComprobar >= 0 && filaComprobar < DIMENSION) && (columnaComprobar >= 0 && columnaComprobar < DIMENSION))
    {
        comprobarDatos = TRUE;
    }
    else
    {
        //mensaje de error
        printf("\nError los numeros tienen que estar entre 0 y %d\n", DIMENSION-1);
    }

    return comprobarDatos;
}