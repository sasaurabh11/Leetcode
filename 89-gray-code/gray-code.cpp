class Solution {
public:
    vector<int> ans;
    unordered_set<int> avail;
    int n;

    void solve(int mask) {
        if(mask == (1 << n))
            return;

        for(int i = 0; i < n; i++) {
            int newMask = (mask ^ (1 << i));
            if(avail.find(newMask) == avail.end()) {
                avail.insert(newMask);
                ans.push_back(newMask);
                solve(newMask);
                break;
            }
        }
    }

    vector<int> grayCode(int n) {
        this->n = n;
        ans.clear(); avail.clear();

        ans.push_back(0); avail.insert(0);
        solve(0);
        return ans;
    }
};