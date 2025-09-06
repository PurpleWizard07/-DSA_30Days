#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;  // max-heap
        for (int s : stones) {
            maxHeap.push(s);
        }
        
        while (maxHeap.size() > 1) {
            int stone1 = maxHeap.top(); maxHeap.pop();
            int stone2 = maxHeap.top(); maxHeap.pop();
            
            if (stone1 != stone2) {
                maxHeap.push(stone1 - stone2);
            }
        }
        
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};
