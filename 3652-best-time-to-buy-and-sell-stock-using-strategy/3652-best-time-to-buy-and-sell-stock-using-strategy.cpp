class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();

        long long maxProfit = 0;
        vector<long long> profit(n + 1, 0), sellAll(n + 1, 0);

        for (int i = 0; i < n; i++) {
            profit[i + 1] = profit[i] + 1LL * strategy[i] * prices[i];
            sellAll[i + 1] = sellAll[i] + prices[i];
        }

        maxProfit = profit[n];

        for (int i = 0; i + k <= n; i++) {
            int j = i + k;
            int mid = i + k / 2;

            long long od = profit[j] - profit[i];
            long long nw = sellAll[j] - sellAll[mid];

            maxProfit = max(maxProfit, profit[n] + nw - od);
        }

        return maxProfit;
    }
};
