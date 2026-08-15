class DisJoinSet {
    vector<int> parent;

    public:
    DisJoinSet(int n) {
        parent.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        int parentA = find(a);
        int parentB = find(b);

        if (parentA == parentB) {
            return false;
        }

        parent[parentA] = parentB;
        return true;
    }
};

class Solution {
    public:

    int removeStones(vector<vector<int>>& stones) {

        int maxRow = 0;
        int maxCol = 0;

        for (auto &it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        int offset = maxRow + 1;

        DisJoinSet ds(maxRow + maxCol + 2);
        unordered_map<int, int> mp;

        for (auto &it : stones) {

            int rowNode = it[0];
            int colNode = it[1] + offset;

            ds.unite(rowNode, colNode);

            mp[rowNode] = 1;
            mp[colNode] = 1;
        }

        int components = 0;
        for (auto &it : mp) {
            if (ds.find(it.first) == it.first) {
                components++;
            }
        }
        return stones.size() - components;
    }
};