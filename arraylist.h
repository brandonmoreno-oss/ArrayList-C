#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

typedef struct {
    void **data;         // Aquí se almacenan los elementos genéricos
    int size;            // Número de elementos actuales
    int capacity;        // Capacidad máxima actual
    int element_size;    // Tamaño en bytes de cada elemento
} ArrayList;

// Constructor y destructor
ArrayList* arraylist_create(int initial_capacity, int element_size);
void arraylist_destroy(ArrayList *list);

// Operaciones básicas
void arraylist_add(ArrayList *list, void *element);
void arraylist_insert(ArrayList *list, void *element, int index);
void* arraylist_get(ArrayList *list, int index);
int arraylist_remove(ArrayList *list, int index);
void arraylist_clear(ArrayList *list);

// Funciones internas de manejo de memoria
void arraylist_ensure_capacity(ArrayList *list, int min_capacity);
void arraylist_trim_clone(ArrayList *list);
ArrayList* arraylist_clone(ArrayList *list);

#endif
