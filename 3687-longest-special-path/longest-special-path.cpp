class Solution {
public:
    vector<int> nums;
    pair<int, int> ans = {0, -1};
    vector<int> depth;

    void dfs(int node, int par, vector<vector<pair<int, int>>>& graph, int left, int curr_level, vector<int>& pre) {
        int prev_level = depth[nums[node]];
        depth[nums[node]] = curr_level;

        left = max(left, prev_level);
        ans = max(ans, {pre.back() - pre[left], -(curr_level - left)});

        for(auto [nbr, wt] : graph[node]) {
            if(nbr != par) {
                pre.push_back(pre.back() + wt);
                dfs(nbr, node, graph, left, curr_level + 1, pre);
                pre.pop_back();
            }
        }

        depth[nums[node]] = prev_level;
    }

    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        int n = nums.size();
        this->nums = nums;
        vector<vector<pair<int, int>>> graph(n);

        for (auto& val : edges) {
            graph[val[0]].emplace_back(val[1], val[2]);
            graph[val[1]].emplace_back(val[0], val[2]);
        }

        vector<int> pre = {0};
        depth = vector<int>(50100, 0);
        dfs(0, -1, graph, 0, 1, pre);

        return {ans.first, -ans.second};
    }
};