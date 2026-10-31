class Solution {
public:
    const int MOD = 1e9 + 7;
    int n, m;
    int f(int i, int j, int d, vector<vector<int>>& grid,
          vector<vector<vector<int>>>& dp){
        if (i >= n || j >= m)
            return 0;
        if (i == n - 1 && j == m - 1) {
            return 1;
        }

        if(dp[i][j][d] != -1){
            return dp[i][j][d];
        }

        // explore
        long long ans = 0;
        if (grid[i][j] == 0) {
            ans = (f(i, j + 1, 0, grid, dp) + f(i + 1, j, 1, grid, dp)) % MOD;
        } else {
            if (d == 0) {
                ans = f(i + 1, j, 1, grid, dp);
            } else {
                ans = f(i, j + 1, 0, grid, dp);
            }
        }
        return dp[i][j][d] = ans;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(2, -1)));

        return f(0, 0, 0, grid, dp)%MOD;
    }
};