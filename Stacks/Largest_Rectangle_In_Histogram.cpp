class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int,int>> st;
        int n=heights.size();
        st.push(pair<int,int>(0,heights[0]));
        for(int i=1;i<n;i++){
            int start = i;
            while(!st.empty() && ((st.top()).second) > heights[i]){
                pair<int,int> curr = st.top();
                st.pop();
                maxArea = max(maxArea, curr.second * (i - curr.first));
                start = curr.first;
            }
            st.push(pair<int,int>(start,heights[i]));
        }
        while(!st.empty()){
            pair<int,int> curr = st.top();
            st.pop();
            maxArea = max(maxArea, curr.second * (n - curr.first));
        }
        return maxArea;
    }
};
