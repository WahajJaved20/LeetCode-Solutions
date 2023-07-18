class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        findSum(res,0,target,0,temp,candidates);
        return vector<vector<int>>(res.begin(),res.end());
    }
    void findSum(set<vector<int>>& res, int sum, int target,int currentIndex, vector<int>& temp,vector<int>& candidates){
        if(target == sum){
            res.insert(temp);
        }
        if(sum > target){
            return;
        }
        int prev = -1;
        for(int i=currentIndex;i<candidates.size();i++){
            if(candidates[i] == prev){
                continue;
            }
            temp.push_back(candidates[i]);
            findSum(res,sum + candidates[i],target,i+1,temp, candidates);
            temp.pop_back();
            prev = candidates[i];
        }
    }
};
