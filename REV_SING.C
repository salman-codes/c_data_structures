/* Reverse of Linked List */ 
#include < stdio.h > 
#include < conio.h >
struct node {
    int data;
    struct node * next;
};
//////////////////
void create(struct node ** q, int ele) {
    struct node * temp = * q, * old;
    if ( * q == NULL) {
        * q = (struct node * ) malloc(sizeof(struct node));
        ( * q) - > data = ele;
        ( * q) - > next = NULL;
    } else {
        while (temp - > next != NULL)
            temp = temp - > next;
        old = (struct node * ) malloc(sizeof(struct node));
        old - > data = ele;
        old - > next = NULL;
        temp - > next = old;
    }
}
/////////////////////////
void display(struct node * q) {
    while (q != NULL) {
        printf("%3d", q - > data);
        q = q - > next;
    }
}
//////////////////
void reverse(struct node ** r) {
    struct node * x, * y, * z;
    x = * r;
    y = NULL;
    while (x != NULL) {
        z = y;
        y = x;
        x = x - > next;
        y - > next = z;
    }
    * r = y;
}
////////////////////
void main() {
    struct node * head = NULL;
    int i, ele, num;
    clrscr();
    printf("\n\nEnter number of nodes: ");
    scanf("%d", & num);
    for (i = 1; i <= num; i++) {
        printf("Enter %d value to insert: ", i);
        scanf("%d", & ele);
        create( & head, ele);
    }
    printf("\nLinked-List: ");
    display(head);
    reverse( & head);
    printf("\n\nReversed linked-list: ");
    display(head);
    getch();
}