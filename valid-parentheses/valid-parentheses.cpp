class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.length(); i++){
            char ch = s[i];
            if(ch == '(' || ch == '[' || ch=='{')
                st.push(ch);
            else
            {
                if(st.size() == 0)
                    return false;
                else if(st.top() == '[' && ch != ']')
                    return false;
                else if(st.top() == '(' && ch != ')')
                    return false;
                else if(st.top() == '{' && ch != '}')
                    return false;
                else
                    st.pop();
            }
        }
        return st.size() == 0;
        
    }
};