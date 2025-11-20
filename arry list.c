#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H
typedef struct{
	void**;// elementos genericos 
	int size; // N. d eelementos de  lista almacenados
	int capacity; // capacidad maxima de los objetos 
	int element_ size; // tamaño en byts de cada elemento
	
}ArrayList;
//constructor y destructor 
// costructuro -> inicializa variables rn sus valores por defecto y pide memoria  para almacenarse 
// destructor -> realiza la liberaciones de memoria para que el Os pueda volver a usarla
ArrayList* arraylist_create (int initial_capacity, int element__size);
void arraylist_destroy (ArrayList *list);
//operciones 
void arrayList_add(ArrayList *list, void *element_);
void arrayList_insert(ArrayList *list, void *element, int index);
void arrayList_get(ArrayList *list, int index);
int arraylist_remove(ArrayList *list, int index);
void arrayList_clear(ArrayList *list);

//funciones usadas 
void ArrayList_ensure_capacity(ArrayList *list, int min_capacity);
void ArrayList_trim_to_size (ArrayList *list);
ArrayList* ArrayList_clone(ArrayList *list);
#endif
