class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int mini = 0;
        for(auto& num: nums) {
            mini += num % 3 ? 1 : 0;
        }
        return mini;
    }
};