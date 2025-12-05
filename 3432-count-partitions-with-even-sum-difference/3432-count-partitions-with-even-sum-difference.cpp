class Solution {
public:
    int countPartitions(vector<int>& nums) {
        vector<int> prefix(1, nums[0]);
        for(int i = 1; i < nums.size(); i++) {
            prefix.push_back(prefix.back() + nums[i]);
        }
        int cnt = 0;
        for(int i = 0; i < prefix.size() - 1; i++) {
            if((prefix[i] + (prefix.back() - prefix[i])) % 2 == 0) cnt++;
            // cout << prefix[i] << " " << (prefix.back() - prefix[i]) << endl;
        }
        return cnt;
    }
};