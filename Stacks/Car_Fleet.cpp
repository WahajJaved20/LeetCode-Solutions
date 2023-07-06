class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> ps;
        int n = position.size();
        for(int i=0;i<n;i++){
            ps.push_back(pair<int,int>(position[i],speed[i]));
        }
        sort(ps.begin(),ps.end());
        stack<pair<int,int>> res;
        res.push(ps[n-1]);
        cout<<ps[0].first;
        for(int i=n-2;i>=0;i--){
            pair<int,int> curr = res.top();
            float currTime = ((target - curr.first)*1.00) / curr.second;
            float ithTime = ((target - ps[i].first)*1.00) / ps[i].second;
            if(ithTime > currTime){
                res.push(ps[i]);
            }
        }
        return res.size();
    }
};
