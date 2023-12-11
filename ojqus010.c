#include "stdio.h"
#include "stdlib.h"

struct ListNode
{
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

ListNode* createList(int a[],int n)
{
  // TODO: 填写创建链表的函数
}
ListNode* sortList(struct ListNode* head)
{
  // TODO: 填写链表排序的函数
}
void output(ListNode* head)
{
  // TODO: 填写输出每个节点值的函数
}
ListNode* insertNode(ListNode* head,int n)
{
  // TODO: 填写向有序链表插入值的函数
}
ListNode* removeNode(ListNode* head,int n)
{
  // TODO: 填写删除链表中指定值的函数
}