#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void multiplyMatrices(int **A1, int N1, int M1, int **A2, int N2, int M2, int **result) {
    int i, j, k;
    for (i = 0; i < N1; i++) {
        for (j = 0; j < M2; j++) {
            result[i][j] = 0;
            for (k = 0; k < M1; k++) {
                result[i][j] += A1[i][k] * A2[k][j];
            }
        }
    }
}


int main() {
    int N1, M1, N2, M2, i, j, mode, max_value;
    int correct_matrix = 0;

    srand(time(NULL));

    printf("1 - manual filling\n2 - random filling: ");
    scanf("%d", &mode);

    while (correct_matrix == 0) {
        printf("Enter the size of the first matrix (rows and columns):\n");
        scanf("%d %d", &N1, &M1);

        printf("Enter the size of the second matrix (rows and columns):\n");
        scanf("%d %d", &N2, &M2);

        if (M1 == N2) {
            correct_matrix = 1;
        } else {
            printf("Multiplication is not possible for these matrices, please retry.\n");
        }
    }

    // выделение памяти
    int **A1 = (int **)malloc(N1 * sizeof(int *));
    for (i = 0; i < N1; i++) {
        A1[i] = (int *)malloc(M1 * sizeof(int));
    }

    int **A2 = (int **)malloc(N2 * sizeof(int *));
    for (i = 0; i < N2; i++) {
        A2[i] = (int *)malloc(M2 * sizeof(int));
    }

    int **result = (int **)malloc(N1 * sizeof(int *));
    for (i = 0; i < N1; i++) {
        result[i] = (int *)malloc(M2 * sizeof(int));
    }


    // заполнение матриц
    if (mode == 1) {
        printf("Enter elements for the first matrix:\n");
        for (i = 0; i < N1; i++) {
            for (j = 0; j < M1; j++) {
                printf("A1[%d][%d]: ", i + 1, j + 1);
                scanf("%d", &A1[i][j]);
            }
        }

        printf("Enter elements for the second matrix:\n");
        for (i = 0; i < N2; i++) {
            for (j = 0; j < M2; j++) {
                printf("A2[%d][%d]: ", i + 1, j + 1);
                scanf("%d", &A2[i][j]);
            }
        }

        // отрисовка введенных матриц
        printf("First matrix:\n");
        for (i = 0; i < N1; i++) {
            for (j = 0; j < M1; j++) {
                printf("%d ", A1[i][j]);
            }
            printf("\n");
        }

        printf("Second matrix:\n");
        for (i = 0; i < N2; i++) {
            for (j = 0; j < M2; j++) {
                printf("%d ", A2[i][j]);
            }
            printf("\n");
        }

    } else if (mode == 2) {
        printf("Select the maximum value for the matrix elements: ");
        scanf("%d", &max_value);

        printf("First matrix:\n");
        for (i = 0; i < N1; i++) {
            for (j = 0; j < M1; j++) {
                A1[i][j] = rand() % max_value + 1;
                printf("%d ", A1[i][j]);
            }
            printf("\n");
        }

        printf("Second matrix:\n");
        for (i = 0; i < N2; i++) {
            for (j = 0; j < M2; j++) {
                A2[i][j] = rand() % max_value + 1;
                printf("%d ", A2[i][j]);
            }
            printf("\n");
        }
    }

    multiplyMatrices(A1, N1, M1, A2, N2, M2, result);

    // вывод результата
    printf("Result of matrix multiplication:\n");
    for (i = 0; i < N1; i++) {
        for (j = 0; j < M2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < N1; i++) {
        free(A1[i]);
    }
    free(A1);

    for (i = 0; i < N2; i++) {
        free(A2[i]);
    }
    free(A2);

    for (i = 0; i < result; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}