class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        string maxi;
        int maxLen = 0;
        for(int i = 0; i < n; i++) {
            dp[i][i] = 1;

            if(maxLen < dp[i][i]) {
                maxLen = dp[i][i];
                maxi = s.substr(i, dp[i][i]);
            }
        }

        for(int len = 1; len < n; len++) {
            for(int i = 0; i < n - len; i++) {
                int j = i + len;
                if(s[i] == s[j]) {
                    if(len == 1) {
                        dp[i][j] = 2;
                    } else if(dp[i + 1][j - 1] > 0) {
                        dp[i][j] = j - i + 1;
                    }
                }
                if(maxLen < dp[i][j]) {
                    maxLen = dp[i][j];
                    maxi = s.substr(i, dp[i][j]);
                }
            }
        }

        return maxi;
    }
};