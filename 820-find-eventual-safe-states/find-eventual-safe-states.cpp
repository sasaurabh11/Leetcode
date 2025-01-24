class Solution {
public:
    bool cycleCheck(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& inRecursion) {
        visited[node] = true;
        inRecursion[node] = true;

        for(auto nbr : graph[node]) {
            if(visited[nbr] == false && cycleCheck(nbr, graph, visited, inRecursion)) {
                return true;
            }
            else if(inRecursion[nbr] == true) {
                return true;
            }
        }

        inRecursion[node] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<bool> visited(n, false), inRecursion(n, false);
        for(int i = 0; i < n; i++) {
            if(!visited[i])
                cycleCheck(i, graph, visited, inRecursion);
        }

        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(inRecursion[i] == false)
                ans.push_back(i);
        }

        return ans;
    }
};