#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
        int n = 0;
	int stringCapacity = 5;
        char *string = (char*) malloc(stringCapacity*sizeof(char));
	
	if (string == NULL) {
                printf("Error! Memory not allocated.\n");
                return 1;
        }
	
	printf("Please enter a string: \n");

        // Dynamic memory reallocation based on the size of user input:
	char ch;
	while ((ch = getchar()) != '\n' && ch != EOF) {
		if (n >= stringCapacity - 1) { // -1 for the null character
			stringCapacity *= 2;
			char *temp = realloc(string, stringCapacity*sizeof(char));
			if (temp == NULL) {
				printf("Error! Memory not allocated.\n");
				free(string);
				return 1;
			}
			string = temp;
		}
		string[n++] = ch;
	}
	string[n] = '\0';

	char *reversed = (char*) malloc((n + 1)*sizeof(char));
	if (reversed == NULL) {
	       printf("Error! Memory not allocated.\n");
	       free(string);
	       return 1;
	}

	for (int i = 0; i < n; i++) {
		reversed[i] = string[n - 1 - i];
	}
	reversed[n] = '\0';

	printf("Original string: %s\n", string);
	printf("Reversed string: %s\n", reversed);

	free(string);
	free(reversed);

	return 0;
}
