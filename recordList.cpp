
 // Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	int length(ListNode *head) {
		int len = 0;
		while(head){
			++len;
			head = head->next;
		}
		return len;
	}
    void reorderList(ListNode *head) {
		if(head == 0 || head->next == 0 || head->next->next == 0) return;
        vector<ListNode*> left;
        vector<ListNode*> right;
		int len = length(head);
		int half = len / 2;

			ListNode * tmp = head;
			for(int i=0; i<half; ++i){
				left.push_back(tmp);
				tmp = tmp->next;
			}
			if(len % 2 == 1){
				left.push_back(tmp);
				tmp = tmp->next;
			}
			for(int i=0; i<half; ++i){
				right.push_back(tmp);
				tmp = tmp->next;
			}
			for(int i=0; i<half; ++i)
				left[i]->next = right[half-i-1];
			for(int i=0; i<half-1; ++i)
				right[half-i-1]->next = left[i+1];
			if(len % 2 == 1){
				right[0]->next = left[half];
			}
    }
};
