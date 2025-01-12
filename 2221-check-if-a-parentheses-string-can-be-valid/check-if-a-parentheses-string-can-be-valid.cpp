class Solution {
public:
    bool canBeValid(string s, string locked) {
        stack<int> st, st2;

        for(int i = 0; i < s.length(); i++) {
            if(locked[i] == '1') {
                if(s[i] == '(') st.push(i);
                else {
                    if(!st.empty()) st.pop();
                    else if(!st2.empty()) st2.pop();
                    else return false;
                }
            }
            else st2.push(i);
        }

        while(!st.empty() && !st2.empty()) {
            if(st.top() <= st2.top()) {
                st.pop();
                st2.pop();
            }
            else return false;
        }

        return st.empty() && st2.size() % 2 == 0;
    }
};