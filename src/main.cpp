#include "LinkedList.h"
#include <iostream>
using namespace std;

int main() {
    cout << "===== PRUEBAS DE LINKED LIST =====" << endl;

    // Lista vacía
    LinkedList list;

    // 1. Método display()
    cout << "\n[1. Método display() en lista vacía]" << endl;
    list.display(); // Esperado: no imprime nada

    // 2. Manejo de Casos Especiales
    cout << "\n[2. Manejo de Casos Especiales]" << endl;

    cout << "- Insertar en lista vacía (insertAtEnd 10)" << endl;
    list.insertAtEnd(10);
    list.display(); // Esperado: 10

    cout << "- Eliminar primer nodo (valor 10)" << endl;
    list.deleteValue(10);
    list.display(); // Esperado: lista vacía

    cout << "- Insertar 2 valores (20, 30) y eliminar último (30)" << endl;
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.deleteValue(30);
    list.display(); // Esperado: 20

    cout << "- Intentar obtener nodo en índice fuera de rango (get(5))" << endl;
    if (list.get(5) == nullptr) {
        cout << "Error: indice fuera de rango" << endl;
    }

    // 3. Crear pruebas de funcionalidad
    cout << "\n[3. Pruebas de funcionalidad]" << endl;

    cout << "- Insertar varios elementos en diferentes posiciones" << endl;
    list.insertAtBeginning(5);   // 5 -> 20
    list.insertAtEnd(40);        // 5 -> 20 -> 40
    list.insertAtPosition(1, 99);// 5 -> 99 -> 20 -> 40
    list.display();

    cout << "- Buscar elementos existentes y no existentes" << endl;
    cout << "Buscar 99: " << (list.search(99) ? "Encontrado" : "No encontrado") << endl;
    cout << "Buscar 15: " << (list.search(15) ? "Encontrado" : "No encontrado") << endl;

    cout << "- Eliminar nodos y mostrar antes/despues" << endl;
    cout << "Lista antes:" << endl;
    list.display();
    list.deleteValue(99); // eliminar intermedio
    cout << "Lista despues de eliminar 99:" << endl;
    list.display();

    cout << "- Verificar que la lista se actualiza correctamente" << endl;
    cout << "Insertar al inicio (1), al final (50)" << endl;
    list.insertAtBeginning(1);
    list.insertAtEnd(50);
    list.display();


    cout << "\n===== FIN DE PRUEBAS =====" << endl;
    return 0;
}
