/* Author:   Damien Robert Mwinamila
 * Date:     01/10/2024
 * Purpose:  Calculate the total cost of elelctricity per month
 * Lab: L1P
 */
#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#define charge1 0.091
#define charge2 0.063
#define delivery_charge 12.98
#define tax 0.11


int main(void) {
	double kilowatt_hours;
	double additional_kilowatt_hours;
	double final_cost;


	printf("Please input the amount of kilowatthours:\n");
	scanf_s("%lf",&kilowatt_hours);

	/*if the kilowatt hours input is negative*/

	if (kilowatt_hours < 0) {
		printf("Error: invalid input.\n");
	}

	/*if the kilowatt hours input is less than 300*/

	else if(kilowatt_hours<=300){
		final_cost = kilowatt_hours * charge1;
		final_cost = final_cost + delivery_charge;
		final_cost = 1.11 * final_cost;
		printf("Total cost of electricity is $ %.2f\n", final_cost);

	}

	/*if the kilowatt hours input is more than 300*/
	else {
		final_cost = 300 * charge1;
		additional_kilowatt_hours = kilowatt_hours - 300;
		final_cost = final_cost + (additional_kilowatt_hours * charge2);
		final_cost = final_cost + delivery_charge;
		final_cost = 1.11 * final_cost;
		printf("Total cost of electricity is $ %.2f\n", final_cost);


	}
}