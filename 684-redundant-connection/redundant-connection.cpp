class Solution {
public:
    bool same(int n, vector<vector<int>>& graph, int v, vector<bool>& visited) {
        if(n == v) return true;
        visited[n] = true;

        for(auto nbr : graph[n]) {
            if(!visited[nbr]) {
                if(same(nbr, graph, v, visited)) return true;;
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<vector<int>> graph(n + 1);
        for(int i = 0; i < n; i++) {
            int u = edges[i][0], v = edges[i][1];
            vector<bool> visited(n + 1, false);
            if(same(u, graph, v, visited)) {
                return {u, v};
            }

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        return {};
    }
};