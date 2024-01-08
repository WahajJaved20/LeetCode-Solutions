class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maximum = 0;
        int length = candies.size();
        for(int i=0;i<length;i++){
            if(candies[i] > maximum){
                maximum = candies[i];
            }
        }
        vector<bool> results;
        for(int i=0;i<length;i++){
            if(candies[i] + extraCandies >= maximum){
                results.push_back(true);
            }else{
                results.push_back(false);
            }
        }
        return results;
    }
};
