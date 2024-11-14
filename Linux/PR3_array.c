#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "PR3_array.h"
#define SIZE 23

void find_max_negative_array() {
    int array[SIZE];
    int max_negative = -51;

    srand(time(NULL));

    printf("Массив:\n");
    for (int i = 0; i < SIZE; i++) {
        array[i] = (rand() % 101) - 50; // Числа от -50 до 50
        printf("%d ", array[i]);
        if (array[i] < 0 && array[i] > max_negative) {
            max_negative = array[i];
        }
    }
    printf("\n");
    printf("%d ", max_negative);
}
