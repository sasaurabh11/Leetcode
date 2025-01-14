class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> st1, st2;

        int n = A.size(), cnt = 0;
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++) {
            st1.push_back(A[i]);
            st2.push_back(B[i]);

            sort(st1.begin(), st1.end());
            sort(st2.begin(), st2.end());

            int k = 0, m = 0, cnt = 0;
            while(k < st1.size() && m < st2.size()) {
                if(st1[k] == st2[m]) {
                    cnt++;
                    m++; k++;
                }
                else if(st1[k] < st2[m]) {
                    k++;
                }
                else if(st1[k] > st2[m])
                    m++;
            }
            ans[i] = cnt;
        }

        return ans;
    }
};