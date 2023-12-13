#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function for palindrome
bool palindrome(char input[]) {
    int middle = strlen(input) / 2;
    int length = strlen(input);
    for (int i = 0; i < middle; i++) {
        if (input[i] != input[length - i - 1]) {
            return false;
        }
    }
    return true;
}

int isRotation(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int idxToDel;

    if (len1 == len2) {
        for (int i = 0; i < strlen(str1); i++) {
            for (int j = 0; j < strlen(str2); j++) {
                if (str1[i] == str2[j]) {
                    idxToDel = j;
                    memmove(&str2[idxToDel], &str2[idxToDel + 1], strlen(str2) - idxToDel);
                    break;
                }
            }
        }
        if (strcmp(str2, "") == 0) {
            printf("Is rotation\n");
        } else {
            printf("Is not rotation\n");
        }
    }
}

bool isPunctuation(char c) {
    // Define the set of characters you consider as punctuation
    char punctuation[] = "!\"#$%&'()*+,-./:;<>?[\\]^_`{|}~";
    
    for (int i = 0; punctuation[i] != '\0'; i++) {
        if (c == punctuation[i]) {
            return true;
        }
    }
    
    return false;
}

int countPunctuation(const char *str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isPunctuation(str[i])) {
            count++;
        }
    }
    return count;
}

int main() {
    int i, j, n;
    printf("Enter how many words you want to order alphabetically: ");
    scanf("%d", &n);
    char word[n][20], temp[20];
    printf("Enter %d words \n", n);
    for (i = 0; i < n; i++) {
        scanf("%s", word[i]);
    }
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (strcmp(word[j], word[j + 1]) > 0) {
                strcpy(temp, word[j]);
                strcpy(word[j], word[j + 1]);
                strcpy(word[j + 1], temp);
            }
        }
    }
    printf("Your %d words in alphabetical order\n", n);
    for (i = 0; i < n; i++) {
        printf("%s\n", word[i]);
    }
    printf("\n");

    char input[100];
    int c;

    printf("Enter a string to check if it's a palindrome: ");
   scanf("%s", input);

    if (palindrome(input)) {
        printf("The input is a valid palindrome.\n");
    } else {
        printf("The input is not a valid palindrome.\n");
    }
    printf("\n");

    char str1[100], str2[100];

    printf("Enter the first string to check if it's a rotation: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    isRotation(str1, str2);
    printf("\n");

    while ((c = getchar()) != '\n' && c != EOF) {
        // Clear the input buffer
    }

    char str3[100];

    printf("Enter the sentence to count punctuation: ");
    scanf("%99[^\n]", str3);

    int punctuationCount = countPunctuation(str3);
    printf("Punctuation count: %d\n", punctuationCount);

    printf("Sentence contains %d punctuation characters.\n", punctuationCount);

    return 0;
}
