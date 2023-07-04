class Solution {
public:
    bool compareStrings(string s1, string s2){
        vector<int> v1,v2;
        v1.resize(26);
        v2.resize(26);
        for(int i=0;i<s1.length();i++){
            v1[s1[i] - 'a'] ++;
        }
        for(int j=0;j<s2.length();j++){
            v2[s2[j] - 'a']++;
        }

        return v1 == v2;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<int,vector<int>> sumToIndices;
        int mapIndex=1;
        vector<vector<string>> result;
        for(int i=0;i<strs.size();i++){
            int sum = 0;
            
            for(int j=0;j<strs[i].size();j++){
                sum += strs[i][j] - 'a';
            }
            bool found = false;
            if(sumToIndices[sum].size()){
                for(int k=0;k<sumToIndices[sum].size();k++){
                    string test = result[sumToIndices[sum][k]-1][0];
                    cout<<test <<" "<<strs[i];
                    if(compareStrings(test,strs[i])){
                        result[sumToIndices[sum][k]-1].push_back(strs[i]);
                        found = true;
                        break;
                    }
                }   
                cout<<endl;
            }
            if(!found){
                if(sumToIndices[sum].size()){
                    sumToIndices[sum].push_back(mapIndex++);
                }else{
                    vector<int> t;
                    t.push_back(mapIndex++);
                    sumToIndices[sum] = t;
                }
                vector<string> temp;
                temp.push_back(strs[i]);
                result.push_back(temp);
            }
                
        }
        return result;
    }
};
