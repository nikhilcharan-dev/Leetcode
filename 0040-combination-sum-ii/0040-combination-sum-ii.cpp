class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> nums;
        helper(candidates, nums, 0, target);
        return ans;
    }
private:
    void helper(vector<int>& candidates, vector<int> nums, int i, int target) {
        if(target == 0) {
            ans.push_back(nums);
            return;
        }
        if(target < 0 || i >= candidates.size()) return;

        nums.push_back(candidates[i]);
        helper(candidates, nums, i + 1, target - candidates[i]);
        nums.pop_back();

        while(i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) i++;
        helper(candidates, nums, i + 1, target);
    }
};