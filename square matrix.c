#include <stdio.h>

void sortNonBoundary(int mat[4][4]) {
    int nbElements[8], i = 0, j;

    for (i = 1; i < 3; i++)
        for (j = 1; j < 3; j++)
            nbElements[i * 2 + j - 3] = mat[i][j];

    for (i = 0; i < 7; i++)
        for (j = 0; j < 7 - i; j++)
            if (nbElements[j] > nbElements[j + 1]) {
                int t = nbElements[j];
                nbElements[j] = nbElements[j + 1];
                nbElements[j + 1] = t;
            }

    for (i = 1, j = 0; i < 3; i++)
        for (j = 1; j < 3; j++)
            mat[i][j] = nbElements[i * 2 + j - 3];
}

int main() {
    int m[4][4], i, j;

    printf("Enter elements for the 4x4 matrix:\n");
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            scanf("%d", &m[i][j]);

    sortNonBoundary(m);

    int diagSum = m[0][0] + m[1][1] + m[2][2] + m[3][3];

    printf("Sorted matrix with diagonal sum after sorting:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }

    printf("Diagonal sum: %d\n", diagSum);

    return 0;
}
