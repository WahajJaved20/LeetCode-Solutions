class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        findSum(res,0,target,0,temp,candidates);
        return res;
    }
    void findSum(vector<vector<int>>& res, int sum, int target,int currentIndex, vector<int>& temp,vector<int>& candidates){
        if(target == sum){
            res.push_back(temp);
        }
        if(sum > target){
            return;
        }
        for(int i=currentIndex;i<candidates.size();i++){
            temp.push_back(candidates[i]);
            findSum(res,sum + candidates[i],target,i,temp, candidates);
            temp.pop_back();
        }
    }
};
