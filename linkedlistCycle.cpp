 // Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
		if(head == 0) return 0;
        ListNode * tmp1 = head;
        ListNode * tmp2 = head;
        ListNode * tmp = 0;

		while(1){
			tmp1 = tmp1->next;
			if(tmp1 == 0) return 0;
			tmp2 = tmp2->next;
			if(tmp2 == 0) return 0;
			tmp2 = tmp2->next;
			if(tmp2 == 0) return 0;
			if(tmp1 == tmp2)
				break;
		}
		tmp = head;
		ListNode * candidate = head;
		ListNode * pin = tmp1;
		ListNode * cur;
		int hit;
		while(1){
			cur = pin;
		while(cur != candidate){

			cur = cur->next;
			if(cur == pin) break;
		}
		if(cur == candidate)
			return cur;
		candidate = candidate->next;
		}

    }
};




 // Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:

bool hasCycle(ListNode *head) {
		if(head == 0) return 0;
        ListNode * tmp1 = head;
        ListNode * tmp2 = head;
        ListNode * tmp = 0;

		while(1){
			tmp1 = tmp1->next;
			if(tmp1 == 0) return 0;
			tmp2 = tmp2->next;
			if(tmp2 == 0) return 0;
			tmp2 = tmp2->next;
			if(tmp2 == 0) return 0;
			if(tmp1 == tmp2)
				return 1;
		}
	}
};

