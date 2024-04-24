#include "stdio.h"
#include "stdlib.h"

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *createList(int a[], int n);

struct ListNode *sortList(struct ListNode *head);

void output(struct ListNode *head);

struct ListNode *insertNode(struct ListNode *head, int n);

struct ListNode *removeNode(struct ListNode *head, int n);

int main() {
    int a[10000];
    int n, ins, rm;
    scanf("%d", &n);
    scanf("%d", &ins);
    scanf("%d", &rm);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    struct ListNode *list = createList(a, n);
    output(list);
    list = sortList(list);
    output(list);
    list = insertNode(list, ins);
    output(list);
    list = removeNode(list, rm);
    output(list);
    return 0;
}
struct ListNode *createList(int a[], int n)
{     
	struct ListNode *head = NULL;
    struct ListNode *NewNode = NULL;
   NewNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    head=NewNode;
    for (int i = 0; i < n; i++)
    {   
        NewNode->val = a[i];
        if(i=n-1)//i==n-1
        {
        	NewNode->next=NULL;
		}
        else
		{NewNode->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        NewNode=NewNode->next; 
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
			
			if(p2->val>p1->val)//方向判断反了！！！！
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
	while(p!=head)
	{printf("%d",p->val);
	  p=p->next;
	}
}
struct ListNode *insertNode(struct ListNode *head, int n)
{
	struct ListNode *prev=head,*pnext=head;
	struct ListNode *NextNode=(struct ListNode *)malloc(sizeof(struct ListNode));
	NextNode->val=n;
	NextNode->next=NULL;
	if(head==NULL)
	{head=NextNode;
	  return head; 
	 } 
	while((pnext!=NULL)&&(pnext->val<n))
	{prev=pnext;
	 pnext=pnext->next;
	}
	if(pnext==head)
	{
		NextNode->next=pnext;
		head=NextNode;
	}
	else
	{prev->next=NextNode;
	NextNode->next=pnext;
	}

}
struct ListNode *removeNode(struct ListNode *head, int n)
{
	
	struct ListNode *prev=head, *pnext=head;	  
    if (head==NULL)  
	return head;    //empty list    
    while (pnext!=NULL && pnext->val!= n)   
    {   prev=pnext;          //prev指向要删除结点的前一个结点
        pnext=pnext->next;     //p指向要删除的结点
    }
    if (pnext==NULL)    
	return head;  //没有找到
    else if (pnext==head)   //删除第一个结点
    {	head = pnext->next;
	free(pnext);	
     } 
     else  
     {	  prev->next=pnext->next;
         free(pnext);
     }     
    return head;

}
