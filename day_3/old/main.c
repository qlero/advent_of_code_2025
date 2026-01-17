#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_file.h"

int compute_part_1(char value[MAX_CHARS]) {

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

int countletter(char value[MAX_CHARS], char x)
{
    int i = 0;
    int count = 0;
    for (i = 0; i < strlen(value); i++){
        // printf("%d\n", i);
        if(value[i] == x){
            count++;
        }
    }
    return count;
}

long long compute_part_2(char value[MAX_CHARS]) {

    printf("%s\n", value);

    long long accumulator = 0;
    long long digit_position = 1;

    int to_remove = strlen(value) - 12;

    // char last;
    char previous;
    int index = 0;

    // Eliminates the small digits
    // 2465480448768841
    // 144204195652221
    while (countletter(value, '-') < strlen(value) - 12){
        for (int i = 1; i < strlen(value); i++) {
            if (value[i-1] != '-') {
                previous = value[i-1];
                index = i-1;
            }
            if (previous <= value[i] && countletter(value, '-') < strlen(value) - 12){
                value[index] = '-';
                to_remove--;
                // break;
            }
        }
        // int i = strlen(value);
        // while (i--) {
        //     // printf("%d", i);
        //     if (value[i] != '-') {
        //         previous = value[i];
        //         index = i;
        //     }
        //     // printf("%d %c %d\n", i, value[i], index);
        //     if (previous <= value[i-1] && countletter(value, '-') < strlen(value) - 12){
        //         value[index] = '-';
        //         to_remove--;
        //     } 
        //     // printf("%d %s\n", i, value);
        //     // break;
        // }     
    }

    for (int i = strlen(value)-1; i >= 0; i--) {
        if (value[i] != '-'){
            accumulator += (long long)(value[i]-'0') * digit_position;
            digit_position *= 10;
        }
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
    int day_31_sum = 0;


    // loads file
    read_lines = day_3_read_file(filename, values);
    if (read_lines == -1) 
    {
        return 1;
    }
    printf("Number of lines read: %d\n", read_lines);

    /*
    DAY 3 PART 1
    */

    for (int i = 0; i < read_lines; i++) {
        max = compute_part_1(values[i]);
        day_31_sum += max;
        // printf("Line %d: %s -> %d | %d\n", i, values[i], max, day_31_sum);
    }

    printf("Deduced solution (day 3, part 1):\t%d\n", day_31_sum);

    /*
    DAY 3 PART 2
    */

    long long day_32_sum = 0;
    long long llmax = 0;

    for (int i = 0; i < read_lines; i++) {
        llmax = compute_part_2(values[i]);
        day_32_sum += llmax;
        printf("Line %d: %s -> %lld | %lld\n", i, values[i], llmax, day_32_sum);
    }

    printf("Deduced solution (day 3, part 2):\t%lld\n", day_32_sum);

    return 0;
}