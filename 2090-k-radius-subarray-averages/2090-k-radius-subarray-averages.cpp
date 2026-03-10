class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> avgs(n, -1);

        if (k == 0) {
            return nums;
        }

        long long windowSize = 2 * k + 1;
        if (windowSize > n) {
            return avgs;
        }

        long long sum = 0;
        for (int i = 0; i < windowSize; i++) {
            sum += nums[i];
        }

        avgs[k] = sum / windowSize;

        for (int i = k + 1; i < n - k; i++) {
            sum = sum - nums[i - k - 1] + nums[i + k];
            avgs[i] = sum / windowSize;
        }

        return avgs;
    }
};