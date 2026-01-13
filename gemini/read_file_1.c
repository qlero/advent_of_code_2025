#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100 // Maximum number of lines we expect
#define COLS 2       // We know each line has 2 numbers

void read_file() {
    FILE *file;
    // A 2D array: [Row Index][Column Index]
    int data[MAX_ROWS][COLS]; 
    int row_count = 0;

    // 1. Open the file for reading ("r")
    file = fopen("data.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // 2. Read the file
    // fscanf returns the number of items successfully read.
    // We expect 2 items per loop iteration.
    // We also check row_count to prevent writing outside the array memory.
    while (fscanf(file, "%d %d", &data[row_count][0], &data[row_count][1]) == 2) {
        
        row_count++;
        
        // Safety check to avoid Buffer Overflow
        if (row_count >= MAX_ROWS) {
            printf("Warning: Array full, stopped reading early.\n");
            break;
        }
    }

    // 3. Close the file
    fclose(file);

    // Optional: Print the array to prove we stored it correctly
    printf("Successfully read %d lines:\n", row_count);
    for (int i = 0; i < row_count; i++) {
        printf("Row %d: %d, %d\n", i, data[i][0], data[i][1]);
    }
}

int main() {
    read_file();
    return 0;
}