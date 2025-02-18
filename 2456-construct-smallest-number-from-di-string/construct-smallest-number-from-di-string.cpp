class Solution {
public:
    bool solve(string& word, string& pattern) {
        for(int i = 0; i < pattern.size(); i++) {
            if(pattern[i] == 'I') {
                if(word[i] > word[i + 1]) return false;
            }
            else {
                if(word[i] < word[i  +1]) return false;
            }
        }

        return true;
    }

    string smallestNumber(string pattern) {
        string word;
        char ch = '1';
        for(int i = 0; i <= pattern.size(); i++) {
            word += ch++;
        }

        while(solve(word, pattern) == false) {
            next_permutation(word.begin(), word.end());
        }

        return word;
    }
};