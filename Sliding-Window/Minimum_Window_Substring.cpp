class Solution {
public:
    string minWindow(string s, string t) {
        if(t==""){
            return t;
        }
        if(s==t){
            return s;
        }
        size_t found = s.find(t);
        if (found != std::string::npos) {
            return t;
        }
        map<char,int> target,window;
        for(int i=0;i<t.length();i++){
            target[t[i]]++;
        }
        int have=0,need=target.size();
        int l = 0;
        string res="";
        int resLength=INT_MAX;
        for(int i=0;i<s.length();i++){
            window[s[i]]++;
            if(target[s[i]] != 0 && target[s[i]] == window[s[i]]){
                have++;
            }
            while(have == need){
                if (i-l+1 < resLength){
                    resLength = i - l + 1;
                    res = s.substr(l,resLength);

                }
                window[s[l]]--;
                if(target[s[l]] != 0 && target[s[l]] > window[s[l]]){
                    have --;
                }
                l++;
            }
        }
        return res;
    }
};
