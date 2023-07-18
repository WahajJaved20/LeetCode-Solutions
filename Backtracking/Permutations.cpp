class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        recur(nums,temp,res);
        return res;
    }
    void recur(vector<int>& nums, vector<int>& temp, vector<vector<int>>& res){
        if(temp.size() == nums.size()){
            res.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i] == -100){
                continue;
            }
            temp.push_back(nums[i]);
            int t = nums[i];
            nums[i] = -100;
            recur(nums,temp,res);
            nums[i] = t;
            temp.pop_back();
        }
    }
};
