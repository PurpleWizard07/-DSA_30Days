#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; i++) parent[i] = i;

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            if (find(parent, u) == find(parent, v)) {
                return e; // cycle found
            }
            unite(parent, u, v);
        }
        return {};
    }

private:
    int find(vector<int>& parent, int x) {
        if (parent[x] != x) parent[x] = find(parent, parent[x]); // path compression
        return parent[x];
    }

    void unite(vector<int>& parent, int a, int b) {
        int pa = find(parent, a);
        int pb = find(parent, b);
        if (pa != pb) parent[pa] = pb; // merge sets
    }
};
