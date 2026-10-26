
class Solution {
public:
    int m, n;

    int dfs(vector<vector<int>>& g, int r, int c, int k) {
        if (r < 0 || r >= m || c < 0 || c >= n || g[r][c] <= 0)
            return 0;

        int sum = g[r][c] % k;
        g[r][c] = -1;

        sum = (sum + dfs(g, r - 1, c, k)) % k;
        sum = (sum + dfs(g, r + 1, c, k)) % k;
        sum = (sum + dfs(g, r, c - 1, k)) % k;
        sum = (sum + dfs(g, r, c + 1, k)) % k;

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        int cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    if (dfs(grid, i, j, k) == 0)
                        cnt++;
                }
            }
        }

        return cnt;
    }
};
