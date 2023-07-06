class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxResult = 0;
        int l=0, r= height.size()-1;
        while ( l < r ){
            int current = (r-l) * min(height[l],height[r]);
            maxResult = max(current,maxResult);
            if(height[l] < height[r]){
                l++;
            }else if(height[r] < height[l]){
                r--;
            }else{
                if(height[l+1] < height[r-1]){
                    l++;
                }else{
                    r--;
                }
            }
        }
        return maxResult;
    }
};
