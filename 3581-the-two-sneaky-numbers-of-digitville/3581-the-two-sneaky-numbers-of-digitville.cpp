class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> ans;
        for(auto& num: nums) {
            mp[num]++;
            if(mp[num] == 2) ans.push_back(num);
        }
        return ans;
    }
};