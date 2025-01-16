class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n  = nums1.size(), m = nums2.size();

        int ans = 0;

        for(int i = 0; i < n; i++) {
            if(m % 2) ans ^= nums1[i];
        }

        for(int i = 0; i < m; i++) {
            if(n % 2) ans ^= nums2[i];
        }

        return ans;
    }
};