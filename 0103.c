#include<stdio.h>
#include<stdlib.h>
struct ListNode
{
    int val;
    struct ListNode* next;
};
struct ListNode *createList(int a[],int n);
struct ListNode *sortList(struct ListNode *head);
void output(struct ListNode *head);
struct ListNode *insertNode(struct ListNode *head,int n);
struct ListNode *removeNode(struct ListNode *head,int n);

int main()
{
    int a[10000];
    int n,ins,rm;
    scanf("%d%d%d",&n,&ins,&rm);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    struct ListNode *list =createList(a,n);
    output(list);
    list =sortList(list);
    output(list);
    list =insertNode(list,ins);
    output(list);
    list =removeNode(list,rm);
    output(list);
    return 0;
}

struct ListNode *createList(int a[],int n)
{
    struct ListNode *head,*p;
    p=(struct ListNode*)malloc(sizeof(struct ListNode));
    head=p;
    for(int i=0;i<n;i++)
    {
        p->val=a[i];
        if(i==n-1)
        p->next=NULL;
        else
        {
        p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
        p=p->next;
        }
    }
    return head;
}

struct ListNode *sortList(struct ListNode *head)
{
    struct ListNode *p1=NULL,*p2=NULL;
    p1=head;
    while(p1!=NULL)
    {
        p2=p1->next;
        while(p2!=NULL)
        {
            if(p1->val>p2->val)
          {
            int t=p1->val;
            p1->val=p2->val;
            p2->val=t;
          }
          p2=p2->next;
        }
        p1=p1->next;
    }
    return head;
}

void output(struct ListNode *head)
{
    struct ListNode *p=NULL;
    p=head;
    while(p!=NULL)
    {
        printf("%d\n",p->val);
        p=p->next;
    }
}

struct ListNode *insertNode(struct ListNode *head,int n)
{
    struct ListNode *p=NULL,*p0=NULL,*p1=NULL;
    if(n<head->val)
    {
        p=(struct ListNode *)malloc(sizeof(struct ListNode));
        p->val=n;
        p->next=head;
        head=p;
    }
    else
    {
        p=head;
        p1=p->next;
            while(p!=NULL)
        {
            
            if(n>p->val&&n<p1->val)
            {
                p0=(struct ListNode*)malloc(sizeof(struct ListNode));
                p0->val=n;
                p->next=p0;
                p0->next=p1;
                break;
            }
            else
            {
                p=p->next;
                p1=p->next;
            }
            
        }
        if(p1==NULL)
        {
            p0=(struct ListNode*)malloc(sizeof(struct ListNode));
            p0->val=n;
            p->next=p0;
            p0->next=NULL;
        }
    }
    return head;
    
}

struct ListNode *removeNode(struct ListNode *head,int n)
{
    struct ListNode *p1=NULL,*p2=NULL;
    if(head->val>n)
    {
        return head;
    }
    else if(head->val==n)
    {
        p1=head;
        head=head->next;
        free(p1);
        return head;
    }
    else
    {
        p1=head;
        p2=p1->next;
        while(p2!=NULL)
        {
            if(p2->val<n)
            {
                p1=p2;
                p2=p1->next;
            }
            else if(p2->val==n)
            {
                p1->next=p2->next;
                free(p2);
                break;
            }
            else break;
        }
    }
    return head;
}