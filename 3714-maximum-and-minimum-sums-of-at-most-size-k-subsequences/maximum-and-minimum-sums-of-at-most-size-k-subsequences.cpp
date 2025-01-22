bool done = false;

#define ll long long
const int MOD = 1e9 + 7;

ll power (ll base, ll x) { if(x < 0) return 0; ll ans = 1; while(x) { if(x % 2 == 0) { base = (base * base) % MOD; x = x / 2; } else { ans = (ans * base) % MOD; x--; } }return ans;}
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m

const ll N = 2e5 + 5;
ll fact[N + 1], inv[N + 1];
void factCalculate() {
    fact[0] = inv[0] = 1;
    for (ll i = 1; i <= N; i++) {
        fact[i] = mod_mul(i, fact[i - 1], MOD);
    }
    inv[N] = mminvprime(fact[N], MOD);
    for (ll i = N - 1; i >= 1; i--) {
        inv[i] = mod_mul(inv[i + 1], i + 1, MOD);
    }
    inv[0] = 1;
}

ll nCr(ll n, ll r) {
    if (n < 0 || r < 0 || r > n) return 0;
    return mod_mul(fact[n], mod_mul(inv[r], inv[n - r], MOD), MOD);
}

class Solution {
public:
    int minMaxSums(vector<int>& arr, int k) {
        if(!done) {
            done = true;
            factCalculate();
        }
        int n = arr.size();
        sort(arr.begin(), arr.end());

        ll minsum = 0, maxsum = 0;
        for(int i = 0; i < n; i++) {
            for(int sz = 1; sz <= k; sz++) {
                maxsum = mod_add(maxsum, mod_mul(arr[i], nCr(i, sz - 1), MOD), MOD);
                minsum = mod_add(minsum, mod_mul(arr[i], nCr(n - i - 1, sz - 1), MOD), MOD);
            }
        }

        return mod_add(maxsum, minsum, MOD);
    }
};