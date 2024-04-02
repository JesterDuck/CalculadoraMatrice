// CalculadoraMatrices.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <WindowsNumerics.h>


using namespace DirectX;
using namespace std;
using namespace Windows::Foundation::Numerics;

// Funci�n para sumar dos matrices
vector<vector<double>> sumarMatrices(const vector<vector<double>>& mat1, const vector<vector<double>>& mat2) {

    // Obtener el n�mero de filas y columnas de las matrices de entrada
    int fil = mat1.size();     // N�mero de filas de la primera matriz
    int col = mat1[0].size();  // N�mero de columnas de la primera matriz

    // Crear una matriz resultado del mismo tama�o que las matrices de entrada
    vector<vector<double>> result(fil, vector<double>(col));

    // Iterar sobre cada elemento de las matrices para realizar la suma
    for (int i = 0; i < fil; ++i) {      // Iterar sobre las filas
        for (int j = 0; j < col; ++j) {  // Iterar sobre las columnas
            // Realizar la suma de los elementos correspondientes de las matrices
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    // Devolver la matriz resultado despu�s de realizar la suma
    return result;
}

// Funci�n para restar dos matrices
vector < vector < double >> restarMatrices(const vector<vector<double>>& mat1, const vector<vector<double>>& mat2) {

    // Obtener el n�mero de filas y columnas de las matrices de entrada
    int fil = mat1.size();     // N�mero de filas de la primera matriz
    int col = mat1[0].size();  // N�mero de columnas de la primera matriz

    // Crear una matriz resultado del mismo tama�o que las matrices de entrada
    vector<vector<double>> result(fil, vector<double>(col));

    // Iterar sobre cada elemento de las matrices para realizar la resta
    for (int i = 0; i < fil; ++i) {       // Iterar sobre las filas
        for (int j = 0; j < col; ++j) {   // Iterar sobre las columnas
            // Realizar la resta de los elementos correspondientes de las matrices
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    // Devolver la matriz resultado despu�s de realizar la resta
    return result;
}

// Funci�n para multiplicar dos matrices
vector<vector<double>> multiplicarMatrices(const vector<vector<double>>& mat1, const vector < vector < double>> &mat2) {

    // Obtener las dimensiones de las matrices de entrada
    int fil1 = mat1.size();    // N�mero de filas de la primera matriz
    int col1 = mat1[0].size(); // N�mero de columnas de la primera matriz
    int col2 = mat2[0].size(); // N�mero de columnas de la segunda matriz

    // Crear una matriz resultado inicializada con ceros
    vector<vector<double>> result(fil1, vector<double>(col2, 0));

    // Algoritmo de multiplicaci�n de matrices
    for (int i = 0; i < fil1; ++i) {                     // Iterar sobre las filas de la primera matriz
        for (int j = 0; j < col2; ++j) {                 // Iterar sobre las columnas de la segunda matriz
            for (int k = 0; k < col1; ++k) {             // Iterar sobre las columnas de la primera matriz o filas de la segunda matriz
                result[i][j] += mat1[i][k] * mat2[k][j]; // Sumar los productos parciales para calcular el elemento (i,j) de la matriz resultado
            }
        }
    }
    return result;// Devolver la matriz resultado
}



// Funci�n para imprimir una matriz
void imprimirMatriz(const vector<vector<double>>& mat) {
    int fil = mat.size();
    int col = mat[0].size();

    for (int i = 0; i < fil; ++i) {
        for (int j = 0; j < col; ++j) {
            printf_s("|%.4f| ", mat[i][j]);  // Imprimir cada n�mero con 4 decimales
        }
        printf_s("\n");
    }
}

// Funci�n para imprimir una matriz 4x4
void imprimirMatriz4x4(float4x4 matriz) {
    printf_s("[ %.4f, %.4f, %.4f, %.4f ]\n", matriz.m11, matriz.m12, matriz.m13, matriz.m14);
    printf_s("[ %.4f, %.4f, %.4f, %.4f ]\n", matriz.m21, matriz.m22, matriz.m23, matriz.m24);
    printf_s("[ %.4f, %.4f, %.4f, %.4f ]\n", matriz.m31, matriz.m32, matriz.m33, matriz.m34);
    printf_s("[ %.4f, %.4f, %.4f, %.4f ]\n", matriz.m41, matriz.m42, matriz.m43, matriz.m44);
}

// Funci�n para imprimir un vector (x, y, z)
void imprimir3x3(float3 vector){
    printf_s("(%f, %f, %f)\n\n", vector.x, vector.y, vector.z);
}

void Suma() {
    int filas, columnas;

    system("cls");

    printf_s("Ingrese el tama�o de las matrices (filas y columnas):\n");
    printf_s("EJEMPLO: 3,3\n");

    if (scanf_s("%d,%d", &filas, &columnas) == 2) {
        // Verificar si el n�mero de filas o columnas es mayor que 10
        if (filas > 10 || columnas > 10) {
            printf_s("Error: El numero de filas o columnas no puede ser mayor que 10.\n");
            return;  // Salir de la funci�n
        }

        // Crear las matrices de acuerdo al tama�o ingresado
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
        printf_s("Primera Matriz:\n");
        imprimirMatriz(matriz1);
        printf_s("Segunda Matriz:\n");
        imprimirMatriz(matriz2);
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

    printf_s("Ingrese el tama�o de las matrices (filas y columnas):\n");
    printf_s("EJEMPLO: 3,3\n");

    if (scanf_s("%d,%d", &filas, &columnas) == 2) {
        // Verificar si el n�mero de filas o columnas es mayor que 10
        if (filas > 10 || columnas > 10) {
            printf_s("Error: El numero de filas o columnas no puede ser mayor que 10.\n");
            return;  // Salir de la funci�n
        }

        // Crear las matrices de acuerdo al tama�o ingresado
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
        printf_s("Primera Matriz:\n");
        imprimirMatriz(matriz1);
        printf_s("Segunda Matriz:\n");
        imprimirMatriz(matriz2);
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

    printf_s("Ingrese el tama�o de la matriz 1 (filas y columnas):\n");
    printf_s("EJEMPLO: 3,3\n");

    if (scanf_s("%d,%d", &fil1, &col1) == 2) {
        // Verificar si el n�mero de filas o columnas es mayor que 10
        if (fil1 > 10 || col1 > 10) {
            printf_s("Error: El numero de filas o columnas no puede ser mayor que 10.\n");
            return;  // Salir de la funci�n
        }
    }
    else {
        // Lectura fallida, mostrar mensaje de error
        printf_s("Error al leer los valores. Asegurese de ingresar dos enteros separados por coma.\n");
        return Multi();
    }

    printf_s("Ingrese el tama�o de la matriz 2 (filas y columnas):\n");
    printf_s("EJEMPLO: 3,3\n");

    if (scanf_s("%d,%d", &fil2, &col2) == 2) {
        // Verificar si el n�mero de filas o columnas es mayor que 10
        if (fil2 > 10 || col2 > 10) {
            printf_s("Error: El numero de filas o columnas no puede ser mayor que 10.\n");
            return;  // Salir de la funci�n
        }
    }
    else {
        // Lectura fallida, mostrar mensaje de error
        printf_s("Error al leer los valores. Asegurese de ingresar dos enteros separados por coma.\n");
        return Multi();
    }

    if (col1 != fil2) {
        printf_s("No se pueden multiplicar las matrices\n");
        return;
    }
    else {
        // Crear las matrices de acuerdo al tama�o ingresado
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
        printf_s("Primera Matriz:\n");
        imprimirMatriz(matriz1);
        printf_s("Segunda Matriz:\n");
        imprimirMatriz(matriz2);
        printf_s("Matriz resultante:\n");
        imprimirMatriz(multi);

    }
}

void Quat() {
    // Declarar variables para el punto, vector de rotaci�n y �ngulo
   float3 p, VectorR;
    float Angulo;

    // Solicitar al usuario que ingrese el punto en el espacio tridimensional
    printf_s("Ingrese las coordenadas del punto (x, y, z): ");
    scanf_s("%f %f %f", &p.x, &p.y, &p.z);

    // Solicitar al usuario que ingrese el vector de rotaci�n
    printf_s("Ingrese las componentes del vector de rotacion (x, y, z): ");
    scanf_s("%f %f %f", &VectorR.x, &VectorR.y, &VectorR.z);

    // Solicitar al usuario que ingrese el �ngulo de rotaci�n en grados
    printf_s("Ingrese el angulo de rotacion en grados: ");
    scanf_s("%f", &Angulo);

    // Convertir el �ngulo de grados a radianes
    float Rad = XMConvertToRadians(Angulo);

    // Crear el cuaternio de rotaci�n
    quaternion rot = make_quaternion_from_axis_angle(normalize(VectorR), Rad);

    // Rotar el punto utilizando el cuaternio de rotaci�n
    float3 puntoR = transform(p, rot);

    // Mostrar el resultado de la rotaci�n
    printf_s("Punto original: (%.4f, %.4f, %.4f)\n\n", p.x, p.y, p.z);
    printf_s("Punto rotado: (%.4f, %.4f, %.4f)\n\n", puntoR.x, puntoR.y, puntoR.z);
}

void Rot3D() {
    // Declarar variables para el punto, vector de rotaci�n y �ngulo
    float3 p, Vector1, Vector2;
    float Angulo;

    // Solicitar al usuario que ingrese el �ngulo de rotaci�n en grados
    printf_s("Ingrese el angulo de rotacion en grados: ");
    scanf_s("%f", &Angulo);

    // Convertir el �ngulo de grados a radianes
    float Rad = XMConvertToRadians(Angulo);

    // Solicitar al usuario que ingrese el vector 1
    printf_s("Ingrese las componentes del vector 1 (x, y, z): ");
    scanf_s("%f %f %f", &Vector1.x, &Vector1.y, &Vector1.z);

    // Solicitar al usuario que ingrese el vector 2
    printf_s("Ingrese las componentes del vector 2 (x, y, z): ");
    scanf_s("%f %f %f", &Vector2.x, &Vector2.y, &Vector2.z);

    float3 VectorR = Vector2 - Vector1;
    
    // Construir la matriz de rotaci�n alrededor del eje especificado
    float4x4 MatR = make_float4x4_from_axis_angle(normalize(VectorR), Rad);
   
    // Transponer la matriz de rotaci�n (Cambiar la fila 1 y la fila 3)
    MatR = transpose(MatR);

    printf_s("\n");

    //Imprimir el vector resultante
    printf_s("Vector Resultante:\n");
    imprimir3x3(VectorR);

    // Imprimir la matriz
    printf_s("Matriz de rotacion:\n");
    imprimirMatriz4x4(MatR);

    // Crear la matriz de Translacion
    float4x4  MatT1 = make_float4x4_translation(Vector1);
    float4x4  MatT2 = make_float4x4_translation(-Vector1);

    // Transponer la matriz de Translacion
    MatT1 = transpose(MatT1);
    MatT2 = transpose(MatT2);

    // imprimir la matriz de translacion
    printf_s("Matriz de traslacion:\n");
    imprimirMatriz4x4(MatT1);
    printf_s("Matriz de traslacion inversa:\n");
    imprimirMatriz4x4(MatT2);

    // Matriz final
    MatR = MatT1 * MatR * MatT2;
    printf_s("Matriz de rotacion final:\n");
    imprimirMatriz4x4(MatR);

    // Transponer de nuevo la Matriz para el transform
    MatR = transpose(MatR);

    printf_s("\n");

    char respuesta;
    do {
        // Pedir al usuario las coordenadas del punto
        float3 punto;

        printf_s("Ingrese las coordenadas del punto (x, y, z): ");
        scanf_s("%f %f %f", &punto.x, &punto.y, &punto.z);

        // Rotar el punto utilizando la matriz de rotaci�n
        float3 P_Rot = transform(punto, MatR);

        printf_s("\n");

        // Mostrar el resultado de la rotaci�n
        printf_s("Punto original: (%.4f, %.4f, %.4f)\n", punto.x, punto.y, punto.z);
        printf_s("Punto rotado: (%.4f, %.4f, %.4f)\n", P_Rot.x, P_Rot.y, P_Rot.z);

        printf_s("\n");

        printf_s("Desea rotar otro punto? (s/n): ");
        scanf_s(" %c", &respuesta, 1);

        // Verificar si la respuesta es diferente de 's' o 'n'
        if (respuesta != 's' && respuesta != 'S' && respuesta != 'n' && respuesta != 'N') {
            printf_s("Respuesta no valida. Se asume 'n' como respuesta.\n");
            respuesta = 'n'; // Asignar 'n' como respuesta por defecto en caso de respuesta inv�lida
        }
    } while (respuesta == 's' || respuesta == 'S');

    
}

int main (){

    int opc;

    do {
        printf_s("Calculadora de Matrices\n");
        printf_s("1.Suma\n");
        printf_s("2.Resta\n");
        printf_s("3.Multiplicacion\n");
        printf_s("4.Cuaternios (eje no paralelo)\n");
        printf_s("5.Rotacion 3D (eje paralelo)\n");

        printf_s("6.Matrices compuestas (z perspectiva)\n");
        printf_s("7.Obtener la perspectiva de los puntos originales y los transformados con las matrices compuestas\n");
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
            Quat();
            break;

        case 5:
            Rot3D();
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