#include "read_file.h"

void update_position(char rotation, int distance, int * position);

int main() 
{
    // declares the target filename
    char * filename = "data.txt";

    // declares the rotation and distance arrays
    char rotations[MAX_ROWS]; 
    int  distances[MAX_ROWS]; 
    long read_lines;

    // loads file
    read_lines = day_1_read_file(filename, rotations, distances);
    if (read_lines == -1) 
    {
        return 1;
    }
    printf("Number of lines read: %ld\n", read_lines);

    /*
    ---- day 1 exercise 1 logic ----

    The attached document (your puzzle input) contains a sequence of rotations, one per line, which tell you how to open the safe. 
    A rotation starts with an L or R which indicates whether the **rotation should be to the left (toward lower numbers) or to the right (toward higher numbers)**. 
    Then, the rotation has a distance value which indicates **how many clicks** the dial should be rotated in that direction.

    So, if the dial were pointing at 11, a rotation of R8 would cause the dial to point at 19. 
    After that, a rotation of L19 would cause it to point at 0.
    Because the dial is a circle, turning the dial left from 0 one click makes it point at 99. 
    Similarly, turning the dial right from 99 one click makes it point at 0.

    -> 0-99 cycle

    So, if the dial were pointing at 5, a rotation of L10 would cause it to point at 95. 
    After that, a rotation of R5 could cause it to point at 0.

    The dial starts by pointing at 50.

    You could follow the instructions, but your recent required official North Pole secret entrance security training seminar taught you that the safe is actually a decoy. 
    The actual password is the number of times the dial is left pointing at 0 after any rotation in the sequence.
    For example, suppose the attached document contained the following rotations:

    L68    L30    R48    L5    R60    L55    L1    L99    R14    L82
    Following these rotations would cause the dial to move as follows:

    The dial starts by pointing at 50.
    The dial is rotated L68 to point at 82.
    The dial is rotated L30 to point at 52.
    The dial is rotated R48 to point at 0.
    The dial is rotated L5 to point at 95.
    The dial is rotated R60 to point at 55.
    The dial is rotated L55 to point at 0.
    The dial is rotated L1 to point at 99.
    The dial is rotated L99 to point at 0.
    The dial is rotated R14 to point at 14.
    The dial is rotated L82 to point at 32.

    Because the dial points at 0 a total of three times during this process, the password in this example is 3.

    */

    int password = 0;
    int position = 50;

    for (int i; i < read_lines; i++)
    {
        update_position(rotations[i], distances[i], &position);
        if (position == 0)
        {
            password++;
        }
    }

    printf("Deduced password: %d\n", password);

    return 0;
}

void update_position(char rotation, int distance, int * position)
{ 
    // Updates position
    switch ( rotation )
    {
        case 'L':
            *position -= distance;
            break;
        default: // for 'R'
            *position += distance;
            break;
    }

    // Applies cycle
    while (*position < 0 || *position > 99) 
    {
        if (*position > 99)
        {
            *position  = *position - 100;
        } 
        if (*position < 0) 
        {
            *position  = 100 + *position;
        }
    }
}