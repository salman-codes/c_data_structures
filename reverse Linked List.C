/* Reversing Linked List */
#include<stdio.h>
#include<conio.h>
#include<alloc.h>
int stk[20],t=-1;
struct cnode
{
 int data;
 struct cnode *next;
};
////////////////////
void menu()
{
 printf("\n\t********MAIN MENU*******\n");
 printf("\n\t1.Create Linked-List");
 printf("\n\t2.Display Linked-List");
 printf("\n\t3.Exit");
}
///////////////////
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
/////////////////
void create(struct cnode **q, int ele)
{
 struct cnode *temp=*q,*old;
 if(*q==NULL)
 {
  *q=(struct cnode*)malloc(sizeof(struct cnode));
  (*q)->data=ele;
  (*q)->next=*q;
 }
 else
 {
  while(temp->next!=*q)
  temp=temp->next;
  old=(struct cnode *)malloc(sizeof(struct cnode));
  old->data=ele;
  old->next=*q;
  temp->next=old;
 }
}
///////////////////
void display(struct cnode *q)
{
 struct cnode *temp=q;
 int r;
 do
 {
  printf("%3d",q->data);
  r=(q->data);
  push(stk,r,&t);
  q=q->next;
 }while(q!=temp);
}
////////////////////
int push(int *stk,int ele,int *t)
{
 if(*t==20)
 printf("\nStack overflow.");
 else
 {
  (*t)++;
  stk[*t]=ele;
 }
}
///////////////////
int pop(int *stk,int *t)
{
 int temp;
 if(*t==-1)
 return(-1);
 else
 {
  temp=stk[*t];
  (*t)--;
 }
 return(temp);
}
///////////////////
void main()
{
 struct cnode *head=NULL;
 int i,ele,num,n,pos,choice,s,temp1;
 int temp;
 do
 {
  clrscr();
  boundary();
  printf("\n\n\tCHOICE: ");
  scanf("%d",&choice);
  if(choice==1)
  {
   printf("\nEnter number of cnodes: ");
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
   {
    printf("\nLinked-List: ");
    display(head);
    printf("\nReversed Linked-List: ");
    while((t)!=-1)
    {
     temp=pop(stk,&t);
     printf("%d ",temp);
    }
   }
   else
   printf("\nCreate Linked-List first.");
  }
  else if(choice==3)
   exit(0);
  else
   printf("\nPlease enter a valid choice.");
  getche();
 }while(choice!=8);
}