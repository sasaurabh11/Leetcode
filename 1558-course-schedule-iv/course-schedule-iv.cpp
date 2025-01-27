class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);

        for(auto val : prerequisites) {
            graph[val[0]].push_back(val[1]);
            indegree[val[1]]++;
        }

        unordered_map<int, set<int>> req;
        queue<int> q;

        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            auto top = q.front();
            q.pop();

            for(auto nbr : graph[top]) {
                indegree[nbr]--;

                req[nbr].insert(top);
                for(auto val : req[top]) {
                    req[nbr].insert(val);
                }

                if(indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        vector<bool> ans;

        for(auto val : queries) {
            if (req[val[1]].find(val[0]) != req[val[1]].end())
                ans.push_back(true);
            else 
                ans.push_back(false);
        }

        return ans;
    }
};