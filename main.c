#include <stdio.h>
#include <stdlib.h>

// Function to concatenate two strings
char* concatenate(char *str1, char *str2) {
    // Pointers to traverse the strings
    char *ptr1 = str1;
    char *ptr2 = str2;
    
    // Calculate the length of str1
    int len1 = 0;
    while (*ptr1 != '\0') {
        len1++;
        ptr1++;
    }

    // Calculate the length of str2
    int len2 = 0;
    while (*ptr2 != '\0') {
        len2++;
        ptr2++;
    }

    // Allocate memory for the concatenated string
    // +1 for the null terminator
    char *result = (char *)malloc((len1 + len2 + 1) * sizeof(char));

    if (result == NULL) {
        // Memory allocation failed
        printf("Memory allocation failed!\n");
        return NULL;
    }

    // Reset the pointers to the beginning of the strings
    ptr1 = str1;
    ptr2 = str2;

    // Copy characters from str1 to result
    char *ptrResult = result;
    while (*ptr1 != '\0') {
        *ptrResult = *ptr1;
        ptrResult++;
        ptr1++;
    }

    // Copy characters from str2 to result
    while (*ptr2 != '\0') {
        *ptrResult = *ptr2;
        ptrResult++;
        ptr2++;
    }

    // Null terminate the concatenated string
    *ptrResult = '\0';

    return result;
}

int main() {
    char str1[] = "Gary ";
    char str2[] = "Chen";

    char *concatenatedString = concatenate(str1, str2);

    if (concatenatedString != NULL) {
        printf("Concatenated String: %s\n", concatenatedString);
        // Free the allocated memory
        free(concatenatedString);
    }

    return 0;
}
