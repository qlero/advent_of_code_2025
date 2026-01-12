#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_file.h"

int main() 
{
    // declares the target filename
    char * filename = "data.txt";

    // declares the rotation and distance arrays
    long start[MAX_ELEMENTS]; 
    long end[MAX_ELEMENTS]; 
    
    long i = 0;
    long j;
    long cutoff;
    long sum;

    long read_lines;
    
    int check;

    char buffer[16] = {0};

    // loads file
    read_lines = day_2_read_file(filename, start, end);
    if (read_lines == -1) 
    {
        return 1;
    }
    printf("Number of lines read: %ld\n", read_lines);
    // for (i = 0; i < read_lines; i++) {
    //     printf("%ld - %ld\n", start[i], end[i]);
    // }
    // printf("\n");

    /*
    The ranges are separated by commas (,).
    Each range gives its first ID and last ID separated by a dash (-).
    
    You can find the invalid IDs by looking for any ID which is made only of some sequence of digits repeated twice. 
    So:
        - 55 (5 twice),
        - 6464 (64 twice),
        - and 123123 (123 twice) would all be invalid IDs.

    None of the numbers have leading zeroes; 0101 isn't an ID at all. (101 is a valid ID that you would ignore.)
    Your job is to find all of the invalid IDs that appear in the given ranges. In the above example:
    */

    for (i = 0; i < read_lines; i++) {
        for (j = start[i]; j <= end[i]; j++) {
            // reads the number into a character array
            sprintf(buffer, "%ld", j);
            // checks the character array for repetitions
            if (strlen(buffer) % 2 == 0){
                cutoff = strlen(buffer) / 2;
                check = 1;
                for (int u = 0; u < cutoff; u++){
                    if (buffer[u] != buffer[u+cutoff]) {
                        check = 0;
                    }
                }
                if (check) {
                    printf("FOUND: %ld\n", j);
                    sum += j;
                }
            }
        }
    }

    printf("Deduced value (day 1, part 1):\t%ld\n", sum);

    return 0;
}