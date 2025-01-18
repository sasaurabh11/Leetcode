class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        
        pq.push({0, 0, 0});
        dist[0][0] = 0;
        
        while (!pq.empty()) {
            auto [cost, x, y] = pq.top();
            pq.pop();
            
            for (int i = 0; i < 4; ++i) {
                int newx = x + dx[i];
                int newy = y + dy[i];
                
                if (newx >= 0 && newx < m && newy >= 0 && newy < n) {
                    int newcost = cost;
                    
                    if ((i == 0 && grid[x][y] == 1) || 
                        (i == 1 && grid[x][y] == 2) || 
                        (i == 2 && grid[x][y] == 3) || 
                        (i == 3 && grid[x][y] == 4)) {
                        newcost += 0;  
                    }
                    else {
                        newcost += 1;
                    }

                    if (newcost < dist[newx][newy]) {
                        dist[newx][newy] = newcost;
                        pq.push({newcost, newx, newy});
                    }
                }
            }
        }
        
        return dist[m - 1][n - 1];
    }
};
