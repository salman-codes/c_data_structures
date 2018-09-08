/* Singly Linked List */ 
#include < stdio.h > 
#include < conio.h > 
#include < alloc.h >
struct cnode {
    int data;
    struct cnode * next;
};
/////////////////
void menu() {
    printf("\n\t********MAIN MENU*******\n");
    printf("\n\t1.Create Linked-List");
    printf("\n\t2.Display Linked-List");
    printf("\n\t3.Add a cnode in begining");
    printf("\n\t4.Add a cnode in between");
    printf("\n\t5.Add a cnode at end");
    printf("\n\t6.Delete an element from list");
    printf("\n\t7.Update an element in the list");
    printf("\n\t8.Count number of elements in list");
    printf("\n\t9.Search an element in the list");
    printf("\n\t10.Sort the list");
    printf("\n\t11.Exit");
}
//////////////////
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
//////////////////
void create(struct cnode ** q, int ele) {
    struct cnode * temp = * q, * old;
    if ( * q == NULL) {
        * q = (struct cnode * ) malloc(sizeof(struct cnode));
        ( * q) - > data = ele;
        ( * q) - > next = * q;
    } else {
        while (temp - > next != * q)
            temp = temp - > next;
        old = (struct cnode * ) malloc(sizeof(struct cnode));
        old - > data = ele;
        old - > next = * q;
        temp - > next = old;
    }
}
///////////////////
void display(struct cnode * q) {
    struct cnode * temp = q;
    do {
        printf("%3d", q - > data);
        q = q - > next;
    } while (q != temp);
}
///////////////////
int count(struct cnode * q) {
    struct cnode * temp = q;
    int count = 0;
    do {
        count++;
        q = q - > next;
    } while (q != temp);
    return (count);
}
/////////////////
void add_beg(struct cnode ** q, int ele) {
    struct cnode * temp, * old = * q, * s;
    do {
        s = old;
        old = old - > next;
    } while (old != * q);
    temp = (struct cnode * ) malloc(sizeof(struct cnode));
    temp - > data = ele;
    temp - > next = * q;
    s - > next = temp;
    ( * q) = temp;
}
//////////////////
void add_bet(struct cnode * q, int ele) {
    struct cnode * temp, * old;
    int pos, i;
    printf("\nEnter position to add in between: ");
    scanf("%d", & pos);
    for (i = 1; i < pos; i++) {
        old = q;
        q = q - > next;
    }
    temp = (struct cnode * ) malloc(sizeof(struct cnode));
    temp - > data = ele;
    temp - > next = q;
    old - > next = temp;
}
/////////////////
void add_end(struct cnode * q, int ele) {
    struct cnode * temp = q, * old;
    do {
        old = q;
        q = q - > next;
    } while (q != temp);
    old - > next = (struct cnode * ) malloc(sizeof(struct cnode));
    old - > next - > data = ele;
    old - > next - > next = q;
}
///////////////////
void update(struct cnode * q, int pos, int ele) {
    int i;
    while (q != NULL || q - > next != NULL) {
        for (i = 1; i < pos; i++)
            q = q - > next;
        q - > next - > data = ele;
    }
}
///////////////////
int del(struct cnode ** q, int pos) {
    struct cnode * temp = * q, * old;
    int count = 1;
    while (temp != NULL) {
        if (temp - > data == pos) {
            if ( * q == temp)
                *
                q = temp - > next;
            else if (temp - > next == NULL)
                old - > next = temp - > next;
            else
                old - > next = temp - > next;
            free(temp);
            return (count);
        }
        count++;
        old = temp;
        temp = temp - > next;
    }
    return (0);
}
////////////////
int search(struct cnode * q, int ele) {
    int c = 0;
    while (q - > next != NULL) {
        if (q - > data == ele)
            return (c);
        else {
            q = q - > next;
            c++;
        }
    }
}
/////////////////
void sort(struct cnode * q) {
    int temp;
    while (q != NULL) {
        if (q - > data > q - > next - > data) {
            temp = q - > data;
            q - > data = q - > next - > data;
            q - > next - > data = temp;
        } else
            q = q - > next;
    }
}
//////////////
void main() {
    struct cnode * head = NULL;
    int i, ele, num, n, pos, choice, s, temp1;
    do {
        clrscr();
        boundary();
        printf("\n\n\tCHOICE: ");
        scanf("%d", & choice);
        if (choice == 1) {
            printf("\nEnter number of cnodes: ");
            scanf("%d", & num);
            for (i = 1; i <= num; i++) {
                printf("\nEnter %d value to insert: ", i);
                scanf("%d", & ele);
                create( & head, ele);
            }
        } else if (choice == 2) {
            if (head != NULL)
                display(head);
            else
                printf("\nCreate Linked-List first.");
        } else if (choice == 3) {
            if (head != NULL) {
                printf("\nEnter number of cnodes to add in begining: ");
                scanf("%d", & n);
                for (i = 1; i <= n; i++) {
                    printf("\nEnter %d value to insert: ", i);
                    scanf("%d", & ele);
                    add_beg( & head, ele);
                }
            } else
                printf("Create linked-list first.");
        } else if (choice == 4) {
            if (head != NULL) {
                printf("\nEnter number of cnodes to add in between: ");
                scanf("%d", & n);
                for (i = 1; i <= n; i++) {
                    printf("\nEnter %d value to insert: ", i);
                    scanf("%d", & ele);
                    add_bet(head, ele);
                }
            } else
                printf("Create linked-list first.");
        } else if (choice == 5) {
            if (head != NULL) {
                printf("\nEnter number of cnodes to add in end: ");
                scanf("%d", & n);
                for (i = 1; i <= n; i++) {
                    printf("\nEnter %d value to insert: ", i);
                    scanf("%d", & ele);
                    add_end(head, ele);
                }
            } else
                printf("Create linked-list first.");
        } else if (choice == 6) {
            if (head != NULL) {
                printf("\nHow many elements you want to delete? ");
                scanf("%d", & n);
                for (i = 1; i <= n; i++) {
                    printf("\nEnter position: ");
                    scanf("%d", & pos);
                    del( & head, ele);
                }
            } else
                printf("Create linked-list first.");
        } else if (choice == 7) {
            printf("\nEnter position: ");
            scanf("%d", & pos);
            printf("\nEnter the new element: ");
            scanf("%d", & ele);
            if (head != NULL) {
                update(head, pos, ele);
                printf("\nList has been updated, go to display to see the result.");
            } else
                printf("\nCreate linked-list first.");
        } else if (choice == 8)
            printf("\nNumber of elements in SLL: %3d", count(head));
        else if (choice == 9) {
            printf("\nEnter the number you want to find? ");
            scanf("%d", & s);
            if (head != NULL) {
                temp1 = search(head, s);
                printf("Number is found at %d position.", temp1);
            } else
                printf("\nCreate linked list first.");
        } else if (choice == 10) {
            if (head != NULL) {
                sort(head);
                printf("\nList has been sorted, go to display to see the result.");
            } else
                printf("\nCreate linked-list first.");
        } else if (choice == 11)
            exit(0);
        else
            printf("\nPlease enter a valid choice.");
        getche();
    } while (choice != 8);
}