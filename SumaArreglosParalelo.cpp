// SumaArreglosParalel.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <omp.h>
#include <vector>
#include <cstdlib> // Para generar números aleatorios
#include <ctime>   // Para la semilla de números aleatorios

int main() {
    // Tamaño del arreglo
    const int n = 1000;

    // Crear arreglos A, B y C
    std::vector<int> A(n), B(n), C(n);

    // Generar valores aleatorios para A y B
    std::srand(std::time(0)); // Inicializar la semilla
    for (int i = 0; i < n; i++) {
        A[i] = std::rand() % 100; // Valores entre 0 y 99
        B[i] = std::rand() % 100;
    }

    // Sumar los arreglos en paralelo usando OpenMP
#pragma omp parallel for
    for (int i = 0; i < n; i++) {
        C[i] = A[i] + B[i];
    }

    // Imprimir parte de los arreglos para verificar los resultados
    std::cout << "Arreglo A: ";
    for (int i = 0; i < 10; i++) std::cout << A[i] << " ";
    std::cout << "\n";

    std::cout << "Arreglo B: ";
    for (int i = 0; i < 10; i++) std::cout << B[i] << " ";
    std::cout << "\n";

    std::cout << "Arreglo C (resultado): ";
    for (int i = 0; i < 10; i++) std::cout << C[i] << " ";
    std::cout << "\n";

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
