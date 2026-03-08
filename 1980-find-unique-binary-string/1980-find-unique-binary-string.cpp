class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string result = "";
        
        // Construct a binary string by flipping the i-th bit of nums[i]
        // This ensures the result differs from every string in nums at least at position i
        for (int i = 0; i < n; ++i) {
            // Flip the i-th bit: if it's '0', make it '1'; if it's '1', make it '0'
            result += (nums[i][i] == '0') ? '1' : '0';
        }
        
        return result;
    }
};