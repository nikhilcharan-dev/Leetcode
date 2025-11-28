class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> dp;
    int maxPathScore(vector<vector<int>>& grid, int k) {
        n = grid.size(), m = grid[0].size();
        dp.resize(n, vector<vector<int>>(m, vector<int>(k + 1, INT_MIN)));
        int ans = helper(grid, 0, 0, 0, k);
        return ans;
    }
    
    vector<vector<int>> directions = {
        {1, 0}, {0, 1}
    };
    
    int helper(vector<vector<int>>& grid, int i, int j, int cost, int k) {
        if(i < 0 || i >= n
        || j < 0 || j >= m) return -1;

        int addingScore = grid[i][j];
        int newCost = cost + (addingScore == 0 ? 0 : 1);

        if(newCost > k) return -1;
        
        if(i == n - 1 && j == m - 1) {
            return addingScore;
        }
        
        if(dp[i][j][newCost] != INT_MIN) return dp[i][j][newCost];

        int left = helper(grid, i, j + 1, newCost, k);
        int right = helper(grid, i + 1, j, newCost, k);

        int cur = max(left, right);

        if(cur < 0) dp[i][j][newCost] = -1;
        else dp[i][j][newCost] = addingScore + cur;
        
        return dp[i][j][newCost];
    }
};