#include<stdio.h>
#include<stdlib.h>

typedef struct LinkNode
{
    int val;
    struct LinkNode *next;
    
}LinkNode;//创建数据类型。

LinkNode *Create_LinkNode(int val)
{
    LinkNode*head=(LinkNode*)malloc(sizeof(LinkNode));
    head->val=val;
    head->next=NULL;
    return head;
}

void Connect_LinkNode(LinkNode *node1,LinkNode *node2)
{
    node1->next=node2;
}

void Print_LinkNode(LinkNode*head)
{
    while(head)
    {
        printf("%d ",head->val);
        head=head->next;
    }
    printf("\n");
}

void Delete_Node(LinkNode*head)
{
    if(head==NULL||(head->next==NULL))
    return;
    LinkNode *pointer=head;
    while(pointer->next!=NULL)
    {
        LinkNode *s=pointer->next;
        while(s!=NULL)
        {
            if(pointer->val==s->val)
            {
                if(s->next!=NULL)
                {
                    s->val=s->next->val;
                    s->next=s->next->next;
                    free(s->next);
                }
                else
                {
                    LinkNode *node=pointer->next;
                    while(node->next!=s)
                    {
                        node=node->next;
                    }
                    node->next=NULL;
                    free(s);
                    s=NULL;
                }
            }
            else
            s=s->next;
            
        }
        pointer=pointer->next;
    }
}
int main(void)
{
    LinkNode *head1=Create_LinkNode(1);
    LinkNode *head2=Create_LinkNode(1);
    LinkNode *head3=Create_LinkNode(2);
    LinkNode *head4=Create_LinkNode(2);
    LinkNode *head5=Create_LinkNode(3);
    LinkNode *head6=Create_LinkNode(5);
    LinkNode *head7=Create_LinkNode(6);
    LinkNode *head8=Create_LinkNode(3);
    LinkNode *head9=Create_LinkNode(7);
    Connect_LinkNode(head1,head2);
    Connect_LinkNode(head2,head3);
    Connect_LinkNode(head3,head4);
    Connect_LinkNode(head4,head5);
    Connect_LinkNode(head5,head6);
    Connect_LinkNode(head6,head7);
    Connect_LinkNode(head7,head8);
    Connect_LinkNode(head8,head9);
    printf("创建链表如下：\n");
    Print_LinkNode(head1);
    Delete_Node(head1);
    printf("删除重复的数字后：\n");
    Print_LinkNode(head1);
}