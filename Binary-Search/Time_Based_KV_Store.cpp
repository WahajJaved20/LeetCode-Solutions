class TimeMap {
private:
    map<string,vector<pair<string,int>>> tm;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if(tm[key].size() == 0){
            vector<pair<string,int>> t{pair<string,int>(value,timestamp)};
            tm[key] = t;
        }else{
            tm[key].push_back(pair<string,int>(value,timestamp));
        }
    }
    
    string get(string key, int timestamp) {
        if(tm[key].size() == 0){
            return "";
        }
        if(tm[key][0].second > timestamp){
            return "";
        }
        int l = 0, r = tm[key].size() - 1;
        string result = tm[key][0].first;
        while(l<=r){
            int m = (l + r) / 2;
            if(tm[key][m].second == timestamp){
                result = tm[key][m].first;
                break;
            }
            if(tm[key][m].second <= timestamp){
                result = tm[key][m].first;
                l = m + 1;
            }else{
                r = m - 1;
            }
        }
        return result;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
