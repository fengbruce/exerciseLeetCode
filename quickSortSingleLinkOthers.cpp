class Solution {
public:
    ListNode *sortList(ListNode *head) {
        return quicksort(head, NULL);
    }
    ListNode *quicksort(ListNode *head, ListNode *tail) {
        if (!head) return NULL;
        if (head -> next == tail) return head;
        ListNode *nexthead = head;
        while (nexthead -> next && nexthead -> next -> val == head -> val) nexthead = nexthead -> next;
        ListNode *prehead = head, *posthead = nexthead, *p = nexthead -> next;
        while (p != tail) {
            if (p -> val < head -> val) {
                ListNode *tmp1 = p -> next;
                ListNode *tmp2 = prehead;
                prehead = p;
                prehead -> next = tmp2;
                p = tmp1;
            } else {
                posthead -> next = p;
                posthead = p;
                p = p -> next;
            }
        }
        posthead -> next = tail;
        if (nexthead -> next != tail) nexthead -> next = quicksort(nexthead -> next, tail);
        if (prehead == head) return head;
        else return quicksort(prehead, head);
    }
};
