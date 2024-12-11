#include <stdio.h>
#include <stdlib.h>

int main(void) {
    double temp_Start;    
    double temp_diff;     
    int num_temp = 0;     
    int count = 0;       
    double Fahren;        


    while (num_temp < 1) {
        printf("Input a positive integer for the number of temperatures:\n");
        scanf("%d", &num_temp);
    }


    printf("Input a starting temperature (up to 2 decimal places):\n");
    scanf("%lf", &temp_Start);


    printf("Input the temperature increment:\n");
    scanf("%lf", &temp_diff);

    printf("Celsius    Fahrenheit\n");


    while (count < num_temp) {
        Fahren = (9.0 / 5.0) * temp_Start + 32.0; 
        printf("%.2f       %.2f\n", temp_Start, Fahren);
        temp_Start = temp_Start + temp_diff;  
        count++;
    }

    return 0;
}