class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        bool check = true, check2 = true;
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(check) {
                for(int j = 0; j < m; j++) {
                    if(check2) ans.push_back(grid[i][j]);
                    check2 = !check2;
                }
            }
            else {
                for(int j = m - 1; j >= 0; j--) {
                    if(check2) ans.push_back(grid[i][j]);
                    check2 = !check2;
                }
            }
            check = !check;
        }

        return ans;
    }
};