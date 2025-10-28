# 🐈 Tic-Tac-Toe (Juego del Gato) en C++

Este es un proyecto simple que implementa el clásico juego de tres en raya (Tic-Tac-Toe o Gato) en la consola utilizando el lenguaje de programación C++.

---

## 🚀 Características y Funcionamiento

El programa permite a dos jugadores humanos turnarse para colocar sus marcas ('X' y 'O') en un tablero de 3x3, con las siguientes características:

* **Interfaz de Consola:** El juego se desarrolla completamente en la terminal.
* **Selección por Número:** Los jugadores ingresan un número del 1 al 9 para elegir la casilla (siguiendo el esquema del teclado numérico).
* **Validación Robusta:**
    * Verifica que la entrada sea un número.
    * Verifica que la casilla elegida no esté ocupada.
* **Detección Automática:** Verifica la victoria por fila, columna o diagonal, y detecta el empate.
* **Juego Continuo:** Ofrece la opción de jugar una nueva partida al finalizar.
* **Limpieza de Pantalla:** Utiliza comandos multi-plataforma (`cls` o `clear`) para mantener la consola limpia en cada turno.

---

## 🛠️ Herramientas Utilizadas

* **Lenguaje de Programación:** C++
* **Compilador:** Cualquier compilador compatible con C++ estándar (ej: GCC, MinGW, Clang).
* **Librerías Estándar de C++:**
    * `<iostream>`: Para entrada y salida en la consola.
    * `<limits>`: Para la gestión y limpieza del búfer de entrada (`cin.ignore`).
    * `<cctype>`: Para manipular caracteres (`tolower` en la lógica de reinicio).

---

## 💻 Cómo Compilar y Ejecutar

Para poner en marcha este juego en tu sistema:

1.  **Guarda el código:** Asegúrate de que todo el código esté guardado en un archivo (ej: `gato.cpp`).
2.  **Compila:** Abre tu terminal (Git Bash, CMD, PowerShell, o Terminal de Linux/Mac) y usa tu compilador de C++.
    ```bash
    g++ gato.cpp -o gato
    ```
    *(Esto creará un archivo ejecutable llamado `gato` o `gato.exe`)*
3.  **Ejecuta:** Corre el programa ejecutable.
    ```bash
    ./gato
    ```
    *(Si estás en Windows, puedes usar `gato.exe`)*

---

## 🗺️ Mapeo del Tablero

Las casillas se corresponden con los números del 1 al 9:
