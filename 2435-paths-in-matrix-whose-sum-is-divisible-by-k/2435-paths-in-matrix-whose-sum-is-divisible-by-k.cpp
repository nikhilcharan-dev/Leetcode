
class Solution {
public:
    int paths;
    int n, m;
    vector<vector<vector<int>>> dp;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n = grid.size(), m = grid[0].size();
        dp.resize(n, vector<vector<int>>(m, vector<int>(k, -1)));
        return helper(grid, 0, 0, 0, k);
    }

    int helper(vector<vector<int>>& grid, int i, int j, long long sum, int k) {
        if(i < 0 || i >= n
        || j < 0 || j >= m) return 0;

        sum = (sum + grid[i][j]) % 1000000007;
        if(i == n - 1 && j == m - 1) {
            return sum % k == 0;
        }
        
        if(dp[i][j][sum % k] != -1) return dp[i][j][sum % k];
        
        int r = helper(grid, i, j + 1, sum, k);
        int d = helper(grid, i + 1, j, sum, k);

        return dp[i][j][sum % k] = (r + d) % 1000000007;
    }
};