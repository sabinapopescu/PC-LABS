#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rando(int** a, int r, int c, int max) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            a[i][j] = (rand() % max) + 1;
        }
    }
}

void selectionSortColumns(int** a, int r, int c) {
    for (int col = 0; col < c; col++) {
        for (int i = 0; i < r - 1; i++) {
            int min_index = i;
            for (int j = i + 1; j < r; j++) {
                if (a[j][col] < a[min_index][col]) {
                    min_index = j;
                }
            }

            // Swap the elements in the column
            int temp = a[i][col];
            a[i][col] = a[min_index][col];
            a[min_index][col] = temp;
        }
    }
}

void insertionSortColumns(int** a, int r, int c) {
    for (int col = 0; col < c; col++) {
        for (int i = 1; i < r; i++) {
            int key = a[i][col];
            int j = i - 1;
            while (j >= 0 && a[j][col] > key) {
                a[j + 1][col] = a[j][col];
                j = j - 1;
            }
            a[j + 1][col] = key;
        }
    }
}

int findFirstOccurrence(int arr[], int size, int target) {
    int *ptr = arr; // Initialize a pointer to the beginning of the array

    for (int i = 0; i < size; i++) {
        if (*ptr == target) {
            return i;  // Return the index of the first occurrence
        }
        ptr++; // Move the pointer to the next element
    }
    
    return -1; // Return -1 if the target value is not found
}
int countOccurrence(int arr[], int size, int target) {
    int *ptr = arr; // Initialize a pointer to the beginning of the array
    int k=0;
    for (int i = 0; i < size; i++) {
        if (*ptr == target) {
           k=k+1;
           
        }
         
        ptr++; // Move the pointer to the next element
    }
    
    return k; 
}
void randomize(int** a, int r, int c, int max)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            a[i][j] = (rand() % max) + 1;
            
        }
    }
}

void sumColumns(int r, int c, int **a) {
    for (int col = 0; col < c; col++) {
        int sumcolumns = 0;
        for (int i = 0; i < r; i++) {
            sumcolumns += a[i][col];
        }
        printf("Sum of column %d is: %d\n", col, sumcolumns);
    }
}

void sumRows(int r, int c, int **a) {
    for (int row = 0; row < r; row++) {
        int sumrows = 0;
        for (int j = 0; j < c; j++) {
            sumrows += a[row][j];
        }
        printf("Sum of row %d is: %d\n", row, sumrows);
    }
}

int main(void) {
    srand(time(NULL));

    int r, c;

    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &r, &c);

    int** a = (int**)malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++) {
        a[i] = (int*)malloc(c * sizeof(int));
    }

    rando(a, r, c, 100);

    printf("Original 2D Array:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }

    selectionSortColumns(a, r, c);

    printf("2D Array after Selection Sort on Columns:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }

    insertionSortColumns(a, r, c);

    printf("2D Array after Insertion Sort on Columns:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < r; i++) {
        free(a[i]);
    }
    free(a);
    int size,target;
    printf("give array size ");
    scanf("%d", &size);

   
    int *arr = (int *)malloc(size * sizeof(int));


    printf("give array values\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
printf("give a specific value\n");
    scanf("%d", &target);
    
    int index = findFirstOccurrence(arr, size, target);
    
    if (index != -1) {
        printf("the first occurrence of %d is at index %d\n", target, index);
    } else {
        printf("%d not found in the array\n", target);
    }
    int k= countOccurrence(arr, size, target);
    printf("%d value found in the array %d times\n", target,k);
    free(arr);


   printf("Enter the number of rows and columns: ");
    scanf("%d", &r);
    scanf("%d", &c);

    int** ar = (int**)malloc(r * sizeof(int*));

    for (int i = 0; i < r; i++)
    {
        ar[i] = (int*)malloc(c * sizeof(int));
    }

    randomize(ar, r, c, 100);
    printf("Bidimensional Array written as a matrix: \n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%3d ", ar[i][j]);
        }
        printf("\n");
    }
     sumColumns(r, c, ar);
    sumRows(r, c, ar);

    for (int i = 0; i < r; i++) {
        free(ar[i]);
    }
    free(ar);

    return 0;
}


