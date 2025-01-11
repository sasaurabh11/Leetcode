class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length() < k) return false;
        if(s.length() == k) return true;

        map<char, int> mp;
        for(auto val : s)
            mp[val]++;

        int odd = 0;
        for(auto val : mp)
            odd += (val.second % 2);

        return odd <= k;
    }
};