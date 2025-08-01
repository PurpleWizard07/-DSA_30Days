class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> store;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        // pushing the (timestamp, value) pair for the given key
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (store.find(key) == store.end()) return "";

        //Get the vector of (timestamp, value) pairs for the given key.
        const auto& entries = store[key];
        int left = 0, right = entries.size() - 1;
        string answer = "";

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (entries[mid].first <= timestamp) {
                answer = entries[mid].second;  
                 left = mid + 1;              
            } else {
                right = mid - 1;
            }
        }
        return answer;
    }
};
