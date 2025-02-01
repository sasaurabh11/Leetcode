class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& st, vector<int>& et) {
        int n = st.size();

        vector<pair<int, int>> arr;
        for(int i = 0; i < n; i++) {
            arr.emplace_back(st[i], et[i]);
        }

        sort(arr.begin(), arr.end());

        vector<int> gaps;
        gaps.push_back(arr[0].first);
        for (int i = 1; i < n; i++) {
            if (arr[i].first >= arr[i - 1].second) {
                gaps.push_back(arr[i].first - arr[i - 1].second);
            }
        }
        gaps.push_back(eventTime - arr.back().second);

        vector<int> pre = gaps;
        vector<int> suff = gaps;

        for(int i = 1; i < gaps.size(); i++) {
            pre[i] = max(pre[i], pre[i - 1]);
        }

        for(int i = gaps.size() - 2; i >= 0; i--) {
            suff[i] = max(suff[i], suff[i + 1]);
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            int temp = gaps[i];
            if(i + 1 < gaps.size()) temp += gaps[i + 1];

            int diff = arr[i].second - arr[i].first;

            if((i - 1 >= 0 && pre[i - 1] >= diff) || (i + 2 < gaps.size() && suff[i + 2] >= diff)) temp += diff;
            ans = max(ans, temp);
        }
        return ans;
    }
};