class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> keyStore;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        keyStore[key].emplace_back(value, timestamp);
    }
    
    string get(string key, int timestamp) {
        auto& values = keyStore[key];
        int l = 0, r = values.size() -  1;
        string res = "";

        while(l <= r){
            int mid = (l + r) / 2;
            if(values[mid].second <= timestamp){
                res = values[mid].first;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }
};
