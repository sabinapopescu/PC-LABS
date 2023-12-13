#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void bubble(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void randomize(int** a, int r, int c, int max);
void fillSpiralRecursive(int n, int m, int b[], int a[n][m], int left, int right, int top, int bottom, int num) {
    if (left > right || top > bottom) {
        return; 
    }

    for (int i = left; i <= right; i++) {
        a[top][i] = b[num++];
    }
    top++;

    
    for (int i = top; i <= bottom; i++) {
        a[i][right] = b[num++];
    }
    right--;

 if (top <= bottom) {
       
        for (int i = right; i >= left; i--) {
            a[bottom][i] = b[num++];
        }
        bottom--;
    }

   
    if (left <= right) {
        
        for (int i = bottom; i >= top; i--) {
            a[i][left] = b[num++];
        }
        left++;
    }

    
    fillSpiralRecursive(n, m, b, a, left, right, top, bottom, num);
}

void fillSpiral(int n, int m, int b[], int a[n][m]) {
    fillSpiralRecursive(n, m, b, a, 0, m - 1, 0, n - 1, 0);
}

 
int main(void)
{
    int r, c;

    printf("Enter the number of rows and columns: ");
    scanf("%d", &r);
    scanf("%d", &c);

    int** a = (int**)malloc(r * sizeof(int*));

    for (int i = 0; i < r; i++)
    {
        a[i] = (int*)malloc(c * sizeof(int));
    }

    randomize(a, r, c, 100);
    
     int z = 0;
    int b[r*c];
    int spiralMatrix[r][c];

    printf("Bidimensional Array written as a matrix: \n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }
        printf("\n");
    printf("Bidimensional array written in a line: \n");
      for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            b[z] = a[i][j];
            z++;
            printf("%3d ", b[z - 1]);
        }
    }      printf("\n");
    bubble(b, r * c);

    printf("Sorted array: \n");
    for (int i = 0; i < r * c; i++) {
        printf("%3d ", b[i]);
    }
    printf("\n");
     printf("\n");
    
    fillSpiral(r, c, b, spiralMatrix);

        printf("The transformed two-dimensional array in spiral order:\n");
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                printf("%2d ", spiralMatrix[i][j]);
            }
            printf("\n");
        }

    for (int i = 0; i < r; i++)
    {
        free(a[i]);
    }
    free(a);
    
    return 0;
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

