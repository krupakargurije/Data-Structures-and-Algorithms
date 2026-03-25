using ll = long long;
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        ll total = 0;

        for(int i = 0;i<n;i++){
            for(int j = 0;j< m;j++){
                total += grid[i][j];
            }
        }

        if(total % 2)return false;

        ll target = total / 2;
        ll sum = 0;

        for(int i = 0;i < n - 1;i++){
            for(int j = 0;j< m;j++){
                sum += grid[i][j];
            }
            if(sum == target)return true;
        }

        sum = 0;

        for(int j = 0;j<m - 1;j++){
            for(int i = 0;i < n;i++){
                sum += grid[i][j];
            }
            if(sum == target)return true;
        }
        return false;
    }
};