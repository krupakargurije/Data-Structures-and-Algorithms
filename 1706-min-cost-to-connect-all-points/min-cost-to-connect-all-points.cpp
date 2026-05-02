class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return false;
        parent[px] = py;
        return true;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        vector<vector<int>> edges;

        // build all edges
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int cost = abs(points[i][0] - points[j][0]) +
                           abs(points[i][1] - points[j][1]);
                edges.push_back({cost, i, j});
            }
        }

        sort(edges.begin(), edges.end());

        int totalCost = 0;
        for (auto &e : edges) {
            if (unite(e[1], e[2])) {
                totalCost += e[0];
            }
        }

        return totalCost;
    }
};