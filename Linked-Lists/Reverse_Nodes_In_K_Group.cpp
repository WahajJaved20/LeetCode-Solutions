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
    ListNode* reverseHead = NULL;
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1){
            return head;
        }
        int counter = 0 ;
        ListNode* temp = head;
        vector<ListNode*> v;
        ListNode* prev;
        while(temp){
            prev = temp;
            counter++;
            temp = temp->next;
            if(counter % (k) == 0){
                if(temp){
                    prev->next = NULL;
                    reverse(head);
                    v.push_back(reverseHead);
                    head = temp;
                }else{
                    reverse(head);
                    v.push_back(reverseHead);
                }
            }
        }
        if(temp || counter % k != 0){
            v.push_back(head);
        }
        
        ListNode* result = v[0];
        temp = result;
        for(int i=1;i<v.size();i++){
            while(temp->next){
                temp = temp->next;
            }
            temp->next = v[i];
        }
        return result;
    }
};
