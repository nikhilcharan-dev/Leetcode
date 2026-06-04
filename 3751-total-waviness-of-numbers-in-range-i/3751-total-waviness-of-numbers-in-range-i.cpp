class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int cnt = 0;
        for(int i = num1; i <= num2; i++) {
            cnt += calculateWave(i);
        }
        return cnt;
    }

    int calculateWave(int n) {
        vector<int> nums;
        while(n) {
            nums.push_back(n % 10);
            n /= 10;
        }
        if(nums.size() < 3) return 0;
        int waveCnt = 0;
        for(int i = 1; i < nums.size() - 1; i++) {
            if(nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                waveCnt++;
            } else if(nums[i] < nums[i - 1] && nums[i] < nums[i + 1]) {
                waveCnt++;
            }
        }

        return waveCnt;
    }
};