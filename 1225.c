struct ListNode *createList(int a[], int n)
{
	struct ListNode* head = NULL, *p = NULL;
	p = (struct ListNode*)malloc(sizeof(struct ListNode));
	head = p;
	for (int i = 0; i < n; i++)
	{
		p->val = a[i];
		if (i == n - 1)
		{
			p->next = NULL;
			break;
		}
		else
		{
			p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
			p = p->next;
		}
	}
	return head;
}

struct ListNode *sortList(struct ListNode *head)
{
	int a0;
	struct ListNode* p0 = NULL, * p1 = NULL, * p2 = NULL;
	p0 = head;
	p1 = head;
	while (p1 != NULL)
	{
		p2 = p1->next;
		while (p2 != NULL)
		{
			if (p1->val > p2->val)
			{
				a0 = p1->val;
				p1->val = p2->val;
				p2->val = a0;
			}
			p2 = p2->next;
		}
		p1 = p1->next;
	}
	return head;
}

void output(struct ListNode *head)
{
	struct ListNode* p=NULL;
	p = head;
	while (p != NULL)
	{
		printf("%d\n", p->val);
		p = p->next;
	}
}

struct ListNode *insertNode(struct ListNode *head, int n) 
{
	struct ListNode* p0=NULL, * p1=NULL;
	p0 = head;
	p1 = p0->next;
	if (n <= head->val)
	{
		struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
		temp->val = n;
		temp->next = head;
		head = temp;
	}
	else
	{
		while (p1 != NULL)
		{
			if (p1->val > n)
			{
				struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
				temp->val = n;
				temp->next = p1;
				p0->next = temp;
				break;
			}
			else
			{
				p0 = p1;
				p1 = p1->next;
			}
		}
		if (p0->next == NULL)
		{
			struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
			temp->val = n;
			temp->next = NULL;
			p0->next = temp;
		}
	}
	return head;
}

struct ListNode *removeNode(struct ListNode *head, int n)
{
	struct ListNode* p0=NULL, * p1=NULL;
	if (head->val > n)
	{
		return head;
	}
	else if (head->val == n)
	{
		p0 = head;
		head = head->next;
		free(p0);
		return head;
	}
	else
	{
		p0 = head;
		p1 = p0->next;
		while (p1 != NULL)
		{
			if (p1->val < n)
			{
				p0 = p1;
				p1 = p1->next;
			}
			else if (p1->val == n)
			{
				p0->next = p1->next;
				free(p1);
				break;
			}
			else
			{
				break;
			}
		}
	}
	return head;
}