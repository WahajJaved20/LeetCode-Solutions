class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        recur(s,0,temp,res);
        return res;
    }
    bool palindrome(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void recur(string s, int start, vector<string>& curr, vector<vector<string>>& result) {
        if (start == s.size()) {
            result.push_back(curr);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (palindrome(s, start, i)) {
                string str = s.substr(start, i - start + 1);
                curr.push_back(str);
                recur(s, i + 1, curr, result);
                curr.pop_back();
            }
        }
    }
};
