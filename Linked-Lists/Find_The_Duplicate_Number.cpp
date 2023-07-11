class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0,fast=0,slow2=0;
        while(true){
            fast = nums[nums[fast]];
            slow = nums[slow];
            if(fast == slow){
                break;
            }
        }
        while(true){
            slow = nums[slow];
            slow2 = nums[slow2];
            if(slow == slow2){
                return slow;
            }
        }
    }
};
