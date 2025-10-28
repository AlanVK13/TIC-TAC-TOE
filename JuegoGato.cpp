#include <iostream>
#include <limits> // Para limpiar el búfer de entrada
#include <cctype> // Para tolower()

using namespace std;

// --- Declaración de Funciones ---

/**
 * @brief Inicializa el tablero con números del 1 al 9.
 * @param tablero Matriz 3x3 que representa el juego.
 */
void inicializarTablero(char tablero[3][3]);

/**
 * @brief Dibuja el estado actual del tablero en la consola.
 * @param tablero Matriz 3x3.
 */
void dibujarTablero(const char tablero[3][3]);

/**
 * @brief Pide al jugador actual que ingrese su jugada.
 * @param jugador El carácter del jugador actual ('X' o 'O').
 * @return El número (1-9) de la casilla elegida.
 */
int obtenerJugada(char jugador);

/**
 * @brief Valida si la jugada es legal.
 * (Dentro del rango 1-9 y la casilla no está ocupada).
 * @param tablero Matriz 3x3.
 * @param jugada El número (1-9) de la casilla.
 * @return true si la jugada es válida, false en caso contrario.
 */
bool esJugadaValida(const char tablero[3][3], int jugada);

/**
 * @brief Coloca la marca ('X' o 'O') del jugador en el tablero.
 * @param tablero Matriz 3x3.
 * @param jugada El número (1-9) de la casilla.
 * @param jugador El carácter del jugador actual.
 */
void actualizarTablero(char tablero[3][3], int jugada, char jugador);

/**
 * @brief Verifica si el jugador actual ha ganado la partida.
 * @param tablero Matriz 3x3.
 * @param jugador El carácter del jugador a verificar.
 * @return true si el jugador ganó, false en caso contrario.
 */
bool verificarGanador(const char tablero[3][3], char jugador);

/**
 * @brief Verifica si el juego ha terminado en empate (tablero lleno).
 * @param tablero Matriz 3x3.
 * @return true si es empate, false en caso contrario.
 */
bool verificarEmpate(const char tablero[3][3]);

/**
 * @brief Cambia el turno del jugador.
 * @param jugador Jugador actual (se pasa por referencia para modificarlo).
 */
void cambiarJugador(char& jugador);

/**
 * @brief Limpia la pantalla de la consola (multiplataforma).
 */
void limpiarPantalla();


// --- Función Principal ---

int main() {
    char tablero[3][3];
    char jugadorActual = 'X';
    char jugarDeNuevo = 's';

    // (Mejora: Bucle para reiniciar el juego)
    do {
        int turnos = 0; // Contador para detectar empates
        jugadorActual = 'X';
        inicializarTablero(tablero);

        // Bucle principal del juego
        while (true) {
            limpiarPantalla();
            dibujarTablero(tablero);

            // 1. Obtener jugada
            int jugada = obtenerJugada(jugadorActual);

            // 2. Validar jugada
            while (!esJugadaValida(tablero, jugada)) {
                cout << "Jugada invalida. La casilla esta ocupada o el numero es incorrecto." << endl;
                cout << "Por favor, intentalo de nuevo." << endl;
                jugada = obtenerJugada(jugadorActual);
            }

            // 3. Actualizar el tablero
            actualizarTablero(tablero, jugada, jugadorActual);
            turnos++;

            // 4. Verificar estado del juego (Ganador)
            if (verificarGanador(tablero, jugadorActual)) {
                limpiarPantalla();
                dibujarTablero(tablero);
                cout << "\n¡FELICIDADES! El jugador '" << jugadorActual << "' ha ganado!" << endl;
                break; // Termina el juego
            }

            // 5. Verificar estado del juego (Empate)
            // Se verifica después del ganador, ya que el último movimiento puede ganar y llenar el tablero
            if (verificarEmpate(tablero)) {
                limpiarPantalla();
                dibujarTablero(tablero);
                cout << "\n¡El juego es un EMPATE!" << endl;
                break; // Termina el juego
            }

            // 6. Cambiar de jugador
            cambiarJugador(jugadorActual);
        }

        // (Mejora: Preguntar si quiere jugar de nuevo)
        cout << "\n¿Quieres jugar de nuevo? (s/n): ";
        cin >> jugarDeNuevo;
        // Limpiar el búfer de entrada en caso de que el usuario escriba más de un carácter
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    } while (tolower(jugarDeNuevo) == 's');

    cout << "\nGracias por jugar. ¡Adios!" << endl;
    return 0;
}


