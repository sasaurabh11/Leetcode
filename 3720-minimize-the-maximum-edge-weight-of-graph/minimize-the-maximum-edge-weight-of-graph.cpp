class Solution {
public:
    bool solve(vector<pair<int, int>> graph[], int mx, int n) {
        vector<int> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;

        int nodes = 0;
        while(!q.empty()) {
            auto topval = q.front();
            q.pop();

            nodes++;
            for(auto [nbr, wt] : graph[topval]) {
                if(!visited[nbr] && wt <= mx) {
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }

        return nodes == n;
    }

    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<pair<int, int>> graph[n];

        int low = 0, high = 0, ans = -1;
        for(auto val : edges) {
            graph[val[1]].push_back({val[0], val[2]});
            high = max(high, val[2]);
        }

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(solve(graph, mid, n)) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return ans;
    }
};