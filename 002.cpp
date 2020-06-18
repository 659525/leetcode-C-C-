/*2. 两数相加
//关键词：单链表
//author：659525
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/
//思路1：创建一个结点，每次相加结果保存在结点中，最后处理一下最高位进位的问题
//思路2：先直接将俩条数组相加，然后最后统一处理进位问题

#include <stdio.h>
#include <windows.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode {
	int val;
	struct ListNode *next;
};

//C++版，采用思路1：创建一个结点，每次相加结果保存在结点中，最后处理一下最高位进位的问题
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* res, *temp;
		res = new ListNode();
		res->next = NULL;
		res->val = 0;
		temp = res;
		int carry = 0;	//进位标识
		//边进位边处理，俩个指针都不为空时停下
		while (!(l1 == NULL && l2== NULL))
		{
			ListNode* node = new ListNode;
			if (l1 == NULL) {
				//如果l1已经跑完,只算l2部分
				node->val = (l2->val + carry) % 10;
				carry = (l2->val + carry) / 10;
				l2 = l2->next;
			}
			else if (l2 == NULL) {
				node->val = (l1->val + carry) % 10;
				carry = (l1->val + carry) / 10;
				l1 = l1->next;
			}
			else {
				node->val = (l1->val + l2->val + carry) % 10;
				carry = (l1->val + l2->val + carry) / 10;
				l1 = l1->next;
				l2 = l2->next;
			}
			temp->next = node;
			temp = node;

		}
		if (carry)
		{
			ListNode *node = new ListNode;
			node->val = 1;
			node->next = NULL;
			temp->next = node;
			temp = node;
		}
		temp = res;
		res = res->next;
		delete[]temp;
		return res;
	}
};

//思路1：创建一个结点，每次相加结果保存在结点中，最后处理一下最高位进位的问题
struct ListNode* addTwoNumbers1(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *end, *head;
	head = (struct ListNode*)malloc(sizeof(struct ListNode));
	end = head;
	head->next = NULL;
	//终止条件：俩个列表都读完了
	int carry = 0;		//进位标识
	int remainder = 0; //余数
	while (l1!=NULL||l2!=NULL)
	{
		struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
		//如果l1跑完了l2没跑完
		if (l1==NULL)
		{
			node->val=(l2->val + carry)%10;
			carry= (l2->val + carry) / 10;
			l2 = l2->next;
		}
		else if (l2==NULL)
		{
			node->val = (l1->val + carry) % 10;
			carry = (l1->val + carry) / 10;
			l1 = l1->next;
		}
		//如果俩个都没跑完
		else {
			remainder = (l1->val + l2->val+carry) % 10;
			carry = (l1->val + l2->val+carry) / 10;
			node->val = remainder;
			l1 = l1->next;
			l2 = l2->next;
		}
		end->next = node;
		end = node;

	}
	//处理最高位进位
	if (carry)
	{
		struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
		node->val = 1;
		end->next = node;
		end = node;
	}
	end->next = NULL;
	return head->next;
}

//思路2：先直接将俩条数组相加，然后最后统一处理进位问题(看上去效率变高了，实际上变慢了)
struct ListNode* addTwoNumbers2(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *head,*end;
	head = (struct ListNode*)malloc(sizeof(struct ListNode));
	head->next = NULL;
	head->val = 0;
	end = head;
	//合并同值
	while (l1!=NULL||l2!=NULL)
	{
		struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
		if (l1==NULL)
		{
			node->val = l2->val;
			l2 = l2->next;
		}
		else if (l2==NULL)
		{
			node->val = l1->val;
			l1 = l1->next;
		}
		else {
			node->val = l1->val + l2->val;
			l1 = l1->next;
			l2 = l2->next;
		}
		end->next= node;
		end = node;
	}
	end->next = NULL;
	//处理进位
	end = head->next;	//将
	int carry = 0;
	while (end)
	{
		//先算当前进位，再算下个数是不是要进位
		end->val += carry;
		if (end->val>=10)
		{
			carry = 1;
			end->val -= 10;
		}
		else {
			carry = 0;
		}	
		if (end->next==NULL)
		{
			break;
		}
		end = end->next;
	}

	if (end->next==NULL&&carry==1)
	{
		struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
		node->next = NULL;
		node->val = 1;
		end->next = node;
		end = node;
	}
	return head->next;
}

//创建带有头节点的单链表
struct ListNode* CreatListNode1(int n) {
	struct ListNode *head, *node, *end;//定义头节点，普通节点，尾部节点；
	head = (struct ListNode*)malloc(sizeof(struct ListNode));//分配地址
	end = head;         //若是空链表则头尾节点一样
	for (int i = 0; i < n; i++)
	{
		node = (struct ListNode*)malloc(sizeof(struct ListNode));
		printf("输入第%d个节点的值:\n", i + 1);
		scanf_s("%d", &node->val);
		end->next = node;
		end = node;
	}
	end->next = NULL;
	return head;
}

//创建不带头节点的单链表
struct ListNode* CreatListNode(int n) {
	struct ListNode *head, *node, *end;//定义头节点，普通节点，尾部节点；
	head = (struct ListNode*)malloc(sizeof(struct ListNode));//分配地址
	printf("输入第%d个节点的值:\n", 1);
	scanf_s("%d", &head->val);
	end = head;         //若是空链表则头尾节点一样
	if (n == 1){
		head->next = NULL;
		return head;
	}
	for (int i = 1; i < n; i++)
	{
		node = (struct ListNode*)malloc(sizeof(struct ListNode));
		printf("输入第%d个节点的值:\n", i + 1);
		scanf_s("%d", &node->val);
		end->next = node;
		end = node;
	}
	end->next = NULL;
	return head;
}

int main() {

	struct ListNode* l1 = CreatListNode(3);//2-4-3
	struct ListNode* l2 = CreatListNode(3);//5-6-8
	Solution A;
	struct ListNode* lresultC = A.addTwoNumbers(l1, l2);
	struct ListNode* lresult1 = addTwoNumbers1(l1, l2);
	struct ListNode* lresult2 = addTwoNumbers2(l1, l2);
	return 0;

}