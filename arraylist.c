#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"

ArrayList* createArrayList(int capacity) {
    ArrayList *list = (ArrayList*)malloc(sizeof(ArrayList));
    list->data = (int*)malloc(sizeof(int) * capacity);
    list->size = 0;
    list->capacity = capacity;
    return list;
}

void addElement(ArrayList *list, int element) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->data = (int*)realloc(list->data, sizeof(int) * list->capacity);
    }
    list->data[list->size++] = element;
}

void removeElement(ArrayList *list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Índice inválido\n");
        return;
    }

    for (int i = index; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }

    list->size--;
}

int getElement(ArrayList *list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Índice inválido\n");
        return -1;
    }

    return list->data[index];
}

void freeArrayList(ArrayList *list) {
    free(list->data);
    free(list);
}
