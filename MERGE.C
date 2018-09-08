/* Merging of Two Linked List */ 
#include < stdio.h > 
#include < conio.h >
struct node {
    int data;
    struct node * next;
};
/////////////////
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
////////////////////
void display(struct node * q) {
    while (q != NULL) {
        printf("%3d", q - > data);
        q = q - > next;
    }
}
///////////////////
void merge(struct node * p, struct node * q, struct node ** r) {
    struct node * temp = p;
    while (temp - > next != NULL)
        temp = temp - > next;
    temp - > next = q;
    * r = p;
}
////////////////////
void main() {
    struct node * head1 = NULL, * head2 = NULL, * head = NULL;
    int i, ele, num;
    clrscr();
    printf("\n\nEnter number of nodes in 1st SLL:");
    scanf("%d", & num);
    for (i = 1; i <= num; i++) {
        printf("Enter %d value to insert: ", i);
        scanf("%d", & ele);
        create( & head1, ele);
    }
    printf("\n\nEnter number of nodes in 2nd SLL:");
    scanf("%d", & num);
    for (i = 1; i <= num; i++) {
        printf("Enter %d value to insert: ", i);
        scanf("%d", & ele);
        create( & head2, ele);
    }
    printf("\n1st Linked-List: ");
    display(head1);
    printf("\n2nd Linked-List: ");
    display(head2);
    merge(head1, head2, & head);
    printf("\n\nMerged linked-list: ");
    display(head);
    getch();
}
/////////////////