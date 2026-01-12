#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20

void ch1_11_11();
void ch1_11_12();
void ch1_12();
void ch1_15_1();
void ch1_15_2();
void ch1_15_3();
void ch1_15_31();
void ch1_15_32();
void ch1_15_33();

// main

int main() {
    // ch1_11_11();
    // ch1_11_12();
    // ch1_12();
    // ch1_15_1();
    // ch1_15_2();
    // ch1_15_3();
    // ch1_15_31();
    // ch1_15_32();
    ch1_15_33();
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

    printf("%ld %ld %ld %ld %ld\n", sizeof(char)*8, sizeof(short)*8, sizeof(int)*8, sizeof(double)*8, sizeof(float)*8);
}

void ch1_15_1() {
    int c; // char could be used but int is instead bc: EOF needs a type size big enough. EOF is defined in stdio.h
    // c = getchar();
    // while (c != EOF) { // EOF can be done using Control - d
    //     putchar(c);
    //     c = getchar();
    // }
    while ((c = getchar()) != EOF) {
        // printf("%d\n", c != EOF);
        putchar(c);
    }
    printf("Exiting while loop\n");
    printf("EOF takes the value: %d\n", EOF);
}

void ch1_15_2() {
    // count characters
    long nc;
    nc = 0;
    while (getchar() != EOF) {
        nc++;
    }
    printf("\n%ld\n", nc);
}

void ch1_15_3() {
    int c, nl;
    nl = 0;
    while ((c = getchar()) != EOF) 
    {
        if (c == '\n')
        {
            ++nl;
        }
    }
    printf("%d\n", nl);
}

void ch1_15_31() {
    int c, nl;
    nl = 0;
    while ((c = getchar()) != EOF) 
    {
        if (c == '\n' || c == ' ' || c == '\t')
        {
            ++nl;
        }
    }
    printf("%d\n", nl);
}

void ch1_15_32() {
    int c;
    int check = 0;
    while ((c = getchar()) != EOF) {
        if (c != ' ')
        {
            putchar(c);
            check = 0;
        } 
        else if (c == ' ' && !check) 
        {
            check = 1;
            putchar(c);
        }
    }
    printf("Exiting while loop\n");
    printf("EOF takes the value: %d\n", EOF);
}

void ch1_15_33() {
    int c;
    
    while ((c = getchar()) != EOF) {
        if (c == '\t'){
            printf("\\t");
        } else if (c == '\b') {
            printf("\\b");
        } else if (c == '\\') {
            printf("\\\\");
        } else {
            putchar(c);
        }
    }
}