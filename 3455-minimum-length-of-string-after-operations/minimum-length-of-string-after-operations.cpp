class Solution {
public:
    int minimumLength(string s) {
        vector<int> mp(26, 0);
        for(auto val : s) 
            mp[val - 'a']++;
        int ans = 0;
        for(auto val : mp) {
            if(val != 0 && val % 2 == 0) ans += 2;
            else if(val % 2 != 0) ans++;
        }
        return ans;
    }
};