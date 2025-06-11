/*
Khandani Template: 
for(int i=0;i<n;i++){
    while(!st.empty() && heights[st.top()] > or < heights[i]){ increasing hua oh > aur agr decreasing hua toh <
    st.pop();
    }
    st.push();
}
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        // nger
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int barHeight = st.top();
                st.pop();
                int previousSE = st.empty() ? -1 : st.top();
                int nextSE = i;
                maxArea = max(maxArea,heights[barHeight] * (nextSE-previousSE -1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int barHeight = st.top();
            st.pop();
            int previousSE = st.empty() ? -1: st.top();
            int nextSE = n;
            maxArea = max(maxArea,heights[barHeight]*(nextSE-previousSE-1));
        }
        
        return maxArea;
    }
};