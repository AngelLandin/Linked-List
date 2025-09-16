#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList(){
    head = nullptr;
    tail = nullptr;
    length = 0;
}

LinkedList::LinkedList(int value){
    Node* newNode = new Node(value);
    head = newNode;
    tail = newNode;
    length = 1;
}

// Método para insertar un Nodo al inicio de la Linked List
void LinkedList::insertAtBeginning(int value){
    Node* newNode = new Node(value); // Creamos el Nodo a insertar
    if (head == nullptr){ // Verificamos si la Linked List está vacía
        // Si está vacía
        head = newNode;  //Asignamos el nuevo nodo como nuevo head
        tail = newNode; // Asigmanos el nuevo nodo como tail
    } else{
        newNode->next = head; //Unimos el next del Nodo con el primer Nodo de la LinkedList (head)
        head = newNode; // Asigamos en nuevo head (el nodo que agregamos)
    }

    length++; // Incrementamos la longitud de la Linked List
}

void LinkedList::insertAtEnd(int value) {
    // Crear un nuevo nodo con el valor a insertar
    Node* newNode = new Node(value);

    // Caso 1: La lista está vacía (head == nullptr)
    if (head == nullptr) {
        // El nuevo nodo se convierte tanto en head como en tail
        head = newNode;
        tail = newNode;
    } 
    // Caso 2: La lista ya tiene elementos
    else {
        // El último nodo actual (tail) apunta al nuevo nodo
        tail->next = newNode;

        // Ahora el nuevo nodo pasa a ser el nuevo tail
        tail = newNode;
    }

    // Incrementar la longitud de la lista
    length++;
}


LinkedList::Node* LinkedList::get(int index) {
    // Verifica si el índice está fuera de rango
    // Índices válidos: 0 <= index < length
    if (index < 0 || index >= length) {
        return nullptr; // Retorna puntero nulo si el índice no es válido
    }

    // Empezamos desde la cabeza de la lista
    Node* temp = head;

    // Avanzamos nodo por nodo hasta llegar a la posición indicada
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }

    // Retornamos el puntero al nodo encontrado
    return temp;
}


bool LinkedList::insertAtPosition(int index, int value) {
    // Verifica si el índice está fuera de rango
    // No se permite insertar en índices negativos o mayores a la longitud de la lista
    if (index < 0 || index > length) return false;

    // Caso 1: Insertar al inicio de la lista
    if (index == 0) {
        insertAtBeginning(value);  // Método auxiliar ya implementado
        return true;
    }

    // Caso 2: Insertar al final de la lista
    if (length == index) {
        insertAtEnd(value);  // Método auxiliar ya implementado
        return true;
    }

    // Caso 3: Insertar en una posición intermedia
    // Crear un nuevo nodo con el valor a insertar
    Node* newNode = new Node(value);

    // Obtener el nodo anterior a la posición deseada
    Node* temp = get(index - 1);

    // Enlazar el nuevo nodo con el siguiente
    newNode->next = temp->next;

    // Ajustar el puntero del nodo anterior para que apunte al nuevo nodo
    temp->next = newNode;

    // Incrementar la longitud de la lista
    length++;

    // Inserción exitosa
    return true;
}


void LinkedList::deleteValue(int value) {
    // Caso 1: La lista está vacía
    if (head == nullptr) return;

    // Caso 2: El valor está en el primer nodo (head)
    if (head->value == value) {
        Node* temp = head;       // Guardamos referencia al nodo actual
        head = temp->next;       // Movemos el head al siguiente nodo
        delete temp;             // Liberamos la memoria del nodo eliminado
        length--;                // Reducimos el contador de elementos
        return;                  // Terminamos porque ya eliminamos el valor
    }

    // Caso 3: El valor está en algún nodo intermedio o final
    Node* temp = head->next;     // Nodo actual que vamos a revisar
    Node* prev = head;           // Nodo previo al actual (necesario para enlazar)

    while (temp != nullptr) {
        if (temp->value == value) {
            prev->next = temp->next; // Saltamos el nodo encontrado
            delete temp;             // Liberamos la memoria del nodo eliminado
            length--;                // Reducimos el contador de elementos
            return;                  // Terminamos porque ya eliminamos el valor
        }
        // Avanzamos en la lista
        prev = temp;
        temp = temp->next;
    }

    // Si llegamos aquí, el valor no estaba en la lista
}

bool LinkedList::search(int value) {
    Node* temp = head;                // 1. Empieza desde el primer nodo (head)
    while (temp != nullptr) {         // 2. Mientras no lleguemos al final de la lista
        if (temp->value == value) {   // 3. Si el nodo actual contiene el valor buscado
            return true;              //    encontramos el valor
        }
        temp = temp->next;            // 4. Avanzamos al siguiente nodo
    }
    return false;                     // 5. Si salimos del ciclo, el valor no estaba en la lista
}

void LinkedList::display(){
    // Caso especial: lista vacía
    if (head == nullptr) {
        cout << "[Lista vacía]" << endl;
        return;
    }

    Node* temp = head; // Guardamos head en un Nodo temporal

    // Recorremos toda la LinkedList hasta llegar al último elemento
    while (temp != nullptr) {
        cout << temp->value << " ";  // Accedemos al valor del Nodo
        temp = temp->next;           // Avanzamos al siguiente nodo
    }
    cout << endl; // Nueva línea al final
}

// Destructor para liberar la memoria cuando la Linked List ya no se usa
LinkedList::~LinkedList(){
    Node* temp = head; // Guardamos un Nodo temporal
    while (head) { // while (head) -> while (head != nullptr)
        head = head->next; // Avanzamos al siguiente Nodo
        delete temp; // Eliminamos el Nodo temporal
        temp = head; // Guardamos en Temp el siguiente Nodo
    }
}