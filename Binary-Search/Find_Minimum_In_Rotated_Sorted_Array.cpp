class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r = nums.size()-1;
        int result = nums[0];
        while(l <= r){
            int m = (l + r) / 2;
            if(nums[l] < nums[r]){
                result = min(result,nums[l]);
                break;
            }
            result = min(result,nums[m]);
            if(nums[m] >= nums[l]){
                l = m + 1;
            }else{
                r = m - 1;
            }
        }
        return result;
    }
};
