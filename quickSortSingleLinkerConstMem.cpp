/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        
    }
};
void qsort(int src[], int len)
{
	if(len < 2) return;
	int midItem = src[0];
	int head = 1;
	int tail = len-1;
	while(1){
		while( head <= tail && src[head] <= midItem ) ++head;
		while( tail > head && src[tail] >= midItem ) --tail;
		cout<<head<<" "<<tail<<endl;
		if( head >= tail ) break;
		swap(src+head, src+tail);
	}
	swap(src+0, src+head-1);
	qsort(src, head-1);
	qsort(src+head, len-head);
}
