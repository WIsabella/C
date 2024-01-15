#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node*next;
};
int main()
{
    int n;
    scanf("%d",&n);
    int N[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&N[n]);
    }
    struct node *p=(struct node *)malloc(sizeof(struct node));
    p->next=NULL;
    struct node *head=p;
    for(int i=0;i<n;i++,p++)
    {
        p->next=(struct node *)malloc(sizeof(struct node));
        p->val=N[i];
    }
    p=NULL;
    struct node *p0=head;
    while(p0!=NULL)
    {
        printf("%d ",p->val);
    }

}