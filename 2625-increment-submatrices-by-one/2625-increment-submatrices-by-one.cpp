class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> nums(n, vector<int>(n, 0));
        for(auto& query: queries) {
            int i = query[0], j = query[1];
            int n = query[2], m = query[3];
            for(int k = i; k <= n; k++) {
                for(int l = j; l <= m; l++) {
                    nums[k][l]++;
                }
            }
        }
        return nums;
    }
};