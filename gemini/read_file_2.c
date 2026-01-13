#include <stdio.h>
#include <stdlib.h> // Required for malloc, realloc, free

#define INITIAL_CAPACITY 10
#define COLS 2

void read_file_dynamic() {
    FILE *file;
    // This is a pointer to an array of 2 ints.
    // It allows us to use data[i][0] syntax just like a normal 2D array.
    int (*data)[COLS]; 
    
    int row_count = 0;
    int capacity = INITIAL_CAPACITY;

    // 1. Initial Allocation
    data = malloc(capacity * sizeof(*data));
    if (data == NULL) {
        perror("Initial memory allocation failed");
        return;
    }

    file = fopen("data.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        free(data); // Don't forget to clean up if file fails!
        return;
    }

    // 2. Read Loop
    while (fscanf(file, "%d %d", &data[row_count][0], &data[row_count][1]) == 2) {
        row_count++;

        // 3. Check if we hit the limit
        if (row_count >= capacity) {
            // Strategy: Double the capacity to minimize expensive realloc calls
            int new_capacity = capacity * 2;
            
            // Use a temporary pointer in case realloc fails
            int (*temp)[COLS] = realloc(data, new_capacity * sizeof(*data));
            
            if (temp == NULL) {
                printf("Error: Out of memory! Could not expand array.\n");
                break; // Stop reading, but keep data we already have
            }
            
            // Success! Update our main pointers
            data = temp;
            capacity = new_capacity;
            printf("--- Array expanded to hold %d rows ---\n", capacity);
        }
    }

    fclose(file);

    // 4. Print Data
    printf("Successfully read %d lines:\n", row_count);
    for (int i = 0; i < row_count; i++) {
        printf("Row %d: %d, %d\n", i, data[i][0], data[i][1]);
    }

    // 5. Clean up
    free(data);
}

int main() {
    read_file_dynamic();
    return 0;
}