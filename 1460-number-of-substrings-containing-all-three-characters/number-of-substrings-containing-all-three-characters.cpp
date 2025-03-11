class Solution {
public:
    int numberOfSubstrings(string s) {
        int i = 0, j = 0, n = s.length();
        
        int ans = 0;
        vector<int> st(3, 0);
        for(i = 0; i < n; i++) {
            st[s[i] - 'a']++;
            while(j <= i && st[0] >= 1 && st[1] >= 1 && st[2] >= 1) {
                ans += n - i;
                st[s[j] - 'a']--;
                j++;
            }
        }

        return ans;
    }
};