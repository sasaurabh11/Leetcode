class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();

        if(n == 1) {
            if(derived[0] == 0) return true;
            else return false;
        }

        vector<int> arr(n);

        if(derived[0] == 1) {
            arr[0] = 1;
            arr[1] = 0;
        }
        else {
            arr[0] = 0;
            arr[1] = 0;
        }

        for(int i = 1; i < n - 1; i++) {
            if(derived[i] == 1) {
                arr[i + 1] = abs(arr[i] - 1);
            }
            else arr[i + 1] = arr[i];
        }


        if(derived[n - 1] == 1) {
            if(arr[n - 1] == arr[0]) return false;
            else return true;
        }
        else {
            if(arr[n - 1] == arr[0]) return true;
            else return false;
        }
    }
};