class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;

        int length = 1;
        ListNode* tail = head;

        // find length and last node
        while(tail->next){
            tail = tail->next;
            length++;
        }

        // make circular list
        tail->next = head;

        k = k % length;

        int steps = length - k;

        ListNode* newTail = head;
        for(int i = 1; i < steps; i++){
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;

        // break circle
        newTail->next = NULL;

        return newHead;
    }
};