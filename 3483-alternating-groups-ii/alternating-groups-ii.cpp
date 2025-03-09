class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        for(int i = 0; i < n; i++) 
            colors.push_back(colors[i]);

        int count = 1, ans = 0;
        for(int i = 1; i < n + k - 1; i++) {
            if(colors[i] == colors[i - 1]) count = 1;
            else {
                count++;
                if(count >= k) ans++;
            }
        }

        return ans;
    }
};