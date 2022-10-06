class TimeMap {
public:
    unordered_map<string,unordered_map<int,string>>mp;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        if(!mp.count(key)){
            return "";
        }
        for(int i=timestamp;i>=1;i--){
            if(mp[key].count(i)){
                return mp[key][i];
            }
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */