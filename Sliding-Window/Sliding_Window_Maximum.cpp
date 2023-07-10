class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        int i=0,j=0;
        while(j<nums.size()){
            // if the one at end < one to be inserted, remove (max calculation)
            while (!dq.empty() && nums[dq.back()] < nums[j]){
                dq.pop_back();
            }
            dq.push_back(j);
            // if leftmost element is lesser than the new incoming one, then remove leftmost
            if(i > dq.front()){
                dq.pop_front();
            }
            // if next window is possible, add current result and increment i
            if(j+1 >= k){
                res.push_back(nums[dq.front()]);
                i++;
            }
            j++;
        }
        return res;
    }
};
