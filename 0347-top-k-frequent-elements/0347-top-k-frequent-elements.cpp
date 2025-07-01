class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //Count frequencies
        // 1 1 1 1 1 2 2 2 2 2 2 3 3 3 3 (1-5, 2-6, 3-4)
        unordered_map<int, int> freq;
        for(int num: nums) {
            freq[num]++;
        }

        //Create bucket
        int n = nums.size();
        vector<vector<int>> buckets(n+1);
        for(auto& p: freq) {
            int num = p.first;
            int f = p.second;
            buckets[f].push_back(num); //(6-2, 5-1. 4-3)
        }

        //Collect top k frequent elements
        vector<int> answer;
        for(int i=n; i>=0; i--) {
            for(int num: buckets[i]) {
                answer.push_back(num);
                if(answer.size() == k) break;
            }
            if(answer.size() == k) break;
        }
        return answer;
    }
};




// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         //create map with frequencies
//         unordered_map<int, int> freq;
//         for(int num: nums) {
//             freq[num]++;
//         }

//         //MinHeap of size <= k
//         using Pair = pair<int, int>;
//         priority_queue<Pair, vector<Pair>, greater<Pair>> minHeap;

//         for(auto& p : freq) {
//             minHeap.emplace(p.second, p.first);
//             if(minHeap.size() > k) minHeap.pop();
//         }

//         vector<int> answer;
//         while(!minHeap.empty()) {
//             answer.push_back(minHeap.top().second);
//             minHeap.pop();
//         }
//         return answer;
//     }
// };