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
  // TODO: ��д��������ĺ���
}
ListNode* sortList(struct ListNode* head)
{
  // TODO: ��д��������ĺ���
}
void output(ListNode* head)
{
  // TODO: ��д���ÿ���ڵ�ֵ�ĺ���
}
ListNode* insertNode(ListNode* head,int n)
{
  // TODO: ��д�������������ֵ�ĺ���
}
ListNode* removeNode(ListNode* head,int n)
{
  // TODO: ��дɾ��������ָ��ֵ�ĺ���
}