class Solution {
public:
    int help(vector<int>&heights){
        stack<int>st;
        int ans = 0,n = heights.size();
        for(int i=0; i<=n; i++){
            while(!st.empty() && (i == n || heights[st.top()] >= heights[i])){
                int height = heights[st.top()];
                st.pop();
                int width;
                if(st.empty()) width = i;
                else width = i - st.top() - 1;
                height = min(height,width);
                ans = max(ans,height * height);
            }
            st.push(i);
        }
        return ans;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        int m = matrix.size(),n = matrix[0].size();
        vector<int>heights(n);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == '0') heights[j] = 0;
                else heights[j] = heights[j] + 1;
            }
            ans = max(ans,help(heights));
        }
        return ans;
    }
};