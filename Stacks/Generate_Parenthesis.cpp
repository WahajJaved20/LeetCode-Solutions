class Solution {
public:
    vector<string> res; 
    stack<string> s;
    void gen(int n,int open,int close){
        if(open == close && close == n){
            string r = "";
            stack<string> x = s;
            while(!x.empty()){
                r += x.top();
                x.pop();
            }
            reverse(r.begin(),r.end());
            res.push_back(r);
        }
        if(open < n){
            s.push("(");
            gen(n,open+1,close);
            s.pop();
        }
        if(close < open){
            s.push(")");
            gen(n,open,close + 1);
            s.pop();
        }
    }
    vector<string> generateParenthesis(int n) {
        gen(n,0,0);
        return res;
    }
    
};
