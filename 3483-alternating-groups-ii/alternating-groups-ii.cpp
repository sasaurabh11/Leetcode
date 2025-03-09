class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        for(int i = 0; i < n; i++) 
            colors.push_back(colors[i]);

        vector<int> pre;
        for(int i = 1; i < n + k; i++) {
            if(colors[i] == colors[i - 1]) pre.push_back(1);
            else {
                if(pre.empty()) pre.push_back(1);
                else pre.push_back(pre.back() + 1);
            }
        }

        int ans = 0;
        for(auto val : pre) 
            if(val >= k) ans++;

        return ans;
    }
};