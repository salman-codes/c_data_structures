/* Stack using Linked List */ 

#include < stdio.h > 
#include < conio.h > 
#include < alloc.h >
struct stack {
    int data;
    struct stack * next;
};
/////////////////
void menu() {
    printf("\n\t********STACK MENU*******\n");
    printf("\n\t1.Push operation");
    printf("\n\t2.Display Stack items");
    printf("\n\t3.Pop operation");
    printf("\n\t4.Number of items in stack");
    printf("\n\t5.Exit");
}
//////////////////////
void boundary() {
    int i;
    printf("\n\n   ");
    for (i = 0; i < 16; i++)
        printf("==");
    gotoxy(10, 3);
    menu();
    printf("\n    ");
    for (i = 0; i < 16; i++)
        printf("==");
    getch();
}
//////////////////////
void push(struct stack ** s, int ele) {
    struct stack * temp;
    temp = (struct stack * ) malloc(sizeof(struct stack));
    temp - > data = ele;
    temp - > next = * s;
    ( * s) = temp;
}
/////////////////////
void display(struct stack * s) {
    while (s != NULL) {
        printf("%3d", s - > data);
        s = s - > next;
    }
}
//////////////////////
int count(struct stack * s) {
    int count = 0;
    while (s != NULL) {
        count++;
        s = s - > next;
    }
    return (count);
}
///////////////////
int pop(struct stack ** s) {
    struct stack * temp;
    int t;
    temp = * s;
    t = temp - > data;
    * s = temp - > next;
    free(temp);
    return (t);
}
////////////////////
void main() {
    struct stack * top = NULL;
    int i, ele, num, n, choice, temp;
    do {
        clrscr();
        boundary();
        printf("\n\n\tCHOICE: ");
        scanf("%d", & choice);
        if (choice == 1) {
            printf("\nEnter number of items in stack: ");
            scanf("%d", & num);
            for (i = 1; i <= num; i++) {
                printf("\nEnter %d value to insert: ", i);
                scanf("%d", & ele);
                push( & top, ele);
            }
        } else if (choice == 2) {
            if (top != NULL)
                display(top);
            else
                printf("\nStack is empty.");
        } else if (choice == 3) {
            if (top != NULL) {
                printf("\nHow many elements you want to pop? ");
                scanf("%d", & n);
                for (i = 1; i <= n; i++)
                    printf("\nItem popped: %d", pop( & top));
            } else
                printf("\nStack is empty.");
        } else if (choice == 4)
            printf("\nNumber of Items in Stack: %3d", count(top));
        else if (choice == 5)
            exit(0);
        else
            printf("\nPlease enter a valid choice.");
        getch();
    } while (choice != 5);
}