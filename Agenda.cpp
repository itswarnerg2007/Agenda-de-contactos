#include <iostream>
using namespace std;

int main() {
    string nombre[100];
    string correo[100];
    int telefono[100];
    int cantidad = 0;
    int opcion = 0;

    cout << "Bienvenido!" << endl;

    do {
        cout << "==========AGENDA DE CONTACTOS=======" << endl;
        cout << "1. Agregar contacto" << endl;
        cout << "2. Buscar contacto por nombre" << endl;
        cout << "3. Mostrar todos los contactos" << endl;
        cout << "4. Modificar contacto (por nombre)" << endl;
        cout << "5. Eliminar contacto (por nombre)" << endl;
        cout << "6. Salir de la agenda de contactos" << endl << endl;

        cout << "Escoja una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            cout << "======Agregar contacto=====" << endl;
            cout << "Nombre: ";
            cin >> nombre[cantidad];
            cout << "Telefono: ";
            cin >> telefono[cantidad];
            cout << "Correo Electronico: ";
            cin >> correo[cantidad];
            cantidad++;
            cout << "Contacto agregado exitosamente" << endl;
            break;
        }

        case 2: { 
            string nombreBuscar;
            cout << "=====Buscar contacto por nombre=====" << endl;
            cout << "Nombre del contacto que desea buscar: ";
            cin >> nombreBuscar;

            bool encontrado = false;
            for (int i = 0; i < cantidad; i++) {
                if (nombreBuscar == nombre[i]) {
                    cout << "Nombre: " << nombre[i] << endl;
                    cout << "Telefono: " << telefono[i] << endl;
                    cout << "Correo: " << correo[i] << endl;
                    cout << "-----------------------------" << endl;
                    encontrado = true;
                }
            }
            if (!encontrado) {
                cout << "No se encontraron contactos con ese nombre" << endl;
            }
            break;
        }

        case 3: { 
            cout << "=====Mostrar todos los contactos=====" << endl;
            if (cantidad == 0) {
                cout << "Ningún contacto registrado" << endl;
            }
            else {
                for (int i = 0; i < cantidad; i++) {
                    cout << "Nombre: " << nombre[i] << endl;
                    cout << "Telefono: " << telefono[i] << endl;
                    cout << "Correo: " << correo[i] << endl;
                    cout << "-----------------------------" << endl;
                }
            }
            break;
        }

        case 4: { 
            string nombreBuscar;
            cout << "====Modificar contacto====" << endl;
            cout << "Ingresa el nombre del contacto que se desea modificar: ";
            cin >> nombreBuscar;

            bool encontrado = false;
            for (int i = 0; i < cantidad; i++) {
                if (nombreBuscar == nombre[i]) {
                    cout << "Contacto encontrado, puede modificarlo" << endl;
                    cout << "Nuevo nombre: ";
                    cin >> nombre[i];
                    cout << "Nuevo telefono: ";
                    cin >> telefono[i];
                    cout << "Nuevo correo: ";
                    cin >> correo[i];
                    encontrado = true;
                    cout << "Contacto modificado" << endl;
                    break; 
                }
            }
            if (!encontrado) {
                cout << "Contacto no encontrado" << endl;
            }
            break;
        }

        case 5: { // Eliminar por nombre (si hay duplicados, elimina el primero encontrado)
            string nombreBuscar;
            cout << "=====Eliminar un contacto=====" << endl;
            cout << "Nombre del contacto que desea eliminar: ";
            cin >> nombreBuscar;

            bool encontrado = false;
            for (int i = 0; i < cantidad; i++) {
                if (nombreBuscar == nombre[i]) {
                    for (int j = i; j < cantidad - 1; j++) {
                        nombre[j] = nombre[j + 1];
                        telefono[j] = telefono[j + 1];
                        correo[j] = correo[j + 1];
                    }
                    cantidad--;
                    encontrado = true;
                    cout << "Contacto eliminado exitosamente" << endl;
                    break; // elimina solo el primero encontrado
                }
            }
            if (!encontrado) {
                cout << "Contacto no encontrado" << endl;
            }
            break;
        }

        case 6: {
            cout << "Gracias por usar la agenda de contactos" << endl;
            break;
        }

        default: {
            cout << "Opción no válida" << endl;
            break;
        }
        }

    } while (opcion != 6);

    system("pause>0");
}
