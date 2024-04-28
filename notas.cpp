#include <iostream>
#include <string>

using namespace std;

//promedio de las notas 
double calcularPromedio(double notas[], int tamano) {
    double suma = 0;
    for (int i = 0; i < tamano; ++i) {
        suma += notas[i];
    }
    return suma / tamano;
}

// determinar si aprueba o reprueba
string determinarEstado(double promedio) {
    if (promedio >= 60) {
        return "Aprobado";
    } else {
        return "Reprobado";
    }
}

int main() {
    int Estudiantes;

    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> Estudiantes;

    // almacenar la información de los estudiantes
    int codigo[Estudiantes];
    string nombres[Estudiantes];
    string apellidos[Estudiantes];
    double notas[3][Estudiantes]; // Cada estudiante tiene 3 notas

    // Informacion para cada estudiante
    for (int i = 0; i < Estudiantes; ++i) {
        cout << "\n Ingrese lo solicitado " << i+1 << ":\n";
        cout << "Codigo: ";
        cin >> codigo[i];
        cout << "Nombre: ";
        cin >> nombres[i];
        cout << "Apellido: ";
        cin >> apellidos[i];

        // Solicitar las 3 notas del estudiante
        for (int j = 0; j < 4; ++j) {
            cout << "Nota " << j+1 << ": ";
            cin >> notas[j][i];
        }
    }

    //Calcular promedio y si aprobo o desaprobo 
    cout << "\nResultados:\n";
    for (int i = 0; i <Estudiantes; ++i) {
        cout << "\nEstudiante " << i+1 << ":\n";
        cout << "codigo: " << codigo[i] << endl;
        cout << "Nombre: " << nombres[i] << " " << apellidos[i] << endl;

        double promedio = calcularPromedio(notas[i], 4);
        cout << "Promedio: " << promedio << endl;

        string estado = determinarEstado(promedio);
        cout << "Estado: " << estado << endl;
    }

    return 0;
}
