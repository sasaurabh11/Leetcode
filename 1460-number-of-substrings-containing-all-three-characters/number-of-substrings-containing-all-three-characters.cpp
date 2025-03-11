class Solution {
public:
    int numberOfSubstrings(string s) {
        int i = 0, j = 0, n = s.length();
        
        int ans = 0;
        map<char, int> st;
        for(i = 0; i < n; i++) {
            st[s[i]]++;
            while(j <= i && st['a'] >= 1 && st['b'] >= 1 && st['c'] >= 1) {
                ans += n - i;
                st[s[j]]--;
                j++;
            }

            cout << i << " " << ans << endl;
        }

        return ans;
    }
};