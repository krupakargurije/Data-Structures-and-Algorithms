class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& nums) {
        vector<int> ans;
        int n = nums.size();
        int m =  nums[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        int rowdir[] = {0,1,0,-1};
        int coldir[] = {1,0,-1,0};

        int r = 0, c = 0, dir = 0;

        for (int k = 0; k < n * m; k++) {
            ans.push_back(nums[r][c]);
            vis[r][c] = 1;

            int nr = r + rowdir[dir];
            int nc = c + coldir[dir];

            // If out of bounds or visited → turn right
            if (nr < 0 || nr >= n || nc < 0 || nc >= m || vis[nr][nc]) {
                dir = (dir + 1) % 4;
                nr = r + rowdir[dir];
                nc = c + coldir[dir];
            }

            r = nr;
            c = nc;
        }

        return ans;
    }
};