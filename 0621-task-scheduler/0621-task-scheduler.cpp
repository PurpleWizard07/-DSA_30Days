#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char t : tasks) freq[t]++;

        priority_queue<int> maxHeap;
        for (auto [task, f] : freq) maxHeap.push(f);

        int time = 0;
        while (!maxHeap.empty()) {
            vector<int> temp;
            int cycle = n + 1;

            while (cycle > 0 && !maxHeap.empty()) {
                int cnt = maxHeap.top(); maxHeap.pop();
                if (--cnt > 0) temp.push_back(cnt);
                time++;
                cycle--;
            }

            for (int c : temp) maxHeap.push(c);

            if (!maxHeap.empty()) {
                time += cycle; // idle slots
            }
        }
        return time;
    }
};
