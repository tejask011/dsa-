#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
	int i;
    for( i = 0; i < n; i++) {
        if(arr[i] == key)
            return 1;
    }
    return 0;
}

int main() {
    int n, key, result;
    printf("Enter number of students: ");
    scanf("%d", &n);

    int roll[n];
    printf("Enter roll numbers:\n");
    int i;
    for(i = 0; i < n; i++) {
        scanf("%d", &roll[i]);
    }

    printf("Enter roll number to search: ");
    scanf("%d", &key);

    result = linearSearch(roll, n, key);

    if(result)
        printf("Student attended the training program.\n");
    else
        printf("Student did not attend the training program.\n");

    return 0;
}

