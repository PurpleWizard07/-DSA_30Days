class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // Sort intervals by start time
        sort(intervals.begin(), intervals.end());

        // Store queries with their original index
        vector<pair<int, int>> queriesWithIndex;
        for(int i = 0; i < queries.size(); i++) {
            queriesWithIndex.push_back({queries[i], i});
        }
        sort(queriesWithIndex.begin(), queriesWithIndex.end());

        // Result vector
        vector<int> res(queries.size(), -1);

        // Min heap to store intervals by their size
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<>> minHeap;

        int i = 0; // Pointer for intervals
        for(auto& query : queriesWithIndex) {
            int q = query.first;
            int idx = query.second;

            // Add all intervals whose start ≤ query
            while(i < intervals.size() && intervals[i][0] <= q) {
                int start = intervals[i][0];
                int end = intervals[i][1];
                int size = end - start + 1;
                minHeap.push({size, {start, end}});
                i++;
            }

            // Remove intervals whose end < query
            while(!minHeap.empty() && minHeap.top().second.second < q) {
                minHeap.pop();
            }

            // If heap is not empty, top is the smallest covering interval
            if(!minHeap.empty()) {
                res[idx] = minHeap.top().first;
            } else {
                res[idx] = -1;
            }
        }

        return res;
    }
};
