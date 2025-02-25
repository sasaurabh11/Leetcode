class Solution {
public:
    const int MOD = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        long long odd = 0, even = 0, sum = 0;

        for(auto val : arr) {
            sum += val;
            if(sum % 2 == 0) even++;
            else odd++;
        }

        return (odd + (odd * even) % MOD) % MOD;
    }
};