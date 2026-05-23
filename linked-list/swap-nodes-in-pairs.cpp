class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Dummy node simplifies edge cases
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        while (prev->next && prev->next->next) {
            ListNode* first = prev->next;
            ListNode* second = first->next;

            // Swapping
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move prev forward
            prev = first;
        }

        return dummy.next;
    }
};