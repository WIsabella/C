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
typedef struct ListNode ListNode;
ListNode* createList(int a[],int n)
{
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next = NULL;
    struct ListNode* p ;
    p = head;
    for (int i = 0; i < n; i++)
    {
        struct ListNode* s = (struct ListNode*)malloc(sizeof(struct ListNode));
        s->val=a[i];
        p->next =s;
        s->next =NULL;
        p=s;
    }
}
ListNode* sortList(struct ListNode* head)
{
  // TODO: 填写链表排序的函数
}
void output(ListNode* head)
{
    struct ListNode* p=head;//让p指针从"头"开始。
	while (p->next != NULL)//如果p的下一个结点不为NULL，也就是说如果p结点后还有节点存在，那就输出p后面结点中保存的数据。
	{
		printf("%d\n", p->next->val);
		p = p->next;//p结点后移
	}
}
ListNode* insertNode(ListNode* head,int n)
{
  // TODO: 填写向有序链表插入值的函数
}
ListNode* removeNode(ListNode* head,int n)
{
  // TODO: 填写删除链表中指定值的函数
}