#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "PR3_matrix.h"
#define ROWS 7
#define COLS 5

void find_max_negative_matrix() {
    int matrix[ROWS][COLS];
    int max_negative = -51;

    srand(time(NULL));

    printf("Матрица:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = (rand() % 101) - 50; // Числа от -50 до 50
            printf("%4d", matrix[i][j]);
            if (matrix[i][j] < 0 && matrix[i][j] > max_negative) {
                max_negative = matrix[i][j];
            }
        }
        printf("\n");
    }
    printf("%d ", max_negative);
}
