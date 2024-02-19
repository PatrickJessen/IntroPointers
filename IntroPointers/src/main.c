#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

char* reverseString(char* str) {
    int length = strlen(str);
    char* temp = malloc(sizeof(char) * length);
    strcpy(temp, str);
    int counter = 0;
    for (int i = length -1; i >= 0; i--) {
        temp[counter] = str[i];
        counter++;
    }
    return temp;
}

void bubbleSort(int arr[], int n) {
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

int countWords(char* str) {
    int count = 0;
    int wordNum = 0;

    while (*str != '\0') {
        if (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r' || *str == ',' || *str == '.' || *str == '!' || *str == '?') {
            wordNum = 0;
        }
        else if (wordNum == 0) {
            wordNum = 1;
            count++;
        }
        str++;
    }

    return count;
}

int compare(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

void sortWords()
{
    char str[] = "dette er en test a tilfældige ord";
    char* words[MAX_WORDS];
    int word_count = 0;

    char* token = strtok(str, " ");
    while (token != NULL && word_count < MAX_WORDS) {
        words[word_count] = _strdup(token);
        word_count++;
        token = strtok(NULL, " ");
    }

    qsort(words, word_count, sizeof(char*), compare);

    printf("Ordene i leksikografisk orden:\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s\n", words[i]);
        free(words[i]);
    }
}

int main()
{
    char* rambuk = "rambuk";
    char* kubmar = reverseString(rambuk);
    printf("%s \n", kubmar);

    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    char str[] = "Hello, test word, next word";
    int word_count = countWords(str);
    printf("Number of words: %d\n", word_count);
    
    sortWords();
	return 0;
}