#include<stdlib.h>
#include<stdio.h>

// �����
struct ListNode
{
    int val;
    struct ListNode *next;
};

// ��Ҫʵ�ֵĺ���
void deleteDuplicates(struct ListNode *head);

int main()
{
    int amount;
    struct ListNode *head, *temp;
  
    // ��������
    scanf("%d", &amount);
    for (int i = 0; i < amount; i++)
    {
        struct ListNode *input = (struct ListNode *)malloc(sizeof(struct ListNode));
        scanf("%d", &(input->val));

        if (i == 0) 
        {
            head = input;
            temp = head;
        } 
        else
        {
            temp->next = input;
            temp = temp->next;
        }

        if (i == amount - 1)
            temp->next = NULL;
    }
  
    // ִ�к���
    deleteDuplicates(head);

    // ���
    while (head != NULL) 
    {
        printf("%d ", head->val);
        head = head->next;
    }
}

// TODO: ���·���ȫ����ʵ��
#define N 1000
void deleteDuplicates(struct ListNode *head)
{
    int A[N];
    for(int i=0;i<N;i++)
    {
        A[i]=-1;
    }
    struct ListNode *temp;
    temp=head;
    while(temp->next!=NULL)
    {
        int j=0;
        for(j=0;A[j]!=-1;j++)
        {
            if(temp->val==A[j])
            break;
        }
        if(A[j]!=-1)
        {
            temp->next=temp->next->next;
            tem
            break;
        }
        else
        {
        A[j]=(temp->val);
        temp=temp->next;
        }


    }
        
    
}