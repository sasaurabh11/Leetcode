class Solution {
public:
    int bfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;

        int ans = 0;
        q.push({row, col});
        visited[row][col] = true;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            ans += grid[x][y];
            for(int i = 0; i < 4; i++) {
                int newx = x + dx[i];
                int newy = y + dy[i];

                if(newx >= 0 && newx < n && newy >= 0 && newy < m && !visited[newx][newy] && grid[newx][newy] != 0) {
                    visited[newx][newy] = true;
                    q.push({newx, newy});
                }
            }
        }

        return ans;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        int ans = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!visited[i][j] && grid[i][j] != 0) {
                    ans = max(ans, bfs(i, j, grid, visited));
                }
            }
        }

        return ans;
    }
};