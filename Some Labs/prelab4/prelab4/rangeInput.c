

int getInputInRange(int min, int max) {
        int number;
        printf("Please input a number between the acceptable range");
        scanf("%d", &number);
        while (number<min || number>max) {
            printf("Number is not within acceptable range, pelase try again");
            scanf("%d", &number);
        }
}