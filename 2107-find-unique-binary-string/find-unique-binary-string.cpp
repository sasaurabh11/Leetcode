class Solution {
public:
    int n;

    void solve(string s, string& ans, set<string>& st) {
        if(s.length() == n) {
            if(st.find(s) == st.end()) ans = s;
            return;
        }

        solve(s + '0', ans, st);
        if(ans != "") return;
        solve(s + '1', ans, st);
        if(ans != "") return;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        set<string> st;
        this->n = nums.size();
        
        for(auto val : nums)
            st.insert(val);

        string ans = "", s = "";
        solve(s, ans, st);
        return ans;
    }
};