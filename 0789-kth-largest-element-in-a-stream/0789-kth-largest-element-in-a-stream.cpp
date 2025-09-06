#include <bits/stdc++.h>
using namespace std;

class KthLargest {
    int k;  
    priority_queue<int, vector<int>, greater<int>> minHeap;  // min-heap
    
public:
    // Constructor: build heap with initial numbers
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();  // keep only k elements
            }
        }
    }
    
    // Add new number and return kth largest
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > k) {
            minHeap.pop();  // maintain size k
        }
        return minHeap.top();  // kth largest element
    }
};
