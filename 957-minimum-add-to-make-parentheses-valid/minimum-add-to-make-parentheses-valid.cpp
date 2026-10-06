class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0;
        stack<char> st;
        for(auto& i : s){
            if(st.empty()) st.push(i);
            else{
                if(st.top() == '(' and i == ')') st.pop();
                else if(st.top() == '{' and i == '}') st.pop();
                else if(st.top() == '[' and i == ']') st.pop();
                else st.push(i);
            }
        }
        while(!st.empty()){
            st.pop();
            count++;
        }
        return count;
    }
};