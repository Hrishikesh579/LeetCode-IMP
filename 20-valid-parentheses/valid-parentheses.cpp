class Solution {
public:
    bool isValid(string s) {
        // stack<char> st;
        // for (auto i : s) {
        //     if (st.empty())
        //         st.push(i);
        //     else {
        //         if (i == ']') {
        //             if (st.empty()) return false;
        //             while (st.top() != '[' || !st.empty())
        //                 st.pop();
        //             // if (st.empty()) st.push(i);
        //             if(!st.empty()) st.pop();
        //         }
        //         else if (i == ')' || !st.empty()) {
        //             if(st.empty()) return false;
        //             while (st.top() != '(')
        //                 st.pop();
        //             // if(st.empty()) st.push(i);
        //             if(!st.empty()) st.pop();
        //         }
        //         else if (i == '}' || !st.empty()) {
        //             if (st.empty()) return false;
        //             while (st.top() != '{')
        //                 st.pop();
        //             // if (st.empty()) st.push(i);
        //             if(!st.empty()) st.pop();
        //         }
        //         else st.push(i);
        //     }
        // }
        // if(st.empty()) return true;
        // else return false;
        stack<char> st;
        for(auto i : s){
            if (i == '[' || i == '{' || i == '(') st.push(i);
            else{
                if (st.empty()) return false;
                else if(i == '}' && st.top() != '{') return false;
                else if(i == ')' && st.top() != '(') return false;
                else if(i == ']' && st.top() != '[') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};