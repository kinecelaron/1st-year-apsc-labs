/*
*Author:Damien R Mwinamila
*Date: 22/09/24
*Purpose: Takes input 2 lengths and 2 angles of a robot arm to compute the final
		position of the robot arm
* Lab Section: L1P
* UBC-email:dmwinami@student.ubc.ca
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void) {
	double x;
	double y;
	double angle1;
	double angle2;
	double length_AB;
	double length_BC;


	printf("Input length of A to B:\n");
	scanf("%lf", &length_AB);

	printf("Input length of B to C:\n");
	scanf("%lf", &length_BC);

	printf("Input angle in radians going counterclockwise from x-axis to direction of AB:\n");
	scanf("%lf", &angle1);

	printf("Input angle in radians going counterclockwise from x-axis to direction of BC:\n");
	scanf("%lf", &angle2);

	/*compute the position of C*/

	x= length_AB *  cos(angle1) + length_BC* cos(angle2);
	y= length_AB *  sin(angle1) + length_BC * sin(angle2);

	printf("(%.6f, %.6f)\n", x, y);

	return 0;
}