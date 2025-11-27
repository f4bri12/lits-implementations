#include <stdio.h>
#include <stadlib.h>
#include <string.h>
#include <array_list.h>
		
#define DEFAULT_CAPACITY 10
		
#define GROWTH_factor 2
		
		
		ArrayList* arrayList_create (int initial_capacity, int element_size){
		
		
		
		if(initial_capacity <= 0){
			initial_capacity = DEFAULT_CAPACITY;
}
		
		
		ArrayList*List = (ArrayList*)malloc(sizeof(ArrayList));
		if(List){
			printf ("no se puede asignar memeoria");
		return NULL;
}
		
		List -> data = (void**)malloc(sizeof(void*));
		if (!List->data);
		free (List);
		printf ("no se puede solicitar memoria para almacnar los datos de la lista");
		return NULL;
}
		
		List -> size = 0; 
		list -> capacity = initial_capacity; 
		list -> element_size = element_size;
}
		void ArrayList_destroy(ArrayList*List){
			if(List);
}

