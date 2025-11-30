#include <stdio.h>
#include "array_list.h"

int main() {
	
	// 3.1) Crear la lista con capacidad mínima de 3 para elementos tipo int
	ArrayList *myArrayList = arraylist_create(3, sizeof(int));
	
	// 3.2) Agregar 4 elementos con arrayList_add
	int a = 10, b = 20, c = 30, d = 40;
	arrayList_add(myArrayList, &a);
	arrayList_add(myArrayList, &b);
	arrayList_add(myArrayList, &c);
	arrayList_add(myArrayList, &d);
	
	// Insertar 1 elemento con arrayList_insert en la posición 2
	int insertValue = 99;
	arrayList_insert(myArrayList, &insertValue, 2);
	
	// 3.3) Obtener un elemento e imprimirlo
	int *value = (int*)arrayList_get(myArrayList, 2);
	if (value != NULL) {
		printf("Elemento en índice 2: %d\n", *value);
	}
	
	// 3.4) Remover 2 elementos (índice 1 y luego el 2)
	arrayList_remove(myArrayList, 1);
	arrayList_remove(myArrayList, 2);
	
	// Mostrar los elementos que quedaron
	printf("\nElementos restantes:\n");
	for (int i = 0; i < myArrayList->size; i++) {
		int *v = (int*)arrayList_get(myArrayList, i);
		printf("[%d] = %d\n", i, *v);
	}
	
	// 3.5) Destruir la lista
	arraylist_destroy(myArrayList);
	
	return 0;
}
