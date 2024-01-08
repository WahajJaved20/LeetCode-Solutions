class Solution {
public:
    string reverseWords(string s) {
        vector<string> strings;
        string currentWord = "";
        for(int i=0;i<s.length();i++){
            if(s[i] == ' '){
                if(currentWord.length() == 0 || currentWord[0] == ' '){
                    continue;
                }
                strings.push_back(currentWord);
                currentWord = "";
                continue;
            }
            currentWord += s[i];
        }
        if(currentWord.length() != 0 && currentWord[0] != ' '){
            strings.push_back(currentWord);
        }
        string result = "";
        for(int i=strings.size()-1;i>=0;i--){
            result += strings[i];
            if(i-1 != -1){
                result += ' ';
            }
        }
        return result;
    }
};
