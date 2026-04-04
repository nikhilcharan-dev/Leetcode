class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        for (int i = 0; i < nums.size(); i++) {
            if (numMap.find(target - nums[i]) != numMap.end()) {
                return {numMap[target - nums[i]], i};
            }
            numMap[nums[i]] = i;
        }
        return {};
    }
};