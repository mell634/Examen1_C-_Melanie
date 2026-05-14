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
//FUNCIONES
void registrarEstudiantes(string nombres[], float notas[], int &n) {
    cout << "Cuantos estudiantes (1-20): ";
    cin >> n;

    // Validacion de cantidad
    while (n < 1 || n > 20) {
        cout << "Invalido. Ingrese entre 1 y 20: ";
        cin >> n;
    }

    for (int i = 0; i < n; i++) {
        cout << "Nombre estudiante " << i + 1 << ": ";
        cin >> nombres[i]; 
        
        cout << "Nota (0-20): ";
        cin >> notas[i];
        
        // Validacion de nota
        while (notas[i] < 0 || notas[i] > 20) {
            cout << "Nota invalida. Ingrese de nuevo: ";
            cin >> notas[i];
        }
    }
}
void mostrarListado(string nombres[], float notas[], int n) {
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << nombres[i] << " - " << notas[i] << endl;
    }
}
float calcularPromedio(float notas[], int n) {
    float suma = 0;
    for (int i = 0; i < n; i++) {
        suma = suma + notas[i];
    }
    return suma / n;
}
void mostrarMayorMenor(string nombres[], float notas[], int n) {
    float mayor = notas[0];
    float menor = notas[0];
    int posMayor = 0;
    int posMenor = 0;

    for (int i = 1; i < n; i++) {
        if (notas[i] > mayor) {
            mayor = notas[i];
            posMayor = i;
        }
        if (notas[i] < menor) {
            menor = notas[i];
            posMenor = i;
        }
    }
    cout << "Nota Mayor: " << nombres[posMayor] << " (" << mayor << ")" << endl;
    cout << "Nota Menor: " << nombres[posMenor] << " (" << menor << ")" << endl;
}
void contarAprobados(float notas[], int n) {
    int ca = 0, cr = 0;
    for (int i = 0; i < n; i++) {
        if (notas[i] >= 14) {
            ca++;
        } else {
            cr++;
        }
    }
    cout << "Aprobados: " << ca << endl;
    cout << "Reprobados: " << cr << endl;
}
void buscarEstudiante(string nombres[], float notas[], int n) {
    string buscado;
    int encontrado = -1; //-1 para indicar que no se encontro
    cout << "Nombre a buscar: ";
    cin >> buscado;

    for (int i = 0; i < n; i++) {
        if (nombres[i] == buscado) {
            encontrado = i;
        }
    }

    if (encontrado != -1) {
        cout << "Estudiante: " << nombres[encontrado] << endl;
        cout << "Nota: " << notas[encontrado] << endl;
        if (notas[encontrado] >= 14) cout << "Estado Aprobado" << endl;
        else cout << "Estado Reprobado" << endl;
    } else {
        cout << "Estudiante no encontrado" << endl;
    }
}

