/* Doubly Linked List */
#include <stdio.h>
#include <conio.h>
#include <alloc.h>
struct dnode
{
    int data;
    struct dnode *next;
    struct dnode *prev;
};

// MENU Options
void menu()
{
    printf("\n\t********MAIN MENU*******\n");
    printf("\n\t1.Create Linked-List");
    printf("\n\t2.Display Linked-List");
    printf("\n\t3.Add a dnode in begining");
    printf("\n\t4.Add a dnode in between");
    printf("\n\t5.Add a dnode at end");
    printf("\n\t6.Delete an element from list");
    printf("\n\t7.Count number of elements in list");
    printf("\n\t8.Search an element in the list");
    printf("\n\t9.Sort the list");
    printf("\n\t10.Exit");
}

// MENU Boundary
void boundary()
{
    int i;
    printf("\n\n   ");
    for(i=0;i<16; i++)
        printf("==");
    gotoxy(10,3);
    menu();
    printf("\n    ");
    for(i=0;i<16; i++)
        printf("==");
    getch();
}

// Creating List
void create(struct dnode **q, int ele)
{
    struct dnode *old;
    if(*q==NULL)
    {
        *q=(struct dnode*)malloc(sizeof(struct dnode));
        (*q)->data=ele;
        (*q)->next=NULL;
        (*q)->prev=NULL;
    }
    else
    {
        while((*q)->next!=NULL)
            *q=(*q)->next;
        (*q)->next=(struct dnode *)malloc(sizeof(struct dnode));
        (*q)->next->data=ele;
        (*q)->next->next=NULL;
        (*q)->next->prev=*q;
    }
}

// Displaying List
void display(struct dnode *q)
{
    while(q!=NULL)
    {
        printf("%2d",q->data);
        q=q->next;
    }
}

// Counting Elements in List
int count(struct dnode *q)
{
    int count=0;
    while(q!=NULL)
    {
        count++;
        q=q->next;
    }
    return(count);
}

// Adding Elements in Begining
void add_beg(struct dnode **q, int ele)
{
    struct dnode *temp;
    temp=(struct dnode*)malloc(sizeof(struct dnode));
    temp->data=ele;
    temp->next=*q;
    temp->prev=NULL;
    (*q)->prev=temp;
    (*q)=temp;
}

// Adding Element in Between
void add_bet(struct dnode *q, int ele)
{
    struct dnode *temp;
    int pos,i;
    printf("\nEnter position to add in between: ");
    scanf("%d",&pos);
    for(i=0; i<pos-1; i++)
        q=q->next;
    temp=(struct dnode*)malloc(sizeof(struct dnode));
    temp->data=ele;
    temp->next=q->next;
    temp->prev=q;
    q->next->prev=temp;
q->next=temp;
}

// Adding Element in Between
void add_end(struct dnode *q, int ele)
{
    while(q->next!=NULL)
        q=q->next;
    q->next=(struct dnode*)malloc(sizeof(struct dnode));
    q->next->data=ele;
    q->next->next=NULL;
    q->next->prev=q;
}

// Deleting Element from the List
int del(struct dnode **q, int pos)
{
    struct dnode *temp=*q,*old;
    int count=1;
    while(temp!=NULL)
    {
        if(count==pos)
        {
            if(*q==temp)
            {
                (*q)->next->prev=NULL;
                *q=(*q)->next;
            }
            else if(temp->next==NULL)
                old->next=temp->next;
            else
            {
                old->next=temp->next;
                temp->next->prev=old;
            }
            free(temp);
            return(count);
        }
        count++;
        old=temp;
        temp=temp->next;
    }
    return(0);
}

// Searching Element in the List
int search(struct dnode *q, int ele)
{
    int c=0;
    while(q->next!=NULL)
    {
        if(q->data==ele)
            return(c);
        else
        {
            q=q->next;
            c++;
        }
    }
}

// Sorting the List
void sort(struct dnode *q)
{
    int temp;
    while(q!=NULL||q->next!=NULL)
    {
        if(q->data>q->next->data)
        {
            temp=q->data;
            q->data=q->next->data;
            q->next->data=temp;
        }
        else
            q=q->next;
    }
}

// Main Function
void main()
{
    struct dnode *head=NULL;
    int i,ele,num,n,pos,choice,s,temp1;
    do
    {
        clrscr();
        boundary();
        printf("\n\n\tCHOICE: ");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("\nEnter number of dnodes: ");
            scanf("%d",&num);
            for(i=1; i<=num; i++)
            {
                printf("\nEnter %d value to insert: ",i);
                scanf("%d",&ele);
                create(&head,ele);
            }
        }
        else if(choice==2)
        {
            if(head!=NULL)
                display(head);
            else
                printf("\nCreate Linked-List first.");
        }
        else if(choice==3)
        {
            if(head!=NULL)
            {
                printf("\nEnter number of dnodes to add in begining: ");
                scanf("%d",&n);
                for(i=1; i<=n; i++)
                {
                    printf("\nEnter %d value to insert: ",i);
                    scanf("%d",&ele);
                    add_beg(&head,ele);
                }
            }
            else
                printf("Create linked-list first.");
        }
        else if(choice==4)
        {
            if(head!=NULL)
            {
                printf("\nEnter number of nodes to add in between: ");
                scanf("%d",&n);
                for(i=1; i<=n; i++)
                {
                    printf("\nEnter %d value to insert: ",i);
                    scanf("%d",&ele);
                    add_bet(head,ele);
                }
            }
            else
                printf("Create linked-list first.");
        }
        else if(choice==5)
        {
            if(head!=NULL)
            {
                printf("\nEnter number of nodes to add in end: ");
                scanf("%d",&n);
                for(i=1; i<=n; i++)
                {
                    printf("\nEnter %d value to insert: ",i);
                    scanf("%d",&ele);
                    add_end(head,ele);
                }
            }
            else
                printf("Create linked-list first.");
        }
        else if(choice==6)
        {
            if(head!=NULL)
            {
                printf("\nHow many elements you want to delete? ");
                scanf("%d",&n);
                for(i=1; i<=n; i++)
                {
                    printf("\nEnter position: ");
                    scanf("%d",&pos);
                    del(&head,ele);
                }
            }
            else
                printf("Create linked-list first.");
        }
        else if(choice==7)
            printf("\nNumber of elements in SLL: %3d",count(head));
        else if(choice==8)
        {
            printf("\nEnter the number you want to find? ");
            scanf("%d",&s);
            if(head!=NULL)
            {
                temp1=search(head,s);
                printf("Number is found at %d position.",temp1);
            }
            else
                printf("\nCreate linked list first.");
        }
        else if(choice==9)
        {
            if(head!=NULL)
            {
                sort(head);
                printf("\nList has been sorted, go to display to see the result.");
            }
            else
                printf("\nCreate linked-list first.");
        }
        else if(choice==10)
            exit(0);
        else
            printf("\nPlease enter a valid choice.");
        getche();
    }while(choice!=8);
}
