class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int result = 0;
        vector<int> leftMax(n),rightMax(n);
        leftMax[0]=height[0];
        rightMax[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            if(height[i] > leftMax[i-1]){
                leftMax[i] = height[i];
            }else{
                leftMax[i] = leftMax[i-1];
            }
        }
        for(int i=n-2;i>=0;i--){
            if(height[i] > rightMax[i+1]){
                rightMax[i] = height[i];
            }else{
                rightMax[i] = rightMax[i+1];
            }
        }
        for(int i=0;i<n;i++){
            int currRes = min(leftMax[i],rightMax[i]);
            currRes = currRes - height[i];
            if(currRes > 0){
                result += currRes;
            }
        }
        return result;
    }
};
