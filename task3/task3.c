#include <stdio.h>
#include <stdlib.h>

int main() {
        int *samples = (int*) malloc(sizeof(int));
	if (samples == NULL) {
		printf("Error! Memory not allocated.\n");
                return 1;
        }

	int count = 0;
	char choice;
	int sum = 0;

	// Collect samples dynamically
	do {
		printf("\nEnter a sample integer value: ");
		scanf("%d", &samples[count]);

		sum += samples[count];
		count++;

		printf("Do you want to add more samples? (y/n): ");
		scanf(" %c", &choice);

		if (choice == 'y') {
			int *temp = realloc(samples, (count + 1)*sizeof(int));
			if (temp == NULL) {
                                printf("Error! Memory not allocated.\n");
                                free(samples);
                                return 1;
                        }
			samples = temp;
		}
	} while (choice == 'y');

	float average = (float)sum/count;

	printf("\nYou entered the following samples:\n");
	for (int i = 0; i < count; i++) {
		printf("%d ", samples[i]);
	}
	printf("\nCalculated DC value: %.2f\n", average);

	printf("Final adjusted samples after DC shift:\n");
	for (int i = 0; i < count; i++) {
		samples[i] -= (int)average;
		printf("%d ", samples[i]);
	}
	printf("\n");

	free(samples);

	return 0;

}
