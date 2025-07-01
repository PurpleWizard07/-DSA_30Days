class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //create map with frequencies
        unordered_map<int, int> freq;
        for(int num: nums) {
            freq[num]++;
        }

        //MinHeap of size <= k
        using Pair = pair<int, int>;
        priority_queue<Pair, vector<Pair>, greater<Pair>> minHeap;

        for(auto& p : freq) {
            minHeap.emplace(p.second, p.first);
            if(minHeap.size() > k) minHeap.pop();
        }

        vector<int> answer;
        while(!minHeap.empty()) {
            answer.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return answer;
    }
};