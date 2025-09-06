#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // max-heap: pair<distance, point>
        priority_queue<pair<int, vector<int>>> maxHeap;
        
        for (auto& p : points) {
            int dist = p[0]*p[0] + p[1]*p[1];  // no sqrt
            maxHeap.push({dist, p});
            if (maxHeap.size() > k) {
                maxHeap.pop(); // remove farthest
            }
        }
        
        vector<vector<int>> ans;
        while (!maxHeap.empty()) {
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return ans;
    }
};
