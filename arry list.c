#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H
#include "array_list.h"


typedef struct {
	void **elements;      // elementos genéricos
	int size;             // número de elementos almacenados
	int capacity;         // capacidad máxima
	int element_size;     // tamaño en bytes de cada elemento
} ArrayList;

// Constructor y destructor
ArrayList* arraylist_create(int initial_capacity, int element_size);
void arraylist_destroy(ArrayList *list);

// Operaciones
void arrayList_add(ArrayList *list, void *element);
void arrayList_insert(ArrayList *list, void *element, int index);
void* arrayList_get(ArrayList *list, int index);
int arraylist_remove(ArrayList *list, int index);
void arrayList_clear(ArrayList *list);

// Funciones auxiliares
void ArrayList_ensure_capacity(ArrayList *list, int min_capacity);
void ArrayList_trim_to_size(ArrayList *list);
ArrayList* ArrayList_clone(ArrayList *list);

#endif
