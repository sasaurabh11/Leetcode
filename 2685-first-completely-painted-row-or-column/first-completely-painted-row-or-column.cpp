class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        
        vector<int> rowsum(n, 0), colsum(m, 0);

        vector<pair<int, int>> indexes(m * n + 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                indexes[mat[i][j]] = {i, j};
            }
        }

        for(int i = 0; i < arr.size(); i++) {
            rowsum[indexes[arr[i]].first]++;
            colsum[indexes[arr[i]].second]++;

            if(rowsum[indexes[arr[i]].first] == m || colsum[indexes[arr[i]].second] == n)
                return i;
        }

        return -1;
    }
};