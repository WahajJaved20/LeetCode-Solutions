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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = NULL;
        ListNode* temp = result;
        int carry = 0;
        while(l1 && l2){
            int sum = carry + l1->val + l2->val;
            if(sum / 10 != 0){
                carry = sum / 10;
                sum = sum % 10;
            }else{
                carry = 0;
            }
            if(!temp){
                temp = new ListNode(sum);
                result = temp;
            }else{
                temp->next = new ListNode(sum);
                temp = temp->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int sum = carry + l1->val;
            if(sum / 10 != 0){
                carry = sum / 10;
                sum = sum % 10;
            }else{
                carry = 0;
            }
            temp->next = new ListNode(sum);
            temp = temp->next;
            l1 = l1->next;
        }
        while(l2){
            int sum = carry + l2->val;
            if(sum / 10 != 0){
                carry = sum / 10;
                sum = sum % 10;
            }else{
                carry = 0;
            }
            temp->next = new ListNode(sum);
            temp = temp->next;
            l2 = l2->next;
        }
        if(carry != 0){
            temp->next= new ListNode(carry);
        }
        return result;
    }
};
