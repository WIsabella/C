#include<stdio.h>

struct Node
{
    int val;
    struct Node* next;
};
int main()
{
    int n;
    scanf("%d",&n);
    struct Node *p= NULL;
    struct Node *p0=NULL;
    struct Node *head=p;
    for(int i=0;i<n;i++)
    {
        p=(struct Node*)malloc(sizeof(struct Node));
        scanf("%d",&p->val);
        p0->next=NULL;

    }

    
}