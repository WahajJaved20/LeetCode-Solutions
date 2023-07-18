class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.length() == 0){
            return res;
        }
        map<char,string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        
        recur(m,res,"",0,digits);
        return res;
    }
    void recur(map<char,string>& m,vector<string>& res,string currentString,int index,string& digits){
        if(index >= digits.size()){
            res.push_back(currentString);
            return;
        }
        string current = m[digits[index]];
        for(int i=0;i<current.length();i++){
            currentString += current[i];
            recur(m,res,currentString,index + 1,digits);
            currentString = currentString.substr(0,currentString.size()-1);
        }
    }
};
