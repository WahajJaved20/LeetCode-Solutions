class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> temp;
        temp.push(pair<int,int>(0,temperatures[0]));
        vector<int> res(temperatures.size());
        for(int i=1;i<temperatures.size();i++){
            if((temp.top()).second < temperatures[i]){
                while(!temp.empty() && ((temp.top()).second < temperatures[i])){
                    pair<int,int> curr = temp.top();
                    temp.pop();
                    res[curr.first] = (i - curr.first);
                    
                }
                temp.push(pair<int,int>(i,temperatures[i]));
                
            }else{
                temp.push(pair<int,int>(i,temperatures[i]));
            }
        }
        return res;
    }
};
