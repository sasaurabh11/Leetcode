class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> rowsum(n, 0), colsum(m, 0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                rowsum[i] += grid[i][j];
                colsum[j] += grid[i][j];
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && (rowsum[i] > 1 || colsum[j] > 1)) 
                    ans++;
            }
        }

        return ans;
    }
};