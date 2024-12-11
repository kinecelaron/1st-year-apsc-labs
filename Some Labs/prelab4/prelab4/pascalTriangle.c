#include <stdio.h>
#include <stdlib.h>

int factorial(int number) {
    if (number == 0) {
        return 1; // Base case: 0! = 1
    }
    else {
        return number * factorial(number - 1); // Recursive case
    }
}

int choose(int integerN, int integerR) {
    if (integerR > integerN) {
        return 0; // Return 0 if R is greater than N
    }
    int n_r = integerN - integerR;
    int number = factorial(integerN) / (factorial(integerR) * factorial(n_r)); // Combination formula
    return number;
}

int getInputInRange(int min, int max) {
        int number;
        printf("Please input a number between the acceptable range\n");
        scanf("%d", &number);
        while (number<min || number>max) {
            printf("Number is not within acceptable range, pelase try again\n");
            scanf("%d", &number);

        return number;
        }
}
int main(void) {
    int count = 0;
    int output;
    int number;
    int a, b;

    number=getInputInRange( 1,  12);

    for (int row = 0; row < number; row++) {
        while (count <=row){
            output = choose(row,count);
            printf("%5d", output);
            count++;
        }
        printf("\n");
        count = 0;
    }

}

