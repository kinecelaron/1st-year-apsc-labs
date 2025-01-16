#include <stdio.h>

int main(void) {
	int house_price;
	double GST;
	double rebate;
	double gross_tax;

	printf("Please input a house price:\n");
	scanf("%d", &house_price);

	gross_tax = house_price * 0.05;
	if (house_price < 0) {
		printf("The house price cannot be negative");
	}
	else if (house_price <= 350000) {
		rebate = 0.36 * gross_tax;
		if (rebate > 5000) {
			rebate = 5000;
		}
	}
	else if (house_price > 350000 && house_price < 450000) {
		rebate = (5000 * (450000 - house_price)) / 100000;
	}
	else if (house_price >= 450000) {
		rebate = 0;
	}

	GST = gross_tax - rebate;
	printf("The GST: %.2f\n", GST);
}