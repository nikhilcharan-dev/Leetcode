class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int, int> mp;
        for(auto& num: nums) mp[num]++;
        while(mp[original]) original *= 2;
        return original;
    }
};