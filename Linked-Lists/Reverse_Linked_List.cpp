class Solution {
public:
    ListNode* reverseHead;
    ListNode* reverseList(ListNode* head) {
        reverse(head);
        return reverseHead;
    }
    ListNode* reverse(ListNode* head){
        if(head == NULL || head->next == NULL){
            reverseHead = head;
            return head;
        }
        ListNode* temp = reverse(head->next);
        temp->next = head;
        head->next = NULL;
        return head;
    }
};
