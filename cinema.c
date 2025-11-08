#include <stdio.h>
#include <stdlib.h>

struct seat {
    int no;
    int booked;
    struct seat *next, *prev;
};

struct seat* createRow(int n) {
    struct seat *head=NULL,*p=NULL,*t;
    int i;
    for(i=1;i<=n;i++){
        t=(struct seat*)malloc(sizeof(struct seat));
        t->no=i; t->booked=0; t->next=NULL; t->prev=p;
        if(!head) head=t;
        if(p) p->next=t;
        p=t;
    }
    return head;
}

void display(struct seat* h){
    while(h){ printf("%d[%s] ",h->no,h->booked?"X":"O"); h=h->next; }
    printf("\n");
}

void book(struct seat* h,int no){
    while(h && h->no!=no) h=h->next;
    if(!h) printf("Invalid seat\n");
    else if(h->booked) printf("Already booked\n");
    else { h->booked=1; printf("Seat %d booked\n",no); }
}

void cancel(struct seat* h,int no){
    while(h && h->no!=no) h=h->next;
    if(!h) printf("Invalid seat\n");
    else if(!h->booked) printf("Seat not booked\n");
    else { h->booked=0; printf("Seat %d cancelled\n",no); }
}

int main(){
    struct seat* rows[10];
    int i;
    for(i=0;i<10;i++) rows[i]=createRow(7);

    rows[0]->next->booked=1;
    rows[2]->next->next->booked=1;

    int ch,row,no;
    do{
        printf("\n1.Display\n2.Book\n3.Cancel\n4.Exit\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                for(i=0;i<10;i++){ printf("Row %d: ",i+1); display(rows[i]); }
                break;
            case 2:
                printf("Enter row and seat no (e.g. 5 3): ");
                if(scanf("%d %d",&row,&no)==2)
                    book(rows[row-1],no);
                else { printf("Invalid input.\n"); while(getchar()!='\n'); }
                break;
            case 3:
                printf("Enter row and seat no (e.g. 5 3): ");
                if(scanf("%d %d",&row,&no)==2)
                    cancel(rows[row-1],no);
                else { printf("Invalid input.\n"); while(getchar()!='\n'); }
                break;
        }
    }while(ch!=4);
    return 0;
}

