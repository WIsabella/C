#include<stdio.h>
#include<stdlib.h>

int main()
{
    struct LinkNode
    {
        int val;
        struct LinkNode *next;
    };//注意这里必须加一个分号，因为原来要创建的。
    struct LinkNode node1={10,NULL};
    struct LinkNode node2={20,NULL};
    struct LinkNode node3={30,NULL};
    struct LinkNode node4={40,NULL};
    struct LinkNode node5={50,NULL};
    node1.next=&node2;
    node2.next=&node3;
    node3.next=&node4;
    node4.next=&node5;
    node5.next=NULL;
    struct LinkNode *pCurrent=&node1;
    while(pCurrent!=NULL)
    {
        printf("%d ",pCurrent->val);
        pCurrent=pCurrent->next;
    }



}