class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), tot = 0;
        for(int i = 0; i < nums.size(); i++) {
            tot += nums[i];
        }

        int val = (n * (n + 1)) / 2;

        return (val - tot);
    }
};