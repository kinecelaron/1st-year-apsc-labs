/*
*Author:Damien R Mwinamila
*Date: 22/09/24
*Purpose: Convert Newtons taken as input to pounds output
*to 3 decimal places
* Lab Section: L1P
* UBC-email:dmwinami@student.ubc.ca
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*constants*/
#define Ratio 4.448

int main(void) {
	double newtons;
	double pounds;

	printf("Input force in newtons:\n");
	scanf("%lf", &newtons);

	pounds = newtons / Ratio;
	printf("The force in pounds is:%.3f\n", pounds);

	return 0;

}