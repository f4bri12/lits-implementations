#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array_list.h"


#define DEFAULT_CAPACITY 10
#define GROWTH_FACTOR 2


// ==========================================================
// Crear lista
// ==========================================================
ArrayList* arraylist_create(int initial_capacity, int element_size) {
	
	if (initial_capacity <= 0)
		initial_capacity = DEFAULT_CAPACITY;
	
	ArrayList *list = (ArrayList*)malloc(sizeof(ArrayList));
	if (!list) {
		printf("No se pudo asignar memoria para la lista.\n");
		return NULL;
	}
	
	list->elements = (void**)malloc(sizeof(void*) * initial_capacity);
	if (!list->elements) {
		printf("No se pudo asignar memoria para los elementos.\n");
		free(list);
		return NULL;
	}
	
	list->size = 0;
	list->capacity = initial_capacity;
	list->element_size = element_size;
	
	return list;
}


// ==========================================================
// Destruir lista
// ==========================================================
void arraylist_destroy(ArrayList *list) {
	if (!list) return;
	
	arrayList_clear(list);
	free(list->elements);
	free(list);
}


// ==========================================================
// Agregar al final
// ==========================================================
void arrayList_add(ArrayList *list, void *element) {
	if (!list || !element) return;
	
	if (list->size >= list->capacity)
		ArrayList_ensure_capacity(list, list->capacity * GROWTH_FACTOR);
	
	list->elements[list->size] = malloc(list->element_size);
	if (!list->elements[list->size]) {
		printf("Error al asignar memoria para el nuevo elemento.\n");
		return;
	}
	
	memcpy(list->elements[list->size], element, list->element_size);
	list->size++;
}


// ==========================================================
// Insertar en índice
// ==========================================================
void arrayList_insert(ArrayList *list, void *element, int index) {
	if (!list || !element || index < 0 || index > list->size) return;
	
	if (list->size >= list->capacity)
		ArrayList_ensure_capacity(list, list->capacity * GROWTH_FACTOR);
	
	for (int i = list->size; i > index; i--)
		list->elements[i] = list->elements[i - 1];
	
	list->elements[index] = malloc(list->element_size);
	if (!list->elements[index]) {
		printf("Error al asignar memoria en la inserción.\n");
		return;
	}
	
	memcpy(list->elements[index], element, list->element_size);
	list->size++;
}


// ==========================================================
// Obtener elemento
// ==========================================================
void* arrayList_get(ArrayList *list, int index) {
	if (!list || index < 0 || index >= list->size)
		return NULL;
	
	return list->elements[index];
}


// ==========================================================
// Remover elemento
// ==========================================================
int arrayList_remove(ArrayList *list, int index) {
	if (!list || index < 0 || index >= list->size)
		return 0;
	
	free(list->elements[index]);
	
	for (int i = index; i < list->size - 1; i++)
		list->elements[i] = list->elements[i + 1];
	
	list->size--;
	list->elements[list->size] = NULL;
	
	return 1;
}


// ==========================================================
// Garantizar capacidad
// ==========================================================
void ArrayList_ensure_capacity(ArrayList *list, int min_capacity) {
	if (!list || min_capacity <= list->capacity) return;
	
	void **new_data = realloc(list->elements, sizeof(void*) * min_capacity);
	if (!new_data) {
		printf("Error al reasignar memoria.\n");
		return;
	}
	
	list->elements = new_data;
	list->capacity = min_capacity;
}


// ==========================================================
// Limpiar lista
// ==========================================================
void arrayList_clear(ArrayList *list) {
	if (!list) return;
	
	for (int i = 0; i < list->size; i++) {
		free(list->elements[i]);
		list->elements[i] = NULL;
	}
	
	list->size = 0;
}
