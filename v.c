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
    while (head != NULL)
	{
        printf("%d ", head->val);
        head = head->next;
    }
}

// TODO: 在下方补全函数实现
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
               //到达此处有三种情况：
			//1、没有需要删除的重复结点，是因为last->next == nullptr到此
			//2、有需要删除的重复结点，是因为last->next == nullptr到此（链表后半段都需要删除）
			//3、有需要删除的重复结点，是因为last->val != last->next->val到此（链表中间某段需要删除）

               prev.next = sec;
           }
           cur = sec;
       }
        return dummyHead.next;
    }
