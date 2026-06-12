/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // This line lets you use "Node" instead of "ListNode"
    using Node = ListNode;

    Node* reverseLinkedList(Node* head){
        if(head==NULL|| head->next==NULL) return head;
        Node* newHead= reverseLinkedList(head->next);
        Node* front= head->next; // Fixed: Capitalized "Node"
        front->next=head;
        head->next= NULL;
        return newHead;
    }

    bool isPalindrome(Node* head) {
        if(head==NULL|| head->next ==NULL){
            return true;
        }
        Node* slow=head;
        Node* fast=head;
        while(fast->next!=NULL&& fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next; // Fixed: Changed ">" to "->"
        }
        Node* newHead= reverseLinkedList(slow->next); // Fixed: Changed ">" to "->"
        Node* first= head;
        Node* second= newHead;
        while(second!= NULL){
            if(first->val!=second->val){ // Fixed: Changed ".data" to ".val"
                reverseLinkedList(newHead);
                return false;
            }
            first=first->next;
            second=second->next;
        }
        reverseLinkedList(newHead);
        return true; // Fixed: Added missing return statement
    }
};
