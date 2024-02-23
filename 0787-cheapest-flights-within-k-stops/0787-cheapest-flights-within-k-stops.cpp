class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> graph;

        for(int i = 0; i < flights.size(); i++) {
            graph[flights[i][0]].push_back(make_pair(flights[i][1], flights[i][2]));
        }

        //print graph
        // for(auto it : graph) {
        //     cout << it.first << " ";
        //     for(auto nbr : graph[it.first]) {
        //         cout << "{ " << nbr.first << ", " << nbr.second << "}" << " ";
        //     }
        //     cout << endl;
        // }

        //dijkstra
        vector<int> stops(n , INT_MAX);

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({0, src, 0}); //{dist, node, steps}

        while(!pq.empty()) {
            auto topElement = pq.top();
            int nodeDist = topElement[0];
            int nodeValue = topElement[1];
            int steps = topElement[2];

            pq.pop();

            if(steps > stops[nodeValue] || steps > k + 1) continue;

            stops[nodeValue] = steps;

            if(nodeValue == dst) return nodeDist;

            for(auto nbr : graph[nodeValue]) {
                pq.push({nodeDist + nbr.second, nbr.first, steps + 1});
            }
        }

        return -1;
    }
};