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
    void reorderList(ListNode* head) {
        if(!head || !head->next){
            return;
        }
        deque<ListNode*> dq;
        ListNode* temp = head;
        while(temp){
            dq.push_back(temp);
            temp = temp->next;
        }
        head = NULL;
        int counter = 1;
        while(!dq.empty()){
            if(!head){
                head = dq.front();
                temp = head;
                dq.pop_front();
            }else{
                if(counter % 2 == 0){
                    temp->next = dq.front();
                    dq.pop_front();
                }else{
                    temp->next = dq.back();
                    dq.pop_back();
                }
                temp = temp->next;
                counter++;
            }
        }
        temp->next = NULL;
    }
};
