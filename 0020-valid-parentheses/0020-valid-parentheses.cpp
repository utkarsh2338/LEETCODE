class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<char> st;
        
        for (int i = 0; i < n; i++) {
            // Push opening brackets onto the stack
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                // If the stack is empty, it means no matching opening bracket
                if (st.empty()) 
                    return false;
                
                char ch = st.top();
                st.pop();
                
                // Check for mismatched brackets
                if ((s[i] == ')' && ch == '(') ||
                    (s[i] == ']' && ch == '[') ||
                    (s[i] == '}' && ch == '{')) {
                }
                else  return false;
            }
        }
        
        // If stack is empty, all brackets were matched
        return st.empty();
    }
};