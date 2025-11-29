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
        printf("(%d) -> %d\n", i, list->data[i]);
    }
}

int main() {
    int capacidadInicial;
    int opcion, valor, index;

    printf("Ingrese la capacidad inicial del ArrayList: ");
    scanf("%d", &capacidadInicial);

    ArrayList *list = createArrayList(capacidadInicial);

    do {
        mostrarMenu();
        scanf("%d", &opcion);

        switch (opcion) {

        case 1:
            printf("Ingrese el valor a agregar: ");
            scanf("%d", &valor);
            addElement(list, valor);
            printf("Elemento agregado correctamente.\n");
            break;

        case 2:
            printf("Ingrese el indice del elemento a eliminar: ");
            scanf("%d", &index);
            removeElement(list, index);
            break;

        case 3:
            printf("Ingrese el indice a consultar: ");
            scanf("%d", &index);
            valor = getElement(list, index);
            if (valor != -1) {
                printf("Elemento en indice %d: %d\n", index, valor);
            }
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

    freeArrayList(list);

    return 0;
}
