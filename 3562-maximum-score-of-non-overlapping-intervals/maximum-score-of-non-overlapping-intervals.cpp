class Solution {
public:
    #define ll long long

    vector<vector<int>> arr;

    int binary_search(int nextVal) {
        int low = 0, high = arr.size() - 1, ans = arr.size();
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid][0] > nextVal) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    bool check(vector<int>& a, vector<int>& b) {
        int it1 = 0, it2 = 0;

        while (it1 < a.size() && it2 < b.size()) {
            if (a[it1] < b[it2]) return true;
            if (a[it1] > b[it2]) return false;
            it1++;
            it2++;
        }

        return a.size() < b.size();
    }

    map<int, map<int, pair<ll, vector<int>>>> dp;

    pair<ll, vector<int>> solve(int idx, int lim) {
        if (idx >= arr.size() || lim >= 4) return {0, {}};

        if(dp[idx].find(lim) != dp[idx].end()) return dp[idx][lim];

        int nextIdx = binary_search(arr[idx][1]);
        auto take = solve(nextIdx, lim + 1);
        take.first += arr[idx][2];
        take.second.push_back(arr[idx][3]);
        sort(take.second.begin(), take.second.end());

        auto nottake = solve(idx + 1, lim);

        if (take.first > nottake.first) {
            return dp[idx][lim] = take;
        } 
        else if (take.first == nottake.first) {
            if (check(take.second, nottake.second)) {
                return dp[idx][lim] = take;
            } 
            else {
                return dp[idx][lim] = nottake;
            }
        } 
        else {
            return dp[idx][lim] = nottake;
        }
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        arr = vector<vector<int>>(intervals.size(), vector<int>(4));

        for (int i = 0; i < intervals.size(); i++) {
            arr[i][0] = intervals[i][0];
            arr[i][1] = intervals[i][1];
            arr[i][2] = intervals[i][2];
            arr[i][3] = i;
        }

        sort(arr.begin(), arr.end());

        dp.clear();

        auto ans = solve(0, 0);
        return ans.second;
    }
};
