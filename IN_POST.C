/* Infix to Postfix and Evolution */
#include<stdio.h>
#include<conio.h>
void push(char *stk,int *n,char ch)
{
 if(*n==99)
 printf("\nStack is full.");
 else
 {
  (*n)=(*n)+1;
  stk[*n]=ch;
 }
}
////////////////
char pop(char *stk,int *n)
{
 int item;
 if(*n==-1)
 {
  printf("\nStack is underflow.");
  return(-1);
 }
 else
 {
  item=stk[*n];
  *n=*n-1;
  return(item);
 }
}
//////////////////
int priority(char ele)
{
 int prio;
 if(ele=='*'||ele=='/'||ele=='%')
  prio=2;
 else
 {
  if(ele=='+'||ele=='-')
   prio=1;
  else
   prio=0;
 }
 return(prio);
}
//////////////////
int main()
{
 static char stack[100],postfix[100];
 char *t,*s,item,n1,n2,infix[100];
 int top=-1,i;
 printf("\nEnter infix string: ");
 scanf("%s",infix);
 s=infix;
 t=postfix;
 while(*s)
 {
  if(isdigit(*s)||isalpha(*s))
  {
   while(isdigit(*s)||isalpha(*s))
   {
    *t=*s;
    t++;
    s++;
   }
  }
  if(*s=='(')
  {
   push(stack,&top,*s);
   s++;
  }
  if(*s==')')
  {
   n1=pop(stack,&top);
   while(n1!='(')
   {
    *t=n1;
    t++;
    n1=pop(stack,&top);
   }
   s++;
  }
  if(*s=='+'||*s=='*'||*s=='/'||*s=='%')
  {
  if(top==-1)
   push(stack,&top,*s);
  else
  {
   n1=pop(stack,&top);
   while(priority(n1)>=priority(*s))
   {
    *t=n1;
    t++;
    n1=pop(stack,&top);
   }
   push(stack,&top,n1);
   push(stack,&top,*s);
  }
  s++;
 }
} // close-while.
while(top!='-1')
{
 n1=pop(stack,&top);
 *t=n1;
 t++;
}
*t='\0';
t=postfix;
printf("Postfix string: ");
while(*t)
 {
  printf("%c",*t);
  t++;
 }
 getch();
}