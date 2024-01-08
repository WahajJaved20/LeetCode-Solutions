class Solution {
public:
    string reverseVowels(string s) {
        int start = 0, end = s.length()-1;
        
        map<char, bool> vowels;
        vowels['a'] = true;
        vowels['e'] = true;
        vowels['i'] = true;
        vowels['o'] = true;
        vowels['u'] = true;
    
        int found1 = -1, found2 = -1;
        bool condition1, condition2;
        while(start <= end){
            condition1 = vowels[tolower(s[start])];
            condition2 = vowels[tolower(s[end])];
            if(condition1){
                found1 = start;
            }else{
                start ++;
            }
            if(condition2){
                found2 = end;
            }else{
                end --;
            }
            if(found1 != -1 && found2 != -1 ){
                char temp = s[found1];
                s[found1] = s[found2];
                s[found2] = temp;
                found1 = -1;
                found2 = -1;
                start ++;
                end --;
            }
        }
        return s;
    }
};
