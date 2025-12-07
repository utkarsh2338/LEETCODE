class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int>st;
        for(auto& t:tokens){
            if(t == "+" || t == "-" || t == "*" || t == "/"){
                int a = st.top();st.pop();
                int b = st.top();st.pop();
                if(t == "+") st.push(b+a);
                else if(t == "-") st.push(b-a);
                else if(t == "*") st.push(b*a);
                else st.push(b/a);
            }
            else{
                st.push(stoi(t));
            }
        }
        return st.top();
    }
};