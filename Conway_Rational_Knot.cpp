#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int numerator;     // 분자
    int denominator;   // 분모
} Rational;

int gcd(int a, int b);
void simplify(Rational *r);
void printRational(Rational r);
void solveTangle(Rational r);

Rational T(Rational r);
Rational R(Rational r);

int main() {
    Rational init;
    printf("Initial Status (in a/b format):\t");
    scanf("%d/%d", &init.numerator, &init.denominator);
    simplify(&init);

    printf("Number of Operations:\t");
    int input_size;
    scanf("%d", &input_size);
    char input[input_size+1];
    scanf("%s", input);
    if (input[0]=='R') {
        printf("Cannot start with R.");
        return 0;
    }

    for (int i=0;i<input_size;i++) {
        if (input[i]=='T') init = T(init);
        else if (input[i]=='R') init = R(init);
        else {
            printf("Can only include T or R");
            return 0;
        }
        printRational(init);
    }
    
    solveTangle(init);
}

int gcd(int a, int b) {   // Euclidean Algorithm
    if (b==0) return a;
    return gcd(b, a%b);
}

void simplify(Rational *r) {
    int common_divisor = gcd(r->numerator, r->denominator);
    r->numerator /= common_divisor;
    r->denominator /= common_divisor;

    if (r->denominator < 0) {   // Normalize the sign - the minus is always stored in numerator
        r->numerator = -(r->numerator);
        r->denominator = -(r->denominator);
    }

    if (r->numerator == 0) r->denominator = 1;   // Keep notation of 0 to 0/1
}

void printRational(Rational r) {
    printf("%d/%d\n", r.numerator, r.denominator);
}

void solveTangle(Rational r) {
    if (r.numerator == 0) {
        printf("Tangle has already been solved.\n");
        return;
    }
    char *operations = NULL;
    int operations_size = 0;
    int capacity = 1;
    operations = (char *)malloc(capacity * sizeof(char));

    while (r.numerator != 0) {
        if (r.numerator > 0) {
            r = R(r);
            operations[operations_size++] = 'R';
        } else {
            r = T(r);
            operations[operations_size++] = 'T';
        }

        // Resize the array if needed
        if (operations_size >= capacity) {
            capacity *= 2;
            operations = (char *)realloc(operations, capacity * sizeof(char));
        }
    }
    for (int i = 0; i < operations_size; i++) {
        printf("%c", operations[i]);
    }
    printf("\n");

    free(operations);
}

Rational T(Rational r) {
    Rational result = {r.numerator + r.denominator, r.denominator};
    simplify(&result);
    return result;
}

Rational R(Rational r) {
    Rational result = {-(r.denominator), r.numerator};
    simplify(&result);
    return result;
}
