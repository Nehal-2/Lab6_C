#include <stdio.h>
#include <stdlib.h>

int main() {
        int n, *ptrX, *ptrY, *ptrZ;
        float a, b;

        printf("Enter the number of the elements in the vectors: ");
        scanf("%d", &n);

	if (n <= 0) {
		printf("Invalid input. Please enter a positive integer.\n");
		return 1;
	}

        ptrX = (int*) malloc(n*sizeof(int));
        ptrY = (int*) malloc(n*sizeof(int));
        ptrZ = (int*) malloc(n*sizeof(int));

	if (ptrX == NULL || ptrY == NULL || ptrZ == NULL) {
		printf("Error! Memory not allocated.\n");
		return 1;
	}

        printf("Enter the scalar value a: ");
        scanf("%f", &a);
        printf("Enter the scalar value b: ");
        scanf("%f", &b);

        printf("Enter the elements of vector x (size %d): \n", n);
        for (int i = 0; i < n; i++) {
                printf("x[%d]: ", i);
                scanf("%d", &ptrX[i]);
        }

        printf("Enter the elements of vector y (size %d): \n", n);
        for (int i = 0; i < n; i++) {
                printf("y[%d]: ", i);
                scanf("%d", &ptrY[i]);
        }

        for (int i = 0; i < n; i++) {
                ptrZ[i] = a*ptrX[i] + b*ptrY[i];
        }

        printf("Resulting z vector (size: %d):\n", n);
        for (int i = 0; i < n; i++) {
                printf("z[%d] = %d\n", i, ptrZ[i]);
        }

	free(ptrX);
	free(ptrY);
	free(ptrZ);

        return 0;
}
