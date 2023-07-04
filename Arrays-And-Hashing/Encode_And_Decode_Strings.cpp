class Solution {
public:
    string watermark="/*wj*/";
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        string res = "";
        for(int i=0;i<strs[i];i++){
            res += strs[i];
            res += watermark;
        }
        return res;
    }

    /*
     * @param str: A string
     * @return: decodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        vector<string> res;
        string temp = "";
        for(int i=0;i<str.length();i++){
            if(str[i] != '/'){
                temp += str[i];
            }else{
                int j=0;
                int k=i;
                while(i < str.length() && j<watermark.length() && str[i] == watermark[j]){
                    i++;
                    j++;
                }
                if(j==watermark.length()){
                    res.push_back(temp);
                    temp = "";
                    i++;
                }else{
                    temp += str[i];
                    i = k;
                }
            }
        }
        return res;
    }
};
