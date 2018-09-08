/* Queue using Linked List */ 

#include < stdio.h > 
#include < conio.h > 
#include < alloc.h >

struct queue {
    int data;
    struct queue * next;
};
//////////////////
void menu() {
    printf("\n\t********QUEUE MENU*******\n");
    printf("\n\t1.Insert operation");
    printf("\n\t2.Display Queue items");
    printf("\n\t3.Delete operation");
    printf("\n\t4.Number of items in queue");
    printf("\n\t5.Exit");
}
//////////////////
void boundary() {
    int i;
    printf("\n\n   ");
    for (i = 0; i < 16; i++)
        printf("==");
    gotoxy(10, 3);
    printf("\n    ");
    for (i = 0; i < 16; i++)
        printf("==");
    getch();
}
///////////////////
void inque(struct queue ** f, struct queue ** r, int ele) {
    struct queue * q;
    q = (struct queue * ) malloc(sizeof(struct queue));
    q - > data = ele;
    q - > next = NULL;
    if ( * f == NULL)
        *
        f = q;
    else
        ( * r) - > next = q;
    * r = q;
}
////////////////////
void display(struct queue * f) {
    while (f != NULL) {
        printf("%3d", f - > data);
        f = f - > next;
    }
}
///////////////////
int count(struct queue * f) {
    int count = 0;
    while (f != NULL) {
        count++;
        f = f - > next;
    }
    return (count);
}
///////////////
int delque(struct queue ** f, struct queue ** r) {
    struct queue * temp;
    int t;
    temp = * f;
    t = temp - > data;
    * f = temp - > next;
    free(temp);
    if ( * f == NULL)
        *
        r = NULL;
    return (t);
}
////////////////
void main() {
    struct queue * front = NULL, * rear = NULL;
    int i, ele, num, n, choice, temp;
    do {
        clrscr();
        menu();
        printf("\n\n\tCHOICE: ");
        scanf("%d", & choice);
        if (choice == 1) {
            printf("\nEnter number of items in queue: ");
            scanf("%d", & num);
            for (i = 1; i <= num; i++) {
                printf("\nEnter %d value to insert: ", i);
                scanf("%d", & ele);
                inque( & front, & rear, ele);
            }
        } else if (choice == 2) {
            if (front != NULL && rear != NULL)
                display(front);
            else
                printf("\nQueue is NULL.");
        } else if (choice == 3) {
            if (rear != NULL) {
                printf("\nHow many items you want to delete? ");
                scanf("%d", & n);
                for (i = 1; i <= n; i++)
                    printf("\nItem deleted: %d", delque( & front, & rear));
            } else
                printf("\nQueue is NULL.");
        } else if (choice == 4)
            printf("\nNumber of Items in Queue: %3d", count(front));
        else if (choice == 5)
            exit(0);
        else
            printf("\nPlease enter a valid choice.");
        getch();
    } while (choice != 5);
}