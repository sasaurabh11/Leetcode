class Solution {
public:
    #define ll long long
    int n; 
    vector<vector<int>> cost;
    vector<vector<vector<ll>>> dp;

    ll solve(ll idx, ll firstcolor, ll secondcolor) {
        if(idx >= n / 2) return 0;

        if(dp[idx][firstcolor][secondcolor] != -1) return dp[idx][firstcolor][secondcolor];

        ll ans = LLONG_MAX;
        for(int c1 = 0; c1 < 3; c1++) {
            for(int c2 = 0; c2 < 3; c2++) {
                if(c1 != firstcolor && c2 != secondcolor && c1 != c2) {
                    ll res = cost[idx][c1] + cost[n - idx - 1][c2] + solve(idx + 1, c1, c2);
                    ans = min(ans, res);
                }
            }
        }

        return dp[idx][firstcolor][secondcolor] = ans;
    }

    long long minCost(int n, vector<vector<int>>& cost) {
        this->n = n;
        this->cost = cost;
        dp = vector<vector<vector<ll>>>(n + 1, vector<vector<ll>>(5, vector<ll>(5, -1)));
        return solve(0, 3, 3);
    }
};