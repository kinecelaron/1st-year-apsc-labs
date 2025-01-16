#include <stdio.h>

int main(void) {
	int year;
	double remainder_of_4;
	double remainder_of_100;
	double remainder_of_400;

	printf("Please input a year:\n");
	scanf("%d", &year);

	remainder_of_4 = year % 4;
	remainder_of_100 = year % 100;
	remainder_of_400 = year % 400;

	if (year < 1582) {
		printf("The Gregorian Calendar had not been adopted at that time");
	}
	else if (remainder_of_400==0 && remainder_of_100 == 0) {
		printf("%d is a leap year", year);
	}
	else if (remainder_of_400 != 0 && remainder_of_100 == 0) {
		printf("%d is not a leap year", year);
	}
	else if (remainder_of_4 == 0) {
		printf("%d is a leap year", year);
	}
	else {
		printf("%d is not a leap year", year);
	}
}