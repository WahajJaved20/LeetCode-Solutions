class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int> res;
       map <int,int> mp;
       for(int i=0;i<nums.size();i++){
           int required = target - nums[i];
           cout<<required<<"  "<<mp[required]<<endl;
           if(mp[required]){
               res.push_back(i+1);
               res.push_back(mp[required]);
               break;
           }
           mp[nums[i]] = i+1;
       }
       res[0]--;
       res[1]--;
       return res;
    }
};
