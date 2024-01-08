class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string result = "";
        if(str1 + str2 != str2 + str1){
            return result;
        }
        result =  str1.substr(0,gcd(str1.length(),str2.length()));
        return result;
    }
};
