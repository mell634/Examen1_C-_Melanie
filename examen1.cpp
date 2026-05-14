/*
Nombre del estudiante: Melanie Alvear
Curso: Bootcamp Programación Cero a POO
Clase: 10 - Examen 1 (C++)
Fecha: 18/03/2026
Tema: Sistema de registro y análisis de notas de estudiantes
*/

#include <iostream>
using namespace std;

void registrarEstudiantes(string nombres[], float notas[], int &n);
void mostrarListado(string nombres[], float notas[], int n);
float calcularPromedio(float notas[], int n);
void mostrarMayorMenor(string nombres[], float notas[], int n);
void contarAprobados(float notas[], int n);
void buscarEstudiante(string nombres[], float notas[], int n);

int main() {
    string nombres[20];
    float notas[20];
    int n = 0; // Cantidad de estudiantes registrados
    int opcion;

    do {
        cout << "\n====== MENU ===========" << endl;
        cout << "1 Registrar estudiantes" << endl;
        cout << "2 Mostrar listado" << endl;
        cout << "3 Mostrar promedio" << endl;
        cout << "4 Nota mayor y menor" << endl;
        cout << "5 Aprobados y reprobados" << endl;
        cout << "6 Buscar estudiante" << endl;
        cout << "7 Salir" << endl;
        cout << "Seleccione una opcion por favor: ";
        cin >> opcion;

        if (opcion == 1) {
            registrarEstudiantes(nombres, notas, n);
        } else if (opcion >= 2 && opcion <= 6) {
            if (n == 0) {
                cout << "Error no hay datos registrados" << endl;
            } else {
                if (opcion == 2) mostrarListado(nombres, notas, n);
                if (opcion == 3) cout << "Promedio general: " << calcularPromedio(notas, n) << endl;
                if (opcion == 4) mostrarMayorMenor(nombres, notas, n);
                if (opcion == 5) contarAprobados(notas, n);
                if (opcion == 6) buscarEstudiante(nombres, notas, n);
            }
        }
    } while (opcion != 7);

    return 0;
}
// ==========================================
// DEFINICIONES 
// ==========================================
void registrarEstudiantes(string nombres[], float notas[], int &n) {}
void mostrarListado(string nombres[], float notas[], int n) {}
float calcularPromedio(float notas[], int n) { return 0; }
void mostrarMayorMenor(string nombres[], float notas[], int n) {}
void contarAprobados(float notas[], int n) {}
void buscarEstudiante(string nombres[], float notas[], int n) {}