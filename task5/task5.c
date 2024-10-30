#include <stdio.h>
#include <stdlib.h>

void MatVecMultiply(int rows, int cols, int **A, int *x, int *y);
void MatMatMultiply(int rowsA, int colsA, int rowsB, int colsB, int **A, int **B, int **C);

int main() {
        int choice;

	while(1) {
		printf("\nChoose an operation:\n");
		printf("1) Matrix-Vector Multiplication\n");
		printf("2) Matrix-Matrix Multiplication\n");
		printf("3) Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		int rows, cols, i, j;

                if (choice == 1) {
			printf("Enter the number of rows in matrix A: ");
        		scanf("%d", &rows);
        		printf("Enter the number of columns in matrix A: ");
        		scanf("%d", &cols);

			// Memory allocation for A
			int **A = (int**) malloc(cols*sizeof(int*));
			for (i = 0; i < rows; i++) {
				A[i] = (int*) malloc(cols*sizeof(int));
			}

			// Memory allocation for vectors x and y (result)
			int *x = (int*) malloc(cols*sizeof(int));
			int *y = (int*) malloc(rows*sizeof(int));

        		printf("Enter the elements of matrix A (%dx%d): \n", rows, cols);
        		for (i = 0; i < rows; i++) {
                		for (j = 0; j < cols; j++) {
                        		printf("A[%d][%d]: ", i, j);
                        		scanf("%d", &A[i][j]);
               			}		
       			}

       	 		printf("Enter the elements of vector x (size %d): \n", cols);
        		for (i = 0; i < cols; i++) {
                		printf("x[%d]: ", i);
                		scanf("%d", &x[i]);
        		}

        		MatVecMultiply(rows, cols, A, x, y);

        		printf("Resulting y vector (size: %d):\n", rows);
        		for (i = 0; i < rows; i++) {
                		printf("y[%d] = %d\n", i, y[i]);
        		}

			for (i = 0; i < rows; i++) {
				free(A[i]);
			}
			free(A);
			free(x);
			free(y);
		} else if (choice == 2) {
			int rowsA, rowsB, colsA, colsB;

			printf("Enter the number of rows in matrix A: ");
                        scanf("%d", &rowsA);
			printf("Enter the number of columns in matrix A: ");
                        scanf("%d", &colsA);

			printf("Enter the number of rows in matrix B: ");
                        scanf("%d", &rowsB);
			printf("Enter the number of columns in matrix B: ");
                        scanf("%d", &colsB);

			if (colsA != rowsB) {
				printf("Error! Incompatible matrix dimensions.\n");
				continue;
			}

			int **A = (int**) malloc(rowsA*sizeof(int*));
			int **B = (int**) malloc(rowsB*sizeof(int*));
			int **C = (int**) malloc(rowsA*sizeof(int*));

			for (i = 0; i < rowsA; i++) {
				A[i] = (int*) malloc(colsA*sizeof(int));
				C[i] = (int*) malloc(colsB*sizeof(int));
			}
			for (i = 0; i < rowsB; i++) {
				B[i] = (int*) malloc(colsB*sizeof(int));
			}

			printf("Enter the elements of matrix A (%dx%d): \n", rowsA, colsA);
                        for (i = 0; i < rowsA; i++) {
                                for (j = 0; j < colsA; j++) {
                                        printf("A[%d][%d]: ", i, j);
                                        scanf("%d", &A[i][j]);
                                }
                        }

			printf("Enter the elements of matrix B (%dx%d): \n", rowsB, colsB);
                        for (i = 0; i < rowsB; i++) {
                                for (j = 0; j < colsB; j++) {
                                        printf("B[%d][%d]: ", i, j);
                                        scanf("%d", &B[i][j]);
                                }
                        }

			MatMatMultiply(rowsA, colsA, rowsB, colsB, A, B, C);

			printf("Resulting C matrix (size: %dx%d):\n", rowsA, colsB);
                        for (i = 0; i < rowsA; i++) {
				for (j = 0; j < colsB; j++) {
					printf("%d ", C[i][j]);
				}
				printf("\n");
                        }
			for (i = 0; i < rowsA; i++) {
				free(A[i]);
				free(C[i]);
			}
			for (i = 0; i < rowsB; i++) {
				free(B[i]);
			}
			free(A);
			free(B);
			free(C);
		
		} else if (choice == 3) {
			printf("Exiting the program. All memory has been freed.\n");
			break;
		} else {
			printf("Invalid input. Please try again.\n");
		}
	}

        return 0;
}

void MatVecMultiply(int rows, int cols, int **A, int *x, int *y) {
        for (int i = 0; i < rows; i++) {
                y[i] = 0;
                for (int j = 0; j < cols; j++) {
                        y[i] += A[i][j]*x[j];
                }
        }
}

void MatMatMultiply(int rowsA, int colsA, int rowsB, int colsB, int **A, int **B, int **C) {
	for (int i = 0; i < rowsA; i++) {
		for (int j = 0; j < colsB; j++) {
			C[i][j] = 0;
			for (int k = 0; k < colsA; k++) {
				C[i][j] += A[i][k]*B[k][j];
			}
		}
	}
}
