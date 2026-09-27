class Solution {
public:
    string reverseParentheses(string s) {
        stack <char> st;
        int n = s.size();
        string res = "";
        for(int i = 0; i < n; i++){
            if(st.empty()) st.push(s[i]);
            else{
                if(s[i] == ')'){
                    while(!st.empty() && st.top() != '('){
                        res += st.top();
                        st.pop();
                    }
                    if(!st.empty()) st.pop();
                    // reverse(res.begin(), res.end());
                    for(int j = 0; j < res.size(); j++){
                        st.push(res[j]);
                    }
                    res = "";
                } else{
                    st.push(s[i]);
                }
            }
        }
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};