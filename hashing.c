#include <stdio.h>
#define SIZE 10

int hash(int key){ return key % SIZE; }
int hash2(int key){ return 7 - (key % 7); }

void insertLinear(int a[], int key){
    int i, index = hash(key);
    for(i=0;i<SIZE;i++){
        int newIndex = (index + i) % SIZE;
        if(a[newIndex] == -1){
            a[newIndex] = key;
            return;
        }
    }
}

void insertQuadratic(int a[], int key){
    int i, index = hash(key);
    for(i=0;i<SIZE;i++){
        int newIndex = (index + i*i) % SIZE;
        if(a[newIndex] == -1){
            a[newIndex] = key;
            return;
        }
    }
}

void insertDouble(int a[], int key){
    int i, index = hash(key), step = hash2(key);
    for(i=0;i<SIZE;i++){
        int newIndex = (index + i*step) % SIZE;
        if(a[newIndex] == -1){
            a[newIndex] = key;
            return;
        }
    }
}

int search(int a[], int key){
	int i;
    for(i=0;i<SIZE;i++){
        if(a[i] == key)
            return i;
    }
    return -1;
}

int main(){
    int a[SIZE], n, i, key, ch, pos;
    for(i=0;i<SIZE;i++) a[i] = -1;
    printf("Enter number of clients: ");
    scanf("%d",&n);
    printf("1.Linear Probing\n2.Quadratic Probing\n3.Double Hashing\nEnter choice: ");
    scanf("%d",&ch);
    for(i=0;i<n;i++){
        printf("Enter telephone number: ");
        scanf("%d",&key);
        switch(ch){
            case 1: insertLinear(a,key); break;
            case 2: insertQuadratic(a,key); break;
            case 3: insertDouble(a,key); break;
            default: printf("Invalid choice\n"); return 0;
        }
    }
    printf("\nEnter telephone number to lookup: ");
    scanf("%d",&key);
    pos = search(a,key);
    if(pos==-1)
        printf("Client not found in directory.\n");
    else
        printf("Client found: Telephone number = %d at index %d\n", a[pos], pos);
    return 0;
}

