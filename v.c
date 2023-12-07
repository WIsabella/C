#include<stdlib.h>
#include<stdio.h>

// �����
struct ListNode {
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
  
    // ִ�к���
    deleteDuplicates(head);

    // ���
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}

// TODO: ���·���ȫ����ʵ��
void deleteDuplicates(struct ListNode* head)
{
	if (head == NULL ||(head->next == NULL))
		return;
	
	struct ListNode* pointer = head;

	while (pointer->next != NULL)
	{
		struct ListNode* s = pointer->next;

		while (s != NULL)
		{
			if (pointer->val == s->val)
			{
				if (s->next != NULL)
				{
					s->val = s->next->val;
					s->next = s->next->next;
					free(s->next);
				}
				else
				{
					struct ListNode *node = pointer->next;
					while (node->next != s)
						node = node->next;
					node->next = NULL;
					free(s);
					s = NULL;
					//free(s);
				}
			}
			else 
				s = s->next;
		}
		pointer = pointer->next;
	}
	
}