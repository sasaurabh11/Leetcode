class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1, n = nums.size(), temp = 1, temp2 = 1;;

        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i - 1]) temp++;
            else temp = 1;
            ans = max(ans, temp);
        }

        
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] > nums[i + 1]) temp2++;
            else temp2 = 1;
            ans = max(ans, temp2);
        }

        return ans;
    }
};