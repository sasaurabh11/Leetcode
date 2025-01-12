class Solution {
public:
    vector<vector<int>> grid;
    vector<vector<vector<int>>> dp;
    int n, m;

    int solve(int i, int j, int cnt) {
        if(i == n - 1 && j == m - 1) {
            if(grid[i][j] < 0 && cnt < 2) return 0;
            return grid[i][j];
        }
        if(i >= n || j >= m) return INT_MIN;

        if(dp[i][j][cnt] != -1) return dp[i][j][cnt];

        int ans1 = solve(i + 1, j, cnt);
        if(ans1 != INT_MIN) ans1 += grid[i][j];
        
        int ans2 = solve(i, j + 1, cnt);
        if(ans2 != INT_MIN) ans2 += grid[i][j];

        int ans3 = INT_MIN, ans4 = INT_MIN;
        if(cnt < 2 && grid[i][j] < 0) {
            ans3 = solve(i + 1, j, cnt + 1);
            ans4 = solve(i, j + 1, cnt + 1);
        }

        return dp[i][j][cnt] = max({ans1, ans2, ans3, ans4});
    }

    int maximumAmount(vector<vector<int>>& grid) {
        this->grid = grid;
        this->n = grid.size();
        this->m = grid[0].size();

        dp = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(m + 1, vector<int>(3, -1)));

        return solve(0, 0, 0);
    }
};