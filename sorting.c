#include <stdio.h>6
void selectionSort(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minPos = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minPos]) {
                minPos = j;
            }
        }
        float temp = arr[i];
        arr[i] = arr[minPos];
        arr[minPos] = temp;
    }
}
void bubbleSort(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void displayArray(float arr[], int n) {
    printf("\nSorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}
void showTop5(float arr[], int n) {
    int limit = (n < 5) ? n : 5;
    printf("\nTop %d Scores:\n", limit);
    for (int i = n - 1; i >= n - limit; i--) {
        printf("%.2f\n", arr[i]);
    }
}
int main() {
    float marks[100];
    int n, choice;   
    printf("Enter number of students: ");
    scanf("%d", &n);   
    printf("Enter percentages:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &marks[i]);
    }
    printf("\n1. Selection Sort\n");
    printf("2. Bubble Sort\n");
    printf("Choose (1 or 2): ");
    scanf("%d", &choice);
    if (choice == 1) {
        selectionSort(marks, n);
    } else if (choice == 2) {
        bubbleSort(marks, n);
    } else {
        printf("Invalid choice!\n");
        return 1;
    }
    displayArray(marks, n);
    showTop5(marks, n);
    return 0;
}