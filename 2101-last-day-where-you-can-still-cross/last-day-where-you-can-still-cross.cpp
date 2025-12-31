class Solution {
    vector<int> parent, rank;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;

        if (rank[px] < rank[py]) parent[px] = py;
        else if (rank[px] > rank[py]) parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }

public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = row * col;
        int TOP = n;
        int BOTTOM = n + 1;

        parent.resize(n + 2);
        rank.resize(n + 2, 0);

        for (int i = 0; i < n + 2; i++)
            parent[i] = i;

        vector<vector<bool>> open(row, vector<bool>(col, false));

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        for (int i = cells.size() - 1; i >= 0; i--) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            open[r][c] = true;

            int id = r * col + c;

            if (r == 0) unite(id, TOP);
            if (r == row - 1) unite(id, BOTTOM);

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if (nr >= 0 && nr < row && nc >= 0 && nc < col && open[nr][nc]) {
                    unite(id, nr * col + nc);
                }
            }

            if (find(TOP) == find(BOTTOM))
                return i;
        }
        return 0;
    }
};