// --- Implementación de Funciones ---

void inicializarTablero(char tablero[3][3]) {
    char casilla = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tablero[i][j] = casilla;
            casilla++;
        }
    }
}

void dibujarTablero(const char tablero[3][3]) {
    cout << "  Juego de Gato (Tic-Tac-Toe)" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << tablero[0][0] << "  |  " << tablero[0][1] << "  |  " << tablero[0][2] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << tablero[1][0] << "  |  " << tablero[1][1] << "  |  " << tablero[1][2] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << tablero[2][0] << "  |  " << tablero[2][1] << "  |  " << tablero[2][2] << "  " << endl;
    cout << "     |     |     " << endl << endl;
}

int obtenerJugada(char jugador) {
    int jugada;
    cout << "Turno del jugador '" << jugador << "'. " << endl;
    cout << "Ingresa el numero de la casilla (1-9): ";
    
    // Validación de entrada (asegura que sea un número)
    while (!(cin >> jugada)) {
        cout << "Entrada invalida. Por favor, ingresa solo un numero: ";
        cin.clear(); // Limpia el estado de error de cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la entrada incorrecta
    }
    return jugada;
}

bool esJugadaValida(const char tablero[3][3], int jugada) {
    // 1. Verificar si está en el rango 1-9
    if (jugada < 1 || jugada > 9) {
        return false;
    }

    // 2. Convertir la jugada (1-9) a coordenadas (fila, col)
    // (jugada - 1) nos da un índice de 0-8
    int fila = (jugada - 1) / 3; // División entera
    int col = (jugada - 1) % 3;  // Módulo

    // 3. Verificar si la casilla NO está ocupada (si aún es un número)
    if (tablero[fila][col] == 'X' || tablero[fila][col] == 'O') {
        return false; // Casilla ocupada
    }

    return true; // Jugada válida
}

void actualizarTablero(char tablero[3][3], int jugada, char jugador) {
    // Convertir la jugada (1-9) a coordenadas (fila, col)
    int fila = (jugada - 1) / 3;
    int col = (jugada - 1) % 3;

    tablero[fila][col] = jugador;
}

bool verificarGanador(const char tablero[3][3], char jugador) {
    // Verificar filas
    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador) {
            return true;
        }
    }

    // Verificar columnas
    for (int j = 0; j < 3; j++) {
        if (tablero[0][j] == jugador && tablero[1][j] == jugador && tablero[2][j] == jugador) {
            return true;
        }
    }

    // Verificar diagonal principal
    if (tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador) {
        return true;
    }

    // Verificar diagonal secundaria
    if (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador) {
        return true;
    }

    return false; // No hay ganador
}

bool verificarEmpate(const char tablero[3][3]) {
    // Si alguna casilla todavía es un número (no 'X' o 'O'), el juego no ha terminado
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tablero[i][j] != 'X' && tablero[i][j] != 'O') {
                return false; // Todavía hay casillas libres
            }
        }
    }
    
    // Si el bucle termina, significa que todas las casillas están llenas
    // (y como se llama después de verificarGanador, sabemos que no hay ganador)
    return true;
}

void cambiarJugador(char& jugador) {
    if (jugador == 'X') {
        jugador = 'O';
    } else {
        jugador = 'X';
    }
    // Forma alternativa (operador ternario):
    // jugador = (jugador == 'X') ? 'O' : 'X';
}

void limpiarPantalla() {
    // Comando para Windows
    #ifdef _WIN32
        system("cls");
    // Comando para Unix/Linux/macOS
    #else
        system("clear");
    #endif
}

//Codigo funcionando 