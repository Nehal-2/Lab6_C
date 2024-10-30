#include <stdio.h>
#include <stdlib.h>

void push(int **stack, int *top, int *capacity, int value);
void pop(int **stack, int *top);
void display(int *stack, int top);

int main() {
        int *stack = (int*) malloc(sizeof(int));
        if (stack == NULL) {
                printf("Error! Memory not allocated.\n");
                return 1;
        }

	int top = 0, capacity = 1;
	char choice;
	int value; 

	while(1) {
		printf("Enter a command (p: push, o: pop, d: display, e: exit): ");
		scanf(" %c", &choice);

		switch (choice) {
			case 'p':
				printf("Enter an integer to push: ");
				scanf("%d", &value);
				push(&stack, &top, &capacity, value);
				break;
			case 'o':
				pop(&stack, &top);
				break;
			case 'd':
				display(stack, top);
				break;
			case 'e':
				free(stack);
				printf("Exiting the program. All memory has been freed.\n");
				return 0;
			default:
				printf("Invalid input.\n");
				break;
		}
	}
	return 0;
}

void push(int **stack, int *top, int *capacity, int value) {
	// Check if stack needs to expand
	if (*top >= *capacity) {
		*capacity *= 2;
		int *temp = realloc(*stack, *capacity*sizeof(int));
		if (temp == NULL) {
			printf("Error! Memory not allocated.\n");
            		free(*stack);
            		exit(1);
        	}
		*stack = temp;
	}
	(*stack)[(*top)++] = value;
}

void pop(int **stack, int *top) {
	if (*top == 0) {
		printf("Stack is empty. Cannot pop.\n");
	} else {
		int value = (*stack)[--(*top)];
		printf("Popped value: %d\n", value);
	}
}

void display(int *stack, int top) {
	if (top == 0) {
		printf("Stack is empty.\n");
	} else {
		printf("Current stack: ");
		for (int i = top - 1; i >= 0; i--) {
			printf("%d", stack[i]);
	 		if (i > 0)
				printf(", ");
		}
		printf("\n");
	}
}	
