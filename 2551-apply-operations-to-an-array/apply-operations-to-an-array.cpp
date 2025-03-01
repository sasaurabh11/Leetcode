class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int count = 0, n = int(nums.size());

        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(i + 1 < n && nums[i] != 0 && nums[i] == nums[i + 1]) {
                ans.push_back(nums[i] * 2);
                count++;
                i++;
            }
            else if(nums[i] != 0) ans.push_back(nums[i]);
            else count++;
        }

        while(count--)
            ans.push_back(0);
        return ans;
    }
};