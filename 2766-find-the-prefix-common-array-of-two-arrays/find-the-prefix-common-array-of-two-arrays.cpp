class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        map<int, int> mp;
        vector<int> ans(n, 0);
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            mp[A[i]]++;
            mp[B[i]]++;

            if(A[i] == B[i]) cnt++;
            else {
                if(mp[A[i]] == 2) cnt++;
                if(mp[B[i]] == 2) cnt++;
            }
            ans[i] = cnt;
        }

        return ans;
    }
};