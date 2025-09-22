#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses, 0);

        // Build graph
        for (auto &p : prerequisites) {
            int course = p[0];
            int prereq = p[1];
            adj[prereq].push_back(course);
            indeg[course]++;
        }

        queue<int> q;
        // Start with courses that have no prereqs
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) q.push(i);
        }

        vector<int> order;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            order.push_back(u);

            for (int v : adj[u]) {
                if (--indeg[v] == 0) {
                    q.push(v);
                }
            }
        }

        if ((int)order.size() == numCourses) return order;
        return {}; // cycle detected
    }
};
