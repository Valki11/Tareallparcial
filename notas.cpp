#include <iostream>
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Estudiante {
    int id;
    string nombre;
    string apellidos;
    float nota1;
    float nota2;
    float nota3;
    float nota4;
    float promedio;
    string resultado;
};

int main()
{
  int opcion;
  do {
    cout << "\n\nMenú de opciones:\n";
    cout << "1. Inciso 1\n";
    cout << "2. Inciso 2\n";
    cout << "3. Inciso 3\n";
    cout << "0. Salir\n";
    cout << "\nIngrese una opción: ";
    cin >> opcion;

    switch (opcion) {
      case 1:
        int Estudiantes;

        cout << "Ingrese la cantidad de estudiantes";
        cin >> Estudiantes;
    
        int codigo[Estudiantes];
        string nombres[Estudiantes];
        string apellidos[Estudiantes];
        double notas[4][Estudiantes];
    
        for (int i = 0; i < Estudiantes; ++i) {
            cout << "\n Ingrese lo solicitado " << i+1 << ":\n";
            cout << "Codigo: ";
            cin >> codigo[i];
            cout << "Nombre: ";
            cin >> nombres[i];
            cout << "Apellido: ";
            cin >> apellidos[i];
    
            for (int j = 0; j < 5; ++j) {
                cout << "Nota " << j+1 << ": ";
                cin >> notas[j][i];
            }
        }
    
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
        
        break;
      case 2:
        int cantidadEstudiantes;
        
          cout << "Ingrese la cantidad de estudiantes ";
          cin >> cantidadEstudiantes;
        
          Estudiante *estudiantes = new Estudiante[cantidadEstudiantes];
        
          for (int i = 0; i < cantidadEstudiantes; i++) {
            registrarEstudiante(&estudiantes[i]);
          }
        
          for (int i = 0; i < cantidadEstudiantes; i++) {
            calcularPromedio(&estudiantes[i]);
            determinarEstado(&estudiantes[i]);
          }
        
          for (int i = 0; i < cantidadEstudiantes; i++) {
            mostrarEstudiante(&estudiantes[i]);
          }
        
          delete[] estudiantes;        
        
        break;
      case 3:
        
        int opcion;
          do {
            cout << "\nMenú Principal:" << endl;
            cout << "1. Crear registro" << endl;
            cout << "2. Ver registros" << endl;
            cout << "3. Editar registro" << endl;
            cout << "4. Eliminar registro" << endl;
            cout << "0. Salir" << endl;
            cout << "Ingrese una opción: ";
            cin >> opcion;
        
            switch (opcion) {
              case 1:
                crear();
                break;
              case 2:
                leerEstudiantes();
                break;
              case 3:
                editarEstudiante();
                break;
              case 4:
                eliminarEstudiante();
                break;
              case 0:
                cout << "Saliendo del inciso 3..." << endl;
                break;
              default:
                cout << "Opción inválida. Intente nuevamente." << endl;
            }
          } while (opcion != 0);
                
        break;
      case 0:
        cout << "Saliendo del programa...\n";
        break;
      default:
        cout << "Opción no válida. Intente nuevamente.\n";
    }
  } while (opcion != 0);

  return 0;
}

//Metodos y Funciones - Inciso 1
void double calcularPromedio(double notas[], int tamano) {
    double suma = 0;
    for (int i = 0; i < tamano; ++i) {
        suma += notas[i];
    }
    return suma / tamano;
}

void string determinarEstado(double promedio) {
    if (promedio >= 60) {
        return "Aprobado";
    } else {
        return "Reprobado";
    }
}


//FIN


//Metodos y Funciones - Inciso 2
void registrarEstudiante(Estudiante *estudiante) {
  cout << "Ingrese la información del estudiante:" << endl;
  cout << "ID ";
  cin >> estudiant.id;
  cout << "Nombre ";
  cin.ignore(); 
  getline(cin, estudiante.nombre);
  cout << "Apellidos ";
  getline(cin, estudiante.apellidos);
  cout << "Nota 1 ";
  cin >> estudiante.nota1;
  cout << "Nota 2 ";
  cin >> estudiante.nota2;
  cout << "Nota 3 ";
  cin >> estudiante.nota3;
  cout << "Nota 4 ";
  cin >> estudiante.nota4;
}

void calcularPromedio(Estudiante *estudiante) {
  estudiante.promedio = (estudiante.nota1 + estudiante.nota2 + estudiante.nota3 + estudiante.nota4) / 4.0;
}

void determinarEstado(Estudiante *estudiante) {
  if (estudiante.promedio >= 60.0) {
    estudiante.resultado = "Aprobado";
  } else {
    estudiante.resultado = "Reprobado";
  }
}

void mostrarEstudiante(Estudiante *estudiante) {
  cout << "\nInformación del estudiante:" << endl;
  cout << "ID: " << estudiante.id << endl;
  cout << "Nombre: " << estudiante.nombre << " " << estudiante->apellidos << endl;
  cout << "Promedio: " << estudiante.promedio << endl;
  cout << "Resultado: " << estudiante.resultado << endl;
}
//FIN


