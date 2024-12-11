int factorial(int integer) {
    int value = integer;
    if (integer == 0) {
        return 1;
    }
    else {
        value = value * factorial(value - 1);
    }
    return value;
}

int facto2(int integerN, int integerR) {
    int n_r = integerN - integerR;
    int number = factorial(integerN) / (factorial(integerR) * (factorial(n_r)));
    return number;
}