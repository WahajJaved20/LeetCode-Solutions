class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int length1 = word1.length();
        int length2 = word2.length();
        if(!length1){
            return word2;
        }
        if(!length2){
            return word1;
        }
        int i=0, j=0;
        string result = "";
        int turn = 0;
        while ( i<length1 && j<length2){
            if(turn % 2 == 0){
                result += word1[i];
                i++;
            }else{
                result += word2[j];
                j++;
            }
            turn++;
        }
        while(i<length1){
            result += word1[i];
            i++;
        }
        while(j<length2){
            result += word2[j];
            j++;
        }
        return result;
    }
};


// better approach
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int length1 = word1.length();
        int length2 = word2.length();
        if(!length1){
            return word2;
        }
        if(!length2){
            return word1;
        }
        int i=0, j=0;
        string result = "";
        while ( i<length1 || j<length2){
            if(i<length1){
                result += word1[i];
                i++;
            }
            if(j<length2){
                result += word2[j];
                j++;
            }
                
            
        }
        return result;
    }
};
