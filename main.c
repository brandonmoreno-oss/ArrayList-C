#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"

void mostrarMenu() {
    printf("\n========== MENU ==========\n");
    printf("1. Agregar elemento\n");
    printf("2. Eliminar elemento\n");
    printf("3. Obtener elemento\n");
    printf("4. Mostrar lista completa\n");
    printf("5. Salir\n");
    printf("===========================\n");
    printf("Seleccione una opcion: ");
}

void mostrarLista(ArrayList *list) {
    printf("\nContenido del ArrayList:\n");

    if (list->size == 0) {
        printf("[Lista vacia]\n");
        return;
    }

    for (int i = 0; i < list->size; i++) {
        int *valor = (int*) list->data[i];
        printf("(%d) -> %d\n", i, *valor);
    }
}

int main() {
    int capacidadInicial;
    int opcion, valor, index;

    printf("Ingrese la capacidad inicial del ArrayList: ");
    scanf("%d", &capacidadInicial);

    // USAR NOMBRE REAL DEL HEADER
    ArrayList *list = arraylist_create(capacidadInicial, sizeof(int));

    do {
        mostrarMenu();
        scanf("%d", &opcion);

        switch (opcion) {

        case 1:
            printf("Ingrese el valor a agregar: ");
            scanf("%d", &valor);

            // Guardar int dinámicamente
            int *nuevo = malloc(sizeof(int));
            *nuevo = valor;

            arraylist_add(list, nuevo);
            printf("Elemento agregado correctamente.\n");
            break;

        case 2:
            printf("Ingrese el indice del elemento a eliminar: ");
            scanf("%d", &index);

            if (arraylist_remove(list, index) == 0)
                printf("Elemento eliminado.\n");
            else
                printf("Índice inválido.\n");

            break;

        case 3:
            printf("Ingrese el indice a consultar: ");
            scanf("%d", &index);

            int *ptr = (int*) arraylist_get(list, index);
            if (ptr != NULL)
                printf("Elemento en indice %d: %d\n", index, *ptr);
            else
                printf("Índice inválido.\n");

            break;

        case 4:
            mostrarLista(list);
            break;

        case 5:
            printf("Saliendo del programa...\n");
            break;

        default:
            printf("Opcion invalida.\n");
        }

    } while (opcion != 5);

    arraylist_destroy(list);

    return 0;
}
