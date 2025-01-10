class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> mp(26, 0);

        for(auto str : words2) {
            vector<int> temp(26, 0);
            for(auto val : str) {
                temp[val - 'a']++;
                mp[val - 'a'] = max(mp[val - 'a'], temp[val - 'a']);
            }
        }

        vector<string> ans;
        for(auto val : words1) {
            vector<int> mp2(26, 0);
            for(auto str : val) {
                mp2[str - 'a']++;
            }

            bool check = true;
            for(int i = 0; i < 26; i++) {
                if(mp2[i] < mp[i]) {
                    check = false;
                    break;
                }
            }

            if(check) ans.push_back(val);
        }

        return ans;
    }
};