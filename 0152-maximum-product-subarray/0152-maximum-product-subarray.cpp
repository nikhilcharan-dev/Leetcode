class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre = 1;
        int suf = 1;
        int ans = nums[0];
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            pre *= nums[i];
            suf *= nums[n - i - 1];

            ans = max({ ans, pre, suf });
            if(!pre) pre = 1;
            if(!suf) suf = 1;
        }

        return ans;
    }
};