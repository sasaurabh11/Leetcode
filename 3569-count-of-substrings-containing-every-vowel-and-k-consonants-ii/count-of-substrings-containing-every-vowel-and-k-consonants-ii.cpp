class Solution {
public:
    bool has(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    long long countOfSubstrings(string word, int k) {
        int i = 0, j = 0, n = word.length();

        vector<int> mp(26, 0);
        int count = 0;
        long long answer = 0;

        vector<int> next(n, -1);
        int idx = n;
        for(int i = n - 1; i >= 0; i--) {
            next[i] = idx;
            if(!has(word[i])) idx = i;
        }

        for(i = 0; i < n; i++) {
            if(has(word[i])) {
                mp[word[i] - 'a']++;
            }
            else count++;

            while(j <= i && count > k) {
                if(has(word[j])) mp[word[j] - 'a']--;
                else count--;
                j++;
            }

            while(mp[0] > 0 && mp[4] > 0 && mp[8] > 0 && mp[14] > 0 && mp[20] > 0 && count == k) {
                answer += next[i] - i;
                if(has(word[j])) mp[word[j] - 'a']--;
                else count--;
                j++;
            }
        }
        
        return answer;
    }
};