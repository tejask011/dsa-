#include <stdio.h>

int main() {
    int M;
    printf("Enter maximum number of orders (M): ");
    scanf("%d", &M);
    int q[M], front = -1, rear = -1;
    int ch, job;

    void addJob(int job) {
        if(rear == M-1) printf("Queue full! Cannot add more orders.\n");
        else {
            if(front == -1) front = 0;
            q[++rear] = job;
            printf("Order %d added.\n", job);
        }
    }

    void deleteJob() {
        if(front == -1 || front > rear) printf("No orders to serve.\n");
        else printf("Order %d served.\n", q[front++]);
    }

    void display() {
        if(front == -1 || front > rear) printf("No pending orders.\n");
        else {
            printf("Pending orders: ");
            int i;
            for(i = front; i <= rear; i++) printf("%d ", q[i]);
            printf("\n");
        }
    }

    do {
        printf("\n1.Add Order\n2.Serve Order\n3.Display Orders\n4.Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: 
                printf("Enter order number: ");
                scanf("%d", &job);
                addJob(job);
                break;
            case 2: 
                deleteJob();
                break;
            case 3: 
                display();
                break;
            case 4: 
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(ch != 4);

    return 0;
}

