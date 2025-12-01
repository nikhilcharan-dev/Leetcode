class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        if(n == batteries.size()) return *min_element(batteries.begin(), batteries.end());
        else if(n > batteries.size()) return 0;

        sort(batteries.rbegin(), batteries.rend());
        long long totalCapacity = accumulate(batteries.begin(), batteries.end(), (long long)0);

        long long low = batteries[n - 1], high = totalCapacity / n;
        long long maxi = low;
        while(low <= high) {
            long long mid = (low + high) / 2;
            if(isValid(batteries, n, mid)) {
                low = mid + 1;
                maxi = max(maxi, mid);
            } else {
                high = mid - 1;
            }
        }

        return maxi;
    }

    bool isValid(vector<int>& nums, int n, int k) {
        int m = nums.size();
        int i = m - 1;
        cout << k << '\n';
        long long rem = 0;
        while(i >= 0 && nums[i] < k) {
            rem += nums[i--];
        }

        int valid = i + 1;
        if(valid >= n) return true;

        return 1LL * k * (n - valid) <= rem;
    }
};