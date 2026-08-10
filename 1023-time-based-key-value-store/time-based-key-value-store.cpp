class TimeMap {
public:
    unordered_map<string , vector<pair<int , string>>>mp;
    // TimeMap() {}
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp , value});
    }
    
    string get(string key, int timestamp) {
        if(mp.count(key) == 0 || mp[key][0].first > timestamp)
            return "";

        auto &curr = mp[key];
        int left = 0 , right = curr.size() - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;

            if(curr[mid].first <= timestamp){
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        return curr[left - 1].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */