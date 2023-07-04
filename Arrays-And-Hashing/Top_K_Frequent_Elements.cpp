class Solution {
public:
    static bool comparePairs(const pair<int, int>& pair1, const pair<int, int>& pair2) {
        return pair1.second < pair2.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        int vectorIndex = 1;
        vector<pair<int,int>> numberToFrequency;
        map<int,int> numberToVectorIndex;
        for(int i=0;i<nums.size();i++){
            if(numberToVectorIndex[nums[i]]){
                numberToFrequency[numberToVectorIndex[nums[i]] - 1].second++;
            }else{
                numberToFrequency.push_back(pair<int,int>(nums[i],1));
                numberToVectorIndex[nums[i]] = vectorIndex++;
            }
        }
        sort(numberToFrequency.begin(), numberToFrequency.end(), comparePairs);
        for(int i=0;i<k;i++){
            result.push_back(numberToFrequency[numberToFrequency.size()-1-i].first);
        }
        return result;
    }
};
