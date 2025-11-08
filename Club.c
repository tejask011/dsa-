#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int prn;
    char name[20];
    struct node *next;
};

struct node* create(int prn, char name[]) {
    struct node* t = (struct node*)malloc(sizeof(struct node));
    t->prn = prn;
    strcpy(t->name, name);
    t->next = NULL;
    return t;
}

void display(struct node* head) {
    struct node* p = head;
    printf("\nMembers:\n");
    while(p) {
        printf("%d %s\n", p->prn, p->name);
        p = p->next;
    }
}

int count(struct node* head) {
    int c = 0;
    while(head) { c++; head = head->next; }
    return c;
}

struct node* add(struct node* head, int prn, char name[], int pos) {
    struct node* t = create(prn, name);
    if(pos == 1) { t->next = head; return t; }
    struct node* p = head;
    while(p->next && p->next->next) p = p->next;
    if(pos == 2 && head) { t->next = p->next; p->next = t; return head; }
    while(p->next) p = p->next;
    p->next = t; return head;
}

struct node* del(struct node* head, int prn) {
    struct node *p = head, *q = NULL;
    while(p && p->prn != prn) { q = p; p = p->next; }
    if(!p) return head;
    if(!q) head = head->next;
    else q->next = p->next;
    free(p); return head;
}

struct node* concat(struct node* a, struct node* b) {
    struct node* p = a;
    while(p->next) p = p->next;
    p->next = b;
    return a;
}

int main() {
    struct node *A = NULL, *B = NULL;
    int ch, prn;
    char name[20];
    do {
        printf("\n1.Add President\n2.Add Member\n3.Add Secretary\n4.Delete Member\n5.Display\n6.Count\n7.Concat DivB\n8.Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: printf("PRN Name: "); scanf("%d%s",&prn,name); A = add(A,prn,name,1); break;
            case 2: printf("PRN Name: "); scanf("%d%s",&prn,name); A = add(A,prn,name,0); break;
            case 3: printf("PRN Name: "); scanf("%d%s",&prn,name); A = add(A,prn,name,2); break;
            case 4: printf("PRN to delete: "); scanf("%d",&prn); A = del(A,prn); break;
            case 5: display(A); break;
            case 6: printf("Total Members: %d\n", count(A)); break;
            case 7: printf("Enter one member for DivB (PRN Name): "); scanf("%d%s",&prn,name); B = add(B,prn,name,1); A = concat(A,B); printf("Lists concatenated.\n"); break;
        }
    } while(ch != 8);
    return 0;
}

