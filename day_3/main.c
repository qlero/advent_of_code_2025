#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_file.h"

int check(char value[MAX_CHARS]) {

    int accumulator = 0;

    for (int i = 0; i < strlen(value)-1; i++) {
        for (int j = i+1; j < strlen(value); j++){
            int temp = (value[i] - '0') * 10 + (value[j] - '0');
            // printf("%d ", temp);
            if (temp > accumulator) {
                accumulator = temp;
            }
        }
        // printf("\n");
    }

    return accumulator;

}

int main() 
{
    // declares the target filename
    char * filename = "data.txt";
    
    char values[MAX_ELEMENTS][MAX_CHARS] = { 0 };

    int read_lines;
    int max = 0;
    int sum = 0;


    // loads file
    read_lines = day_3_read_file(filename, values);
    if (read_lines == -1) 
    {
        return 1;
    }
    printf("Number of lines read: %d\n", read_lines);

    // prints lines
    for (int i = 0; i < read_lines; i++) {
        max = check(values[i]);
        sum += max;
        printf("Line %d: %s -> %d | %d\n", i, values[i], max, sum);
    }

    printf("Deduced solution (day 3, part 1):\t%d\n", sum);

    return 0;
}