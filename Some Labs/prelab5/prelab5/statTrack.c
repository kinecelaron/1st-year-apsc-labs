#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/** Param: n - size of data */
double mean(double data[], int n);
double var(double data[], int n);
double sdev(double data[], int n);
double minimum(double data[], int n);

double mean(double data[], int n) {
    double sum = 0;
    double average = 0;
    int i;
    for (i = 0; i < n; i++) {
        sum += data[i];
    }
    average = sum / n;
    return average;
}

double var(double data[], int n) {
    double sum = 0;
    double mean1 = mean(data, n);  // Corrected function call
    int i;
    for (i = 0; i < n; i++) {
        sum += pow(data[i] - mean1, 2); // Use pow() for exponentiation
    }
    return sum / (n - 1); // Return variance directly
}

double sdev(double data[], int n) {
    return sqrt(var(data, n)); // Use sqrt() to calculate standard deviation
}

double minimum(double data[], int n) {
    double min = data[0]; // Initialize min with the first element
    for (int i = 1; i < n; i++) { // Start from the second element
        if (data[i] < min) {
            min = data[i];
        }
    }
    return min; // Return the minimum value
}