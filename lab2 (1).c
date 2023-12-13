#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, i, a[100], b[100], s[100];
    
    printf("Give number of elements: ");
    scanf("%d", &n);
    
    printf("Enter %d elements for the first array:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("First array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("Enter %d elements for the second array:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    printf("Second array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");

    // Sum the arrays
    printf("The sum:\n");
    for (i = 0; i < n; i++) {
        s[i] = a[i] + b[i];
        printf("%d\n", s[i]);
    }

    return 0;
}

