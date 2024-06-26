#include<stdlib.h>
#include<stdio.h>
// 结点类
struct ListNode {
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
    for (int i = 0; i < amount; i++) {
        struct ListNode *input = (struct ListNode *) malloc(sizeof(struct ListNode));
        scanf("%d", &(input->val));

        if (i == 0) {
            head = input;
            temp = head;
        } else {
            temp->next = input;
            temp = temp->next;
        }

        if (i == amount - 1)
            temp->next = NULL;
    }
  
    // 执行函数
    deleteDuplicates(head);

    // 输出
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}
// TODO: 在下方补全函数实现
void deleteDuplicates(struct ListNode* head)
{
    struct ListNode* p = head;
    while (p && p->next)
        if (p->val == p->next->val) p->next = p->next->next;
        else p = p->next;
    return ;
}
