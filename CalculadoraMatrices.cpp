// CalculadoraMatrices.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// Función para sumar dos matrices
vector<vector<double>> sumarMatrices(const vector<vector<double>>& mat1, const vector<vector<double>>& mat2) {

    // Obtener el número de filas y columnas de las matrices de entrada
    int fil = mat1.size();     // Número de filas de la primera matriz
    int col = mat1[0].size();  // Número de columnas de la primera matriz

    // Crear una matriz resultado del mismo tamaño que las matrices de entrada
    vector<vector<double>> result(fil, vector<double>(col));

    // Iterar sobre cada elemento de las matrices para realizar la suma
    for (int i = 0; i < fil; ++i) {      // Iterar sobre las filas
        for (int j = 0; j < col; ++j) {  // Iterar sobre las columnas
            // Realizar la suma de los elementos correspondientes de las matrices
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    // Devolver la matriz resultado después de realizar la suma
    return result;
}

// Función para restar dos matrices
vector < vector < double >> restarMatrices(const vector<vector<double>>& mat1, const vector<vector<double>>& mat2) {

    // Obtener el número de filas y columnas de las matrices de entrada
    int fil = mat1.size();     // Número de filas de la primera matriz
    int col = mat1[0].size();  // Número de columnas de la primera matriz

    // Crear una matriz resultado del mismo tamaño que las matrices de entrada
    vector<vector<double>> result(fil, vector<double>(col));

    // Iterar sobre cada elemento de las matrices para realizar la resta
    for (int i = 0; i < fil; ++i) {       // Iterar sobre las filas
        for (int j = 0; j < col; ++j) {   // Iterar sobre las columnas
            // Realizar la resta de los elementos correspondientes de las matrices
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    // Devolver la matriz resultado después de realizar la resta
    return result;
}

// Función para multiplicar dos matrices
vector<vector<double>> multiplicarMatrices(const vector<vector<double>>& mat1, const vector < vector < double>> &mat2) {

    // Obtener las dimensiones de las matrices de entrada
    int fil1 = mat1.size();    // Número de filas de la primera matriz
    int col1 = mat1[0].size(); // Número de columnas de la primera matriz
    int col2 = mat2[0].size(); // Número de columnas de la segunda matriz

    // Crear una matriz resultado inicializada con ceros
    vector<vector<double>> result(fil1, vector<double>(col2, 0));

    // Algoritmo estándar de multiplicación de matrices
    for (int i = 0; i < fil1; ++i) {                     // Iterar sobre las filas de la primera matriz
        for (int j = 0; j < col2; ++j) {                 // Iterar sobre las columnas de la segunda matriz
            for (int k = 0; k < col1; ++k) {             // Iterar sobre las columnas de la primera matriz o filas de la segunda matriz
                result[i][j] += mat1[i][k] * mat2[k][j]; // Sumar los productos parciales para calcular el elemento (i,j) de la matriz resultado
            }
        }
    }
    return result;// Devolver la matriz resultado
}



// Función para imprimir una matriz
void imprimirMatriz(const vector<vector<double>>& mat) {
    int fil = mat.size();
    int col = mat[0].size();

    for (int i = 0; i < fil; ++i) {
        for (int j = 0; j < col; ++j) {
            printf_s("|%.4f| ", mat[i][j]);  // Imprimir cada número con 4 decimales
        }
        printf_s("\n");
    }
}

void Suma() {
    int filas, columnas;

    system("cls");

    printf_s("Ingrese el tamaño de las matrices (filas y columnas):\n");
    printf_s("EJEMPLO: 3,3\n");

    if (scanf_s("%d,%d", &filas, &columnas) == 2) {
        // Verificar si el número de filas o columnas es mayor que 10
        if (filas > 10 || columnas > 10) {
            printf_s("Error: El numero de filas o columnas no puede ser mayor que 10.\n");
            return;  // Salir de la función
        }

        // Crear las matrices de acuerdo al tamaño ingresado
        vector<vector<double>> matriz1(filas, vector<double>(columnas));
        vector<vector<double>> matriz2(filas, vector<double>(columnas));

        // Solicitar al usuario que ingrese los elementos de la primera matriz
        printf_s("Ingrese los elementos de la primera matriz:\n");
        printf_s("EJEMPLO: 1 (enter) 1...\n");
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                scanf_s("%lf", &matriz1[i][j]);
            }
        }

        // Solicitar al usuario que ingrese los elementos de la segunda matriz
        printf_s("Ingrese los elementos de la segunda matriz:\n");
        printf_s("EJEMPLO: 1 (enter) 1...\n");
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                scanf_s("%lf", &matriz2[i][j]);
            }
        }

        // Sumar las matrices ingresadas
        vector<vector<double>> suma = sumarMatrices(matriz1, matriz2);

        // Mostrar la matriz resultante
        printf_s("Matriz resultante:\n");
        imprimirMatriz(suma);
    }
    else {
        // Lectura fallida, mostrar mensaje de error
        printf_s("Error al leer los valores. Asegurese de ingresar dos enteros separados por coma.\n");
        return Suma();
    }
}

