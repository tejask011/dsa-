#include <stdio.h>
#include <string.h>

int main() {
    int n = 0, dist[10][10] = {0}, i, j, d;
    char city[10][20], src[20], dest[20], ch;

    printf("***** Flight Main Menu *****\n");
    printf("1. Create\n2. Adjacency Matrix\n3. Exit\n");

    int choice;
    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                do {
                    printf("\nEnter Source City: ");
                    scanf("%s", src);
                    printf("Enter Destination City: ");
                    scanf("%s", dest);
                    printf("Enter Distance From %s to %s: ", src, dest);
                    scanf("%d", &d);

                    int s = -1, t = -1;
                    for(i=0;i<n;i++){
                        if(strcmp(city[i],src)==0) s=i;
                        if(strcmp(city[i],dest)==0) t=i;
                    }
                    if(s==-1) { strcpy(city[n],src); s=n++; }
                    if(t==-1) { strcpy(city[n],dest); t=n++; }

                    dist[s][t] = dist[t][s] = d;

                    printf("Do you want to add more cities? (y/n): ");
                    scanf(" %c", &ch);
                } while(ch=='y' || ch=='Y');
                break;

            case 2:
                printf("\nAdjacency Matrix (Distances):\n   ");
                for(i=0;i<n;i++) printf("%10s", city[i]);
                printf("\n");
                for(i=0;i<n;i++){
                    printf("%10s", city[i]);
                    for(j=0;j<n;j++)
                        printf("%10d", dist[i][j]);
                    printf("\n");
                }
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while(choice != 3);
    return 0;
}

