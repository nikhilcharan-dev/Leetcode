class Solution {
public:

    int minOperations(vector<int>& nums) {
        int ones = 0;
        int n = nums.size();
        int g = 0;
        for(auto& num: nums) {
            if(num == 1) {
                ones++;
            }
            g = gcd(g, num);
        }
        if(g > 1) return -1;
        if(ones) {
            return n - ones;
        }

        int mini = n;
        for(int i = 0; i < n; i++) {
            int g = 0;
            for(int j = i; j < n; j++) {
                g = gcd(g, nums[j]);
                if(g == 1) {
                    mini = min(mini, j - i + 1);
                    break;
                }
            }
        }

        return mini + n - 2;
    }
};