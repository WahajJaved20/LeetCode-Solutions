class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        recur(0,res,nums,temp);
        return vector<vector<int>>(res.begin(),res.end());
    }
    void recur(int index, set<vector<int>>& res,vector<int>&nums,vector<int> current){
        res.insert(current);
        for(int i=index;i<nums.size();i++){
            current.push_back(nums[i]);
            recur(i+1,res,nums,current);
            current.pop_back();
        }
    }
};
