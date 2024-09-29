class Solution {
public:
    vector<int> pse(vector<int>& heights){
        stack<int>st;
        vector<int>ans(heights.size());
        for(int i=0; i<heights.size(); i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()) ans[i] = 0;
            else ans[i] = st.top() + 1;
            st.push(i);
        }
        return ans;
    }
    vector<int> nse(vector<int>& heights){
        stack<int>st;
        vector<int>ans(heights.size());
        for(int i=heights.size()-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()) ans[i] = heights.size() - 1;
            else ans[i] = st.top() - 1;
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>prev = pse(heights);
        vector<int>next = nse(heights);
        int ans = 0;
        for(int i=0; i<heights.size(); i++){
            ans = max(ans,heights[i] * (next[i] - prev[i] + 1));
        }
        return ans;
    }
};