void Resta() {
    int filas, columnas;

    system("cls");

    printf_s("Ingrese el tamaño de las matrices (filas y columnas):\n");
    printf_s("EJEMPLO: 3,3\n");

    if (scanf_s("%d,%d", &filas, &columnas) == 2) {
        // Verificar si el número de filas o columnas es mayor que 10
        if (filas > 10 || columnas > 10) {
            printf_s("Error: El numero de filas o columnas no puede ser mayor que 10.\n");
            return;  // Salir de la función
        }

        // Crear las matrices de acuerdo al tamaño ingresado
        vector<vector<double>> matriz1(filas, vector<double>(columnas));
        vector<vector<double>> matriz2(filas, vector<double>(columnas));

        // Solicitar al usuario que ingrese los elementos de la primera matriz
        printf_s("Ingrese los elementos de la primera matriz:\n");
        printf_s("EJEMPLO: 1 (enter) 1...\n");
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                scanf_s("%lf", &matriz1[i][j]);
            }
        }

        // Solicitar al usuario que ingrese los elementos de la segunda matriz
        printf_s("Ingrese los elementos de la segunda matriz:\n");
        printf_s("EJEMPLO: 1 (enter) 1...\n");
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                scanf_s("%lf", &matriz2[i][j]);
            }
        }

        // Restar las matrices ingresadas
        vector<vector<double>> resta = restarMatrices(matriz1, matriz2);

        // Mostrar la matriz resultante
        printf_s("Matriz resultante:\n");
        imprimirMatriz(resta);
    }
    else {
        // Lectura fallida, mostrar mensaje de error
        printf_s("Error al leer los valores. Asegurese de ingresar dos enteros separados por coma.\n");
        return Resta();
    }
}

void Multi() {
    int fil1, col1, fil2, col2;

    system("cls");

    printf_s("Ingrese el tamaño de la matriz 1 (filas y columnas):\n");
    printf_s("EJEMPLO: 3,3\n");

    if (scanf_s("%d,%d", &fil1, &col1) == 2) {
        // Verificar si el número de filas o columnas es mayor que 10
        if (fil1 > 10 || col1 > 10) {
            printf_s("Error: El numero de filas o columnas no puede ser mayor que 10.\n");
            return;  // Salir de la función
        }
    }
    else {
        // Lectura fallida, mostrar mensaje de error
        printf_s("Error al leer los valores. Asegurese de ingresar dos enteros separados por coma.\n");
        return Suma();
    }

    printf_s("Ingrese el tamaño de la matriz 2 (filas y columnas):\n");
    printf_s("EJEMPLO: 3,3\n");

    if (scanf_s("%d,%d", &fil2, &col2) == 2) {
        // Verificar si el número de filas o columnas es mayor que 10
        if (fil2 > 10 || col2 > 10) {
            printf_s("Error: El numero de filas o columnas no puede ser mayor que 10.\n");
            return;  // Salir de la función
        }
    }
    else {
        // Lectura fallida, mostrar mensaje de error
        printf_s("Error al leer los valores. Asegurese de ingresar dos enteros separados por coma.\n");
        return Suma();
    }

    if (col1 != fil2) {
        printf_s("No se pueden multiplicar las matrices\n");
        return;
    }
    else {
        // Crear las matrices de acuerdo al tamaño ingresado
        vector<vector<double>> matriz1(fil1, vector<double>(col1));
        vector<vector<double>> matriz2(fil2, vector<double>(col2));

        // Solicitar al usuario que ingrese los elementos de la primera matriz
        printf_s("Ingrese los elementos de la primera matriz:\n");
        printf_s("EJEMPLO: 1 (enter) 1...\n");
        for (int i = 0; i < fil1; ++i) {
            for (int j = 0; j < col1; ++j) {
                scanf_s("%lf", &matriz1[i][j]);
            }
        }

        // Solicitar al usuario que ingrese los elementos de la segunda matriz
        printf_s("Ingrese los elementos de la segunda matriz:\n");
        printf_s("EJEMPLO: 1 (enter) 1...\n");
        for (int i = 0; i < fil2; ++i) {
            for (int j = 0; j < col2; ++j) {
                scanf_s("%lf", &matriz2[i][j]);
            }
        }

        // Multiplicar las matrices ingresadas
        vector<vector<double>> multi = multiplicarMatrices(matriz1, matriz2);

        // Mostrar la matriz resultante
        printf_s("Matriz resultante:\n");
        imprimirMatriz(multi);

    }
}

int main (){

    int opc;

    do {
        printf_s("Calculadora de Matrices\n1.Suma\n2.Resta\n3.Multiplicacion\n4.Generar coordenadas por cuaternios\n");
        printf_s("5.Obtener matriz compuesta\n6.Resolver matriz compuesta\n7.Obtener la perspectiva de los puntos originales y los transformados con las matrices compuestas\n");
        printf_s("8.SALIR\n");

        scanf_s("%d", &opc);

        system("cls");

        switch (opc) {

        case 1:
            Suma();
            break;

        case 2:
            Resta();
            break;

        case 3:
            Multi();
            break;

        case 4:
            break;

        case 5:
            break;

        case 6:
            break;

        case 7:
            break;

        case 8:
            return 0;
            break;

        default:
            printf_s("Opcion incorrecta\n");
            break;
        }
    } while (opc != 8);

    system("cls");
    return 0;
}