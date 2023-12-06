#include<stdlib.h>
#include<stdio.h>

// 结点类
struct ListNode
{
    int val;
    struct ListNode *next;
};

// 需要实现的函数
void deleteDuplicates(struct ListNode *head);

int main()
{
    int amount;
    struct ListNode *head, *temp;
  
    // 读入数据
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
  
    // 执行函数
    deleteDuplicates(head);

    // 输出
    while (head != NULL) 
    {
        printf("%d ", head->val);
        head = head->next;
    }
}

// TODO: 在下方补全函数实现
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