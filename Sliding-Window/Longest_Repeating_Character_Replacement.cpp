class Solution {
public:
    int characterReplacement(string s, int k) {
        int result = 0;
        int start = 0;
        int maxFreq = 0;
        map<char,int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
            maxFreq = max(maxFreq,m[s[i]]);
            while((i - start + 1) - maxFreq > k){
                m[s[start]]--;
                start++;
            }
            result = max(result, i-start+1);
        }
        return result;
    }
};
