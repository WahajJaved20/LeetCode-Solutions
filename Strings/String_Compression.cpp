class Solution {
public:
    int compress(vector<char>& chars) {
    
        int currentLength = 1;
        vector<char> results;
        if(chars.size() == 1){
            return chars.size();
        }
       
        for(int i=1;i<chars.size();i++){
            if(chars[i] == chars[i-1]){
                currentLength+=1;
            }else{
                if(currentLength != 1){
                    results.push_back(chars[i-1]);
                    string l = to_string(currentLength);
                    for(int j=0;j<l.length();j++){
                        results.push_back(l[j]);
                    }
                }else{
                    results.push_back(chars[i-1]);
                }
                currentLength = 1;
            }
        }
        if(currentLength == 1){
            results.push_back(chars[chars.size()-1]);
        }else{
            results.push_back(chars[chars.size()-1]);
            string l = to_string(currentLength);
            for(int j=0;j<l.length();j++){
                results.push_back(l[j]);
            }
        }
        
        chars = results;
        return results.size();
    }
};
