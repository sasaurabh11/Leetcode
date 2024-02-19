class Solution {
public:
    #define ll long long
    bool check(ll k, vector<int>& piles, int h) {
        ll count = 0;

        for(int i = 0; i < piles.size(); i++) {
            ll val;
            if(k == 0) {
                val = 1e18;
            } else 
                val = (piles[i] + k - 1) / k;
            count += val;
        }

        if(count <= h) return true;
        else return false;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        ll low = 0, high = 1e10, ans = -1;

        while(low <= high) {
            ll mid = low + (high - low) / 2;
            if(check(mid, piles, h)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};