class Solution {
public:
    bool check(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0;
        for(int i = 1; i < n; i++) {
            if(arr[i] < arr[i - 1] && arr[0] < arr.back()) return false;
            if(arr[i] < arr[i - 1]) {
                if(cnt < 1) cnt++;
                else return false;
            }
        }
        return true;
    }
};