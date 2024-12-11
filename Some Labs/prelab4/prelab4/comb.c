int factorial(int integer) {
    if (integer == 0) {
        return 1; // Base case: 0! = 1
    }
    else {
        return integer * factorial(integer - 1); // Recursive case
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