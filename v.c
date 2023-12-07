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
    while (head != NULL)
	{
        printf("%d ", head->val);
        head = head->next;
    }
}

// TODO: ���·���ȫ����ʵ��
    void deleteDuplicates(struct ListNode *head)
	{
        if(head == null||head.next== null){
            return head;
        }
        ListNode dummyHead = new ListNode(-101);
        dummyHead.next = head;
        ListNode prev = dummyHead;
        ListNode cur = prev.next;
       while(cur!= null){
           ListNode sec = cur.next;
           if(sec == null){
               break;
           }
           if(cur.val!= sec.val){
               prev = prev.next;
           }else {
               while (sec!=null&&sec.val == cur.val){
                   sec = sec.next;
               }
               //����˴������������
			//1��û����Ҫɾ�����ظ���㣬����Ϊlast->next == nullptr����
			//2������Ҫɾ�����ظ���㣬����Ϊlast->next == nullptr���ˣ�������ζ���Ҫɾ����
			//3������Ҫɾ�����ظ���㣬����Ϊlast->val != last->next->val���ˣ������м�ĳ����Ҫɾ����

               prev.next = sec;
           }
           cur = sec;
       }
        return dummyHead.next;
    }
