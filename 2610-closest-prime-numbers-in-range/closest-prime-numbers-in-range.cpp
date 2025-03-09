bool done = false;
vector<int> prime;

class Solution {
public:
    const int N = 1e6 + 5;

    void seive() {
        vector<bool> primes(N, true);
        primes[0] = primes[1] = false;
        for(int i = 2; i < N; i++) {
            if(primes[i]) {
                for(int j = 2 * i; j < N; j += i) 
                    primes[j] = false;
            }
        }

        for(int i = 0; i < N; i++) {
            if(primes[i]) prime.push_back(i);
        }
    }

    vector<int> closestPrimes(int left, int right) {
        if(!done) {
            done = true;
            seive();
        }

        int diff = INT_MAX;
        vector<int> ans = {-1, -1};
        for(int i = 0; i < prime.size(); i++) {
            if(prime[i] >= left && (i + 1 < prime.size() && prime[i + 1] <= right)) {
                if(prime[i + 1] - prime[i] < diff) {
                    diff = prime[i + 1] - prime[i];
                    ans = {prime[i], prime[i + 1]};
                }
            }
        }

        return ans;
    }
};