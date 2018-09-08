/* Binary Search Tree */
#include <stdio.h>
#include <conio.h>
struct bst
{
    int data;
    struct bst *lchild;
    struct bst *rchild;
};

// Creating BST
void create_bst(struct bst **r,int val)
{
    if(*r==NULL)
    {
        *r=(struct bst*)malloc(sizeof(struct bst));
        (*r)->data=val;
        (*r)->lchild=NULL;
        (*r)->rchild=NULL;
    }
    else
    {
        if((*r)->data<val)
            create_bst(&((*r)->lchild),val);
        else if((*r)->data>val)
            create_bst(&((*r)->rchild),val);
        else
            printf("\nDuplicate value..");
    }
}

// IN-ORDER
void in_order(struct bst *r)
{
    if(r!=NULL)
    {
        in_order(r->rchild);
        printf("%d ",r->data);
        in_order(r->lchild);
    }
}

// PRE-ORDER
void pre_order(struct bst *r)
{
    if(r!=NULL)
    {
        printf("%d ",r->data);
        pre_order(r->rchild);
        pre_order(r->lchild);
    }
}

// POST-ORDER
void post_order(struct bst *r)
{
    if(r!=NULL)
    {
        post_order(r->rchild);
        post_order(r->lchild);
        printf("%d ",r->data);
    }
}
// MAIN Function
void main()
{
    struct bst *root=NULL;
    int i,n,ele;
    printf("\nEnter number of nodes in bst: ");
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        printf("\nEnter %d element: ",i);
        scanf("%d",&ele);
        create_bst(&root,ele);
    }
    printf("\nIn-order traversal: ");
    in_order(root);
    printf("\nPre-order traversal: ");
    pre_order(root);
    printf("\nPost-order traversal: ");
    post_order(root);
    getch();
}