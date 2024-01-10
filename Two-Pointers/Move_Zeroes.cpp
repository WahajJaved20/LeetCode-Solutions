class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastIndex = 0;
        int i = 0;
        while(i<nums.size()){
            if(nums[i] != 0){
                nums[lastIndex] = nums[i];
                lastIndex++;
            }
            i++;
        }
        while(lastIndex < nums.size()){
            nums[lastIndex] = 0;
            lastIndex++;
        }
    }
};
