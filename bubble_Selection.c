#include <stdio.h>

void selectionSort(float a[], int n) {
    int i, j, min;
    float temp;
    for(i = 0; i < n - 1; i++) {
        min = i;
        for(j = i + 1; j < n; j++) {
            if(a[j] < a[min])
                min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

void bubbleSort(float a[], int n) {
    int i, j;
    float temp;
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {
    float per[100];
    int n, ch, i;
    printf("Enter number of students: ");
    scanf("%d", &n);
    printf("Enter percentages:\n");
    for(i = 0; i < n; i++)
        scanf("%f", &per[i]);
    printf("1.Selection Sort\n2.Bubble Sort\nEnter choice: ");
    scanf("%d", &ch);
    switch(ch) {
        case 1: selectionSort(per, n); break;
        case 2: bubbleSort(per, n); break;
        default: printf("Invalid choice"); return 0;
    }
    printf("Top five scores:\n");
    for(i = n - 1; i >= n - 5 && i >= 0; i--)
        printf("%.2f\n", per[i]);
    return 0;
}

