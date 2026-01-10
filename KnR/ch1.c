#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20

void ch1_11_11();
void ch1_11_12();
void ch1_12_11();
void ch1_15();

// main

int main() {
    ch1_11_11();
    ch1_11_12();
    ch1_12();
    ch1_15();
}
 
// function

void ch1_11_11() {
    printf("Hello, World!\n");
}

void ch1_11_12() {
    printf("Hello, World!\c"); // will raise a warning
    printf("\n"); // will raise a warning
}

void ch1_12() {
    int i;
    int fahrenheit, celsius;

    for (i = LOWER; i <= UPPER; i = i + STEP) {
        fahrenheit = i;
        celsius = 5 * (fahrenheit - 32) / 9;
        printf("%4dF\t%4dC\n", fahrenheit, celsius);
    }

    float fcelsius, ffahrenheit;

    printf("#### Fahrenheit to Celsius converter #####\n");
    for (i = LOWER; i <= UPPER; i = i + STEP) {
        fahrenheit = i;
        fcelsius = 5 * ((float)fahrenheit - 32) / 9;
        printf("%4dF\t%5.1fC\n", fahrenheit, fcelsius);
    }

    printf("#### Celsius to Fahrenheit converter #####\n");
    for (i = LOWER; i <= UPPER; i = i + STEP) {
        fcelsius = i;
        ffahrenheit = 9.0 * fcelsius / 5.0 + 32.0;
        printf("%4.0fC\t%5.1fF\n", fcelsius, ffahrenheit);
    }

    printf("#### Celsius to Fahrenheit converter #####\n");
    for (i = 300; i >= 0; i = i - 20) {
        fcelsius = i;
        ffahrenheit = 9.0 * fcelsius / 5.0 + 32.0;
        printf("%4.0fC\t%5.1fF\n", fcelsius, ffahrenheit);
    }

    printf("%d %d %d %d %d\n", sizeof(char)*8, sizeof(short)*8, sizeof(int)*8, sizeof(double)*8, sizeof(float)*8);
}

void ch1_15() {
    int c;
    c = getchar();
    while (c != EOF) { // EOF can be done using Control - d
        putchar(c);
        c = getchar();
    }
    printf("Exiting while loop\n");
}