#include <iostream> 
#include <string>
using namespace std;

struct Estudiante {
    string nombre;
    int codigo;
    float nota;
    Estudiante* siguiente;  
};

Estudiante* crearEstudiante(string nombre, int codigo, float nota) {
    Estudiante* nuevo = new Estudiante();
    nuevo->nombre = nombre;
    nuevo->codigo = codigo;
    nuevo->nota = nota;
    nuevo->siguiente = NULL; 
    return nuevo;
}

void agregarEstudiante(Estudiante*& cabeza, string nombre, int codigo, float nota) {
    Estudiante* nuevo = crearEstudiante(nombre, codigo, nota);
    if (!cabeza) {
        cabeza = nuevo;  
    } else {
        Estudiante* actual = cabeza;
        while (actual->siguiente) {
            actual = actual->siguiente;  
        }
        actual->siguiente = nuevo;  
    }
}

void mostrarMenu() {
    cout << "\nMenu de Gestion de Estudiantes\n";
    cout << "1. Ingresar datos de estudiantes\n";
    cout << "2. Ordenar estudiantes por codigo\n";
    cout << "3. Ordenar estudiantes por nota\n";
    cout << "4. Mostrar mayor nota\n";
    cout << "5. Mostrar menor nota\n";
    cout << "6. Mostrar promedio de notas\n";
    cout << "7. Salir\n";
}

int main() {
    Estudiante* lista = NULL;  
    int opcion;
    
    do {
        mostrarMenu();
        cin >> opcion;
        
        if (opcion == 1) {
            string nombre;
            int codigo;
            float nota;
            cout << "Ingrese el nombre del estudiante: "; cin >> nombre;
            cout << "Ingrese el codigo del estudiante: "; cin >> codigo;
            cout << "Ingrese la nota del estudiante: "; cin >> nota;
            agregarEstudiante(lista, nombre, codigo, nota);
        }
        
       
        
    } while (opcion != 7);  
    
    return 0;
}

