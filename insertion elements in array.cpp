#include <stdio.h>  // Standard I/O library for printf and scanf

int main() {
    // Declare variables
    int i, size = 5, x, pos; // i: loop variable, size: current number of elements, x: element to insert, pos: insertion position
    
    // Declare and initialize an array with a capacity of 10, but only using first 5 slots initially
    int arr[10] = {2, 4, 6, 8, 12}; // The rest of the elements are uninitialized (garbage values)
    
    // Display the elements of the array before insertion
    printf("The array elements before insertion operation:\n");
    for (i = 0; i < size; i++)
        printf("arr[%d] = %d\n", i, arr[i]);

    // Prompt user to enter the new element to insert
    printf("\nEnter the element to be inserted: ");
    scanf("%d", &x); // Store user input in variable x

    // Prompt user to enter the position where the element should be inserted
    printf("Enter the position to insert (1 to %d): ", size + 1);
    scanf("%d", &pos); // Store user input in variable pos

    // Validate the position entered by the user
    if (pos < 1 || pos > size + 1) { // Position must be between 1 and size+1 (1-based index)
        printf("Invalid position! Position should be between 1 and %d.\n", size + 1);
        return 1; // Exit the program with an error code
    }

    // Shift elements to the right starting from the last element to create space
    // This prevents overwriting elements before inserting the new one
    for (i = size; i >= pos; i--) {
        arr[i] = arr[i - 1]; // Move element at index i-1 to index i
    }

    // Insert the new element at the desired position (convert 1-based index to 0-based index)
    arr[pos - 1] = x;
    size++; // Increase size of the array to reflect new element

    // Display the elements of the array after insertion
    printf("\nThe array elements after insertion operation:\n");
    for (i = 0; i < size; i++)
        printf("arr[%d] = %d\n", i, arr[i]);

    return 0; // Return 0 to indicate successful execution
}