//Metodos y Funciones - Inciso 3
void crear() {
    Estudiante estudiante;

    cout << "Ingrese el id del estudiante ";
    cin >> estudiante.id;

    cout << "Ingrese el nombre del estudiante ";
    cin.ignore(); 
    getline(cin, estudiante.nombre);

    cout << "Ingrese los apellidos del estudiante ";
    getline(cin, estudiante.apellidos);

    cout << "Ingrese la nota 1 ";
    cin >> estudiante.nota1;

    cout << "Ingrese la nota 2 ";
    cin >> estudiante.nota2;

    cout << "Ingrese la nota 3 ";
    cin >> estudiante.nota3;

    cout << "Ingrese la nota 4 ";
    cin >> estudiante.nota4;

    estudiante.promedio = (estudiante.nota1 + estudiante.nota2 + estudiante.nota3 + estudiante.nota4) / 4;

    if (estudiante.promedio >= 60) {
        estudiante.resultado = "Aprobado";
    } else {
        estudiante.resultado = "Reprobado";
    }

    fstream archivo("notas.dat", ios::out | ios::binary);

    if (archivo.is_open()) {
        archivo.write((char *)&estudiante, sizeof(Estudiante));
        archivo.close();

        cout << "Estudiante creado exitosamente!" << endl;
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
}

void leerEstudiantes() {
    Estudiante estudiante;
    fstream archivo("notas.dat", ios::in | ios::binary);

    if (archivo.is_open()) {
        while (archivo.read((char *)&estudiante, sizeof(Estudiante))) {
            cout << "ID: " << estudiante.id << endl;
            cout << "Nombre: " << estudiante.nombre << endl;
            cout << "Apellidos: " << estudiante.apellidos << endl;
            cout << "Nota 1: " << estudiante.nota1 << endl;
            cout << "Nota 2: " << estudiante.nota2 << endl;
            cout << "Nota 3: " << estudiante.nota3 << endl;
            cout << "Nota 4: " << estudiante.nota4 << endl;
            cout << "Promedio: " << estudiante.promedio << endl;
            cout << "Resultado: " << estudiante.resultado << endl;
            cout << "------------------------------------" << endl;
        }
    }
}

void editarEstudiante() {
    int idEstudiante;

    cout << "Ingrese el ID del estudiante a editar: ";
    cin >> idEstudiante;
    
    fstream archivo("notas.dat", ios::in | ios::out | ios::binary);

    if (archivo.is_open()) {
        Estudiante estudiante;

        bool encontrado = false;
        while (archivo.read((char *)&estudiante, sizeof(Estudiante))) {
            if (estudiante.id == idEstudiante) {
                encontrado = true;
                break;
            }
        }

        if (encontrado) {
            cout << "-----------Estudiantes------------" << endl;
            cout << "ID: " << estudiante.id << endl;
            cout << "Nombre: " << estudiante.nombre << endl;
            cout << "Apellidos: " << estudiante.apellidos << endl;
            cout << "Nota 1: " << estudiante.nota1 << endl;
            cout << "Nota 2: " << estudiante.nota2 << endl;
            cout << "Nota 3: " << estudiante.nota3 << endl;
            cout << "Nota 4: " << estudiante.nota4 << endl;
            cout << "Promedio: " << estudiante.promedio << endl;
            cout << "Resultado: " << estudiante.resultado << endl;
            cout << "------------------------------------" << endl;

            cout << "Ingrese los nuevos datos del estudiante:" << endl;

            cout << "Nombre";
            cin.ignore(); // Limpiar buffer de entrada
            getline(cin, estudiante.nombre);

            cout << "Apellidos";
            getline(cin, estudiante.apellidos);

            cout << "Nota 1";
            cin >> estudiante.nota1;

            cout << "Nota 2";
            cin >> estudiante.nota2;

            cout << "Nota 3";
            cin >> estudiante.nota3;

            cout << "Nota 4";
            cin >> estudiante.nota4;

            estudiante.promedio = (estudiante.nota1 + estudiante.nota2 + estudiante.nota3 + estudiante.nota4) / 4;

            if (estudiante.promedio >= 60) {
                estudiante.resultado = "Aprobado";
            } else {
                estudiante.resultado = "Reprobado";
            }

            archivo.seekp(archivo.tellg() - sizeof(Estudiante));

            archivo.write((char *)&estudiante, sizeof(Estudiante));

            cout << "Estudiante editado exitosamente!" << endl;
        } else {
            cout << "Estudiante con ID " << idEstudiante << " no encontrado." << endl;
        }
    } else {
        cout << "Error al abrir el archivo." << endl;
    }

    archivo.close();
}

void eliminarEstudiante() {
    int idEstudiante;

    cout << "Ingrese el ID del estudiante a eliminar: ";
    cin >> idEstudiante;

    fstream archivo("notas.dat", ios::in | ios::out | ios::binary);

    if (archivo.is_open()) {
        Estudiante estudiante;
        vector<Estudiante> estudiantes;

        while (archivo.read((char *)&estudiante, sizeof(Estudiante))) {
            estudiantes.push_back(estudiante);
        }

        for (int i = 0; i < estudiantes.size(); i++) {
            if (estudiantes[i].id == idEstudiante) {
                estudiantes.erase(estudiantes.begin() + i);
                break;
            }
        }
    }
}

//FIN 
