class Solution {
   public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        if (m <= 2 || n <= 2) return 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    pq.emplace(heightMap[i][j], i, j);
                    visited[i][j] = true;
                }
            }
        }
        int volume = 0;
        while (!pq.empty()) {
            auto [height, i, j] = pq.top();
            pq.pop();
            for (auto& [di, dj] : DIRS) {
                int ni = i + di, nj = j + dj;
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && !visited[ni][nj]) {
                    volume += max(height - heightMap[ni][nj], 0);
                    pq.emplace(max(height, heightMap[ni][nj]), ni, nj);
                    visited[ni][nj] = true;
                }
            }
        }
        return volume;
    }

   private:
    static constexpr int DIRS[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};