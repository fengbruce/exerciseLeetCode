// 还算比较顺利
// 遍历链表常见保存当前指针的前一个指针
// 另外，如果需要只包含头指针的链表，需要把头指针的next域置零
#include <iostream>
#include <stdlib.h>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
		if(head == 0 || head->next == 0) return head;
		ListNode *cur = head->next;
		ListNode *ret = head;
		ret->next = 0;

		while(cur != 0){
			ListNode * tmp1 = cur;
			cur = cur->next;
			ListNode * tmp2 = ret;
			ListNode * before = tmp2;
			while(tmp2 && tmp2->val < tmp1->val){
				before = tmp2;
				tmp2 = tmp2->next;
			}				
			tmp1->next = tmp2;
			if(before == tmp2)
				ret = tmp1;
			else
				before->next = tmp1;
		}
		return ret;
    }
};



int main()
{
	Solution so;
	ListNode head(9);
	ListNode * tmp = &head;
	int maxN = 10;
	for(int i=0; i<20; ++i){
		ListNode * nh = new ListNode(rand()%maxN);
		tmp->next = nh;
		tmp = tmp->next;
	}
	tmp = &head;
	while(tmp){
		cout<<tmp->val<<" ";
		tmp = tmp->next;
	}
	tmp = &head;
	cout<<endl;
	tmp = so.insertionSortList(tmp);
	while(tmp){
		cout<<tmp->val<<" ";
		tmp = tmp->next;
	}

	return 0;
}
