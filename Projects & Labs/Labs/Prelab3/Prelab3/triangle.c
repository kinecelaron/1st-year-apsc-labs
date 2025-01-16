#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int size = 0;
	int y = 1;
	int num = 1;
	int row_length = 0;

	while (size < 1 || size>9) {
		printf("Input a positive int for the size of the table\n");
		scanf("%d", &size);
	}

	while (y <= size) {
		for (int dot = 0; dot < size - y; dot++) {
			printf(".");
			row_length++;
		}
		while (row_length < size) {
			printf("%d", num);
			row_length++;
			num++;
		}
		printf("\n");
		y++;
		num = 1;
		row_length = 0;
	}
	return 0;
}

