class Solution {
public:
    static bool customComp(pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
    }

    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(auto val : arr) 
            mp[val]++;

        vector<pair<int, int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), customComp);

        for(int i = 0; i < v.size(); i++) {
            int val = min(v[i].second, k);
            v[i].second -= val;
            k -= val;
        }

        int ans = 0;
        for(auto val : v) {
            if(val.second != 0)
                ans++;
        }

        return ans;
    }
};