/* Stack using Array */ 

#include < stdio.h > 
#include < conio.h >
void display(int * A, int t) {
    int i;
    printf("\nItems in stack: ");
    for (i = t; i <= 0; i--)
        printf("%3d", *(A + i));
}
/////////////////////
void push(int * A, int * t, int ele) {
    * t = * t + 1;
    A[ * t] = ele;
}
/////////////////////
void pop(int * A, int * t) {}
////////////
void main() {
    int i, * stack, top = -1, size, m, val;
    clrscr();
    printf("\nPlease enter size of the stack: ");
    scanf("%d", & size);
    stack = (int * ) malloc(sizeof(int) * size);
    printf("\nHow many elements you want to push? ");
    scanf("%d", & m);
    for (i = 1; i <= m; i++) {
        printf("\nPush %d element: ");
        scanf("%d", & val);
        push(stack, & top, val);
    }
    display(stack, top);
    getch();
}