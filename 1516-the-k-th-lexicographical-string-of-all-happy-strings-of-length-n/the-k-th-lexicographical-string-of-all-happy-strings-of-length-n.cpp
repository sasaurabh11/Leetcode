class Solution {
public:
    int n, k;

    bool check(string& s) {
        for(int i = 0; i < s.length() - 1; i++) {
            if(s[i] == s[i + 1]) return false;
        }

        return true;
    }

    void solve(string s, int& count, string &res) {
        if(s.length() == n) {
            if(check(s)) {
                count++;
            }
            if(count == k) res = s;
            return;
        }

        for(char ch = 'a'; ch <= 'c'; ch++) {
            solve(s + ch, count, res);
            if(res != "") return;
        }

    }

    string getHappyString(int n, int k) {
        this->n = n;
        this->k = k;
        string res = "";

        int count = 0;
        solve("", count, res);

        return res;
    }
};