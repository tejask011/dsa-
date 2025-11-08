#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid;
    while(low <= high) {
        mid = (low + high) / 2;
        if(arr[mid] == key)
            return 1;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return 0;
}

int main() {
    int n, key, result;
    printf("Enter number of students: ");
    scanf("%d", &n);

    int roll[n];
    printf("Enter roll numbers in sorted order:\n");
    int i;
    for( i = 0; i < n; i++) {
        scanf("%d", &roll[i]);
    }

    printf("Enter roll number to search: ");
    scanf("%d", &key);

    result = binarySearch(roll, n, key);

    if(result)
        printf("Student attended the training program.\n");
    else
        printf("Student did not attend the training program.\n");

    return 0;
}

